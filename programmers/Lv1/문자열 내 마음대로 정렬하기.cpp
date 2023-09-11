#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class cmp {
    int idx;
public:
    cmp(int n): idx(n) {}
    bool operator()(string a, string b) {
        if(a[idx] == b[idx]) {
            return a < b;
        }
        return a[idx] < b[idx];
    }
};

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), cmp(n));
    return strings;
}

int main() {
    return 0;
}