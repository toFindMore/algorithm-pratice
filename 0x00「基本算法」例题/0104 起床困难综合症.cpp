#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int m, n;

int ts[N], ops[N];

// c : 0, 1
int calc(int c, int pos) {
    for(int i=0;i<n;i++) {
        int t = ts[i] >> pos & 1;
        if(ops[i] == 0) {
            if(t + c <= 1) c = 0;
            else c = 1;
        }
        else if(ops[i] == 1) {
            if(t + c >= 1) c = 1;
            else c = 0;
        }
        else {
            if(t + c == 1) c = 1;
            else c = 0;
        }
    }
    return c;
}

int main() {
    scanf("%d%d", &n, &m);
    char op[4];
    for(int i=0;i<n;i++) {
        int t;
        scanf("%s%d", op, &t);
        ts[i] = t;
        if(op[0] == 'A') ops[i] = 0;
        else if(op[0] == 'O') ops[i] = 1;
        else ops[i] = 2;
    }
    int cur = 0, res = 0;
    for(int i=30;i>=0;i--) {
        int k = calc(0, i);
        if(k) {
            res += (1 << i);
            continue;
        }
        k = calc(1, i);
        if(k && cur + (1 << i) <= m) {
            res += (1 << i);
            cur += (1 << i);
        }
    }
    printf("%d\n", res);
    return 0;
}