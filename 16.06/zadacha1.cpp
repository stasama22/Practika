#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> func(int num) {
    vector<vector<int>> vec;
    vec.resize(num);
    for (int i = 1; i <= num; i++) {
        vec[i - 1].resize(i);
        for (int j = 0; j < vec[i - 1].size(); j++) {
            int n = rand() % 100;
            vec[i - 1][j] = n;
            std::cout << n << ' ';
        }
        std::cout << '\n';
    }
    return vec;
}
int main() {
    int m = 0;
    cin >> m;
    vector<int> iii;
    vector<vector<int>> vec = func(m);
    int num = vec[0][0];
    iii.push_back(vec[0][0]);
    int k = 0;
    for (int i = 1; i < m; i++) {
        if (k == 0) {
            int y = min(vec[i][k + 1], vec[i][k]);
            if (y == vec[i][k + 1]) {
                k++;
            }
            num += y;
            iii.push_back(y);
        }
        else if (k == vec[i].size() - 1) {
            int y = 0;
            y = min(vec[i][k - 1], vec[i][k]);
            if (y == vec[i][k - 1]) {
                k--;
            }
            num += y;
            iii.push_back(y);
        }
        else {
            int f = min(vec[i][k + 1], vec[i][k]);
            int y = std::min(f, vec[i][k - 1]);
            if (y == vec[i][k - 1]) {
                k--;
            }
            else if (y == vec[i][k + 1]) {
                k++;
            }
            num += y;
            iii.push_back(y);
        }
    }
    std::cout << num << '\n';
    for (int i = 0; i < m; i++) {
        cout << iii[i] << ' ';
    }
}
