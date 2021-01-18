#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, int> cmap;

int main()
{
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i){
        ++cmap[s[i]];
    }
    int ans = 0;
    while(true){
        map<int,bool> exists;
        bool flag = true;
        for(int i = 'a'; i <= 'z'; ++i)
        {
            if(cmap[i] == 0)
                continue;
            if(exists[cmap[i]]){
                flag = false;
                --cmap[i];
                ++ans;
                break;
            }
            exists[cmap[i]] = true;
        }
        if(flag == true)
            break;
    }
    cout << ans << endl;
    return 0;
}