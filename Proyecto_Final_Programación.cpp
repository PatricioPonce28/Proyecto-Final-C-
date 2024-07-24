#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Multa {
    string nombreInfractor;
    string descripcion;
    string fecha;
    double monto;
};

// Función para obtener la fecha actual en formato DD/MM/YYYY
string fecha_actual() {
    time_t t = time(NULL);
    struct tm* fecha = localtime(&t);
    char buffer[11]; // Formato DD/MM/YYYY
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", fecha);
    return string(buffer);
}

void registrarMulta(const Multa& multa) {
    string rutaArchivo = "C:\\RegistroDeMultas\\" + multa.fecha + "_" + multa.nombreInfractor + ".txt";
    ofstream archivo(rutaArchivo);

    if (!archivo) {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return;
    }

    archivo << "Nombre del Infractor: " << multa.nombreInfractor << endl;
    archivo << "Descripción: " << multa.descripcion << endl;
    archivo << "Fecha: " << multa.fecha << endl;
    fecha_actual();
    archivo << "Monto: " << multa.monto << endl;

    archivo.close();
}

int main() {
    Multa nuevaMulta;
    
    // Asignar la fecha actual a la multa
    nuevaMulta.fecha = fecha_actual();
    
    cout << "Ingrese el nombre del infractor: ";
    getline(cin, nuevaMulta.nombreInfractor);
    
    cout << "Ingrese la descripción de la multa: ";
    getline(cin, nuevaMulta.descripcion);
    
    cout << "Ingrese el monto de la multa: ";
    cin >> nuevaMulta.monto;
    
    registrarMulta(nuevaMulta);
    cout << "Multa registrada con éxito." << endl;

    return 0;
}
