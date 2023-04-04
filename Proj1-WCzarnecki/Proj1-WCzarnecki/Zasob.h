#pragma once
#include <string>
using namespace std;

class Zasob
{
protected:
	string autor;
	string gatunek;
	string tytul;
	string typ_zasobu;
	int IDZasobu;
	int rok_powstania;

public:
	Zasob();
	Zasob(string linia);
	int ID();
	string typ();
	virtual void wyswietlZasob();
	virtual void menu_edytuj();
	virtual string wypisz();
	~Zasob();
};

