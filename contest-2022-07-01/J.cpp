#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int min(int a, int b) {
    if (a < b)
        return a;

    return b;
}

int next_pos(string l, int p, int d, int n) {
    for (int pi = min(n-1, p+d); pi > p; pi--) {
        if (l[pi] ==  '1')
            return pi;
    }
    return -1;
}

int main() {
    int n, d;
    cin >> n >> d;
    
    string lilies;
    cin >> lilies;

    int jumps = 0;
    int position = 0;
    while (position >= 0 && position < n-1) {
        position = next_pos(lilies, position, d, n);
        jumps++;
    }

    if (position > 0)
        cout << jumps;
    else
        cout << -1;
    cout << '\n';

    return 0;
}