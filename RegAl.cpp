#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

class RegistroAlu{
	
	protected:

		string nombre, carnet, correo, seccion, estado;
		int ciclo;
		float promedio;	
	
	public:
		
		void agregarAl();
		void verDatos(string);
		void buscarAl();
		void modificarDatos();
		void restaurar();
		
		
};
		
void RegistroAlu::agregarAl(){
	
	ofstream file;
	file.open("registroAlumnos.txt", ios::app);
	
	cout << "\n     ****************************" << endl;
	cout << "     |    Registro de Alumnos   |" << endl;
	cout << "     ****************************\n" << endl;
	cout << "Nombre y apellido de alumno: ";
	cin.ignore(1, '\n');
	getline(cin, nombre);
	cout << "Numero carnet: ";
	getline(cin, carnet, '\n');
	verDatos(carnet);
	cout << "Correo electronico: ";
	getline(cin, correo, '\n');
	cout << "Seccion: ";
	getline(cin, seccion, '\n');
	cout << "Ciclo escolar: ";
	cin >> ciclo;
	cout << "Estado, A = Aprobado, R = Reprobado: ";
	cin.ignore(1, '\n');
	getline(cin, estado);
	cout << "Promedio: ";
	cin >> promedio;
	
	file << nombre << "," << carnet << "," << correo << "," << seccion << "," << ciclo << "," << estado << "," << promedio << endl;
	file.close();
	
	cout << "\nDatos registrados correctamente\n" << endl;
	system("pause");
	
}

void RegistroAlu::verDatos(string a){
	
	string texto;
	fstream file;
	file.open("registroAlumnos.txt", ios::in);
	
	if (file.fail()){
		
		cout << "El archivo no se pudo abrir" << endl;
		exit(1);
	}
	
	while(!file.eof()){
		
		getline(file, texto, ',');
		
		if (texto == a){
			
			cout << "Numero de carnet ya registrado!!" << endl;
			getline(cin, carnet, '\n');
			verDatos(carnet);
			break;
			
		} 
	}
	
}

void RegistroAlu::modificarDatos(){
	
	int sel, op;
	string carnet2, texto, ciclo, promedio;
	fstream file, file2;
	int encontrado = 0;
	int noEncontrado = 0;
	file.open("registroAlumnos.txt", ios::in);
	file2.open("registro.txt", ios::app);
	
	cout << "\n     ****************************" << endl;
	cout << "     |    Modificar Datos       |" << endl;
	cout << "     ****************************\n" << endl;
	cin.ignore(1, '\n');
	cout << "Ingresar numero de carnet: ";
	getline(cin, carnet2, '\n');
	
	while(getline(file, texto, '\n')){
		
		stringstream input_stringstream(texto);
		
		getline(input_stringstream, nombre, ',');
		getline(input_stringstream, carnet, ',');
		getline(input_stringstream, correo, ',');
		getline(input_stringstream, seccion, ',');
		getline(input_stringstream, ciclo, ',');
		getline(input_stringstream, estado, ',');
		getline(input_stringstream, promedio, ',');
		
		if (carnet2 == carnet){
			
			cout << "\nQue datos desea modificar?\n" << endl;
			cout << "1. Estado" << endl;
			cout << "2. Promedio" << endl;
			cout << "0. Salir\n" << endl;
			cout << " -> ";
			cin >> sel;
			
			if (sel == 1){
				
				cout << "\nEstado actual: " << estado << endl;
				cin.ignore(1, '\n');
				cout << "\nIngrese nuevo estado: ";
				getline(cin, estado, '\n');
				
				cout << "Desea continuar?" << endl;
				cout << "1. SI" << endl;
				cout << "2. NO" << endl;
				cin >> op;
				
				if (op == 1){
					
					cout << "\nNombre: " << nombre << endl;
					cout << "Carnet: " << carnet << endl;
					cout << "Correo: " << correo << endl;
					cout << "Seccion: " << seccion << endl;
					cout << "Ciclo: " << ciclo << endl;
					cout << "Estado: " << estado << endl;
					cout << "Promedio: " << promedio << endl;
					
					file2 << nombre << "," << carnet << "," << correo << "," << seccion << "," << ciclo << "," << estado << "," << promedio << endl;
					
				} else {
					
					cout << "No se realizaron cambios" << endl;
				}
				
			} else if (sel == 2){
				
				cout << "\nPromedio actual: " << promedio << endl;
				cin.ignore(1, '\n');
				cout << "\nIngrese nuevo promedio: ";
				getline(cin, promedio, '\n');
				
				cout << "Desea continuar?" << endl;
				cout << "1. SI" << endl;
				cout << "2. NO" << endl;
				cin >> op;
				
				if (op == 1){
					
					cout << "\nNombre: " << nombre << endl;
					cout << "Carnet: " << carnet << endl;
					cout << "Correo: " << correo << endl;
					cout << "Seccion: " << seccion << endl;
					cout << "Ciclo: " << ciclo << endl;
					cout << "Estado: " << estado << endl;
					cout << "Promedio: " << promedio << endl;
					
					file2 << nombre << "," << carnet << "," << correo << "," << seccion << "," << ciclo << "," << estado << "," << promedio << endl;
					
				} else {
					
					cout << "No se realizaron cambios" << endl;
				}
			} 
			
			encontrado = 1;
			
		} else {

			file2 << nombre << "," << carnet << "," << correo << "," << seccion << "," << ciclo << "," << estado << "," << promedio << endl;
			noEncontrado = 0;
		}
		
	}
	
	if (encontrado == 0 && noEncontrado == 0){
			
		cout << "\nNumero de carnet no encontrado\n" << endl;
		
	} else {
			
		cout << "\n" << endl;
	}
	
	file.close();
	file2.close();
	restaurar();
	system("pause");
}

void RegistroAlu::restaurar(){
	
	ifstream file;
	ofstream file2;
	string texto;
	file.open("registro.txt", ios::in);
	file2.open("registroAlumnos.txt", ios::out);
	
	if (file.fail()){
		
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	
	while(getline(file, texto, '\n')){
		
		file2 << texto << endl;
	}
	
	file.close();
	file2.close();
	remove("registro.txt");
}	

int main(){
	
	RegistroAlu reg;
	int sel;
	
	do {
		
		cout << "     **********************" << endl;
		cout << "     |     Bienvenido     |" << endl;
		cout << "     **********************\n" << endl;
		cout << "Seleccione una opcion:\n" << endl;
		cout << "1. Agregar Alumno" << endl;
		cout << "2. Buscar Alumno" << endl;
		cout << "3. Modificar datos de Alumno" << endl;
		cout << "0. Salir\n" << endl;
		cout << " -> ";
		cin >> sel;
		
		switch (sel){
			
			case 1:
				system("cls");
				reg.agregarAl();
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				break;
		}
		
		system("cls");
		
	} while (sel != 0);
	
	return 0;
	
}
