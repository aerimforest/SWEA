// 비트
#include <iostream>
using namespace std;

bool isAllOn(int n, int m)
{
    while(n--) {
        if(m & 1) {
            m /= 2;
            continue;
        }
        else return false;
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, m;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> m;
        if(isAllOn(n, m) == true) {
            cout << "#" << i << " ON" << '\n';
        }
        else {
            cout << "#" << i << " OFF" << '\n';
        }
    }
    return 0;
}