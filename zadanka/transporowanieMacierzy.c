// Program do obracania macierzy

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

double** rotate(double** matrix, int rows, int columns);

int main() {
    int rows, columns;
    rows = 5;
    columns = 5;

    double** matrix = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(columns * sizeof(double));
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = i + j;
        }
        
    }
    

    double** x = rotate(matrix, rows, columns); 

    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%lf    ", x[i][j]);
        }
        printf("\n");
    }
    

    _getch();
}

double** rotate(double** matrix, int rows, int columns) {
    double** newMatrix = malloc(columns * sizeof(double*));
    for (int i = 0; i < columns; i++)
    {
        newMatrix[i] = malloc(rows * sizeof(double));
    }
    

    for (int i = 0; i < rows; i++)
    { 
        for (int j = 0; j < columns; j++)
        {
            newMatrix[j][i] = matrix[i][j];
        }
    }

    return newMatrix;
}