#include<stdio.h>
long int num;
int obtenFactorDec(int b){
    if (b==0 || b==1){
        return 1;
    }
    return b * obtenFactorDec(b-1);
}
int obtenFactorInc(int i, int resultado, int num1){
    if (i>num1){
        return resultado;
    }
    resultado *= i;
    obtenFactorInc(i+1, resultado, num1);
}

int main(){
    printf("Factoriales de numeros.\nNumero:");
    scanf("%d",&num);
    if (num>=0){
        printf("Factorial de %d: %d",num, obtenFactorDec(num));
        printf("\nFactorial de %d: %d",num, obtenFactorInc(1,1,num));
    }else{
        printf("Valor negativo invalido");
    }
    return 0;
}