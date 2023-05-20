#ifndef LIBPRINT_H
#define LIBPRINT_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

struct Aluno {
    int matricula;
    float media;
    Aluno* esquerda;
    Aluno* direita;
}

int main();
void substituiAluno(Aluno* raiz, int matricula, float novaMedia);
void imprimeAluno(Aluno* aluno);
void liberaArvore(Aluno*& raiz);

#endif
