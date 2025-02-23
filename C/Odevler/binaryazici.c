#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int sayi1, sayi2;
    int onay = 0;
    int tutucu,switcheroo,uzunluk;
    int i,j;

    while (onay == 0) {
        printf("ilk sayiyi giriniz: ");
        scanf("%d", &sayi1);
        if (sayi1 > 16000) {
            printf("Sayi cok buyuk! (Maksimum limit 16000)\n");
        } else if (sayi1 < 0) {
            printf("Sayi negatif! (Lutfen pozitif bir sayi giriniz.)\n");
        } else {
            onay = 1;
        }
    }

    char* sayidizisi1 = (char*)malloc((sayi1 + 1) * sizeof(char));
    sprintf(sayidizisi1, "%d", sayi1);
    int stringboy1 = strlen(sayidizisi1);

    onay = 0;

    while (onay == 0) {
        printf("ikinci sayiyi giriniz: ");
        scanf("%d", &sayi2);
        if (sayi2 > 16000) {
            printf("Sayi cok buyuk! (Maksimum limit 16000)\n");
        } else if (sayi2 < 0) {
            printf("Sayi negatif! (Lutfen pozitif bir sayi giriniz.)\n");
        } else {
            onay = 1;
        }
    }

    char* sayidizisi2 = (char*)malloc((sayi2 + 1) * sizeof(char));
    sprintf(sayidizisi2, "%d", sayi2);
    int stringboy2 = strlen(sayidizisi2);

    char* binaryformat1 = (char*)malloc((stringboy1 + 1) * sizeof(char));
    tutucu = 0;

    while (sayi1 > 0) {
        binaryformat1[tutucu++] = (sayi1 % 2) + '0';
        sayi1 /= 2;
    }
    binaryformat1[tutucu] = '\0';

    i = 0;
    j = tutucu - 1;
    while (i < j) {
        char temp = binaryformat1[i];
        binaryformat1[i] = binaryformat1[j];
        binaryformat1[j] = temp;
        i++;
        j--;
    }

    tutucu = 0;

    char* binaryformat2 = (char*)malloc((stringboy2 + 1) * sizeof(char));

    while (sayi2 > 0) {
        binaryformat2[tutucu++] = (sayi2 % 2) + '0';
        sayi2 /= 2;
    }
    binaryformat2[tutucu] = '\0';

    i = 0;
    j = tutucu - 1;
    while (i < j) {
        char temp = binaryformat2[i];
        binaryformat2[i] = binaryformat2[j];
        binaryformat2[j] = temp;
        i++;
        j--;
    }
    
uzunluk = stringboy1 + stringboy2;

    int* binaryformat1int = (int*)malloc((uzunluk + 1) * sizeof(int));
    int* binaryformat2int = (int*)malloc((uzunluk + 1) * sizeof(int));
    int* sonucdizisi = (int*)malloc((uzunluk + 1) * sizeof(int));

    for (int i = 0; i < stringboy1; i++) {
        binaryformat1int[i] = binaryformat1[i] - '0';
    }
    for (int i = 0; i < stringboy2; i++) {
        binaryformat2int[i] = binaryformat2[i] - '0';
    }

    printf("hangi islemi yapmak istersiniz?\n");
    printf("1 - VE\n");
    printf("2 - VEYA\n");
    printf("3 - XOR\n");
    scanf("%d", &switcheroo);

    switch(switcheroo) {

    case 1:
        for(int i = 0; i < uzunluk;i++){
           sonucdizisi[i] = binaryformat1int[i] && binaryformat2int[i];
        }
        break;
        
    case 2:
        for(int i = 0; i < uzunluk;i++){
           sonucdizisi[i] = binaryformat1int[i] || binaryformat2int[i];
        }
        break;

    case 3:
        for(int i = 0; i < uzunluk;i++){
           sonucdizisi[i] = binaryformat1int[i] ^ binaryformat2int[i];
        }
        break;

        default:
        
        printf("hatali girdi.");
        
        return 0;
    }

    printf("-----------------------------\n");
    printf("girilen ilk sayi: %s\n", sayidizisi1);
    printf("girilen ikinci sayi: %s\n", sayidizisi2);
    printf("\n");
    printf("ilk sayinin binary degeri: %s\n", binaryformat1);
    printf("ikinci sayinin binary degeri: %s\n", binaryformat2);
    printf("binary ile yapilan islemin sonucu: ");
        for (int i = 0; i < uzunluk; i++) {
        printf("%d", sonucdizisi[i]);
    }

    free(sayidizisi1);
    free(sayidizisi2);
    free(binaryformat1);
    free(binaryformat2);
    free(sonucdizisi);

    return 0;
}