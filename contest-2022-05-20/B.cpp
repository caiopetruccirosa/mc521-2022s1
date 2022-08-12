#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll n; cin >> n;
    
    ll operations = 0;
    ll zero_amount = 0, negative_amount = 0;

    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] == 0)
            zero_amount++;
        else
            operations += abs(arr[i])-1;

        if (arr[i] < 0)
                negative_amount++;
    }

    if (negative_amount % 2 != 0 && zero_amount == 0) {
        cout << operations + 2;
    } else {
        cout << operations + zero_amount;
    }
    cout << '\n';
    
    return 0;
}