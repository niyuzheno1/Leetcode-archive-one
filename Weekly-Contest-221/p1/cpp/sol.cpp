#include <cstdio>
#include <iostream>
#include "console.h"
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair
int eatenApples(vector<int>& apples, vector<int>& days) {
    priority_queue<pii> pq;
    int d = 1;
    int n = apples.size();
    int i = 0;
    int appleret = 0;
    while(i < n){ 
        
        while(i < d && i < n){
            if(apples[i] > 0)
                pq.push(mp(-(i+1+days[i]), i));
            ++i;
        }
        if(pq.empty()){
            d = d + 1;
        }
       while(!pq.empty()){
            int pbefore = d;
            auto x = pq.top().second;
            if (days[x] + x + 1 > d){
                if (days[x] + x + 1 - d + 1 < apples[x]){
                    appleret += days[x] + x + 1 - d + 1;
                    d = days[x] + x + 1;
                }else{
                    appleret += apples[x];
                    d += apples[x];
                }
                
            }
            pq.pop();
        }
    }
    return appleret;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> a1, a2;
    rvector(a1);
    rvector(a2);
    eatenApples(a1,a2);
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