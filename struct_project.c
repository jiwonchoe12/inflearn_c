#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//5마리 고양이가 있고 아무 키나 눌러서 랜덤으로 고양이를 뽑되,
//5마리 모두 다 수집을 해서 열심히 키우면 됨, 중복 발생 가능
//고양이 :이름, 나이, 성격, 키우기 난이도(레벨)

typedef struct{
  char *name;
  int age;
  char *character;
  int level;
}CAT;

//현재까지 보유한 고양이
int collection[5] = {0, 0, 0, 0, 0};
//전체 고양이 리스트
CAT cats[5];

void initCats();
void printCat(int selected);
int checkCollection();

int main(void)
{
  srand(time(NULL));
  initCats();

  while (1)
  {
    printf("두근두근 어느 고양이의 집사가 될까요?\n 아무 키나 눌러서 확인하세요!!");
    getchar();

    int selected = rand()%5;
    printCat(selected); //뽑은 고양이 정보 출력
    collection[selected] = 1;

    int collectAll = checkCollection();
    if (collectAll == 1)
    {
      break;
    }
  }
  return 0;
}

void initCats()
{
  cats[0].name = "깜냥이";
  cats[0].age = 5;
  cats[0].character = "온순";
  cats[0].level = 1;

  cats[1].name = "귀요미";
  cats[1].age = 3;
  cats[1].character = "날카롭";
  cats[1].level = 2;

  cats[2].name = "수줍이";
  cats[2].age = 7;
  cats[2].character = "늘 잠만 잠";
  cats[2].level = 3;

  cats[3].name = "까꿍이";
  cats[3].age = 2;
  cats[3].character = "시끄러움";
  cats[3].level = 4;

  cats[4].name = "돼냥이";
  cats[4].age = 1;
  cats[4].character = "배고픔";
  cats[4].level = 5;
}

void printCat(int selected)
{
  printf("\n\n == 당신은 이 고양이의 집사가 되었어요!\n");
  printf("이름      : %s\n", cats[selected].name);
  printf("나이      : %d\n", cats[selected].age);
  printf("특징(성격) : %s\n", cats[selected].character);
  printf("레벨      : ");

  for (int i=0; i<cats[selected].level; i++)
  {
    printf("%s", "★");
  }
  printf("\n\n");
}

int checkCollection()
{
  //현재 보유한 고양이 목록도 출력, 다 모았는지 여부를 반환
  int all = 1;
  printf("\n ==보유한 고양이 목록이에요==\n");
  for (int i=0; i<5; i++)
  {
    if (collection[i] ==0)
    {
      printf("  빈 박스  ");
      all = 0;
    }
    else
    {
      printf("  %s  ", cats[i].name);
    }
  }
  printf("\n=========================\n");

  if (all == 1);
  {
    printf("축하합니다. 다 모으셨어요!");
  }
  return all;
}
