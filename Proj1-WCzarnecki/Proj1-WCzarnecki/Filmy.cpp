#include "stdafx.h"
#include "Filmy.h"
#include <iostream>

Filmy::Filmy(int IDZasobu_, string autor_, string tytul_, string gatunek_, string typ_zasobu_, int rok_powstania_, char *context)
{
	char * pch = strtok_s(NULL, "|", &context);
	IDZasobu = IDZasobu_;
	autor = autor_;
	gatunek = gatunek_;
	tytul = tytul_;
	typ_zasobu = typ_zasobu_;
	rok_powstania = rok_powstania_;
	if (pch != NULL) { rezyser = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { muzyka = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { wytwornia = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { aktor_glowny = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { scenariusz = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
}

Filmy::Filmy(int IDZasobu_, string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, string rezyser_, string aktor_glowny_, string muzyka_, string wytwornia_, string scenariusz_)
{
	IDZasobu = IDZasobu_;
	autor = autor_;
	gatunek = gatunek_;
	tytul = tytul_;
	typ_zasobu = typ_zasobu_;
	rok_powstania = rok_powstania_;
	rezyser = rezyser_;
	aktor_glowny = aktor_glowny_;
	muzyka = muzyka_;
	wytwornia = wytwornia_;
	scenariusz = scenariusz_;
}

void Filmy::edytuj(string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, string rezyser_, string aktor_glowny_, string muzyka_, string wytwornia_, string scenariusz_)
{
	if (autor_ != "") { autor = autor_; }
	if (tytul_ != "") { tytul = tytul_; }
	if (gatunek_ != "") { gatunek = gatunek_; }
	if (typ_zasobu_ != "") { typ_zasobu = typ_zasobu_; }
	if (rok_powstania_ != 13) { rok_powstania = rok_powstania_; } // sprawdziæ jak zareaguje na ""
	if (rezyser_ != "") { rezyser = rezyser_; }
	if (muzyka_ != "") { muzyka = muzyka_; }
	if (wytwornia_ != "") { wytwornia = wytwornia_; }
	if (aktor_glowny_ != "") { aktor_glowny = aktor_glowny_; }
	if (scenariusz_ != "") { scenariusz = scenariusz_; }
}

void Filmy::wyswietlZasob()
{
	cout << "Autor: " << autor << endl;
	cout << "Tytul: " << tytul << endl;
	cout << "Gatunek: " << gatunek << endl;
	cout << "Typ zasobu: " << typ_zasobu << endl;
	cout << "Rok produkcji: " << rok_powstania << endl;
	cout << "Rezyser: " << rezyser << endl;
	cout << "Autor muzyki: " << muzyka << endl;
	cout << "Wytwornia: " << wytwornia << endl;
	cout << "Glowny aktor: " << aktor_glowny << endl;
	cout << "Autor scenariusza: " << scenariusz << endl;
}

string Filmy::wypisz()
{
	return to_string(IDZasobu) + ")"
		+ autor + "|"
		+ tytul + "|"
		+ gatunek + "|"
		+ typ_zasobu + "|"
		+ to_string(rok_powstania) + "|"
		+ rezyser + "|"
		+ aktor_glowny + "|"
		+ muzyka + "|"
		+ wytwornia + "|"

		+ scenariusz + "\n";
}


void Filmy::menu_edytuj()
{
	int rok_powstania_;
	string autor_, gatunek_, tytul_, typ_zasobu_, rezyser_, wytwornia_, muzyka_, aktor_glowny_, scenariusz_;

	cout << "Podaj autora: ";   			cin.ignore();	getline(cin, autor_);
	cout << "Podaj tytul: ";   				cin.ignore();	getline(cin, tytul_);
	cout << "Podaj gatunek: ";   			cin.ignore();	getline(cin, gatunek_);
	cout << "Podaj typ zasobu: ";   		cin.ignore();	getline(cin, typ_zasobu_);
	cout << "Podaj rok powstania filmu: ";  cin.ignore();	cin >> rok_powstania_;
	cout << "Podaj rezysera: "; 			cin.ignore();	getline(cin, rezyser_);
	cout << "Podaj autora muzyki: ";  		cin.ignore();	getline(cin, muzyka_);
	cout << "Podaj wytwornie: "; 			cin.ignore();	getline(cin, wytwornia_);
	cout << "Podaj glownego aktora: ";  	cin.ignore();	getline(cin, aktor_glowny_);
	cout << "Podaj autora scenariusza: "; 	cin.ignore();	getline(cin, scenariusz_);

	edytuj(autor_, gatunek_, tytul_, typ_zasobu_, rok_powstania_, rezyser_, wytwornia_, muzyka_, aktor_glowny_, scenariusz_);
}

Filmy::~Filmy()
{
}

