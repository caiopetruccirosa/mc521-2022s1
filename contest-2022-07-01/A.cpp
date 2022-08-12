#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, string>> points;
    for (int i = 0; i < n; i++) {
        string handle;
        int plus, minus, a, b, c, d, e;
        cin >> handle >> plus >> minus >> a >> b >> c >> d >> e;

        int p = (plus * 100) - (minus * 50) + a + b + c + d + e;
        points.push_back(make_pair(p, handle));
    }
    sort(points.begin(), points.end());

    string handle = points[(points.size()-1)].second;
    cout << handle << '\n';

    return 0;
}