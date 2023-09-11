#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int wh = (brown >> 1) + 2;
    int h = 3;
    int w = wh - 3;

    while(h <= w) {
        if((h - 2) * (w - 2) == yellow) { 
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
        h++;
        w--;
    }

    return answer;
}

int main() {
    return 0;
}
