#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define tam 20

int prioridad(char simbolo);



int main()
{

	int opcion;
	int tope=-1;
	int pos=-1;
	int tamExpresion;
	int pila[tam],epos[tam],epre[tam];
	char infija[tam],simbolo;
	do{
		system("cls");

		printf("\n         	Menu de Opciones           ");
		printf("\n  1.Convertir una Expresion de Infija a Postfija");
		printf("\n  2.Convertir una Expresion de Infija a Prefija");
		printf("\n  3.Salir del Menu");
		printf("\n ");
		printf("\n Ingrese su opcion: ");
		scanf("%d",&opcion);
		switch(opcion)
 		{
		case 1:
  			system("cls");
  			printf("\n Ingrese la expresion en notacion Infija (sin espacios): ");
  			scanf("%s",&infija);

            tope=-1;
            pos=-1;
            tamExpresion=strlen(infija);
            for(int i=0; i<tamExpresion ;i++)
            {
                simbolo=infija[i];
                if(simbolo=='(')
                {
                    tope=tope+1;
                    pila[tope]=simbolo;

                }
                else if(simbolo==')')
                {
                    while(pila[tope]!='(')
                    {
                        pos=pos+1;
                        epos[pos]=pila[tope];
                        tope=tope-1;

                    }
                    tope=tope-1;
                }
                else if((simbolo>='a')&&(simbolo<='z')||(simbolo>='A')&&(simbolo<='Z'))
                {
                    pos=pos+1;
                    epos[pos]=simbolo;

                }
                else
                {
                    while(tope>-1 && (prioridad(simbolo)<=prioridad(pila[tope])))  //mandamos a llamar la funcion de prioridad y le pasamos el simbolo para saber cual es
                    {
                        pos=pos+1;
                        epos[pos]=pila[tope];
                        tope=tope-1;
                    }
                    tope=tope+1;
                    pila[tope]=simbolo;
                }
            }

            while(tope>-1)
            {
                pos=pos+1;
                epos[pos]=pila[tope];
                tope=tope-1;
            }

            printf("La expresion en postfija es: ");

            for(int i=0;i<=pos;i++)
            {
                printf("%c",epos[i]);
            }

            getch();


		break;

		case 2:
			system("cls");
			printf("\n Ingrese la expresion en notacion Infija (sin espacios): ");
            scanf("%s",&infija);




            tope=-1;
            pos=-1;
            tamExpresion=strlen(infija);
            for(int i=tamExpresion-1; i>=0 ;i--)
            {
                simbolo=infija[i];
                if(simbolo==')')
                {
                    tope=tope+1;
                    pila[tope]=simbolo;

                }
                else if(simbolo=='(')
                {
                    while(pila[tope]!=')')
                    {
                        pos=pos+1;
                        epre[pos]=pila[tope];
                        tope=tope-1;

                    }
                    tope=tope-1;
                }
                else if((simbolo>='a')&&(simbolo<='z')||(simbolo>='A')&&(simbolo<='Z'))
                {
                    pos=pos+1;
                    epre[pos]=simbolo;

                }
                else
                {
                    while((prioridad(simbolo)<prioridad(pila[tope])))  //mandamos a llamar la funcion de prioridad y le pasamos el simbolo para saber cual es
                    {
                        pos=pos+1;
                        epre[pos]=pila[tope];
                        tope=tope-1;
                    }
                    tope=tope+1;
                    pila[tope]=simbolo;
                }
            }

            while(tope>-1)
            {
                pos=pos+1;
                epre[pos]=pila[tope];
                tope=tope-1;
            }

            printf("La expresion en prefija es: ");

            for(int i=pos;i>=pos;i--)
            {
                printf("%c",epre[i]);
            }

            getch();



		break;

		case 3:
		    printf("\n ");
            printf("Adios...");
            printf("\n ");

            break;


		default: printf("\n Por favor seleccione una opcion valida...");
		getch();
		break;
		}

	}while(opcion!=3);
	getch();
}






int prioridad(char simbolo)
{
    int prioridadSimbolo;
    switch(simbolo)
    {
        case '^': prioridadSimbolo = 3;
        break;

        case '/': prioridadSimbolo = 2;
        break;

        case '*': prioridadSimbolo = 2;
        break;

        case '-': prioridadSimbolo = 1;
        break;

        case '+': prioridadSimbolo = 1;
        break;

        case ')': prioridadSimbolo = 0;
        break;

        case '(': prioridadSimbolo = 0;
        break;

    }
}
