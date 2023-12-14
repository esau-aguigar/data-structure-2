#include <stdlib.h>
#include "iostream"
#include "fstream"
#include "cstring"

using namespace std;


class Clientes
{
    public:
        char cliente[10], nombre[35], rfc[15];

    void Agregar();
    void Mostrar();
    void Modificar();
    void Eliminar();
    void Buscar();
    void menu();
}pr;

int dim1, dim2, dim3, opc = 0;


void Clientes::Agregar()
{
    cout<<"Cliente: ";
    fflush(stdin);
    cin.getline(cliente, 10);
    cout<<"Nombre: ";
    fflush(stdin);
    cin.getline(nombre,35);
    cout<<"RFC: ";
    fflush(stdin);
    cin.getline(rfc,15);
    ofstream Archivo("Clientes.txt",ios::app);
    dim1 = strlen(cliente);
    dim2 = strlen(nombre);
    dim3 = strlen(rfc);
    Archivo.write((char*)&dim1, sizeof(int));
    Archivo.write((char*)&cliente, dim1);
    Archivo.write((char*)&dim2, sizeof(int));
    Archivo.write((char*)&nombre, dim2);
    Archivo.write((char*)&dim3, sizeof(int));
    Archivo.write((char*)&rfc, dim3);

    Archivo.close();

}
void Clientes::Mostrar()
{
    system("cls");

    ifstream archivo("Clientes.txt");
    if(!archivo.good()){
        cout<<"\nEl archivo no existe...";
    }
    else{
        while(!archivo.eof()){
            archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tama�o de la cadena que se quiere leer
            archivo.read((char*)&cliente, dim1);
            cliente[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&nombre, dim2);
            nombre[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&rfc, dim3);
            rfc[dim3] = '\0';
            cout << cliente << "  " << nombre << "  " << rfc << endl;
        }
    }
    archivo.close();
}


void Clientes::Modificar()
{
    int band = 0;
    char cliente2[10];

    ifstream archivo("Clientes.txt");
    if(!archivo.good()){
            cout<<"\nEl archivo no existe...";
    }
    else
    {
        cout << "Cliente: ";
        cin.getline(cliente2, 10);
        cin.getline(cliente2, 10);
        while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&cliente, dim1);
            cliente[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&nombre, dim2);
            nombre[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&rfc, dim3);
            rfc[dim3] = '\0';

            if(strcmp(cliente2, cliente) == 0)
            {
                cout << cliente << "  " << nombre << "  " << rfc << endl;
                band = 1;
                cout<<"DESEA MODIFICAR?\n1.SI\n0.NO\n>: ";
                cin>>opc;
            }//condicion

        }   //ciclo
    archivo.close();

    if(opc == 1)
    {
        ifstream archivo("Clientes.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&cliente, dim1);
            cliente[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&nombre, dim2);
            nombre[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&rfc, dim3);
            rfc[dim3] = '\0';

            if(strcmp(cliente2, cliente) == 0)
            {
                cout<<"Cliente: ";
                cin.getline(cliente, 10);
                cin.getline(cliente, 10);
                cout<<"Nombre: ";
                cin.getline(nombre,35);
                cout<<"RFC: ";
                cin.getline(rfc,15);
                dim1 = strlen(cliente);
                dim2 = strlen(nombre);
                dim3 = strlen(rfc);
            }//condicion
            temporal.write((char*)&dim1, sizeof(int));
            temporal.write((char*)&cliente, dim1);
            temporal.write((char*)&dim2, sizeof(int));
            temporal.write((char*)&nombre, dim2);
            temporal.write((char*)&dim3, sizeof(int));
            temporal.write((char*)&rfc, dim3);
        }//ciclo while

    temporal.close();
    archivo.close();
    remove("Clientes.txt");
    rename("temporal.txt", "Clientes.txt");
    }//condicional de la opcion

    }// else

}

void Clientes::Eliminar()
{
int band = 0;
    char cliente2[10];

    ifstream archivo("Clientes.txt");
    if(!archivo.good()){
            cout<<"\nEl archivo no existe...";
    }
    else
    {
        cout << "cliente QUE QUIERES ELIMINAR: ";
        cin.getline(cliente2, 10);
        cin.getline(cliente2, 10);
        while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&cliente, dim1);
            cliente[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&nombre, dim2);
            nombre[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&rfc, dim3);
            rfc[dim3] = '\0';

            if(strcmp(cliente2, cliente) == 0)
            {
                cout << cliente << "  " << nombre << "  " << rfc << endl;
                band = 1;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opc;
            }//condicion

        }   //ciclo
    archivo.close();

    if(opc == 1)
    {
        ifstream archivo("Clientes.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&cliente, dim1);
            cliente[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&nombre, dim2);
            nombre[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&rfc, dim3);
            rfc[dim3] = '\0';

            if(strcmp(cliente2, cliente) != 0)
            {
                temporal.write((char*)&dim1, sizeof(int));
                temporal.write((char*)&cliente, dim1);
                temporal.write((char*)&dim2, sizeof(int));
                temporal.write((char*)&nombre, dim2);
                temporal.write((char*)&dim3, sizeof(int));
                temporal.write((char*)&rfc, dim3);
            }//condicion

        }//ciclo while

    temporal.close();
    archivo.close();
    remove("Clientes.txt");
    rename("temporal.txt", "Clientes.txt");
    }//condicional de la opcion

    }//

}

void Clientes::Buscar()
{
    char cliente2[10];
    int band = 0;
    system("cls");

    ifstream archivo("Clientes.txt");
    if(!archivo.good()){
        cout<<"\nEl archivo no existe...";
    }
    else{
        cout << "Cliente: ";
        cin.getline(cliente2, 10);
        cin.getline(cliente2, 10);
        while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tama�o de la cadena que se quiere leer
            archivo.read((char*)&cliente, dim1);
            cliente[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&nombre, dim2);
            nombre[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&rfc, dim3);
            rfc[dim3] = '\0';
            if( strcmpi(cliente2, cliente) == 0)
            {
                cout << cliente << "  " << nombre << "  " << rfc << endl;
                band = 1;
            }
        }
        if (!band)
            cout << "NO SE ENCUENTRA EL PRODUCTO..." << endl;
    }
    archivo.close();
}
int main()
{
    //if(band == 1) {
    cout<<"\n\n\t\tClientes\n\n";
    do{
        system("pause");
        system("cls");
        cout<<"\n\tSELECCIONE LA OPCION DESEADA\n1.- AGREGAR\n2.- MOSTRAR\n3.- BUSCAR\n4.- MODIFICAR\n5.- ELIMINAR\n6.- SALIR\n>: ";
        cin>>opc;
        switch(opc) {
          case 1:
            pr.Agregar();
            break;
          case 2:
            pr.Mostrar();
            break;
          case 3:
            pr.Buscar();
            break;
          case 4:
            pr.Modificar();
            //empleado.Datos();
            break;
          case 5:
            pr.Eliminar();
            break;
          case 6:
            cout << "Hasta Pronto...."<<endl;
            break;
          default:
            cout << "OPCION INCORRECTA...."<<endl;
        }
        system("Pause");
    }while(opc != 6);
}
