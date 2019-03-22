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
        Prodotto(int, std::string, float, std::string, int, int); //costruttore per l'oggetto
        Prodotto(); //costruttore per un oggetto temporaneo
        int getCodice();
        std::string getNome();
        float getPrezzo();
        std::string getDescrizione();
        int getQuantita();
        int getScaffale();
        friend Prodotto& prendiDati();

    private:
        int codice; //codice del prodotto univoco
        std::string nome; //nome del prodotto
        float prezzo; //prezzo in euro
        std::string descrizione; //descrizione del prodotto massimo 50 caratteri
        int quantita; //quante copie ce ne sono
        int scaffale; //id dello scaffale in cui è riposto
};

#endif //PRODOTTO_h