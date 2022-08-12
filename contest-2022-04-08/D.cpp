#include <bits/stdc++.h>
#include <stdio.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        int W, H;
        cin >> W >> H;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int w1 = x2-x1, h1 = y2-y1;

        int w2, h2;
        cin >> w2 >> h2;

        if (w1+w2 > W && h1+h2 > H) {
            printf("-1");
        } else {
            int min_dist = INT_MAX;
            if (w1+w2 <= W) {
                if (x1 >= w2)
                    min_dist = min(min_dist, 0);
                else
                    min_dist = min(min_dist, abs(x1-w2));

                if (x2+w2 <= W)
                    min_dist = min(min_dist, 0);
                else
                    min_dist = min(min_dist, abs(x2-(W-w2)));
            }
            if (h1+h2 <= H) {
                if (y1 >= h2)
                    min_dist = min(min_dist, 0);
                else
                    min_dist = min(min_dist, abs(y1-h2));

                if (y2+h2 <= H)
                    min_dist = min(min_dist, 0);
                else
                    min_dist = min(min_dist, abs(y2-(H-h2)));

                min_dist = min(min_dist, abs(y1-h2));
                min_dist = min(min_dist, abs(y2-(H-h2)));
            }
            printf("%.9lf", (double)min_dist);
        }
        
        printf("\n");
    }

    return 0;
}