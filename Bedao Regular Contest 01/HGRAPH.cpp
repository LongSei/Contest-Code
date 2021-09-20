#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int, int> 
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAX = 1005;
int n, m, board[MAX][MAX];
vector<int> row[MAX], col[MAX];
ii next_pos[4][MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int dist[MAX][MAX];
// 0: R, 1: L, 2: U, 3: D

bool isok(int nx, int ny) {
    return nx >= 1 && nx <= n && ny >= 1 && ny <= m;
}

signed main() {
    faster;
    cin >> n >> m;
    for (int i= 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 1) {
                row[i].emplace_back(j);
            }
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (board[i][j] == 1) {
                col[j].emplace_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < row[i].size(); j++) {
            if (j < row[i].size() - 1) {
                next_pos[0][i][row[i][j]] = ii(i, row[i][j + 1]);
            }
            if (j > 0) {
                next_pos[1][i][row[i][j]] = ii(i, row[i][j - 1]);
            }
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 0; i < col[j].size(); i++) {
            if (i < col[j].size() - 1) {
                next_pos[3][col[j][i]][j] = ii(col[j][i + 1], j);
            }
            if (i > 0) {
                next_pos[2][col[j][i]][j] = ii(col[j][i - 1], j);
            }
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            dist[i][j] = 10000000;
        }
    }
    queue<pair<int, ii> > q;
    dist[1][1] = 0;
    q.push(make_pair(0, ii(1, 1)));
    while (q.empty() == false) {
        pair<int, ii> nw = q.front(); q.pop();
        int x = nw.second.first;
        int y = nw.second.second;
        int timer = nw.first;
        if (timer != dist[x][y]) {
            continue;
        }
        if (board[x][y] == 1) {
            for (int p = 0; p < 4; p++) {
                int mx = next_pos[p][x][y].first;
                int my = next_pos[p][x][y].second;
                if (mx == 0 && my == 0) {
                    if (p == 0) {
                        my = m;
                        mx = x;
                    }
                    if (p == 1) {
                        my = 1;
                        mx = x;
                    }
                    if (p == 2) {
                        mx = 1;
                        my = y;
                    }
                    if (p == 3) {
                        mx = n;
                        my = y;
                    }
                }
                for (int i = min(x, mx); i <= max(x, mx); i++) {
                    for (int j = min(y, my); j <= max(y, my); j++) {
                        if (isok(i, j) == true && dist[i][j] > timer + 1) {
                            dist[i][j] = timer + 1;
                            q.push(make_pair(timer + 1, ii(i, j)));
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isok(nx, ny) && dist[nx][ny] > timer + 1) {
                dist[nx][ny] = timer + 1;
                q.push(make_pair(dist[nx][ny], ii(nx, ny)));
            }
        }
    }
    cout << dist[n][m];
}
