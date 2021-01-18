#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

#define MAXN 100010

int pre[2][MAXN];
int post[2][MAXN];

int waysToMakeFair(vector<int>& nums) {
    int ret = 0;
    memset(pre,0,sizeof(pre));
    memset(post,0,sizeof(post));
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        if(i == 0)
        {
            pre[i & 1][i] = nums[i];
            pre[(~i) & 1][i] = 0;
        }else{
            pre[i & 1][i] = pre[i & 1][i-1] + nums[i];
            pre[(~i) & 1][i] = pre[(~i) & 1][i-1];
        }
    }
    for(int i = n-1; i >= 0; --i){
        post[i & 1][i] = post[i & 1][i+1] + nums[i];
        post[(~i) & 1][i] = post[(~i) & 1][i+1];
    }
    for(int i = 1; i < n;++i){
        if(pre[0][i-1] + post[1][i+1] == pre[1][i-1]+post[0][i+1])
        {
            ++ret;
        }
    }
    if( post[1][1] == post[0][1])
    {
            ++ret;
    }
    return ret;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> a;
    rvector(a);
    cout<<waysToMakeFair(a);
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