#include "func.h"

#include <iostream>

using namespace std;
// Criar a logica da função

int menu()
{

    int n;

    cout << "Digite uma opcao" << endl;
    cout << "[1] Criar" << endl;
    cout << "[2] Substituir" << endl;
    cout << "[3] Buscar" << endl;
    cout << "[4] Remover" << endl;
    cout << "[0] Sair" << endl;
    cin >> n;

    return n;
}

Aluno *criarAluno(int matricula, float media)
{
    Aluno *novoAluno = new Aluno;
    novoAluno->matricula = matricula;
    novoAluno->media = media;
    novoAluno->esquerda = nullptr;
    novoAluno->direita = nullptr;
    return novoAluno;
}

Aluno *inserirAluno(Aluno *raiz, int matricula, float media)
{
    if (raiz == nullptr)
    {
        return criarAluno(matricula, media);
    }
    if (matricula < raiz->matricula)
    {
        raiz->esquerda = inserirAluno(raiz->esquerda, matricula, media);
    }
    else
    {
        raiz->direita = inserirAluno(raiz->direita, matricula, media);
    }
    return raiz;
}

void imprimirAlunos(Aluno *raiz)
{
    if (raiz != nullptr)
    {
        imprimirAlunos(raiz->esquerda);
        cout << "Matrícula: " << raiz->matricula << ", Média: " << raiz->media << endl;
        imprimirAlunos(raiz->direita);
    }
}

void desenfileirarAlunos(Aluno *raiz)
{
    if (raiz != nullptr)
    {
        desenfileirarAlunos(raiz->esquerda);
        if (raiz->media >= 5.0f)
        {
            cout << "Matrícula: " << raiz->matricula << endl;
        }
        desenfileirarAlunos(raiz->direita);
        delete raiz;
    }
}

Aluno *buscarAluno(Aluno *raiz, int matricula)
{
    if (raiz == nullptr || raiz->matricula == matricula)
    {
        return raiz;
    }
    if (matricula < raiz->matricula)
    {
        return buscarAluno(raiz->esquerda, matricula);
    }
    return buscarAluno(raiz->direita, matricula);
}

Aluno *substituirAluno(Aluno *raiz, int matricula, float novaMedia)
{
    if (raiz == nullptr)
    {
        return criarAluno(matricula, novaMedia);
    }
    if (matricula == raiz->matricula)
    {
        raiz->media = novaMedia;
    }
    else if (matricula < raiz->matricula)
    {
        raiz->esquerda = substituirAluno(raiz->esquerda, matricula, novaMedia);
    }
    else
    {
        raiz->direita = substituirAluno(raiz->direita, matricula, novaMedia);
    }
    return raiz;
}

Aluno *menorValor(Aluno *node)
{
    Aluno *current = node;
    while (current && current->esquerda != nullptr)
    {
        current = current->esquerda;
    }
    return current;
}
Aluno *remove(Aluno *root, int matricula)
{
    if (root == nullptr)
    {
        return root;
    }

    if (matricula < root->matricula)
    {
        root->esquerda = remove(root->esquerda, matricula);
    }
    else if (matricula > root->matricula)
    {
        root->direita = remove(root->direita, matricula);
    }
    else
    {
        if (root->esquerda == nullptr)
        {
            Aluno *temp = root->direita;
            delete root;
            return temp;
        }
        else if (root->direita == nullptr)
        {
            Aluno *temp = root->esquerda;
            delete root;
            return temp;
        }

        Aluno *successor = menorValor(root->direita);
        root->matricula = successor->matricula;
        root->media = successor->media;
        root->direita = remove(root->direita, successor->matricula);
    }

    return root;
}