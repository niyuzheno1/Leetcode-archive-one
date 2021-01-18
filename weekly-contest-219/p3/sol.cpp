#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

#define MAXN 1010
int f[MAXN][MAXN][2];
bool st[MAXN][MAXN][2];

int dfs(vector<int>& a, int x, int y, int p){
    if(y <= x)
        return 0;
    if(st[x][y][p] != 0)
        return f[x][y][p];
    st[x][y][p] = 1;
    if(p == 0){
        int diff = x-1 < 0 ? 0 : a[x-1];
        f[x][y][p] = max(a[y]-a[x] + dfs(a,x+1,y,1), a[y-1]-diff + dfs(a,x,y-1,1));
    } 
    if(p == 1){ 
        int diff = x-1 < 0 ? 0 : a[x-1];
        f[x][y][p] = min( dfs(a,x+1,y,0)-(a[y]-a[x]),   dfs(a,x,y-1,0)- (a[y-1]-diff));
    }
    return f[x][y][p];
}

int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> ps(n);
        ps[0] = stones[0];
        for(int i = 1; i < n; ++i)
            ps[i] = ps[i-1] + stones[i];
        memset(st,0,sizeof(st));
        dfs(ps, 0, n-1, 0);
        return f[0][n-1][0];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> v;
    rvector(v);

    cout << stoneGameVII(v);

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