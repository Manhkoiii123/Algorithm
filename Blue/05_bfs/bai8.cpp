#include <bits/stdc++.h>
#define MAX 500 + 1
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int N, M;
int nsheeps, nwolves;
string backyard[MAX];

struct Cell {
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && c >= 0 && r < N && c < M;
}

void BFS(Cell s) {
    queue<Cell> q;
    q.push(s);

    int sheep = (backyard[s.r][s.c] == 'k');
    int wolf = (backyard[s.r][s.c] == 'v');

    bool canEscape = false;
    backyard[s.r][s.c] = '#';

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];

            if (!isValid(r, c)) {
                canEscape = true;
                continue;
            }

            if (backyard[r][c] != '#') {
                sheep += (backyard[r][c] == 'k');
                wolf += (backyard[r][c] == 'v');
                backyard[r][c] = '#';
                q.push((Cell) {r, c});
            }
        }
    }

    if (canEscape) {
        nsheeps += sheep;
        nwolves += wolf;
    }
    else {
        sheep > wolf ? nsheeps += sheep : nwolves += wolf;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> backyard[i]; //cái ày là 1 mảng string => nhaapk 1 mảng 1 string là 1 hàng của ma trận luôn
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         if (backyard[i][j] != '#') {
    //             BFS((Cell) {i, j});
    //         }
    //     }
    // }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout<<backyard[i][j];
        }
        cout<<endl;
    }
    cout << nsheeps << " " << nwolves;
    return 0;
}