#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {_
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> lengths(n, 0);
    for (int i = 0; i < n; i++) {
        lengths[i] = s[i]-'a'+1;
        if (i > 0)
            lengths[i] += lengths[i-1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (l > 0) {
            cout << lengths[r] - lengths[l-1];
        } else {
            cout << lengths[r];
        }
        cout << '\n';
    }

    return 0;
}