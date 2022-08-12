#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool is_shot_possible(vector<vector<int>>& is_possible, vector<string>& matrix, int i, int j, int n) {
    if (i > n-1 || j > n-1)
        return true;
    
    if (is_possible[i][j] > -1)
        return (is_possible[i][j] == 1);

    if (matrix[i][j] == '0') {
        is_possible[i][j] = 0;
        return false;
    }
    
    if (is_shot_possible(is_possible, matrix, i+1, j, n) || is_shot_possible(is_possible, matrix, i, j+1, n)) {
        is_possible[i][j] = 1;
        return true;
    }

    is_possible[i][j] = 0;
    
    return false;
}

bool is_every_shot_possible(vector<string>& matrix, int n) {
    vector<vector<int>> is_possible(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1' && !is_shot_possible(is_possible, matrix, i, j, n)) {
                return false;
            }
        }
    }

    return true;
}

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<string> matrix(n, "");
        for (int i = 0; i < n; i++)
            cin >> matrix[i];

        if (is_every_shot_possible(matrix, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}