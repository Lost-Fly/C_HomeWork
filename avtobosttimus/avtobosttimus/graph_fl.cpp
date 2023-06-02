#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
#include <list>

using namespace std;

const int INF = 1000;

class Graph {
public:

	int n;
	list<int>* w;
	Graph(string);

	int edges_count = 100;

	vector<vector<int>> g;
	vector<vector<long long int>> p;

	vector<bool> used;
	vector<long long int> dist;

	vector<int> path_p;


	Graph() {
		g.resize(100, vector<int>(100, 0));
		p.resize(100, vector<long long int>(100, 0));

		// Заполнение матрицы g случайными значениями от 0 до 999
		srand(time(NULL));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (i != j) {
					int weight = rand() % 1000;
					if (weight == 0) weight = 1000;
					g[i][j] = weight;
				}
			}
		}

		// Заполнение матрицы p на основе матрицы g
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if ((g[i][j] != 0) && (g[i][j] != 100)) p[i][j] = i + 1;
			}
		}
	};

	void print_w() {
		for (int i = 0; i < edges_count; i++) {
			for (int j = 0; j < edges_count; j++) {
				cout << g[i][j] << ' ';
			}
			cout << endl;
		}
	};

	void print_p() {
		for (int i = 0; i < edges_count; i++) {
			for (int j = 0; j < edges_count; j++) {
				cout << p[i][j] << ' ';
			}
			cout << endl;
		}
	};


	void floyd() {
		for (int k = 0; k < edges_count; k++)
			for (int i = 0; i < edges_count; ++i)
				for (int j = 0; j < edges_count; ++j)
					if (g[i][k] < INF && g[k][j] < INF && (g[i][j] > g[i][k] + g[k][j])) {
						g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
						p[i][j] = k+1;
					}
	};



	int Dijkstra(int s, int t) {
		used.resize(edges_count, 0);
		dist.resize(edges_count, 0);
		used[s-1] = true;

		for (int i = 0; i < edges_count; i++) {
			dist[i] = g[s-1][i];
		}

		for (int k = 1; k < edges_count; k++) {
			int imin = s;
			int dmin = 10000;
			for (int i = 0; i < edges_count; i++) {
				if ((used[i] == false) && (dist[i] < dmin)) {
					imin = i;
					dmin = dist[i];
					//cout << dist[i] << endl;
				}
			}
			used[imin] = 1;
			for (int i = 0; i < edges_count; i++) {
				if ((used[i] == false) && (dmin + g[imin][i] < dist[i])) {
					dist[i] = dmin + g[imin][i];
					p[s - 1][i] = i + 1;
					//cout << dist[i] << endl;
				}
			}
			

		}
		return dist[t];

	}

	//void dijkstra(int start) {
	//	vector<int> dist(edges_count, INF);
	//	vector<bool> visited(edges_count, false);
	//	dist[start - 1] = 0;
	//	p[start - 1][start - 1] = start;
	//	for (int i = 0; i < edges_count - 1; i++) {
	//		int u = -1;
	//		for (int j = 0; j < edges_count; j++) {
	//			if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
	//				u = j;
	//			}
	//		}
	//		visited[u] = true;
	//		for (int v = 0; v < edges_count; v++) {
	//			if (g[u][v] != 0 && dist[u] + g[u][v] < dist[v]) {
	//				dist[v] = dist[u] + g[u][v];
	//				p[start - 1][v] = u + 1;
	//			}
	//		}
	//	}
	//}



	void Path(int u, int v) {
		path_p.push_back(v);
		while (u != v) {
			v = p[u-1][v-1];
			path_p.push_back(v);
		}
		reverse(path_p.begin(), path_p.end());
		for (auto it = path_p.begin(); it != path_p.end(); it++) {
			cout << *it << ' ';
		}
		//long long int sum = 0;
		//for (int i = 0; i < path_p.size(); i++) {
		//	if (i + 1 < path_p.size()) {
		//		sum += g[path_p[i]][path_p[i + 1]];
		//	}
		//}
		//cout << sum << endl;
	}

	void dijkstra2(int start, int end) {
		vector<int> dist(edges_count, INF);
		vector<bool> visited(edges_count, false);
		dist[start - 1] = 0;
		p[start - 1][start - 1] = start;
		for (int i = 0; i < edges_count - 1; i++) {
			int u = -1;
			for (int j = 0; j < edges_count; j++) {
				if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
					u = j;
				}
			}
			visited[u] = true;
			for (int v = 0; v < edges_count; v++) {
				if (g[u][v] != 0 && dist[u] + g[u][v] < dist[v]) {
					dist[v] = dist[u] + g[u][v];
					p[start - 1][v] = u + 1;
				}
			}
		}
		Path(start, end);
	}


	void floydlist() {
		
	}



};

Graph::Graph(string s) {
	ifstream fi(s);
	int u;
	fi >> n;
	this->w = new list<int>[n + 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			fi >> u;
			this->w[i].push_back(u);
		}
}


void printGraph(const Graph& graph) {
	for (int i = 1; i <= graph.n; i++) {
		cout << "Node " << i << ": ";
		for (auto it = graph.w[i].begin(); it != graph.w[i].end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}
}



int main() {

	//Graph Gr("Текст.txt");

	// Graph Gr;

	Graph* gr = new Graph("Текст.txt");
	printGraph(*gr);


	//gr->floydlist();

	//Gr.print_w();
	/*cout << endl;
	Gr.print_p();*/

	//cout << endl;

	///*cout << "AFTER FLOYD" << endl;

	//Gr.print_w();
	//cout << endl;
	//Gr.print_p();*/


	//srand(time(NULL));
	//int v_1 = rand() % 99 + 1;
	//
	//int v_2 = rand() % 99 + 1;

	//cout << "FINDING ROUTE BETWEEN " << v_1 << ' ' << v_2 << endl;
	//cout << endl;

	////cout << "FINDING BY FLOYD" << endl;
	////unsigned int start_time = clock(); // начальное время
	////Gr.floyd();
	////Gr.Path(v_1, v_2);
	////unsigned int end_time = clock(); // конечное время
	////unsigned int search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // искомое время

	////cout << "SEARCH TIME - " << search_time << endl;

	//cout << endl;
	//

	//cout << "FINDING BY DJKStRA" << endl;
	//unsigned int start_time2 = clock(); // начальное время
	//Gr.dijkstra2(v_1, v_2);
	//cout << endl;
	////cout << Gr.Dijkstra(v_1, v_2) << endl;
	////Gr.Path(v_1, v_2);
	//unsigned int end_time2 = clock(); // конечное время
	//unsigned int search_time2 = (double)(end_time2 - start_time2) / CLOCKS_PER_SEC; // искомое время

	//cout << "SEARCH TIME - " << search_time2 << endl;


	//cout << endl;

	//cout << "FINDING BY FLOYD" << endl;
	//unsigned int start_time = clock(); // начальное время
	//Gr.floyd();
	//Gr.Path(v_1, v_2);
	//unsigned int end_time = clock(); // конечное время
	//unsigned int search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // искомое время    

	//cout << "SEARCH TIME - " << search_time << endl;

	return 0;

}