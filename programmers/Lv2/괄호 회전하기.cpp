#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int ln = s.size();

    for(int i = 0; i < ln; i++) {
        stack<char> st;
        bool right = true;

        for(int j = i; j < i + ln; j++) {
            int idx = j % ln;

            if(s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
                st.push(s[idx]);
            }
            else {
                if(st.empty()) { 
                    right = false; break; 
                }
                else if(s[idx] == ')') {
                    if(s[idx] - st.top() != 1) {
                        right = false; break;
                    }
                }
                else {
                    if(s[idx] - st.top() != 2) {
                        right = false; break;
                    }
                }
                st.pop();
            }
        }

        if(st.empty() && right) { answer++; }
    }

    return answer;
}

int main() {
    return 0;
}