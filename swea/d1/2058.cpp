#include<iostream>

using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    int res = 0;

    while (N > 0) {
        res += N % 10;
        N = N / 10;
    }
    cout << res;

    return 0;
}