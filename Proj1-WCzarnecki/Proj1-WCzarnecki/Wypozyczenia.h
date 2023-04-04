#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Klient.h"
#include "Zasob.h"
using namespace std;

class Wypozyczenia
{
private:
	vector<Klient*> klienci;
	int k;
	vector<auto_ptr<Zasob>> zasoby;
	int z;
	vector<pair<int, int>> wypozyczenia;
	void dodajFilm();
	void dodajGre();
	void dodajMuzyke();
	auto_ptr<Zasob> wczytajZasob(string linia);
public:
	Wypozyczenia();
	void dodajZasob();
	void dodajKlienta();
	void usunZasob();
	void usunKlienta();
	void wyswietlZasob();
	void wyswietlKlienta();
	void wypozycz();
	void zwroc();
	void wczytaj();
	void zapiszZasoby();
	void zapiszKlientow();
	void zapiszWypozyczenia();
	void MenuGlowne();
	void edytujZasob();
	void edytujKlienta();
	~Wypozyczenia();

};