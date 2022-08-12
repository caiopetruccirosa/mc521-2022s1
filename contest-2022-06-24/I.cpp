#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string i_string, f_string;
        cin >> i_string >> f_string;

        vector<char> i_list(i_string.begin(), i_string.end());
        vector<char> f_list(f_string.begin(), f_string.end());

        int i = 0;
        int f = 0;
        while (i < i_list.size()) {
            //cout << "i_list [" << i << "]" << " " << i_list[i] << "\n";
            //cout << "f_list [" << f << "]" << " " << f_list[f] << "\n\n";

            if (!(f < f_list.size()) || (i_list[i] != f_list[f])) {
                auto pos = find(i_list.begin(), i_list.end(), i_list[i]);
                i_list.erase(pos);
            } else {
                i++;
                f++;
            }
        }

        string i_result(i_list.begin(), i_list.end());

        //cout << "i_result = [" << i_result << "] e f_string = [" << f_string << "]\n";

        if (i_result == f_string)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}