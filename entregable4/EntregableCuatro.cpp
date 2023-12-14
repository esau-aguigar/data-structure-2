#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class pedidos
{
public:
    char cliente[10], producto[10], precio[35];
    void Capturar();
    void Modificar();
    void Mostrar();
}datos;

void pedidos::Capturar()
{
    cout<<"\ncliente: ";
    fflush(stdin);
    cin.getline(cliente,35);
    cout<<"producto: ";
    fflush(stdin);
    cin.getline(producto,10);
    cout<<"precio: ";
    fflush(stdin);
    cin.getline(precio,35);
    ofstream a("pedidos.txt",ios::app);
    a.write((char*)&datos,sizeof(datos));
    a.close();
}

void pedidos::Mostrar()
{
    char cliente2[10], producto2[10];
    int band=0;
    ifstream a("pedidos.txt");
    if(!a.good()){
        cout<<"\n NO EXISTE ARCHIVO.....";
    }
    else
    {
        while(!a.eof())
        {
            a.read((char*)&datos,sizeof(datos));
            if(a.eof()){
                break;
            }
            cout<<"\nCliente:"<<datos.cliente<<"\nProducto:"<<datos.producto<<"\nPrecio:"<<datos.precio<<endl;
        }
        a.close();
    }
}

int main()
{
    int opc;
    do
    {
        system("pause");
        system("cls");
        cout<<"\t\t\tPedidos\n";
        cout<<"\n1.- CAPTURAR \n2.- MOSTRAR \n0.- Salir \nOpcion:";
        cin>>opc;
        switch(opc)
        {
        case 1:
            datos.Capturar();
            break;
        case 2:
            datos.Mostrar();
            break;
        default:
            cout<<"Error Intentelo de nuevo...\n";
            break;
        case 0:
            cout<<"Hasta luego...\n";
            break;
        }
    }while(opc!=0);
    return 0;
}
