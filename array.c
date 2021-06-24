#include <stdio.h>

int main(void)
{
  // 배열
  int subway_array[3]; //여러개의 변수를 함께, 동시에 생성
  subway_array[0] = 30;
  subway_array[1] = 40;
  subway_array[2] = 50;

  for (int i=0; i<3; i++)
  {
    printf("지하철 %d호차에 %d 명이 타고 있습니다.\n", i+1, subway_array[i]);
  }

  //값 설정 방법, 값 초기화 하지 않으면 쓰레기 값 저장됨
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i=0; i<10; i++)
  {
    printf("%d\n", array[i]);
  }
  //배열 크기는 항상 상수로 선언
  //  int size = 10;
  //int arr[size]; // 오류가 생김

  //문자 vs 문자열
  char c = 'A';
  printf("%c\n", c);

  //문자열 끝에는 "끝"을 의미하는 NULL문자 '\0'이 포함되어야 함
  char str[7] = 'coding';
  printf("%s\n", str);

  char str[] = 'coding'; //char c_array[7] = {'c', 'o', 'd', 'i', 'n', 'g', '₩0'};
  printf("%s\n", str);
  printf("%d\n", sizeof(str)); //7

  for (int i =0; i<sizeof(str); i++)
  {
    printf("%c\n", str[i]);
  }

  char kor[] = "나도코딩";
  printf("%s\n", kor);
  printf("%d\n", sizeof(kor)); //9
  //영어 1글자 : 1byte
  //한글 1글자 : 2byte
  //char 크기 : 1byte

  char c_array[10] = {'c', 'o', 'd', 'i', 'n', 'g'}; //정상으로 출력, 나머지는 빈//
  return 0;

  //아스키 코드에서 NULL은 0으로 출력됨

  //참고1 : 아스키코드는 ANSI(미국표준협회) 에서 제시한 표준 코드 체계
  //7bit 총 128개 코드(0-127)
  //a:97 A:65 0:48

  //참고2 : 0-127 사이의 아스키코드 정수값에 해당하는 문자 확인
  for (int i=0; i<128; i++)
  {
    printf("아스키코드 정수 %d : %c\n", i, i);
  }






}
