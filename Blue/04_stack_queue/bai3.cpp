#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    while(true) {
        int n;
        cin>>n;
        if(n == 0) break;
        queue<int> q;
        for(int i=1;i<=n;i++) {
            q.push(i);
        }
        cout<<"Discarded cards:";
        while(q.size() > 1) {
            int a = q.front();
            if(q.size() == 2) cout<<" "<<a;
            else cout<<" "<<a<<",";
            q.pop();
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int ans = q.front();
        cout<<endl;
        cout<<"Remaining card: "<<ans<<endl;
    }
}