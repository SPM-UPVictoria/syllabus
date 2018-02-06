#ifndef PLANTARREORD_H_INCLUDED
#define PLANTARREORD_H_INCLUDED

#include <iostream>

using namespace std;

#define MAX 100

template <class T>
class Arreglo
{
    private:
        T Datos[MAX];
        int tam;
    public:
        Arreglo();
        void lectura();
        int insertaOrdenado(T);
        int eliminaOrdenado(T);
        void escribe();
        int buscaOrdenado(T);

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
        cout << "\n\n Ingrese numero de datos a guardar: ";
        cin >> tam;
    } while (tam < 1 || tam > MAX);

    for (indice=0; indice < tam; indice++)
    {
        cout << "\ningrese el " << indice+1 << " dato: ";
        cin >> Datos[indice];
    }
}

template <class T>
int Arreglo<T>::insertaOrdenado(T valor)
{
    int indice, posic, res = 1;
    if (tam < MAX)
    {
        posic = buscaOrdenado(valor);
        if (posic > 0)
            res = -1;
        else
        {
            posic = (posic * -1) -1;
            for (indice = tam; indice > posic; indice--)
                Datos[indice] = Datos[indice - 1];
            Datos[posic] = valor;
            tam++;
        }
    }
    else
    {
        res = 0;
    }
    return res;
}

template <class T>
int Arreglo<T>::eliminaOrdenado(T valor)
{
    int posic, indice, res = 1;
    if (tam > 0)
    {
        posic = buscaOrdenado(valor);
        if (posic < 0)
            res = -1;
        else
        {
            tam--;
            for (indice =posic; indice < tam; indice++)
                Datos[indice] = Datos[indice+1];
        }
    }
    else
    {
        res = 0;
    }
    return res;
}

template <class T>
void Arreglo<T>::escribe()
{
    int indice;
    if (tam > 0)
    {
        cout << "\nimpresion de datos \n";
        for (indice=0; indice < tam; indice++)
            cout << '\t' << Datos[indice];
    }
    else cout << "\nNo hay elementos registrados";
}

template <class T>
int Arreglo<T>::buscaOrdenado(T valor)
{
    int indice = 0, res;
    while ((indice < tam) && (Datos[indice] < valor)) indice++;

    if (indice == tam || Datos[indice] > valor) res= -(indice+1);
    else res = indice;

    return res;
}


#endif // PLANTARREORD_H_INCLUDED
