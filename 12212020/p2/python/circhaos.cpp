//CIRCHAOS
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
      int t; cin>>t;    
          while(t--){
                int n,m,ans=0; cin>>n>>m;
                
                vector <int> a(m); 
                for(int i=0 ; i<m ; i++) cin>>a[i];
                sort(a.begin(), a.end());
                

                int GCD = a[0];
                for(auto i:a) GCD = gcd(GCD,i);

                if(GCD<n){
                     cout<<max(n-GCD,1LL*0)<<"\n";
                }else{
                     int largest_factor = 1;
                     for(int f=1 ; f*f <= GCD ; f++){
                         if(GCD%f==0){
                               largest_factor = max(largest_factor, max(f<=n ? f : 0, GCD/f <= n ? GCD/f : 0));
                         }
                     }
                        cout<<max(n-largest_factor,1LL*0)<<"\n";            
                }
        }
                   
}


