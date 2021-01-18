#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> a(n+2);
    vector<int> b(n+2);
    for(int i = 0; i < n; ++i)
        a[i] = b[i] = 1;
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < i; ++j)
            if(nums[j] < nums[i]){
                a[i] = max(a[i], a[j] + 1);
            }
    }
    for(int i = n-1; i >=0 ; --i){
        for(int j = n-1; j > i; --j){
            if(nums[j] < nums[i]){
                b[i] = max(b[i],b[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < n-1; ++i)
        ans = max(ans,a[i]+b[i]);
    return n - ans + 1;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> a;
    rvector(a);
    cout << minimumMountainRemovals(a) << endl;

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