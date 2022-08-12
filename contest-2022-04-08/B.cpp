#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int f, r;
    
    while (cin >> f >> r && f && r) {
        vector<int> front_teeth(f, 0);
        for (int i = 0; i < f; i++)
            cin >> front_teeth[i];

        vector<int> rear_teeth(r, 0);
        for (int i = 0; i < r; i++)
            cin >> rear_teeth[i];
    }

    return 0;
}