#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 20;

int g[20][20];

int f[1<<N][N];

int main() {
    int n;
    memset(f, 0x3f, sizeof f);
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &g[i][j]);
    f[1][0] = 0;
    int S = (int)pow(2, n) - 1;
    for(int i=2;i<=S;i++) {
        for(int j=0;j<n;j++) {
            if((i >> j & 1) == 0) continue;
            int s = i - (1<<j);
            for(int k=0;k<n;k++) {
                if((s >> k & 1) == 0) continue;
                if(g[k][j]) f[i][j] = min(f[i][j], f[s][k] + g[k][j]);
            }
        }
    }
    cout << f[S][n-1] << endl;
    return 0;
}