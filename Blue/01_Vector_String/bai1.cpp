#include<bits/stdc++.h>
using namespace std;
bool check(int n,vector<int>&v){
    if(n==1) {
        if(v[0] == 1){
            return true;
        }else{  
            return false;
        }
    }
    int tmp=0;
    for(int i=0;i<n;i++) {
        if(v[i] == 0){
            tmp++;
            
        }
    }
    return tmp == 1;
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
   if(check(n,v)) {
       cout<<"YES";
   }
   else cout<<"NO";
}
