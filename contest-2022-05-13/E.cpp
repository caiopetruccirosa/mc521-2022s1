#include <iostream>
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int, int>

using namespace std;

int to_add(int ecoins, int ccoins, int emodulus) {
    for (int i = 0; i <= emodulus-ecoins; i++)
        if (((ecoins+i)*(ecoins*i)) + (ccoins*ccoins) == (emodulus*emodulus))
            return i;
        
    return -1;
}

int main() {_
    int n;
    cin >> n;

    while (n--) {
        int m, S;
        cin >> m >> S;

        int esum = 0;
        int csum = 0;

        while (m--) {
            int c, e;
            cin >> c >> e;
            esum += e;
            csum += c;
        }

        double ecoins = sqrt((S*S)-(csum*csum));

        cout << ecoins << '\n';
        if (ecoins == ((int)ecoins)) {
            int to_add = ((int)ecoins)-esum;
            cout << to_add << '\n';
        } else {
            cout << "not possible\n";
        }
    }

    return 0;
}