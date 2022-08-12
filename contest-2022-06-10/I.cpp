#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

vector<int> build_path(vector<int> previous, int start, int end) {
    deque<int> path;

    int current = end;
    while (current != start) {
        path.push_front(current);
        current = previous[current];
    }
    path.push_front(start);
    
    return vector<int>(path.begin(), path.end());
}

vector<int> shortest_path(vector<vector<pii>>& graph, int start, int end) {
    vector<bool> visited(graph.size(), false);
    vector<int> distances(graph.size(), INT_MAX);
    vector<int> previous(graph.size(), -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distances[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pii v = pq.top();
        pq.pop();

        if (visited[v.second])
            continue;

        visited[v.second] = true;

        if (v.second == end)
            return build_path(previous, start, end);

        for (auto adj : graph[v.second]) {
            if (!visited[adj.second]) {
                int d = distances[v.second] + adj.first;
                if (d < distances[adj.second]) {
                    distances[adj.second] = d;
                    previous[adj.second] = v.second;
                    pq.push(make_pair(d, adj.second));
                }
            } 
        }
    }

    return vector<int>();
}

int main() {_
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n, vector<pii>());
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a-1].push_back(make_pair(w, b-1));
        graph[b-1].push_back(make_pair(w, a-1));
    }

    vector<int> path = shortest_path(graph, 0, n-1);

    if (path.size() == 0) {
        cout << -1;
    } else {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i]+1;
            if (i < path.size()-1)
                cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}