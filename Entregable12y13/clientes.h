#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>

using namespace std;

class Cliente
{
    private:
    char codigoCliente[30];
    char nombreCliente[30];
    char apellidoCliente[30];
    char Direccion[30];
    char telefono[30];
    char tipoMembresia[30];
    public:
    void AgregarCliente();
    void MostrarCliente();
    void ModificarCliente();
    void EliminarCliente();
    void BuscarCliente();
    void Encriptar();
    void Desencriptar();
    void EncriptarAux();
};
void Cliente::EncriptarAux()
{
  int a,b,c,d,e,f,i;
   a=strlen(codigoCliente);
   b=strlen(nombreCliente);
   c=strlen(apellidoCliente);
   d=strlen(Direccion);
   e=strlen(telefono);
   f=strlen(tipoMembresia);
   char sep='|';
   ofstream File("AuxClientes.txt",ios::app);
   for(i=0;i<a;i++)
   {
       codigoCliente[i]=codigoCliente[i]^'x';
       File.write((char *)&codigoCliente[i],1);

   }
   File.write((char *)&sep,1);

   for(i=0;i<b;i++)
   {
       nombreCliente[i]=nombreCliente[i]^'x';
       File.write((char *)&nombreCliente[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<c;i++)
   {
       apellidoCliente[i]=apellidoCliente[i]^'x';
       File.write((char *)&apellidoCliente[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<d;i++)
   {
       Direccion[i]=Direccion[i]^'x';
       File.write((char *)&Direccion[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<e;i++)
   {
       telefono[i]=telefono[i]^'x';
       File.write((char *)&telefono[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<f;i++)
   {
       tipoMembresia[i]=tipoMembresia[i]^'x';
       File.write((char *)&tipoMembresia[i],1);

   }
   File.write((char *)&sep,1);
   File.close();
}
void Cliente::Encriptar()
{
   int a,b,c,d,e,f,i;
   a=strlen(codigoCliente);
   b=strlen(nombreCliente);
   c=strlen(apellidoCliente);
   d=strlen(Direccion);
   e=strlen(telefono);
   f=strlen(tipoMembresia);
   char sep='|';
   ofstream File("Clientes.txt",ios::app);
   for(i=0;i<a;i++)
   {
       codigoCliente[i]=codigoCliente[i]^'x';
       File.write((char *)&codigoCliente[i],1);

   }
   File.write((char *)&sep,1);

   for(i=0;i<b;i++)
   {
       nombreCliente[i]=nombreCliente[i]^'x';
       File.write((char *)&nombreCliente[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<c;i++)
   {
       apellidoCliente[i]=apellidoCliente[i]^'x';
       File.write((char *)&apellidoCliente[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<d;i++)
   {
       Direccion[i]=Direccion[i]^'x';
       File.write((char *)&Direccion[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<e;i++)
   {
       telefono[i]=telefono[i]^'x';
       File.write((char *)&telefono[i],1);

   }
   File.write((char *)&sep,1);
   for(i=0;i<f;i++)
   {
       tipoMembresia[i]=tipoMembresia[i]^'x';
       File.write((char *)&tipoMembresia[i],1);

   }
   File.write((char *)&sep,1);
   File.close();

}
void Cliente::Desencriptar()
{
   int a,b,c,d,e,f,i;
   a=strlen(codigoCliente);
   b=strlen(nombreCliente);
   c=strlen(apellidoCliente);
   d=strlen(Direccion);
   e=strlen(telefono);
   f=strlen(tipoMembresia);
   for(i=0;i<a;i++)
   {
       codigoCliente[i]=codigoCliente[i]^'x';

   }
   for(i=0;i<b;i++)
   {
       nombreCliente[i]=nombreCliente[i]^'x';
   }

   for(i=0;i<c;i++)
   {
       apellidoCliente[i]=apellidoCliente[i]^'x';
   }
   for(i=0;i<d;i++)
   {
       Direccion[i]=Direccion[i]^'x';
   }
   for(i=0;i<e;i++)
   {
       telefono[i]=telefono[i]^'x';
   }
   for(i=0;i<f;i++)
   {
       tipoMembresia[i]=tipoMembresia[i]^'x';
   }

}
void Cliente::AgregarCliente()
{
   cout<<"Codigo del Cliente: ";
   fflush(stdin);
   cin.getline(codigoCliente,30);
   cout<<"Nombre del Cliente: ";
   cin.getline(nombreCliente,30);
   cout<<"Apellido del Cliente: ";
   cin.getline(apellidoCliente,30);
   cout<<"Direccion: ";
   cin.getline(Direccion,30);
   cout<<"Telefono: ";
   cin.getline(telefono,30);
   cout<<"Tipo de Membresia: ";
   cin.getline(tipoMembresia,30);
   Encriptar();
}

void Cliente::MostrarCliente()
{
    ifstream fileRead("Clientes.txt");
    int i;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(codigoCliente[i-1]!='|');
            codigoCliente[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&nombreCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(nombreCliente[i-1]!='|');
            nombreCliente[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&apellidoCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(apellidoCliente[i-1]!='|');
            apellidoCliente[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&Direccion[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(Direccion[i-1]!='|');
            Direccion[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&telefono[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(tipoMembresia[i-1]!='|');
            tipoMembresia[i-1]='\0';

            if(fileRead.eof())
                break;

            Desencriptar();
            cout<<"Codigo del cliente: "<<codigoCliente<<endl;
            cout<<"Nombre del Cliente: "<<nombreCliente<<endl;
            cout<<"Apellido del Cliente: "<<apellidoCliente<<endl;
            cout<<"Direccion: "<<Direccion<<endl;
            cout<<"Telefono: "<<telefono<<endl;
            cout<<"Tipo de Membresia: "<<tipoMembresia<<endl;
            cout<<"_______________________________________________________________________________"<<endl;

        }
    }
    fileRead.close();

}

void Cliente::ModificarCliente()
{
    ifstream fileRead("Clientes.txt");
    int i;
    string comparaCodigo;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el codigo del Cliente a Modificar: ";
        fflush(stdin);
        getline(cin,comparaCodigo);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(codigoCliente[i-1]!='|');
            codigoCliente[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&nombreCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(nombreCliente[i-1]!='|');
            nombreCliente[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&apellidoCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(apellidoCliente[i-1]!='|');
            apellidoCliente[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&Direccion[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(Direccion[i-1]!='|');
            Direccion[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&telefono[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(tipoMembresia[i-1]!='|');
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;
            Desencriptar();
            if(comparaCodigo==codigoCliente)
            {
               cout<<"Codigo del Cliente: ";
               fflush(stdin);
               cin.getline(codigoCliente,30);
               cout<<"Nombre del Cliente: ";
               cin.getline(nombreCliente,30);
               cout<<"Apellido del Cliente: ";
               cin.getline(apellidoCliente,30);
               cout<<"Direccion: ";
               cin.getline(Direccion,30);
               cout<<"Telefono: ";
               cin.getline(telefono,30);
               cout<<"Tipo de Membresia: ";
               cin.getline(tipoMembresia,30);
               EncriptarAux();

            }
            else
            {
                EncriptarAux();
            }


        }
    }
    fileRead.close();
    remove ("Clientes.txt");
    rename("AuxClientes.txt","Clientes.txt");
}

void Cliente::EliminarCliente()
{
     ifstream fileRead("Clientes.txt");
    int i;
    string comparaCodigo;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el codigo del Cliente a Eliminar: ";
        fflush(stdin);
        getline(cin,comparaCodigo);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(codigoCliente[i-1]!='|');
            codigoCliente[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&nombreCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(nombreCliente[i-1]!='|');
            nombreCliente[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&apellidoCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(apellidoCliente[i-1]!='|');
            apellidoCliente[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&Direccion[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(Direccion[i-1]!='|');
            Direccion[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&telefono[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(tipoMembresia[i-1]!='|');
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;
            Desencriptar();
            if(comparaCodigo==codigoCliente)
            {
               cout<<"Codigo del cliente: "<<codigoCliente<<endl;
               cout<<"Nombre del Cliente: "<<nombreCliente<<endl;
               cout<<"Apellido del Cliente: "<<apellidoCliente<<endl;
               cout<<"Direccion: "<<Direccion<<endl;
               cout<<"Telefono: "<<telefono<<endl;
               cout<<"Tipo de Membresia: "<<tipoMembresia<<endl<<endl;

               cout<<"ELIMINANDO REGISTRO.....LISTO "<<endl;

            }
            else
            {
                EncriptarAux();
            }


        }
    }
    fileRead.close();
    remove ("Clientes.txt");
    rename("AuxClientes.txt","Clientes.txt");
}

void Cliente::BuscarCliente()
{
     ifstream fileRead("Clientes.txt");
    int i;
    string comparaCodigo;
    if(!fileRead.good())
        cout<<"No existe el Archivo "<<endl;
    else
    {
        cout<<"Dame el codigo del Cliente a Modificar: ";
        fflush(stdin);
        getline(cin,comparaCodigo);
        while(!fileRead.eof())
        {
            i=0;
            do
            {
                fileRead.read((char *)&codigoCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(codigoCliente[i-1]!='|');
            codigoCliente[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&nombreCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(nombreCliente[i-1]!='|');
            nombreCliente[i-1]='\0';
            if(fileRead.eof())
                break;

             i=0;
            do
            {
                fileRead.read((char *)&apellidoCliente[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(apellidoCliente[i-1]!='|');
            apellidoCliente[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&Direccion[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(Direccion[i-1]!='|');
            Direccion[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&telefono[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(telefono[i-1]!='|');
            telefono[i-1]='\0';
            if(fileRead.eof())
                break;
             i=0;
            do
            {
                fileRead.read((char *)&tipoMembresia[i],1);
                if(fileRead.eof())
                    break;
                i++;
            }while(tipoMembresia[i-1]!='|');
            tipoMembresia[i-1]='\0';
            if(fileRead.eof())
                break;
            Desencriptar();
            if(comparaCodigo==codigoCliente)
            {

               cout<<"Codigo del cliente: "<<codigoCliente<<endl;
               cout<<"Nombre del Cliente: "<<nombreCliente<<endl;
               cout<<"Apellido del Cliente: "<<apellidoCliente<<endl;
               cout<<"Direccion: "<<Direccion<<endl;
               cout<<"Telefono: "<<telefono<<endl;
               cout<<"Tipo de Membresia: "<<tipoMembresia<<endl<<endl;
            }


        }
    }
    fileRead.close();
}


#endif // CLIENTES_H_INCLUDED
