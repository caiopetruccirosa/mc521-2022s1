#include <bits/stdc++.h>
#include <stdio.h>
#include <float.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    int n, p, k = 1;
    while (cin >> n >> p && n && p) {
        string best_complaint;
        int best_req_met = -1;
        double best_price = DBL_MAX;

        string s;
        getline(cin, s);
        while (n--) {
            getline(cin, s);
        }

        while (p--) {
            string complaint; double price; int req_met;
            getline(cin, complaint);
            cin >> price >> req_met;

            if ((req_met > best_req_met) || (req_met == best_req_met && price < best_price)) {
                best_complaint = complaint;
                best_req_met = req_met;
                best_price = price;
            }

            getline(cin, s);
            while (req_met--) {
                getline(cin, s);
            }
        }

        if (k > 1)
            cout << '\n';
        cout << "RFP #" << k << '\n';
        cout << best_complaint << '\n';
        k++;
    }

    return 0;
}