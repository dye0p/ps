//
// PS on 2024/02/05, 9:28 AM.
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll pow(ll a, ll b, ll m) {
    if (b == 1) { // base Condition (b==1일때)
        return a % m; //a * 1 % m 과 같다.
    }
    ll ans = pow(a, b / 2, m);
    ans = ans * ans % m; //분할정복으로 둘로 쪼갬
    if (b % 2 == 0) { //b가 짝수면
        return ans;
        //ans를 리턴함 -> ans가 리턴되면 pow를 호출하게 된다. -> 재귀 호출
    }
    //b가 홀수일땐 재귀호출을 통해서 제곱을 한 다음 한번더 a를 곱해주면 b는 홀수가 된다.
    return ans * a % m;

    /*
     * 시간복잡도 : O(log N) -> 입력n에 대해 로그함수에 비례하는 시간 복잡도를 가진다
     * 로그함수는 x의 크기가 커질수록 그래프가 선형적으로 증가한다.
     * 따라서 입력의 크기가 커질수록 로그함수에 비례하여 증가하기때문에 효율적이다
     * */
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << pow(a, b, c);
}
