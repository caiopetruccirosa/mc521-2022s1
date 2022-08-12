#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int rhombus_cells(int n) {
    if (n <= 1)
        return n;
    
    return rhombus_cells(n-1)+(n*2)+((n-2)*2);
}

int main() {_
    int n; cin >> n;
    cout << rhombus_cells(n) << '\n';
    return 0;
}