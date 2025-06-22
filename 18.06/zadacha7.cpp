#include <iostream>
#include <cctype>

bool isLatinLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isCarNumber(const std::string& s) {
    if (s.length() != 6) return false;
    if (!isLatinLetter(s[0])) return false;
        for (int i = 1; i <= 3; ++i) {
            if (!isdigit(s[i])) return false;
        }
    for (int i = 4; i <= 5; ++i) {
        if (!isLatinLetter(s[i])) return false;
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Ввод";
    std::string number;
    std::cin >> number;
    std::cout << "Вывод" << '\n';
    if (isCarNumber(number)) {
        std::cout << "YES" << '\n';
    }
    else {
        std::cout << "NO" << '\n';
    }
}













