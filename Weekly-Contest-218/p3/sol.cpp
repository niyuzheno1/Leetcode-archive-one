#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
ll power[30];
#define MODN 1000000007
int concatenatedBinary(int n) {
    power[0] = 1;
    for(int i = 1; i <= 30; ++i)
        power[i] = (power[i-1]*2)% MODN;
    int ans = 0;
    for(int i= 1; i <= n; ++i)
            for(int j= 30; j >= 0; --j)
                if (i & (1 << j)){
                    ans = (ans * power[j+1]) % MODN;
                    ans = (ans + i) % MODN;
                    break;
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