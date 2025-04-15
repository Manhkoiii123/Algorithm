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
    int a[13];
    for(int i=1;i<=12;i++) {
       cin>>a[i];
    }
    
    sort(a+1,a+13,greater<int>());
    if(n == 0) {
        cout<<0;
        return 0;
    }
    int sum = 0;
    for(int i=1;i<=12;i++) {
        sum += a[i];
        if(sum >= n) {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}