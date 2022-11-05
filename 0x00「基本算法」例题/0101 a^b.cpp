// s
#include <iostream>

using namespace std;

using LL = long long;

LL power(LL a, LL b, LL p) {
    LL res = 1 % p;
    while(b) {
        if ((b & 1) == 1) res = (res * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    LL a, b, p;
    cin >> a >> b >> p;
    cout << power(a, b, p) << endl;
    return 0;
}