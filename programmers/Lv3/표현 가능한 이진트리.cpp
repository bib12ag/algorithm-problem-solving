#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

string to_binary(long long number) {
    stack<char> st;
    while(number > 0) {
        if(number & 1) { st.push('1'); }
        else { st.push('0'); }

        number >>= 1;
    }

    string bi = "";
    for(int i = 1; i <= 6; i++) {
        int f = ((1 << i) - 1) - st.size();

        if(f >= 0) {
            for(int j = 0; j < f; j++) { bi += '0'; }
            while(!st.empty()) {
                bi += st.top();
                st.pop();
            }
            break;
        }
    }

    return bi;
}

bool is_tree(string bi) {
    queue<pair<int, int>> q;
    q.push(make_pair(1, bi.length()));

    while(!q.empty()) {
        int lt = q.front().first;
        int rt = q.front().second; q.pop();

        if(lt == rt) { continue; }

        int root = (lt + rt) >> 1;

        if(bi[root - 1] == '0') {
            for(int i=lt; i<=rt; i++) {
                if(bi[i - 1] == '1') { return false; }
            }
        }
        else {
            q.push(make_pair(lt, root - 1));
            q.push(make_pair(root + 1, rt));
        }
    }
    
    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(long long num : numbers) {
        if(is_tree(to_binary(num))) {
            answer.push_back(1);
        }
        else { answer.push_back(0); }
    }

    return answer;
}

int main() {
    return 0;
}