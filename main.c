#include <stdio.h>

#include <stdio.h>
#include <string.h>

int main(void) {
    char roman_numeral[16];
    int i, decimal = 0;

    printf("Ingrese un numero romano: ");
    scanf("%s", roman_numeral);
    int caracter = strlen(roman_numeral) -1;

    for (i = 0; i < strlen(roman_numeral); i++) {
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

    return 0;
}

