#include <string>
#include <vector>
#include <cmath>

using namespace std;

// d* -> l* -> (rl)* -> r* -> u*

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int rk = k - abs(x - r) - abs(y - c);
    if(rk < 0 || rk & 1) { return "impossible"; }

    int nd = max(0, r - x);
    int nl = max(0, y - c);
    int nr = max(0, c - y);
    int nu = max(0, x - r);

    int ndu = min(n - (x + nd), rk >> 1);
    rk -= ndu << 1;
    int nlr = min((y - nl) - 1, rk >> 1);
    rk -= nlr << 1;
    int nrl = rk >> 1;

    string answer = "";
    for(int i = 0; i < nd + ndu; i++) { answer += 'd'; }
    for(int i = 0; i < nl + nlr; i++) { answer += 'l'; }
    for(int i = 0; i < nrl; i++) { answer += "rl"; }
    for(int i = 0; i < nr + nlr; i++) { answer += 'r'; }
    for(int i = 0; i < nu + ndu; i++) { answer += 'u'; }

    return answer;
}

int main() {
    return 0;
}