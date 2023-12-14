#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>

using namespace std;
    class producto
    {
        public:
        char codigo[35], presentacion[15], marca[15], precio[15];
        void Capturar();
        void Imprimir();
        void Buscar();
        void Eliminar();
    }objeto;

    void producto::Capturar()
    {
        cout<<"\ncodigo: ";
        fflush(stdin);
        cin.getline(codigo, 35);
        cout<<"\npresentacion: ";
        fflush(stdin);
        cin.getline(presentacion, 15);
        cout<<"\nmarca: ";
        fflush(stdin);
        cin.getline(marca, 15);
        cout<<"\nprecio: ";
        fflush(stdin);
        cin.getline(precio, 15);
        ofstream archivo("Productos.txt", ios::app);
        archivo<<codigo<<"|"<<presentacion<<"|"<<marca<<"|"<<precio<<"|";
        archivo.close();
    }

    void producto::Imprimir()
    {
        char ref[35], comp[35], prev[35];
        ifstream arc("Productos.txt");
        if(!arc.good())
        cout<<"\nEl archivo no existe";
        else
        {
            char c; int i;
            while(!arc.eof())
            {
                i=0;
                do
                {
                    arc.read((char*)&c, 1);
                    if(c!='|')
                    {
                        codigo[i]=c;
                        i++;
                    }
                }while(c!='|' && !arc.eof());
                codigo[i]='\0';
                i=0;
                do
                {
                    arc.read((char*)&c, 1);
                    if(c!='|')
                    {
                        presentacion[i]=c;
                        i++;
                    }
                }while(c!='|' && !arc.eof());
                presentacion[i]='\0';
                arc.getline(marca, 15, '|');
                arc.getline(precio, 15, '|');
                if(!arc.eof())
                cout<<"\ncodigo: "<<codigo<<"\npresentacion: "<<presentacion<<"\nmarca: "<<marca<<"\nprecio: "<<precio<<"\n";
            }
        }
        arc.close();
    }

    void producto::Buscar()
    {
        char ref[35], comp[35], prev[35];
        int band=1;
        cout<<"\nEscribe el codigo del producto a buscar \n";
        fflush(stdin);
        cin.getline(ref, 35);
        ifstream arc("Productos.txt");
        if(!arc.good())
        cout<<"\nEl archivo no existe";
        else
        {
            while(!arc.eof() && band==1)
            {
                arc.getline(prev, 35, '|');
                arc.getline(comp, 35, '|');
                if(strcmp(comp, ref)==0){
                    cout<<"\ncodigo: "<<prev;
                    cout<<"\npresentacion: "<<comp;
                    arc.getline(comp, 15, '|');
                    cout<<"\nmarca: "<<comp;
                    arc.getline(comp, 15, '|');
                    cout<<"\nprecio: "<<comp;
                    arc.getline(comp, 15, '|');
                    cout<<"\nLinea: "<<comp;
                    band=0;
                }
                else{
                    arc.getline(comp, 35, '|');
                    arc.getline(comp, 35, '|');
                    arc.getline(comp, 35, '|');
                }
            }
            if(band)
            cout<<"\nNo se encontro el producto";
        }
        arc.close();
    }

    void producto::Eliminar()
    {
        char ref[35], comp[35], prev[35];
        int band=1, op;
        cout<<"\nEscribe el presentacion del producto a eliminar \n";
        fflush(stdin);
        cin.getline(ref, 35);
        ifstream arc("Productos.txt");
        if(!arc.good())
        cout<<"\nEl archivo no existe";
        else
        {
            while(!arc.eof() && band)
            {
                arc.getline(prev, 35, '|');
                arc.getline(comp, 35, '|');
                if(strcmp(comp, ref)==0)
                {
                cout<<"\ncodigo: "<<prev<<"\npresentacion: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nmarca: "<<comp;
                arc.getline(comp, 15, '|');
                cout<<"\nprecio: "<<comp;
                arc.getline(comp, 15, '|');
                band=0;
                arc.close();
                cout<<"\nDesea eliminar este producto? \n1.Si \n2.No \n";
                cin>>op;
                    if(op==1)
                    {
                        cout<<"\nEsta seguro? \n1.Si \n2.No \n";
                        cin>>op;
                        if(op==1)
                        {
                            ifstream elim("Productos.txt");
                            ofstream nuevo("Temporal.txt", ios::app);
                            while(!elim.eof())
                            {
                                elim.getline(prev, 35, '|');
                                elim.getline(comp, 35, '|');
                                if(strcmp(comp, ref)!=0 && !elim.eof())
                                {
                                nuevo<<prev<<"|"<<comp<<"|";
                                elim.getline(comp, 15, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 15, '|');
                                nuevo<<comp<<"|";
                                elim.getline(comp, 15, '|');
                                nuevo<<comp<<"|";
                                }
                                else
                                {
                                    elim.getline(comp, 35, '|');
                                    elim.getline(comp, 15, '|');
                                    elim.getline(comp, 15, '|');
                                }
                            }
                        nuevo.close();
                        elim.close();
                        remove("Productos.txt");
                        rename("Temporal.txt", "Productos.txt");
                        }
                    }
                }
        }
        if(band)
        cout<<"\nNo se encontro el producto";
    }
    }

    int main()
    {
        int op;
        do
        {
            system("pause");
            system("cls");
            cout<<"\nIngresa el numero de la opcion: \n1.Capturar \n2.Imprimir todo \n3.Buscar \n4.Eliminar \n5.Salir \n";
            cin>>op;
            switch(op)
            {
                case 1:
                objeto.Capturar();
                break;
                case 2:
                objeto.Imprimir();
                break;
                case 3:
                objeto.Buscar();
                break;
                case 4:
                objeto.Eliminar();
                break;
            }
        }while(op!=5);
    return 0;
    }
