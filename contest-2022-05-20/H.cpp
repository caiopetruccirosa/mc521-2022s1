#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    string months[12] = { 
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    map<string, int> month_idx;
    month_idx["January"] = 0;
    month_idx["February"] = 1;
    month_idx["March"] = 2;
    month_idx["April"] = 3;
    month_idx["May"] = 4;
    month_idx["June"] = 5;
    month_idx["July"] = 6;
    month_idx["August"] = 7;
    month_idx["September"] = 8;
    month_idx["October"] = 9;
    month_idx["November"] = 10;
    month_idx["December"] = 11;

    string m;
    int k;
    cin >> m >> k;

    cout << months[((month_idx[m]+k)%12)] << '\n';

    return 0;
}