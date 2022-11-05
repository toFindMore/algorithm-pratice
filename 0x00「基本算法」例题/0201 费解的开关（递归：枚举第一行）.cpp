#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>
 
using namespace std;

typedef long long LL;
typedef long double ld;
typedef std::vector<int> VI;
typedef std::vector<bool> VB;
typedef std::vector<string> VS;
typedef std::vector<double> VD;
typedef std::vector<long long> VLL;
typedef std::vector<std::vector<int> > VVI;
typedef vector<VLL> VVLL;
typedef std::vector<std::pair<int, int> > VPI;
typedef vector<VPI> VVPI;
typedef std::pair<int, int> PI;
typedef std::pair<LL, LL> PLL;
typedef std::vector<PLL> VPLL;

const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
LL gcd (LL a, LL b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define x first
#define y second
#define eb push_back
#define pb pop_back
#define mp make_pair

const int N = 11;

char s[5][6], sc[5][6];

bool check() {
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(s[i][j] == '0') return false;
    return true;
}

int min_step;

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {1, 0, 0, -1, 0};

void flip(int x, int y) {
    for(int i=0;i<5;i++) {
        int cx = dx[i] + x, cy = dy[i] + y;
        if(cx < 0 || cy < 0 || cx >= 5 || cy >= 5) continue;
        s[cx][cy] ^= 1;
    }
}

void solve() {
    min_step = INF;
    for(int i=0;i<5;i++) scanf("%s", s[i]), cout << s[i] << endl;
    memcpy(sc, s, sizeof s);
    for(int i=0;i<32;i++) {
        memcpy(s, sc, sizeof sc);
        int cnt = 0;
        for(int j=0;j<5;j++) {
            if(i >> j & 1) {
                ++ cnt;
                flip(0, j);
            }
        }
        for(int j=1;j<5;j++) {
            if(cnt >= min_step || cnt > 6) break;
            for(int k=0;k<5;k++) {
                if(cnt >= min_step || cnt > 6) break;
                if(s[j-1][k] == '0') {
                    ++ cnt;
                    flip(j, k);
                }
            }
        }
        int j;
        for(j=0;j<5;j++) if(s[4][j] != '1') break;
        if(j >= 5 && cnt <= 6) min_step = min(cnt, min_step);
    }
    if(min_step == INF) puts("-1");
    else printf("%d\n", min_step);
}

#define LOCAL
int main() {
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif
    int ToT = 1;
    cin >> ToT;
    while(ToT --) {
        solve();
    }
    return 0;
}

