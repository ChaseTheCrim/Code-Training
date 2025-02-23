#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

    char metin[25];

    printf("buyuk harfli bir metin giriniz: ");
    scanf("%s", metin);

    for(int i = 0; metin[i]; i++){
        metin[i] = tolower(metin[i]);
    }

    printf("\nkucuk harfli donusum: %s", metin);

    return 0;
}
