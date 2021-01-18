#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;



bool closeStrings(string word1, string word2) {
        vector<int> w1(27),w2(27);
        for(int i = 0; i < word1.length(); ++i){
            ++w1[word1[i]-'a'];
        }
        for(int i = 0; i < word2.length(); ++i){
            ++w2[word2[i]-'a'];
        }
        for(int i = 0; i < 27; ++i){
            if(w1[i] != 0 && w2[i] == 0)
                return false;
            if(w1[i] == 0 && w2[i] != 0)
                return false;
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        for(int i = 0; i < 27; ++i){
            if(w1[i] != w2[i])
                return false;
        }
        return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string a,b;
    cin >> a >>b;
    cout<<closeStrings(a,b);

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