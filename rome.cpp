#include <iostream>
#include <string>
using namespace std;
int getNum(string s) {
    const string c[] = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                        "XC", "C",  "CD", "D",  "CM", "M"};
    const int n[] = {1, 3, 5, 8, 10, 30, 50, 80, 100, 300, 500, 800, 1000};

    for (size_t i = 0; i < 13; i++) {
        if (c[i].compare(s) == 0) {
            return n[i];
        }
    }
    return 0;
}

int main(int argc, char const* argv[]) {
    /* code */
    string str;
    getline(cin, str);
    int r = getNum(str.substr(0, 1));
    for (size_t i = 1; i < str.length(); i++) {
        string s1 = str.substr(i, 1);
        string s2 = str.substr(i - 1, 2);
        if (0 != getNum(s2)) {
            r += getNum(s2);
        } else {
            r += getNum(s1);
        }
    }
    cout << r << endl;
    return 0;
}
