#include <string>
#include <vector>

using namespace std;

void dfs(int r, vector<int>& visited, vector<vector<int>>& computers);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n);
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;
        else 
        {
            visited[i] = 1;
            dfs(i, visited, computers);
            answer++;
        }
    }
    
    return answer;
}

void dfs(int r, vector<int>& visited, vector<vector<int>>& computers) {
    int c;

    for (c = 0; c < visited.size(); c++) {
        if (visited[c] == 0 && computers[r][c] == 1) {
            visited[c] = 1;
            dfs(c, visited, computers);
        }
    }
    
    return;
}