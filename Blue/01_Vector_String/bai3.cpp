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
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    v.push_back(90);
    
    if(v[0] > 15) {
        cout<<15;
        return 0;
    }
    for(int i=1;i<v.size();i++) {
        if(v[i] - v[i-1] > 15) {
            cout<<v[i-1] + 15;
            return 0;
        }
    }
    cout<<90;
}