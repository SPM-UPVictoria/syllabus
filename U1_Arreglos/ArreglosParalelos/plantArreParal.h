#ifndef PLANTARREPARAL_H_INCLUDED
#define PLANTARREPARAL_H_INCLUDED

#include <iostream>

using namespace std;

#define MAX 100

template <class T> class ArreParal;
template <class T> istream& operator>>(istream &, ArreParal<T>&);
template <class T> ostream& operator<<(ostream &, ArreParal<T>&);

template <class T>
class ArreParal
{
    private:
        T Datos[MAX];
        int tam;

    public:
        ArreParal();
        int insertaOrdenado(int , T);
        int insertaDesordenado(T);
        void elimina(int);
        int buscaOrdenado(T);
        int buscaDesordenado(T);
        T regresaValor(int);
        int regresaTamano();
        friend istream &operator>> <T>(istream &, ArreParal<T> &);
        friend ostream &operator<< <T>(ostream &, ArreParal<T> &);

};

template <class T>
ArreParal<T>::ArreParal()
{
    tam = 0;
}

template <class T>
int ArreParal<T>::insertaOrdenado(int posic, T valor)
{
    int indice, res = 1;

    if (tam < MAX)
    {
        for (indice= tam; indice > posic; indice--)
            Datos[indice] = Datos[indice -1];
        Datos[posic] = valor;
        tam++;
    }
    else res = 0;

    return res;
}

template <class T>
int ArreParal<T>::insertaDesordenado(T valor)
{
    int indice, res = 1;
    if (tam < MAX)
    {
        Datos[tam] = valor;
        tam++;
    }
    else res = 0;

    return res;
}

template <class T>
void ArreParal<T>::elimina(int pos)
{
    int indice;

    tam--;
    for (indice = pos; indice < tam; indice++)
        Datos[indice] = Datos[indice+1];
}

template <class T>
int ArreParal<T>::buscaOrdenado(T valor)
{
    int indice = 0, res;
    while ((indice < tam) && (Datos[indice] < valor))
        indice++;

    if (indice == tam || Datos[indice] > valor)
        res = -(indice + 1);
    else
        res = indice;
    return res;
}

template <class T>
int ArreParal<T>::buscaDesordenado(T valor)
{
    int indice = 0, res = -1;
    while ((indice < tam) && (Datos[indice] != valor))
        indice++;
    if (indice < tam)
        res = indice;
    else
        res = indice;
    return res;
}

template <class T>
T ArreParal<T>::regresaValor(int indice)
{
    return Datos[indice];
}

template <class T>
int ArreParal<T>::regresaTamano()
{
    return tam;
}

template <class T>
istream &operator>> (istream &Lee, ArreParal<T> &objArre)
{
    int indice;
    do {
        Lee >> objArre.tam;
    } while (objArre.tam < 1 || objArre.tam > MAX);

    for (indice = 0; indice < objArre.tam; indice++)
        Lee >> objArre.Datos[indice];

    return Lee;
}

template <class T>
ostream &operator<< (ostream &Escribe, ArreParal<T> &objArre)
{
    int indice;

    if (objArre.tam > 0)
        for (indice = 0; indice < objArre.tam; indice++)
            Escribe << objArre.Datos[indice] << " ";
    else
        cout << "\nNo hay elementos registros";
    return Escribe;
}

#endif // PLANTARREPARAL_H_INCLUDED
