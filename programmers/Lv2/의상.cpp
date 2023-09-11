#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> category;
    vector<int> num_of_clothes;
    int ci = 0;
    
    for(int i = 0; i < clothes.size(); i++) {
        string ctg = clothes[i][1];
        
        if(category.find(ctg) == category.end()) {
            category.insert({ctg, ci});
            num_of_clothes.push_back(1);
            ci++;
        }
        else {
            num_of_clothes[category[ctg]]++;
        }
    }
    
    for(int n : num_of_clothes) {
        answer *= n + 1;
    }
    
    return answer - 1;
}

int main() {
    return 0;
}