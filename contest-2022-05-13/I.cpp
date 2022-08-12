#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        vector<int> amount(n, 0);
        vector<bool> drenched(n, false);
        for (int i = 0; i < n; i++) {
            cin >> amount[i];

            if (amount[i] > 0) {
                drenched[i] = true;

                int prev = 0;
                if (i > 0)
                    prev = amount[i-1];
                
                int start = max(0, i-amount[i]+1);
                int end = i-prev;
                for (int j = start; j < end; j++) {
                    drenched[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << drenched[i];
            if (i < n-1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}