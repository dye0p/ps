//
// Created by DongYeop on 2024/01/28.
//
#include <bits/stdc++.h>

using namespace std;

int vis[100002]; //방문처리
int dist[100002]; //도착 시간
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k; //위치
    queue<int> q;
    q.push(n); //수빈위치 push

    while (!q.empty()) {
        vis[n] = 1; //방문처리 //수빈위치 방문처리
        auto x = q.front();
        q.pop();

        for (int loop: {x - 1, x + 1, 2 * x}) { //이동할수 있는 경우
            //범위를 벗어나면
            if (loop < 0 || loop > 100000) continue;
            //방문처리가 되있으면 건너뜀
            if (vis[loop] >= 1) continue;

            vis[loop] = 1; //방문처리
            dist[loop] = dist[x] + 1; //시간 더하기
            q.push(loop);
        }
    }
    cout << dist[k]; //동생 위치의 시간 출력
}