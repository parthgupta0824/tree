#include <stdio.h>
void main(){
    int i, j;
    printf("Enter a number of your choice:");
    scanf("%d", &i);
    if (i < 55){
        for (i = 1; i <= 111; i++){
            for (j = 1; j <= i; j++) printf("*", j);
            printf("\n");
        }
        return ;
    }
    else{
        while (i <= 111){
            j = 1;
            while (j <= i) printf("&"),j++;
            printf("\n");
            i++;
        }
    }
    return ;
}