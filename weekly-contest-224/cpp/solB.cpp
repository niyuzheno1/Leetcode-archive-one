#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

typedef pair<int,int> pii;
#define Y second
class Solution {
public:
    map<int, int> products;
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                ++products[nums[i]*nums[j]];
            }
        }
        int ans = 0;
        for(auto & x: products){
            //? div 2
            ans += ((x.Y * (x.Y-1))>>1)*2*2*2;
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