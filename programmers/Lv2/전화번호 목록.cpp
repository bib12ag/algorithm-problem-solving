#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool short_solution(vector<string> phone_book) {
    bool answer = true;

    for(int i = 0; i < phone_book.size() - 1; i++) {
        if(phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) {
            answer = false;
            break;
        }
    }

    return answer;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; i++) {
        if(phone_book[i].size() >= phone_book[i + 1].size()) { continue; }
        
        bool same = true;
        for(int j = 0; j < phone_book[i].size(); j++) {
            if(phone_book[i][j] != phone_book[i + 1][j]) {
                same = false;
                break;
            }
        }
        
        if(same) {
            answer = false;
            break;
        }
    }
    
    return answer;
}

int main() {
    return 0;
}