#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;


#define MAXN 10005


typedef struct _Node { 
    int value = -1; 
}Node; 
  
map<pair<int,bool>,Node> f;


void dfs(int state, int a, int b, int x, int depth, bool inarow){
    if(state > MAXN)
        return;
    if(state < 0)
        return;
    pair<int,int> st = make_pair(state , inarow);
    if( (depth >= f[st].value && f[st].value >= 0) )
        return;
    Node xxx;
    xxx.value = depth;
    f[st] = xxx;
    
    if(state == x) return;
    if(inarow){
        dfs(state + a, a, b, x, depth + 1, false);
    }else{
        dfs(state + a, a, b, x, depth +1 , false);
        dfs(state - b, a, b, x, depth +1 , true);
    }
}

int smin(int x, int y){
    if(x== y && x == -1)    return -1;
    if(x == -1) x = MAXN;
    if(y == -1) y = MAXN;
    return min(x,y);
}

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        for(int i = 0; i < forbidden.size(); ++ i){
            Node xxx;
            xxx.value = 0;
            f[make_pair(forbidden[i],0)] = f[make_pair(forbidden[i],1)] = xxx;
        }
        
        dfs(0, a, b, x, 0, false);
        return smin(f[make_pair(x,0)].value,f[make_pair(x,1)].value);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> fx;
    rvector(fx);
    int a = rint(), b = rint(), x  = rint();
    cout << minimumJumps(fx,a,b,x);    

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