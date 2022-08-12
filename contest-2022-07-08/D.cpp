#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {_
    int m, w;

    while (cin >> m >> w && m && w) {
        vector<int> machines_costs(m, 0);
        vector<vector<pii>> original_graph(m, vector<pii>());
        for (int l = 0; l < m-2; l++) {
            int i, c; cin >> i >> c;
            machines_costs[i-1] = c;
        }
        for (int l = 0; l < w; l++) {
            int j, k, d;
            cin >> j >> k >> d;
            original_graph[j-1].push_back(make_pair(d, k-1));
            original_graph[k-1].push_back(make_pair(d, j-1));
        }
        int v = 2*m-2;
        vector<vector<pii>> graph((2*(m-2))+2, vector<pii>());
        for (int i = 1; i < m-2; i++) {
            graph[i]
        }

    }

    return 0;
}