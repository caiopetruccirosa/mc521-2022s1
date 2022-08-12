#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

ll number_restaurants(vector<vector<ll>> graph, vector<bool> cats, ll m) {
    vector<bool> visited(graph.size(), false);
    vector<bool> is_leaf(graph.size(), false);
    vector<ll> number_cats(graph.size(), 0);
    vector<ll> s;

    visited[0] = true;
    is_leaf[0] = false;
    number_cats[0] = cats[0];
    s.push_back(0);

    while(!s.empty()) {
        ll v = s.back();
        s.pop_back();

        if (number_cats[v] <= m) {
            for (auto vi: graph[v]) {
                if (!visited[vi]) {
                    is_leaf[v] = false;
                    is_leaf[vi] = true;
                    visited[vi] = true;
                    if (cats[vi])
                        number_cats[vi] = number_cats[v] + 1;
                    s.push_back(vi);
                }
            }
        }
    }

    ll k = 0;
    for (int i = 0; i < graph.size(); i++) {
        if (is_leaf[i] && number_cats[i] <= m) {
            k++;
        }
    }
    return k;
}

int main() {_
    ll n, m;
    cin >> n >> m;

    vector<bool> cats(n, false);
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;   
        cats[i] = (a == 1);
    }

    vector<vector<ll>> graph(n, vector<ll>());
    for (ll i = 0; i < n-1; i++) {
        ll a, b;
        cin >> a >> b;   
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    cout << number_restaurants(graph, cats, m) << '\n';

    return 0;
}