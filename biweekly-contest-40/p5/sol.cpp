#include <cstdio>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tcases; 
    cin >> tcases;
    for(int jj = 0; jj < tcases; ++ jj ){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n ;++i)
            cin >> v[i];
        #define movenext(x) (x+1)%n;
        int ans = 0;
        int gas = v[0];
        v[0] = 0;
        int pos = 0;
        while((gas-1)>=0){
            ++ans;
            pos = movenext(pos);
            gas += v[pos];
            v[pos] = 0;
            --gas;
        }
        cout << ans <<endl;

    }

    #ifndef ONLINE_JUDGE
    cout<<endl; fclose(stdin);fclose(stdout);
    #endif
    return 0;
}


string rline(){
    string ret;
    getline(cin,ret);
    return ret;
}
int rint(){
    int ret;
    cin >> ret;
    return ret;
}
long long rlong(){
    long long ret;
    cin >> ret;
    return ret;
}
void rvector(vector<int> & x){
    string aline = rline();
    replace(aline.begin(), aline.end(), ',', ' ');
    istringstream is(aline);
    while(!is.eof()){
        int y = 0; is>>y;
        x.push_back(y);
    }
}
char rchar(){
    char x; cin>>x; return x;
}