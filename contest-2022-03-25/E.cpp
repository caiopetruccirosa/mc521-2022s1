#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int k;
    cin >> k;

    while (k != 0) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;

            if (x == n || y == m) {
                cout << "divisa\n";
            } else if (x < n && y < m) {
                cout << "SO\n"; 
            } else if (x < n && y > m) {
                cout << "NO\n"; 
            } else if (x > n && y < m) {
                cout << "SE\n"; 
            } else if (x > n && y > m) {
                cout << "NE\n"; 
            }
        }

        cin >> k;
    }

    return 0;
}