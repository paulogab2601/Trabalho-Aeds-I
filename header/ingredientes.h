#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>


//Identifica o Sistema Operacional para limpeza de tela
#ifdef _WIN32   
    #define Clear "cls"
#else
    #define Clear "clear"
#endif


//Struct
typedef struct Ingrediente{
    int id;
    char nome[20];
    float preco;
}Ingrediente;


//Funções
void clearScreen();
void newIngrediente();
void viewIngrediente();
void editIngrediente();
void delIngrediente();

#endif