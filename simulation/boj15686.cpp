#include <bits/stdc++.h>

using namespace std;

#define MAX_INT 2147483643

int n, m;
int minCityDistance = MAX_INT;
int board[52][52];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<int> selected;

void calculateDistance() {
    int cityDistance = 0; //도시의 치킨거리

    for (int i = 0; i < house.size(); i++) {
        int minHouseDistance = MAX_INT; //최소 치킨거리
        for (int j = 0; j < chicken.size(); j++) {
            if (selected[j] == 1) {
                int houseDistance = abs(house[i].first - chicken[j].first)
                                    + abs(house[i].second - chicken[j].second);
                if (houseDistance < minHouseDistance) {
                    minHouseDistance = houseDistance;
                }
            }
        }
        cityDistance += minHouseDistance;
    }
    if (cityDistance < minCityDistance) {
        minCityDistance = cityDistance;
    }
}

void chickenLoad() {
    for (int i = 0; i < chicken.size() - m; i++) { //치킨집 갯수 - m
        selected.push_back(0); //선택하지 않을 치킨집
    }
    for (int i = 0; i < m; i++) {
        selected.push_back(1); //선택할 치킨집
    }
    do {
        calculateDistance();
    } while (next_permutation(selected.begin(), selected.end()));


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    //입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) chicken.push_back({i, j});
            if (board[i][j] == 1) house.push_back({i, j});
        }
    }

    //치킨거리 구하기
    chickenLoad();

    cout << minCityDistance;
}