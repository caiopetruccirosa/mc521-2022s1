#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n;
    cin >> n;

    int x, y, z;
    x = y = z = 0;
    for (int i = 0; i < n; i++) {
        int xi, yi, zi;
        cin >> xi >> yi >> zi;

        x += xi;
        y += yi;
        z += zi;
    }

    if (x == 0 && y == 0 && z == 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}