#include <stdio.h>
#include <math.h>
#include<stdbool.h>
#include <string.h>
#include <stdlib.h>

//Parte Kevin
int numeroRomano();

void numeroMagico();

int multiplicacionMatrices();

//Parte Camilo
void borrarEspacios();

void fecha();

void mostrarMatrizMagica();

// Parte Juan Diego
void calcularFactoresPrimos();

void calcularNumerosEgolatras();

void calcularProductoPunto();

int main() {

    int option = 0;

    do {
        printf("\n---MENU DE FUNCIONES--- \n"
               "1. Numeros Romanos \n"
               "2. Factores primos \n"
               "3. Borrar espacios \n"
               "4. Numeros egolatras \n"
               "5. Numero Magico \n"
               "6. Fechas \n"
               "7. Producto Punto \n"
               "8. Multiplicacion de matrices \n"
               "9. Matriz Magica \n"
               "10. salir \n"
               "Introduzca una opcion: \n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                numeroRomano();
                break;
            case 2:
                calcularFactoresPrimos();
                break;
            case 3:
                borrarEspacios();
                break;
            case 4:
                calcularNumerosEgolatras();
                break;
            case 5:
                numeroMagico();
                break;
            case 6:
                fecha();
                break;
            case 7:
                calcularProductoPunto();
                break;
            case 8:
                multiplicacionMatrices();
                break;
            case 9:
                mostrarMatrizMagica();
                break;
        }
    } while (option != 10);

}

//Numeros Romanos
int numeroRomano() {
    char roman_numeral[16];
    int decimal = 0;

    printf("Ingrese un numero romano: ");
    scanf("%s", roman_numeral);

    int caracter = strlen(roman_numeral) - 1;

    for (int i = 0; i < strlen(roman_numeral); i++) {
        switch (roman_numeral[i]) {
            case 'I':
                if (caracter == i) {
                    decimal += 1;
                } else {
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
}

//Factores primos
void calcularFactoresPrimos() {
    int num;
    printf("Digite un numero: ");
    scanf("%i", &num);
    //printf("%s\n", calcularFactoresPrimos(num));
    if(num == 1){
        printf("%i\n",num);
    }
    else{
        int factores[num/2]; // Almacenamos los factores primos en un vector
        int exponentes[num/2];
        int primos[num/2];
        int factor = 2; // Se toma como primer primo el 2
        // llenar vector de factores
        int numFact = 0;
        int i = 0;
        while(num != 1){
            if((num%factor) == 0){ // El numero es divisible entre el factor primo
                int numExp = 0; // contador
                while((num%factor) == 0){
                    num = num / factor;
                    factores[numFact] = factor;
                    numFact++;
                    numExp++;
                }
                primos[i] = factor;
                exponentes[i] = numExp;
                i++;
            }else {
                factor++; //Incrementa el factor en 1
            }
        }
        int contador = 1;
        for(int j = 0; j < i; j++){
            if(contador < i){
                if(exponentes[j] == 1){
                    printf("%i*",primos[j],exponentes[j]);
                }else{
                    printf("%i^%i*",primos[j],exponentes[j]);
                }
            }else{
                if(exponentes[j] == 1){
                    printf("%i",primos[j],exponentes[j]);
                }else{
                    printf("%i^%i",primos[j],exponentes[j]);
                }
            }
            contador++;
        }
        printf("\n");
    }
}

//Borrar espacios
void borrarEspacios() {
    char cadena[60];
    char stringSalida[60];
    printf("Ingrese un texto corto: \n");

    scanf("\n%[^\n]", cadena);

    int auxIndex = 0;
    for (int i = 0; i < strlen(cadena); ++i) {
        if (cadena[i] != *" ") {
            stringSalida[auxIndex] = cadena[i];
            auxIndex++;
        }
    }

    printf("Texto sin espacios: \n");
    printf("%s", stringSalida);
}

//Numeros egolatras
void calcularNumerosEgolatras(){
    int num;
    printf("Digite un numero: ");
    scanf("%i", &num);
    // num2 y num3 almacenan el valor de num para realizar las respectivas operaciones
    int num2 = num; //La variable num2 guarda el valor del numero ingresado
    int num3 = num;
    // Determinamos el numero de digitos del num ingresado
    int cont = 1; // contador
    while (num3 >= 10){
        num3 = num3/10;
        cont++;
    }
    int tamanio = cont; // A la variable tama??o le asignamos el numero de digitos del num ingresado
    int secuencia[tamanio];// se crea un vector de enteros con el tama??o
    // rellenamos el arreglo de numeros con los digitos del num ingresado, de forma inversa
    for(int i = 0; num!=0;i++ ){
        secuencia[i] = num % 10;
        num /= 10;
    }
    int a, b, c, aux;
    int suma = 0;
    aux = tamanio-1; //
    for(int i = 0; i < tamanio; i++){
        a = secuencia[aux]; // base
        b = tamanio; //exponente
        c = pow(a, b);// Calculamos la potencia
        suma = suma + c;
        aux--;
    }
    // Mostramos verdadero si el numero es egolatra o falso si no lo es
    if(num2 == suma){ // El resultado de la suma de las potencias es igual al numero ingresado
        printf("VERDADERO\n");
    }else{
        printf("FALSO\n");
    }
}

//Numeros magicos
void numeroMagico() {
    int num, a, b, c, d, e, ascendente, descendente, resta;

    printf("Ingrese un numero de 3 digitos: ");
    scanf("%d", &num);
    a = num / 100;
    b = (num / 10) % 10;
    c = num % 10;

    // Ordenar los d??gitos de forma ascendente
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
    a = a * 100;
    b = b * 10;
    ascendente = a + b + c;
    a = a / 100;
    b = b / 10;
    printf("Ascendente: %d%d%d\n", a, b, c);

    // Ordenar los d??gitos de forma descendente
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
    a = a * 100;
    b = b * 10;
    descendente = a + b + c;
    a = a / 100;
    b = b / 10;
    printf("Descendente: %d%d%d\n", a, b, c);
    resta = descendente - ascendente;
    printf("Resta: %d\n", resta);
    if (resta == num) {
        printf("El numero es magico");
    } else {
        printf("El numero no es magico\n");
    }
}

//Fechas
void fecha() {
    int day, month, year;
    printf("Ingresa la fecha que desees (dd/mm/aaaa): \n");
    scanf("%d/ %d/ %d", &day, &month, &year);

    if (year < 2023) {
        switch (month) {
            case 1:
                if (day <= 31) {
                    printf("%d de Enero de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 2:
                if (day <= 28) {
                    printf("%d de Febrero de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 3:
                if (day <= 31) {
                    printf("%d de Marzo de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 4:
                if (day <= 30) {
                    printf("%d de Abril de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 5:
                if (day <= 31) {
                    printf("%d de Mayo de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 6:
                if (day <= 30) {
                    printf("%d de Junio de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 7:
                if (day <= 31) {
                    printf("%d de Julio de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 8:
                if (day <= 31) {
                    printf("%d de Agosto de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 9:
                if (day <= 30) {
                    printf("%d de Septiembre de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            case 10:
                if (day <= 31) {
                    printf("%d de Octubre de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;

            case 11:
                if (day <= 30) {
                    printf("%d de Noviembre de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;

            case 12:
                if (day <= 31) {
                    printf("%d de Diciembre de %d ", day, year);
                } else {
                    printf("dia invalido");
                }
                break;
            default:
                printf("Mes invalido");
        }
    } else {
        printf("tiempo invalido");
    }
}

//Producto punto
void calcularProductoPunto(){
    int v1[3], v2[3];
    // Llenar vector 1
    printf("Ingrese el valor de cada componente del vector 1\n ");
    for(int i = 0; i < 3; i++){
        i++;
        printf("Componente %i = ",i);
        i--;
        scanf("%i",&v1[i]);
    }
    // Llenar vector 2
    printf("Ingrese el valor de cada componente del vector 2\n ");
    for(int i = 0; i < 3; i++){
        i++;
        printf("Componente %i = ",i);
        i--;
        scanf("%i",&v2[i]);
    }
    // Calcular producto punto
    int escalar = 0;
    for(int i = 0; i < 3; i++){
        escalar = escalar + (v1[i]*v2[i]);
    }
    // Obetener producto punto entre v1 y v2
    printf("El producto vectorial entre v1 y v2 es: %i \n",escalar);
}

//Multiplicaci??n de matrices
int multiplicacionMatrices() {
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
            matriz1[i][j] = rand() % 11 + 1;
        }
    }

    for (i = 0; i < filas2; i++) {
        for (j = 0; j < columnas2; j++) {
            matriz2[i][j] = rand() % 11 + 1;
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

#define nums 100

//Matriz Magica
void matrizMagica(int n) {
    int a[nums][nums];
    int i,j;
    i = 1;
    j = (1+n)/2;
    a[i][j] = 1;
    int sumarFilas;

    if(n % 2 == 0) {
        printf("No es posible hacerlo con un numero par");
        return;
    }

    for(int value = 2; value <= n*n; value++){
        sumarFilas = 0;
        i -= 1;
        j += 1;
        if(i < 1 && j > n){
            i += 2;
            j -= 1;
        }else{
            if(i < 1){
                i = n;
            }
            if(j > n){
                j = 1;
            }
        }
        if(a[i][j] == 0){
            a[i][j] = value;
        }else{
            i += 2;
            j -= 1;
            a[i][j] = value;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", a[i][j]);

        }
        sumarFilas = sumarFilas + a[i][j];


        printf("\n");
    }
    printf("la suma de cada una de sus filas, columnas y diagonales es de %d", sumarFilas);

}

//Muestra la matriz magica
void mostrarMatrizMagica() {
    printf("Ingrese la dimension de la matriz magica impar: \n");
    int a[nums][nums];
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = 0;
        }
    }

    matrizMagica(n);
}
