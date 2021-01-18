#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
typedef pair<int,int> pii;
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> presum(n+2);
    vector<int> sufsum(n+2);
    vector<int> ans(n+2);
    vector<pii> s; 
    for(int i = 0; i < nums.size(); ++ i)
        s.push_back(make_pair(nums[i],i));
    sort(s.begin(),s.end());
    presum[0] = s[0].first;
    for(int i = 1; i < n; ++ i)
        presum[i] = presum[i-1] + s[i].first;
    sufsum[n-1] = s[n-1].first;
    for(int i = n-2; i >= 0; -- i)
        sufsum[i] = sufsum[i+1] + s[i].first;
    for(int i = 0; i < n; ++i){
        ans[s[i].second] += presum[i] - (i+1)* s[i].first;
        ans[s[i].second] += sufsum[i+1] - (n-i-1)* s[i].first;
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    

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