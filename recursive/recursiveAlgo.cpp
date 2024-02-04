//
// PS on 2024/02/04, 9:50 PM.
//
#include <bits/stdc++.h>

using namespace std;

void func1(int n) {
    if (n == 0) return;
    cout << n << ' ';
    func1(n - 1);
}
//0을 입력하게 되면 자기자신을 호출하지않고 return 즉, 종료된다.
//이러한 특정 입력을 Base Condirion이라고 함
//모든 입력은 Base Condition으로 수렴해야함
//func1을 예시로 들면 n에 0을 입력하게 되면 함수는 종료된다 -> Base Condition
//즉 함수가 종료되는 조건은 n==0인 경우 -> 결국 n에 어떠한 입력이 들어오든 결론적으로 모든 n은 0에 수렴하게된다
//-> 모든 입력은 Base Condition에 수렴

int func2(int n) {
    if (n == 0) return 0;
    return n + func2(n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    func1(3);

}

