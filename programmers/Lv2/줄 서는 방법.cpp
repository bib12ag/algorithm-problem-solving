#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer, number;

    for(int i=1; i<=n; i++) { number.push_back(i); }

    k = k - 1;
    
    for(int i=n-1; i>=1; i--) {
        long long val = 1;
        for(int j=1; j<=i; j++) { val *= j; }

        int d = (int)(k / val);

        answer.push_back(number[d]);
        number.erase(number.begin() + d);

        k = k % val;
        if(k == 0) {
            for(int num : number) { answer.push_back(num); }
            break;
        }
    }

    return answer;
}

int main() {
    return 0;
}