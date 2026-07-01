#include <stdio.h>  //biblioteca
#include <stdlib.h> //biblioteca
#include <string.h> //biblioteca

// variaveis
#define MAX 100 // define o tamanho máximo do vetor

struct Contato
{
    char nome[50];
    char telefone[15];
};

struct Contato agenda[MAX];
int quantidade = 0;

// Função para salvar os contatos em um arquivo
void salvarAgenda()
{
    FILE *arquivo;

    arquivo = fopen("agenda.dat", "wb"); // abre o arquivo para escrita em modo binário

    if (arquivo == NULL)
    {
        printf("\nErro ao salvar o arquivo!");
        return;
    }

    // salva a quantidade de contatos
    fwrite(&quantidade, sizeof(int), 1, arquivo);

    // salva todos os contatos cadastrados
    fwrite(agenda, sizeof(struct Contato), quantidade, arquivo);

    fclose(arquivo);
}

// Função para carregar os contatos do arquivo
void carregarAgenda()
{
    FILE *arquivo;

    arquivo = fopen("agenda.dat", "rb"); // abre o arquivo para leitura em modo binário

    // caso o arquivo ainda não exista
    if (arquivo == NULL)
    {
        quantidade = 0;
        return;
    }

    // lê a quantidade de contatos
    fread(&quantidade, sizeof(int), 1, arquivo);

    // lê todos os contatos
    fread(agenda, sizeof(struct Contato), quantidade, arquivo);

    fclose(arquivo);
}

int main()
{
    // Carrega os contatos salvos antes de mostrar o menu
    carregarAgenda();

    int opcao;

    do
    {
        // menu de opções
        printf("\n=========================");
        printf("\n    MENU DE OPCOES       ");
        printf("\n=========================");
        printf("\n1. Opcao 1(incluir contato)"); // incluir contato
        printf("\n2. Opcao 2 (listar contatos)"); // listar contatos
        printf("\n3. Opcao 3 (consultar contato pelo nome)"); // consultar contato pelo nome
        printf("\n4. Opcao 4 (excluir contato)"); // excluir contato
        printf("\n5. Sair (ir embora)");    // ir embora
        printf("\n=========================");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        // estrutura de decisão
        switch (opcao)
        {
        case 1:
            printf("\nVoce escolheu  Incluir contato 1");
            printf("\nDigite o nome do contato: ");
            scanf("%s", agenda[quantidade].nome);   // variavel quantidade é usada para armazenar o número de contatos na agenda

            printf("Digite o telefone do contato: ");
            scanf("%s", agenda[quantidade].telefone);

            quantidade++; // adiciona 1 ao número de contatos na agenda

            // salva os contatos após cadastrar
            salvarAgenda();

            break;

        case 2:
            printf("\nVoce escolheu a Listar contatos 2");

            for (int i = 0; i < quantidade; i++) // loop para percorrer todos os contatos na agenda
            {
                printf("\n\nContato %d", i + 1);
                printf("\nNome: %s", agenda[i].nome);
                printf("\nTelefone: %s", agenda[i].telefone);
            }

            break;

        case 3:
            printf("\nVoce escolheu a Consultar contato pelo nome 3");

            char busca[50]; // define o tamanho do vetor de busca

            printf("\nDigite o nome para buscar: ");
            scanf("%s", busca);

            for (int i = 0; i < quantidade; i++)
            {
                if (strcmp(busca, agenda[i].nome) == 0) // strcmp compara duas strings e retorna 0 se forem iguais
                {
                    printf("\nContato encontrado!");
                    printf("\nNome: %s", agenda[i].nome);
                    printf("\nTelefone: %s", agenda[i].telefone);
                }
            }

            break;

        case 4:
            printf("\nVoce escolheu a Excluir contato 4");

            char nomeExcluir[50];

            printf("\nDigite o nome do contato para excluir: ");
            scanf("%s", nomeExcluir);

            for (int i = 0; i < quantidade; i++)
            {
                if (strcmp(nomeExcluir, agenda[i].nome) == 0) // strcmp compara duas strings e retorna 0 se forem iguais
                {
                    for (int j = i; j < quantidade - 1; j++)
                    {
                        agenda[j] = agenda[j + 1];
                    }

                    quantidade--; // decrementa a quantidade de contatos na agenda

                    // salva a agenda após excluir
                    salvarAgenda();

                    printf("\nContato excluido com sucesso!");

                    break;
                }
            }

            break;

        case 5:
            printf("\nSaindo do programa...");
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.");
        }

    } while (opcao != 5); // condição de saída do loop

    return 0; // retorna 0 para indicar que o programa terminou com sucesso
}