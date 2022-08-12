#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int min_int(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {_
    ll t;
    cin >> t;

    while (t--) {
        ll a, b; cin >> a >> b;
        if (a == 0)
            cout << 1;
        else
            cout << 2*b + a + 1;
        cout << '\n';
    }

    return 0;
}