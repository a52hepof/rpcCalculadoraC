/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "prueba.h"
#include <time.h>

void
calculadora_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	operandos  suma_1_arg;
	int  *result_2;
	operandos  multiplicacion_1_arg;
	int  *result_3;
	operandos  resta_1_arg;
	int  *result_4;
	operandos  division_1_arg;


	char operador[4];
	int a;
	int b;

	clock_t start, end;
	double cpu_time_used;
	 
	
	
	printf("Calculadora Simple RPC\n"); // msj incial

    printf("Ingrese el primer operando\n ");
    scanf("%i", &a);
    printf("Ingrese el segundo operando\n ");
    scanf("%i", &b);

    printf("Ingrese operación que desea realizar:\n");
    printf("1.Suma\t\t\t\t+"); printf("\n");
	printf("2.Resta\t\t\t\t-"); printf("\n");
	printf("3.multiplicar\t\t\t*"); printf("\n");
	printf("4.Dividir\t\t\t/"); printf("\n");
	printf("6.Test Suma Local\t\tTL"); printf("\n");
	printf("7.Test Suma Servidor local\tTSL"); printf("\n");
	printf("8.Test Suma Servidor remoto\tTSR"); printf("\n");
	printf("9.Salir de la aplicación\tEXIT"); printf("\n");


    scanf("%s", operador);


	clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}


	if (strcmp(operador, "+")==0){
     	
     	suma_1_arg.a=a; //asigna el valor de n1 num1
        suma_1_arg.b=b; //asigna el valor de n2 num2

		result_1 = suma_1(&suma_1_arg, clnt);

		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}

    	printf("Resultado %i\n",*result_1);


	};


	if (strcmp(operador, "-")==0){
     	
     	resta_1_arg.a=a; //asigna el valor de n1 num1
        resta_1_arg.b=b; //asigna el valor de n2 num2

		result_2 = resta_1(&resta_1_arg, clnt);

		if (result_2 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}

    	printf("Resultado %i\n",*result_2);


	};


	if (strcmp(operador, "TSL")==0){
     	
     	suma_1_arg.a=a; //asigna el valor de n1 num1
        suma_1_arg.b=b; //asigna el valor de n2 num2

		start = clock();

        for (int i=0; i<10000;i++){

			result_1 = suma_1(&suma_1_arg, clnt);

        }

		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}

    	//printf("Resultado %i\n",*result_1);
		printf("Tiempo procesamiento %.2f\n",cpu_time_used );

	};



	if (strcmp(operador, "EXIT")==0){
    	exit (0);
    }


	/*
	result_2 = multiplicacion_1(&multiplicacion_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = resta_1(&resta_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = division_1(&division_1_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	*/

		clnt_destroy (clnt);
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}




	host = argv[1];
	calculadora_prog_1(host);


    exit (0);


}
