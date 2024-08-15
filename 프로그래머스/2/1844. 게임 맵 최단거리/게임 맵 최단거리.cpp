#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct position {
    int x;
    int y;
    int dist;
};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    pair<int, int> move[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<position> q;
    q.push({0, 0, 1});

    while (!q.empty()) {
        position cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = cur.x + move[i].first;
            int new_y = cur.y + move[i].second;
            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && visited[new_x][new_y] == 0 && maps[new_x][new_y] == 1) {
                if (new_x == n - 1 && new_y == m - 1)
                    return cur.dist + 1;
                visited[new_x][new_y] = 1;
                q.push({new_x, new_y, cur.dist + 1});   
            }
        }
    }
    
    return -1;
}