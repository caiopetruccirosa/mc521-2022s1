#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

ll calculate_score(vector<ll>& arr, vector<ll>& scores, int k, int n) {
    if (k >= n)
        return 0;

    if (scores[k] != -1)
        return scores[k];

    ll s = arr[k] + calculate_score(arr, scores, k+arr[k], n);
    scores[k] = s;

    return s;
}

int main() {_
    ll t; cin >> t;

    while (t--) {
        ll n; cin >> n;

        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        vector<ll> scores(n, -1);

        ll max_score = 0;
        for (ll k = 0; k < n; k++) {
            ll score = calculate_score(arr, scores, k, n);
            if (score > max_score)
                max_score = score;
        }
        cout << max_score << '\n';
    }

    return 0;
}