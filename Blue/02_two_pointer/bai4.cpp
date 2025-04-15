#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    int a[n],b[k];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<k;i++) cin>>b[i];
    vector<pii>v;
    int i=0,j=0;
    int ans = 0;
    while(i<n && j< k) {
        if(a[i] - x <= b[j] && b[j] <= a[i] + y){
            v.push_back({i+1,j+1});
            i++;
            j++;
            ans++;
        } else{
           if(a[i] < b[j]) {
               i++;
           }else{
               j++;
           }
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}