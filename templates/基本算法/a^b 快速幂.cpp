using LL = long long;

LL power(LL a, LL b, LL p) {
    LL ans = 1 % p;
    while(b) {
        if ((b & 1) == 1) ans = (ans * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}