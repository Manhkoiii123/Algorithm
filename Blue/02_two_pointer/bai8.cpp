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
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int l=0;
    int r=n-1;
    int A=0,B=0;
    int sumA=a[l];
    int sumB=a[r];
    while(l<r) {
        if(sumA < sumB) {
            l++;
            sumA+=a[l];
            A++;
        }else if(sumA >= sumB){
            r--;
            sumB +=a[r];
            B++;
        }
    }
    if(l==r && sumA == sumB) {
        A++;
    } else if(sumA > sumB) {
        B++;
    }else{
        A++;
    }
    cout<<A<<" "<<B;
}
