#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> snow(n + 1, 0);
    vector<long long> results;

    for (int i = 0; i < k; i++) {
        int command, a, b;
        cin >> command >> a >> b;

        if (command == 1) {

            snow[a] += b;
        }
        else if (command == 2) {

            long long sum = 0;
            for (int j = a; j <= b; j++) {
                sum += snow[j];
            }
            results.push_back(sum);
        }
    }

    for (long long res : results) {
        cout << res << '\n';
    }
}
