#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXN 100010
class Solution {
public:
    vector<int> src, dst;
    vector<int> g[MAXN];
    int n;
    int visited[MAXN];
    int timestamp[MAXN];
    int values[MAXN];
    int vertices[MAXN];
    int sv = 0;
    int ctime;
    void dfs(int x){
        visited[x] = 1;
        if(timestamp[src[x]] < ctime){
            values[src[x]] = 1;
            timestamp[src[x]] = ctime;
        }else{
            values[src[x]] += 1;
        }
        
        if(timestamp[dst[x]] < ctime){
            values[dst[x]] = -1;
            timestamp[dst[x]] = ctime;
        }else{
            values[dst[x]] -= 1;
        }
        vertices[sv] = x;
        ++sv; 
        for(auto & y : g[x]){
            if(visited[y]){ continue;}
            dfs(y);
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        this->src =source;
        this->dst = target;
        memset(visited,0,sizeof(visited));
        memset(timestamp,0,sizeof(timestamp));
        memset(values,0,sizeof(values));
        this->ctime = 0;
        for(auto & x:allowedSwaps ){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        this->n = source.size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                ++this->ctime;
                this->sv = 1;
                dfs(i);
                for(int i = 1; i < this->sv; ++i){
                    if(values[src[vertices[i]]] > 0){
                        ans += values[src[vertices[i]]];
                    }else{
                        ans -= values[src[vertices[i]]];
                    }
                }
            }
        }
        return ans/2;
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}