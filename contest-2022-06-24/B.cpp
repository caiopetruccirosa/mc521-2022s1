#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> distances(n, 0);
        for (ll i = 0; i < n; i++) {
            ll d;
            cin >> d;
            distances[i] = d;
        }
        sort(distances.begin(), distances.end());
        
        ll sum = 0;
        ll negative_sum = 0;
        for (ll i = 0; i < n-1; i++) {
            ll d = distances[i+1] - distances[i];
            sum += d;
            negative_sum += (i+1) * d;
            sum -= negative_sum;
        }

        cout << sum << "\n";
    }

    return 0;
}