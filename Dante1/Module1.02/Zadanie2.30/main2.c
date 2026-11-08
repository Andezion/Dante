#include <stdio.h>

int main(void)
{
    int ocena = 0;

    printf("Enter your mark: ");
    scanf("%d", &ocena);

    switch (ocena)
    {
        case 1:
            printf("Brak promocji do nastepnej klasy");
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Promocja do nastepnej klasy");
            break;
        case 6:
            printf("Promocja z ocena celujaca");
            break;
        default:
            printf("Wprowadzona ocena jest niepoprawna");
    }

    return 0;
}
