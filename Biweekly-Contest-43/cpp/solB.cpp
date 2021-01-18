#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    char gv(char c, int x, int y){
        if(x>y){
            if(c == 'a')
                return 'a';  
            if(c == 'b')
                return 'b';
        }else{
            if(c == 'b')
                return 'a';
            if(c == 'a')
                return 'b';
        }
        return '$';
    }
    int maximumGain(string s, int x, int y) {
        
        s = s + '$';
        int n = s.length();
        string proc;
        stack<char> st;
        stack<char> st2;
        int res = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] != 'a' && s[i] != 'b'){
                st.push('$');
            }
            if(gv(s[i],x,y) == 'a'){
                st.push('a');
            }
            if(gv(s[i],x,y) == 'b'){
                if(!st.empty() && st.top() == 'a'){
                    st.pop();
                    res += max(x,y);
                }else{
                    st.push('b');
                }
            }
        }
        while(!st.empty()){
            if(st.top() != 'a' && st.top() != 'b'){
                st2.push('$');
                st.pop();
                continue;
            }
            if(st.top() == 'b'){
                if(!st2.empty() && st2.top() == 'a'){
                    st.pop();
                    res += min(x,y);
                    st2.pop();
                }else{
                    st.pop();
                    st2.push('b');
                }
            }else if(st.top() == 'a'){
                st.pop();
                st2.push('a');
            }
        }
        return res;
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    Solution sol;
    sol.maximumGain("aaaabbb", 4, 5);
    return 0;
}