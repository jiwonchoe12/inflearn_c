#include <stdio.h>

int main(void)
{
  //다차원 배열 Multidimensional Array
  //다차원 배열 선언
  int arr[2][5] = {
    {1, 2, 3, 4, 5},
    {1, 2, 3, 4, 5}
  };

  for (int i=0; i<2; i++)
  {
    for (int j=0; j<5; j++)
    {
      printf("2차원 배열 (%d, %d)의 값 : %d\n", i, j, arr[i][j]);
    }
    printf("\n");
  }

  int arr2[3][3][3] = {
    {
      {1, 2, 3},
      {1, 2, 3},
      {1, 2, 3}
    },
    {
      {1, 2, 3},
      {1, 2, 3},
      {1, 2, 3}
    },
    {
      {1, 2, 3},
      {1, 2, 3},
      {1, 2, 3}
    }
  };
  return 0;//
}
