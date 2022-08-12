#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool spitted(vector<ll> positions, vector<ll> distances) {
    for (int i = 0; i < positions.size(); i++) {
        ll pos1 = positions[i] + distances[i];
        for (int j = 0; j < positions.size(); j++) {
            ll pos2 = positions[j] + distances[j];
            if (pos1 == positions[j] && pos2 == positions[i]) {
                return true;
            }
        }
    }

    return false;
}

int main() {_
    int n;
    cin >> n;

    vector<ll> positions(n, 0);
    vector<ll> distances(n, 0);
    for (int i = 0; i < n; i++) {
        ll x, d;
        cin >> x >> d;
        positions[i] = x;
        distances[i] = d;
    }

    if (spitted(positions, distances))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}