#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {_
    string s;
    cin >> s;

    int counter[3] = {0, 0, 0};

    for (int i = 0; i < s.size(); i +=2) {
        int num = s[i] - '0' - 1;
        counter[num]++;
    }

    string S;
    S.reserve(s.size()+1);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < counter[i]; j++) {
            S.push_back(i+1+'0');
            S.push_back('+');
        }
    }

    S.pop_back();

    cout << S << '\n';

    return 0;
}