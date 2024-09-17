#include<stdio.h>

int FibonacciSeries(int n) {
    // Caso base
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Llamada recursiva
    return FibonacciSeries(n - 1) + FibonacciSeries(n - 2);
}

// Función recursiva para imprimir la serie
void PrintFibonacciSeries(int current, int limit) {
    if (current > limit-1) {
        return;
    }
    // Imprimir el valor actual de la serie de Fibonacci
    printf("%d ", FibonacciSeries(current));
    
    // Llamada recursiva incrementando la posición actual
    PrintFibonacciSeries(current + 1, limit);
}

int main() {
    int num;

    // Entrada del usuario
    printf("Serie de Fibonacci\n");
    printf("Escriba hasta que posición de la serie quiere ver\nPosicion: ");
    scanf("%d", &num);

    // Imprimir la serie de Fibonacci hasta la posición indicada
    printf("Serie de Fibonacci hasta la posición %d:\n", num);
    PrintFibonacciSeries(0, num); // Llamada a la función recursiva para imprimir
    printf("\n");

    //Imprimir la sumatoria total
    printf("Total: %d",FibonacciSeries(num));
    printf("\n");

    return 0;
}
