#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
using namespace std;

typedef pair<int,int> pii;

int a[100010];

int findx(int x, int l, int r){
    int mid;
    ++l;++r;
    while(l < r){
        mid = (l+r)>>1;
        if(mid-1 == -1)
            return -1;
        if(a[mid-1] == x)
            return mid-1;
        if(a[mid-1] > x){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    mid = ((l+r)>>1);
    if(mid-1 == -1)
            return -1;
    if(l >= r && a[mid-1] != x)
        return -1;
    else
    {
        return mid-1;
    }
    
}

int minOperations(vector<int>& nums, int x) {
        int ret = -1;
        int n = nums.size();
        int y = 0;
        for(int i = 0; i < n;++i){
            y+= nums[n-i-1];
            a[n-i-1] = y;
        }
        y = 0;
        int u = findx(x,0,n-1);
        if(u != -1){
            ret = n-u;
        }
        for(int i = 0; i <n ;++i){
            y+= nums[i];
            int z = x-y;
            if(z == 0){
                int cmpx = i+1;
                if(cmpx < ret || ret == -1){
                    ret = cmpx;
                }
            }
            u = findx(z,0,n-1);
            if(u != -1){
                int cmpx = i+1;
                cmpx += n-u;
                if(cmpx > n)
                    continue;
                if(cmpx < ret || ret == -1){
                    ret = cmpx;
                }
            }   
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
    int x;cin>>x;
    cout << minOperations(a,x);
    

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