// solved
#include <bits/stdc++.h>
using namespace std;
void solve(int t) {
    int N;
    cin >> N;

    string pre, suf, mid;
    vector<string> lines;

    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        lines.push_back(line);
    }

    for (int i = 0; i < N; ++i) {
        auto line = lines[i];
        int j = 0;
        string cpre, csuf, cmid;
        for (j = 0; j < line.size(); ++j) {
            if (line[j] == '*') {
                ++j;
                break;
            } else {
                cpre += line[j];
            }
        }
        for (int k = 0; k < min(pre.size(), cpre.size()); ++k) {
            if (pre[k] != cpre[k]) {
                cout << "Case #" << t << ": *" << endl;
                return;
            }
        }
        pre = (pre.size() > cpre.size()) ? pre : cpre;

        int x = line.size() - 1;
        for (; x >= 0; --x) {
            if (line[x] == '*') {
                --x;
                break;
            } else {
                csuf = line[x] + csuf;
            }
        }

        for (int k = 0; k < min(suf.size(), csuf.size()); ++k) {
            if (suf[suf.size() - k - 1] != csuf[csuf.size() - k - 1]) {
                cout << "Case #" << t << ": *" << endl;
                return;
            }
        }
        suf = (suf.size() > csuf.size()) ? suf : csuf;

        for (; j <= x; ++j) {
            if (line[j] == '*') continue;
            cmid += line[j];
        }

        mid += cmid;
    }

    cout << "Case #" << t << ": " << (pre + mid + suf) << endl;
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
