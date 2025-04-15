#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    while(true) {
        int n; cin >> n;
        if(n == 0) break;
        stack<int> st;
        int a[n+1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        int cnt = 1;
        for(int  i = 1; i <= n; i++) {
            if(a[i] == cnt) {
                cnt++;
                while(!st.empty() && st.top() == cnt) {
                    cnt++;
                    st.pop();
                }
            }else if(a[i] > cnt) {
                st.push(a[i]);
            }else{
                while(!st.empty() && st.top() == cnt) {
                    cnt++;
                    st.pop();
                }
            }
        }
        if(st.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}