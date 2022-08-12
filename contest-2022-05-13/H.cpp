#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {_
    ll t; cin >> t;

    while (t--) {
        ll m; cin >> m;
        ll score = LLONG_MAX, left = 0, right = 0;

        vector<vector<ll>> matrix(2, vector<ll>(m, 0));
        for (ll i = 0; i < 2; i++)
            for (ll j = 0; j < m; j++)
                cin >> matrix[i][j];

        for (ll i = 0; i < m; i++)
            right += matrix[0][i];

        for (ll i = 0; i < m; i++) {
            right -= matrix[0][i];
            if (i > 0)
                left += matrix[1][i-1];
            score = min(score, max(left, right));
        }

        cout << score << '\n';
    }

    return 0;
}