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
LL gcd (LL a, LL b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define x first
#define y second
#define eb push_back
#define pb pop_back
#define mp make_pair

const int N = 11;

int nums[N];
bool chosen[N];
int n;

void print() {
    for(int i=1;i<=n;i++) printf("%d ", nums[i]);
    printf("\n");
}

void dfs(int i) {
    if(n + 1 == i) print();
    else {
        for(int j=1;j<=n;j++) {
            if(chosen[j]) continue;
            chosen[j] = true;
            nums[i] = j;
            dfs(i + 1);
            chosen[j] = false;
        }
    }
}

void solve() {
    cin >> n;
    dfs(1);
}

#define LOCAL
int main() {
#ifdef LOCAL
    // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}

