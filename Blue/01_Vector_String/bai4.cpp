// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string s,t;
//     cin>>s>>t;
//     int n = s.length();
//     for(int i=0;i<n;i++) {
//         if(s[i] != t[i]) {
//             if(s[i] - t[i] == -1) {
//                 if(i == n-1) {
//                     cout<<"No such string";
//                     return 0;
//                 }else{
//                     if(s[i+1] == 'z') {
//                         s[i]++;
//                         for(int j=i+1;j<n;j++){
//                             s[j] = 'a';
//                         }
//                         break;
//                     }else{
//                         s[i+1]++;
//                         break;
//                     }
//                 }
//             } 
//             else{
//                 s[i]++;
//                 break;
//             }

//         }
//     }
//     cout<<s;
// }



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
    int i = s.length() -1;
    while(s[i] == 'z') {
        s[i] = 'a';
        i--;
    }
    s[i] = s[i] + 1;
    if(s == t) {
        cout<<"No such string";
    }else{
        cout<<s;
    }
}