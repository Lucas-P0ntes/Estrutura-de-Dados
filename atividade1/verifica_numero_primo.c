#include <stdio.h>

int main() {
    int numero, i, primo = 1;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    if (numero <= 1) {
        primo = 0;
    } else {
        for (i = 2; i * i <= numero; i++) {
            if (numero % i == 0) {
                primo = 0;
                break;
            }
        }
    }
    
    if (primo) {
        printf("1");
    } else {
        printf("0");
    }
    
    return 0;
}
