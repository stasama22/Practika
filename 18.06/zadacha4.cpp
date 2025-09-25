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
    string cur = "";
    string f = "";
    for (int i : k) {
        f = cur;
        for (int j = 0; j < n; j++) {
            int ind = per[j] - 1;
            cur[j] = f[ind];
        }
    }
    cout << cur << '\n';
}
