#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> cnt(m, vector<int> (n,0));
        auto count = [&](int x){
            bool flag = false;
            int firsti = 0;
            for(int i = 0; i < m; ++i){
                if(matrix[i][x] == 1){
                    if(flag) continue;
                    flag = true;
                    firsti = i;
                }else{
                    if(!flag) continue;
                    for(int j = firsti; j < i; ++j){
                        cnt[j][x] = i-j;
                    }
                    flag = false;
                }
            }
            if(flag){
                for(int j = firsti; j < n; ++j){
                     cnt[j][x] = n-j;
                }
            }
        };
        for(int i = 0; i < n; ++i)
            count(i);
        int ans = 0;
        for(int i = 0; i < m; ++i){
            vector<int> row;
            for(int j = 0; j < n; ++j)
                row.push_back(cnt[i][j]);
            sort(row.begin(), row.end());
            
            for(int j = 0; j < n; ++j)
                ans = max(ans, row[j]*(n-j));
        }
        return ans;
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