#include "func.cpp"

int main()
{
    int op = 0;
    do
    {
        op = menu();
        cout << op;

        switch (op)
        {
        case 1:
            inserirAluno();
            break;
        case 2:
            substituirAluno();
            break;
        case 3:
            buscarAluno();
            break;
        case 4:

            break;
        default:
            break;
        }

    } while (op != 0);

    return 0;
}
