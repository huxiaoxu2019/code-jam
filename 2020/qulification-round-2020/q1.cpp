// solved
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, i = 0;
    cin >> n;
    while (i < n) {
        int N, trace = 0, rno = 0, cno = 0;
        cin >> N;
        int rr[N], cr[N];
        memset(rr, 0, sizeof(rr));
        memset(cr, 0, sizeof(cr));
        int csets[N][N];
        memset(csets, 0, sizeof(csets));
        for (int r = 0; r < N; ++r) {
            int rset[N];
            memset(rset, 0, sizeof(rset));
            for (int c = 0; c < N; ++c) {
                int num;
                cin >> num;
                if (r == c) {
                    trace += num;
                }
                if (rset[num - 1] == 1) {
                    rr[r] = 1;
                } else {
                    rset[num - 1] = 1;
                }
                if (csets[c][num - 1] == 1) {
                    cr[c] = 1;
                } else {
                    csets[c][num - 1] = 1;
                }
            }
        }
        rno = accumulate(rr, rr + N, 0);
        cno = accumulate(cr, cr + N, 0);
        cout << "Case #" << (i + 1) << ": " << trace << " " << rno << " " << cno << endl;
        ++i;
    }
    return 0;
}
