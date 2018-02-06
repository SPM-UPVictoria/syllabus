#include <iostream>
#include "PlantArreOrd.h"

using namespace std;

char menuOpciones();

int main()
{
    Arreglo<float> tiempos;
    char Opc;
    float t;
    int res;

    do {
        Opc = menuOpciones();
        switch(Opc)
        {
            case 'L':
                tiempos.lectura();
                break;
            case 'I':
                tiempos.escribe();
                break;
            case 'A':
                cout << "\n\n Nuevo tiempo registrado por el nadador: ";
                cin >> t;
                res = tiempos.insertaOrdenado(t);

                if (res == 1) cout << "\n\n El nuevo tiempo ya fue dado de alta.";
                else if (res == 0) cout << "\n\n No hay espacio para registrar el nuevo tiempo.";
                else cout << "\n\n Ese tiempo ya fue registrado.";

                break;
            case 'B':
                cout << "\n\nTiempo a dar de baja: ";
                cin >> t;
                res = tiempos.eliminaOrdenado(t);
                if (res == 1) cout << "\n\n El tiempo ya fue dado de baja." ;
                else if (res == 0) cout << "\n\nNo hay tiempos registrados.";
                else cout << "\n\nTiempo no registrado.";
                break;
            case 'T':
                cout << "\n\nTermina el proceso.\n\n";
                break;
        }
    } while (Opc != 'T');

    return 0;
}

char menuOpciones()
{
    char Opc;

    do {
        cout << "\nL: Leer los tiempos hechos por el nadador \n";
        cout << "\nI: Imprimir un listado con los tiempos del nadador. \n";
        cout << "\nA: Dar de alta un nuevo tiempo. \n";
        cout << "\nB: Dar de baja un tiempo ya registrado. \n";
        cout << "\nT: Terminar el proceso \n";
        cin >> Opc;
    } while (Opc != 'L' && Opc != 'I' && Opc != 'A' && Opc != 'B' && Opc != 'T');

    return Opc;
}
