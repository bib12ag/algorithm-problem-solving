#include <string>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

pair<int, int> parent[51][51];
string content[51][51];
int R = 50, C = 50;

void init() {
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            parent[i][j] = make_pair(i, j);
            content[i][j] = "EMPTY";
        }
    }
}

void update_by_idx(int r, int c, string val) {
    pair<int, int> p = parent[r][c];

    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(parent[i][j] == p) {
                content[i][j] = val;
            }
        }
    }
}

void update_by_str(string val1, string val2) {
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(content[i][j] == val1) {
                content[i][j] = val2;
            }
        }
    }
}

void merge(int r1, int c1, int r2, int c2) {
    pair<int, int> p1 = parent[r1][c1];
    pair<int, int> p2 = parent[r2][c2];
    string val = content[p1.first][p1.second];

    if(val != "EMPTY") {
        for(int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++) {
                if(parent[i][j] == p2) {
                    parent[i][j] = p1;
                    content[i][j] = val;
                }
            }
        }
    }
    else {
        val = content[p2.first][p2.second];

        for(int i=1; i<=R; i++) {
            for(int j=1; j<=C; j++) {
                if(parent[i][j] == p1) {
                    parent[i][j] = p2;
                    content[i][j] = val;
                }
            }
        }
    }
}

void unmerge(int r, int c) {
    pair<int, int> p = parent[r][c];
    string val = content[p.first][p.second];

    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(parent[i][j] == p) {
                parent[i][j] = make_pair(i, j);
                content[i][j] = "EMPTY";
            }
        }
    }

    content[r][c] = val;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    init();

    for(string str : commands) {
        istringstream ss(str);
        vector<string> cmd;
        string c;

        while(getline(ss, c, ' ')) { cmd.push_back(c); }

        if(cmd[0] == "UPDATE") {
            if(cmd.size() == 4) {
                update_by_idx(stoi(cmd[1]), stoi(cmd[2]), cmd[3]);
            }
            else { update_by_str(cmd[1], cmd[2]); }
        }
        else if(cmd[0] == "MERGE") {
            merge(stoi(cmd[1]), stoi(cmd[2]), stoi(cmd[3]), stoi(cmd[4]));
        }
        else if(cmd[0] == "UNMERGE") {
            unmerge(stoi(cmd[1]), stoi(cmd[2]));
        }
        else if(cmd[0] == "PRINT") {
           answer.push_back(content[stoi(cmd[1])][stoi(cmd[2])]);
        }
    }
    
    return answer;
}

int main() {
    return 0;
}