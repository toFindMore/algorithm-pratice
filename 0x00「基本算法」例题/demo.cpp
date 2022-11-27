#include <iostream>

using namespace std;

using LL = long long;

LL mul(LL a, LL b, LL p) {
    LL ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    cout << mul(101, 3652, 1000000) << endl;
    cout << 101 * 3652 << endl;
    return 0;
}

