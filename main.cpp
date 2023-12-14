#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void Limpia(){
    system("pause");
    system("cls");
}

int main()
{
    int op;
    do
    {
        Limpia();
        cout << "\n\t***** Menu de Entregables del 2 al 9 ****** \n" << endl;
        cout << "1.-Entregable Dos" << endl;
        cout << "2.-Entregable Tres" << endl;
        cout << "3.-Entregable Cuatro" << endl;
        cout << "4.-Entregable 5, 6 y 7" << endl;
        cout << "5.-Entregable 8 y 9" << endl;
        cout << "6.-Entregable 12 y 13" << endl;
        cout << "0.-Salir. " << endl;
        cout << "\nPresione el numero de trabajo que desea: ";
        cin >> op;
        switch (op)
        {
            case 1:
                system(".\\entregable2\\EntregableDos.exe"); break;
            case 2:
                system(".\\entregable3\\EntregableTres.exe"); break;
            case 3:
                system(".\\entregable4\\EntregableCuatro.exe"); break;
            case 4:
                system(".\\entregable5-6y7\\EntregableCinco.exe"); break;
            case 5:
                system(".\\entregable8y9\\EntregableOcho.exe"); break;
            case 6:
                system(".\\entregable12y13\\EntregableDoce.exe"); break;
            case 0:
            default:
                cout << "Hasta pronto. " << endl; break;
        }
    }while (op!=0);
    return 0;
}
