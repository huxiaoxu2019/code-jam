// solved
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int>& b) {
    return a[0] < b[0];
}

int main() {
    int T, N = 0, i = 0;
    cin >> T;
    while (i < T) {
        cin >> N;
        vector<vector<int>> as;
        string ans(N, 'J');
        int t1 = 0, t2 = 0;
        for (int j = 0; j < N; ++j) {
            int s, e;
            cin >> s;
            cin >> e;
            as.push_back({s, e, j});
        }
        sort(as.begin(), as.end(), cmp);
        for (auto& pa : as) {
            cout << pa[0] << " " << pa[1] << " " << pa[2] << endl;
            if (t1 <= pa[0]) {
                ans[pa[2]] = 'C';
                t1 = pa[1];
            } else if (t2 <= pa[0]) {
                ans[pa[2]] = 'J';
                t2 = pa[1];
            } else {
                ans = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << (i + 1) << ": " << ans <<endl;
        ++i;
    }
    return 0;
}
