/*
    @author: Stefano Golzio

    programma C++ per la creazione di un file .xml contenente le informazioni sui prodotti di un magazzino

    il programma avrà un menu dal quale può scegliere le azioni
    1 - inserisci prodotti: carica la lista con i prodotti cghe l'utente inserisce, chiede di immettere l'id del magazzino
    2 - salva file: scrive e chiude il file con gli elementi della lista presenti
    3 - esci:  esce dal programma
    se non viene inserito un numero da 1 a 5 cverrà visualizzato un messaggio di errore

    viengono inseriti nella lista i prodotti che appartengono ad un magazzino,
    se si vogliono caricare dei prodotti di un altro magazzino bisogna tornare al menu principale,
    salvare la lista sul file e riniziare da capo
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
    int magazzino; //id del magazzino in cui è presente il prodotto
}prodotto;

/*funzione che stampa sul file il prdotto
file per la scrittura dei prodotti nei magazzini, struttura dati contenente il prodotto*/
void newProdotto(fstream *, list<prodotto>::iterator);

/*prende dalla tastiera i dati del prodotto*/
prodotto prendiDati();

int main()
{
    fstream FileMagazzini{"FileMagazzini.xml", ios::app}; //file dove andrò a scrivere la struttura XML
    int magazzino, //codice del magazzino che sto riempiendo
        scelta; //scelta effettuata dall'utente nel menu
    prodotto temp; //variabile per lo storage temporaneo del prodotto
    char continuaInserimentoProdotti;
    bool esci; //quando è settata a flase esce dal programma
    list<prodotto> magazzini; //lista che contiene

    FileMagazzini << "<document>\n"; //scrivo il tag principale sul file

    do
    {
        system("cls");
        //informo l'utente delle possibilità che ha a disposizione
        cout << "------------------------------" << endl;
        cout << "1 - inserisci i prodotti" << endl;
        cout << "2 - salva file" << endl;
        cout << "3 - esci" << endl;
        cout << "------------------------------" << endl;

        cout << endl << "scegli un operazione: "; cin >> scelta; //chiedo all'utente quale azione vuole intraprendere

        esci = true;
        switch(scelta)
        {
            case 1:
                system("cls");
                bool continua;
                cout << "inserisci il codice del magazzino: " << endl; cin >> magazzino; //richiedo all'utente il codice del magazzino
                do
                {
                    continua = true; //se è uguale a false esce dal ciclo
                    temp = prendiDati(); //prendo i dati dalla tastiera
                    temp.magazzino = magazzino; //inserisco il codice del magazzino nella variabile per scrivere correttamente le informazioni sul file XML
                    magazzini.push_front(temp); //inserisco l'elemento nella lista
                    cout << "continuare?(S/n): "; cin >> continuaInserimentoProdotti;
                    continua = continuaInserimentoProdotti == 'S' || continuaInserimentoProdotti == 's' ? true : false;
                }while(continua);
                break;

            case 2:
                system("cls");
                FileMagazzini << endl << "<magazzino id=\"" << magazzino << "\">" << endl;
                for(auto i = magazzini.begin(); i != magazzini.end(); i++)
                {
                    if(magazzino == i->magazzino)
                        newProdotto(&FileMagazzini, i);
                    else
                    {
                        magazzino = i->magazzino;
                        FileMagazzini << "</magazzino>" << endl;
                        FileMagazzini << endl << "<magazzino id=\"" << magazzino << "\">" << endl;
                        newProdotto(&FileMagazzini, i);
                    }
                }
                FileMagazzini << "</magazzino>" << endl;
                break;

            case 3:
                FileMagazzini << "\n</document>"; //chiudo il tag principale
                FileMagazzini.close();
                esci = false; //esce dal programma
                break;

            default:
                cout << "[ERRORE] inserire numeri da 1 a 3" << endl;
                break;
        } 
    }while(esci);

    return 0;
}

void newProdotto(fstream *file, list<prodotto>::iterator p)
{
    *file << "\t<prodotto>" << endl;
        *file << "\t\t<codice>" << p->codice << "</codice>" << endl;
        *file << "\t\t<nome>" << p->nome << "</nome>" << endl;
        *file << "\t\t<quantita>" << p->quantita << "</quantita>" << endl;
        *file << "\t\t<descrizione>" << p->descrizione << "</descrizione>" << endl;
        *file << "\t\t<scaffale>" << p->scaffale << "</scaffale>" << endl;
        *file << "\t\t<prezzo>" << p->prezzo << "</prezzo>" << endl;
    *file << "\t</prodotto>" << endl;
}

prodotto prendiDati()
{
    prodotto p; //variabile temporanea per prendere i dati dalla tastiera
    cout << "inserire il codice del prodotto: "; cin >> p.codice;
    fflush(stdin); //svuoto il buffer di entrata dei dati per riuscire a prendere la stringa con gli spazi
    cout << "inserire il nome del prodotto: "; getline(cin, p.nome); //prendo la stringa con gli spazi
    cout << "inserire il prezzo del prodotto: "; cin >> p.prezzo;
    fflush(stdin); //svuoto il buffer di entrata dei dati per riuscire a prendere la stringa con gli spazi
    cout << "inserire la descrizione del prodotto: "; getline(cin, p.descrizione); //prendo la stringa con gli spazi
    cout << "inserire la quantita del prodotto: "; cin >> p.quantita;
    cout << "inserire il codice dello scaffale in cui è situato il prodotto: "; cin >> p.scaffale;
    //ritorno la variabile
    return p;
}