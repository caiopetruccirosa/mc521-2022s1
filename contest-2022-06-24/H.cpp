#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 0xffffffff
#define pll pair<ll, ll>

vector<ll> dijkstra(vector<vector<ll>> g, ll start) {
    vector<bool> visited(g.size(), false);
    vector<ll> distances(g.size(), INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    visited[start] = true;
    distances[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pll p = pq.top();
        pq.pop();
        ll from = p.second;
        for (auto to: g[from]) {
            if (!visited[to]) {
                visited[to] = true;
                distances[to] = distances[from] + 1;
                pq.push(make_pair(distances[to], to));
            }
        }
    }

    return distances;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n, vector<ll>());
    for (ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    return 0;
}