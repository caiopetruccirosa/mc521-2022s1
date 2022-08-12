#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n, m;
    cin >> n >> m;

    while (n && m) {
        int both = 0;
        set<int> jack_cds;
        while (n--) {
            int j;
            cin >> j;
            jack_cds.insert(j);
        }
        while (m--) {
            int l;
            cin >> l;
            if (jack_cds.find(l) != jack_cds.end())
                both++;
        }

        cout << both << '\n';
        
        cin >> n >> m;
    }

    return 0;
}