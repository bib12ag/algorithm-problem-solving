#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> num_of_prior(10);
    queue<int> que;
    
    for(int i = 0; i < priorities.size(); i++) {
        num_of_prior[priorities[i]]++;
        que.push(i);
    }
    
    int e = 1;
    vector<int> execute_order(priorities.size());
    
    for(int p = 9; p >= 1; p--) {
        while(num_of_prior[p] > 0) {
            int idx = que.front();
            que.pop();
            
            if(priorities[idx] == p) {
                execute_order[idx] = e++;
                num_of_prior[p]--;
            }
            else {
                que.push(idx);
            }
        }
    }
    
    int answer = execute_order[location];
    
    return answer;
}

int main() {
    return 0;
}