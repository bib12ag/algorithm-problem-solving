#include <string>
#include <vector>

using namespace std;

long long solution(int price, int money, int count)
{
    long long total = (long long)price * ((count * (count + 1)) >> 1);
    long long answer = total - money; 

    if(answer < 0) { answer = 0; }

    return answer;
}

int main() {
    return 0;
}