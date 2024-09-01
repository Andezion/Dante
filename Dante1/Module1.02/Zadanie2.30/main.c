#include <stdio.h>

int main()
{
    int ocena;
    printf("Enter your mark:");
    scanf("%i",&ocena);

    switch (ocena)
    {
        case 1:
            printf("Brak promocji do nastepnej klasy");
            break;
        case 2:
            printf("Promocja do nastepnej klasy");
            break;
        case 3:
            printf("Promocja do nastepnej klasy");
            break;
        case 4:
            printf("Promocja do nastepnej klasy");
            break;
        case 5:
            printf("Promocja do nastepnej klasy");
            break;
        case 6:
            printf("Promocja z ocena celujaca.");
            break;

        default:
            printf("Wprowadzona ocena jest niepoprawna");

    }
    return 0;

}
