#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n, t;
    cin >> n >> t;

    string q;
    cin >> q;

    while (t--) {
        for (int i = 0; i < n-1; i++) {
            if (q[i] == 'B' && q[i+1] == 'G') {
                q[i] = 'G';
                q[i+1] = 'B';
                i++;
            }
        }
    }

    cout << q << '\n';

    return 0;
}