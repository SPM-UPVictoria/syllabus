#ifndef PLANARREGLO_H_INCLUDED
#define PLANARREGLO_H_INCLUDED

#include <iostream>

using namespace std;

#define MAX 100

template <class T>
class Arreglo
{
    private:
        T Datos [MAX];
        int tam;
    public:
        Arreglo();
        void lectura();
        int insertaDesordenado(T);
        int eliminaDesordenado(T);
        int buscaDesordenado(T);
        void escribe();
};

template <class T>
Arreglo<T>::Arreglo()
{
    tam = 0;
}

template <class T>
void Arreglo<T>::lectura()
{
    int indice;

    do {
        cout << "\n\n ingrese total de elementos: ";
        cin >> tam;
    } while (tam < 1 || tam > MAX);

    for (indice = 0; indice < tam; indice ++)
    {
        cout << "\nIngrese el " << indice + 1 << " dato: ";
        cin >> Datos[indice];
    }
}

template <class T>
int Arreglo<T>::insertaDesordenado(T valor)
{
    int posic, res = 1;
    if (tam < MAX)
    {
        posic = buscaDesordenado(valor);
        if (posic < 0)
            Datos[tam++] = valor;
        else
            res = -1;
    }
    else
        res = 0;
    return res;
}

template <class T>
int Arreglo<T>::eliminaDesordenado(T valor)
{
    int indice, posic, res = 1;
    if (tam > 0)
    {
        posic = buscaDesordenado(valor);
        if (posic < 0)
            res = -1;
        else
        {
            tam--;
            for (indice=posic; indice < tam; indice++)
                Datos[indice] = Datos[indice+1];
        }
    }
    else
        res = 0;

    return res;
}

template <class T>
int Arreglo<T>::buscaDesordenado(T valor)
{
    int indice = 0, res = -1;
    while ((indice < tam) && (Datos[indice] != valor))
        indice++;
    if (indice < tam) res = indice;

    return res;
}

template <class T>
void Arreglo<T>::escribe()
{
    int indice;
    if (tam > 0)
    {
        cout << "\n\n";
        for (indice=0; indice < tam; indice++)
            cout << '\t' << Datos[indice];
        cout << "\n\n";
    }
    else cout << "\n No hay elementos almacenados";
}

#endif // PLANARREGLO_H_INCLUDED
