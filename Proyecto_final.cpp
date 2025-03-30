#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct Asignatura{
	string asignatura;
	int hora_trab;
};

struct Cargo{
	string puesto;
	string escalafon;
	int cantidad_asignatura;
	Asignatura asignaturas[100];
};

struct Empleado{
	string nombre;
	string apellido;
	int cedula;
	Cargo cargo;
	char asterisco;
	int cant_salarios;
	int salario;
};

int cantidad_empleados;
int contar();
void cargar(Empleado trabajador[]);
void nuevo_empleado(Empleado trabajador[]);
void eliminar_empleado(Empleado trabajador[]);
void ag_materiaprof(Empleado trabajador[]);
void ag_materiamoni(Empleado trabajador[]);
void cal_salempleado(Empleado trabajador[]);
void cal_salmonitor(Empleado trabajador[]);
void crear_archivo(Empleado trabajador[]);
void cal_salprofe(Empleado trabajador[]);

int main() {
	int opc;
	Empleado trabajador[100];
	do{
		cout<<"\t\t\tProyecto Nomina"<<endl;
        cout<<"\n\t\t\tMenu de Opciones"<<endl;
        cout<<"\t\t\t----------------"<<endl;
        cout<<"\n\t1. Cargar empleados"<<endl;
        cout<<"\t2. Agregar empleado"<<endl;
        cout<<"\t3. Eliminar empleado"<<endl;
        cout<<"\t4. Anadir asignatura a un Profesor"<<endl;
		cout<<"\t5. Anadir asignatura a un Monitor"<<endl;
		cout<<"\t6. Calcular salario de un Empleado"<<endl;
		cout<<"\t7. Calcular salario de un Profesor"<<endl;
        cout<<"\t8. Calcular salario de un Monitor"<<endl;
        cout<<"\t9. Generar la nomina Reporte.txt"<<endl;
        cout<<"\t0. SALIR"<<endl;
        cout<<"\n\tIngrese una opcion: ";
        cin>>opc;
        switch(opc){
			case 1:	cantidad_empleados=contar(); 
				cargar(trabajador);
			break;
			case 2: nuevo_empleado(trabajador);
			break;
			case 3: eliminar_empleado(trabajador);
			break;
			case 4: ag_materiaprof(trabajador);
			break;
			case 5: ag_materiamoni(trabajador);
			break;
			case 6: cal_salempleado(trabajador);
			break;
			case 7: cal_salprofe(trabajador);
			break;
			case 8: cal_salmonitor(trabajador);
			break;
			case 9: crear_archivo(trabajador);
			break;
			case 0: break;
		}
	}while(opc!=0);{
	}
}

int contar(){
ifstream archivo ("Nomina.txt");
	string a; 
	int b = 0;
	if(archivo.fail()){
        cout<<"Archivo no pudo abrirse"<<endl;
        exit(1);
    }
	for(int i=0; !archivo.eof(); i++){
		archivo>>a;      
        if(a=="#"){
			b++;
		}else if(a=="FIN"){
			break; 
		}	
    }
	return b;
	archivo.close(); 
}

void cargar(Empleado trabajador[]){
	ifstream archivo ("Nomina.txt");
	for (int i= 0; i<cantidad_empleados; i++){
		archivo>>trabajador[i].nombre;
		archivo>>trabajador[i].apellido;
		archivo>>trabajador[i].cedula;
		archivo>>trabajador[i].cargo.puesto;
		if(trabajador[i].cargo.puesto=="Profesor"){
		archivo>>trabajador[i].cargo.escalafon;
		archivo>>trabajador[i].cargo.cantidad_asignatura;
		for(int k =0; k<trabajador[i].cargo.cantidad_asignatura; k++){
			archivo>>trabajador[i].cargo.asignaturas[k].asignatura;
			archivo>>trabajador[i].cargo.asignaturas[k].hora_trab;
		}
		archivo>>trabajador[i].asterisco;
	}	
		if(trabajador[i].cargo.puesto=="Monitor"){
		archivo>>trabajador[i].cargo.cantidad_asignatura;
		for(int k =0; k<trabajador[i].cargo.cantidad_asignatura; k++){
			archivo>>trabajador[i].cargo.asignaturas[k].asignatura;
			archivo>>trabajador[i].cargo.asignaturas[k].hora_trab;
		}
		archivo>>trabajador[i].asterisco;
	}
		if(trabajador[i].cargo.puesto=="Empleado"){
		archivo>>trabajador[i].cargo.escalafon;
		archivo>>trabajador[i].cant_salarios;
		archivo>>trabajador[i].asterisco;
		}
	}
	cout<<"\n\tDatos cargados con exito 100%"<<endl;
}

void nuevo_empleado(Empleado trabajador[]) {
	int nueva_cedula, noexiste = 1, aux;
	cout<<"\n\tDigite el numero de cedula del nuevo empleado: ";
	cin>>nueva_cedula;

	for(int k = 0; k < cantidad_empleados; k++) {
		if(nueva_cedula == trabajador[k].cedula) {
			cout<<"\n\tERROR-El empleado ya existe y es imposible crearlo"<<endl;
			noexiste = 0;
			break;
		}
	}

	if(noexiste == 1) {
		aux = cantidad_empleados;
		cantidad_empleados += 1;

		for(int j = aux; j < cantidad_empleados; j++) {
			cout<<"\n\tEl empleado no existe, ingrese los siguientes datos"<<endl;

			cout<<"\n\tDigite el nombre del empleado: ";
			cin>>trabajador[j].nombre;
			cout<<"\n\tDigite el apellido del empleado: ";
			cin>>trabajador[j].apellido;
			trabajador[j].cedula = nueva_cedula;
			nueva_cedula = 0;

			cout<<"\n\tDigite el cargo del empleado: ";
			cin>>trabajador[j].cargo.puesto;

			if(trabajador[j].cargo.puesto == "Profesor") {
				cout<<"\n\tDigite el escalafon del Profesor: ";
				cin>>trabajador[j].cargo.escalafon;
				cout<<"\n\tDigite la cantidad de materias que dicta el Profesor: ";
				cin>>trabajador[j].cargo.cantidad_asignatura;

				for(int k = 0; k < trabajador[j].cargo.cantidad_asignatura; k++) {
					cout<<"\n\tDigite el nombre de la materia "<<k+1<<" : ";
					cin>>trabajador[j].cargo.asignaturas[k].asignatura;
					cout<<"\n\tDigite el numero de horas trabajadas en la materia "<<k+1<<" : ";
					cin>>trabajador[j].cargo.asignaturas[k].hora_trab;
				}
			}

			if(trabajador[j].cargo.puesto == "Monitor") {
				cout<<"\n\tDigite la cantidad de materias a cargo del Monitor: ";
				cin>>trabajador[j].cargo.cantidad_asignatura;

				for(int v = 0; v < trabajador[j].cargo.cantidad_asignatura; v++) {
					cout<<"\n\tDigite el nombre de la materia "<<v+1<<" : ";
					cin>>trabajador[j].cargo.asignaturas[v].asignatura;
					cout<<"\n\tDigite el numero de horas trabajadas en la materia "<<v+1<<" : ";
					cin>>trabajador[j].cargo.asignaturas[v].hora_trab;
				}
			}

			if(trabajador[j].cargo.puesto == "Empleado") {
				cout<<"\n\tDigite el escalafon del Empleado: ";
				cin>>trabajador[j].cargo.escalafon;
				cout<<"\n\tDigite la cantidad de salarios que gana el Empleado: ";
				cin>>trabajador[j].cant_salarios;
			}
		}
	}
}

void eliminar_empleado(Empleado trabajador[]) {
	int emp_elim, i, j;
	int encontrado = 0;

	cout<<"\n\tDigite el ID del empleado a eliminar: ";
	cin>>emp_elim;

	for(i = 0; i < cantidad_empleados; i++) {
		if(emp_elim == trabajador[i].cedula) {
			encontrado = 1;

			// Mover todos los empleados hacia arriba
			for(j = i; j < cantidad_empleados - 1; j++) {
				trabajador[j] = trabajador[j + 1];
			}

			cantidad_empleados = cantidad_empleados - 1;
			cout<<"\n\tEmpleado eliminado con EXITO"<<endl;
			break;
		}
	}

	if(encontrado == 0) {
		cout<<"\n\tERROR - El empleado no existe"<<endl;
	}
}

void ag_materiaprof(Empleado trabajador[]){
	int cedula_agr, aux;
	cout<<"\n\tDigite la cedula del profesor al que quiere agregarle una materia: ";
	cin>>cedula_agr;
	for(int i=0; i<cantidad_empleados; i++){
		if(cedula_agr==trabajador[i].cedula&&trabajador[i].cargo.puesto=="Profesor"){
			aux =trabajador[i].cargo.cantidad_asignatura;
			trabajador[i].cargo.cantidad_asignatura+=1;
			for(int j=aux; j<trabajador[i].cargo.cantidad_asignatura; j++){
				cout<<"\n\tDigite el nombre de la materia "<<j+1<<" : ";
				cin>>trabajador[i].cargo.asignaturas[j].asignatura;
				cout<<"\n\tDigite el numero de horas trabajadas en la materia "<<j+1<<" : ";
				cin>>trabajador[i].cargo.asignaturas[j].hora_trab;
			}
			cout<<"\n\tMateria cargada con EXITO";
		}
	}
}

void ag_materiamoni(Empleado trabajador[]){
	int cedula_agr, aux;
	cout<<"\n\tDigite la cedula del monitor al que quiere agregarle una materia: ";
	cin>>cedula_agr;
	for(int i=0; i<cantidad_empleados; i++){
		if(cedula_agr==trabajador[i].cedula&&trabajador[i].cargo.puesto=="Monitor"){
			aux =trabajador[i].cargo.cantidad_asignatura;
			trabajador[i].cargo.cantidad_asignatura+=1;
			for(int j=aux; j<trabajador[i].cargo.cantidad_asignatura; j++){
				cout<<"\n\tDigite el nombre de la materia "<<j+1<<" : ";
				cin>>trabajador[i].cargo.asignaturas[j].asignatura;
				cout<<"\n\tDigite el numero de horas trabajadas en la materia "<<j+1<<" : ";
				cin>>trabajador[i].cargo.asignaturas[j].hora_trab;
			}
			cout<<"\n\tMateria cargada con EXITO";
		}
	}
}

void cal_salempleado(Empleado trabajador[]){
	int cel_cal, aux;
	cout<<"\n\tDigite la cedula del empleado al que quiere calcularle el salario: ";
	cin>>cel_cal;
	for(int i=0; i<cantidad_empleados; i++){
			if(cel_cal==trabajador[i].cedula&&trabajador[i].cargo.puesto=="Empleado"){
				trabajador[i].salario= ((trabajador[i].cant_salarios*1000000)*0.75);
				cout<<trabajador[i].salario;
			}
		}
	cout<<"\n\tSalario calculado con EXITO";
	}

void cal_salmonitor(Empleado trabajador[]){
	int cel_cal, aux=0;
	cout<<"Digite la cedula del monitor al que quiere calcularle el salario: ";
	cin>>cel_cal;
	for(int i=0; i<cantidad_empleados; i++){
			if(cel_cal==trabajador[i].cedula&&trabajador[i].cargo.puesto=="Monitor"){
				for(int j=0; j<trabajador[i].cargo.cantidad_asignatura; j++)
					aux+=trabajador[i].cargo.asignaturas[j].hora_trab;
				trabajador[i].salario= aux*7197;
				cout<<trabajador[i].salario;
			}
		}
	cout<<"\n\tSalario calculado con EXITO";
	}
	
void cal_salprofe(Empleado trabajador[]){
	int cel_cal, aux=0;
	float salmin=1000000;
	cout<<"\n\tDigite la cedula del profesor al que quiere calcularle el salario: ";
	cin>>cel_cal;
	for(int i=0; i<cantidad_empleados; i++){
			if(cel_cal==trabajador[i].cedula&&trabajador[i].cargo.puesto=="Profesor"){
				for(int j=0; j<trabajador[i].cargo.cantidad_asignatura; j++){
				aux+=trabajador[i].cargo.asignaturas[j].hora_trab;
			}
				if(trabajador[i].cargo.escalafon=="Catedra"){
					salmin = salmin *2.5;
					trabajador[i].salario=((0.5*salmin)*(0.75*aux));
					cout<<trabajador[i].salario;
				}
				if(trabajador[i].cargo.escalafon=="Intructor"){
					trabajador[i].salario=((1*salmin)*(0.75*aux));
					cout<<trabajador[i].salario;
				}
				if(trabajador[i].cargo.escalafon=="Asistente"){
					trabajador[i].salario=((1.5*salmin)*(0.75*aux));
					cout<<trabajador[i].salario;
				}
				if(trabajador[i].cargo.escalafon=="Asociado"){
					trabajador[i].salario=((2*salmin)*(0.75*aux));
					cout<<trabajador[i].salario;
				}
				if(trabajador[i].cargo.escalafon=="Titular"){
					trabajador[i].salario=((2.5*salmin)*(0.75*aux));
					cout<<trabajador[i].salario;
				}
			}
		}
	cout<<"\n\tSalario calculado con EXITO";
	}

void crear_archivo(Empleado trabajador[]){
	ofstream archivo;
	archivo.open("Reporte.txt");
	if (archivo.fail()){
	cout << "Error al abrir el archivo" << endl;
    exit(1);
	}
	for(int i=0; i<cantidad_empleados; i++){
		archivo<<trabajador[i].nombre<<" ";
		archivo<<trabajador[i].apellido<<" ";
		archivo<<trabajador[i].cedula<<" ";
		archivo<<trabajador[i].salario<<" \n";
	}
	archivo.close();
	cout<<"\n\tArhivo generado con EXITO";
}