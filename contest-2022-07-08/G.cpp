#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(6, 0), b(6, 0);

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        a[p] += 1;
    }

    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        b[p] += 1;
    }

    /*for (int i = 1; i <= 5; i++) {
        cout << a[i];
        if (i < 5)
            cout << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= 5; i++) {
        cout << b[i];
        if (i < 5)
            cout << ' ';
    }
    cout << '\n';*/

    double exchanges = 0;
    for (int i = 1; i <= 5; i++) {
        int sum = a[i] + b[i];
        if (sum % 2 != 0) {
            cout << -1 << '\n';
            return 0;
        }
        exchanges += abs(a[i] - b[i])/2.0;
    }
    printf("%.0lf\n", exchanges/2.0);

    return 0;
}