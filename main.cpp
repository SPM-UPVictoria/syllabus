#include <iostream>
#include "PlanArreglo.h"

using namespace std;

int menuOpciones();

int main()
{
    Arreglo<int> ClvAlum;

    int clv, res;
    char opc;

    do {
        opc = menuOpciones();
        switch(opc)
        {
            case 'L':
                ClvAlum.lectura();
                break;
            case 'I':
                ClvAlum.escribe();
                break;
            case 'A':
                cout << "\n\n Clave del nuevo alumno: ";
                cin >> clv;
                res = ClvAlum.insertaDesordenado(clv);

                if (res == 1)
                    cout << "\n\n El nuevo alumno ya fue dado de alta. ";
                else
                    if (res == 0) cout << "\n\n No hay espacio para registrar el nuevo alumno. ";
                    else cout << "\n\nEsa clave ya fue registrada";
                break;
            case 'B':
                cout << "\n\n Clave del alumno a dar de baja: ";
                cin >> clv;
                res = ClvAlum.eliminaDesordenado(clv);

                if (res == 1) cout << "\n\n El alumno ya fue dado de baja.";
                else if (res == 0) cout << "\n\n No hay alumnos registrados";
                else cout << "\n\nEsa clave no está registrada.";
                break;
            case 'F':
                cout << "\n\nTermina el proceso.\n\n";
                break;
        }
    } while(opc != 'F');
    return 0;
}


int menuOpciones()
{
    char Opc;

    do {
        cout << "\n\n\nL: Leer la lista de claves: ";
        cout << "\nA: Dar de alta un nuevo alumno";
        cout << "\nB: Dar de baja un alumno: ";
        cout << "\nI: Imprimir la lista de claves: ";
        cout << "\nF: Finalizar el proceso.";
        cout << "\n\n Ingrese opción de trabajo: ";
        cin >> Opc;
    } while (Opc != 'A' && Opc != 'B' && Opc != 'I' && Opc != 'L' && Opc != 'F');

    return Opc;
}
