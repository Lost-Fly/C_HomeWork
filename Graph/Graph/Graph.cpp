#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>

using namespace std;


class Graph{
private:
	vector<vector<int>> g;

	vector<bool> used;

	int edges_count;

public:



	void ReadGrFromFile(string filename) {
		ifstream filein(filename);
		if (!filein.is_open()) {
			cout << "Error while opening file" << endl;
			return;
		}

		string edges_c;
		getline(filein, edges_c);
		edges_count = stoi(edges_c);

		used.resize(edges_count, false);

		g.resize(edges_count, vector<int>(edges_count));

		for (int i = 0; i < edges_count; i++) {
			for (int j = 0; j < edges_count; j++) {
				filein >> g[i][j];
				cout << g[i][j] << ' ';
			}
			cout << endl;
		}

		filein.close();

	}

	void dfs(int v) {
		
		
		used[v] = true;
		cout << v << " visited" << endl;
		
		for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); ++i)			
			if (!used[*i])	
 				dfs(*i);
	}


	void bfs(int s) {

		used.resize(edges_count, false);

		queue<int> q;
		q.push(s);
		used[s] = true;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < g[v].size(); ++i) {
				if (!used[i] && g[v][i] == 1) {
					used[i] = true;
					cout << i << ' ';
					q.push(i);
				}
			}
		}
	}



	/*Graph(string filename) {
		ifstream filein(filename);
		if (!filein.is_open()) {
			cout << "Error while opening file" << endl;
			return;
		}

		string edges_c;
		getline(filein, edges_c);
		edges_count = stoi(edges_c);

		g.resize(edges_count, vector<int>(edges_count, 0));
		p.resize(edges_count, vector<int>(edges_count, 0));

		for (int i = 0; i < edges_count; i++) {
			for (int j = 0; j < edges_count; j++) {
				filein >> g[i][j];
				if (g[i][j] != 0) p[i][j] = i+1;
			}
		}

		filein.close();
	};*/
	
};

int main() {

	Graph Gr;

	Gr.ReadGrFromFile("smatrix.txt");

	cout << "DFS" << endl;

	Gr.dfs(2);

	cout << "BFS" << endl;

	Gr.bfs(2);

	return 0;
}





//vector<list<int>> list_data(matrix_size);
//
//for (int i = 0; i < matrix_size; i++) {
//    list<int> tmp_data;
//    for (int j = 0; j < matrix_size; j++) {
//		int a;
//		cin >> a;
//        if (a) {
//            tmp_data.push_front(j+1);
//        }
//    }
//    cout << i + 1 << " -> ";
//    PrintList(tmp_data);
//    cout << endl;
//
//}