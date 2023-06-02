#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int edges_count;
	cin >> edges_count;

	vector<vector<int>> g(edges_count, vector<int>(edges_count, -2000000));

	int lines_count;
	cin >> lines_count;

	for (int i = 0; i < lines_count; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a-1][b-1] = c;
	}

	int src, dest;
	cin >> src >> dest;

    for (int k = 0; k < edges_count; k++) {
        for (int i = 0; i < edges_count; i++) {
            for (int j = 0; j < edges_count; j++) {
                if (g[i][k] > -2000000 && g[k][j] > -2000000) {
                    g[i][j] = max(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    if (g[src - 1][dest - 1] > -2000000) {
        cout << g[src - 1][dest - 1] << endl;
    }
    else {
        cout << "No solution" << endl;
    }

    return 0;
}
