#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define N 5

void generateLatInSquare(int arr[N][N]) {
    // Stworzenie losowości
    srand(time(0));
    int start = rand() % 5 + 1;

    // Wypełnianie pierwszego rzędu
    for (int i = 0; i < N; i++) {
        arr[0][i] = start++;
        if (start > N) start = 1;
    }

    // Wypełnianie reszty rzędów za pomocą algorytmu przesunięcia
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = arr[i - 1][j] % N +1;
        }
    }
}

int howManySeen(int arr[N]) {
    int seen = 0;
    int largest = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > largest) {
            seen++;
            largest = arr[i];
        }
    }

    return seen;
}

int main() {
    int arr[N][N];
    int row[N];
    int top[N], right[N], bottom[N], left[N];

    // generowanie całej tablicy
    generateLatInSquare(arr);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            row[j] = arr[i][j];
        }
        left[i] = howManySeen(row);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            row[j] = arr[j][i];
        }
        top[i] = howManySeen(row);
    }

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            row[N - 1 - j] = arr[i][j];
        }
        right[i] = howManySeen(row);
    }

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            row[N - 1 - j] = arr[j][i];
        }
        bottom[i] = howManySeen(row);
    }



    // ------------------- Wypisanie wszystkiego ----------------------------------
    for (int i = 0; i < N + 2; i++) {
        if (i == 0 || i == 6) {
            printf("X ");
        }
        else {
            printf("%d ", top[i-1]);
        }
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 2; j++) {
            if (j == 0) {
                printf("%d ", left[i]);
            }
            else if (j == 6) {
                printf("%d ", right[i]);
            }
            else {
                printf("%d ", arr[i][j-1]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < N + 2; i++) {
        if (i == 0 || i == 6) {
            printf("X ");
        }
        else {
            printf("%d ", bottom[i-1]);
        }
    }

    _getch();
}
