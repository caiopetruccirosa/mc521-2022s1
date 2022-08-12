#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    string a, b;
    cin >> a >> b;

    bool done = false;
    int len = a.size();
    int i = 0;
    while (!done && i < len) {
        if (tolower(a[i]) < tolower(b[i])) {
            cout << -1 << '\n';
            done = true;
        } else if (tolower(a[i]) > tolower(b[i])) {
            cout << 1 << '\n';
            done = true;
        }
        i++;
    }

    if (!done) {
        cout << 0 << '\n';
    }

    return 0;
}