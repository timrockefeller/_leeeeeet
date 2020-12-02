#include <iostream>
// #include <string>
// #include <cmath>
// #include <vector>
// #include <stdio.h>
using namespace std;
int P(int n, int m) {
    int r = 1;
    for (int i = n; i > n - m; i--) {
        r *= i;
    }
    return r;
}
int C(int n, int m) {
    int r = P(n, m);
    for (int i = m; i > 1; i--) {
        r /= i;
    }
    return r;
}

int getLight(int n, int m) {
    if (n > m)
        return 0;
    if (n <= 0 || m < 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == m)
        return 1;
    int r = 0;
    for (int n_ = n; n_ > 0; n_--) {
        r += getLight(n_, m - n) * C(n, n_);
    }
    return r;
}
int main() {
    int n, m;
    cin >> n >> m;
    int r = 0;
    for (int n_ = n; n_ > 0;n_--) {
        r += getLight(n_, m) * C(n, n_);
    }
    cout << r<<endl;
    return 0;
}
