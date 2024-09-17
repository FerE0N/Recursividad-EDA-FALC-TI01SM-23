#include <stdio.h>
int num;
void sacarBinario(int b){
    if (b==0){
        return;
    }
    sacarBinario(b/2);
    printf("%d",b % 2);
}

int main(){
    printf("Enteros a binarios\nNumero:");
    scanf("%d",&num);
    if (num<0){
        printf("%d Es un numero negativo.\nEl proceso no es posible con numeros negativos.",num);
    }else{
        printf("Representacion binaria de %d es:",num);
        sacarBinario(num);
        printf("\n");
        return 0;
    }
}