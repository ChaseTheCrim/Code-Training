#include <stdio.h>

//fonk. prototip
void bul(int A[],int n);

int main(){

int n,i;

printf("dizi kaç sayılı olsun?\n");
scanf("%d", &n);

int A[n];
printf("dizi elemanlarını giriniz.\n");

for(i=0;i<n;i++){
    scanf("%d", &A[i]);}

bul(A,n);

return 0;
}

void bul(int A[],int n){    
printf("tek sayılar:\n");
for(int i=0;i<n;i++){
    if (A[i]%2==1){
        printf("%d ", A[i]);}}

printf("\n");

printf("çift sayılar:\n");
for(int i=0;i<n;i++){
    if (A[i]%2==0){
        printf("%d ", A[i]);}}

return;        
}
