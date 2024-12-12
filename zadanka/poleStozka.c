#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
// #include<math.h>

// #define _USE_MATH_DEFINES
#define M_PI 3.14

double pole(double r, double h, double l);

int main() {
    double r, h, l;

    do
    {
        printf("Podaj promien podstawy: ");
        scanf("%lf", &r);

        printf("%lf", r);

        printf("Podaj wysokosc: ");
        scanf("%lf", &r);

        printf("Podaj dlugosc boku: ");
        scanf("%lf", &l);  

    } while (r <= 0.0 || h <= 0.0 || l <= 0.0);
    
    printf("pole wynosi: %lf", pole(r, h, l));

    _getch();
}

double pole(double r, double h, double l) {
    double pole;

    pole = h * M_PI * l + M_PI * r * r;

    return pole;
}