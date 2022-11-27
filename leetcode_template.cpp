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
using PII = pair<int, int>;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define max_que priority_queue<int, vector<int>, less<int>>
#define min_que priority_queue<int, vector<int>, greater<int>>
#define max_pair_que priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
#define min_pair_que priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>