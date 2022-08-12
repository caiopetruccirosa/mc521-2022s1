#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 0x3f3f3f3f
#define MIN(a, b) (a < b ? a : b)

int main() {_
    int y[26][26], m[26][26], n;
    cin >> n;
    while (n) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j)
                    y[i][j] = m[i][j] = 0;
                else
                    y[i][j] = m[i][j] = INF;
            }
        }

        for (int i = 0; i < n; i++) {
            char age, direction, from, to;
            int length;
            cin >> age >> direction >> from >> to >> length;

            int f = from - 'A';
            int t = to - 'A';

            if (age == 'Y') {
                y[f][t] = MIN(y[f][t], length);
                if (direction == 'B')
                    y[t][f] = MIN(y[t][f], length);
            } else {
                m[f][t] = MIN(m[f][t], length);
                if (direction == 'B')
                    m[t][f] = MIN(m[t][f], length);
            }
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (y[i][j] > y[i][k] + y[k][j])
                        y[i][j] = y[i][k] + y[k][j];

                    if (m[i][j] > m[i][k] + m[k][j])
                        m[i][j] = m[i][k] + m[k][j];
                }
            }
        }

        int k = 0;
        char a, b, points[26];
        cin >> a >> b;

        int ai = a - 'A';
        int bi = b - 'A';

        int cost = INF;
        for (int i = 0; i < 26; i++) {
            int aux = y[ai][i] + m[bi][i];
            if (cost > aux) {
                cost = aux;
                points[0] = 'A' + i;
                k = 1;
            } else if (cost == aux) {
                points[k] = 'A' + i;
                k++;
            }
        }

        if (cost < INF) {
            cout << cost;
            for (int i = 0; i < k; i++)
                cout << ' ' << points[i];
        } else {
            cout << "You will never meet.";
        }

        cout << '\n';
        cin >> n;
    }

    return 0;
}