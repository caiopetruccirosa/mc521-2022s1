#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {_
    int n, m;
    cin >> n >> m;

    vector<vector<int>> stage(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> stage[i][j];

    int consecutive_zero, good = 0;
    for (int i = 0; i < n; i++) {
        consecutive_zero = 0;
        for (int j = 0; j < m; j++) {
            if (!stage[i][j]) {
                consecutive_zero++;
            } else {
                good += consecutive_zero;
                consecutive_zero = 0;
            }
        }
        consecutive_zero = 0;
        for (int j = m-1; j >= 0; j--) {
            if (!stage[i][j]) {
                consecutive_zero++;
            } else {
                good += consecutive_zero;
                consecutive_zero = 0;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        consecutive_zero = 0;
        for (int i = 0; i < n; i++) {
            if (!stage[i][j]) {
                consecutive_zero++;
            } else {
                good += consecutive_zero;
                consecutive_zero = 0;
            }
        }
        consecutive_zero = 0;
        for (int i = n-1; i >= 0; i--) {
            if (!stage[i][j]) {
                consecutive_zero++;
            } else {
                good += consecutive_zero;
                consecutive_zero = 0;
            }
        }
    }

    cout << good << '\n';

    return 0;
}