#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Nodo{
	int dato;
	char dni[8];
	char nombre[30];
	char ape[30];
	char sex;
	char fec[10];
	char corr[100];
	char tel[12];
	char dir[100];
	Nodo *der;
	Nodo *izq;
};

//prototipos de funcion
void menu();
Nodo *crearNodo(int dato, char dni[],char nom[],char ape[],char sex,char fec[],char corr[],char tel[],char dir[]);
void insertarNodo(Nodo *&arbol,int dato, char dni[],char nom[],char ape[], char sex,char fec[],char corr[],char tel[],char dir[]);
bool buscar(Nodo *arbol,int n);
void mostrarbo(Nodo *arbol);
Nodo *buscarnom(Nodo *arbol,char nom[30]);
Nodo *buscardni(Nodo *arbol,char dni[8]);
Nodo *buscarape(Nodo *arbol,char ape[30]);
Nodo *buscarfec(Nodo *arbol,char fec[30]);

Nodo *arbol = NULL;

int main(){

	menu();

	system("pause");
	return 0;
}

void menu(){
	int dato,op,p=0,m=0,f=0;
	char nom[30],ape[30],fec[10],tel[12];
	char dni[10],sex,corr[100],dir[100];
	Nodo *a;

	do{
		cout<<"\t\t AGENDA SISTEMATICA"<<endl<<endl;
		cout<<"\t\t. MENU DE OPCIONES"<<endl;
		cout<<"\t1. Registrar datos"<<endl;
		cout<<"\t2. Modificar datos"<<endl;
		cout<<"\t3. Mostrar todo los datos "<<endl;
		cout<<"\t4. Buscar por nombre "<<endl;
		cout<<"\t5. Buscar por DNI "<<endl;
		cout<<"\t6. Buscar por apell "<<endl;
		cout<<"\t7. Buscar por F.nac "<<endl;
		cout<<"\t8. Visualizar Dat. Estad"<<endl;
		cout<<"\t9. Salir "<<endl;

		cout<<"\n\tDigite una opcion -> ";
		cin>>op;

		switch(op){
			case 1:
					cout<<"\tDigite un dato : ";
					cin>>dato;
					cout<<endl<<"\tDNI de Contacto  :";
					fflush(stdin);
					cin.getline(dni,10,'\n');
					cout<<endl<<"\tNombres :";
					fflush(stdin);
					cin.getline(nom,30,'\n');
					cout<<endl<<"\tApellidos :";
					fflush(stdin);
					cin.getline(ape,30,'\n');
					cout<<endl<<"\tSexo (m/f):";
					cin.get(sex);
					if(sex=='m'){
						m++;
					}
					if(sex=='f'){
						f++;
					}
					cout<<endl<<"\tFecha de Nac (DD/MM/AA):";
					fflush(stdin);
					cin.getline(fec,10,'\n');
					cout<<endl<<"\tCorreo :";
					fflush(stdin);
					cin.getline(corr,30,'\n');
					cout<<endl<<"\tTelefono :";
					fflush(stdin);
					cin.getline(tel,30,'\n');
					cout<<endl<<"\tDireccion :";
					fflush(stdin);
					cin.getline(dir,30,'\n');
					p++;
					insertarNodo(arbol,dato,dni,nom,ape,sex,fec,corr,tel,dir);
		            cout<<"\n";
					system("pause");
					break;
			case 2:
                   cout<<"\nDigite el dato a modificar: ";
					cin>>dato;
					if(buscar(arbol,dato)==true){
						cout<<"\nElemento "<<dato<<" ha sido encontrado en la agenda"<<endl;
						cout<<endl<<"\tDNI de Contacto  :";
						fflush(stdin);
						cin.getline(dni,10,'\n');
						strcpy(arbol->dni,dni);
						cout<<endl<<"\tNombres :";
						fflush(stdin);
						cin.getline(nom,30,'\n');
						strcpy(arbol->nombre,nom);
						cout<<endl<<"\tApellidos :";
						fflush(stdin);
						cin.getline(ape,30,'\n');
						strcpy(arbol->ape,ape);
						cout<<endl<<"\tSexo :";
						cin.get(sex);
						arbol->sex = sex;
						cout<<endl<<"\tFecha de Nac :";
						fflush(stdin);
						cin.getline(fec,10,'\n');
						strcpy(arbol->fec,fec);
						cout<<endl<<"\tCorreo :";
						fflush(stdin);
						cin.getline(corr,30,'\n');
						strcpy(arbol->corr,corr);
						cout<<endl<<"\tTelefono :";
						fflush(stdin);
						cin.getline(tel,30,'\n');
						strcpy(arbol->tel,tel);
						cout<<endl<<"\tDireccion :";
						fflush(stdin);
						cin.getline(dir,30,'\n');
						strcpy(arbol->dir,dir);
					}
					cout<<"\n";
					system("pause");
					break;

			case 3:
					cout<<"\nMostrando el arbol completo: \n\n";
				   mostrarbo(arbol);
				   cout<<"\n";
				   system("pause");
				   break;
			case 4:
					cout<<endl<<"\tNombre de Contacto  ";
					fflush(stdin);
			        cin.getline(nom,30,'\n');
			  		a = buscarnom(arbol,nom);
			        if(a!=NULL){
						fflush(stdin);
				  		cout<<"\t\nContacto encontrado:"<<endl;
				  		cout<<"\tNombres: "<<a->nombre<<endl;
				  		cout<<"\tdni: "<<a->dni<<endl;
				  		cout<<"\tCorreo: "<<a->corr<<endl;
				  		cout<<"\tDireccion: "<<a->dir<<endl;

			  		}
			  		system("pause");
			  		break;
			case 5:
					cout<<endl<<"\tIngrese el DNI a buscar: ";
					fflush(stdin);
			        cin.getline(dni,10,'\n');
			  		a = buscardni(arbol,dni);
			        if(a!=NULL){
						fflush(stdin);
				  		cout<<"\t\nContacto encontrado:"<<endl;
				  		cout<<"\tNombres: "<<a->nombre<<endl;
				  		cout<<"\tSexo: "<<a->sex<<endl;
				  		cout<<"\tCorreo: "<<a->corr<<endl;
				  		cout<<"\tTelefono: "<<a->tel<<endl;

			  		}
			  		system("pause");
			  		break;
			case 6:
					cout<<endl<<"\tIngrese el apellido a buscar: ";
					fflush(stdin);
			        cin.getline(ape,10,'\n');
			  		a = buscarape(arbol,ape);
			        if(a!=NULL){
						fflush(stdin);
				  		cout<<"\t\nContacto encontrado:"<<endl;
				  		cout<<"\tNombres: "<<a->nombre<<endl;
				  		cout<<"\tSexo: "<<a->sex<<endl;
				  		cout<<"\tF. Nac: "<<a->fec<<endl;
				  		cout<<"\tTelefono: "<<a->tel<<endl;

			  		}
			  		system("pause");
			  		break;
			case 7:
					cout<<endl<<"\tIngrese FEC. NAC: ";
					fflush(stdin);
			        cin.getline(fec,10,'\n');
			  		a = buscarfec(arbol,fec);
			        if(a!=NULL){
						fflush(stdin);
				  		cout<<"\t\nContacto encontrado:"<<endl;
				  		cout<<"\tNombres: "<<a->nombre<<endl;
				  		cout<<"\tSexo: "<<a->sex<<endl;
				  		cout<<"\tDNI: "<<a->dni<<endl;
				  		cout<<"\tTelefono: "<<a->tel<<endl;

			  		}
			  		system("pause");
			  		break;
			case 8:
			  		cout<<"\tCan. pers:  "<<p<<endl;
			  		cout<<"hombres: "<<m<<endl;
			  		cout<<"mujeres: "<<f<<endl;
					system("pause");
			  		break;
		}
		system("cls");
	}while(op!=9);
}

//crea un nuevo nodo
Nodo *crearNodo(int dato,char dni[8],char nom[30],char ape[30],char sex,char fec[10],char corr[100],char tel[12],char dir[100]){
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->dato = dato;
	strcpy(nuevo_nodo->dni,dni);
	strcpy(nuevo_nodo->nombre,nom);
	strcpy(nuevo_nodo->ape,ape);
	nuevo_nodo->sex = sex;
	strcpy(nuevo_nodo->fec,fec);
	strcpy(nuevo_nodo->corr,corr);
	strcpy(nuevo_nodo->tel,tel);
	strcpy(nuevo_nodo->dir,dir);
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int dato,char dni[8],char nom[30]
,char ape[30],char sex,char fec[10],char corr[100],char tel[12],char dir[100]){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(dato,dni,nom,ape,sex,fec,corr,tel,dir);
		arbol = nuevo_nodo;
	}
	else{//si tiene 1 o mas de un nodo
		int valorRaiz = arbol->dato;//tenemos el valor de raiz
		if(dato < valorRaiz){//si el dato es menor a la raiz
			insertarNodo(arbol->izq,dato,dni,nom,ape,sex,fec,corr,tel,dir);
		}
		else{
			insertarNodo(arbol->der,dato,dni,nom,ape,sex,fec,corr,tel,dir);
		}
	}
}


void mostrarbo(Nodo *arbol){
	if(arbol==NULL){
		return ;
	}
	else{
    	mostrarbo(arbol->izq); //recorre el subárbol Izquierdo
    	fflush(stdin);
		if(strcmp("M",arbol->nombre)!=0){
			 cout<<"Dato: "<<arbol->dato<<endl;
			 cout<<"DNI: "<<arbol->dni<<endl;
			 cout<<"Nombres: "<<arbol->nombre<<endl;
			 cout<<"Apelli: "<<arbol->ape<<endl;
			 cout<<"Sexo: "<<arbol->sex<<endl;
			 cout<<"F. Nac: "<<arbol->fec<<endl;
			 cout<<"Correo: "<<arbol->corr<<endl;
			 cout<<"Telef: "<<arbol->tel<<endl;
			 cout<<"Direcc: "<<arbol->dir<<endl;
			 cout<<"---------------------------"<<endl;

		}
		mostrarbo(arbol->der); //recorre el subárbol Derecho
	}
}

Nodo *buscarnom(Nodo *arbol,char nom[30]){

	if (arbol == NULL){
		return NULL;
	}
	else {
			if (strcmp(nom,arbol->nombre)==0){
				return arbol;
			}
			else {
					if (strcmp(nom,arbol->nombre)<0){
				   		return buscarnom(arbol->izq, nom);
					}
					else{
							return buscarnom(arbol->der, nom);
						}
				}
		}
}

Nodo *buscardni(Nodo *arbol,char dni[8]){
	if (arbol == NULL){
		return NULL;
	}
	else {
			if (strcmp(dni,arbol->dni)==0){
				return arbol;
			}
			else {
					if (strcmp(dni,arbol->dni)<0){
				   		return buscardni(arbol->izq, dni);
					}
					else{
							return buscardni(arbol->der, dni);
						}
				}
		}
}

Nodo *buscarape(Nodo *arbol,char ape[30]){
	if (arbol == NULL){
		return NULL;
	}
	else {
			if (strcmp(ape,arbol->ape)==0){
				return arbol;
			}
			else {
					if (strcmp(ape,arbol->ape)<0){
				   		return buscarape(arbol->izq, ape);
					}
					else{
							return buscarape(arbol->der, ape);
						}
				}
		}
}

Nodo *buscarfec(Nodo *arbol,char fec[30]){
	if (arbol == NULL){
		return NULL;
	}
	else {
			if (strcmp(fec,arbol->fec)==0){
				return arbol;
			}
			else {
					if (strcmp(fec,arbol->fec)<0){
				   		return buscarape(arbol->izq, fec);
					}
					else{
							return buscarape(arbol->der, fec);
						}
				}
		}
}

bool buscar(Nodo *arbol,int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == n){
		return true;
	}
	else if(n < arbol->dato){
		return buscar(arbol->izq,n);
	}
	else{
		return buscar(arbol->der,n);
	}
}
