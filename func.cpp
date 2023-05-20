#include "func.h"
#include <iostream>

using namespace std;
// Criar a logica da função

int menu()
{

    int n;

    cout << "Digite uma opcao" << endl;
    cout << "[1] Inserir" << endl;
    cout << "[2] Substituir" << endl;
    cout << "[3] Buscar" << endl;
    cout << "[4] Remover" << endl;
    cout << "[0] Sair" << endl;
    cin >> n;

    return n;
}
