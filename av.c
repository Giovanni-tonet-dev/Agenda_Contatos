#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

struct v0001
{
    char v0002[51];
    char v0003[20];
    char v0004[50];
};

struct v0001 v0005[MAX];
int v0006 = 0;

void f0001()
{
    if (v0006 >= MAX)
    {
        printf("Agenda cheia!\n");
        return;
    }
    printf("\n-- Incluir Contato --\n");
    printf("Nome: ");
    scanf(" %[^\n]", v0005[v0006].v0002);
    fflush(stdin);
    printf("Telefone: ");
    scanf(" %[^\n]", v0005[v0006].v0003);
    fflush(stdin);
    printf("Email: ");
    scanf(" %[^\n]", v0005[v0006].v0004);
    fflush(stdin);
    v0006++;
    printf("Contato incluido!\n");
}

void f0002()
{
    printf("\n-- Lista de Contatos --\n");
    if (v0006 == 0)
    {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    for (int i = 0; i < v0006; i++)
    {
        printf("[%i] %s | %s | %s\n", i + 1, v0005[i].v0002, v0005[i].v0003, v0005[i].v0004);
    }
}

void f0003()
{
    char v0007[50];
    printf("\n-- Consultar Contato --\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", v0007);
    fgets(v0007, sizeof(v0007), stdin);
    fflush(stdin);
    int v0008 = 0;
    for (int i = 0; i < v0006; i++)
    {
        if (strcmp(v0005[i].v0002, v0007) == 0)
        {
            printf("Nome: %s\n", v0005[i].v0002);
            printf("Telefone: %s\n", v0005[i].v0003);
            printf("Email: %s\n", v0005[i].v0004);
            v0008 = 1;
        }
    }
    if (!v0008)
    {
        printf("Contato nao encontrado.\n");
    }
}

void f0004()
{
    char v0009[50];
    printf("\n-- Excluir Contato --\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", v0009);
    fflush(stdin);
    int v0010 = -1;
    for (int i = 0; i < v0006; i++)
    {
        if (strcmp(v0005[i].v0002, v0009) == 0)
        {
            v0010 = i;
        }
    }
    if (v0010 == -1)
    {
        printf("Contato nao encontrado.\n");
        return;
    }
    for (int i = v0010; i < v0006 - 1; i++)
    {
        v0005[i] = v0005[i + 1];
    }
    v0006--;
    printf("Contato excluido!\n");
}

int main(void)
{
    int v0011;
    do
    {
        printf("\n=== Agenda de Contatos ===\n");
        printf("1 - Incluir\n");
        printf("2 - Listar\n");
        printf("3 - Consultar\n");
        printf("4 - Excluir\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%i", &v0011);
        fflush(stdin);

        switch (v0011)
        {
        case 1:
            f0001();
            break;
        case 2:
            f0002();
            break;
        case 3:
            f0003();
            break;
        case 4:
            f0004();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (v0011 != 0);

    return 0;
}