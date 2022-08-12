#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll n;

    while (cin >> n) {
        vector<ll> prices(n, -1);
        for (ll i = 0; i < n; i++)
            cin >> prices[i];
        
        ll m; cin >> m;

        ll pi, pj, min_diff = INT_MAX;
        for (ll i = 0; i < n; i++) {
            for (ll j = i+1; j < n; j++) {
                if (prices[i]+prices[j]==m) {
                    if (abs(prices[i]-prices[j]) < min_diff) {
                        min_diff = abs(prices[i]-prices[j]);
                        pi = prices[i];
                        pj = prices[j];
                    }
                }
            }
        }

        if (pi <= pj)
            cout << "Peter should buy books whose prices are " << pi << " and " << pj << ".\n";
        else
            cout << "Peter should buy books whose prices are " << pj << " and " << pi << ".\n";

        if (n > 0)
            cout << '\n';
    }

    return 0;
}