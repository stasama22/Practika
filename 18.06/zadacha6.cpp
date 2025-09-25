#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateMaxPairs(int a, int b, int x, int y) {
    int p1 = min(a, x + y);
    int p2 = min(b, x);
    return p1 + p2;
}

int main() {
    int n;
    cin >> n;
    vector<int> res;

    for (int i = 0; i < n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        res.push_back(calculateMaxPairs(a, b, x, y));
    }

    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << '\n';
}