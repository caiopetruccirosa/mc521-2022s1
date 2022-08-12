#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        int o = 0;
        if (a != 0) {
            o = 15;
            for (int k = 0; k < 15; k++) {
                ll ak = a + k;

                ll b, p;
                b = ak;
                p = 0;
                while (b % 2 == 0) {
                    b /= 2;
                    p++;
                }

                int oi =  k + (15 - p);
                if (oi < o)
                    o = oi;
            }
        }

        cout << o << ' ';
    }

    cout << '\n';

    return 0;
}