#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int culprit(vector<int>& g, vector<bool>& visited, int v) {
    if (visited[v])
        return v;

    visited[v] = true;

    return culprit(g, visited, g[v]);
}

int main() {_
    int n;
    cin >> n;

    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
        int pi; cin >> pi;
        p[i] = pi-1;
    }

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        int c = culprit(p, visited, i) + 1;
        cout << c;
        if (i < n-1)
            cout << ' ';
    }
    cout << '\n';

    return 0;
}