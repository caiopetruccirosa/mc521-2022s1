#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int R, C;
    cin >> R >> C;

    vector<vector<char>> matrix(R, vector<char>(C, '.'));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 'S') {
                if (
                    (i > 0 && matrix[i-1][j] == 'W') ||
                    (i < R-1 && matrix[i+1][j] == 'W') ||
                    (j > 0 && matrix[i][j-1] == 'W') ||
                    (j < C-1 && matrix[i][j+1] == 'W')
                ) {
                    cout << "NO\n";
                    return 0;
                }
                if (i > 0 && matrix[i-1][j] == '.')
                    matrix[i-1][j] = 'D';
                if (i < R-1 && matrix[i+1][j] == '.')
                    matrix[i+1][j] = 'D';
                if (j > 0 && matrix[i][j-1] == '.')
                    matrix[i][j-1] = 'D';
                if (j < C-1 && matrix[i][j+1] == '.')
                    matrix[i][j+1] = 'D';
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << matrix[i][j];
        }
        cout << '\n';
    }

    return 0;
}