#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int check(string & s, int * dp, int x, int y, int ldim){
        if(x > y){
            return 1;
        }
        if(x == y){
            return 1;
        }
        if(dp[x * ldim + y ] != -1)
            return dp[x * ldim + y ];
        if(s[x] == s[y]){
            dp[x * ldim + y ]  = check(s, dp, x+1, y-1, ldim);
        }else{
            dp[x * ldim + y ] = 0;
        }
        return dp[x*ldim + y];
    }
    string longestPalindrome(string s) {
        int * dp = new int [(s.length()+10)*(s.length()+10)];
        int ldim = s.length()+1;
        for(int i = 0; i < s.length(); ++ i)
            for(int j = i; j < s.length(); ++ j)
                dp[ i * ldim + j] = -1;
        int ans = 0, ansx = 0, ansy = 0;
        for(int i = 0; i < s.length(); ++ i)
            for(int j = i; j < s.length(); ++ j)
             { 
                   int u = check(s, dp, i, j, ldim);
                   if(u == 1){
                       if(j-i+1 > ans){
                           ans = j-i+1;
                           ansx = i;
                           ansy = j;
                       }
                   }
             }
        string ret = "";
        for(int i = ansx; i <= ansy; ++i)
        {
            ret += s[i];
        }
        return ret;

    }
};

Solution sol;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s; 
    cin >> s;
    cout << sol.longestPalindrome(s);
    return 0;
}