#include <iostream>
using namespace std;

const int N = 35;

int main() {
    int n;
    cin >> n;

    char maze[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    int wall_area = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (maze[i][j] == '#') {
                bool is_wall = true;
                for (int k = -1; k <= 1 && is_wall; k++) {
                    for (int l = -1; l <= 1 && is_wall; l++) {
                        if (maze[i + k][j + l] != '#') {
                            is_wall = false;
                            break;
                        }
                    }
                }
                if (!is_wall) {
                    wall_area += 9;
                }
            }
        }
    }

    cout << wall_area * 9 << endl;

    return 0;
}
