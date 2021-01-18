#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
typedef pair<int,int> pii;
int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int n =  aliceValues.size();
    vector<pii> v;
    for(int i = 0; i < n; ++i){
        v.push_back(make_pair(aliceValues[i] + bobValues[i],i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    int ansx = 0, ansy = 0;
    for(int i = 0; i < n; ++i){
      if(i%2 ==0) ansx += aliceValues[v[i].second];
      if(i%2 ==1) ansy += bobValues[v[i].second];
    }
    if(ansx > ansy){
        return 1;
    }
    
    if(ansx == ansy){
        return 0;
    }
    
    if(ansx < ansy){
        return -1;
    }
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