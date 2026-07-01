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
int main()
{
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
            printf("\nVoce escolheu a Incluir contato 1");
            // incluir contato
            printf("Digite o nome do contato: ");
            scanf("%s", agenda[quantidade].nome);
            printf("Digite o telefone do contato: ");
            scanf("%s", agenda[quantidade].telefone);
            quantidade++;
            break;
        case 2:
            printf("\nVoce escolheu a Listar contatos 2");
            for (int i = 0; i < quantidade; i++)
            {
                printf("\n\nContato %d", i + 1);
                printf("\nNome: %s", agenda[i].nome);
                printf("\nTelefone: %s", agenda[i].telefone);
            }
            break;
        case 3:
            printf("\nVoce escolheu a Consultar contato pelo nome 3");
 
            char busca[50];
 
            printf("\nDigite o nome para buscar: ");
            scanf("%s", busca);
 
            for (int i = 0; i < quantidade; i++)
            {
                if (strcmp(busca, agenda[i].nome) == 0)
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
                if (strcmp(nomeExcluir, agenda[i].nome) == 0)
                {
                    for (int j = i; j < quantidade - 1; j++)
                    {
                        agenda[j] = agenda[j + 1];
                    }
 
                    quantidade--;
 
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