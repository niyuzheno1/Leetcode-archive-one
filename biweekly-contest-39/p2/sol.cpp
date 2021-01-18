#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;
//bbabb
//12233
//11100

int minimumDeletions(string s) {
    int ret = s.length()+1;
    int n = s.length();
    vector<int> a(n+2);
    vector<int> b(n+2);
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'b')
            b[i+1] = b[i] + 1;
        else
            b[i+1] = b[i];
    }
    b[n+1] = b[n];
    for(int i = 0; i < s.length(); ++i){
        int j = n-i-1;
        if(s[j] == 'a')
            a[j+1] = a[j+2] + 1;
        else
            a[j+1] = a[j+2];
    }
    a[0] = a[1];
    ret = min(a[0],b[n+1]);
    for(int i = 1; i <= n ; ++i){
        ret = min(ret,b[i-1] + a[i+1]);
    }
    return ret;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >>s;    
    cout << minimumDeletions(s);
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