#include <iostream>
#include <algorithm>
using namespace std;

int N,K,A[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>K;
    for(int i=1; i<=N; i++) { cin>>A[i]; }

    int t=0;
    for(int i=N; i>=2; i--) {
        for(int j=1; j<i; j++) {
            if(A[j]>A[j+1]) { swap(A[j],A[j+1]); t++;}
            if(t==K) { cout<<A[j]<<" "<<A[j+1]; return 0; }
        }
    }

    if(t<K) { cout<<-1; }
    return 0;
}