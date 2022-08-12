#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n; cin >> n;

    vector<int> shops(n, 0);
    for (int i = 0; i < n; i++)
        cin >> shops[i];

    sort(shops.begin(), shops.end());

    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        int idx = upper_bound(shops.begin(), shops.end(), m) - shops.begin();
        cout << idx << '\n';
    }

    return 0;
}