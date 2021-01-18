#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

int cnt[1010];
int f[2048];
vector<int> a;



bool dfssolver(vector<int> & quantity, int idx){
    if(idx >= quantity.size())
        return true;

    bool ret = false;
    for(int j = 0; j < a.size(); ++j){
            if(a[j] >= quantity[idx]){
                a[j] -= quantity[idx];
                ret =  ret || dfssolver(quantity, idx+1);
                if(ret)
                    return ret;
                a[j] += quantity[idx];
            }
    }
    return ret;
}

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        for(int i = 0; i < nums.size();++i)
            ++cnt[nums[i]];
        for(int i = 1; i <= 1000; ++i)
            if(cnt[i] != 0){
                a.push_back(cnt[i]);
            }
        int m = quantity.size();
        //sort(a.begin(), a.end());
        sort(quantity.begin(), quantity.end());
        reverse(quantity.begin(), quantity.end());
        return dfssolver(quantity,  0);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> nums,quant;
    rvector(nums);
    rvector(quant);
    
    cout << canDistribute(nums,quant);

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