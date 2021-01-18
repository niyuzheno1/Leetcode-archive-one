#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n = 100;

int main()
{
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int * a;
    a = new int[n+2];
    a[0] = 0;
    a[1] = 1;
    for(int i = 0; i <= n; ++i){
        if(2*i > n)
            continue; 
        a[2*i] = a[i];
        if(2*i+1 > n)
            continue; 
        a[2*i+1] = a[i] + a[i+1];
    }
    int m;
    cin>>m;
    int ans = 0;
    for(int i = 0; i <= m; ++i){
        ans = max(ans, a[i]);
    }
    cout << ans <<endl;
    return 0;
}