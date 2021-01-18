#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<ll> psum; 
    ll calc(int x, int y){
        if(x > y){
            return 0;
        }
        if(y < 0){
            return 0;
        }
        if(x <= 0){
            return psum[y];
        }else{
            
            return psum[y]-psum[x-1];
        }
    }
    int first_bound(vector<int>& nums, int li, int n, ll csum){
        int l = li;
        int r = n-1;
        while(1 < r-l){
            int mid = (l+r)>>1;
            
            ll s = calc(li, mid);
            if(s < csum){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        auto s1 = calc(li, r);
        auto s2 = calc(li, l);
        if(s2 >= csum){
            return l;
        }else{
            return r;
        }
    }
    int second_bound(vector<int>& nums, int li, int n, ll csum){
        int l = li;
        int r = n-1;
        while(r-l > 1){
            int mid = (l+r)>>1;
            ll s1 = calc(li, mid);
            ll s2 = calc(mid+1,n);
            if(max(csum,s1) > s2){
                r = mid;
            }
            if(max(csum, s1) <= s2){
                l = mid;
            }
        }
        ll s1 = calc(li, l);
        ll s2 = calc(l+1,n);
        if(max(csum,s1) > s2){
            return l;
        }
        if(max(csum, s1) <= s2){
            return l+1;
        }
        return r;
    }
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        psum.resize(n+2);         
        for(int i = 0; i < n; ++i){
            if(i > 0)
                psum[i] = psum[i-1];
            psum[i] += nums[i];
        }
        psum[n] = psum[n-1];
        ll csum = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            csum += nums[i];
            int l =first_bound(nums, i+1, n, csum);
            int r =second_bound(nums, i+1, n, csum);
            
            if(r > l && l > i && r > i && l < n && r < n){
                ans += r-l;
                ans %= 1000000007;
            }
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
    int n; cin >> n;
    vector<int> v(n);
    for(auto & x : v){
        cin >> x;
    }
    Solution u;
    cout << u.waysToSplit(v) <<endl;
    return 0;
}