#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll t;
    cin >> t;

    while (t--) {
        ll n, B, x, y;
        cin >> n >> B >> x >> y;

        ll sum = 0;
        ll a = 0;
        while (n--) {
            if (a+x <= B)
                a = a+x;
            else
                a = a-y;
            sum += a;
        }
        cout << sum << '\n';
    }

    return 0;
}