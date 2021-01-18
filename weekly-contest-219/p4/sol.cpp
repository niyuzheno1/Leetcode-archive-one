#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
#define MAXN 110
typedef pair<int,int> pii;
typedef pair<pii, pii> pit;
typedef pair<pit, pii> pitt;
map<pitt, int> f[MAXN];

struct pt{
    int x;
    int y;
    int z;
};

vector<pt> generateheightandwidth(vector<int> & x){
    int myints[] = {1,2,3};
    vector<pt> ret;
    do {
     pt tmp;
     tmp.x = x[myints[0]-1];
     tmp.y = x[myints[1]-1];
     tmp.z = x[myints[2]-1];
     ret.push_back(tmp);
    } while ( std::next_permutation(myints,myints+3) );
    return ret;
}
#define mp make_pair 

#define update(x,y) if(x < y) x = y;
int maxHeight(vector<vector<int>>& cuboids) {
    int n = cuboids.size();
    int ans = 0;
     for(int i = 0; i < n; ++i) f[i].clear();
    for(int i = 0; i < n; ++i){
       vector<pt> it =  generateheightandwidth(cuboids[i]);
       for(int j = 0; j < it.size(); ++j){
        f[i][mp(mp(mp(it[j].x,it[j].y),mp(it[j].x,it[j].y)),mp(it[j].z,it[j].z))] = it[j].z;
        ans = max(ans,f[i][mp(mp(mp(it[j].x,it[j].y),mp(it[j].x,it[j].y)), mp(it[j].z,it[j].z))]);
       }
    for(int k = 0; k < it.size(); ++k)
       for(int j = 0; j < i; ++j){
           for(auto u : f[j]){
               if(u.first.first.first.first >= it[k].x && u.first.first.first.second >= it[k].y && u.first.second.first >= it[k].z){
                   update(f[i][mp(mp(mp(it[k].x,it[k].y), u.first.first.second), mp(it[k].z, u.first.second.second))], u.second + it[k].z)
                   update(ans, f[i][mp(mp(mp(it[k].x,it[k].y), u.first.first.second), mp(it[k].z, u.first.second.second))]);
                   
               }
               if(u.first.first.second.first <= it[k].x && u.first.first.second.second <= it[k].y && u.first.second.second <= it[k].z){
                   update(f[i][mp(mp(u.first.first.first, mp(it[k].x,it[k].y)), mp(u.first.second.first, it[k].z))], u.second + it[k].z);
                   update(ans, f[i][mp(mp(u.first.first.first, mp(it[k].x,it[k].y)), mp(u.first.second.first, it[k].z))]);
               }
           }
       }
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    string s;
    getline(cin, s);
    vector<vector<int>> b;
    while(n --){
        vector<int> t;
        rvector(t);
        b.push_back(t);
    }
    cout << maxHeight(b);
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