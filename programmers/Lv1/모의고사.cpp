#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int person1(vector<int>& answers) {
    vector<int> submit = {1, 2, 3, 4, 5};

    int correct = 0;
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == submit[i % 5]) { correct++; }
    }

    return correct;
}

int person2(vector<int>& answers) {
    vector<int> submit = {2, 1, 2, 3, 2, 4, 2, 5};

    int correct = 0;
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == submit[i % 8]) { correct++; }
    }

    return correct;
}

int person3(vector<int>& answers) {
    vector<int> submit = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int correct = 0;
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == submit[i % 10]) { correct++; }
    }

    return correct;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> v;

    v.push_back(make_pair(person1(answers), 1));
    v.push_back(make_pair(person2(answers), 2));
    v.push_back(make_pair(person3(answers), 3));

    sort(v.begin(), v.end(), cmp);

    answer.push_back(v[0].second);
    if(v[0].first == v[1].first) { answer.push_back(v[1].second); }
    if(v[0].first == v[2].first) { answer.push_back(v[2].second); }

    return answer;
}

int main() {
    return 0;
}