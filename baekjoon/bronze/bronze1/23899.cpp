#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N,A[10001],B[10001],idx[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    pair<int,int> pos[N+1];

    for(int i=1; i<=N; i++) { 
        cin>>A[i]; 
        pos[i]=make_pair(A[i],i);
    }
    for(int i=1; i<=N; i++) { cin>>B[i]; }

    sort(pos+1,pos+N+1);
    for(int i=1; i<=N; i++) { idx[pos[i].second]=i; }

    for(int last=N; last>=2; last--) {
        if(A[last]>B[last]) { cout<<0; return 0; }
        
        if(A[last]!=pos[last].first) {
            if(A[last]==B[last]) {
                for(int i=1; i<last; i++) {
                    if(A[i]!=B[i]) { cout<<0; return 0;}
                }
                cout<<1; return 0;
            }

            int j=pos[last].second;
            A[j]=A[last];
            idx[j]=idx[last];
            pos[idx[last]].second=j;
            A[last]=pos[last].first;
        }
        if(A[last]!=B[last]) { cout<<0; return 0; }
    }

    if(A[1]==B[1]) { cout<<1; }
    else { cout<<0; }
    return 0;
}