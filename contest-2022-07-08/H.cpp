#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {_
    ll t; cin >> t;

    while (t--) {
        ll n; cin >> n;

        string enemy, gregor;
        cin >> enemy >> gregor;

        vector<bool> enemy_eaten(n, false);

        int amount = 0;
        for (int i = 0; i < n; i++) {
            if (gregor[i] == '1') {
                if (enemy[i] == '0') {
                    amount++;
                } else {
                    if (i > 0 && enemy[i-1] == '1' && !enemy_eaten[i-1]) {
                        enemy_eaten[i-1] = true;
                        amount++;
                    } else if (i < n-1 && enemy[i+1] == '1' && !enemy_eaten[i+1]) {
                        enemy_eaten[i+1] = true;
                        amount++;
                    }
                }
            }
        }

        cout << amount << '\n';
    }

    return 0;
}