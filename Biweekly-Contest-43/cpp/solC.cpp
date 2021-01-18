#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int ans[100];
    int picked[21];
    int ng;
    bool dfs(int x, int ne, int su, int cnt){
        if(cnt >= ng){
            return true;
        }
        if(){
            picked[su] = 1;
            ans[x-1] = su;
            ans[x-1-su] = su;
            picked[su] = 0;
            
        }
    }

    vector<int> constructDistancedSequence(int n) {
        for(int i = 0; i < 100; ++i) ans[i] = 0;
        for(int i = 0; i < 20; ++i) picked[i] = 0;
        this->ng = n;
        ans[0] = n;
        ans[n] = n;
        picked[n] = 1;
        dfs(n-1, n-1, n-2, 1);
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