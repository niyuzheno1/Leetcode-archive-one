#include <iostream>
#include <vector>
#include <string>
#define MAXN 13
#define MAXPN (1<<12)
using namespace std;
class Solution {
public:
    int f[MAXPN], k,n, g[MAXN][MAXPN];
    void enumerate(vector<int> & jobs){
        
        for(int i = 0; i < (1<<n); ++i){
            f[i] = 0;
            for(int j = 0; j < n; ++j){
                if((1<<j) & i){
                    f[i] += jobs[j];
                }
            }
        }
    }
    int dfs(int x, int selected){
        if(x > k){
            if(selected == ((1<<n)-1)){
                return 0;
            }
            return INT_MAX;
        }
        if(g[x][selected] >= 0){
            return g[x][selected];
        }
        if(selected == (1<<n)-1){
            return INT_MAX;
        }
        int retx = INT_MAX;
        int mask = ((1<<n)-1)^selected;
        for(int i = mask; i  ; i = (i-1) & mask)
        {
            int sums = f[i];
            int ret = dfs(x+1, selected | i);
            sums = max(sums, ret);
            retx = min(sums, retx);
        }
        return g[x][selected]=retx;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        this->n = jobs.size();
        enumerate(jobs);
        this->k = k;
        for(int i = 0; i <= k+1; ++i){
            for(int j = 0; j < (1<<n); ++j){
                g[i][j] = -1;
            }
        }
        
        return dfs(1,0);
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n; cin >> n;
    vector<int> a(n);
    for(auto & x : a) cin >> x;
    Solution sol;
    cout << sol.minimumTimeRequired(a,6);
    return 0;
}