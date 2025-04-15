#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int sum = 0;
    int l = 0;
    int ans = -1;
    for(int r = 0;r<n;r++) {
        sum+=a[r];
        while(sum > k) {
            sum-=a[l];
            l++;
        }
        ans = max(ans,r-l+1);
    }
    cout<<ans;
}