#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main() {
    int x;
    printf("ile chcesz wprowadzic liczb? ");
    scanf("%d", &x);

    double *nums = malloc(x* sizeof(double));
    if (nums == NULL)
    {
        printf("error");
        return 1;
    }
    

    for (int i = 0; i < x; i++)
    {
        printf("Podaj %d liczbe: ", i + 1);
        scanf("%lf", &nums[i]);
    }
    int maxIndex = 0;
    double maxNum = nums[0];

    for (int i = 0; i < x; i++)
    {
        if(maxNum < nums[i]) {
            maxIndex = i;
            maxNum = nums[i];
        }
    }
    
    printf("Index najwiekszej liczby (%lf): %d", maxNum, maxIndex);

    _getch();
}