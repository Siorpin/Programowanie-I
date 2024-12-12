#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int main() {
    char name[50], id[50], b_name[50], job[50];

    FILE *file;
    file = fopen("dane.txt", "r");
    if (file == NULL)
    {
        printf("plik nie odnaleziony");
        return 1;
    }

    printf("Podaj nazwisko pracownika: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    while (fscanf(file, "%s %s %s", &id, &b_name, &job) == 3)
    {
        if (strcmp(name, b_name) == 0)
        {
            printf("id: %s, nazwisko: %s, praca: %s\n", id, b_name, job);
        }
    }

    fclose(file);


    _getch();
}