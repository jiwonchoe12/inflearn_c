#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));
  printf("\n\n == 아빠는 대머리 게임 == \n\n");
  int answer; //사용자 입력값
  int treatment = rand()%4; //정답(발모제 선택) 0-3

  //서로 보여주는 병 갯수를 다르게 하여 정답률 향상
  int cntShowBottle = 0; //이번 게임에서 보여줄 병 갯수
  int prevShowBottle = 0; // 앞 게임에서 보여준 병 갯수

  //3번 기회를 주고 답 입력
  for (int i=1; i<4; i++)
  {
    int bottle[4] = {0, 0, 0, 0};
    int isincluded = 0;
    printf(" > %d번째 시도 : ", i);

    do
    {
      cntShowBottle = rand()%2 + 2; //보여줄 병 갯수 (2개 혹은 3개)
    }while (cntShowBottle == prevShowBottle); //앞전이 2개면 지금은 3개, 앞전이 3개면 지금은 2개
    prevShowBottle = cntShowBottle;

    //보여줄 병 종류를 선택
    for (int j=0; j<cntShowBottle; j++)
    {
      int randBottle = rand()%4;
      if (bottle[randBottle]==0)
      {
        bottle[randBottle]=1;
        if (randBottle == treatment)
          isincluded = 1;
      }
      else
        j--;
    }

    for (int k=0; k<4; k++)
    {
      if (bottle[k] == 1)
        printf("%d ", k+1);
    }
    printf("물약을 머리에 바릅니다\n\n");

    if (isincluded == 1)
      printf(">> 성공! 머리가 났어요\n");
    else
      printf(">> 실패! 머리가 나지 않았어요...\n");

    printf("\n.... 계속하려면 아무키나 누르세요...");
    getchar();
  }

  printf("\n\n발모제는 몇 번 일까요??");
  scanf("%d", &answer);

  if (answer == treatment+1)
    printf(">> 정답입니다!!\n");
  else
    printf(">> 틀렸어요. 정답은 %d입니다\n", treatment+1);

  return 0;
}
