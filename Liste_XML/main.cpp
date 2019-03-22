#include <iostream>
#include <cstdlib>
#include <list>
#include <string>

#include "Prodotto.h"

using namespace std;

#define MAX_CARATTERI 50

typedef struct prodotto
{
    int codice;
    string nome;
    int quantita;
    float prezzo;
}prodotto;

Prodotto& prendiDati();
void stampaDati(Prodotto &);

int main()
{
    // list<int> sas;

    // for(int i = 0; i < 10; i++)
    // {
    //     sas.push_back(i);
    // }
    
    // for(auto i = sas.begin(); i != sas.end(); i++)
    // {
    //     cout << *i << endl;
    // }

    Prodotto &prova = prendiDati();
    stampaDati(prova);

    system("pause");
    return 0;
}

Prodotto& prendiDati()
{
    Prodotto temp{};
    cout << "inserire il codice del prodotto: "; cin >> temp.codice;
    cout << "inserire il nome del prodotto: "; cin >> temp.nome;
    cout << "inserire il prezzo del prodotto (numero con la virgola)"; cin >> temp.prezzo;
    cout << "inserire la descrizione del prodotto: "; cin >> temp.descrizione;
    cout << "inserire la quantita del prodotto: "; cin >> temp.quantita;
    cout << "inserire l'indentificativo dello scaffale: "; cin >> temp.scaffale;

    return temp;
}

void stampaDati(Prodotto *p)
{
    cout << p->getCodice() << endl;
    cout << p->getNome() << endl;
    cout << p->getPrezzo() << endl;
    cout << p->getDescrizione() << endl;
    cout << p->getQuantita() << endl;
    cout << p->getScaffale() << endl;
}