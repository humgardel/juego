# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <time.h>
//# include <windows.h>

#define SIZE_Nave 10
#define SIZE_Tierra 12
/*
void gotoxy(int x, int y) { // compiladores de borlan.
	HANDLE hCon;//identificador
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;//coordenadas
	dwPos.X = x;//parametro
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);//genero para mover, identificador consola de ejecucion HANDLE

}
void pintar_limites() {
	for (int i = 2; i < 78; i++) {
		gotoxy(i, 3); printf("%c", 205);//lineas de arriba
		gotoxy(i, 33); printf("%c", 205);//lineas de abajo

	}
	for (int i = 4; i < 33; i++) {
		gotoxy(2, i); printf("%c", 186);//lineas de izquierda
		gotoxy(77, i); printf("%c", 186);//lineas de derecha
	}

	gotoxy(2, 3); printf("%c", 201);//esquina superior izq
	gotoxy(2, 33); printf("%c", 200);//esquina inferior izq
	gotoxy(77, 3); printf("%c", 187);//esquina superior dere
	gotoxy(77, 33); printf("%c", 188);//esquina inferior dere
}
*/
void generarRandom(int[], int);
void mostrarVector(int[], int);
void generarRandom1(int[], int);
void mostrarVector1(int[], int);
void disparoTierra();
void disparoNave();

void main() {
       //	pintar_limites();
	int opc;
	srand(time(NULL));
	int barrera_nave[SIZE_Nave] = { 0 };
	int barrera_tierra[SIZE_Tierra] = { 0 };
	char empiezaTierra;
	
		printf("\t\t\t\t **** Defensa Digital contra Ataque Alienigena **** \n\n\n");
		printf("Estudiante: Jostin Piedra \n");
		printf("Fecha: 20/10/15 \n\n");
		printf("\t\t Menu de Opciones: \n\n");
		printf("1. Comenzar juego: \n");
		printf("2. Salir del juego: \n");
		scanf("%d", &opc);
		switch (opc)
		{
		case 1:
			system("cls");
			int op;
			do
			{
				printf("\t Menu de Opciones: \n\n");
				printf("1. Activar Defensas. \n");
				printf("2. Empezar Combate. \n");
				printf("3. Mostrar Resumen Final. \n");
				printf("4. Salir. \n");
				scanf("%d", &op);

				switch (op)
				{
				case 1:
					system("cls");
					generarRandom(barrera_nave, SIZE_Nave);
					mostrarVector(barrera_nave, SIZE_Nave);
					generarRandom1(barrera_tierra, SIZE_Tierra);
					mostrarVector1(barrera_tierra, SIZE_Tierra);
					printf("\n");
					getch();
					break;
				case 2:
					system("cls");
					/*
					Los disparos de la tierra son #3y12(listo)
					Los disparos de la nave son #2y18(listo)
					El planeta Tierra dispara primero(D)(listo)
					Los disparos de la nave son automaticos dsps de la tierra(listo)
					En cada disparo si acierta, contenido de celda cambiar a 0
					la batalla termina cuando:
					se completan 20 disparos(tregua diplomatica), antes de los 20 intentos el 75% de una de las defensas esta en 0
					se debe mostrar por pantalla el progreso de la batalla
					*/
					empiezaTierra = 'D';
					printf("Empezando combate...\n\n");
					printf("Para empezar porfavor presione la letra: D \n");
					scanf(" %c", &empiezaTierra);
					printf("Planeta Tierra disparando...");
					printf("\n");
					disparoTierra();
					printf("\n");
					printf("Empezando Contraataque...\n\n");
					printf("Nave Nodriza disparando...");
					printf("\n");
					disparoNave();
					getch();
					break;
				case 3:
					system("cls");
					break;
				case 4:
					system("cls");
					break;
				default:
					system("cls");
					break;
				}
			} while (op < 5);
		default:
			exit(1);
			break;
		}
}
void generarRandom(int barrera_nave[], int size_nave)

{
	int i, j, num, dupl;
	//printf("Numeros aleatorios: \n");
	for (i = 0; i < size_nave; i++) {
		num = 3 + rand() % size_nave;
		dupl = 0;
		//printf("%-4d", num);<--Espacios
		for (j = 0; j <= i; j++) {
			if (num == barrera_nave[j]) {
				dupl = 1;
				break;
			}
		}
		if (dupl == 1)
			i--;
		else
			barrera_nave[i] = num;
	}
}
void mostrarVector(int barrera_nave[], int size_nave)
{
	int i;

	printf("\n\nNave Nodriza: \n");
	printf("-Barrera Activada...\nLista para combatir! \n\n");
	for (i = 0; i < size_nave; i++)
		printf("%d\n", barrera_nave[i]);
}
void generarRandom1(int barrera_tierra[], int size_tierra)
{
	int i, j, num, dupl;
	//printf("numeros aleatorios: \n");
	for (i = 0; i < size_tierra; i++) {
		num = 2 + rand() % size_tierra;
		dupl = 0;
		//printf("%-4d", num); <--espacios a imprimir
		for (j = 0; j <= i; j++) {
			if (num == barrera_tierra[j]) {
				dupl = 1;
				break;
			}
		}
		if (dupl == 1)
			i--;
		else
			barrera_tierra[i] = num;
	}
}
void mostrarVector1(int barrera_tierra[], int size_tierra)
{
	int i;

	printf("\n\nPlaneta Tierra: \n");
	printf("-Barrera Activada...\nLista para combatir! \n\n");
	for (i = 0; i < size_tierra; i++)
		printf("%d\n", barrera_tierra[i]);
}
void disparoTierra() {
	int num;
	for (int i = 0; i < 1; i++) {
		num = 3 + rand() % SIZE_Nave;
		printf("%d", num);
	}
}
void disparoNave() {
	int num;
	for (int i = 0; i < 1; i++) {
		num = 2 + rand() % SIZE_Tierra;
		printf("%d", num);
		}
}