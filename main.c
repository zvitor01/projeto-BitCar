/*
*Autores: Iago Ribeiro Sales e José Vitor Pires Silveira Campos
*Programa: ENUNCIADO 6 - BitCar
*Data: 02/12/2025
*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// Tipos especiais (enum)
typedef enum {
    GASOLINA,
    ALCOOL,
    DIESEL,
    FLEX
} Combustivel;

typedef enum {
    PASSEIO,
    UTILITARIO
} TipoCarro;

//estrutura
struct cadastro
{
    int codigo;
    char marca[20];
    char modelo[20];
    int anoFabricacao;
    int anoModelo;
    Combustivel combustivel;
    TipoCarro tipo;
    float preco;
    char data[12];
} carro;

//declaração de variáveis
void gotoxy(int x, int y);
void bordas();

//função principal
int main()
{
    system("mode con:cols=80 lines=25");
    bordas();
    system("pause");
    return 0;
}

//funções
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void bordas()
{
    for (int x = 3; x < 79; x++)
    {
        gotoxy(x, 2);
        printf ("%c", 196);//borda horizontal superior
        gotoxy(x, 24);
        printf("%c", 196); //borda horizontal inferior
    }

    for (int y = 3; y < 24; y++)
    {
        gotoxy(2, 2);
        printf("%c", 218); //canto superior esquerdo
        gotoxy(79, 2);
        printf("%c", 191); //canto superior direito
        gotoxy(2, y);
        printf("%c", 179); //borda vertical do lado direito
        gotoxy(79, y);
        printf("%c", 179); //borda vertical do lado esquerdo
        gotoxy(2, 24);
        printf("%c", 192); //canto inferior esquerdo
        gotoxy(79, 24);
        printf("%c", 217); //canto inferior direito
    }
    printf("\n");
}
