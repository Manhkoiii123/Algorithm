#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    priority_queue<int>pq;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   
    for(int i=0;i<n;i++){

        pq.push(a[i]);
        if(i< 2) {
            cout<<-1<<endl;
        }
        else{
            int f= pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int t = pq.top();
            pq.pop();
            pq.push(f);
            pq.push(t);
            pq.push(s);
            cout<<1ll*f*s*t<<endl;
        }
    }
}