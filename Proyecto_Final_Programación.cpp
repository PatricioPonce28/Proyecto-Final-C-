#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Multa {
    string nombreInfractor;
    string descripcion;
    string fecha;
    double monto;
};
void registrarMulta(const Multa& multa) {
    ofstream archivo("C:\\RegistroDeMultas\\" + multa.fecha + "_" + multa.nombreInfractor + ".txt");
    archivo << "Nombre del Infractor: " << multa.nombreInfractor << endl;
    archivo << "Descripción: " << multa.descripcion << endl;
    archivo << "Fecha: " << multa.fecha << endl;
    archivo << "Monto: " << multa.monto << endl;
    archivo.close();
}

int main() {
    Multa nuevaMulta;
    cout << "Ingrese el nombre del infractor: ";
    getline(cin, nuevaMulta.nombreInfractor);
    cout << "Ingrese la descripción de la multa: ";
    getline(cin, nuevaMulta.descripcion);
    cout << "Ingrese la fecha (DDMMYYYY): ";
    getline(cin, nuevaMulta.fecha);
    cout << "Ingrese el monto de la multa: ";
    cin >> nuevaMulta.monto;

    registrarMulta(nuevaMulta);
    cout << "Multa registrada con éxito." << endl;

    return 0;
}
