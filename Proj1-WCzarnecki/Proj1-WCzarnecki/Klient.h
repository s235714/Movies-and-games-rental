#pragma once
#include <string>
using namespace std;
class Klient
{
private:
	string imie;
	string nazwisko;
	string email;
	string nr_tel;
	int IDKlienta;

public:
	Klient(int IDKlienta_, string imie_, string nazwisko_, string email_, string nr_tel_);
	Klient(string linia);
	void edytuj(string imie_, string nazwisko_, string email_, string nr_tel_);
	string wypisz();
	int ID();
	void wyswietlKlienta();
	void menu_edytuj();
	~Klient();
};


