#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;

int maximumUniqueSubarray1(vector<int>& nums) {
    int n =  nums.size();
    int ans = nums[0];
    for(int i = 0; i < n; )
    {
        set<int> s; s.insert(nums[i]);
        int cur = nums[i];
        int j = i+1;
        for(; j < n; ++j){
            if(s.find(nums[j]) != s.end())  break;
            s.insert(nums[j]);
            cur += nums[j];
        }
        ans = max(ans, cur);
        i = j;
    }        
    return ans;
}
int maximumUniqueSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];  
    vector<int> su(n+1);
    vector<int> a(10010);
    for(int i = 0; i < n; ++i)
        su[i] = (i >= 1 ? su[i-1] : 0) + nums[i];
    for(int i = 0; i < 10000; ++ i)
        a[i] = -1;
    int l = 0, r = 0;
    int cur = 0;
    while(r < n){
        if(a[nums[r]] >= l){
            l = a[nums[r]]+1;
        }
        ans = max(ans, su[r] - (l >= 1? su[l-1] : 0) );
        a[nums[r]] = r;
        ++r;
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> v;
    rvector(v);
    cout << maximumUniqueSubarray(v);
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