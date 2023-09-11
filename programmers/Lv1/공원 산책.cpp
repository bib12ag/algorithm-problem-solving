#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int r = park.size();
    int c = park[0].size();
    
    int cur_r, cur_c;
    bool is_find = false;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(park[i][j] == 'S') {
                cur_r = i;
                cur_c = j;

                is_find = true;
                break;
            }
        }
        if(is_find) { break; }
    }

    for(string cmd : routes) {
        char d = cmd[0];
        int n = cmd[2] - '0';
        bool obs = false;

        if(d == 'E' && cur_c + n < c) {
            for(int i = cur_c + 1; i <= cur_c + n; i++) {
                if(park[cur_r][i] == 'X') {
                    obs = true;
                    break;
                }
            }
            if(!obs) { cur_c = cur_c + n; }
        }
        else if(d == 'W' && cur_c - n >= 0) {
            for(int i = cur_c - 1; i >= cur_c - n; i--) {
                if(park[cur_r][i] == 'X') {
                    obs = true;
                    break;
                }
            }
            if(!obs) { cur_c = cur_c - n; }
        }
        else if(d == 'S' && cur_r + n < r) {
            for(int i = cur_r + 1; i <= cur_r + n; i++) {
                if(park[i][cur_c] == 'X') {
                    obs = true;
                    break;
                }
            }
            if(!obs) { cur_r = cur_r + n; }
        }
        else if(d == 'N' && cur_r - n >= 0) {
            for(int i = cur_r - 1; i >= cur_r - n; i--) {
                if(park[i][cur_c] == 'X') {
                    obs = true;
                    break;
                }
            }
            if(!obs) { cur_r = cur_r - n; }
        }
    }

    answer.push_back(cur_r);
    answer.push_back(cur_c);

    return answer;
}

int main() {
    return 0;
}