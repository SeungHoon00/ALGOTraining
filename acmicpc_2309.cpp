#include <stdio.h>

void main(){
    int array[10];
    int ans[7];
    int a, temp;
    for (int i = 0; i < 10; i++){
        scanf("%d", &a);
        array[i] = a;
    }
    for (int i = 0; i < 10; i++){
        for (int j = i; j < 10; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp; 
            }
        }
    }
    for(int i = 0; i < 10; i++)
       printf("%d", array[i])
}