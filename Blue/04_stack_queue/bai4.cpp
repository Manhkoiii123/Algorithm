#include<bits/stdc++.h>
using namespace std;
// That is Your Queue - Uva
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int tc = 1;
    while(1) {
        int p,c;
        cin>>p>>c;
        if(p == 0 && c == 0) break;
        cout<<"Case "<<tc++<<":"<<endl;
        queue<int>q;
        for(int i=1;i<=min(p,c);i++) {
            q.push(i);
        }
        for(int i=0;i<c;i++) {
            char x;
            cin>>x;
            if(x == 'N') {
                int tmp = q.front();
                cout<<tmp<<endl;
                q.pop();
                q.push(tmp);
            }else if(x == 'E'){
                int y;
                cin>>y;
                int n = q.size();
                q.push(y);
                for(int j=0;j<n;j++) {
                    int tmp = q.front();
                    q.pop();
                    if(tmp != y) {
                        q.push(tmp);
                    }
                }
            }
        } 
        while (!q.empty()) {
            q.pop();
        }
    }
}