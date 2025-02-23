#include <stdio.h>

int main(){
int n;
printf("sayı diziniz kaç sayılı olsun?\n");
scanf("%d", &n);
int A[n];
printf("dizi değerlerini girinz.\n");

for(int i = 0 ; i<n ; i++){
   scanf("%d", &A[i]);
}

for(int i = 0 ; i<n ; i++){
printf("%d ", A[i]);
}

return 0;
}