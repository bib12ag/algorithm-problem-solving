#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> score;

    score.insert(make_pair('R', 0));
    score.insert(make_pair('T', 0));
    score.insert(make_pair('C', 0));
    score.insert(make_pair('F', 0));
    score.insert(make_pair('J', 0));
    score.insert(make_pair('M', 0));
    score.insert(make_pair('A', 0));
    score.insert(make_pair('N', 0));

    int sz = survey.size();
    for(int i = 0; i < sz; i++) {
        switch(choices[i]) {
            case 1:
                score[survey[i][0]] += 3; 
                break;
            case 2:
                score[survey[i][0]] += 2; 
                break;
            case 3:
                score[survey[i][0]] += 1; 
                break;
            case 5:
                score[survey[i][1]] += 1; 
                break; 
            case 6:
                score[survey[i][1]] += 2;
                break;
            case 7:
                score[survey[i][1]] += 3;
                break;
            default:
                break;
        }
    }

    if(score['R'] < score['T']) { answer.append("T"); }
    else { answer.append("R"); }

    if(score['C'] < score['F']) { answer.append("F"); }
    else { answer.append("C"); }

    if(score['J'] < score['M']) { answer.append("M"); }
    else { answer.append("J"); }

    if(score['A'] < score['N']) { answer.append("N"); }
    else { answer.append("A"); }

    return answer;
}

int main() {
    return 0;
}
