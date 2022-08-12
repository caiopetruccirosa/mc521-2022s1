#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    string s;
    cin >> s;

    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'Q') {
            for (int j = i+1; j < s.size(); j++) {
                if (s[j] == 'A') {
                    for (int k = j+1; k < s.size(); k++) {
                        if (s[k] == 'Q') {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << '\n';

    return 0;
}