#include <bits/stdc++.h>

#define ABS(a) ((a < 0) ? (-a) : (a))
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int min_distance(int a, int b) {
    if (a % b == 0) {
        return 0;
    }

    int dist1 = a % b;
    int dist2 = b - (a % b);

    if (dist1 < dist2) {
        return -dist1;
    }

    return dist2;
}

int main() {_
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // CASE 1 b is the fixed number
        int a_to_b1 = min_distance(a, b);
        int c_to_b1 = min_distance(c, b);
        int n1 = ABS(a_to_b1) + ABS(c_to_b1);

        // CASE 2 a is the fixed number
        int b_to_a2 = min_distance(a, b);
        int c_to_b2 = min_distance(c, b + b_to_a2);
        int n2 = ABS(b_to_a2) + ABS(c_to_b2);

        // CASE 3 c is the fixed number
        int b_to_c3 = min_distance(c, b);
        int a_to_b3 = min_distance(a, b + b_to_c3);
        int n3 = ABS(b_to_c3) + ABS(a_to_b3);

        if (n1 <= n2 && n1 <= n3) {
            cout << n1 << '\n';
            cout << (a + a_to_b1) << ' ' << b << ' ' << (c + c_to_b1) << '\n';
        } else if (n2 <= n1 && n2 <= n3) {
            cout << n2 << '\n';
            cout << a << ' ' << (b + b_to_a2) << ' ' << (c + c_to_b2) << '\n';
        } else if (n3 <= n1 && n3 <= n3) {
            cout << n3 << '\n';
            cout << (a + a_to_b3) << ' ' << (b + b_to_c3) << ' ' << c << '\n';
        }
    }

    return 0;
}