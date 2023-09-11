#include <string>
#include <vector>

using namespace std;

void bf(int m, int idx, vector<int>& rates, vector<vector<int>>& dc_prices, vector<vector<int>>& users, vector<int>& answer) {
    if(idx == m) {
        int t_user = 0, t_price = 0;

        for(vector<int> user : users) {
            int total = 0;
            for(int j=0; j<m; j++) {
                if(user[0] <= (rates[j] * 10)) { total += dc_prices[rates[j]][j]; }
            }

            if(user[1] <= total) { t_user++; }
            else { t_price += total; }
        }

        if(answer[0] < t_user) {
            answer[0] = t_user;
            answer[1] = t_price;
        }
        else if(answer[0] == t_user && answer[1] < t_price) {
            answer[1] = t_price;
        }

        return;
    }
    
    for(int i=1; i<=4; i++) {
        rates[idx] = i;
        bf(m, idx + 1, rates, dc_prices, users, answer);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2);
    vector<vector<int>> dc_prices(5);

    for(int i=1; i<=4; i++) {
        float dc = 0.1 * (10 - i);

        for(int p : emoticons) {
            dc_prices[i].push_back((int)(p * dc));
        }
    }
    
    int m = emoticons.size();
    vector<int> rates(m);

    bf(m, 0, rates, dc_prices, users, answer);

    return answer;
}

int main() {
    return 0;
}