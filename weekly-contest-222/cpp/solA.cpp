#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    return 0;
}

        while(1 < r-l){
            int mid = (l+r)>>1;
            
            ll s = calc(li+1, mid);
            if(s < csum){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        auto s1 = calc(li+1, r);
        auto s2 = calc(li+1, l);
        if(s2 > csum){
            return l;
        }else{
            return r;
        }

        int l = li;
        int r = n-1;
        while(1 < r-l){
            int mid = (l+r)>>1;
            
            ll s1 = calc(mid,n);

            ll s2 = calc(li+1,mid-1);
            if(max(s2,csum) > s1){
                r = mid-1;
            }else{
                l = mid;
            }
        }
        ll s1 = calc(l,n);
        ll s2 = calc(li+1,l-1);
        if(max(s2,csum) > s1)  return r;
        return l;