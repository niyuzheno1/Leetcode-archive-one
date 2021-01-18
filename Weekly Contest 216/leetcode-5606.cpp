#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;
#define MAXN 100010
char ourstring[MAXN];

string getSmallestString(int n, int k) {
    string ret;
    
    for(int i = 0; i < n; ++i){
        ourstring[i] = 'a';
        --k;
    }
    int i = 0;
    while(k){
        if(k <= 25){
            ourstring[i] += k;
            break;
        }
        ourstring[i] = 'z';
        ++i;
        k -= 25;
    }
    ret = ourstring;
    reverse(ret.begin(), ret.end()); 
    return ret;       
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;

    cout << getSmallestString(n,k);
    

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