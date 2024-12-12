#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    FILE *file;
    char fileName[50];
    char line[1024];

    do
    {
        printf("Podaj nazwe pliku: ");
        fgets(fileName, sizeof(fileName), stdin);
        fileName[strcspn(fileName, "\n")] = '\0';

        file = fopen(fileName, "r");
    } while (file == NULL);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }
    

    _getch();
}