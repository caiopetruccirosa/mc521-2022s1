#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> p(n, 0);
        for (ll i = 0; i < n; i++) {
            cin >> p[i];
        }

        string s;
        cin >> s;

        vector<pair<ll, ll>> like, dislike;
        like.reserve(n); dislike.reserve(n);
        for (ll i = 0; i < n; i++) {
            pair<ll, ll> pi = make_pair(p[i], i);
            if (s[i] == '1')
                like.push_back(pi);
            else
                dislike.push_back(pi);
        }
        sort(like.begin(), like.end());
        sort(dislike.begin(), dislike.end());

        ll q = 1;
        for (ll i = 0; i < dislike.size(); i++) {
            p[dislike[i].second] = q;
            q++;
        }
        for (ll i = 0; i < like.size(); i++) {
            p[like[i].second] = q;
            q++;
        }

        for (ll i = 0; i < n; i++) {
            cout << p[i];
            if (i < n-1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}