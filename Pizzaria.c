#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#ifdef _WIN32   //Identifica o Sistema Operacional
    #define Clear "cls"
#else
    #define Clear "clear"
#endif

void clearScreen() {   //Funcao para limpar terminal
    system(Clear);
}


typedef struct Ingrediente{
    int id;
    char nome[20];
    float preco;
}Ingrediente;

typedef struct Pizza{
    int id;
    char nome[30];
    char tamanho;
    float preco;
    Ingrediente ingredientes[10];
}Pizza;


int main(){
    int op, temp;

    int id=0;

    char tempChar;

    Pizza pizza[99];

    while(1){ // Menu Principal
        clearScreen();

        puts("\t\t\t\e[1m| Seja Bem-Vindo a Freddy's Bear Pizzaria |\e[0m");

        puts("1) Adicionar Pizza\n2) Visualizar Cardapio\n3) Editar Cardapio\n4) Remover Pizza\n0) Encerrar Programa");
        scanf("%d", &op);

        getchar();

        switch(op){

        case 1: // Menu Adicionar Pizza
            //addPizza();

            clearScreen();

            id++;
            pizza[id].id = id;
            int qtd_ingred = 0;

            printf("Digite o nome da nova Pizza [ID: %d] :\n", id);
            scanf("%[^\n]", pizza[id].nome);

            while(1){   // Verifica se o tamanho é valido
                puts("Digite o Tamanho (P, M, G): ");
                scanf(" %c", &tempChar);
                tempChar = toupper(tempChar);

                if(tempChar != 'P' && tempChar != 'M' && tempChar != 'G'){
                    puts("Tamanho invalido");
                }else{
                    pizza[id].tamanho = tempChar;
                    break;
                }
            }

            puts("Digite o Preco: ");
            scanf("%f", &pizza[id].preco);

            getchar();

            while(qtd_ingred < 10){

                printf("Adicionar Ingrediente %d/10: ", qtd_ingred+1);
                fgets(pizza[id].ingredientes[qtd_ingred].nome, 20, stdin);

                pizza[id].ingredientes[qtd_ingred].nome[strcspn(pizza[id].ingredientes[qtd_ingred].nome, "\n")] = '\0';     // Remove '\n'

                if(strcmp(pizza[id].ingredientes[qtd_ingred].nome, "x") == 0 || strcmp(pizza[id].ingredientes[qtd_ingred].nome, "X") == 0){
                    strcpy(pizza[id].ingredientes[qtd_ingred].nome, "");
                    break;
                }

                qtd_ingred++;

            }

            printf("\nPizza \"%s\" adicionada com sucesso!", pizza[id].nome);
            puts("\nPressione ENTER para continuar...");
            getchar();

            break;
        
        case 2:      // Visualizar Cardapio

            clearScreen();

            puts("\t\t| Pizzas Pequenas |\n");
            
            for(int i=1; i<=id; i++){
                if(pizza[i].tamanho == 'P'){
                    printf("\n| %-25s | R$  %.2f |\n", pizza[i].nome, pizza[i].preco);
                    printf(" - ");

                    for(int j=0; j<10; j++){    // Print Ingredientes
                        if(strlen(pizza[i].ingredientes[j].nome) > 0)
                            printf("\e[38;5;245m%s, \e[0m", pizza[i].ingredientes[j].nome);
                    }
                }
            }

            puts("\n\n\t\t| Pizzas Medias |\n");
            
            for(int i=1; i<=id; i++){
                if(pizza[i].tamanho == 'P'){
                    printf("\n| %-25s | R$  %.2f |\n", pizza[i].nome, pizza[i].preco);
                    printf(" - ");

                    for(int j=0; j<10; j++){    // Print Ingredientes
                        if(strlen(pizza[i].ingredientes[j].nome) > 0)
                            printf("\e[38;5;245m%s, \e[0m", pizza[i].ingredientes[j].nome);
                    }
                }
            }

            puts("\n\n\t\t| Pizzas Grandes |\n");
            
            for(int i=1; i<=id; i++){
                if(pizza[i].tamanho == 'P'){
                    printf("\n| %-25s | R$  %.2f |\n", pizza[i].nome, pizza[i].preco);
                    printf(" - ");

                    for(int j=0; j<10; j++){    // Print Ingredientes
                        if(strlen(pizza[i].ingredientes[j].nome) > 0)
                            printf("\e[38;5;245m%s, \e[0m", pizza[i].ingredientes[j].nome);
                    }
                }
            }

            getchar();

            break;
        
        case 3:     // Editar Cardapio
            
            clearScreen();

            puts("\t\t| Pizzas Cadastradas |\n");
            for(int i=1; i<=id; i++){
                printf("\n[ID %d] | %-25s | R$  %.2f |\n", i, pizza[i].nome, pizza[i].preco);
                printf(" - ");

                for(int j=0; j<10; j++){    // Print Ingredientes
                    if(strlen(pizza[i].ingredientes[j].nome) > 0)
                        printf("\e[38;5;245m%s, \e[0m", pizza[i].ingredientes[j].nome);
                }
            }
            
            puts("Digite o ID da Pizza que deseja alterar: ");
            scanf("%d", &temp);
            
                clearScreen();

                printf("\n[ID %d] | %-25s | R$  %.2f |", temp, pizza[temp].nome, pizza[temp].preco);
                for(int j=0; j<10; j++){ 
                    if(strlen(pizza[temp].ingredientes[j].nome) > 0)
                        printf("\n%s (R$ %.2f)", pizza[temp].ingredientes[j].nome, pizza[temp].ingredientes[j].preco);
                }


            getchar();

            break;
        
        case 4:
            
            break;
        
        case 0:
            clearScreen();

            puts("\nAte a proxima!");
        
            return 0;
            break;
        
        default:
            puts("Opcao Invalida.");
            break;
        }
    }
}