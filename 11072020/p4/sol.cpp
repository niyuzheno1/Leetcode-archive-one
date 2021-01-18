#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
#define MODN 1000000007
vector<int> inventory; 
int orders;

long long sum(long long a, long long  b, long long c){
    long long ans = ((a+b) *(b-a+1))%MODN;
    ans = (ans * 500000004)%MODN;
    return ((c * ans)%MODN);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string ar;
    getline(cin,ar);
    istringstream ia(ar);
    while(!ia.eof()){
        int x;
        ia>>x;
        inventory.push_back(x);
    }
    cin>>orders;
    sort(inventory.begin(),inventory.end());
    long long ans = 0;
    long long ord = orders;
    int b = inventory.size()-1;
    long long cnt = 1;
    while(ord){
        
        
        long long inv = inventory[b];
        
        while(b > 0){
            if(inventory[b] != inventory[b-1])
                break;
            --b;
            ++cnt;
        }
        long long now =0;
        if(b-1 >= 0)
            now = inventory[b-1];
        if(inv == 0)
            break;
        if((inv-now)*cnt > ord){
            long long tmpcnt = 0;
            long long a = ord / cnt;
            long long b = ord % cnt;
            tmpcnt = (inv-a)*b;
            tmpcnt %= MODN;
            tmpcnt += sum(inv-a+1, inv, cnt);
            tmpcnt %= MODN;
            ans = ans + tmpcnt;
            ans %= MODN;
            break;
        }else{
            ord -= (inv-now)*cnt;
            inventory[b] = now;
            ans = ans+sum(now+1,inv,cnt);
            ans %= MODN;
        }
    }
    cout << ans <<endl;
    return 0;
}