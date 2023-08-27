#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

void mostrarLinea (int, const char* const, double);
void pausa ();

int main () {

    ifstream archivo_Clientes_Entrada;
    int cuenta;
    char nombre[30];
    double saldo;

    int opc;
    do {
        system(CLEAR);
        cout << "MEN" << char(233) << " - INVESTIGACI" << char(224) << "N DE CREDITOS" <<endl<<endl;

        cout << "1. Mostrar cuentas con saldo en ceros" <<endl;
        cout << "2. Mostrar cuentas con saldo acreedor (-)" <<endl;
        cout << "3. Mostrar cuentas con saldo deudor (+)" <<endl;
        cout << "4. Salir" <<endl<<endl;

        cout << "Tu opcion >> ";
        cin >> opc;

        switch (opc) {
        case 1:
            archivo_Clientes_Entrada.open("clentes.txt", ios::in);
            if (!archivo_Clientes_Entrada) {
                cerr << "No se puede abrir el archivo" <<endl;
                exit(1);
            }
            
            cout <<endl;
            cout << setw(13) << "Cuentas con Saldos en Ceros" <<endl;
            cout << left << setw(10) << "Cuenta" << setw(13) << "Nombre" << "Saldo" <<endl << fixed << showpoint;
            while (archivo_Clientes_Entrada >> cuenta >> nombre >> saldo) {
                if (saldo == 0) {
                    mostrarLinea(cuenta, nombre, saldo);
                }
            } pausa();
            archivo_Clientes_Entrada.close();
            break;
        
        case 2:
            archivo_Clientes_Entrada.open("clentes.txt", ios::in);
            if (!archivo_Clientes_Entrada) {
                cerr << "No se puede abrir el archivo" <<endl;
                exit(1);
            }
            
            cout <<endl;
            cout << setw(13) << "Cuentas con Saldos Acreedores" <<endl;
            cout << left << setw(10) << "Cuenta" << setw(13) << "Nombre" << "Saldo" <<endl << fixed << showpoint;
            while (archivo_Clientes_Entrada >> cuenta >> nombre >> saldo) {
                if (saldo < 0) {
                    mostrarLinea(cuenta, nombre, saldo);
                }
            } pausa();
            archivo_Clientes_Entrada.close();
            break;

        case 3:
            archivo_Clientes_Entrada.open("clentes.txt", ios::in);
            if (!archivo_Clientes_Entrada) {
                cerr << "No se puede abrir el archivo" <<endl;
                exit(1);
            }
            
            cout <<endl;
            cout << setw(13) << "Cuentas con Saldos Adeudor" <<endl;
            cout << left << setw(10) << "Cuenta" << setw(13) << "Nombre" << "Saldo" <<endl << fixed << showpoint;
            while (archivo_Clientes_Entrada >> cuenta >> nombre >> saldo) {
                if (saldo > 0) {
                    mostrarLinea(cuenta, nombre, saldo);
                }
            } pausa();
            archivo_Clientes_Entrada.close();
            break;

        case 4:
            break;

        default:
            cout << endl << "Opcion incorrecta, intentalo de nuevo..."; pausa();
            break;
        }

    } while (opc != 4);

    return 0;
}

void mostrarLinea (int cuenta, const char* const nombre, double saldo) {
    cout << left << setw(10) << cuenta << setw(13) << nombre << setw(7) << setprecision(2) << right << saldo <<endl;
}
 
void pausa ()  {
    cin.clear(); cin.sync(); cin.ignore();
}