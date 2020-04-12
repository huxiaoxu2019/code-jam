// 1 2 solved
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, unordered_map<int, int>> memo;
int query(int r, int k) {
    if (r < 1 || k < 1) return 0;
    if (r == 1 && k == 1) return 1;
    if (memo.find(r) != memo.end() && memo[r].find(k) != memo[r].end()) return memo[r][k];
    int ans = 0;
    ans = query(r - 1, k) + query(r - 1, k - 1);
    //cout << "query:" << r << " " << k << " " << ans << endl;
    return memo[r][k] = ans;
}
struct E{
    int r;
    int k;
    int s;
    unordered_map<int, unordered_set<int>> vis{};
    vector<pair<int, int>> path;
    E(int vr, int vk, int vs, unordered_map<int, unordered_set<int>> vvis, vector<pair<int, int>> vpath) : r(vr), k(vk), s(vs), vis(vvis), path(vpath) {};
};
// (ri - 1, ki - 1), (ri - 1, ki), (ri, ki - 1), (ri, ki + 1), (ri + 1, ki), (ri + 1, ki + 1)
vector<int> d{-1, -1, 0, 1, 1, 0, -1};

bool helper(int r, int k, int sum, int& target, unordered_map<int, unordered_set<int>>& vis, vector<pair<int, int>>& path, int& t) {
    if (path.size() >= 500) return false;
    for (int di = 0; di < 6; ++di) {
        int nr = r + d[di];
        int nk = k + d[di + 1];
        if (nr <= 0 || nk <= 0 || nk > nr) continue;
        if (vis.find(nr) != vis.end() && vis[nr].find(nk) != vis[nr].end()) continue;
        int cur = query(nr, nk);
        //cout << "query:" << nr << " " << nk << " sum:" << cur << endl;
        if (cur + sum > target) continue;
        if (cur + sum == target) {
            path.push_back({nr, nk});
            cout << "Case #" << t <<":" << endl;
            for (auto& p : path) {
                cout << p.first << " " << p.second << endl;
            }
            return true;
        }

        path.push_back({nr, nk});
        vis[nr].insert(nk);
        if (helper(nr, nk, sum + cur, target, vis, path, t)) return true;
        path.pop_back();
        vis[nr].erase(nk);
    }

    return false;
}
void solve(int t) {
    int N = 0;
    cin >> N;
    queue<E> q;
    unordered_map<int, unordered_set<int>> vis{{1, {1}}};
    vector<pair<int, int>> path{{1, 1}};
    if (N == 1) {
        cout << "Case #" << t <<":" << endl;
        cout << "1 1" << endl;
        return;
    } else {
        helper(1, 1, 1, N, vis, path, t);
    }
    /**
    q.push(E(1, 1, 1, vis, path));
    while (!q.empty()) {
        auto e = q.front();
        q.pop();
        //cout <<" pop: r:" << e.r << " k:" << e.k << endl;
        for (int di = 0; di < 6; ++di) {
            E ce = e;
            int nr = ce.r + d[di];
            int nk = ce.k + d[di + 1];
            if (nr <= 0 || nk <= 0 || nk > nr) continue;
            if (ce.vis.find(nr) != ce.vis.end() && ce.vis[nr].find(nk) != ce.vis[nr].end()) continue;
            int cur = query(nr, nk);
            //cout << "query:" << nr << " " << nk << " sum:" << cur << endl;
            ce.path.push_back({nr, nk});
            if (cur + ce.s > N) continue;
            if (cur + ce.s == N) {
                cout << "Case #" << t <<":" << endl;
                for (auto& p : ce.path) {
                    cout << p.first << " " << p.second << endl;
                }
                return;
            }
            ce.vis[nr].insert(nk);
            ce.r = nr, ce.k = nk;
            ce.s += cur;
            q.push(ce);
        }
    }
    **/

    //cout << "Case #" << t << ":" << endl << "NULL" << endl;
}
int main() {
    int T;
    cin >> T;
    int i = 1;
    while (i <= T) {
        solve(i);
        ++i;
    }
    return 0;
}
