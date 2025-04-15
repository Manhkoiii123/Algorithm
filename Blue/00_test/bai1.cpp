// #include<iostream>
// #include<math.h>
// #include<algorithm>
// using namespace std;
// int n, c[20][20], res = 9999999, cmin = 999;
// bool visited[20];// danh dau nhung thanh pho da di qua
// int X[20];//danh dau thanh pho vua di qua
// void nhap() {
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 1; j <= n; j++) {
// 			cin >> c[i][j];
// 			if (c[i][j] != 0) 
// 				cmin = min(cmin, c[i][j]);// Gia tien nho nhat de di tu thanh pho i den j
// 		}
// 	}
// }
// void Try(int i, int cost) {
// 	for (int j = 2; j <= n; j++) {
// 		if (!visited[j]) {
// 			visited[j] = true;
// 			X[i] = j;
// 			cost += c[X[i - 1]][j];
// 			if (i == n) {
// 				cost += c[1][X[i]];
// 				res = min(res, cost);
// 			}
// 			// da di qua i thanh pho
// 			// con (n - i) thanh pho => tong so tp can di qua : (n - i) + 1 vi con quay lai tp 1
// 			else if (cost + (n - i + 1) * cmin < res) { // TH tot nhat khi di (n-i+1) tp con lai
// 				// Kiem tra xem trong TH tot nhat < res khong vi thuc te cost sau khi di n tp >= cost gia su
// 				Try(i + 1, cost);
// 			}
// 			//backtrack
// 			cost -= c[X[i - 1]][j];
// 			visited[j] = false;
// 		}
// 	}
// }
// int main() {
// 	cin >> n;
// 	nhap();
// 	X[1] = 1;
// 	Try(2, 0);
// 	cout << res << endl;
// }

#include <iostream>
#include <algorithm>
using namespace std;

int n = 4; // số lượng thành phố
int c[20][20] = {
    {0, 12, 18, 25}, // chi phí từ thành phố 1 (X)
    {12, 0, 35, 22}, // chi phí từ thành phố 2 (Y)
    {18, 35, 0, 15}, // chi phí từ thành phố 3 (Z)
    {25, 22, 15, 0}  // chi phí từ thành phố 4 (W)
};

int res = 9999999, cmin = 999;
bool visited[20];
int X[20];

void nhap() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i-1][j-1] != 0) 
                cmin = min(cmin, c[i-1][j-1]); // Gia tien nho nhat de di tu thanh pho i den j
        }
    }
}

void Try(int i, int cost) {
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = true;
            X[i] = j;
            cost += c[X[i - 1] - 1][j - 1];
            if (i == n) {
                cost += c[0][X[i] - 1]; // Quay lại thành phố 1
                res = min(res, cost);
            } else if (cost + (n - i + 1) * cmin < res) { 
                Try(i + 1, cost);
            }
            cost -= c[X[i - 1] - 1][j - 1];
            visited[j] = false;
        }
    }
}

int main() {
    nhap();
    X[1] = 1;
    Try(2, 0);
    cout << res << endl;
}



// void bfs(int x){
//     queue<int>q;
//     q.push(x);
//     vis[x]=true;
//     while(!q.empty()){
//         int top=q.front();q.pop();
//         for(int v:ke[top]){
//             if(!vis[v]){
//                 q.push(v);
//                 vis[v]=true;
//             }
//         }
//     }
// }