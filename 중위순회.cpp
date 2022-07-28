#include <iostream>
#define MAX 100
using namespace std;

char text[MAX];
int N, length;
struct Node {
    char alphabet;
    int child[2];
} nodes[MAX];

void input()
{
    char alphabet;
    int idx, child[2] = {0, };

    cin >> idx >> alphabet;
    if(cin.get() != '\n') {
        cin >> child[0]; // 왼쪽 자식
        if(cin.get() != '\n') cin >> child[1]; // 오른쪽 자식
    }
    idx--;
    child[0]--; child[1]--;
    
    nodes[idx].alphabet = alphabet;
    nodes[idx].child[0] = child[0];
    nodes[idx].child[1] = child[1];
}

void inOrder(int idx) {
    if(nodes[idx].child[0] != -1) {
        inOrder(nodes[idx].child[0]);
    }
    text[length++] = nodes[idx].alphabet;
    if(nodes[idx].child[1] != -1) {
        inOrder(nodes[idx].child[1]);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int t = 1; t <= 10; t++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            input();
        }
        length = 0;
        inOrder(0);

        cout << '#' << t << ' ';
        for(int i = 0; i < length; i++) {
            cout << text[i];
        }
        cout << '\n';
    }
    return 0;
}