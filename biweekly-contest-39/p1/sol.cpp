#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

int addorsub(int x, int y){
    x =  x % y;
    while(x < 0){
        x += y;
    }
    return x;
}

vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(), m = abs(k);
        vector<int> ret(n);
        int signs = 0;
        if(k > 0) signs = 1; else signs = -1;
        for(int i = 0; i<n;++i){
            for(int j = 1; j <= m; ++j){
                 ret[i] += code[addorsub(i+signs *j,n)];
            }
        }
        return ret;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> code;
    rvector(code);
    int k = rint();
    vector<int> d = decrypt(code,k);
    for(int i = 0; i < d.size(); ++i){
        cout << d[i] << " ";
    }
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