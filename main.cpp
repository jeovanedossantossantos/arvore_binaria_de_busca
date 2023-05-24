#include "func.cpp"
using namespace std;
int main()
{
    int op = 0;
    int matricula;
    float media;
    Aluno *aluno = new Aluno;
    do
    {
        op = menu();
        cout << op;

        switch (op)
        {
        case 1:
            cout << "Digite a matricula\n";
            cin >> matricula;
            cout << "Digite a media";
            cin >> media;
            aluno = criarAluno(matricula, media);
            break;
        case 2:
            cout << "Digite a matricula\n";
            cin >> matricula;
            cout << "Digite a media";
            cin >> media;
            aluno = substituirAluno(aluno, matricula, media);
            break;
        case 3:
            // buscarAluno();
            break;
        case 4:

            break;
        default:
            break;
        }

    } while (op != 0);

    return 0;
}
