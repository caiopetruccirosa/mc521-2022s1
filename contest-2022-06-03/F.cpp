#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool is_possible(vector<int>& g, int v, int t) {
    if (v > t)
        return false;
    else if (v == t)
        return true;

    return is_possible(g, v+g[v], t);
}

int main() {_
    int n, t;
    cin >> n >> t;

    vector<int> portals(n-1, 0);
    for (int i = 0; i < n-1; i++)
        cin >> portals[i];

    if (is_possible(portals, 0, t-1))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}