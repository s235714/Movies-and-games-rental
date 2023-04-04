#include "stdafx.h"
#include "Gry.h"
#include <iostream>

Gry::Gry(int IDZasobu_, string autor_, string tytul_, string gatunek_, string typ_zasobu_, int rok_powstania_, char *context)
{
	IDZasobu = IDZasobu_;
	autor = autor_;
	gatunek = gatunek_;
	tytul = tytul_;
	typ_zasobu = typ_zasobu_;
	rok_powstania = rok_powstania_;
	char * pch = strtok_s(NULL, "|", &context);
	if (pch != NULL) { wytwornia = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { nosnik = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
}

Gry::Gry(int IDZasobu_, string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, string wytwornia_, string nosnik_)
{
	IDZasobu = IDZasobu_;
	autor = autor_;
	gatunek = gatunek_;
	tytul = tytul_;
	typ_zasobu = typ_zasobu_;
	rok_powstania = rok_powstania_;
	wytwornia = wytwornia_;
	nosnik = nosnik_;
}

void Gry::wyswietlZasob()
{
	cout << "Autor: " << autor << endl;
	cout << "Tytul: " << tytul << endl;
	cout << "Gatunek: " << gatunek << endl;
	cout << "Typ zasobu: " << typ_zasobu << endl;
	cout << "Rok produkcji: " << rok_powstania << endl;
	cout << "Wytwornia: " << wytwornia << endl;
	cout << "Nosnik: " << nosnik << endl;
}

void Gry::edytuj(string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, string wytwornia_, string nosnik_)
{
	if (autor_ != "") { autor = autor_; }
	if (tytul_ != "") { tytul = tytul_; }
	if (gatunek_ != "") { gatunek = gatunek_; }
	if (typ_zasobu_ != "") { typ_zasobu = typ_zasobu_; }
	if (rok_powstania_ != 13) { rok_powstania = rok_powstania_; } // sprawdziæ jak zareaguje na ""
	if (wytwornia_ != "") { wytwornia = wytwornia_; }
	if (nosnik_ != "") { nosnik = nosnik_; }
}

void Gry::menu_edytuj()
{
	int rok_powstania_;
	string autor_, gatunek_, tytul_, typ_zasobu_, wytwornia_, nosnik_;

	cout << "Podaj autora: ";   					 cin.ignore();	getline(cin, autor_);
	cout << "Podaj tytul: ";   						 cin.ignore();	getline(cin, tytul_);
	cout << "Podaj gatunek: ";   					 cin.ignore();	getline(cin, gatunek_);
	cout << "Podaj typ zasobu: ";   				 cin.ignore();	getline(cin, typ_zasobu_);
	cout << "Podaj rok powstania gry: ";			 cin >> rok_powstania_;
	cout << "Podaj wytwornie: ";  					 cin.ignore();	getline(cin, wytwornia_);
	cout << "Podaj nosnik: "; 						 cin.ignore();	getline(cin, nosnik_);

	edytuj(autor_, gatunek_, tytul_, typ_zasobu_, rok_powstania_, wytwornia, nosnik_);
}

string Gry::wypisz()
{
	return to_string(IDZasobu) + ")"
		+ autor + "|"
		+ tytul + "|"
		+ gatunek + "|"
		+ typ_zasobu + "|"
		+ to_string(rok_powstania) + "|"
		+ wytwornia + "|"
		+ nosnik + "\n";
}

Gry::~Gry()
{
}

