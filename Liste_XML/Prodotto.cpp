#include <string>

#include "Prodotto.h"

Prodotto::Prodotto(int codice, std::string nome, float prezzo, std::string descrizione, int quantita, int scaffale)
    :codice(codice),
    nome(nome),
    prezzo(prezzo),
    descrizione(descrizione),
    quantita(quantita),
    scaffale(scaffale)
{
    //costruttore base
}

Prodotto::Prodotto()
{
    //costruzione per la creazione di un oggetto temporaneo
}

int Prodotto::getCodice() { return codice; }

std::string Prodotto::getNome() { return nome; }

float Prodotto::GetPrezzo() { return prezzo; }

std::string Prodotto::getDescrizione() { return descrizione; }

int Prodotto::getQuantita() { return quantita; }

int Prodotto::getScaffale() { return scaffale; }