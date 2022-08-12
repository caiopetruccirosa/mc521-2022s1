#include <bits/stdc++.h>
#include <limits.h>
#include <cstdlib>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;

        int n = INT_MAX, a = 0, b = 0, c = 0;
        for (int ai = 1; ai <= 2*A; ai++) {
            for (int bi = ai; bi <= B+abs(B-ai); bi += ai) {
                for (int i = 0; i <= 1; i++) {
                    int ci = bi * (C/bi) + bi * i;
                    int tmp = abs(A - ai) + abs(B - bi) + abs(C - ci);
                    if (tmp < n) {
                        n = tmp;
                        a = ai;
                        b = bi;
                        c = ci;
                    }
                }
            }
        }
        cout << n << '\n';
        cout << a << ' ' << b << ' ' << c << '\n';
    }

    return 0;
}