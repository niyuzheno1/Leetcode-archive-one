#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

typedef pair<int,int> pii;
#define MAXN 100010
int f[MAXN][32];

void process(vector<pii> & nums, int n){
    for(int i = 0 ; i < n; ++i)
        f[i][0] = i;
   for (int j = 1; (1 << j) <= n; ++j){
       for(int i = 0; (i+(1<<j) - 1) < n; ++i)
            if(nums[f[i][j-1]] < nums[f[i+(1<<(j-1))][j-1]])
                f[i][j] = f[i][j-1];
            else
                f[i][j] = f[i+(1<<(j-1))][j-1];    
   }
}

int q(vector<pii> & nums, int l, int r){
    int j = (int)log2(r-l+1);
    if (nums[f[l][j]] <= nums[f[r-(1<<j)+1][j]])
        return f[l][j];
    else
        return f[r-(1<<j)+1][j];
}

vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        vector<int> a(n+1);
        vector<pii> b;
        for(int i = 0; i < n; ++i)
            b.push_back(make_pair(nums[i],i));
        process(b,n);
        int l = -1;
        for(int u = k; u > 0; --u){
            l = q(b,l+1,n-u);
            ret.push_back(nums[l]);
        }

        // sort(b.begin(),b.end());
        // for(int i = k; i < n; ++i)
        //     a[b[i].second] = 1;
        // for(int i = 0; i < n; ++i)
        //     if (a[i] == 0)
        //         ret.push_back(nums[i]);
        return ret;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> a;
    rvector(a);
    int k;
    cin >> k;
    vector<int> ret = mostCompetitive(a,k);
    for(int i = 0; i< ret.size(); ++i)
        cout << ret[i] << endl;

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