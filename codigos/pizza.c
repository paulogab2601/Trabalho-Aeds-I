#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/pizza.h"

// Função para adicionar uma pizza
void adicionarPizza(Pizza *pizzas, int *numPizzas)
{
    if (*numPizzas >= MAX_PIZZAS)
    {
        printf("Limite de pizzas atingido.\n");
        system("PAUSE");
        system("CLS");
        return;
    }
    Pizza novaPizza;
    novaPizza.id = *numPizzas + 1; // ID auto-incremental
    printf("Nome da pizza: ");

    getchar(); // Limpa o buffer de entrada
    fgets(novaPizza.nome, 100, stdin);

    // Remove o '\n' do final da string, se existir
    int tamanho = strlen(novaPizza.nome);
    if (tamanho > 0 && novaPizza.nome[tamanho - 1] == '\n')
    {
        novaPizza.nome[tamanho - 1] = '\0';
    }

    do
    {
        printf("Tamanho (P, M, G): ");
        scanf(" %c", &novaPizza.tamanho);

        if ((novaPizza.tamanho != 'P') && (novaPizza.tamanho != 'p') && (novaPizza.tamanho != 'M') && (novaPizza.tamanho != 'm') && (novaPizza.tamanho != 'G') && (novaPizza.tamanho != 'g'))
        {
            printf("Digite uma opcao valida!\n");

            system("PAUSE");
            system("CLS");
        }

    } while ((novaPizza.tamanho != 'P') && (novaPizza.tamanho != 'p') && (novaPizza.tamanho != 'M') && (novaPizza.tamanho != 'm') && (novaPizza.tamanho != 'G') && (novaPizza.tamanho != 'g'));

    printf("Preco: ");
    scanf("%f", &novaPizza.preco);

    // Adiciona ingredientes padrão
    novaPizza.num_ingredientes = 0;
    printf("Quantos ingredientes padrao deseja adicionar? ");
    scanf("%d", &novaPizza.num_ingredientes);

    for (int i = 0; i < novaPizza.num_ingredientes; i++)
    {
        printf("Nome do ingrediente %d: ", i + 1);
        getchar(); // Limpa o buffer de entrada
        fgets(novaPizza.ingredientes[i].nome, 100, stdin);

        // Remove o '\n' do final da string, se existir
        tamanho = strlen(novaPizza.ingredientes[i].nome);
        if (tamanho > 0 && novaPizza.ingredientes[i].nome[tamanho - 1] == '\n')
        {
            novaPizza.ingredientes[i].nome[tamanho - 1] = '\0';
        }

        printf("Preco do ingrediente %d: ", i + 1);
        scanf("%f", &novaPizza.ingredientes[i].preco);
        novaPizza.ingredientes[i].id = i + 1; // ID incremental
    }

    pizzas[*numPizzas] = novaPizza;
    (*numPizzas)++;
    printf("Pizza adicionada com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para visualizar as pizzas
void visualizarPizzas(Pizza *pizzas, int numPizzas)
{
    if (numPizzas == 0)
    {
        printf("Nenhuma pizza cadastrada.\n");

        system("PAUSE");
        system("CLS");

        return;
    }
    for (int i = 0; i < numPizzas; i++)
    {
        printf("ID: %d, Nome: %s, Tamanho: %c, Preco: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].preco);
        printf("Ingredientes:\n");
        for (int j = 0; j < pizzas[i].num_ingredientes; j++)
        {
            printf("  - %s (%.2f)\n", pizzas[i].ingredientes[j].nome, pizzas[i].ingredientes[j].preco);
        }
        printf("\n");
    }

    system("PAUSE");
    system("CLS");
}

// Função para editar uma pizza
void editarPizza(Pizza *pizzas, int numPizzas)
{
    int id;
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);

    if (id < 1 || id > numPizzas)
    {
        printf("Pizza nao encontrada.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    Pizza *pizza = &pizzas[id - 1]; // Acesso à pizza
    printf("Novo nome da pizza (atual: %s): ", pizza->nome);

    getchar();
    fgets(pizza->nome, 100, stdin);

    // Remove o '\n' do final da string, se existir
    int tamanho = strlen(pizza->nome);
    if (tamanho > 0 && pizza->nome[tamanho - 1] == '\n')
    {
        pizza->nome[tamanho - 1] = '\0';
    }

    do
    {
        printf("Novo tamanho da pizza (atual: %c): ", pizza->tamanho);
        scanf(" %c", &pizza->tamanho);
        if ((pizza->tamanho != 'P') && (pizza->tamanho != 'p') && (pizza->tamanho != 'M') && (pizza->tamanho != 'm') && (pizza->tamanho != 'G') && (pizza->tamanho != 'g'))
        {
            printf("Digite uma opcao valida!\n");

            system("PAUSE");
            system("CLS");
        }

    } while ((pizza->tamanho != 'P') && (pizza->tamanho != 'p') && (pizza->tamanho != 'M') && (pizza->tamanho != 'm') && (pizza->tamanho != 'G') && (pizza->tamanho != 'g'));

    printf("Novo preco da pizza (atual: %.2f): ", pizza->preco);
    scanf("%f", &pizza->preco);

    printf("Quantos ingredientes padrao deseja adicionar? ");
    scanf("%d", &pizza->num_ingredientes);

    for (int i = 0; i < pizza->num_ingredientes; i++)
    {
        printf("Nome do ingrediente %d: ", i + 1);

        getchar();
        fgets(pizza->ingredientes[i].nome, 100, stdin);
        pizza->ingredientes[i].nome[strcspn(pizza->ingredientes[i].nome, "\n")] = '\0';
        printf("Preco do ingrediente %d: ", i + 1);
        scanf("%f", &pizza->ingredientes[i].preco);
        pizza->ingredientes[i].id = i + 1; // ID auto-incremental para ingredientes
    }
    printf("Pizza editada com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para remover uma pizza
void removerPizza(Pizza *pizzas, int *numPizzas)
{
    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);

    if (id < 1 || id > *numPizzas)
    {
        printf("Pizza nao encontrada.\n");

        system("PAUSE");
        system("CLS");

        return;
    }

    // Remover a pizza, deslocando os elementos
    for (int i = id - 1; i < *numPizzas - 1; i++)
    {
        pizzas[i] = pizzas[i + 1];
    }
    (*numPizzas)--; // Decrementa o número de pizzas
    printf("Pizza removida com sucesso!\n");

    system("PAUSE");
    system("CLS");
}

// Função para exportar pizza
void exportarPizzas(Pizza *pizzas, int numPizzas)
{
    FILE *file = fopen("pizzas.txt", "w");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo para exportação");
        return;
    }

    for (int i = 0; i < numPizzas; i++)
    {
        // Exporta os dados da pizza em uma única linha, separados por ponto e vírgula
        fprintf(file, "%d;%s;%c;%.2f;%d",
                pizzas[i].id,
                pizzas[i].nome,
                pizzas[i].tamanho,
                pizzas[i].preco,
                pizzas[i].num_ingredientes);

        // Adiciona os ingredientes na mesma linha
        for (int j = 0; j < pizzas[i].num_ingredientes; j++)
        {
            fprintf(file, ";%s,%.2f",
                    pizzas[i].ingredientes[j].nome,
                    pizzas[i].ingredientes[j].preco);
        }
        fprintf(file, "\n"); // Finaliza a linha para a próxima pizza
    }

    fclose(file);
    printf("Pizzas exportadas com sucesso!\n");
}

// Função para importar pizza
void importarPizzas(Pizza *pizzas, int *numPizzas)
{
    FILE *file = fopen("pizzas.txt", "r");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo para importação");
        return;
    }

    char linha[1024];
    while (fgets(linha, sizeof(linha), file))
    {
        // Divide a linha em partes usando strtok
        char *token = strtok(linha, ";");

        // Lê os dados principais da pizza
        pizzas[*numPizzas].id = atoi(token);
        token = strtok(NULL, ";");
        strcpy(pizzas[*numPizzas].nome, token);
        token = strtok(NULL, ";");
        pizzas[*numPizzas].tamanho = token[0];
        token = strtok(NULL, ";");
        pizzas[*numPizzas].preco = atof(token);
        token = strtok(NULL, ";");
        pizzas[*numPizzas].num_ingredientes = atoi(token);

        // Lê os ingredientes
        for (int j = 0; j < pizzas[*numPizzas].num_ingredientes; j++)
        {
            token = strtok(NULL, ";");
            if (token == NULL)
                break;

            // Divide nome e preço do ingrediente
            char *subtoken = strtok(token, ",");
            strcpy(pizzas[*numPizzas].ingredientes[j].nome, subtoken);
            subtoken = strtok(NULL, ",");
            pizzas[*numPizzas].ingredientes[j].preco = atof(subtoken);
            pizzas[*numPizzas].ingredientes[j].id = j + 1;
        }

        (*numPizzas)++;
        if (*numPizzas >= MAX_PIZZAS)
        {
            printf("Limite de pizzas atingido durante a importação.\n");
            break;
        }
    }

    fclose(file);
    printf("Pizzas importadas com sucesso!\n");
}