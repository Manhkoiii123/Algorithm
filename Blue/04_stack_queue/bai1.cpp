#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        stack<char> st;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(') st.push(s[i]);
            else if(isalpha(s[i])) {
                cout<<s[i];
            }else if(s[i] == ')') {
                while(st.top() != '(') {
                    cout<<st.top();
                    st.pop();
                }
                st.pop();
            }else {
                st.push(s[i]);
            }
        }
        cout<<endl;
    }
}