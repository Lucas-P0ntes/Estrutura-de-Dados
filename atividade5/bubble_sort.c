#include<stdio.h>
#include<stdlib.h>
#include "bubble_sort.h"

void swap (char **arr1, char **n2){
    char *tmp = *arr1;
    *arr1 = *n2;
    *n2 = tmp;
};

void bubble_sort(char arr[], int n){
    int tmp;
    for (int i = 0; i < n-1; i++){ // n-1 porque o último elemento já estará ordenado
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
            
        }
        
    }

};