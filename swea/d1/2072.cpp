#include<iostream>

using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    int T;

    int a;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            cin >> a;

            if(a % 2 != 0) {
                sum += a;
            }
        }
        cout << "#" << test_case << " " << sum << '\n';
    }
    return 0;
}