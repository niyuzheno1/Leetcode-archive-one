#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n+1);
    dp[0] = nums[0];
    for(int i = 1; i < n; ++i)
    {
        dp[i] = -0x7fffff;
        for(int j=max(0, i-k); j <= i-1; ++j)
            dp[i] = max(dp[i], dp[j] + nums[i]);
    }
    for(int i = 0; i < n; ++i)
        cout << dp[i] << endl;
    return dp[n-1];
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> v;
    rvector(v);
    int k ;
    cin >> k;
    cout << maxResult(v,k);

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