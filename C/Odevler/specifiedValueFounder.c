#include <stdio.h>
#include <stdlib.h>

int main(){

    int ArrSize,DefSrch;
    int ScsflFind=0;

    printf("dizi eleman sayisini girin: ");
    scanf("%d", &ArrSize);

    int* Arr = (int*)malloc(ArrSize * sizeof(int));

    printf("dizinin elemanlarini giriniz: \n");
    for(int i=0; i < ArrSize ;i++){
        printf("%d- ", i+1);
        scanf("%d", &Arr[i]);
    }

    printf("dizide aramak istediginiz deger: ");
    scanf("%d", &DefSrch);

    for(int i=0;i<ArrSize;i++){
        if(Arr[i] == DefSrch){
            printf("Aradiginiz deger %d. konumda bulunudu.\n", i+1);
            ScsflFind = 1;
        }
    }

    if(!ScsflFind){
        printf("girdiginiz deger bulunamadi.");
    }

free(Arr);

    return 0;

}