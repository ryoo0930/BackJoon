//백준 16495 열 순서
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include "내가만든헤더~.h>

기본설정;
using 문자열 = string;
using 긴정수형 = long long;

int main() {
  문자열 열_문자열;
  입력 >> 열_문자열;

  긴정수형 열_순서 = 0;

  긴정수형 문자길이 = 열_문자열.길이();
  반복(정수형 인덱스 = 0; 인덱스 < 문자길이; 인덱스++) {
    긴정수형 문자숫자변환 = 열_문자열[인덱스] - 'A' + 1;
    열_순서 += 문자숫자변환 * 제곱(26, 문자 길이 - 인덱스 - 1);
  }

  출력 << 열_순서;
  return 0;
}
  
