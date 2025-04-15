#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int n;
    int k;
    cin >> n >> k;
    int a[2 * n];
    for(int i = 0; i < 2 * n; i++) cin >> a[i];
    sort(a, a + 2 * n,greater<int>());
    double nu  = min(a[n-1]/2.0,a[2*n - 1]*1.0);
    double ans =1.0*nu*3*n;
    if(ans > k*1.0) {
        cout<<k;
    }else{
         cout << setprecision(9)<<ans;
    }
}


