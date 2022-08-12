#include <bits/stdc++.h>
#include <stdio.h>
#include <limits.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<ll, ll>

using namespace std;

pll minimize_fraction(pll frac) {
    ll mdc = frac.first, rest = frac.second;
    while (rest != 0) {
        ll tmp = mdc;
        mdc = rest;
        rest = tmp % rest;
    }
    return make_pair(frac.first/mdc, frac.second/mdc);
}

pll fraction(string path, ll idx, pll l, pll r) {
    pll current = make_pair((l.first + r.first), (l.second + r.second));

    if (idx == path.size())
        return current;

    if (path[idx] == 'R')
        return fraction(path, idx+1, current, r);
    else
        return fraction(path, idx+1, l, current);
}

int main() {_
    ll n;
    cin >> n;

    while (n--) {
        string path;
        cin >> path;

        pll f = minimize_fraction(fraction(path, 0, make_pair(0, 1), make_pair(1, 0)));

        cout << f.first << '/' << f.second << '\n';
    }

    return 0;
}