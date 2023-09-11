#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(vector<int> cmd : commands) {
        vector<int> tmp;
        for(int i = cmd[0] - 1; i <= cmd[1] - 1; i++) {
            tmp.push_back(array[i]);
        }

        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[cmd[2] - 1]);
    }

    return answer;
}

int main() {
    return 0;
}