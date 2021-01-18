#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
using namespace std;

#define mp make_pair

pair<int,int> next(int l, int m, int r){
    if(m == 1 && r == -1)
        return mp(0,0);
    if(m == -1 && l == 1)
        return mp(0,0);
    if(m == 1 && r == 1)
        return mp(1,1);
    if(m == -1 && l == -1)
        return mp(1,-1);
}

int drop(vector<vector<int>>& grid, int n, int m, int x, int y){
    while(x >= 0 && y >= 0 && x < n && y < m){
        int l, m, r; 
        m = grid[x][y];
        if(y == 0)
            l = 1;
        else{
            l = grid[x][y-1];
        }
        if(y == n-1)
            r = -1;
        else
        {
            r = grid[x][y+1];
        }
        auto xx =next(l,m,r);
        if(xx.first == 0 && xx.second == 0)
            break;
        x += xx.first;
        y += xx.second;
    }
    if(x == n+1){
        return y;
    }else
        return -1;
} 


vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ret;
        for(int i = 0; i < m; ++i){
            ret.push_back(drop(grid, n, m, 0, i));
        }
        return ret;
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