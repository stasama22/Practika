#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n = 0;
    int k = 0;
    cin >> n >> k;
    string str = "";
    string res = "";
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int d = 0;
        cin >> d;
        vec.push_back(d);
    }
    cin >> str;
    res.resize(str.size());
    int it = 0;
    for (int i = 0; i < k; i++) {
        if (it % 2 == 0) {
            for (int j = 0; j < str.size(); j++) {
                int ind = vec[j];
                res[--ind] = str[j];
            }
        }
        else {
            for (int j = 0; j < str.size(); j++) {
                int ind = vec[j];
                str[--ind] = res[j];
            }
        }
        it++;
    }
    if (it % 2 == 1) {
        cout << res;
    }
    else {
        cout << str;
    }
}
