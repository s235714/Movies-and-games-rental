#pragma once
#include "Zasob.h"
#include <string>
using namespace std;

class Muzyka :
	public Zasob
{
private:
	int ilosc_utw;
public:
	Muzyka(int IDZasobu_, string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, int ilosc_utw_);
	Muzyka(int IDZasobu_, string autor_, string tytul_, string gatunek_, string typ_zasobu_, int rok_powstania_, char *context);
	void edytuj(string autor_, string gatunek_, string tytul_, string typ_zasobu_, int rok_powstania_, int ilosc_utw_);
	void wyswietlZasob();
	string wypisz();
	void menu_edytuj();
	~Muzyka();
};

