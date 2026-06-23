//trabalho feito por alunos: giovani, kawan




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101 // informa o tamanho maximo da agenda, ou seja, a quantidade de contatos que podem ser cadastrados.

// variaveis cadastro de contatos
struct Contato
{ // struct e utilizado para definir os campos 
    char nome[51]; //define o tamanho maximo de caracteres para cada campo 
    char telefone[20]; //define o tamanho maximo de caracteres para cada campo 
    char email[50]; //define o tamanho maximo de caracteres para cada campo 
};

struct Contato agenda[MAX]; // define o tamanho maximo da agenda como 100 contatos, atrasvez da constante MAX.
int total = 0;

// funcoes
void incluir()
{
    if (total >= MAX)
    { // verifica se a agenda esta cheia.
        printf("Agenda cheia!\n");
        return;
    }
    printf("\n-- Incluir Contato --\n");
    printf("Nome: ");
    scanf(" %[^\n]", agenda[total].nome); // " %[^\n]" e utilizado para ler uma string com espacos, ou seja, o nome completo do contato.
    fflush(stdin);
    printf("Telefone: ");
    scanf(" %[^\n]", agenda[total].telefone); // agenda[total] serve para acessar o proximo indice disponivel da agenda, ou seja, o proximo contato a ser cadastrado.
    fflush(stdin);
    printf("Email: ");
    scanf(" %[^\n]", agenda[total].email);
    fflush(stdin);
    total++; // Atualiza o contator de contatos cadastrados, para que o proximo contato seja cadastrado no indice correto da agenda.
    printf("Contato incluido!\n");
}

// lista os contatos cadastrados
void listar()
{
    printf("\n-- Lista de Contatos --\n"); // \n e utilizado para pular uma linha, deixando a exibicao mais organizada.
    if (total == 0)
    { // verifica se a agenda esta vazia.
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    for (int i = 0; i < total; i++)
    { // O loop percorre a agenda do indice 0 ate o indice total, exibindo os contatos cadastrados.
        printf("[%i] %s | %s | %s\n", i + 1, agenda[i].nome, agenda[i].telefone, agenda[i].email);
    }
}

// consulta um contato pelo nome. OBS: Precisa ser o nome completo.
void consultar()
{
    char busca[50]; // variavel para armazenar o nome a ser buscado.
    printf("\n-- Consultar Contato --\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", busca); // " %[^\n]" e utilizado para ler uma string com espacos, ou seja, o nome completo do contato.
    fflush(stdin);
    int encontrado = 0; // utilizado para verificar se o contato foi encontrado durante a busca.
    for (int i = 0; i < total; i++)
    { // percorre todos os contatos cadastrados na agenda.
        if (strcmp(agenda[i].nome, busca) == 0)
        { // strcmp compara duas strings. Se retornar 0, significa que os nomes sao iguais.
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            encontrado = 1; // altera a variavel para indicar que o contato foi encontrado.
        }
    }
    if (!encontrado)
    { // executa caso nenhum contato tenha sido encontrado.
        printf("Contato nao encontrado.\n");
    }
}

// exclui um contato pelo nome. OBS: Precisa ser o nome completo.
void excluir()
{
    char busca[50]; // variavel utilizada para armazenar o nome que sera procurado para exclusao.
    printf("\n-- Excluir Contato --\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", busca); // " %[^\n]" permite informar o nome completo com espacos.
    fflush(stdin);
    int pos = -1; // armazena a posicao do contato encontrado. Inicia com -1 para indicar que nao foi localizado.
    for (int i = 0; i < total; i++)
    { // percorre todos os contatos cadastrados.
        if (strcmp(agenda[i].nome, busca) == 0)
        {            // verifica se o nome informado e igual ao nome cadastrado.
            pos = i; // salva a posicao do contato encontrado.
        }
    }
    if (pos == -1)
    { // se continuar -1 significa que o contato nao existe na agenda.
        printf("Contato nao encontrado.\n");
        return;
    }
    for (int i = pos; i < total - 1; i++)
    { // reorganiza os contatos para preencher o espaco deixado pelo contato excluido.
        agenda[i] = agenda[i + 1];
    }
    total--; // reduz a quantidade total de contatos cadastrados.
    printf("Contato excluido!\n");
}

int main(void)
{
    // variaveis
    int op; // op = opcao do menu.
    // menu de opcoes
    do
    {
        printf("\n=== Agenda de Contatos ===\n");
        printf("1 - Incluir\n");
        printf("2 - Listar\n");
        printf("3 - Consultar\n");
        printf("4 - Excluir\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1: // adicionar usuario
            incluir();
            break; // break para que o programa saia do switch e volte para o menu, evitando que ele execute as outras opcoes.
        case 2:    // listar usuarios
            listar();
            break;
        case 3: // consultar usuario
            consultar();
            break;
        case 4: // excluir usuario
            excluir();
            break;
        case 0: // sair do programa
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (op != 0); // O codigo fica em loop ate o usuario escolher a opcao de sair (0).

    return 0;

}
