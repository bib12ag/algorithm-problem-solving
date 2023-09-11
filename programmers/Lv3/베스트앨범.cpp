#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp1(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

bool cmp2(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> gr_idx;
    vector<vector<pair<int, int>>> gr_list; // {play, music_idx}
    vector<pair<int, int>> play_total; // {play_sum, genre_idx}

    for(int i=0; i<genres.size(); i++) {
        int idx;
        map<string, int>::iterator it = gr_idx.find(genres[i]);

        if(it == gr_idx.end()) {
            idx = gr_idx.size();
            gr_idx.insert({genres[i], idx});
            gr_list.push_back({});
            play_total.push_back(make_pair(0, idx));
        }
        else {
            idx = it->second;
        }

        gr_list[idx].push_back(make_pair(plays[i], i));
        play_total[idx].first += plays[i];
    }

    sort(play_total.begin(), play_total.end(), cmp1);

    for(pair<int, int> info : play_total){
        int idx = info.second;

        if(gr_list[idx].size() == 1) { answer.push_back(gr_list[idx][0].second); }
        else {
            sort(gr_list[idx].begin(), gr_list[idx].end(), cmp2);
            answer.push_back(gr_list[idx][0].second);
            answer.push_back(gr_list[idx][1].second);
        }
    }

    return answer;
}

int main() {
    return 0;
}