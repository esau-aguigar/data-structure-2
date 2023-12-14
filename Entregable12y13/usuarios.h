#ifndef USUARIOS2_H_INCLUDED
#define USUARIOS2_H_INCLUDED

#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<cstring>
#define LIM 30
using namespace std;

class Usuario
{
public:
    char nombre[LIM],apellido[LIM],escuela[LIM],codigo[LIM];
    void agregar();
    void mostrar();
    void buscar();
    void modificar();
    void eliminar();
    void encriptar(char cadena[LIM]);
    void desencriptar(char cadena[LIM]);
}user;

int dim1,dim2,dim3,dim4,opc;

void Usuario::agregar()
{
    cout<<"Nombre: ";
    fflush(stdin);
    cin.getline(nombre,LIM);
    cout<<"Apellido: ";
    fflush(stdin);
    cin.getline(apellido,LIM);
    cout<<"Escuela: ";
    fflush(stdin);
    cin.getline(escuela,LIM);
    cout<<"Codigo: ";
    fflush(stdin);
    cin.getline(codigo,LIM);
    ofstream Usuarios("datos.txt",ios::app);
    dim1=strlen(nombre);
    dim2=strlen(apellido);
    dim3=strlen(escuela);
    dim4=strlen(codigo);
    Usuarios.write((char*)&dim1,sizeof(int));
    Usuarios.write((char*)&nombre,dim1);
    Usuarios.write((char*)&dim2,sizeof(int));
    Usuarios.write((char*)&apellido,dim2);
    Usuarios.write((char*)&dim3,sizeof(int));
    Usuarios.write((char*)&escuela,dim3);
    Usuarios.write((char*)&dim4,sizeof(int));
    Usuarios.write((char*)&codigo,dim4);
    user.encriptar(nombre);
    user.encriptar(apellido);
    user.encriptar(escuela);
    user.encriptar(codigo);
    Usuarios.close();
}

void Usuario::mostrar()
{
    ifstream Usuarios("datos.txt");
    if(!Usuarios.good())
    {
        cout<<"El archivo no existe"<<endl;
    }
    else
    {
        user.desencriptar(nombre);
        user.desencriptar(apellido);
        user.desencriptar(escuela);
        user.desencriptar(codigo);
        while(!Usuarios.eof())
        {
            Usuarios.read((char*)&dim1,sizeof(int));
            Usuarios.read((char*)&nombre,dim1);
            nombre[dim1]='\0';
            Usuarios.read((char*)&dim2,sizeof(int));
            Usuarios.read((char*)&apellido,dim2);
            apellido[dim2]='\0';
            Usuarios.read((char*)&dim3,sizeof(int));
            Usuarios.read((char*)&escuela,dim3);
            escuela[dim3]='\0';
            Usuarios.read((char*)&dim4,sizeof(int));
            Usuarios.read((char*)&codigo,dim4);
            codigo[dim4]='\0';
        }
    }
    user.encriptar(nombre);
    user.encriptar(apellido);
    user.encriptar(escuela);
    user.encriptar(codigo);
    Usuarios.close();
}

void Usuario::buscar()
{
    char busqueda[LIM];
    int band=0;

    ifstream Usuarios("datos.txt");
        if(!Usuarios.good())
        {
            cout<<"El archivo no existe"<<endl;
        }
        else
        {
            user.desencriptar(nombre);
            user.desencriptar(apellido);
            user.desencriptar(escuela);
            user.desencriptar(codigo);
            cout<<"Ingresa el codigo del alumno a buscar"<<endl;
            fflush(stdin);
            cin.getline(busqueda,LIM);
            while(!Usuarios.eof()&&!band)
            {
                Usuarios.read((char*)&dim1,sizeof(int));
                Usuarios.read((char*)&nombre,dim1);
                nombre[dim1]='\0';
                Usuarios.read((char*)&dim2,sizeof(int));
                Usuarios.read((char*)&apellido,dim2);
                apellido[dim2]='\0';
                Usuarios.read((char*)&dim3,sizeof(int));
                Usuarios.read((char*)&escuela,dim3);
                escuela[dim3]='\0';
                Usuarios.read((char*)&dim4,sizeof(int));
                Usuarios.read((char*)&codigo,dim4);
                codigo[dim4]='\0';

                if(strcmpi(busqueda,codigo)==0)
                {
                    cout<<nombre<<" "<<apellido<<endl<<escuela<<endl<<codigo<<endl;
                    band=1;
                }
            }
            if(!band)
                {
                    cout<<"Usuario no encontrado"<<endl;
                }
        }
        user.encriptar(nombre);
        user.encriptar(apellido);
        user.encriptar(escuela);
        user.encriptar(codigo);
        Usuarios.close();
}

void Usuario::modificar()
{
    char modif[LIM];
    int band=0;

    ifstream Usuarios("datos.txt");
    if(!Usuarios.good())
    {
        cout<<"El archivo no existe"<<endl;
    }
    else
    {
        user.desencriptar(nombre);
        user.desencriptar(apellido);
        user.desencriptar(escuela);
        user.desencriptar(codigo);
        cout<<"Escribe el codigo del usuario"<<endl;
        fflush(stdin);
        cin.getline(modif,LIM);

        while(!Usuarios.eof() && !band)
        {
            Usuarios.read((char*)&dim1,sizeof(int));
            Usuarios.read((char*)&nombre,dim1);
            nombre[dim1]='\0';
            Usuarios.read((char*)&dim2,sizeof(int));
            Usuarios.read((char*)&apellido,dim2);
            apellido[dim2]='\0';
            Usuarios.read((char*)&dim3,sizeof(int));
            Usuarios.read((char*)&escuela,dim3);
            escuela[dim3]='\0';
            Usuarios.read((char*)&dim4,sizeof(int));
            Usuarios.read((char*)&codigo,dim4);
            codigo[dim4]='\0';

            if(strcmpi(modif,codigo)==0)
            {
                cout<<"Datos actuales:"<<endl<<endl;
                cout<<"Nombre: "<<nombre<<"Apellido: "<<apellido<<"Escuela: "<<escuela<<"Codigo: "<<codigo<<endl<<endl;
                band=1;
                cout<<"En verdad desea modificar los datos del usuario?\n1)Si\n2)No"<<endl;
                cin>>opc;
            }
        }
        Usuarios.close();
        if(opc==1)
        {
                ifstream Usuarios("datos.txt");
                ofstream temporal("info.txt",ios::app);

                while(!Usuarios.eof())
                {
                    Usuarios.read((char*)&dim1,sizeof(int));
                    Usuarios.read((char*)&nombre,dim1);
                    nombre[dim1]='\0';
                    Usuarios.read((char*)&dim2,sizeof(int));
                    Usuarios.read((char*)&apellido,dim2);
                    apellido[dim2]='\0';
                    Usuarios.read((char*)&dim3,sizeof(int));
                    Usuarios.read((char*)&escuela,dim3);
                    escuela[dim3]='\0';
                    Usuarios.read((char*)&dim4,sizeof(int));
                    Usuarios.read((char*)&codigo,dim4);
                    codigo[dim4]='\0';

                    if(strcmpi(modif,codigo)==0)
                    {
                        cout<<"Escriba el nuevo nombre del usuario"<<endl;
                        fflush(stdin);
                        cin.getline(nombre,LIM);
                        cout<<"Escriba el nuevo apellido del usuario"<<endl;
                        fflush(stdin);
                        cin.getline(apellido,LIM);
                        cout<<"Escriba el nombre de la escuela del usuario"<<endl;
                        fflush(stdin);
                        cin.getline(escuela,LIM);
                        cout<<"Escriba el nuevo codigo del usuario"<<endl;
                        fflush(stdin);
                        cin.getline(codigo,LIM);
                        dim1=strlen(nombre);
                        dim2=strlen(apellido);
                        dim3=strlen(escuela);
                        dim4=strlen(codigo);
                    }
                    temporal.write((char*)&dim1,sizeof(int));
                    temporal.write((char*)&nombre,dim1);
                    temporal.write((char*)&dim2,sizeof(int));
                    temporal.write((char*)&apellido,dim2);
                    temporal.write((char*)&dim3,sizeof(int));
                    temporal.write((char*)&escuela,dim3);
                    temporal.write((char*)&dim4,sizeof(int));
                    temporal.write((char*)&codigo,dim4);
                }
                user.encriptar(nombre);
                user.encriptar(apellido);
                user.encriptar(escuela);
                user.encriptar(codigo);
                temporal.close();
                Usuarios.close();
                remove("datos.txt");
                rename("info.txt","datos.txt");
        }
    }
}

void Usuario::eliminar()
{
    char elim[LIM];
    int band=0;

    ifstream usuarios("datos.txt");
    if(!usuarios.eof())
    {
        cout<<"El archivo no existe"<<endl;
    }
    else
    {
        user.desencriptar(nombre);
        user.desencriptar(apellido);
        user.desencriptar(escuela);
        user.desencriptar(codigo);
        cout<<"Ingrese el codigo del usuario que desea eliminar"<<endl;
        fflush(stdin);
        cin.getline(elim,LIM);

        while(!usuarios.eof() && !band)
        {
            usuarios.read((char*)&dim1,sizeof(int));
            usuarios.read((char*)&nombre,dim1);
            nombre[dim1]='\0';
            usuarios.read((char*)&dim2,sizeof(int));
            usuarios.read((char*)&apellido,dim2);
            apellido[dim2]='\0';
            usuarios.read((char*)&dim3,sizeof(int));
            usuarios.read((char*)&escuela,dim3);
            escuela[dim3]='\0';
            usuarios.read((char*)&dim4,sizeof(int));
            usuarios.read((char*)&codigo,dim4);
            codigo[dim4]='\0';

            if(strcmpi(elim,codigo)==0)
            {
                cout<<"Datos actuales:"<<endl<<endl;
                cout<<"Nombre: "<<nombre<<"Apellido: "<<apellido<<"Escuela: "<<escuela<<"Codigo: "<<codigo<<endl<<endl;
                band=1;
                cout<<"En verdad desea eliminar los datos del usuario?\n1)Si\n2)No"<<endl;
                cin>>opc;
            }
        }
        usuarios.close();
        if(opc==1)
        {
                ifstream Usuarios("datos.txt");
                ofstream temporal("info.txt",ios::app);

                while(!Usuarios.eof())
                {
                    Usuarios.read((char*)&dim1,sizeof(int));
                    Usuarios.read((char*)&nombre,dim1);
                    nombre[dim1]='\0';
                    Usuarios.read((char*)&dim2,sizeof(int));
                    Usuarios.read((char*)&apellido,dim2);
                    apellido[dim2]='\0';
                    Usuarios.read((char*)&dim3,sizeof(int));
                    Usuarios.read((char*)&escuela,dim3);
                    escuela[dim3]='\0';
                    Usuarios.read((char*)&dim4,sizeof(int));
                    Usuarios.read((char*)&codigo,dim4);
                    codigo[dim4]='\0';

                    if(strcmpi(elim,codigo)!=0)
                    {
                        temporal.write((char*)&dim1,sizeof(int));
                        temporal.write((char*)&nombre,dim1);
                        temporal.write((char*)&dim2,sizeof(int));
                        temporal.write((char*)&apellido,dim2);
                        temporal.write((char*)&dim3,sizeof(int));
                        temporal.write((char*)&escuela,dim3);
                        temporal.write((char*)&dim4,sizeof(int));
                        temporal.write((char*)&codigo,dim4);
                    }
                }
                user.encriptar(nombre);
                user.encriptar(apellido);
                user.encriptar(escuela);
                user.encriptar(codigo);
                temporal.close();
                Usuarios.close();
                remove("datos.txt");
                rename("info.txt","datos.txt");
        }
    }
}

void Usuario::encriptar(char cadena[LIM])
{
    int contador=0,longitud,i=0;

    for(contador=0;contador<longitud;contador++)
    {
        if(isalpha(cadena[contador]))
        {
            cadena[contador]=tolower(cadena[contador]);
            for(i=0;i<13;i++)
            {
                if(cadena[contador]=='z')
                {
                    cadena[contador]='a';
                }
                else
                {
                    cadena[contador]++;
                }
            }
        }
    }
}

void Usuario::desencriptar(char cadena[LIM])
{
    int contador=0,longitud,i=0;

    for(contador=0;contador<longitud;contador++)
    {
        if(isalpha(cadena[contador]))
        {
            cadena[contador]=tolower(cadena[contador]);
            for(i=0;i<13;i++)
            {
                if(cadena[contador]=='a')
                {
                    cadena[contador]='z';
                }
                else
                {
                    cadena[contador]--;
                }
            }
        }
    }
}

#endif // USUARIOS2_H_INCLUDED
