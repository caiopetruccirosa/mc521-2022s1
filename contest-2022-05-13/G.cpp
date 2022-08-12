#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int cost(int n, int m) {
    if (n == 1 && m == 1)
        return 0;

    if (n == 1)
        return m-1;

    if (m == 1)
        return n-1;

    return (n-1)+(m-1)*n;
}

int main() {_
    int t; cin >> t;

    while (t--) {
        int n, m, k; 
        cin >> n >> m >> k;
        
        if (k == cost(n, m))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}