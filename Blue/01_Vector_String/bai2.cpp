#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    string s;
    cin>>s;
    int ans =s[0] != 'z' ?  min(s[0] - 'a','z' - s[0] + 1) : 1;
    for(int i=1;i<s.length();i++) {
        int tmp = abs(s[i] - s[i-1]);
        ans += min(tmp,26-tmp);
    }
        cout<<ans;
}