#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

#define MAXN 6
int dp[MAXN][MAXN][MAXN][MAXN];
int grid[MAXN][MAXN];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
bool within(int x,int y, int m, int n){
    return (x >= 0) && (y >= 0) && (x < m) && (y < n);
}

int dfs(int u, int v, int ins, int exs, int m, int n){
    if(v >= 0 && dp[u][v][ins][exs] >= 0)
        return dp[u][v][ins][exs];
    if(ins == 0 && exs == 0){
        return 0;
    }
    int ret = -MAXN * MAXN * 140;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
        if(!grid[i][j] && i *n + j > u * n + v){
           int scores = 0;
           int neighbor = 0;
           int t1 = -MAXN * MAXN * 140,t2 = -MAXN * MAXN * 140;
           for(int k = 0; k < 4; ++k)
           {
               int nx = i+dx[k], ny = j+dy[k]; 
               if(within(nx,ny, m,n) && grid[nx][ny]){
               scores += grid[nx][ny];
               ++neighbor;
               }
           } 
           grid[i][j] = -30;
           scores += (120-30*neighbor);
           if(ins > 0){
            t1 = dfs(i,j,ins-1,exs, m, n);
            t1 += scores;
             
            
            
           }
           scores -= (120-30*neighbor);
           grid[i][j] = 0;

           grid[i][j] = 20;
           scores += (40+20*neighbor);
           if(exs > 0){
            t2 = dfs(i,j,ins,exs-1, m, n);
            t2 += scores;
           }
           scores -= (40+20*neighbor);
           grid[i][j] = 0;
           t1 = max(t1,t2);
           if(ret < t1){
               ret = t1;
           }
        }
    if(ret < 0)
    {
        ret =0;
    }
    if(v >= 0)
        dp[u][v][ins][exs] = ret;
    return ret;
}

int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
    for(int i = 0; i< m; ++i)
        for(int j = 0; j < n; ++j)
            for(int k =0 ; k <= introvertsCount; ++k)
                for(int t = 0; t <= extrovertsCount; ++ t)
                    dp[i][j][k][t] = -1;
    int ans = dfs(0,-1,introvertsCount,extrovertsCount, m, n);
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int m,n,ins,exs;
    cin >> m >> n >> ins >> exs;
    cout<<getMaxGridHappiness(m,n,ins,exs);

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