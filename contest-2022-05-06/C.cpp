#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int max_cuts = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int k = n - (i*a + j*b);
            if (k >= 0 && k % c == 0)
                max_cuts = max(max_cuts, (i+j+(k/c)));
        }
    }

    cout << max_cuts << '\n';

    return 0;
}