#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

class Usuario
{
public:
    char codigo[10], nombre[35], domicilio[35], tel[20];
void capturar();
void mostrar();
void buscar();
void modificar();
void eliminar();
void encriptar();
void desencriptar();
void menu();
};

void Usuario::encriptar()
{
    int z;
    int dim1, dim2,dim4, dim5;
    char cod[10], nom[35], dom[35], phone[20];

    ofstream a("datausu.txt", ios::app);

    dim1=strlen(codigo);
    a.write((char*)&dim1,sizeof(int));
    for(z=0; z<dim1; z++){
        cod[z]=codigo[z]^'|';
        a.write((char*)&cod[z],1);
    }

    dim2=strlen(nombre);
    a.write((char*)&dim2,sizeof(int));
    for(z=0; z<dim2; z++){
        nom[z]=nombre[z]^'|';
        a.write((char*)&nom[z],1);
    }

    dim4=strlen(domicilio);
    a.write((char*)&dim4,sizeof(int));
    for(z=0; z<dim4; z++)
    {
        dom[z]=domicilio[z]^'|';
        a.write((char*)&dom[z],1);
    }

    dim5=strlen(tel);
    a.write((char*)&dim5,sizeof(int));
    for(z=0; z<dim5; z++)
    {
        phone[z]=tel[z]^'|';
        a.write((char*)&phone[z],1);
    }
    a.close();
}

void Usuario::desencriptar()
{
    int z;
    int dim1, dim2, dim4, dim5;

    dim1=strlen(codigo);

    for(z=0; z<dim1; z++)
    {
        codigo[z]=codigo[z]^'|';
    }

    dim2=strlen(nombre);

    for(z=0; z<dim2; z++)
    {
        nombre[z]=nombre[z]^'|';
    }

    dim4=strlen(domicilio);

    for(z=0; z<dim4; z++)
    {
        domicilio[z]=domicilio[z]^'|';
    }

    dim5=strlen(tel);

    for(z=0; z<dim5; z++)
    {
        tel[z]=tel[z]^'|';
    }
}

void Usuario::capturar()
{
    cin.ignore();
    cout<<"Cliente:";
    cin.getline(codigo, 10);
    cout<<"Nombre:     ";
    cin.getline(nombre, 35);
    cout<<"Domicilio:";
    cin.getline(domicilio, 35);
    cout<<"Telefono:";
    cin.getline(tel, 20);
    cout<<endl;
    encriptar();
}

void Usuario::mostrar()
{
    int dim1, dim2, dim3, dim4, dim5, dim6, dim7;
    ifstream lectura("datausu.txt");
    if(!lectura.good()){
        cout << "No existe el archivo" << endl;
    }
    else{
        while(!lectura.eof())
        {
        lectura.read((char*)&dim1,sizeof(int));
        lectura.read((char*)&codigo,dim1);
        codigo[dim1]='\0';

        lectura.read((char*)&dim2,sizeof(int));
        lectura.read((char*)&nombre,dim2);
        nombre[dim2]='\0';

        lectura.read((char*)&dim4,sizeof(int));
        lectura.read((char*)&domicilio,dim4);
        domicilio[dim4]='\0';

        lectura.read((char*)&dim5,sizeof(int));
        lectura.read((char*)&tel,dim5);
        tel[dim5]='\0';

        if(lectura.eof())
            break;

            desencriptar();

        cout<<" Codigo:     "<<codigo<<endl
            <<" Nombre:     "<<nombre<<endl
            <<" Domicilio:  "<<domicilio<<endl
            <<" Telefeno:   "<<tel<<endl;
        }
    }
    lectura.close();
}

void Usuario::menu()
{
    char opc, continuar;
    do
    {
        system("cls");
        cout << "\t\tMENU PRINCIPAL" << endl;
        cout << "1. Agregar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "6. Salir" << endl;
        cout << "Numero Opcion:";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case '1':
            cout<<"Agregar"<<endl;
            capturar();
            system("pause");
            system("cls");
            break;
        case '2':
            cout << "MOSTRAR"<< endl;
            mostrar();
            system("pause");
            system("cls");
            break;
        case '0':
            exit(0);
            break;
        default:
            cout << "Error Intente d enuevo.." << endl;
            system("pause");
            system("cls");
        }
    }while(opc!='6');
}


int main()
{
    Usuario usr;

    usr.menu();

    return 0;
}
