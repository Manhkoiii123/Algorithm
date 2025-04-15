#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e5+7);

int main(){
    int n;
    cin>>n;
    int a[n],sorted[n];
    int rank[MOD] = {0};
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        a[i] = x;
        sorted[i] = x;
    }
    sort(sorted,sorted+n,greater<int>());
    for(int i=0;i<n;i++) {
       int rate = sorted[i];
        if(rank[rate] == 0) {
            rank[rate] = i+1;
        }
    }
    for(int i=0;i<n;i++) {
        cout<<rank[a[i]]<<' ';
    }
}