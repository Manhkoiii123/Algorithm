#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int n;
    cin>>n;
    int L[n];
    for(int i=0;i<n;i++) cin>>L[i];
    int i=n-1,j=n-1;
    int last_kill =0;
    int cnt_killed = 0;
    for(int i=n-1;i>0;i--) {
        j = min(j,i);
        last_kill = max(0,i-L[i]);
        if(j>last_kill) {
            cnt_killed+=(j-last_kill);
            j=last_kill;
        }
    }
    cout<<n-cnt_killed;
}

