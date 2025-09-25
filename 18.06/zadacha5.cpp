#include <iostream>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    int up = n;
    int down = -1;
    int left = m;
    int right = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num = 0;
            cin >> num;
            if (num == 1) {
                if (i < up) up = i;
                if (i > down) down = i;
                if (j < left) left = j;
                if (j > right) right = j;
            }
        }
    }

    // По условию фигура всегда есть, поэтому выводим координаты
    cout << up - 1 << ' ' << left - 1 << ' ' << down + 1 << ' ' << right + 1;

    return 0;
}