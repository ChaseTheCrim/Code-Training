#include <stdio.h>

int main() {

    float B[] = {8.9 ,15.4 ,3.2, 12.7, 5.1};

    float maximum = B[0];

for(int i=0;i<5;i++){
        if(maximum< B[i]){
    maximum = B[i];
    }
}
printf("%.1f", maximum);

    return 0;
}