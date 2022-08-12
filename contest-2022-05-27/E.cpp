#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> l(n, 0);
        for (int i = 0; i < n; i++)
            cin >> l[i];

        int e = 0;
        for (int i = 0; i < n-1; i++)
            e += l[i]-e;

        if (k == l[n-1]-e)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}