#include <bits/stdc++.h>

#define ABS(a) ((a < 0) ? (-a) : (a))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int matrix[5][5];
    int pos_i, pos_j;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j]) {
                pos_i = i;
                pos_j = j;
            }
        }
    }

    int moves = ABS((pos_i - 2)) + ABS((pos_j - 2));

    cout << moves << '\n';

    return 0;
}