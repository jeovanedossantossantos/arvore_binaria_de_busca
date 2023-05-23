#include "func.h"



void substituiAluno(Aluno* raiz, int matricula, float novaMedia) {
    Aluno* atual = raiz;

    while (atual != nullptr) {
        if (matricula == atual->matricula) {
            atual->media = novaMedia;
            break;
        } else if (matricula < atual->matricula) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
}

void imprimeAluno(Aluno* aluno) {
    if (aluno != nullptr) {
        imprimeAluno(aluno->esquerda);
        cout << "Matr�cula: " << aluno->matricula << ", M�dia: " << aluno->media <<endl;
        imprimeAluno(aluno->direita);
    }
}

void liberaArvore(Aluno*& raiz) {
    if (raiz != nullptr) {
        liberaArvore(raiz->esquerda);
        liberaArvore(raiz->direita);
        delete raiz;
        raiz = nullptr;
    }
}
Aluno* buscarAluno(Aluno* raiz, int matricula) {
    if (raiz == nullptr || raiz->matricula == matricula) {
        return raiz;
    }

    if (matricula < raiz->matricula) {
        return buscarAluno(raiz->esquerda, matricula);
    } else {
        return buscarAluno(raiz->direita, matricula);
    }
}

