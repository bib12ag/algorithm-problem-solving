#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int tn = truck_weights.size();
    int cur = 0, sum = 0;
    int answer = bridge_length;

    while(cur < tn) {
        if(bridge.size() == bridge_length) {
            sum -= bridge.front();
            bridge.pop();
        }
        
        if(sum + truck_weights[cur] <= weight){
            bridge.push(truck_weights[cur]);
            sum += truck_weights[cur];
            cur++;
        }
        else {
            bridge.push(0);
        }
        answer++;
    }

    return answer;
}

int main() {
    return 0;
}