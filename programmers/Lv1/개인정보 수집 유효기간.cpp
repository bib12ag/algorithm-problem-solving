#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int YY = stoi(today.substr(0, 4));
    int MM = stoi(today.substr(5, 2));
    int DD = stoi(today.substr(8));
    int Days = (YY-2000)*12*28 + (MM-1)*28 + DD; 

    int exp_date[30];
    for(int i=0; i<terms.size(); i++) {
        istringstream ss(terms[i]);
        char term;
        int month;
        ss >> term >> month;

        exp_date[term - 'A'] = month;
    }

    for(int i=0; i<privacies.size(); i++) {
        istringstream ss(privacies[i]);
        string date;
        char term;
        ss >> date >> term;

        int yy = stoi(date.substr(0, 4));
        int mm = stoi(date.substr(5, 2));
        int dd = stoi(date.substr(8));
        int days = (yy-2000)*12*28 + (mm+exp_date[term-'A']-1)*28 + dd;

        if(days <= Days) { answer.push_back(i + 1); }
    }

    return answer;
}

int main() {
    return 0;
}