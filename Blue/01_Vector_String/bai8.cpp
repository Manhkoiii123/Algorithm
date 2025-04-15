#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    string s,t;
    cin>>s>>t;
    int a[26],b[26];
    ms(a,0);
    ms(b,0);
    for(int i=0;i<s.size();i++)
        a[s[i]-'a']++;
    for(int i=0;i<t.size();i++)
        b[t[i]-'a']++;
    for(int i=0;i<26;i++){
        if(a[i]<b[i]){
            cout<<"need tree";
            return 0;
        }
    }
        
    if(s.size()==t.size()){
        cout<<"array";
        return 0;
    }
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==t[j]){
            j++;
        }
    }
    if(j==t.size()){
        cout<<"automaton";
    }
    else{
        cout<<"both";
    }  
    return 0;
}
