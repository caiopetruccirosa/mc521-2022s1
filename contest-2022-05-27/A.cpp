#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        
        if (n <= 19) { // 3^20 > 10^9 -> not possible
            cout << "YES\n";
            int k = 1;
            for (int i = 0; i < n; i++) {
                cout << k;
                if (i < n-1)
                    cout << ' ';
                k *= 3;
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}