#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;
int orden=0;

class Empleado
{
    public:
    char rfc[14], nombre[35], direccion[40];
    char sueldo[20],turno[20],puesto[20];
    void capturar();
    void buscar();
    void mostrar();
    void Modificar();
    void Eliminar();
    void Mostrar_Indice();
    void Orden();
}emp;

class Indice
{
    public:
    char rfc[14];
    long int pos;

}y;

void Empleado::mostrar()
{
    ifstream a("datos.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&emp,sizeof(emp));
            if(a.eof())
                break;
            cout<<"RFC:"<<emp.rfc<<endl<<"Nombre: "<<emp.nombre<<endl<<"Direccion: "<<emp.direccion<<endl<<"sueldo:"<<emp.sueldo<<endl<<"turno:"<<emp.turno<<endl<<"puesto:"<<puesto<<endl;
        }
    }
    a.close();
}

void Empleado::Mostrar_Indice()
{
  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No eempiste el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&y,sizeof(y));
            if(a.eof())
                break;
            cout<<"RFC:"<<y.rfc<<endl<<endl;
        }
    }
    a.close();
}




void Empleado::capturar()
{
    fflush(stdin);
    cout<<"RFC:";
    fflush(stdin);
    cin.getline(rfc,14);
    cout<<"Empleado:";
    fflush(stdin);
    cin.getline(nombre,35);
    cout<<"Dame la direccion:";
    fflush(stdin);
    cin.getline(direccion,40);
    cout<<"Sueldo:";
    fflush(stdin);
    cin.getline(sueldo,20);
    cout<<"Turno:";
    fflush(stdin);
    cin.getline(turno,20);
    cout<<"Puesto:";
    cin.getline(puesto,20);
    ofstream a("datos.txt",ios::app);
    a.write((char*)&emp,sizeof(emp));
    y.pos=a.tellp();
    y.pos-=sizeof(emp);
    a.close();
    strcpy(y.rfc,rfc);
    ofstream b("indice.txt",ios::app);
    b.write((char*)&y,sizeof(y));
    b.close();
    orden++;
}

void Empleado::buscar()
{
    char rfcbus[14];
    int band=0;
    //cout<<"posicion "<<y.pos;
    ifstream b("indice.txt");
    if(!b.good()){
    cout<<"No eempiste el archivo";}
    else{
    cout<<"\nRFC a buscar!"<<endl;
    fflush(stdin);cin.getline(rfcbus,14);
    while(!b.eof())
    {
        b.read((char*)&y,sizeof(y));
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfcbus)==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);
            a.read((char*)&emp,sizeof(emp));
            cout<<"RFC:"<<emp.rfc<<endl<<"Nombre: "<<emp.nombre<<endl<<"Direccion: "<<emp.direccion<<endl<<"sueldo:"<<emp.sueldo<<endl<<"turno:"<<emp.turno<<endl<<"puesto:"<<puesto<<endl;
            a.close();
            band=1;
            break;
        }
    }
    if(band==0)
    {
     cout<<"\n NO EXISTE REGISTRO....."   ;
    }
    }
    b.close();

}

void Empleado::Modificar()
{
     char rfcmod[15];
     int band=0;
     int opc;
     ifstream b("indice.txt");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"\nRFC a modificar!"<<endl;
     fflush(stdin);cin.getline(rfcmod,14);
     while(!b.eof())
    {   opc=0;
        b.read((char*)&y,sizeof(y));
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfcmod)==0 && band==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);

             a.read((char*)&emp,sizeof(emp));
             if(a.eof())   break;
            cout<<"RFC:"<<emp.rfc<<endl<<"Nombre: "<<emp.nombre<<endl<<"Direccion: "<<emp.direccion<<endl<<"sueldo:"<<emp.sueldo<<endl<<"turno:"<<emp.turno<<endl<<"puesto:"<<puesto<<endl;
            cout<<"Deseas modificarlo\n"<<"1.-Si   2.-No\nOpcion:"; cin>>opc;
            band=1;
            a.close();
            break;
         }//if de comparacion
         }//while
         b.close();
         if(opc==1)
{
    fflush(stdin);
    ifstream indice("indice.txt");
    ifstream datos("datos.txt");
          while(!indice.eof())
         {cout<<"entro al ciclo\n";
          indice.read((char*)&y,sizeof(y));
          cout<<"\nrfc:"<<y.rfc<<"\n";
          datos.read((char*)&emp,sizeof(emp));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfcmod)==0){
            cout<<"RFC:"<<endl;
            cin.getline(rfc,14);
            cout<<"Empleado"<<endl;
            cin.getline(nombre,35);
            cout<<"direccion "<<endl;
            cin.getline(direccion,40);
            cout<<"sueldo"<<endl;
            cin.getline(sueldo,20);
            cout<<"turno"<<endl;
            cin.getline(turno,20);
            fflush(stdin);
            cout<<"puesto"<<endl;
            cin.getline(puesto,20);
        }

          ofstream c("temp.txt",ios::app);
          c.write((char*)&emp,sizeof(emp));

        strcpy(y.rfc,rfc);
        ofstream d("tempind.txt",ios::app);
        d.write((char*)&y,sizeof(y));
        d.close();
        c.close();

        }//while archivo



}

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}

    }//else


    remove("indice.txt"); rename("tempind.txt","indice.txt");
    remove("datos.txt");  rename("temp.txt","datos.txt");


}

void Empleado::Eliminar()
{
 char rfceli[15];
     int band=0;
     int opc,cont=0,cont2=0;
     ifstream b("indice.txt");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"\nRFC a eliminar!"<<endl;
     fflush(stdin);cin.getline(rfceli,14);
     while(!b.eof())
    {
        b.read((char*)&y,sizeof(y));
        cont++;
            cout<<"contador --"<<cont;
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfceli)==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);
            a.read((char*)&emp,sizeof(emp));
             if(a.eof())   break;

            cout<<"RFC:"<<emp.rfc<<endl<<"Nombre:"<<emp.nombre<<endl<<"Direccion:"<<emp.direccion<<endl<<"sueldo:"<<emp.sueldo<<endl<<"turno:"<<emp.turno<<endl<<"puesto:"<<puesto<<endl;
            cout<<"Deseas eliminar\n"<<"1.-Si   2.-No"; cin>>opc;
            band=1;
           a.close();
             break;
         }//if de comparacion

         }//while
        b.close();
         cout<<"salio--";

         if(opc==1)
         {cout<<"entro al si\n";
          ifstream indice("indice.txt");
          ifstream datos("datos.txt");
          while(!indice.eof())
         {cout<<"entro al ciclo\n";
          indice.read((char*)&y,sizeof(y));
          cout<<"\nrfc:"<<y.rfc<<"\n";
          datos.read((char*)&emp,sizeof(emp));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(y.rfc,rfceli))
        {cont2++; cout<<"contador de if es "<<cont2;


          cout<<"nombre escrito es "<<emp.nombre;
          ofstream c("temp.txt",ios::app);
          c.write((char*)&emp,sizeof(emp));

        strcpy(y.rfc,rfc);
        ofstream d("tempind.txt",ios::app);
        d.write((char*)&y,sizeof(y));
        d.close();
        c.close();
        }
        }//while archivo
       indice.close();
       datos.close();
       remove("indice.txt"); rename("tempind.txt","indice.txt");
    remove("datos.txt");  rename("temp.txt","datos.txt");
        }//if
        else
        {

        }

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}

    }//else


}

void Empleado::Orden()
{int i=0;
char indice[20][14];
char auemp[20];

  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No eempiste el archivo";
    else
    {cout<<"else";
        while(!a.eof())
        {
            a.read((char*)&y,sizeof(y));
            if(a.eof())
                break;

                char *cadena=y.rfc;
                strcpy(indice[i],cadena);

                i++;
        }
    }
    a.close();

    for(int i=0;i<orden-1;i++)
for(int j=i+1;j<orden;j++)
if(strcmp(indice[i],indice[j])>0)
{
strcpy(auemp,indice[j]);
strcpy(indice[j],indice[i]);
strcpy(indice[i],auemp);
system("cls");}
for(int i=0;i<orden;i++)
{

strcpy(y.rfc,indice[i]);

ofstream a("tempind.txt",ios::app);
a.write((char*)&y,sizeof(y));
a.close();
}

 remove("indice.txt");
 rename("tempind.txt","indice.txt");

}



int main()
{
    int opc;
    do{
        system("pause");
        system("cls");
        cout<<"Empleados\n"<<"1.-Capturar\n"<<"2.-Buscar\n"<<"3.-Mostrar todos\n";
        cout<<"4.-Modificar\n"<<"5.-Eliminar\n"<<"6.-Mostrar Indice\n"<<"7-.Ordenar Indice\n";
        cout<<"8.-Salir\n"<<"Opcion:";
        cin>>opc;
        switch(opc)
        {
        case 1:
            emp.capturar(); break;
        case 2:
            emp.buscar(); break;
        case 3:
            emp.mostrar(); break;
        case 4:
            emp.Modificar(); break;
        case 5:
            emp.Eliminar(); break;
        case 6:
            emp.Mostrar_Indice(); break;
        case 7:
            emp.Orden(); break;
        case 8:
            cout<<"Hasta Luego.. \n";
            break;
        default:
            cout<<"Error inentelo de nuevo... \n";
            break;
        }
    }while(opc!=8);
    return 0;
}
