#include <iostream>
#include "plantArreParal.h"

using namespace std;

int menuOpciones();

int main()
{
    ArreParal<int> clv;
    ArreParal<float> calif;
    int clvAlumno, opc, pos, indice, totalAl;
    float calAlumno;

    do {
        opc = menuOpciones();
        switch (opc)
        {
            case 1:
                cout << "\n\nDe el número de claves y cada una de las claves\n";
                cin >> clv;
                cout << "\n\nDé el numero de calificaciones y cada una de ellas\n";
                cin >> calif;
                break;
            case 2:
                cout << "\n\nDé la clave y calificación del nuevo alumno:";
                cin >> clvAlumno;
                cin >> calAlumno;
                pos = clv.buscaOrdenado(clvAlumno);
                if (pos > 0)
                    cout << "\n\nEsa clave ya fue registrada previamente. \n";
                else
                {
                    pos = (pos * -1) -1;
                    if (clv.insertaOrdenado(pos, clvAlumno) == 1)
                        calif.insertaOrdenado(pos, calAlumno);
                    else
                        cout << "\n\nYa no se pueden regisrar nuevos alumnos.\n";
                }
                break;
            case 3:
                cout << "\n\n Dé la clave del alumno que desea dar de baja: ";
                cin >> clvAlumno;
                pos = clv.buscaOrdenado(clvAlumno);
                if (pos > 0)
                {
                    clv.elimina(pos);
                    calif.elimina(pos);
                }
                else
                    cout << "\n\nEsa clave no está registrada. \n";
                break;
            case 4:
                cout << "\n\nListado de claves de alumnos registrados. \n";
                cout << clv;
                cout << "\n\n";
                break;
            case 5:
                totalAl = clv.regresaTamano();
                cout << "\n\nClave\t\t\tCalificación\n";
                for (indice=0; indice < totalAl; indice++)
                {
                    cout << clv.regresaValor(indice);
                    cout << calif.regresaValor(indice);
                }
                break;
            case 6:
                cout << "\n\n Clave de alumno que desea conocer su calificación: ";
                cin >> clvAlumno;
                pos = clv.buscaOrdenado(clvAlumno);
                if (pos > 0)
                {
                    cout << "\n\nCalificación del alumno con clave: " << clvAlumno;
                    cout << " es : " << calif.regresaValor(pos);
                }
                else
                    cout << "\n\nesa clave no está registrada. \n\n";
                break;
            case 7:
                cout << "\n\nTermina el proceso \n\n";
                break;

        }
    } while(opc != 7);
    return 0;
}

int menuOpciones()
{
    int opc;

    do {
        cout << "\n\n1.- Captura inicial de claves y calificaciones de alumnos.";
        cout << "\n2.- Ingresar un nuevo alumno y su calificaciòn";
        cout << "\n3.- Eliminar un alumno y su calificación.";
        cout << "\n4.- Obtener un listado de las claves de los alumnos.";
        cout << "\n5.- Obtener un listado de claves y calificaciones";
        cout << "\n6.- Obtener la calificación de un alumno.";
        cout << "\n7.- Terminar el proceso.";
        cout << "\n\nIngrese la opciòn seleccionada.";
        cin >> opc;
    } while (opc < 1 || opc > 7);

    return opc;
}
