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
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
   int l=0;
   int r=n-1;
   int sum1=0;
   int sum2=0;
   int i=0;
   while(l<=r) {
    if(i%2 == 0 ){
        if(a[l] > a[r]) {
            sum1+=a[l];
            l++;
        }else{
            sum1+=a[r];
            r--;
        }
    }else{
        if(a[l] > a[r]) {
            sum2+=a[l];
            l++;
        }else{
            sum2+=a[r];
            r--;
        }
    }
    i++;
   }
   cout<<sum1<<" "<<sum2;
}