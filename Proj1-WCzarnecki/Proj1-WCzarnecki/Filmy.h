#pragma once
#include "Zasob.h"
#include <string>
using namespace std;

class Filmy :
	public Zasob
{
private:
	string rezyser;
	string aktor_glowny;
	string scenariusz;
	string wytwornia;
	string muzyka;

public:
	Filmy(int IDZasobu_, string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, string rezyser_, string muzyka_, string scenariusz_, string aktor_glowny_, string wytwornia_);
	Filmy(int IDZasobu_, string autor_, string tytul_, string gatunek_, string typ_zasobu_, int rok_powstania_, char *context);
	void edytuj(string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, string rezyser_, string aktor_glowny_, string muzyka_, string wytwornia_, string scenariusz_);
	string wypisz();
	void wyswietlZasob();
	void menu_edytuj();
	~Filmy();
};

