#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Uso: %s <num1> <num2> <num3> ...\n", argv[0]);
        return 1;
    }

    int arr[argc-1];
    for(int i = 1; i < argc; i++) {
        arr[i-1] = atoi(argv[i]);
    }

    int n = argc - 1;

    bubble_sort(arr, n);

    printf("Saída:");
    for(int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}
