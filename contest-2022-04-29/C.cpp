#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void calculate_depth(vector<int> &tree, vector<int> &heights, int l, int r, int d) {
    if (l > r)
        return;

    int root = l;
    for (int i = l; i <= r; i++)
        if (tree[i] > tree[root])
            root = i;

    heights[root] = d;

    calculate_depth(tree, heights, root+1, r, d+1);
    calculate_depth(tree, heights, l, root-1, d+1);
}

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        
        vector<int> tree(n, 0);
        for (int i = 0; i < n; i++)
            cin >> tree[i];
        
        vector<int> heights(n, -1);
        calculate_depth(tree, heights, 0, n-1, 0);

        for (int i = 0; i < n; i++) {
            cout << heights[i];
            if (i < n-1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}