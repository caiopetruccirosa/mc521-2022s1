#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

bool is_2020_possible(string s, int n) {
    for (int i = 0; i <= 4; i++) {
        string a, b;
        a = s.substr(0, i);
        b = s.substr(n-(4-i), (4-i));
        a.append(b);
        if (a == "2020")
            return true;
    }
    return false;
}

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        if (is_2020_possible(s, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}