#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Sucursal{
    public:
    char nombre[35], domicilio[45], responsable[45];
    void generachivo();
    void dispersion();
    void capturar();
    void mostrar();
    void modificar();
}suc;

char llave[35];
long int d_base, pos;
int cont=0;

void Sucursal::dispersion(){
int j=0;
d_base=0;
while(j<strlen(llave))
{
    d_base=d_base+(100*llave[j])+(llave[j+1]%84645);
    j=j+2;
}
d_base=d_base%100;
}

void Sucursal::generachivo()
{
    int j,i;
    ofstream achivo("dispersa.txt",ios::app);
    for(i=0;i<100;i++)
    {
        achivo.write((char*)&cont,sizeof(int));
        for(j=0;j<4;j++){
        achivo.write((char*)&suc,sizeof(suc));
        }
    }
    achivo.close();
}

void Sucursal::capturar()
{
    long int ausuc,ausuc2;
    cout<<"Dame el nombre:";
    fflush(stdin);
    cin.getline(nombre,35);
    cout<<"Dame el domicilio:";
    cin.getline(domicilio,45);
    cout<<"dame el responsable a asignar:";
    cin.getline(responsable,45);
    strcpy(llave,nombre);
    dispersion();
    ausuc=d_base;
    fstream b("dispersa.txt",ios::in|ios::out);
    d_base=d_base*((sizeof(suc)*4)+sizeof(int));
    b.seekg(d_base,ios::beg);
    b.read((char*)&cont,sizeof(int));
    cout<<"CONTADOR"<<cont<<endl;
    system("pause");
    if(cont==4){
    cout<<"NO HAY ESPACIO PARA ESTA LLAVE"<<endl;}
    else{
    pos=d_base+(cont*sizeof(suc))+sizeof(int);
    ausuc2=pos;
    b.seekp(pos,ios::beg);
    b.write((char*)&suc,sizeof(suc));
    cont++;
    pos=d_base;
    b.seekp(pos,ios::beg);
    b.write((char*)&cont,sizeof(int));
    cout<<"Contador:"<<cont<<" De la llave, y la direccion es: "<<ausuc2<<" Su distancia base fue: "<<ausuc<<endl;
    system("pause");
    }
    b.close();
}

void Sucursal::mostrar()
{
    int i;
    pos=0;
    ifstream achivo("dispersa.txt");
    if(!achivo.good())
    cout<<"No esuciste el archivo";
    else{
    while(!achivo.eof())
    {
        achivo.seekg(pos,ios::beg);
        achivo.read((char*)&cont,sizeof(int));
        if(cont==0){
        pos=pos+(4*sizeof(suc))+sizeof(int);
        }else{
            for(i=0;i<cont;i++)
            {
                achivo.read((char*)&suc,sizeof(suc));
                cout<<"Nombre: "<<nombre<<endl<<"domicilio: "<<domicilio<<endl<<"responsable:"<<responsable<<endl<<endl;
            }
            pos=pos+(4*sizeof(suc))+sizeof(int);
        }
    }
    }
    achivo.close();
}


void Sucursal::modificar()
{
    int i,band=0,opc,posanterior;
    cout<<"Dame el nombre del registro que deseas modificar"<<endl;
    cin.getline(llave,35);
    fstream achivo("dispersa.txt",ios::in|ios::out);
    if(!achivo.good()){
    cout<<"No se encontro el archivo, D:"<<endl;
    }
    else{
        dispersion();
        cout<<"BASE: "<<d_base;
        d_base=d_base*((sizeof(suc)*4)+sizeof(int));
        achivo.seekg(d_base,ios::beg);
        achivo.read((char*)&cont,sizeof(int));
        for(i=0;i<cont;i++){
            achivo.read((char*)&suc,sizeof(suc));
            if(strcmpi(llave,nombre)==0){
                band=1;
                do{
                cout<<"Que desea modificar? \n1.-Nombre"<<endl
                <<"2.-domicilio"<<endl
                <<"3.-responsable"<<endl
                <<"4.-CANCELAR"<<endl
                <<"Opcion:";
                cin>>opc;
                switch(opc){
                case 1:
                Sucursal ausuc;
                posanterior=achivo.tellg();
                posanterior=posanterior-sizeof(suc);
                pos=cont-i+1;
                pos=pos*sizeof(suc);
                pos=pos+achivo.tellg();
                pos=pos-sizeof(suc);
                achivo.seekg(pos,ios::beg);
                achivo.read((char*)&ausuc,sizeof(ausuc));
                achivo.seekp(posanterior,ios::beg);
                achivo.write((char*)&ausuc,sizeof(ausuc));
                cont--;
                achivo.seekp(d_base,ios::beg);
                achivo.write((char*)&cont,sizeof(int));
                /////
                cout<<"Dame el nombre"<<endl;
                fflush(stdin);
                cin.getline(suc.nombre,35);
                strcpy(llave,suc.nombre);
                dispersion();
                d_base=d_base*((sizeof(suc)*4)+sizeof(int));
                achivo.seekg(d_base,ios::beg);
                achivo.read((char*)&cont,sizeof(int));
                if(cont==4){
                cout<<"NO HAY ESPACIO PARA ESTA LLAVE"<<endl;}
                else{
                pos=d_base+(cont*sizeof(suc))+sizeof(int);
                achivo.seekp(pos,ios::beg);
                achivo.write((char*)&suc,sizeof(suc));
                cont++;
                pos=d_base;
                achivo.seekp(pos,ios::beg);
                achivo.write((char*)&cont,sizeof(int));
                }
                break;

                case 2:
                fflush(stdin);
                cout<<"Dame el nuevo domicilio"<<endl;
                cin.getline(domicilio,45);
                pos=achivo.tellp();
                pos=pos-sizeof(suc);
                achivo.seekp(pos,ios::beg);
                achivo.write((char*)&suc,sizeof(suc));
                break;

                case 3:
                fflush(stdin);
                cout<<"Dame el nuevo responsable"<<endl;
                cin.getline(responsable,45);
                pos=achivo.tellp();
                pos=pos-sizeof(suc);
                achivo.seekp(pos,ios::beg);
                achivo.write((char*)&suc,sizeof(suc));
                break;


                case 4:
                cout<<"No se modifico nada";

                default:
                cout<<"OPCION INVALIDA";

                }
                }while(opc<=0 || opc>4);
                }//fin IF
            }
        if(band==0)
        cout<<"No se encontro el registro, intente de nuevo";
    }
    achivo.close();
}



int main(){
    int h=0,opc;
    ifstream achivo("dispersa.txt");
    if(achivo.good())
    h=1;
    achivo.close();
    if(h==0)
    suc.generachivo();
    do{
        system("pause");
        system("CLS");
        cout<<"\t\t\tSucursales\n"<<"1.-Agregar\n"<<"2.-Mostrar\n"<<"3.-Modificar\n"<<"4.-Salir\nOpcion:";
        cin>>opc;
        fflush(stdin);
        switch(opc)
        {
        case 1:
            suc.capturar(); break;
        case 2:
            suc.mostrar(); break;
        case 3:
            suc.modificar(); break;
        case 4:
            cout<<"Hasta luego..\n"<<endl;
        default:
            cout<<"Error intente de nuevo..\n"<<endl;
        }
    }while(opc!=4);
}
