/*
    @author: Stefano Golzio

    programma C++ per la creazione di un file .xml contenente le informazioni sui prodotti di un magazzino
*/

// list<int> sas;

// for(int i = 0; i < 10; i++)
// {
//     sas.push_back(i);
// }

// for(auto i = sas.begin(); i != sas.end(); i++)
// {
//     cout << *i << endl;
// }

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <fstream>

using namespace std;

#define MAX_CARATTERI 50 //caratteri massimi per la descrizione del prodotto

typedef struct struct_prodotto //struttura dati che contiene i dati del prodotto
{
    int codice; //codice del prodotto univoco
    string nome; //nome del prodotto
    float prezzo; //prezzo in euro
    string descrizione; //descrizione del prodotto massimo 50 caratteri
    int quantita; //quante copie ce ne sono
    int scaffale; //id dello scaffale in cui è riposto
}prodotto;

/*funzione che stampa su file il tag magazzino con l'apposito id di magazzino*/
// void stampaMagazzino(FILE *, int);

/*funzione che stampa sul file il prdotto*/
void stampaProdotto(ofstream, prodotto *);

int main()
{
    ofstream FileMagazzini{"FileMagazzini.xml"}; //file dove andrò a scrivere la struttura XML
    int magazzino; //codice del magazzino che sto riempiendo
    prodotto prova = {
        1,
        "jwg",
        100.00,
        "hfjskdhfjkdshfkhsdkjfhdkfhdf",
        666,
        69
    };

    cout << "inserire il codice del magazzino: "; cin >> magazzino;
    
    //stampo la linea di intestazione nel file
    fprintf(FileMagazzini, "<?xml version=\"1.0\"?>\n");
    fprintf(FileMagazzini, "<magazzino id=\"%d\">\n", magazzino);
    stampaProdotto(FileMagazzini, &prova);
    fprintf(FileMagazzini, "</magazzino>\n");

    system("pause");
    return 0;
}

void stampaProdotto(ofstream file, prodotto *p)
{
    fprintf(file, "\t<prodotto>\n");
        fprintf(file, "\t\t<codice>%d</codice>\n", p->codice);
        fprintf(file, "\t\t<nome>%s</nome>\n", p->nome);
        fprintf(file, "\t\t<quantita>%d</quantita>\n", p->quantita);
        fprintf(file, "\t\t<descrizione>%s</descrizione>\n", p->descrizione);
        fprintf(file, "\t\t<scaffale>%d</scaffale>\n", p->scaffale);
        fprintf(file, "\t\t<prezzo>%.2f</prezzo>\n", p->prezzo);
    fprintf(file, "\t</prodotto>\n");
}