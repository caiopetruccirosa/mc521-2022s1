#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll c;
    cin >> c;

    while (c--) {
        ll n, t, m;
        cin >> n >> t >> m;

        queue<pair<ll, ll>> left;
        queue<pair<ll, ll>> right;
        for (ll i = 0; i < m; i++) {
            ll a; string b;
            cin >> a >> b;
            if (b[0] == 'l')
                left.push(make_pair(a, i));
            else
                right.push(make_pair(a, i));
        }

        char bank = 'l';
        ll time_elapsed = 0;
        vector<ll> arrivals(m, -1);
        while(!left.empty() || !right.empty()) {
            if (left.empty())
                time_elapsed = max(time_elapsed, right.front().first);
            else if (right.empty())
                time_elapsed = max(time_elapsed, left.front().first);
            else
                time_elapsed = max(time_elapsed, min(left.front().first, right.front().first));

            ll amount = 0;
            queue<pair<ll, ll>> *q = (bank == 'l' ? &left : &right);
            while (amount <= n && !(q->empty()) && q->front().first <= time_elapsed) {
                arrivals[q->front().second] = time_elapsed + t;
                q->pop();
                amount++;
            }

            time_elapsed += t;
            bank = (bank == 'l' ? 'r' : 'l');
        }

        for (ll i = 0; i < m; i++) {
            cout << arrivals[i] << '\n';
        }
        if (c > 0)
            cout << '\n';
    }

    return 0;
}