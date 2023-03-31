#include<bits/stdc++.h>
using namespace std;

int n, m, ax, ay;
char grid[1005][1005];
bool vis[1005][1005];

int dx[] = {-1, 0, 1, 0};  // to move in all four directions
int dy[] = {0, 1, 0, -1};

string path = "";  // variable to store the path

bool isValid(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m) return false;  // if out of grid
    if(grid[x][y] == '#' || grid[x][y] == 'M') return false;  // if wall or monster
    return true;
}

bool dfs(int x, int y) {
    vis[x][y] = true;
    if(x == 1 || x == n || y == 1 || y == m) return true;  // if reached boundary cell
    for(int i=0; i<4; i++) {  // check in all four directions
        int nx = x + dx[i], ny = y + dy[i];
        if(isValid(nx, ny) && !vis[nx][ny]) {  // if the next cell is valid and not visited
            if(i == 0) path += "U";  // if moved up
            if(i == 1) path += "R";  // if moved right
            if(i == 2) path += "D";  // if moved down
            if(i == 3) path += "L";  // if moved left
            if(dfs(nx, ny)) return true;  // if reached boundary cell from this cell
            path.pop_back();  // if the current path is not valid, remove the last move from path
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') ax = i, ay = j;  // store the starting cell
        }
    }

    if(dfs(ax, ay)) {  // if a valid path exists
        cout << "YES\n";
        cout << path.size() << "\n" << path << "\n";
    }
    else cout << "NO\n";  // if a valid path doesn't exist

    return 0;
}
