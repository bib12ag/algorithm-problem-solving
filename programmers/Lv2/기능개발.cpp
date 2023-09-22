#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++) {
        int d = (int)ceil(float(100 - progresses[i]) / speeds[i]);
        q.push(d);
    }
    
    int skill = 0;
    int day = q.front();
    
    while(!q.empty()) {
        if(day >= q.front()) {
            skill++;
            q.pop();
        }
        else {
            answer.push_back(skill);
            skill = 1;
            day = q.front();
            q.pop();
        }
    }
    
    if(skill > 0) { answer.push_back(skill); }
    
    return answer;
}

int main() {
    return 0;
}