#include <iostream>
using namespace std;

int N,K,A[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>K;
    for(int i=1; i<=N; i++) { cin>>A[i]; }

    int t=0,target,idx;
    for(int i=2; i<=N; i++) {
        target=A[i];
        idx=i-1;

        while(idx>0&&A[idx]>target) {
            A[idx+1]=A[idx];
            if(++t==K) { cout<<A[idx]; return 0; }
            idx--;
        }
        if(idx!=i-1) {
            A[idx+1]=target;
            if(++t==K) { cout<<target; return 0; }
        }
    }

    cout<<-1;
    return 0;
}