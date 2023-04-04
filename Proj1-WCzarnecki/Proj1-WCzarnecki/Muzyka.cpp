#include "stdafx.h"
#include "Muzyka.h"
#include <iostream>

Muzyka::Muzyka(int IDZasobu_, string autor_, string tytul_, string gatunek_, string typ_zasobu_, int rok_powstania_, char *context)
{
	char * pch = strtok_s(NULL, "|", &context);
	if (pch != NULL) { ilosc_utw = atoi(pch); pch = strtok_s(NULL, "|", &context); }
	else { return; }
}

Muzyka::Muzyka(int IDZasobu_, string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, int ilosc_utw_)
{
	IDZasobu = IDZasobu_;
	autor = autor_;
	gatunek = gatunek_;
	tytul = tytul_;
	typ_zasobu = typ_zasobu_;
	rok_powstania = rok_powstania_;
	ilosc_utw = ilosc_utw_;
}

void Muzyka::wyswietlZasob()
{
	cout << "Autor: " << autor << endl;
	cout << "Tytul: " << tytul << endl;
	cout << "Gatunek: " << gatunek << endl;
	cout << "Typ zasobu: " << typ_zasobu << endl;
	cout << "Rok produkcji: " << rok_powstania << endl;
	cout << "Ilosc utworow: " << ilosc_utw << endl;
}

void Muzyka::edytuj(string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, int ilosc_utw_)
{
	if (autor_ != "") { autor = autor_; }
	if (tytul_ != "") { tytul = tytul_; }
	if (gatunek_ != "") { gatunek = gatunek_; }
	if (typ_zasobu_ != "") { typ_zasobu = typ_zasobu_; }
	if (rok_powstania_ != 13) { rok_powstania = rok_powstania_; } // sprawdziæ jak zareaguje na ""
	if (ilosc_utw_ != 13) { ilosc_utw = ilosc_utw_; }
}

void Muzyka::menu_edytuj()
{
	int rok_powstania_, ilosc_utw_;
	string autor_, gatunek_, tytul_, typ_zasobu_;

	cout << "Podaj autora: ";   					 cin.ignore();	getline(cin, autor_);
	cout << "Podaj tytul: ";   						 cin.ignore();	getline(cin, tytul_);
	cout << "Podaj gatunek: ";   					 cin.ignore();	getline(cin, gatunek_);
	cout << "Podaj typ zasobu: ";   				 cin.ignore();	getline(cin, typ_zasobu_);
	cout << "Podaj rok powstania plyty: ";			 cin.ignore();	cin >> rok_powstania_;
	cout << "Podaj ilosc utworow na plycie: ";  	 cin.ignore();  cin >> ilosc_utw_;

	edytuj(autor_, gatunek_, tytul_, typ_zasobu_, rok_powstania_, ilosc_utw_);
}

string Muzyka::wypisz()
{
	return to_string(IDZasobu) + ")"
		+ autor + "|"
		+ tytul + "|"
		+ gatunek + "|"
		+ typ_zasobu + "|"
		+ to_string(rok_powstania) + "|"
		+ to_string(ilosc_utw) + "\n";
}

Muzyka::~Muzyka()
{
}
