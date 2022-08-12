#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int color = 0;
    int t = -1;
    while (r + g + b > 0) {
        if (color == 0) { // red
            r = max(r-2, 0);
        } else if (color == 1) { // green
            g = max(g-2, 0);
        } else if (color == 2) { // blue
            b = max(b-2, 0);
        }
        color = (color+1) % 3;
        t++;
    }
    t += 30;

    cout << t << '\n';

    return 0;
}