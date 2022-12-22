#include <stdio.h>

#include <string.h>
#include <stdlib.h>

int main(void) {

    //Numeros Romanos

    char roman_numeral[16];
    int decimal = 0;

    printf("Ingrese un numero romano: ");
    scanf("%s", roman_numeral);
    int caracter = strlen(roman_numeral) -1;

    for (int i = 0; i < strlen(roman_numeral); i++) {
        switch (roman_numeral[i]) {
            case 'I':
                if(caracter == i){
                    decimal += 1;
                }else{
                    decimal -= 1;
                }
                break;
            case 'V':
                decimal += 5;
                break;
            case 'X':
                decimal += 10;
                break;
            case 'L':
                decimal += 50;
                break;
            case 'C':
                decimal += 100;
                break;
            case 'D':
                decimal += 500;
                break;
            case 'M':
                decimal += 1000;
                break;
            default:
                printf("El numero romano es invalido, asegurese de que este bien escrito y en mayuscula.\n");
                return 1;
        }

    }

    printf("El numero romano es equivalente a %d en base 10.\n", decimal);

    //Numeros magicos

    int num, a, b, c, d, e,ascendente,descendente,resta;

    printf("Ingrese un numero de 3 digitos: ");
    scanf("%d", &num);
    a = num / 100;
    b = (num / 10) % 10;
    c = num % 10;

    // Ordenar los dígitos de forma ascendente
    if (a > b) {
        d = a;
        a = b;
        b = d;
    }
    if (b > c) {
        d = b;
        b = c;
        c = d;
    }
    if (a > b) {
        d = a;
        a = b;
        b = d;
    }
    a=a*100;
    b=b*10;
    ascendente= a + b + c;
    a=a/100;
    b=b/10;
    printf("Ascendente: %d%d%d\n", a, b, c);

    // Ordenar los dígitos de forma descendente
    if (a < b) {
        d = a;
        a = b;
        b = d;
    }
    if (b < c) {
        d = b;
        b = c;
        c = d;
    }
    if (a < b) {
        d = a;
        a = b;
        b = d;
    }
    a=a*100;
    b=b*10;
    descendente= a + b + c;
    a=a/100;
    b=b/10;
    printf("Descendente: %d%d%d\n", a, b, c);
    resta=descendente-ascendente;
    printf("Resta: %d\n",resta);
    if(resta==num){
        printf("El numero es magico");
    }else{
        printf("El numero no es magico");
    }

    //Multiplicación de matrices
    int i, j, k;
    int filas1, columnas1, filas2, columnas2;
    int matriz1[100][100], matriz2[100][100], resultado[100][100];


    printf("Ingrese las filas de la primera matriz: ");
    scanf("%d", &filas1);
    printf("Ingrese las columnas de la primera matriz: ");
    scanf("%d", &columnas1);
    printf("Ingrese las filas de la segunda matriz: ");
    scanf("%d", &filas2);
    printf("Ingrese las columnas de la segunda matriz: ");
    scanf("%d", &columnas2);

    if (columnas1 != filas2) {
        printf("**********************************************\n");
        printf("Las matrices no se pueden multiplicar.\n");
        printf("**********************************************\n");
        return 1;
    }

    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas1; j++) {
            matriz1[i][j] = rand()%11 +1;
        }
    }

    for (i = 0; i < filas2; i++) {
        for (j = 0; j < columnas2; j++) {
            matriz2[i][j] = rand()%11 +1;
        }
    }

    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas2; j++) {
            resultado[i][j] = 0;
            for (k = 0; k < columnas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    printf("**********************************************\n");
    printf("El resultado de la multiplicacion de las dos matrices es: \n");
    printf("**********************************************\n");
    for (i = 0; i < filas1; i++) {
        for (j = 0; j < columnas2; j++)
            printf("%d\t", resultado[i][j]);

        printf("\n");

    }
    printf("**********************************************\n");

    return 0;
}

