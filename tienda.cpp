#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

struct usuario{
	char nombre[3][30];
	float saldo;
	float comprar;
	int code;
};

struct tiendaOnline{
	
	char producto[30];
	int NumProducto[10];
	float costo;
	int codigo;
	struct usuario usu;	
};

void menu();

int main()
{
	int opcion,opc;
	do{
		
	    struct tiendaOnline tienda[3];
		menu();
		cin>>opcion;
		switch(opcion){
		case 1:
			{
				cout<<endl<<"1.-dar de alta productos";
				cout<<endl<<"Introduzca los productos: "<<endl;
				for(int i=0;i<3;i++)
				{
					fflush(stdin);
					cout<<"introduzca el nombre del producto ["<<i+1<<"] :";
					cin.getline(tienda[i].producto,30,'\n');
					cout<<endl<<"introduzca el costo del producto ["<<i+1<<"] :";
					cin>>tienda[i].costo;
					cout<<endl<<"introduzca el codigo del producto: ";
					cin>>tienda[i].codigo;					
				}
				system("pause");
				system("cls");
				break;
			}
			
		case 2:
			{
				int cont=0,opcio;
				for(int i=0;i<3;i++)
				{
					cout<<"\t"<<"producto"<<"\t"<<"costo"<<"\t"<<"codigo";
					cout<<endl<<"\t"<<tienda[i].producto<<"\t \t"<<tienda[i].costo<<"\t"<<tienda[i].codigo;
					cout<<endl;
				}
				cout<<"que desa hacer"<<endl;
				cout<<"1.-comprar"<<endl;
				cin>>opcio;
				int buscar;
					do{
						cout<<"escriba el codigo de el producto a comprar:";
						cin>>buscar;
						for(int i=0;i<3;i++)
						{
							if(tienda[i].codigo==buscar)
							{
								tienda[i].usu.code = tienda[i].codigo;
								tienda[i].usu.comprar = tienda[i].costo;
								strcpy(tienda[i].usu.nombre[i], tienda[i].producto);
							}
						}						
						cont++;
					}while(cont<2);
					cout<<"productos comprados"<<endl;
					for(int i=0;i<2;i++)
					{						
						cout<<"nombre del producto comprado: ["<<tienda[i].usu.nombre[i] << "]"<<endl;
						cout<<"codigo del producto ["<<tienda[i].usu.code<<"]\n"<<endl;
						cout<<"costo del producto ["<<tienda[i].usu.comprar<<"]\n"<<endl;
					}
				
				break;
			}
		}
    }while(opcion!=3||opcion>3);
	return 0;
}

void menu(){
	cout<<"bienbenido a la tienda online"<<endl;
	cout<<"identifiquese como:"<<endl;
	cout<<"1.-administrador"<<endl;
	cout<<"2.-usuario"<<endl;
}

