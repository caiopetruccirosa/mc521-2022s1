#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool has_path_bfs(vector<vector<int>> graph, int n, int a, int b) {
    deque<int> queue;

    vector<bool> visited;
    visited.assign(n, false);

    visited[a] = true;
    queue.push_back(a);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop_front();

        if (vertex == b) {
            return true;
        }

        for (auto adjacent: graph[vertex]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
    
    return false;
}

int main() {
    int n, s;
    vector<bool> open1;
    vector<bool> open2;
    vector<vector<int>> graph;

    cin >> n >> s;
    open1.assign(n, false);
    open2.assign(n, false);
    graph.assign(n, vector<int>());

    for (int i = 0; i < n; i++) {
        int open;
        cin >> open;
        open1[i] = (open == 1); 
    }

    for (int i = 0; i < n; i++) {
        int open;
        cin >> open;
        open2[i] = (open == 1); 
    }

    for (int i = 0; i < n; i++) {
        if (open1[i]) {
            for (int j = i-1; j >= 0; j--) {
                if (open1[j]) {
                    graph[j].push_back(i);
                }
            }
        }
        if (open2[i]) {
            for (int j = i+1; j < n; j++) {
                if (open2[j]) {
                    graph[j].push_back(i);
                }
            }
        }
    }

    /*cout << "Number of vertex: " << graph.size() << "\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex [" << i << "]\n";

        for (int j = 0; j < graph[i].size(); j++) {
            cout << "\tVertex [" << graph[i][j] << "]\n";
        }

        cout << "\n";
    }*/

    bool has = has_path_bfs(graph, n, 0, s-1);
    if (has) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}