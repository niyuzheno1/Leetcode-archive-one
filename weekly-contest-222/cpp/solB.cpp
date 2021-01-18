#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
#define MODN 1000000007
typedef long long ll;
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<ll,ll> f;
        int n = deliciousness.size();
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            for(ll j = 0; j < 41; ++j){
                ll u = 1LL << j;
                ans += f[u-deliciousness[i]];
                ans %=MODN;
            }
            ++f[deliciousness[i]];
        }
        return ans;
    }
};

int main()
{
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}