#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n; cin >> n;
    
    if (n % 2 == 0) {
        int k = 1;
        for (int i = 0; i < n/2; i++) {
            k *= 2;
        }
        cout << k;
    } else {
        cout << 0;
    }
    cout << '\n';
    
    return 0;
}