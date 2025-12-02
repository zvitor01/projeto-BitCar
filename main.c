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
const char *combustivelStr[] = {
    "",            // posição 0 (não usada)
    "Gasolina",    // 1
    "Alcool",      // 2
    "Diesel",      // 3
    "Flex"         // 4
};

const char *tipoStr[] = {
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
    int ativo; // 1 = ativo e 0 = excluído 
}cadastro;

//declaração de funções
void gotoxy(int x, int y);
void bordas();
void cabecalho();
void telaCarregamento();
void telaLogin();
void menu();
void incluir();
int acharCodigo(int condigo);
void buscar();
void alterar();
void listar();
void listarPorCombustivel();
void excluir();
void gerarRelatorio();
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

void cabecalho()
{
    gotoxy(28, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
    gotoxy(28, 3);
    printf("%c          BitCar          %c",179,179);
    gotoxy(28, 4);
    printf("%c     Revenda de Carros    %c",179,179);
    gotoxy(28, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    gotoxy(28, 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
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

        Sleep(40);
    }

    gotoxy(80/2 - 15, 18);
    printf("Sistema carregado com sucesso!");

    gotoxy(4, 23);
    system("pause");
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
            gotoxy(4, 23);
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
        cabecalho();
        gotoxy(35, 6);
        printf("Menu principal");
        

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
                alterar();
                break;

            case '4':
                listar();
                break;

            case '5':
                excluir();
                break;

            case '6':
                gerarRelatorio();
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
    cabecalho();
	gotoxy(38, 6);
	printf("Incluir");
	
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

        time_t agora = time(NULL);
        struct tm *hoje = localtime(&agora);
        strftime(carro.data, sizeof(carro.data), "%d/%m/%Y", hoje); //registra a data da inclusão

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

        carro.ativo = 1; //ativa o carro

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

int acharCodigo(int codigo)
{
    cadastro carro;
    FILE *arq;

    //abre o arquivo binario para leitura
    arq = fopen("carros.dat", "rb");

    if(arq)
    {
        while(fread(&carro, sizeof(cadastro), 1, arq))
        {
            if(codigo == carro.codigo && carro.ativo == 1)
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
                gotoxy(4, 18);
                printf("Data do cadastro: %s", carro.data);

                fclose(arq);
                return 1;
            }         
        }

        gotoxy(4, 11);
        printf("Carro nao encontrado!");
        fclose(arq);
        return 0;
    }
    else
    {
        gotoxy(26, 13);
        printf("Nao foi possivel abrir o arquivo.");
        return 0;
    }
}

void buscar()
{
    int codigo;
    int c; //usado para limpar o buffer

    system("cls");
    bordas();
    cabecalho();
	gotoxy(39, 6);
	printf("Buscar");

    gotoxy(4, 9);
    printf("Digite o codigo do carro que deseja buscar: ");
    scanf("%d", &codigo);
    while ((c = getchar()) != '\n' && c != EOF); // flush

    acharCodigo(codigo);

    gotoxy(4, 23);
    system("pause");
}

void alterar()
{   
    FILE *arq;
    cadastro carro;
    int codigo;
    char resp;
    int c; //usado para limpar o buffer

    system("cls");
    bordas();
    cabecalho();
	gotoxy(38, 6);
	printf("Alterar");
	
    gotoxy(4, 9);
    printf("Digite o codigo do carro que deseja alterar: ");
    scanf("%d", &codigo);
    while ((c = getchar()) != '\n' && c != EOF); // flush

    if(acharCodigo(codigo))
    {
        gotoxy(4, 23);
        printf("Deseja alterar os dados deste carro? (S/N) ");
        resp = getchar();
        while ((c = getchar()) != '\n' && c != EOF); // flush

        if(resp == 's' || resp == 'S')
        {
            arq = fopen("carros.dat", "rb+");

            if(arq)
            {
                while(fread(&carro, sizeof(cadastro), 1, arq))
                {
                    if(carro.codigo == codigo)
                    {
                        system("cls");
                        bordas();
                        cabecalho();
                        gotoxy(38, 6);
                        printf("Alterar");
                    
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

                        time_t agora = time(NULL);
                        struct tm *hoje = localtime(&agora);
                        strftime(carro.data, sizeof(carro.data), "%d/%m/%Y", hoje); //registra a data da alteração

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

                        fseek(arq, -(long)sizeof(cadastro), SEEK_CUR); //volta o ponteiro para escrever em cima do antigo
                        fwrite(&carro, sizeof(cadastro), 1, arq); //escreve no arquivo

                        gotoxy(4, 18);
                        printf("Dados alterados com sucesso!\n");
                        fclose(arq);

                        gotoxy(4, 23);
                        system("pause");
                        return;
                    }
                }
            }
            else
            {
                gotoxy(26, 13);
                printf("Nao foi possivel abrir o arquivo.");
                gotoxy(4,23);
                system("pause");
                return;
            }
        }
        else
        {
            return;
        }
    }

    gotoxy(4, 23);
    system("pause");
}

void listar()
{
    FILE *arq;
    cadastro carro;
    int linha = 12; //começa a listar a partir da linha 12
    int cont = 0;   //contador para saber se o arquivo estava vazio
    char opcao;

    do
    { 
        system("cls");
        bordas();
        cabecalho();
        gotoxy(39, 6);
        printf("Listar");

        gotoxy(28, 9);
        printf("[1] Listagem de todos os carros");
        gotoxy(28, 10);
        printf("[2] Listagem por combustivel");

        gotoxy(28, 17);
        printf("Escolha a opcao desejada: ");
        opcao = getche();
    }while(opcao < '1' || opcao > '2');
    
    if(opcao == '2')
    {
        listarPorCombustivel();
        return;
    }

    system("cls");
    bordas();
    cabecalho();
	gotoxy(39, 6);
	printf("Listar");

    arq = fopen("carros.dat", "rb");

    if(arq)
    {
        // Títulos das Colunas
        gotoxy(3, 9); 
        printf("COD");
        gotoxy(8, 9); 
        printf("MARCA");
        gotoxy(24, 9); 
        printf("MODELO");
        gotoxy(40, 9); 
        printf("ANO/MOD");
        gotoxy(51, 9); 
        printf("PRECO (R$)");
        gotoxy(65, 9); 
        printf("TIPO");

        // Linha divisória
        gotoxy(3, 10);
        for(int i=0; i<74; i++) 
        {
            printf("%c", 196);
        }

        while(fread(&carro, sizeof(cadastro), 1, arq))
        {
            if(carro.ativo == 1)
            {
                cont++; // Achamos pelo menos um carro

                // Imprime os dados nas colunas certas
                gotoxy(3, linha);  
                printf("%d", carro.codigo); 
                gotoxy(8, linha);  
                printf("%.15s", carro.marca); // %.15s corta se for muito grande
                gotoxy(24, linha); 
                printf("%.15s", carro.modelo);
                gotoxy(40, linha); 
                printf("%d/%d", carro.anoFabricacao, carro.anoModelo);
                gotoxy(51, linha); 
                printf("%.2f", carro.preco);
                gotoxy(65, linha); 
                printf("%s", tipoStr[carro.tipo]);

                linha++; // Vai para a próxima linha da tela

                // Se chegar na linha 22, a tela está cheia. 
                if(linha > 22)
                {
                    gotoxy(4, 23);
                    printf("Pressione qualquer tecla para ver a proxima pagina...");
                    getch();
                    
                    // Limpa e redesenha o cabeçalho para a nova página
                    system("cls");
                    bordas();
                    cabecalho();
                    gotoxy(39, 6);
                    printf("Listar");
                    
                    // Redesenha colunas
                    gotoxy(3, 9);
                    printf("COD");
                    gotoxy(8, 9);
                    printf("MARCA");
                    gotoxy(24, 9);
                    printf("MODELO");
                    gotoxy(40, 9);
                    printf("ANO/MOD");
                    gotoxy(51, 9);
                    printf("PRECO (R$)");
                    gotoxy(65, 9);
                    printf("TIPO");
                    gotoxy(3, 10);
                    
                    for(int i=0; i<74; i++)
                    {
                        printf("%c", 196);
                    }

                    linha = 12; // Reseta a linha para o topo da tabela
                }       
            }
        }

        if(cont == 0)
        {
            gotoxy(20, 13);
            printf("Nenhum carro cadastrado no sistema.");
        }
        else
        {
            gotoxy(3, linha + 1);
            printf("Fim da listagem. Total: %d carros.", cont);
        }

        fclose(arq);
        gotoxy(4,23);
        system("pause");
        return;
    }
    else
    {
        gotoxy(26, 13);
        printf("Nao foi possivel abrir o arquivo.");
        gotoxy(4,23);
        system("pause");
        return;
    }
}

void listarPorCombustivel()
{
    cadastro carro;
    FILE *arq;
    char opcao;
    int linha = 12;
    int cont = 0;
    int filtro; //variável auxiliar para a comparação

    do
    { 
        system("cls");
        bordas();
        cabecalho();
        gotoxy(39, 6);
        printf("Listar");

        gotoxy(28, 9);
        printf("[1] Gasolina");
        gotoxy(28, 10);
        printf("[2] Alcool");
        gotoxy(28, 11);
        printf("[3] Diesel");
        gotoxy(28, 12);
        printf("[4] Flex");

        gotoxy(28, 17);
        printf("Escolha a opcao desejada: ");
        opcao = getche();
    }while(opcao < '1' || opcao > '4');

    filtro = opcao - '0'; //converte o char '1' para int 1

    system("cls");
    bordas();
    cabecalho();
	gotoxy(39, 6);
	printf("Listar");

    arq = fopen("carros.dat", "rb");

    if(arq)
    {

        // Títulos das Colunas
        gotoxy(3, 9); 
        printf("COD");
        gotoxy(8, 9); 
        printf("MARCA");
        gotoxy(24, 9); 
        printf("MODELO");
        gotoxy(40, 9); 
        printf("ANO/MOD");
        gotoxy(51, 9); 
        printf("PRECO (R$)");
        gotoxy(65, 9); 
        printf("TIPO");

        // Linha divisória
        gotoxy(3, 10);
        for(int i=0; i<74; i++) 
        {
            printf("%c", 196);
        }

        while(fread(&carro, sizeof(cadastro), 1, arq))
        {
            if(carro.combustivel == filtro && carro.ativo == 1)
            {
                cont++; // Achamos pelo menos um carro

                // Imprime os dados nas colunas certas
                gotoxy(3, linha);  
                printf("%d", carro.codigo);
                gotoxy(8, linha);  
                printf("%.15s", carro.marca); // %.15s corta se for muito grande
                gotoxy(24, linha); 
                printf("%.15s", carro.modelo);
                gotoxy(40, linha); 
                printf("%d/%d", carro.anoFabricacao, carro.anoModelo);
                gotoxy(51, linha); 
                printf("%.2f", carro.preco);
                gotoxy(65, linha); 
                printf("%s", tipoStr[carro.tipo]);

                linha++; // Vai para a próxima linha da tela

                // Se chegar na linha 22, a tela está cheia. 
                if(linha > 22)
                {
                    gotoxy(4, 23);
                    printf("Pressione qualquer tecla para ver a proxima pagina...");
                    getch();
                    
                    // Limpa e redesenha o cabeçalho para a nova página
                    system("cls");
                    bordas();
                    cabecalho();
                    gotoxy(39, 6);
                    printf("Listar");
                    
                    // Redesenha colunas
                    gotoxy(3, 9);
                    printf("COD");
                    gotoxy(8, 9);
                    printf("MARCA");
                    gotoxy(24, 9);
                    printf("MODELO");
                    gotoxy(40, 9);
                    printf("ANO/MOD");
                    gotoxy(51, 9);
                    printf("PRECO (R$)");
                    gotoxy(65, 9);
                    printf("TIPO");
                    gotoxy(3, 10);
                    
                    for(int i=0; i<74; i++)
                    {
                        printf("%c", 196);
                    }

                    linha = 12; // Reseta a linha para o topo da tabela
                }
            }
        }

        if(cont == 0)
        {
            gotoxy(20, 13);
            printf("Nenhum carro com esse combustivel no sistema.");
        }
        else
        {
            gotoxy(3, linha + 1);
            printf("Fim da listagem. Total: %d carros.", cont);
        }

        fclose(arq);
        gotoxy(4, 23);
        system("pause");
        return;
    }
    else
    {
        gotoxy(26, 13);
        printf("Nao foi possivel abrir o arquivo.");
        gotoxy(4, 23);
        system("pause");
        return;
    }
}

void excluir()
{
    FILE *arq;
    cadastro carro;
    int codigo;
    char resp;
    int c; //usado para limpar o buffer

    system("cls");
    bordas();
    cabecalho();
    gotoxy(38, 6);
    printf("Excluir");

    gotoxy(4, 9);
    printf("Digite o codigo do carro para excluir: ");
    scanf("%d", &codigo);
    while ((c = getchar()) != '\n' && c != EOF); // Flush

    // Verifica se existe (e se está ativo)
    if(acharCodigo(codigo))
    {
        gotoxy(4, 23);
        printf("Tem certeza que deseja excluir este carro? (S/N): ");
        resp = getchar();
        while ((c = getchar()) != '\n' && c != EOF); // flush

        if(resp == 's' || resp == 'S')
        {
            // Abre para Leitura e Escrita
            arq = fopen("carros.dat", "rb+");

            if(arq)
            {
                while(fread(&carro, sizeof(cadastro), 1, arq))
                {
                    if(carro.codigo == codigo)
                    {
                        system("cls");
                        bordas();
                        cabecalho();
                        gotoxy(38, 6);
                        printf("Excluir");

                        carro.ativo = 0; // desativa o carro

                        // Volta o cursor e grava a alteração
                        fseek(arq, -(long)sizeof(cadastro), SEEK_CUR);
                        fwrite(&carro, sizeof(cadastro), 1, arq);
                        
                        break; // Sai do loop
                    }
                }
                fclose(arq);
                gotoxy(28, 13);
                printf("Carro excluido com sucesso!");
            }
            else
            {
                gotoxy(26, 13);
                printf("Nao foi possivel abrir o arquivo.");
                gotoxy(4, 23);
                system("pause");
                return;
            }
        }
        else
        {
            return;
        }
    }
    // Se acharCodigo for 0, ele já avisa que não encontrou

    gotoxy(4, 23);
    system("pause");
}

void gerarRelatorio()
{
    cadastro carro;
    FILE *arq, *temp;
    
    // Variáveis para Estatísticas
    double somaPrecos = 0;
    double maiorPreco = 0;
    double menorPreco = 0;
    char modeloMaisCaro[20] = "";
    char modeloMaisBarato[20] = "";
    int qtdTotal = 0;
    int qtdGasolina = 0, qtdAlcool = 0, qtdDiesel = 0, qtdFlex = 0;
    int primeiro = 1; // Flag para inicializar o menor preço

    system("cls");
    bordas();
    cabecalho();
    gotoxy(35, 6);
    printf("Gerar Relatorio");

    arq = fopen("carros.dat", "rb");
    if(arq == NULL)
    {
        gotoxy(28, 13);
        printf("Nenhum dado encontrado.");
        gotoxy(4, 23);
        system("pause");
        return;
    }

    temp = fopen("relatorio_completo.csv", "w+");
    if(temp == NULL)
    {
        fclose(arq);
        gotoxy(20, 13);
        printf("Erro! Feche o arquivo CSV antes de continuar.");
        gotoxy(4, 23);
        system("pause");
        return;
    }

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char dataHoje[12];
    
    // Formata a data como DD/MM/AAAA
    strftime(dataHoje, sizeof(dataHoje), "%d/%m/%Y", tm);

    // Cabeçalho das Colunas
    fputs("RELATORIO GERAL DE ESTOQUE - BITCAR\n", temp);
    fprintf(temp, "Data de Geracao:;%s\n\n", dataHoje);
    fputs("CODIGO;MARCA;MODELO;ANO FAB;ANO MOD;COMBUSTIVEL;TIPO;PRECO;DATA CAD;STATUS\n", temp);

    while(fread(&carro, sizeof(cadastro), 1, arq))
    {
        // Só processa se não estiver excluído (se você estiver usando exclusão lógica)
        if(carro.ativo == 1) 
        {
            // Grava a linha do carro
            fprintf(temp, "%d;%s;%s;%d;%d;%s;%s;%.2lf;%s;Ativo\n", 
                carro.codigo, carro.marca, carro.modelo, 
                carro.anoFabricacao, carro.anoModelo, 
                combustivelStr[carro.combustivel], tipoStr[carro.tipo], 
                carro.preco, carro.data);

            // Cálculos estatísticos
            somaPrecos += carro.preco;
            qtdTotal++;

            // Contagem por combustível
            if(carro.combustivel == 1) 
                qtdGasolina++;
            else if(carro.combustivel == 2) 
                qtdAlcool++;
            else if(carro.combustivel == 3) 
                qtdDiesel++;
            else if(carro.combustivel == 4) 
                qtdFlex++;

            // Verifica Maior e Menor Preço
            if(primeiro)
            {
                maiorPreco = carro.preco;
                menorPreco = carro.preco;
                strcpy(modeloMaisCaro, carro.modelo);
                strcpy(modeloMaisBarato, carro.modelo);
                primeiro = 0;
            }
            else
            {
                if(carro.preco > maiorPreco)
                {
                    maiorPreco = carro.preco;
                    strcpy(modeloMaisCaro, carro.modelo);
                }
                if(carro.preco < menorPreco)
                {
                    menorPreco = carro.preco;
                    strcpy(modeloMaisBarato, carro.modelo);
                }
            }
        }
    }

    // Área de Estatísticas (Dashboard no rodapé)
    fputs("\n\n", temp); // Pula 2 linhas
    fputs(";;;RESUMO FINANCEIRO;;;;;RESUMO DE FROTA\n", temp);
    
    // Média e Totais
    double media = (qtdTotal > 0) ? (somaPrecos / qtdTotal) : 0.0;

    fprintf(temp, ";;;Valor Total em Estoque:;R$ %.2lf;;;;Total de Carros:;%d\n", somaPrecos, qtdTotal);
    fprintf(temp, ";;;Media de Preco:;R$ %.2lf;;;;Gasolina:;%d\n", media, qtdGasolina);
    fprintf(temp, ";;;Carro Mais Caro:;%s (R$ %.2lf);;;;Alcool:;%d\n", modeloMaisCaro, maiorPreco, qtdAlcool);
    fprintf(temp, ";;;Carro Mais Barato:;%s (R$ %.2lf);;;;Diesel:;%d\n", modeloMaisBarato, menorPreco, qtdDiesel);
    fprintf(temp, ";;;;;;;;Flex:;%d\n", qtdFlex);

    fclose(arq);
    fclose(temp);

    gotoxy(20, 13);
    printf("Relatorio 'relatorio_completo.csv' gerado!");
    gotoxy(16, 14);
    printf("Confira os dados estatisticos no final da planilha.");

    gotoxy(4, 23);
    system("pause");
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
