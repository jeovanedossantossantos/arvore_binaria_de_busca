#ifndef LIBPRINT_H
#define LIBPRINT_H
#include <iostream>

using namespace std;

// criar o prototipo da função

struct Aluno
{
    int matricula;
    float media;
    Aluno *esquerda;
    Aluno *direita;
};

int menu();
void substituiAluno(Aluno *raiz, int matricula, float novaMedia);
void imprimeAluno(Aluno *aluno);
void liberaArvore(Aluno *&raiz);

#endif
