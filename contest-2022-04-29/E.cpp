#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

bool is_palindrome(string s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r])
            return false;

        l++;
        r--;
    }
    return true;
}

bool has_palindrome(string s, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (is_palindrome(s, i, j))
                return true;
    return false;
}

int main() {_
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        if (has_palindrome(s, n))
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}