#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int divisible(int n) {
    if (n % 7 == 0)
        return n;

    int k = n % 10;
    for (int i = 1; i < 10-k; i++) {
        if ((n+i) % 7 == 0)
            return n+i;
    }
    for (int i = 1; i < k; i++) {
        if ((n-i) % 7 == 0)
            return n-i;
    }

    return n;
}

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;
        cout << divisible(n) << '\n';
    }

    return 0;
}