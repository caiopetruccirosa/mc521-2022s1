#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long
#define pii pair<int, int>

#define RIGHT 1
#define LEFT -1

using namespace std;

bool is_possible_from(string s, ll i, string t, ll j, ll direction) {
    if (j >= t.size())
        return true;

    if (i < 0 || i >= s.size())
        return false;

    if (s[i] != t[j])
        return false;

    if (direction == RIGHT && is_possible_from(s, i+RIGHT, t, j+1, RIGHT))
        return true;

    return is_possible_from(s, i+LEFT, t, j+1, LEFT);
}

bool is_possible(string s, string t) {
    for (ll i = 0; i < s.size(); i++)
        if (is_possible_from(s, i, t, 0, RIGHT))
            return true;

    return false;
}

int main() {_
    ll q; cin >> q;

    while (q--) {
        string s, t;
        cin >> s >> t;

        if (is_possible(s, t))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}