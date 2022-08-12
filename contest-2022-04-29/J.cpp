#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n, q;
    cin >> n >> q;

    int permutations[100000];
    for (int i = 0; i < n; i++)
        cin >> permutations[i];

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            int tmp = permutations[x-1];
            permutations[x-1] = permutations[y-1];
            permutations[y-1] = tmp;
        } else if (t == 2) {
            int i, k; cin >> i >> k;
            while (k--) {
                i = permutations[i-1];
            }
            cout << i << '\n';
        }
    }

    return 0;
}