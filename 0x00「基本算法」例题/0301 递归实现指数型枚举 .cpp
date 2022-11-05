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

void print(VI& nums) {
    if(nums.size() != 0) {
        printf("%d", nums[0]);
        for(int i=1;i<nums.size();i++) printf(" %d", nums[i]);
    }
    printf("\n");
}

void dfs(int i, int n, VI& nums) {
    if(i == n) {
        print(nums);
        nums.eb(i);
        print(nums);
        nums.pb();
        return;
    }
    dfs(i + 1, n, nums);
    nums.eb(i);
    dfs(i + 1, n, nums);
    nums.pb();
}

void solve() {
    int n;
    cin >> n;
    VI nums;
    dfs(1, n, nums);
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

