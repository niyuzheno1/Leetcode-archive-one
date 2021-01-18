#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

#define MAXN (1<<17)
int f[MAXN];
int g[17];
int NR[MAXN];
vector<vector<int>> vii;
void decode (int state, int n){
        int q = 0;
        for(int i = 0; i < n; ++i)
            if((state & (1<<i)) == 0)
                g[++q] = i;
        g[0] = q;
        return ;
} 

vector<vector<int>> enumerate(vector<int> & nums, int n, int k, int depths, int pos){
    if(depths == k){
        vector<vector<int>> a;
        a.push_back(vector<int>());
        return a;
    }
    vector<vector<int>> ret;
    for(int i = pos; i < n; ++i){
        vector<vector<int>> vi = enumerate(nums, n ,k , depths + 1, i + 1);
        for(auto x : vi){
            vector<int> b = x;
            b.push_back(i);
            bool flag = true;
            int mm = b.size();
            for(int v = 0; v < mm; ++v)
                for(int w = 0; w < mm; ++ w)
                    if(nums[b[v]] == nums[b[w]] && v != w)
                        flag = false;
            if(flag)
                ret.push_back(b);
            
        }
    }
    if(depths != 0){
        return ret;
    }else{
        vector<vector<int>> finalized;
        for(int j = 0; j < ret.size(); ++j){
            bool flag = true;
            if(flag)
                finalized.push_back(ret[j]);
        }
        return finalized;
    }
}
int getmaxmin(vector<int> & nums, vector<int> & x, int k){
    int mmax = nums[x[0]], mmin = nums[x[0]];
    for(int i = 0; i < k; ++i)
    {
        mmax = max(nums[x[i]], mmax);
        mmin = min(nums[x[i]], mmin);
    }
    return mmax - mmin;
}
int dfs(int state, vector<int>& nums, int n, int k){
    if(state == ((1<<n)-1))
        return 0;
    if(f[state] != -2){
        return f[state];
    }
    decode(state, n);
    int ans = -1;
    for(int i = 0; i < vii.size(); ++i){
        if(NR[i] & state) continue;
        int newstate = state | NR[i];
        int m = getmaxmin(nums, vii[i], k);
        if (m > ans && ans != -1) continue;
        int p = dfs(newstate, nums, n, k);
        if (p == -1)
            continue;
        if ( ans == -1 || ans > m+p){
            ans = m + p;
        }
    }
    f[state] = ans;
    return ans;
}

int minimumIncompatibility(vector<int>& nums, int k) {
    int n = nums.size();
    vii = enumerate(nums,  n,n/k, 0, 0);
    for(int i = 0; i < vii.size(); ++i){
        for(int j = 0; j < vii[i].size(); ++ j)
            NR[i] |= (1<<vii[i][j]);
    }
    for(int i = 0; i<= ((1<<n)-1); ++i){
        f[i] = -2;
    }
    return dfs(0,nums, n, n/k);
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> nums; 
    rvector(nums);
    int k;
    cin >> k;
    cout<<minimumIncompatibility(nums, k);
    #ifndef ONLINE_JUDGE
    cout<<endl; fclose(stdin);fclose(stdout);
    #endif
    return 0;
}


string rline(){
    string ret;
    getline(cin,ret);
    return ret;
}
int rint(){
    int ret;
    cin >> ret;
    return ret;
}
long long rlong(){
    long long ret;
    cin >> ret;
    return ret;
}
void rvector(vector<int> & x){
    string aline = rline();
    replace(aline.begin(), aline.end(), ',', ' ');
    istringstream is(aline);
    while(!is.eof()){
        int y = 0; is>>y;
        x.push_back(y);
    }
}
char rchar(){
    char x; cin>>x; return x;
}