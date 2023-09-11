#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int sz = a.size();
    if(sz < 3) { return sz; }

    vector<int> min_lt(sz), min_rt(sz);
    min_lt[0] = a[0];
    min_rt[sz - 1] = a[sz - 1];

    for(int i = 1; i < sz; i++) {
        if(min_lt[i - 1] > a[i]) { min_lt[i] = a[i]; }
        else { min_lt[i] = min_lt[i - 1]; }
    }
    for(int i = sz - 2; i >= 0; i--) {
        if(min_rt[i + 1] > a[i]) { min_rt[i] = a[i]; }
        else { min_rt[i] = min_rt[i + 1]; }
    }

    int answer = 2;
    for(int i = 1; i < sz - 1; i++) {
        if(min_lt[i - 1] > a[i] || min_rt[i + 1] > a[i]) { answer++; }
    }

    return answer;
}

int main() {
    return 0;
}