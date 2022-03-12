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
