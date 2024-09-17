#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>  // Para la función sleep()

#define MAX_DISCOS 10  // Máximo número de discos

void imprimirTorres(int n, int torres[3][MAX_DISCOS]);
void moverDisco(int origen, int destino, int torres[3][MAX_DISCOS], int *top);

void hanoi(int n, int origen, int destino, int auxiliar, int torres[3][MAX_DISCOS], int *top) {
    if (n == 1) {
        moverDisco(origen, destino, torres, top);  // Mover el disco directamente
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino, torres, top);  // Mover n-1 discos al auxiliar
    moverDisco(origen, destino, torres, top);  // Mover el disco más grande
    hanoi(n - 1, auxiliar, destino, origen, torres, top);  // Mover n-1 discos al destino
}

// Función para mover un disco de una torre a otra
void moverDisco(int origen, int destino, int torres[3][MAX_DISCOS], int *top) {
    // Mover el disco del origen al destino
    torres[destino][++top[destino]] = torres[origen][top[origen]--];
    
    // Imprimir el estado actual de las torres
    imprimirTorres(MAX_DISCOS, torres);
    
    // Esperar un poco para que se pueda ver el movimiento
    sleep(1);  // Pausa de 1 segundo entre movimientos
}

// Función para imprimir las torres en la consola
void imprimirTorres(int n, int torres[3][MAX_DISCOS]) {
    // Limpiar la pantalla (en Windows usar "cls")
        #ifdef _WIN32
            system("cls");  // Comando para Windows
        #else
            system("clear");  // Comando para Unix/Linux
        #endif
        
    // Imprimir las tres torres fila por fila
    for (int i = n - 1; i >= 0; i--) {
        for (int t = 0; t < 3; t++) {
            if (torres[t][i] != 0) {
                // Imprimir el disco
                for (int j = 0; j < torres[t][i]; j++) {
                    printf("-");
                }
            } else {
                // Imprimir espacio en blanco
                printf(" ");
            }
            printf("\t");  // Espacio entre torres
        }
        printf("\n");
    }
    // Imprimir las bases de las torres
    printf("====\t====\t====\n");
    printf(" A  \t B  \t C  \n");
}

int main() {
    int n;

    // Pedir al usuario el número de discos
    printf("Introduce el número de discos (máximo %d): ", MAX_DISCOS);
    scanf("%d", &n);

    // Inicializar las torres: cada columna es una torre, cada fila es un disco
    int torres[3][MAX_DISCOS] = {0};  // 3 torres y hasta MAX_DISCOS discos
    int top[3] = {n-1, -1, -1};  // Índices superiores de cada torre

    // Colocar los discos en la torre 0 (origen)
    for (int i = 0; i < n; i++) {
        torres[0][i] = n - i;
    }

    // Imprimir el estado inicial de las torres
    imprimirTorres(n, torres);
    sleep(1);

    // Resolver el problema usando recursividad
    hanoi(n, 0, 2, 1, torres, top);

    return 0;
}
