#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int basket, count = 0;
	cin >> basket >> count;

    int* basket_arr = (int*)malloc(sizeof(int) * basket);
    for (int i = 0; i < basket; i++) { // 바구니 자신의 번호 공으로 초기화
        basket_arr[i] = i + 1;
    }

    int pre_basket, post_basket;
    for (int i = 0; i < count; i++) { // 어느 공을 바꿀건지 입력받기
		cin >> pre_basket >> post_basket;
        int temp = basket_arr[pre_basket - 1]; // 공 바꾸기
        basket_arr[pre_basket - 1] = basket_arr[post_basket - 1];
        basket_arr[post_basket - 1] = temp;
    }

    for (int i = 0; i < basket; i++) { // 바구니에 담긴 공 출력
		cout << basket_arr[i] << " ";
    }

    free(basket_arr);
    return 0;
}