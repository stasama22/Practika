#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> per(n);
    for (int i = 0; i < n; i++) {
        cin >> per[i];
    }

    string str;
    cin >> str;

    string cur = str;
    string t = str;

    for (int i = 0; i < k; i++) {
        t = cur;

        for (int j = 0; j < n; j++) {
            int new_pos = per[j] - 1;
            cur[new_pos] = t[j];
        }
    }

    cout << cur << '\n';
    return 0;
}
