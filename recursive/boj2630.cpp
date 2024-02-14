//
// PS on 2024/02/13, 3:40 PM.
//
#include <bits/stdc++.h>

using namespace std;

int n; //한변의 길이
int paper[130][130]; //색종이
int cnt[2]; //흰색, 파란색 색종이 개수

//모두 같은 색인지 체크
bool check(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (paper[x][y] != paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int z) {
    //모두 같은색이라면
    if (check(x, y, z)) {
        cnt[paper[x][y]] += 1;
        return;
    }
    /*같은 색이 아니라면 4등분 해야함
     *한 행열의 길이가 n/2인 종이 4개로 쪼개야함
     *
     * */
    int n = z / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            solve(x + i * n, y + j * n, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; //행렬의 크기는 n x n
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j]; //입력
        }
    }
    solve(0, 0, n);

    for (int i = 0; i < 2; i++) {
        cout << cnt[i] << "\n";
    }
}