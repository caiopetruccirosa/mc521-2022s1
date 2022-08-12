#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool possible(int n) {
    for (int i = 0; i <= n/2020; i++) {
        for (int j = 0; j <= n/2021; j++) {
            int k = i*2020 + j*2021;
            if (k == n)
                return true;
            else if (k > n)
                break;
        }
    }
    return false;
}

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        if (possible(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}