#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

// Criando a estrutura que arazenará os cadastros realizados.
typedef struct {
    char nome[30];
    int idade;
    float salario;
    char sexo;
} cadastro;

// Função que permite navegar entre as posições do console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Função que limpa a tela anterior, e reescreve as estruturas da interface
void construirTela() {

    system("cls");

    // Comando de repetição que cria as linhas da interface
    for (int i = 1; i < 90; i++) {
        gotoxy(i, 1);
        printf("=");
        gotoxy(i, 3);
        printf("-");
        gotoxy(i, 23);
        printf("-");
        gotoxy(i, 25);
        printf("=");
    }
    // Comando de repetição que cria as colunas da interface
    for (int i = 1; i < 26; i++) {
        gotoxy(1, i);
        printf("|");
        gotoxy(90, i);
        printf("|");
    }
    // Criando uma posição de saída no console
    gotoxy(2, 24);
    printf("SAIDA:");
}

// Função que leva o cursor do console à posição de saida da interface
void posicaoConsoleSaida() {

    gotoxy(10, 24);
    printf("                                                                         ");
    gotoxy(10, 24);

}

// Função que leva o cursor do console à posição do título da interface
void posicaoConsoleTitulo() {

    gotoxy(3, 2);
    printf("                                                                            ");
    gotoxy(3, 2);

}

int main() {

    int continuarCadastro;
    int i = 0;
    cadastro log_cadastro[10]; // variável que armazenará os cadastros.

    while (1) {
        
        construirTela();
        posicaoConsoleTitulo();
        printf("CADASTRO DE PESSOA");

        // Campos do cadastro
        gotoxy(3, 5);
        printf("Digite o nome......:");
        gotoxy(3, 7);
        printf("Digite a idade.....:");
        gotoxy(3, 9);
        printf("Digite o salario...:");
        gotoxy(3, 11);
        printf("Digite o seu sexo..:");

        // Lendo o nome
        gotoxy(24, 5);
        scanf("%s", log_cadastro[i].nome);
        getchar();

        // Lendo a idade, e permitindo que apenas as pessoas entre 18 e 120 anos façam o cadastro
        while (1) {
            gotoxy(24, 7);
            printf("                         ");
            gotoxy(24, 7);
            scanf("%d", &log_cadastro[i].idade);

            if (log_cadastro[i].idade < 18 || log_cadastro[i].idade > 120) {
                posicaoConsoleSaida();
                printf("Digite uma idade valida! Acima de 18 anos");
                getch();
                posicaoConsoleSaida();
            } else {
                break;
            }
        }
        
        // Lendo o salario, e permitindo que apenas salarios positivos sejam inseridos
        while (1) {
            gotoxy(24, 9);
            printf("                         ");
            gotoxy(24, 9);
            scanf("%f", &log_cadastro[i].salario);

            if (log_cadastro[i].salario < 0) {
                posicaoConsoleSaida();
                printf("Digite um salario maior que 0!");
                getch();
                posicaoConsoleSaida();
            } else {
                break;
            }
        }

        // Lendo o sexo, e permitindo que apenas as opções F e M sejam inseridas.
        while(1) {
            gotoxy(24, 11);
            printf("                         ");
            gotoxy(24, 11);
            scanf(" %c", &log_cadastro[i].sexo);
            
            if (log_cadastro[i].sexo == 'F' || log_cadastro[i].sexo == 'f' || log_cadastro[i].sexo == 'M' || log_cadastro[i].sexo == 'm') {
                if (log_cadastro[i].sexo == 'm') {
                    log_cadastro[i].sexo = 'M';
                } else if (log_cadastro[i].sexo == 'f') {
                    log_cadastro[i].sexo = 'F';
                }
                break;
            } else {
                posicaoConsoleSaida();
                printf("Digite um sexo valido: F (feminino) ou M (masculino)");
                getch();
                posicaoConsoleSaida();
            }
        }

        // Verificando se o usuário deseja ou não realizar um próximo cadastro
        while (1) {
            posicaoConsoleSaida();
            printf("Cadastrar nova pessoa (1. Sim | 2. Nao):");
            gotoxy(51, 24);
            scanf("%d", &continuarCadastro);

            if (continuarCadastro == 1 || continuarCadastro == 2) {
                break;
            } else {
                posicaoConsoleSaida();
                printf("Digite uma opcao valida!");
                getch();
                posicaoConsoleSaida();
            }
        }

        // Se o usuário não quiser realizar outro cadastro, o comando de repetição é quebrado
        if (continuarCadastro == 2) {
            break;
        }

        // Se o limite de armazenamento da variável for preenchido, quebra o comando de repetição
        if (i == 10) {
            break;
        }

        i++;
    }

    // Exibição dos cadastros em formato de tabela
    construirTela();

    posicaoConsoleTitulo();
    printf("EXIBICAO DE CADASTROS");

    gotoxy(3, 5);
    printf("%-20s%-10s%-15s%-5s", "Nome", "Idade", "Salario", "Sexo");

    for (int j = 0; j <= i; j++) {
        gotoxy(3, j + 8);
        printf("%-20s%-10d%-15.2f%-5c", log_cadastro[j].nome, log_cadastro[j].idade, log_cadastro[j].salario, log_cadastro[j].sexo);
    }

    posicaoConsoleSaida();
    getch();

    return 0;
    
}