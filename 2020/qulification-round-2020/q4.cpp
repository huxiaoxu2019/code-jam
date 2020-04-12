// not solved
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, B;
    cin >> T;
    cin >> B;
    while (i < T) {
        string ans, res;
        if (B == 10) {
            for (int i = 0; i < 10; ++i) {
                cout << (i + 1) << endl;
                char c;
                cin >> c;
                ans += c;
            }
        } else if (B == 20) {
        } else {
            // b = 100
        }
        cout << ans << endl;
        cin >> res;
        if (res == "N") {
            return 0;
        }
        ++i;
    }
    return 0;
}
