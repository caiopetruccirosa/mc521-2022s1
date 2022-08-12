#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n, b, h, w;

    while (cin >> n >> b >> h >> w) {
        int min_cost = 500001;

        while (h--) {
            int p;
            cin >> p;

            bool possible = false;
            while (w--) {
                int a;
                cin >> a;
                if (a >= n) {
                    possible = true;
                }
            }

            int hotel_cost = p*n;
            if (possible && hotel_cost < min_cost) {
                min_cost = hotel_cost;
            }
        }

        if (min_cost <= b) {
            cout << min_cost << '\n';
        } else {
            cout << "stay home\n";
        }
    }

    return 0;
}