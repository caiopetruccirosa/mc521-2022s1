#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_possible(vector<int>& values, int n) {
    set<int> permutation;
    for (int i = 0; i < n; i++) {
        int v = values[i];

        while (v > n || permutation.find(v) != permutation.end()) {
            v /= 2;
        }

        if (v == 0)
            return false;

        permutation.insert(v);
    }

    return true;
}

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> values(n, 0);
        for (int i = 0; i < n; i++)
            cin >> values[i];

        if (is_possible(values, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}