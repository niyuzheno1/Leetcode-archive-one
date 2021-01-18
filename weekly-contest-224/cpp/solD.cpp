#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef struct _state{
    int catx;
    int caty;
    int mousex;
    int mousey;
    int mouseturn;
    int howmanyturns;
    int getstate(){
        int ret = catx * 8 * 8 * 8 + caty * 8 * 8 + mousex * 8 + mousey;
        if(mouseturn) ret = -ret;
        return ret;
    }
}state;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
class Solution {
public:
    vector<string> g;
    map<int, int> visited;
    int cjump, mjump, n, m, fx, fy;
    bool within(int x, int y){
        if(x < 0 || y < 0 || x >= n || y >= m)
            return false;
        if(g[x][y] == '#') return false;
        return true;
    }
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        this->g = grid;
        this->cjump = catJump;
        this->mjump = mouseJump;
        state st;
        st.mouseturn = 1;
        st.howmanyturns = 0;
        bool mousewin = false;
        this->n = grid.size();
        this->m = grid[0].length();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 'C'){
                    st.catx = i;
                    st.caty = j;
                }
                if(grid[i][j] == 'M'){
                    st.mousex = i;
                    st.mousey = j;
                }
                if(grid[i][j] == 'F'){
                    fx = i;
                    fy = j;
                }
            }
        queue<state> q; 
        q.push(st);
        while(!q.empty()){
            auto x = q.front(); q.pop();
            if(visited[x.getstate()] == 1) continue;
            visited[x.getstate()] = 1;
            if(x.mouseturn == 1){
                for(int i = 0; i < 4; ++ i){
                    for(int j = 0; j <= mjump; ++j){
                        int nmx = x.mousex + dx[i] * j;
                        int nmy = x.mousey + dy[i] * j;
                        if(!within(nmx,nmy)) break;
                        if(nmx == x.catx && nmy == x.caty) continue;
                        if(nmx == fx && nmy == fy) {
                            mousewin = true;
                            break;
                        }
                        state y(x);
                        y.mousex = nmx;
                        y.mousey = nmy;
                        y.mouseturn ^=1;
                        y.howmanyturns ++ ;
                        q.push(y);
                    }
                    if(mousewin) break;
                }
                if(mousewin) break;
            }else{
                bool cuts = false;
                for(int i = 0; i < 4; ++ i){
                    for(int j = 0; j <= mjump; ++j){
                        int nmx = x.catx + dx[i] * j;
                        int nmy = x.caty + dy[i] * j;
                        if(!within(nmx,nmy)) break;
                        if(nmx == x.mousex && nmy == x.mousey){
                            cuts = true;
                            break;
                        }
                    }
                    if(cuts) break;
                }
                if(cuts) continue;
                for(int i = 0; i < 4; ++ i){
                    for(int j = 0; j <= mjump; ++j){
                        int nmx = x.catx + dx[i] * j;
                        int nmy = x.caty + dy[i] * j;
                        if(!within(nmx,nmy)) break;
                        state y(x);
                        y.mousex = nmx;
                        y.mousey = nmy;
                        y.mouseturn ^=1;
                        y.howmanyturns ++ ;
                        q.push(y);
                 
                    }
                    if(cuts) break;
                }
            }
        }
        return mousewin;
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