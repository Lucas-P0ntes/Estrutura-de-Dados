#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0; // Números menores ou iguais a 1 não são primos
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Encontrou um divisor, portanto não é primo
        }
    }

    return 1; // Não encontrou divisores, é primo
}

int main() {
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d é um número primo.\n", num);
    } else {
        printf("%d não é um número primo.\n", num);
    }

    return 0;
}
