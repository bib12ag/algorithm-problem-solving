#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> vertex(n+1);

    for(int i=0; i<wires.size(); i++) {
        int v1 = wires[i][0], v2 = wires[i][1];
        vertex[v1].push_back(v2);
        vertex[v2].push_back(v1);
    }

    for(int i=0; i<wires.size(); i++) {
        vector<bool> visit(n+1);
        queue<int> q;

        int v1 = wires[i][0], v2 = wires[i][1];
        int n1 = 0;

        q.push(v1);
        visit[v1] = visit[v2] = true;
        n1++;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int nxt : vertex[cur]) {
                if(!visit[nxt]) {
                    q.push(nxt);
                    visit[nxt] = true;
                    n1++;
                }
            }
        }

        int n2 = n - n1;
        answer = min(answer, abs(n1 - n2));
    }

    return answer;
}

int main() {
    return 0;
}