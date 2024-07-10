#include<iostream>
#include <algorithm> //sort()를 사용하기 위한 라이브러리 추가

using namespace std;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int arr[200];

    cin >> N;

    for (int i = 0; i < N; ++i) cin >> arr[i];

    sort(arr, arr + N);

    cout << arr[N / 2];

    return 0;
}