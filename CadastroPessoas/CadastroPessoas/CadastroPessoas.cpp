#include <iostream>
#include <conio.h>
#include <string.h>
#include <Windows.h>

//Struct de pessoas
struct Pessoas {
    char nrCpfCnpj[15];
    char nome[50];
};

//Função que cadastra uma pessoa
void cadastrarPessoa(Pessoas pessoa[10], int &contagem) {

    system("cls");
    printf("Cadastrar uma nova pessoa: \n\n");
    
    if (contagem >= 10) {//Não deixar cadastrar pessoas, caso já esteja no limite permitido
        printf("Limite de cadastros excedidos, favor verificar \n");
    }
    else { //Cadastrar pessoas
        printf("Informe o CPF ou CNPJ (Sem pontos): \n");
        scanf_s("%s", &pessoa[contagem].nrCpfCnpj, 15);
        fflush(stdin); //Lê o dado de entrada para evitar problemas de buffer

        printf("Informe o nome completo: \n");
        scanf_s("%c", pessoa[contagem].nome, 50);
        fgets(pessoa[contagem].nome, sizeof(pessoa[contagem].nome), stdin); //Lê o dado de entrada para evitar problemas de buffer

        contagem++;

        printf("Cadastro efetuado \n");
    }
}

//Função que visualiza os cadastros
void visualizarPessoas(Pessoas pessoa[10], int contagem) {

    system("cls");
    printf("Cadastros \n\n");
    if (contagem == 0) {
        printf("Não há pessoas cadastradas \n");
    }

    for (int i = 0; i < contagem; i++) {
        printf("CPF/CNPJ: %s \tNome: %s \n", pessoa[i].nrCpfCnpj, pessoa[i].nome);
    }
}

//Função que altera cadastros
void alterarPessoas(Pessoas pessoa[], int& contagem, char pesquisaCpfCnpj[]) {

    bool localizado = false;
    system("cls");
    printf("Alterar Pessoa \n\n");
    printf("Digite o CPF ou CNPJ para pesquisa (Sem pontos): \n");
    scanf_s("%s", pesquisaCpfCnpj, 15);

    for (int i = 0; i < contagem; i++) {
        if (strcmp(pessoa[i].nrCpfCnpj, pesquisaCpfCnpj) == 0) { //Se tiver CPF/CNPJ igual ao pesquisado libera a altereção
            printf("\n");
            printf("Digite o novo CPF ou CNPJ do cadastro (Sem pontos): \n");
            scanf_s("%s", pessoa[i].nrCpfCnpj, 15);
            fflush(stdin); //Lê o dado de entrada para evitar problemas de buffer

            printf("Digite o novo nome do cadastro: \n");
            scanf_s("%c", pessoa[i].nome, 50);
            fgets(pessoa[i].nome, sizeof(pessoa[i].nome), stdin); //Lê o dado de entrada para evitar problemas de buffer

            printf("Cadastro alterado com sucesso \n");
            localizado = true;
            break;
        }
    }

    if (!localizado) { //Se não tiver CPF/CNPJ igual ao pesquisado, retorna mensagem de erro
        printf("Cadastro nao localizado \n");
    }
}

//Função que exclui os cadastros
void excluirPessoa(Pessoas pessoa[], int &contagem, char pesquisaCpfCnpj[]) {

    bool encontrado = false;

    system("cls");
    printf("Excluir Pessoa \n\n");
    printf("Digite o CPF ou CNPJ para pesquisa (Sem pontos): \n");
    scanf_s("%s", pesquisaCpfCnpj, 15);

    for (int i = 0; i < contagem; i++) {
        if (strcmp(pessoa[i].nrCpfCnpj, pesquisaCpfCnpj) == 0) {
            for (int j = i; j < contagem - 1; j++) {
                pessoa[j] = pessoa[j + 1];
            }

            contagem--;
            printf("Cadastro excluido com sucesso \n");
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Cadastro nao localizado \n");
    }
}

int main() {
    struct Pessoas pessoa[10]; //Declarando o struct Pessoas
    int opcao, contagem = 0;
    char res = 's';
    char pesquisaCpfCnpj[15];

    while (res == 's') {
        system("cls");
        printf("Menu de Cadastros \n\n");
        printf("1- Cadastrar Pessoa \n");
        printf("2- Cadastros \n");
        printf("3- Alterar Cadastros \n");
        printf("4- Excluir Cadastros \n");
        printf("5- Sair \n");
        scanf_s("%d", &opcao);

        switch (opcao) {
        case 1:
            cadastrarPessoa(pessoa, contagem);
            break;

        case 2:
            visualizarPessoas(pessoa, contagem);
            break;

        case 3:
            alterarPessoas(pessoa, contagem, pesquisaCpfCnpj);
            break;

        case 4: 
            excluirPessoa(pessoa, contagem, pesquisaCpfCnpj);
            break;

        case 5: 
            printf("Saindo... \n");
            break;

        default:
            printf("Opcao invalida \n");
            break;
        }

        printf("\n");
        printf("Deseja voltar para o menu? (s/n) \n");
        res = _getch();
    }
    system("pause");
}