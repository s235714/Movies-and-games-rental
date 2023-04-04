#include "stdafx.h"
#include "Klient.h"
#include <iostream>
#include <fstream>

Klient::Klient(string linia)
{
	char * pch;
	char * context = NULL;
	char * linia_c = new char[linia.length() + 1];
	strcpy_s(linia_c, linia.length() + 1, linia.c_str());
	pch = strtok_s(linia_c, ")|", &context);
	if (pch != NULL) { IDKlienta = atoi(pch); pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { imie = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { nazwisko = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { nr_tel = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
	if (pch != NULL) { email = pch; pch = strtok_s(NULL, "|", &context); }
	else { return; }
}


Klient::Klient(int IDKlienta_, string imie_, string nazwisko_, string email_, string nr_tel_)
{
	imie = imie_;
	nazwisko = nazwisko_;
	email = email_;
	nr_tel = nr_tel_;
	IDKlienta = IDKlienta_;
}

void Klient::edytuj(string imie_, string nazwisko_, string email_, string nr_tel_)
{
	imie = imie_;
	nazwisko = nazwisko_;
	email = email_;
	nr_tel = nr_tel_;
}

string Klient::wypisz()
{
	return IDKlienta + ")"
		+ imie + "|"
		+ nazwisko + "|"
		+ nr_tel + "|"
		+ email + "\n";
}

int Klient::ID()
{
	return IDKlienta;
}

void Klient::wyswietlKlienta()
{
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko: " << nazwisko << endl;
	cout << "Numer telefonu: " << nr_tel << endl;
	cout << "Adres e-mail: " << email << endl;
}

void Klient::menu_edytuj()
{
	string imie_, nazwisko_, nr_tel_, email_;

	cout << "Podaj imie: ";   					cin.ignore();	getline(cin, imie_);
	cout << "Podaj nazwisko: ";   				cin.ignore();	getline(cin, nazwisko_);
	cout << "Podaj numer telefonu: ";   		cin.ignore();	getline(cin, nr_tel_);
	cout << "Podaj adres e-mail: ";   			cin.ignore();	getline(cin, email_);

	edytuj(imie_, nazwisko_, nr_tel_, email_);
}

Klient::~Klient()
{
}

