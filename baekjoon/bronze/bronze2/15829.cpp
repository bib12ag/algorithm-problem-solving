#include <iostream>
using namespace std;

#define MOD 1234567891

int N;
char s[51];
long p[51],ans;

void calc_pow() {
    p[0]=1;
    for(int i=1; i<N; i++) {
        p[i]=(p[i-1]*31)%MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    calc_pow();

    for(int i=0; i<N; i++) { cin>>s[i]; }

    for(int i=0; i<N; i++) {
        ans=(ans+p[i]*(s[i]-'a'+1))%MOD;
    }
    cout<<ans;
    return 0;
}