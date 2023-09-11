#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <utility>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
    priority_queue<pair<int, int>> maxq;
    vector<bool> out;
    int idx = 0;
    int remain = 0;

    for(string op : operations) {
        istringstream ss(op); 
        char cmd;
        int data;
        ss >> cmd >> data;

        if(cmd == 'I') {
            minq.push(make_pair(data, idx));
            maxq.push(make_pair(data, idx));
            out.push_back(false);
            idx++;
            remain++;
        }
        else if(data == 1) {
            if(remain == 0) { continue; }
            while(out[maxq.top().second]) {
                maxq.pop();
            }
            out[maxq.top().second] = true;
            maxq.pop();
            remain--;
        }
        else {
            if(remain == 0) { continue; }
            while(out[minq.top().second]) {
                minq.pop();
            }
            out[minq.top().second] = true;
            minq.pop();
            remain--;
        }
    }    

    if(remain == 0) { 
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        while(out[maxq.top().second]) {
            maxq.pop();
        }
        while(out[minq.top().second]) {
            minq.pop();
        }
        answer.push_back(maxq.top().first);
        answer.push_back(minq.top().first);
    }

    return answer;
}

int main() {
    return 0;
}