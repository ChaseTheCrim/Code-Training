#include <stdio.h>
#include <string.h>

int main() {
    char cumle[1000];
    char kelime[25];
    int kackere = 0;

    printf("Cumle giriniz: ");
    scanf("%999[^\n]%*c", cumle);

    printf("Aranacak kelimeyi giriniz: ");
    scanf("%24s", kelime);

    char* ptr = cumle;

    while ((ptr = strstr(ptr, kelime)) != NULL) {
        kackere++;
        ptr++;
    }

    printf("'%s' kelimesi cumle icinde %d kez geciyor.\n", kelime, kackere);

    return 0;
}
