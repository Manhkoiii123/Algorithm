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
    int min_length = MOD;
    for(int i=0;i<n;i++) cin>>a[i];
    int dem=0;
    int l=0;
    int cnt[100001]={0};
    int min_ans=0,max_ans=0;
    vector<pii>v;
    for(int r=0;r<n;r++) {
        if(cnt[a[r]] == 0) {
            cnt[a[r]]++;
            dem++;
            while(dem == k) {
                v.push_back({l+1,r+1});
                cnt[a[l]]--;
                if(cnt[a[l]] == 0) dem--;
                l++;
            }
        
        }
        else{
            cnt[a[r]]++;
        }
    }
    if(v.size() == 0) cout<<-1<<" "<<-1;
    else{
        for(int i=0;i<v.size();i++){
            if((v[i].second - v[i].first) < min_length) {
                min_length = v[i].second - v[i].first;
                min_ans = v[i].first;
                max_ans = v[i].second;
            } 
        }
        cout<<min_ans<<" "<<max_ans;
    }
}

