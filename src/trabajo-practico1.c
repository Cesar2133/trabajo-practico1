/*
 ============================================================================
 Name        : pedirNumEnteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "PedirNumero.h"


int main()
{
	setbuf(stdout, NULL);
	// variable de datos a ingresar
    float kilometros;
    float precioLatam;
    float precioAerolineas;

    //variables latam.
    float tarjetaDebitoLatam;
    float tarjetaCreditoLatam;
    float bitLatam;
    float precioUnitarioLatam;
    float diferenciaDeprecios;

    // variables Areolineas;
    float tarjetaDebitoAreo;
    float tarjetaCreditoAreo;
    float bitAreo;
    float precioUnitarioAreo;


    //valor de bitcoin.
    float bitcoin = 4606954.55;

    // Variables forzadas
    int kms = 7090;
    int AreolineaArgentina = 162965;
    int Latam = 159339;


    int opcion;

    // banderas
    int contadorkms = 0;
    int contadorDePrecio = 0;
    int contadorOpcion3 = 0;


    do{

    	fflush(stdin);
    	printf("1. Ingresar Kilometros: ");
    	printf("\n2. Ingresar precio de vuelo: ");
    	printf("\n3. Calcular todos los costos: ");
    	printf("\n4. Informar resultados: ");
    	printf("\n5. carga forzada de datos:  ");
    	printf("\n6. Salir: ");
    	printf("\nopcion: ");
    	scanf("%d",&opcion);


    	switch(opcion)
    	{
    		case 1:
    			// Ingreso de kilometros con la funcion pedirNumero.

    			kilometros = PedirEnteroPositivo("Ingrese los kilometros: ","Error ingreso cero o un numero no positivo, reingrese los kilometros: ");
    			if(kilometros > 0)
    			{
    				contadorkms++;
    			}

    			break;

    		case 2:
    			// Ingreso de precios con la funcion pedirNumero

    			 precioLatam = PedirEnteroPositivo("Ingrese precioLatam: ","Error ingreso cero o un numero no positivo, reingrese los precios de Latam: ");
    			 precioAerolineas = PedirEnteroPositivo("Ingrese los precioAerolineas: ","Error ingreso cero o un numero no positivo, reingrese los precios de Aerolineas: ");
    			 if(precioLatam > 0 && precioAerolineas > 0)
    			 {
    				 contadorDePrecio++;
    			 }

    			break;

    		case 3:

    			if(contadorkms > 0 && contadorDePrecio > 0)
    			{	// calculos de Areolineas.
    				tarjetaDebitoAreo = precioAerolineas - (precioAerolineas * 0.10);
    				tarjetaCreditoAreo = precioAerolineas * 1.25;
    				bitAreo = precioAerolineas / bitcoin;
    				precioUnitarioAreo = precioAerolineas / kilometros;

    				// calculos de Latam.
    				tarjetaDebitoLatam = precioLatam -(precioLatam * 0.10);
    				tarjetaCreditoLatam = precioLatam * 1.25;
    				bitLatam = precioLatam / bitcoin ;
    				precioUnitarioLatam = precioLatam / kilometros;
    				diferenciaDeprecios = precioLatam - precioAerolineas;
    				printf("Sus datos ya han sido calculados");
    				contadorOpcion3++;
    			}
    			else
    			{
    				printf("No hay datos para calcular");
    			}

    			break;

    		case 4:

    			if(contadorkms > 0 && contadorDePrecio > 0 && contadorOpcion3 > 0)

    			{	// resultados de latam
    				printf("Kilometraje: %.2f",kilometros);
    				printf("Latam: ");

    				printf("\nPrecio De Latam: %.2f",precioLatam);
    				printf("\na).precio con tarjeta de debito: %.2f ",tarjetaDebitoLatam);
    				printf("\nb).precio con tarjeta de credito: %.2f ",tarjetaCreditoLatam);
    				printf("\nc).precio con bitcoin: %.2f ",bitLatam);
    				printf("\nd).Precio unitario latam: %.2f ",precioUnitarioLatam);
    				// resultados de areolinia
    				printf("\nAerolinias: ");

    				printf("\nPrecio De Areolinia: %.2f ",precioAerolineas);
    				printf("\na).precio con tarjeta de debito: %.2f ",tarjetaDebitoAreo);
    				printf("\nb).precio con tarjeta de credito: %.2f ",tarjetaCreditoAreo);
    				printf("\nc).precio con bitcoin: %.2f ",bitAreo);
    				printf("\nd).Precio unitario areolineas: %.2f",precioUnitarioAreo);
    				printf("\ne).Diferencia de precios (latam y areoleoneas): %.2f ",diferenciaDeprecios);

    			}

    			else if(contadorkms > 0 && contadorDePrecio > 0 && contadorOpcion3 == 0)
    			{
    				printf("Primero tiene que ingresar la opcion 3 para mostrar los calulos.");
    			}
    			else
    			{
    				printf("No hay datos ingresados para mostrar esta opcion.");
    			}
    			break;

    		case 5:
    			// Carga Forzada

    			printf("\nKm: %d",kms);
    			printf ("\nAreolinia argentina: %d",AreolineaArgentina);
    			printf("\nlatam: %d",Latam);
    			break;

    		case 6:
    			// Opcion salir

    			printf("Ha salido del menu");
    			fflush(stdin);
    			break;

    		default:
    			// ERROR de carga al menu
    			printf("La opcion no es correcta,Ingrese un numero correspondiente al menu.");

    			break;


    			fflush(stdin);

    	}
    	printf("\n\n");

    }while(opcion != 6);

    return 0;
}




