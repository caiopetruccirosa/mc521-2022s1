#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n;
    string s;
    cin >> n >> s;

    int e = count(s.begin(), s.end(), '8');

    int max_p = 0;
    for (int i = 1; i <= e; i++) {
        int p = min((n-i)/10, i);
        if (p > max_p)
            max_p = p;
    }

    cout << max_p << '\n';

    return 0;
}