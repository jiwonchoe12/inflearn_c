#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//10마리의 서로 다른 동물(각 카드 2장씩)
//사용자로부터 2개의 입력값을 받아서 같은 동물을 찾으면 카드 뒤집기
//모든 동물 쌍을 찾으면 게임 종류
// 마지막에 총 실패 횟수 알려주기

int arrayAnimal[4][5]; //총 20장
char *strAnimal[10];
int checkAnimal[4][5]; //뒤집혔는지 여부 확인

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestions();
int foundAnimals();

int main(void)
{
  srand(time(NULL));

  initAnimalArray();
  initAnimalName();
  shuffleAnimal();

  int failCount = 0;

  while(1)
  {
    int select1 = 0;
    int select2 = 0;
    printAnimals(); //동물 위치 출력
    printQuestions(); //문제 출력 (카드 지도)
    printf("뒤집을 카드 2개를 고르세요 : ");
    scanf("%d %d", &select1, &select2);

    if (select1 == select2)
      continue;

    //정수 좌표 (x, y)로 변환
    int firstSelect_x = conv_pos_x(select1);
    int firstSelect_y = conv_pos_y(select1);

    int secondSelect_x = conv_pos_x(select2);
    int secondSelect_y = conv_pos_y(select2);

    //같은 동물일 경우
    if (checkAnimal[firstSelect_x][firstSelect_y] == 0
        && checkAnimal[secondSelect_x][secondSelect_y] == 0
        &&arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])
    {
      printf("\n\nBingo! You found %s!\n\n",strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
      checkAnimal[firstSelect_x][firstSelect_y] = 1;
      checkAnimal[secondSelect_x][secondSelect_y] = 1;
    }
    else
    {
      printf("\nYour wrong\n!!");
      printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
      printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);

      failCount++;
    }
    //모든 동물을 찾았는지 여부 : 1은 참 0은 거짓
    if (foundAnimals() == 1)
    {
      printf("\n\n축하합니다. 모든 동물을 다 찾았어요!!\n");
      printf("지금까지 총 %d번 실수하였습니다!\n", failCount);
      break;
    }
  }


  return 0;
}

void initAnimalArray()
{
  for (int i=0; i<4; i++)
  {
    for (int j=0; j<5; j++)
    {
      arrayAnimal[i][j] = -1;
    }
  }
}

void initAnimalName()
{
  strAnimal[0] = "원숭이";
  strAnimal[1] = "하마";
  strAnimal[2] = "강아지";
  strAnimal[3] = "고양이";
  strAnimal[4] = "돼지";
  strAnimal[5] = "코끼리";
  strAnimal[6] = "기린";
  strAnimal[7] = "낙타";
  strAnimal[8] = "타조";
  strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
  for (int i=0; i<10; i++)
  {
    for (int j=0; j<2; j++)
    {
      int pos = getEmptyPosition();
      int x = conv_pos_x(pos);
      int y = conv_pos_y(pos);

      arrayAnimal[x][y] = i;
    }
  }
}

int getEmptyPosition() //좌표에서 빈 공간 찾기
{
  while(1)
  {
    int randPos = rand()%20;

    int x = conv_pos_x(randPos);
    int y = conv_pos_y(randPos);

    if (arrayAnimal[x][y] == -1)
    {
      return randPos;
    }
  }
  return 0;
}

int conv_pos_x(int x)
{
  return x/5;
}

int conv_pos_y(int y)
{
  return y%5;
}

void printAnimals()
{
  printf("\n==========이건 비밀인데.. 몰래 보여줍니다..==========\n");
  for (int i=0; i<4; i++)
  {
    for (int j=0; j<5; j++)
    {
      printf("     %s     ", strAnimal[arrayAnimal[i][j]]);
    }
    printf("\n");
  }
  printf("\n==============================================\n");
}

void printQuestions()
{
  //카드를 뒤집어서 정답을 맞췄으면 동물 이름 보여주기
  //아직 뒤집지 못했으면(정답을 못맞혔으면) 뒷면은 위치를 나타내는 숫자 보여주기
  printf("\n\n문제\n");
  int seq = 0;

  for (int i=0; i<4; i++)
  {
    for (int j=0; j<5; j++)
    {
      if (checkAnimal[i][j] != 0)
      {
        printf("%8s", strAnimal[arrayAnimal[i][j]]);
      }
      else
      {
        printf("%8d", seq);
      }
      seq++;
    }
    printf("\n");
  }
}

int foundAnimals()
{
  for (int i=0; i<4; i++)
  {
    for (int j=0; j<5; j++)
    {
      if (checkAnimal[i][j] == 0)
        return 0;
    }
  }
  return 1;
}
