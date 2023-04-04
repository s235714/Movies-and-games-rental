#pragma once
#include "Zasob.h"
#include <string>
using namespace std;

class Gry :
	public Zasob
{
private:
	string wytwornia;
	string nosnik;

public:
	Gry(int IDZasobu_, string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, string wytwornia_, string nosnik_);
	Gry(int IDZasobu_, string autor_, string tytul_, string gatunek_, string typ_zasobu_, int rok_powstania_, char *context);
	void edytuj(string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, string wytwornia, string nosnik_);
	string wypisz();
	void menu_edytuj();
	void wyswietlZasob();
	~Gry();
};


