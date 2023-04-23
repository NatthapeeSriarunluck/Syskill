#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double compute_det(int **a, int n);

// generate a submatrix for calculation excluding both row and column that is inputted
int **submatrix(int **a, int n, int excluded);
int main(void)
{
  int size;
  scanf("%d", &size);
  int **matrix = (int **)malloc(sizeof(int *) * size);
  for (int i = 0; i < size; i++)
  {
    matrix[i] = (int *)malloc(sizeof(int) * size);
  }

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("%.5f\n", compute_det(matrix, size));

  for (int i = 0; i < size; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}

double compute_det(int **a, int n)
{
  double result = 0.0;
  int sign = 1;
  if (n == 1)
  {
    return a[0][0];
  }
  else if (n == 2)
  {
    return a[0][0] * a[1][1] - a[1][0] * a[0][1];
  }
  else
  {
    for (int i = 0; i < n; i++)
    {

      int **b = (int **)submatrix(a, n, i);
      result += sign * a[0][i] * compute_det(b, n - 1);
      sign *= -1;
      for (int j = 0; j < n - 1; j++)
      {
        free(b[j]);
      }
      free(b);
    }
  }
  return result;
}

// generate a submatrix for calculation excluding both row and column that is inputted
int **submatrix(int **a, int n, int excluded)
{
  int row = 0;
  int **submatrix = malloc((n - 1) * sizeof(int *));
  for (int i = 1; i < n; i++) // starts at 1 since we always skip the first row
  {
    submatrix[row] = malloc((n - 1) * sizeof(int));
    int column = 0;
    for (int j = 0; j < n; j++)
    {
      if (j != excluded)
      {
        submatrix[row][column] = a[i][j];
        column++;
      }
    }
    row++;
  }
  return submatrix;
}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
