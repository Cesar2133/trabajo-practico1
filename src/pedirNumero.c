/*
 * pedirNumero.c
 *
 *  Created on: 11 abr 2022
 *      Author: cesar
 */
#include <stdio.h>
#include <stdlib.h>


float PedirEnteroPositivo(char mensaje[],char error[])

{
    float numero;

    printf("%s",mensaje);
    scanf("%d", &numero);

    while(numero < 1)
    {
        printf("%s",error);
        scanf("%d", &numero);
    }

    return numero;
}

