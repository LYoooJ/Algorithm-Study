#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool dfs(vector<int>& visited, vector<list<int>>& v, int depth, int src);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    bool flag = false;
    cin >> N >> M;
    vector<list<int>> v(N);
    vector<int> visited(N, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        visited[i] = 1;
        if (dfs(visited, v, 0, i)) {
            cout << 1 << "\n";
            flag = true;
            break;
        }
        else {
            visited[i] = 0;
        }
    }

    if (!flag)
        cout << 0 << "\n";

    return 0;
}

bool dfs(vector<int>& visited, vector<list<int>>& v, int depth, int src) {
    bool flag = false;
    if (depth >= 4) {
        return true;
    }
    else {
        for (list<int>::iterator iter = v[src].begin(); iter != v[src].end(); iter++) {
            if (!visited[*iter]) {
                visited[*iter] = 1;
                flag = dfs(visited, v, depth + 1, *iter);
                if (flag)
                    break;
                else
                    visited[*iter] = 0;
            }
        }
    }

    return flag;
}
