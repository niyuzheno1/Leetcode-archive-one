#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;
#define MAXN 2*100010
int suma[MAXN];
int sumb[MAXN];
int sumc[MAXN];
int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int j = n - i -1;
            if ( j < i)
                break;
            suma[nums[i]+nums[j]] += 2;
            int nx = max(nums[i],nums[j]);
            sumb[nx + limit] += 1;
            nx = min(nums[i], nums[j]);
            sumc[1+nx] += 1;
        }
        for(int i = 1; i < MAXN; ++i){
            suma[i] = suma[i]+suma[i-1];
            sumb[i] = sumb[i]+sumb[i-1];
            sumc[i] = sumc[i]+sumc[i-1];
        }
        int ans =MAXN*2;
        for(int i = 0; i < n; ++i)
        {
            int j = n - i -1;
            int s = nums[i]+nums[j];
            int hm = 0;
            if(s >0)
                hm = suma[MAXN-1]-suma[s-1];
            else
                hm = suma[MAXN-1];
            hm/=2;
            //case 1:
            int u = suma[s-1] - (sumb[MAXN-1]-sumb[s-1]-hm);
           

            //case2:
            if(s > 0)
                hm = suma[s];
            else
                hm = 0;
            hm /= 2;
            int v = suma[MAXN-1]-suma[s] - (sumc[s] - hm);
            if(ans > MAXN)
                ans = u+v;
            else
                ans = min(ans,u+v);
        }
        return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> a;
    int l; 
    rvector(a);
    cin >> l;
    cout<<minMoves(a,l);

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