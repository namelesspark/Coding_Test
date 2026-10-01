#include <stdio.h>

#define LEN_INPUT 100

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);

    for (int i = 0; s1[i] != '\0'; i++) {
        // 'A'(65) ~ 'Z'(90) 사이일 경우 (대문자)
        if (s1[i] >= 'A' && s1[i] <= 'Z') {
            s1[i] += 32; // 32를 더해 소문자로 변환
        } 
        // 'a'(97) ~ 'z'(122) 사이일 경우 (소문자)
        else if (s1[i] >= 'a' && s1[i] <= 'z') {
            s1[i] -= 32; // 32를 빼서 대문자로 변환
        }
    }

    printf("%s", s1);

    return 0;
}