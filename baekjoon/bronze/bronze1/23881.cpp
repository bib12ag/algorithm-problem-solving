#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N,K,A[10001],idx[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>K;
    pair<int,int> pos[N+1];

    for(int i=1; i<=N; i++) { 
        cin>>A[i]; 
        pos[i]=make_pair(A[i],i);
    }
    sort(pos+1,pos+N+1);

    for(int i=1; i<=N; i++) { idx[pos[i].second]=i; }

    int t=0;
    for(int last=N; last>=2; last--) {
        if(A[last]!=pos[last].first) {
            if(++t==K) { cout<<A[last]<<" "<<pos[last].first; return 0; }
            
            int j=pos[last].second;
            A[j]=A[last];
            idx[j]=idx[last];
            pos[idx[last]].second=j;
        }
    }

    cout<<-1;
    return 0;
}