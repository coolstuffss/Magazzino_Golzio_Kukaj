/*
    @author: Stefano Golzio

    header della classe prodotto
    la struttura dati contiene la rappresentazione del protottosottoforma di oggetto
*/

#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>

class Prodotto
{
    public:
        Prodotto(int codice, std::string nome, float prezzo, std::string descrizione, int quantita, int scaffale);
        Prodotto();
        int getCodice();
        std::string getNome();
        float GetPrezzo();
        std::string getDescrizione();
        int getQuantita();
        int getScaffale();

    private:
        int codice; //codice del prodotto univoco
        std::string nome; //
        float prezzo;
        std::string descrizione;
        int quantita;
        int scaffale;
};

#endif //PRODOTTO_h