// [1233] 사칙연산 유효성 검사
#include <iostream>
using namespace std;

int N, ans;

void input()
{
    char value;
    int idx, leftChild, rightChild;
    for(int i = 1; i <= N; i++) {
        cin >> idx >> value;
        if(i <= N/2) {
            cin >> leftChild >> rightChild; // 핵심!
            if('0' <= value && value <= '9') {
                ans = 0;
            }
        } 
        else {
            if(!('0' <= value && value <= '9')) {
                ans = 0;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int t = 1; t <= 10; t++) {
        cin >> N;
        ans = 1;
        input();
        cout << '#' << t << " " << ans << '\n';
    }

    return 0;
}