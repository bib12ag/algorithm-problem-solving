#include <string>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> st;
    
    for(int i = 0; i < prices.size(); i++) {
        while(!st.empty() && st.top().first > prices[i]) {
            answer[st.top().second] = i - st.top().second;
            st.pop();
        }
        
        st.push(make_pair(prices[i], i));
    }
    
    int ei = prices.size() - 1;
    while(!st.empty()) {
        answer[st.top().second] = ei - st.top().second;
        st.pop();
    }
    
    return answer;
}

int main() {
    return 0;
}