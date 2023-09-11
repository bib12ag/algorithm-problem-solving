#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if(s < n) { answer.push_back(-1); }
    else {
        int d = 0, m = 0;
        for(int i = n; i > 0; i--) {
            d += (int)(s / i);
            m = (int)(s % i);
            answer.push_back(d);
            s = m;
        }    
    }

    return answer;
}

int main() {
    return 0;
}