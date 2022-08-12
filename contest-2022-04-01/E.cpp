#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll n;
    cin >> n;

    vector<pair<ll, char>> events;
    events.reserve(2*n);
    while (n--) {
        ll b, d;
        cin >> b >> d;
        events.push_back(make_pair(b, 1));
        events.push_back(make_pair(d, -1));
    }
    sort(events.begin(), events.end());

    int y = 0, k = 0, count = 0;
    for (auto event: events) {
        if (event.second > 0)
            count++;
        else
            count--;
        
        if (count > k) {
            k = count;
            y = event.first;
        }
    }

    cout << y << ' ' << k << '\n';

    return 0;
}