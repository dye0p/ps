#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    int T;
    int a;
    double res =0;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            cin >> a;

            sum += a;
        }
        res = sum / 10.0;
        cout << "#" << test_case << " " << floor(res + 0.5) << '\n';
    }
    return 0;
}