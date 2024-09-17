#include <stdio.h>

// Función recursiva para mover los discos
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    hanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int discos;
    printf("Introduce el número de discos: ");
    scanf("%d", &discos);
    hanoi(discos, 'A', 'C', 'B'); // A es la origen, C es la destino, B es la auxiliar
    return 0;
}
