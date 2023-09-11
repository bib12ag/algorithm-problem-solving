#include <string>
#include <vector>

using namespace std;

long long sum_of_queue(vector<int>& queue) {
    long long result = 0;
    for(int num : queue) { result += num; }

    return result;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum1 = sum_of_queue(queue1);
    long long sum2 = sum_of_queue(queue2);
    if((sum1 + sum2) & 1) { return -1; }
    
    long long d1 = sum1 > sum2 ? sum1 - sum2 : 0;
    long long d2 = sum2 > sum1 ? sum2 - sum1 : 0;
    
    int sz = queue1.size();
    int s = 0;
    int e = sz - 1;

    while(s <= e && e < (sz << 1)) {
        if(d1 == d2) { break; }

        if(d1 > d2) {
            if(s < sz) {
                d1 -= queue1[s];
                d2 += queue1[s];
            }
            else {
                d1 -= queue2[s - sz];
                d2 += queue2[s - sz];
            }
            s++;
        }
        else {
            e++;
            d1 += queue2[e - sz];
            d2 -= queue2[e - sz];
        }

        answer++;
    }

    if(d1 != d2) { return -1; }

    return answer;
}

int main() {
    return 0;
}