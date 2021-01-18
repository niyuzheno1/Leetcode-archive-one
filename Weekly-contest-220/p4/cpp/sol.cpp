#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <algorithm>
using namespace std;
#define mp make_pair
typedef pair<int,int> pii;
#define X first
#define Y second
#define MAXN 100010
int f[MAXN];
int find(int x){
    if(f[x] == x)
        return x;
    return (f[x] = find(f[x]));
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    f[x] = f[y];
}
bool question(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return true;
    else
    {
        return false;
    }
    
}

vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        std::sort(edgeList.begin(), edgeList.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {return a[2] < b[2];});
        vector<pii> qquery;
        for(int i = 0; i < n; ++i)
            f[i] = i;
        int q = queries.size();
        int m = edgeList.size();
        vector<bool> vb(q);
        for(int i = 0; i < queries.size(); ++i){
            qquery.push_back(mp (queries[i][2], i));
        }
        sort(qquery.begin(), qquery.end());
        int l = 0; 
        for (int i = 0; i < qquery.size(); ++ i){
            while(l < m && qquery[i].X > edgeList[l][2]){
                merge(edgeList[l][0], edgeList[l][1]);
                ++l;
            }
            vb[qquery[i].Y]= question(queries[qquery[i].Y][0], queries[qquery[i].Y][1]);
        }
        return vb;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int m;
    cin >> m;
    string s;
    getline(cin,s);
    vector<vector<int>> e;
    for(int i = 0; i < m; ++i)
    {
        vector<int> x; rvector(x);
        e.push_back(x);
    }
    
    int q;
    cin >> q;
    getline(cin,s);
    vector<vector<int>> qe;
    for(int i = 0; i < q; ++i)
    {
        vector<int> x; rvector(x);
        qe.push_back(x);
    }
     distanceLimitedPathsExist(n, e, qe);
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