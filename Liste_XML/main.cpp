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

/*file che serve per stampare l'intestazione sul file*/
void stampaIntestazione(FILE *, int, prodotto *);

int main()
{
    FILE *FileMagazzini; //file dove andrò a scrivere la struttura XML
    int magazzino; //codice del magazzino che sto riempiendo
    prodotto prova = {
        1,
        "Dildo di gomma",
        100.00,
        "Bellissimi dildi di gomma per uso personale",
        666,
        69
    };

    cout << "inserire il codice del magazzino: "; cin >> magazzino;

    system("pause");
    return 0;
}

void stampaIntestazione(FILE *file, int magazzino, prodotto *p)
{
    // file << "<?xml version=\"1.0\"?>" << endl;
    // file << "<magazzino id=\"" << magazzino << "\">" << endl;
    //     file << "\t<prodotto>" << endl;
    //         file << "\t\t<codice>" << p->codice << "</codice>" << endl;
    //         file << "\t\t<nome>" << p->nome << "</nome>" << endl;
    //         file << "\t\t<quantita>" << p->quantita << "</quantita>" << endl;
    //         file << "\t\t<descrizione>" << p->descrizione << "</descrizione>" << endl;
    //         file << "\t\t<scaffale>" << p->scaffale << "</scaffale>" << endl;
    //         file << "\t\t<prezzo>" << p->prezzo << "</prezzo>" << endl;
    //     file << "\t</prodotto>" << endl;
    // file << "</magazzino>" << endl;

}