// Program do liczenia układu równań używając metody wyznaczników macierzy

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

double* calculate(double** matrix, double* results);

int main() {
    // alokacja pamieci dla tablicy
    double** uklad = malloc(2*sizeof(double*));

    if (uklad == NULL) 
    {
        printf("error\n");
        return 0;
    }

    // teraz dla wynikow
    double* wyniki = malloc( 2 * sizeof(double));
    if(wyniki == NULL) {
        printf("error\n");
        return 0;
    }


    // alokacja pamieci dla kazdego wiersza
    for (int i = 0; i < 2; i++)
    {
       uklad[i] = malloc(sizeof(double*));
       if (uklad[i] == NULL) {
            printf("error\n");
            return 0;
        }
    }

    // inicjalizacja matrycy
    uklad[0][0] = 2; uklad[0][1] = -2;
    uklad[1][0] = -1; uklad[1][1] = 3;
    // inicjalizacja wyników
    wyniki[0] = 4;
    wyniki[1] = 1;

    double* result = calculate(uklad, wyniki);
    printf("%lf\n", result[0]);
    printf("%lf", result[1]);

    _getch();
}

double* calculate(double** matrix, double* results) {
    double W, Wx, Wy, x, y;

    W = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    Wx = matrix[1][1] * results[0] - matrix[0][1] * results[1];
    Wy = matrix[0][0] * results[1] - matrix[1][0] * results[0];

    x = Wx / W;
    y = Wy / W;

    double* wynik = malloc(2 * sizeof(double));
    if (wynik == NULL)
    {
        printf("errror");
    }
    
    wynik[0] = x;
    wynik[1] = y;

    if(W == 0) {
        return 0;
    }

    return wynik;
}