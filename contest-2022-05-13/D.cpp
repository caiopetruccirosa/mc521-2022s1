#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {_
    ll t; cin >> t;

    while (t--) {
        ll sum = 0, n; cin >> n;

        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        if ((2*sum) % n == 0) {
            ll s = (2*sum)/n, pairs = 0;

            map<ll, ll> freq;
            for (ll i = 0; i < n; i++) {
                pairs += freq[s-arr[i]];
                freq[arr[i]]++;
            }
            cout << pairs << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}