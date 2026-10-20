#include <stdio.h>
#include <string.h>

struct Cliente
{
    char nome[100];
    int idade;
};

int main()

{
    int opcao;
    struct Cliente clientes[100];
    int totalClientes = 0;
    char nomePesquisa[100];
    char nomeExcluir[100];
    FILE *arquivo;

    arquivo = fopen("clientes.dat", "rb");

    if (arquivo != NULL)
    {
        totalClientes = fread(clientes, sizeof(struct Cliente), 100, arquivo);

        fclose(arquivo);

        printf("Clientes carregados: %d\n", totalClientes);
    }

    do
    {

        printf("===============================\n");
        printf("    SISTEMA DE CADASTRO\n");
        printf("===============================\n");
        printf("===============================\n");
        printf(" 1 - Cadastrar cliente\n");
        printf(" 2 - Listar clientes\n");
        printf(" 3 - Pesquisar cliente\n");
        printf(" 4 - Excluir cliente\n");
        printf(" 0 - Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1)
        {
            printf("\nEntrada invalida! Digite um numero.\n");

            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF)
            {
            }

            opcao = -1;
            continue;
        }
        switch (opcao)
        {
        case 1:
            if (totalClientes >= 100)
            {
                printf("Limite de clientes atingido!\n");
                break;
            }

            printf("\n--- CADASTRO DE CLIENTE ---\n");

            printf("Digite o nome do cliente: ");
            scanf(" %99[^\n]", clientes[totalClientes].nome);

            do
            {
                printf("Digite a idade do cliente: ");

                if (scanf("%d", &clientes[totalClientes].idade) != 1)
                {
                    printf("Idade invalida! Digite um numero.\n");

                    int caractere;
                    while ((caractere = getchar()) != '\n' && caractere != EOF)
                    {
                    }

                    clientes[totalClientes].idade = -1;
                }
                else if (clientes[totalClientes].idade < 0 ||
                         clientes[totalClientes].idade > 120)
                {
                    printf("Idade invalida! Digite uma idade entre 0 e 120.\n");
                }

            } while (clientes[totalClientes].idade < 0 ||
                     clientes[totalClientes].idade > 120);

            printf("\nCliente cadastrado!\n");
            printf("Nome: %s\n", clientes[totalClientes].nome);
            printf("Idade: %d\n", clientes[totalClientes].idade);

            totalClientes++;

            break;

        case 2:
            printf("\n--- LISTA DE CLIENTES ---\n");

            if (totalClientes == 0)
            {
                printf("Nenhum cliente cadastrado!\n");
            }
            else
            {
                for (int i = 0; i < totalClientes; i++)
                {
                    printf("\nCliente %d\n", i + 1);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Idade: %d\n", clientes[i].idade);
                }
            }

            break;

        case 3:
        {
            int encontrado = 0;

            printf("\n--- PESQUISAR CLIENTE ---\n");

            printf("Digite o nome do cliente: ");
            scanf(" %99[^\n]", nomePesquisa);

            for (int i = 0; i < totalClientes; i++)
            {
                if (strcmp(nomePesquisa, clientes[i].nome) == 0)
                {
                    printf("\nCliente encontrado!\n");
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Idade: %d\n", clientes[i].idade);

                    encontrado = 1;
                    break;
                }
            }

            if (encontrado == 0)
            {
                printf("\nCliente nao encontrado!\n");
            }

            break;
        }

        case 4:
        {
            int encontrado = 0;

            printf("\n--- EXCLUIR CLIENTE ---\n");
            printf("Digite o nome do cliente: ");
            scanf(" %99[^\n]", nomeExcluir);

            for (int i = 0; i < totalClientes; i++)
            {
                if (strcmp(nomeExcluir, clientes[i].nome) == 0)
                {
                    for (int j = i; j < totalClientes - 1; j++)
                    {
                        clientes[j] = clientes[j + 1];
                    }

                    totalClientes--;

                    printf("\nCliente excluido com sucesso!\n");
                    encontrado = 1;
                    break;
                }
            }

            if (encontrado == 0)
            {
                printf("\nCliente nao encontrado!\n");
            }

            break;
        }

        case 0:
            arquivo = fopen("clientes.dat", "wb");

            if (arquivo == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
            }
            else
            {

                size_t gravados = fwrite(clientes, sizeof(struct Cliente), totalClientes, arquivo);

                int erroFechamento = fclose(arquivo);

                if (gravados == totalClientes && erroFechamento == 0)
                {
                    printf("Clientes salvos com sucesso!\n");
                }
                else
                {
                    printf("Erro ao salvar os clientes!\n");
                }
            }

            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
    return 0;
}
