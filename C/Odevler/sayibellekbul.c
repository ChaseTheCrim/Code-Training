#include <stdio.h>

int main() {
    int x;

    printf("sayi giriniz: ");
    scanf("%d", &x);

       int* ptr = &x;

    printf("bellek adresi: %p\n", ptr);
    printf("bellekteki ilk deger: %p\n", ptr[0]);
    // son değeri nasıl gösteririm bilemedim
    return 0;
}
