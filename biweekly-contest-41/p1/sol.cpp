#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    map<char, int> a; 
    for(int i = 0; i < allowed.length(); ++ i){
        a[allowed[i]] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < words.size(); ++i){
        int c = 1;
        for(int j = 0; j < words[i].length(); ++j){
            if(a[words[i][j]] == 0) c = 0;
        }
        cnt += c;
    }
    return cnt;
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