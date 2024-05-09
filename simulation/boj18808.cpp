//
// PS on 24. 5. 6, 오후 5:51.
//
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int r, c;
int paper[12][12]; //모눈종이
int note[42][42]; //노트북

bool isPossible(int x, int y) {
    //붙일 수 없는 자리
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (note[x + i][y + j] == 1 && paper[i][j])
                return false;
        }
    }
    //붙일 수 있다면
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            //스티커 붙이기
            if (paper[i][j] == 1) {
                note[x + i][y + j] = 1;
            }
        }
    }
    return true;
}

//회전함수
void remote() {
    int tmp[12][12];

    //원래 있던 스티커를 임시 tmp에 옮겨놓음
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = paper[i][j]; //회전된 스티커일수도 있음
        }
    }

    //회전
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            paper[i][j] = tmp[r - 1 -j][i];
        }
    }
    swap(r, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    while (k--) { //스티커의 갯수만큼 입력 받음
        //모눈종이 크기 입력
        cin >> r >> c;
        //모눈 종이 크기만큼 반복하며 스티커 입력
        for (int i = 0; i < r; i++) { //행
            for (int j = 0; j < c; j++) { //열
                cin >> paper[i][j]; //스티커 입력
                //i,j는 현재 스티커의 위치
            }
        }//스티커 입력 완료

        for (int rot = 0; rot < 4; rot++) { //회전 횟수 여부
            bool is_paste = false;
            for (int x = 0; x <= n - r; x++) {
                if (is_paste) {
                    break; //is_paste가 참이면 탈출
                }
                for (int y = 0; y <= m - c; y++) {
                    if (isPossible(x, y)) { //true라면 붙였다는 뜻
                        is_paste = true;
                        break;
                    }
                } //스티커가 붙여졌을때 탈출 범위
            }
            if (is_paste) {
                break;
            }
            // 스티커가 붙여지지 못하였을떄 도달
            remote(); //회전
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        for (int j = 0; j < m; j++) {
            if (note[i][j] == 1) {
                ++cnt;
            }
        }
    }
    cout << cnt << '\n';
}


