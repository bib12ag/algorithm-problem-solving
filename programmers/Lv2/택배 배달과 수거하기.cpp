#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    stack<pair<int, int>> dv, pk;

    for(int i=0; i<n; i++) {
        if(deliveries[i] > 0) {
            dv.push(make_pair(i+1, deliveries[i]));
        }
        if(pickups[i] > 0) {
            pk.push(make_pair(i+1, pickups[i]));
        }
    }

    while(!dv.empty() || !pk.empty()) {
        int mx_dv = 0, mx_pk = 0;
        if(!dv.empty()) { mx_dv = dv.top().first; }
        if(!pk.empty()) { mx_pk = pk.top().first; }

        if(mx_dv > mx_pk) { answer += mx_dv * 2; }
        else { answer += mx_pk * 2; }

        int cur_cap = cap;
        while(!dv.empty() && cur_cap > 0) {
            pair<int, int> cur = dv.top(); dv.pop();
            if(cur.second > cur_cap) {
                dv.push(make_pair(cur.first, cur.second - cur_cap));
                cur_cap = 0;
            }
            else {
                cur_cap -= cur.second;
            }
        }

        cur_cap = cap;
        while(!pk.empty() && cur_cap > 0) {
            pair<int, int> cur = pk.top(); pk.pop();
            if(cur.second > cur_cap) {
                pk.push(make_pair(cur.first, cur.second - cur_cap));
                cur_cap = 0;
            }
            else {
                cur_cap -= cur.second;
            }
        }
    }

    return answer;
}

int main() {
    return 0;
}