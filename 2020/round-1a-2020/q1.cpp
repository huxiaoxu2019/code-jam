// not solved
#include <bits/stdc++.h>
using namespace std;
bool helper(string& data, string& pattern, int sd, int sp) {
    if (sd < data.size() && sp < pattern.size()) {
        char d = data[sd], p = pattern[sp];
        if (p != '*') {
            if (d == p) return helper(data, pattern, sd + 1, sp + 1);
            else return false;
        } else {
            return helper(data, pattern, sd + 1, sp) || helper(data, pattern, sd, sp + 1);
        }
    } else if (sd < data.size() && sp >= pattern.size()) {
        return false;
    } else if (sd >= data.size() && sp >= pattern.size()) {
        return true;
    } else {
        for (int i = sp; i < pattern.size(); ++i) {
            if (pattern[i] != '*') return false;
        }
        return true;
    }
    return false;
}
void solve(int t) {
    int N;
    cin >> N;
    vector<string> lines(N);
    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        lines[i] = line;
    }
    string pre = "", suf = "";
    for (int i = 0; i < N; ++i) {
        auto line = lines[i];
        string curp = "", curs = "";
        bool star = false;
        for (int j = 0; j < line.size(); ++j) {
            char c = line[j];
            if (c == '*') {
                star = true;
                continue;
            }
            if (star) {
                curs += c;
            } else {
                curp += c;
            }
        }
        if (curs.size() > suf.size()) {
            suf = curs;
        }
        if (curp.size() > pre.size()) {
            pre = curp;
        }
    }
    //cout << "pre:" <<  pre << "suf: " << suf << endl;
    bool ans = true;
    string full = pre + suf;
    //for (auto line : lines) {
    for (int i = 0; i < N; ++i) {
        auto line = lines[i];
        //cout << "ine:" << line <<" full:" << full <<endl;
        //cout << "line:" << line << endl;
        if (helper(full, line, 0, 0) == false) {
            ans = false;
            break;
        }
    }
    if (ans) {
        cout << "Case #" << t << ": " << full << endl;
    } else {
        cout << "Case #" << t << ": " << "*";
    }
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
