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
typedef enum 
{
    gasolina = 1,
    alcool,
    diesel,
    flex
}Combustivel;

typedef enum 
{
    passeio = 1,
    utilitario
}TipoCarro;

// Conversão dos enums para texto
char *combustivelStr[] = {
    "",            // posição 0 (não usada)
    "Gasolina",    // 1
    "Alcool",      // 2
    "Diesel",      // 3
    "Flex"         // 4
};

char *tipoStr[] = {
    "",            // posição 0 (não usada)
    "Passeio",     // 1
    "Utilitario"   // 2
};

//estrutura
typedef struct
{
    int codigo;
    char marca[20];
    char modelo[20];
    int anoFabricacao;
    int anoModelo;
    Combustivel combustivel;
    TipoCarro tipo;
    double preco;
    char data[12];
}cadastro;

//declaração de funções
void gotoxy(int x, int y);
void bordas();
void telaCarregamento();
void telaLogin();
void menu();
void incluir();
int buscar();
void sair();

//função principal
int main()
{
    system("mode con:cols=82 lines=27");
    telaCarregamento();
    telaLogin();
    menu();

    return 0;
}

//funções
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void bordas()
{
    // cantos
    gotoxy(2,2);
    printf("%c", 218);
    gotoxy(79,2);
    printf("%c", 191);
    gotoxy(2,24);
    printf("%c", 192);
    gotoxy(79,24);
    printf("%c", 217);

    // horizontais
    for (int x = 3; x < 79; x++)
    {
        gotoxy(x, 2); printf ("%c", 196);
        gotoxy(x, 24); printf ("%c", 196);
    }

    // verticais
    for (int y = 3; y < 24; y++)
    {
        gotoxy(2, y); printf("%c", 179);
        gotoxy(79, y); printf("%c", 179);
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

    Sleep(1500);
}

void telaLogin()
{
    char login[10] = "admin";
    char senha[10] = "123";
    char loginUser[10] = {0};
    char senhaUser[10] = {0};

    int logado = 0;
    int i = 0; 
    char c;    

    do // Loop principal do Login (fica aqui até acertar a senha)
    {
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
        gotoxy(28, 11);
        printf("Digite o usuario: ");
        gotoxy(28, 12);
        printf("Digite a senha..: ");

        gotoxy(46, 11);
        fgets(loginUser, 10, stdin);
        loginUser[strcspn(loginUser,"\n")] = 0;

        gotoxy(46, 12);
        i = 0;
        
        do 
        {
            c = getch(); // Lê a tecla

            if (c == 8) // Backspace
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if (c != 13) // Se não for Enter, é um caractere da senha
            {
                if (i < 9) // Limite de tamanho
                {
                    senhaUser[i] = c;
                    printf("*");
                    i++;
                }
            }
            
        } while (c != 13); // Repete enquanto a tecla NÃO for Enter (código 13)
        
        // Finaliza a string manualmente depois do loop
        senhaUser[i] = '\0'; 

        if(strcmp(login, loginUser) == 0 && strcmp(senha, senhaUser) == 0)
        {
            logado = 1;
        }
        else
        {
            gotoxy(25, 15);
            printf("Usuario e/ou senha invalidos");
            system("pause");
        }
    } while(logado == 0);
}

void menu()
{
    char opcao;

    do
    {   
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

        gotoxy(28, 17);
        printf("Escolha a opcao desejada: ");
        opcao = getche(); //função da biblioteca conio.h que lê o caractere digitado pelo usuário 

        switch(opcao)
        {
            case '1':
                incluir();
                break;

            case '2':
                buscar();
                break;

            case '3':
                
                break;

            case '4':
                
                break;

            case '5':
                
                break;

            case '6':
                
                break;

            case '7':
                sair();
                break;
        }
    }while(opcao != '7');
}

void incluir()
{
    cadastro carro;
    FILE *arq;
    int codigo = 1;
    int c; //usado para limpar o buffer

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
	gotoxy(38, 6);
	printf("Incluir");
	gotoxy(28, 7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);

    //abre arquivo binario ou cria se nao existir
    arq = fopen("carros.dat", "ab+");

    if(arq)
    {
        rewind(arq);

        while(fread(&carro, sizeof(cadastro), 1, arq))
        {
            if(carro.codigo >= codigo)
            {
                codigo = carro.codigo + 1;
            }
        }
        carro.codigo = codigo;

        gotoxy(4, 9);
        printf("Marca: ");
        gotoxy(4, 10);
        printf("Modelo: ");
        gotoxy(4, 11);
        printf("Ano de fabricacao: ");
        gotoxy(4, 12);
        printf("Ano do modelo: ");
        gotoxy(4, 13);
        printf("Combustivel (1 = Gasolina, 2 = Alcool, 3 = Diesel, 4 = Flex): ");
        gotoxy(4, 14);
        printf("Tipo (1 = Passeio, 2 = Utilitario): ");
        gotoxy(4, 15);
        printf("Preco de venda: ");
        _strdate(carro.data);

        gotoxy(11, 9);
        fgets(carro.marca, 20, stdin);
        carro.marca[strcspn(carro.marca, "\n")] = 0;

        gotoxy(12, 10);
        fgets(carro.modelo, 20, stdin);
        carro.modelo[strcspn(carro.modelo, "\n")] = 0;

        gotoxy(23, 11);
        scanf("%d", &carro.anoFabricacao);
        while ((c = getchar()) != '\n' && c != EOF); // flush

        gotoxy(19, 12);
        scanf("%d", &carro.anoModelo);
        while ((c = getchar()) != '\n' && c != EOF); // flush

        do 
        {
            gotoxy(66, 13);
            scanf("%d", &carro.combustivel);
            while ((c = getchar()) != '\n' && c != EOF); // flush
        } while (carro.combustivel < gasolina || carro.combustivel > flex);

        do 
        {
            gotoxy(40, 14);
            scanf("%d", &carro.tipo);
            while ((c = getchar()) != '\n' && c != EOF); // flush
        } while (carro.tipo < passeio || carro.tipo > utilitario);

        gotoxy(20, 15);
        scanf("%lf", &carro.preco);
        while ((c = getchar()) != '\n' && c != EOF); // flush

        //gravar os dados no arquivo
        fwrite(&carro, sizeof(cadastro), 1, arq);

        gotoxy(4, 18);
        printf("Dados gravados com sucesso!\n");
    }
    else
    {
        gotoxy(26, 13);
        printf("Nao foi possivel abrir o arquivo.");
        gotoxy(4,23);
        system("pause");
        return;
    }

    //fechar o arquivo
    fclose(arq);
    gotoxy(4,23);
    system("pause");
}

int buscar()
{
    cadastro carro;
    FILE *arq;
    int busca;
    int c; //usado para limpar o buffer

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
	gotoxy(39, 6);
	printf("Buscar");
	gotoxy(28, 7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);

    //abre o arquivo binario para leitura
    arq = fopen("carros.dat", "rb");

    if(arq)
    {
        gotoxy(4, 9);
        printf("Digite o codigo do carro que deseja buscar: ");
        gotoxy(48, 9);
        scanf("%d", &busca);
        while ((c = getchar()) != '\n' && c != EOF); 

        while(fread(&carro, sizeof(cadastro), 1, arq))
        {
            if(busca == carro.codigo)
            {
                gotoxy(4, 11);
                printf("Marca: %s", carro.marca);
                gotoxy(4,12);
                printf("Modelo: %s", carro.modelo);
                gotoxy(4, 13);
                printf("Ano de fabricacao: %d", carro.anoFabricacao);
                gotoxy(4, 14);
                printf("Ano do modelo: %d", carro.anoModelo);
                gotoxy(4, 15);
                printf("Combustivel: %s", combustivelStr[carro.combustivel]);
                gotoxy(4,16);
                printf("Tipo: %s", tipoStr[carro.tipo]);
                gotoxy(4, 17);
                printf("Preco: %.2lf", carro.preco);

                fclose(arq);
                gotoxy(4, 23);
                system("pause");
                return 1;
            }         
        }

        gotoxy(4, 11);
        printf("Carro nao encontrado!");

        fclose(arq);
        gotoxy(4, 23);
        system("pause");
        return 0;
    }
    else
    {
        gotoxy(26, 13);
        printf("Nao foi possivel abrir o arquivo.");
        gotoxy(4,23);
        system("pause");
        return 0;
    }
}

void sair()
{
    system("cls");
    bordas();
    gotoxy(25, 12);
    printf("Obrigado por usar nosso sistema!");
    gotoxy(4, 23);
    printf("Pressione qualquer tecla para sair...");
    getch(); //espera 1 tecla sem mostrar nada
    exit(0);   
}
