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
#include <windows.h>

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

//declaração de funções
void gotoxy(int x, int y);
void bordas();
void telaCarregamento();
void telaLogin();
void menu();

//função principal
int main()
{
    system("mode con:cols=80 lines=25");
    telaCarregamento();
    telaLogin();

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
}

void telaCarregamento()
{
    system("cls");
    bordas();

    gotoxy(80/2 - 8, 5);
    printf("PROJETO BITCAR"); //título centralizado

    gotoxy(80/2 - 30, 7);
    printf("Autores: Iago Ribeiro Sales e Jose Vitor Pires Silveira Campos"); //autores centralizados

    gotoxy(80/2 - 10, 10);
    printf("Carregando sistema..."); //texto de carregamento

    int tam = 40;
    int barraX = 80/2 - (tam/2); //barra centralizada

    for (int i = 0; i <= tam; i++) //desenha a barra
    {
        gotoxy(barraX, 13);

        printf("[");

        for (int j = 0; j < i; j++)
            printf("%c", 219);

        for (int j = i; j < tam; j++)
            printf(" ");

        printf("]");

        gotoxy(80/2 - 3, 15);
        printf("%d%%   ", (i * 100) / tam); //porcentagem

        Sleep(80);
    }

    gotoxy(80/2 - 15, 18);
    printf("Sistema carregado com sucesso!");

    Sleep(900);
}

void telaLogin()
{
    char login[10] = "admin";
    char senha[10] = "123";
    char loginUser[10] = {0};
    char senhaUser[10] = {0};

    system("cls");
	bordas();
	gotoxy(28, 2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28, 3);
	printf("%c          BitCar          %c",179,179);
    gotoxy(28, 4);
	printf("%c     Revenda de Carros    %c",179,179);
	gotoxy(28, 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(35, 6);
	printf("Tela de Login");
	gotoxy(28, 7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);

    gotoxy(28, 11);
    printf("Digite o usuario: ");
    gotoxy(28, 12);
    printf("Digite a senha..: ");

    gotoxy(46, 11);
    fgets(loginUser, 10, stdin);
    strtok(loginUser, "\n");

    gotoxy(46, 12);
    fgets(senhaUser, 10, stdin);
    strtok(senhaUser, "\n");

    if(strcmp(login, loginUser) == 0 && strcmp(senha, senhaUser) == 0)
    {
        menu();
    }
    else
    {
        gotoxy(25, 15);
        printf("Usuario e/ou senha invalidos");
        Sleep(1200);
        telaLogin();
    }
}

void menu()
{
    system("cls");
	bordas();

	char opcao;

	gotoxy(28, 2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28, 3);
	printf("%c          BitCar          %c",179,179);
    gotoxy(28, 4);
	printf("%c     Revenda de Carros    %c",179,179);
	gotoxy(28, 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(35, 6);
	printf("Menu principal");
	gotoxy(28, 7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);

    gotoxy(28, 9);
    printf("[1] Incluir");
    gotoxy(28, 10);
    printf("[2] Buscar");
    gotoxy(28, 11);
    printf("[3] Alterar");
    gotoxy(28, 12);
    printf("[4] Listar");
    gotoxy(28, 13);
    printf("[5] Excluir");
    gotoxy(28, 14);
    printf("[6] Gerar relatorio");
    gotoxy(28, 15);
    printf("[7] Sair");


}
