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
Aluno *criarAluno(int matricula, float media);
Aluno *inserirAluno(Aluno *raiz, int matricula, float media);
void imprimirAlunos(Aluno *aluno);
void desenfileirarAlunos(Aluno *raiz);
Aluno *buscarAluno(Aluno *raiz, int matricula);
Aluno *substituirAluno(Aluno *raiz, int matricula, float novaMedia);
Aluno *menorValor(Aluno *node);
Aluno *remove(Aluno *root, int matricula);

#endif
