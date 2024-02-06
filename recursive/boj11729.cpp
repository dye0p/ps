//
// PS on 2024/02/05, 1:34 PM.
//
#include <bits/stdc++.h>

using namespace std;

void func(int a, int b, int n){ //시작, 마지막, 원판개수
    if(n == 1) { //base condition(탈출조건)
        cout << a << ' ' << b << "\n"; //시작에서 마지막으로
        return;
    }
    //재귀 시작
    func(a, 6-a-b, n-1); //n-1개의 원판을 시작에서 중간으로 이동
    cout << a << ' ' << b << '\n'; //이동한 경로를 출력
    func(6-a-b, b, n-1); //n-1개의 원판을 중간에서 마지막으로 이동

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cout << (1 << k) - 1 << '\n';

    func(1, 3, k);
}