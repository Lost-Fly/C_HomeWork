#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Pixel {
    int x, y;
    vector<Pixel*> neighbors;

    bool operator<(const Pixel& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

void dfs(Pixel* pixel, map<Pixel*, bool>& visited) {
    visited[pixel] = true;
    for (Pixel* neighbor : pixel->neighbors) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<Pixel> pixels(n);
    for (int i = 0; i < n; i++) {
        cin >> pixels[i].x >> pixels[i].y;
    }

    // Build graph
    for (int i = 0; i < n; i++) {
        Pixel& pixel = pixels[i];
        for (int j = i + 1; j < n; j++) {
            Pixel& other = pixels[j];
            if ((pixel.x == other.x && abs(pixel.y - other.y) == 1) ||
                (pixel.y == other.y && abs(pixel.x - other.x) == 1)) {
                pixel.neighbors.push_back(&other);
                other.neighbors.push_back(&pixel);
            }
        }
    }

    // Find connected components
    map<Pixel*, bool> visited;
    vector<int> components;
    for (Pixel& pixel : pixels) {
        if (!visited[&pixel]) {
            components.push_back(1);
            dfs(&pixel, visited);
        }
    }

    // Sort pixels by row
    sort(pixels.begin(), pixels.end());

    // Find bottom-left pixel
    Pixel* start_pixel = &pixels[0];
    for (int i = 1; i < n; i++) {
        Pixel& pixel = pixels[i];
        if (pixel.y < start_pixel->y || (pixel.y == start_pixel->y && pixel.x < start_pixel->x)) {
            start_pixel = &pixel;
        }
    }

    // Output second representation
    cout << start_pixel->x << " " << start_pixel->y << endl;
    for (Pixel& pixel : pixels) {
        if (pixel.neighbors.empty()) {
            cout << "." << endl;
            continue;
        }
        sort(pixel.neighbors.begin(), pixel.neighbors.end());
        for (Pixel* neighbor : pixel.neighbors) {
            if (neighbor->x == pixel.x + 1) {
                cout << "R";
            }
            else if (neighbor->y == pixel.y - 1) {
                cout << "T";
            }
            else if (neighbor->x == pixel.x - 1) {
                cout << "L";
            }
            else if (neighbor->y == pixel.y + 1) {
                cout << "B";
            }
        }
        cout << "." << endl;
    }

    return 0;
}
