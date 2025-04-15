
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    cin.ignore();
    map<int,int>mapStr;
    for(int i=0;i<n;i++) {
        string x;
        cin>>x;
        if(mapStr.find(x.length()) != mapStr.end()) {
            mapStr[x.length()]++;
        }else{
            mapStr[x.length()] = 1;
        }
    }
    string ans;
    cin>>ans;
    int m = ans.length();
    int min_ans = 0;
    int max_ans = 0;
    int cnt=0;
    int dem_bang_m ;
    for( auto pair : mapStr) {
        if(pair.first < m){
            cnt+=pair.second;
            max_ans+=pair.second;
            min_ans+=pair.second;
        }
        else  if(pair.first == m) {
            dem_bang_m=pair.second;
            max_ans+=dem_bang_m;
        }
        else{
            break;
        }
    }
    
    if(k == 1){
        min_ans += (cnt) * 5 + 1;
        max_ans += (cnt) * 5 + (dem_bang_m - 1) * 5; //cái đầu tiên chỉ bốc 1
    }else{
        int delay = cnt/k;
        min_ans+=delay*5;
        min_ans+=1;
        int div = k - cnt%k;
        max_ans+=delay*5;
        if(dem_bang_m > div) {
            max_ans+= 5 + (dem_bang_m - div) / k * 5;
        }
    }
    cout<<min_ans<<" "<<max_ans;
}


// cba => 1
// abc => 1 + 5
// bb1 => 1 + 5
// abC => 1 + 5
// ABC => 1 + 5
// ccc => 1 + 5
// abc
