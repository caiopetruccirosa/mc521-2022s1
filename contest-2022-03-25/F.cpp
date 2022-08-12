#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    vector<pair<int, int>> possibilities{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    int n, r, c, k;

    while (cin >> n >> r >> c >> k && n && r && c && k) {
        vector<vector<int>> land(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> land[i][j];
            }
        }

        while (k--) {
            vector<vector<int>> during_battle = land;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int enemy = (land[i][j] + 1) % n;
                    for (int p = 0; p < 4; p++) {
                        int ii = i + possibilities[p].first;
                        int jj = j + possibilities[p].second;
                        if (ii >= 0 && ii < r && jj >= 0 && jj < c) {
                            if (land[ii][jj] == enemy) {
                              during_battle[ii][jj] = land[i][j];  
                            }
                        }
                    }
                }
            }
            land = during_battle;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << land[i][j];
                if (j < c-1)
                    cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}