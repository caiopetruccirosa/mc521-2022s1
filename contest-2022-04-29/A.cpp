#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll k, n, w;
    cin >> k >> n >> w;

    ll amout_to_pay = 0;
    for (int i = 1; i <= w; i++) {
        amout_to_pay += i*k;
    }

    if (amout_to_pay >= n)
        cout << (amout_to_pay - n);
    else
        cout << 0;
    cout << '\n';

    return 0;
}