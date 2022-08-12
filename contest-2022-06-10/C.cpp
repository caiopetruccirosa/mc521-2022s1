#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LEFT 0
#define RIGHT 1

using namespace std;

vector<int> build_path(vector<int> &previous, int start, int end) {
    deque<int> path;

    int current = end;
    while (current != start) {
        path.push_front(current);
        current = previous[current];
    }
    path.push_front(start);

    return vector<int>(path.begin(), path.end());
}

vector<int> bfs_path(vector<vector<int>> &graph, vector<bool>& dangerous, int start, int end) {
    vector<bool> visited(graph.size(), false);
    vector<int> previous(graph.size(), -1);
    queue<int> q;

    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visited[v] = true;
        for (auto adj: graph[v]) {
            if (adj == -1) {
                previous[end] = v;
                return build_path(previous, start, end);
            } else if (!visited[adj] && !dangerous[adj]) {
                visited[adj] = true;
                previous[adj] = v;
                q.push(adj);
                if (adj == end)
                    return build_path(previous, start, end);
            }
        }
    }

    return vector<int>();
}

bool is_possible(vector<vector<int>>& graph, vector<bool>& dangerous, int n, int target) {
    vector<int> path = bfs_path(graph, dangerous, 0, target);

    if (path.size() == 0)
        return false;

    int water_level = -1;
    for (int i = 0; i < path.size(); i++) {
        int level = path[i];
        if (level >= n)
            level -= n;

        if (water_level >= level)
            return false;

        water_level++;
    }

    return true;
}

int main() {_
    int n, k;
    cin >> n >> k;
    
    string l, r;
    cin >> l >> r;

    vector<bool> dangerous(n*2, false);
    vector<vector<int>> graph(n*2, vector<int>());
    for (int i = 0; i < n; i++) {
        int li = LEFT*n+i;
        int ri = RIGHT*n+i;

        if (l[i] == 'X')
            dangerous[li] = true;
        if (r[i] == 'X')
            dangerous[ri] = true;

        if (i > 0) {
            graph[li].push_back(li-1);
            graph[ri].push_back(ri-1);
        }
        if (i < n-1) {
            graph[li].push_back(li+1);
            graph[ri].push_back(ri+1);
        }

        int j = i+k;
        if (j > n-1) {
            graph[li].push_back(-1);
            graph[ri].push_back(-1);
        } else {
            int lj = LEFT*n+j;
            int rj = RIGHT*n+j;
            graph[li].push_back(rj);
            graph[ri].push_back(lj);
        }
    }

    /*for (int i = 0; i < graph.size(); i++) {
        int level = i;
        if (level >= n) {
            level -= n;
            cout << "RIGHT ";
        } else {
            cout << "LEFT ";
        }
        cout << level << '\n';
        for (auto adj: graph[i]) {
            cout << '\t';
             int leveladj = adj;
            if (leveladj >= n) {
                leveladj -= n;
                cout << "RIGHT ";
            } else {
                cout << "LEFT ";
            }
            cout << leveladj << '\n';
        }
    }*/

    if (is_possible(graph, dangerous, n, n-1) || is_possible(graph, dangerous, n, 2*n-1))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}