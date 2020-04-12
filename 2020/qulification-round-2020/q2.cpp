// solved
#include <bits/stdc++.h>
using namespace std;

vector<int> get_sub(string& s, int start) {
    //cout << s << endl;
    int base = 0;
    int d = 0, len = 0;
    for (int i = start; i < s.size(); ++i) {
        //cout << i << endl;
        if (s[i] == '(') {
            --base;
        } else if (s[i] == ')') {
            ++base;
        } else {
            int num = s[i] - '0';
            d = max(d, num + base);
        }
        if (base == 0) {
            len = i - start + 1;
            break;
        }
    }
    return {d, len};
}

vector<vector<int>> get_groups(string& str) {
    vector<vector<int>> groups;
    //cout <<"get_groups:" << str << endl;
    for (int i = 0; i < str.size();) {
        int len = groups.size();
        if (str[i] == '(') {
            auto sub = get_sub(str, i);
            int subd = sub[0], subl = sub[1];
            //cout << "i:" << i << subd << " " << subl << endl;
            if (groups.empty() || groups[len - 1][0] != subd) {
                groups.push_back({subd, i, i + subl - 1});
            } else {
                groups[len - 1][2] = i + subl - 1;
            }
            i += subl;
        } else {
            int num = str[i] - '0';
            if (groups.empty() || groups[len - 1][0] != num) {
                groups.push_back({num, i, i});
            } else {
                groups[len - 1][2] = i;
            }
            ++i;
        }
    }
    return groups;
}

string solve(string str) {
    while (true) {
        //cout << "b:" <<str << endl;
        vector<vector<int>> groups{}; // value, start, end

        groups = get_groups(str);

        int md = 0, mdi = 0;

        for (int i = 0; i < groups.size(); ++i) {
            if (md < groups[i][0]) {
                md = groups[i][0];
                mdi = i;
            }
        }

        if (md == 0) break;

        int d = min((mdi > 0 ? abs(md - groups[mdi - 1][0]) : md), (mdi < groups.size() - 1 ? abs(md - groups[mdi + 1][0]) : (md)));
        int start = groups[mdi][1];
        int end = groups[mdi][2];
        //cout << "mdi:" << mdi << " md:" << md << " s:" << start << " e:" << end << endl;
        str.insert(end + 1, string(d, ')'));
        str.insert(start, string(d, '('));
        //cout << "a:" << str << endl;
    }
    return str;
}

int main() {
    int n, i = 0;
    cin >> n;
    while (i < n) {
        string str;
        cin >> str;
        cout << "Case #" << (i + 1) << ": " << solve(str) << endl;
        ++i;
    }
    return 0;
}
