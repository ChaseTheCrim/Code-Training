#include <stdio.h>

int main(){

int n,i;

printf("dizi kaç sayılı olsun?\n");
scanf("%d", &n);

int A[n];
printf("dizi elemanlarını giriniz.\n");

for(i=0;i<n;i++){
    scanf("%d", &A[i]);}
    
printf("tek sayılar:\n");
for(i=0;i<n;i++){
    if (A[i]%2==1){
        printf("%d ", A[i]);}}

printf("\n");

printf("çift sayılar:\n");
for(i=0;i<n;i++){
    if (A[i]%2==0){
        printf("%d ", A[i]);}}

return 0;
}