#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
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
    srand(std::time(nullptr));
    int n = 0;
    std::cin >> n;
    cout << '\n';
    auto pyramid = func(n);
    vector<vector<int>> dp = pyramid;
    vector<vector<int>> res(n, vector<int>(n, -1));

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            int m_n = min(dp[i + 1][j], dp[i + 1][j + 1]);
            dp[i][j] += m_n;
            if (m_n == dp[i + 1][j]) {
                res[i][j] = j;
            }
            else {
                res[i][j] = j + 1;
            }
        }
    }
    cout << dp[0][0] << '\n';
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cout << pyramid[i][cur] << " ";
        cur = res[i][cur];
    }
    cout << '\n';
}