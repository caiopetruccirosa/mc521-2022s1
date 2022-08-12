#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool can_slay(ll hc, ll dc, ll hm, ll dm, ll k, ll w, ll a) {
    for (ll i = 0; i <= k; i++) {
        ll healthc = hc + (a * (k-i));
        ll damagec = dc + (w * i);
        
        ll tk = hm/damagec;
        if (hm % damagec)
            tk++;

        ll td = healthc/dm;
        if (healthc % dm)
            td++;
        
        if (tk <= td)
            return true;
    }
    return false;
}

int main() {_
    ll t; cin >> t;

    while (t--) {
        ll hc, dc, hm, dm;
        cin >> hc >> dc >> hm >> dm;

        ll k, w, a;
        cin >> k >> w >> a;

        if (can_slay(hc, dc, hm, dm, k, w, a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}