#include<iostream>

using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    int T;
    int a, b;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {

        cin >> a >> b;

        if (a < b) cout << "#" << test_case << " " << "<" << '\n';
        else if (a == b) cout << "#" << test_case << " " << "=" << '\n';
        else cout << "#" << test_case << " " << ">" << '\n';

    }
    return 0;
}