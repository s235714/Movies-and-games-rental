#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Wypozyczenia.h"
#include "Muzyka.h"
#include "Gry.h"
#include "Filmy.h"


Wypozyczenia::Wypozyczenia()
{
	k = 0;
	z = 0;
}

void Wypozyczenia::dodajZasob()
{
	int x;
	cout << "Jaki typ zasobu chcesz dodac? \n\n";
	cout << "1) Dodanie filmu\n";
	cout << "2) Dodanie gry\n";
	cout << "3) Dodanie plyty muzycznej\n";
	cout << "Wpisz odpowiednia cyfre: ";

	cin >> x;
	switch (x)
	{
	case 1: dodajFilm(); break;
	case 2: dodajGre(); break;
	case 3: dodajMuzyke(); break;
	default: cout << "Wpisano zla cyfre!"; break;
	}
}

void Wypozyczenia::dodajFilm()
{
	int rok_powstania_;
	string autor_, gatunek_, tytul_, typ_zasobu_, rezyser_, wytwornia_, muzyka_, aktor_glowny_, scenariusz_;

	cin.clear();
	cin.sync();

	cout << "Podaj autora: ";   			cin.ignore();	getline(cin, autor_);
	cout << "Podaj tytul: ";   					getline(cin, tytul_);
	cout << "Podaj gatunek: ";   				getline(cin, gatunek_);
	cout << "Podaj typ zasobu: ";   		getline(cin, typ_zasobu_);
	cout << "Podaj rok powstania filmu: ";  cin >> rok_powstania_;
	cout << "Podaj rezysera: "; 			cin.ignore();	getline(cin, rezyser_);
	cout << "Podaj autora muzyki: ";  			getline(cin, muzyka_);
	cout << "Podaj wytwornie: "; 				getline(cin, wytwornia_);
	cout << "Podaj glownego aktora: ";  		getline(cin, aktor_glowny_);
	cout << "Podaj autora scenariusza: "; 		getline(cin, scenariusz_);

	Filmy *fil = new Filmy(++z, autor_, gatunek_, tytul_, typ_zasobu_, rok_powstania_, rezyser_, muzyka_, wytwornia_, aktor_glowny_, scenariusz_);
	auto_ptr<Filmy> fil_ptr = auto_ptr<Filmy>(fil);
	zasoby.push_back(fil_ptr);

	fstream plik;
	plik.open("zasoby.txt", ios::out | ios::app);

	plik << (fil->wypisz());
	plik.close();
}

void Wypozyczenia::dodajGre()
{
	int rok_powstania_;
	string autor_, gatunek_, tytul_, typ_zasobu_, nosnik_, wytwornia_;

	cin.clear();
	cin.sync();

	cout << "Podaj autora: ";   					 cin.ignore();	getline(cin, autor_);
	cout << "Podaj tytul: ";   						 	getline(cin, tytul_);
	cout << "Podaj gatunek: ";   						getline(cin, gatunek_);
	cout << "Podaj typ zasobu: ";   				 	getline(cin, typ_zasobu_);
	cout << "Podaj rok powstania gry: ";			 cin >> rok_powstania_;

	cout << "Podaj wytwornie: ";  					 cin.ignore();	getline(cin, wytwornia_);
	cout << "Podaj nosnik: "; 							getline(cin, nosnik_);

	Gry *gry = new Gry(++z, autor_, gatunek_, tytul_, typ_zasobu_, rok_powstania_, wytwornia_, nosnik_);
	auto_ptr<Gry> gry_ptr = auto_ptr<Gry>(gry);
	zasoby.push_back(gry_ptr);

	fstream plik;
	plik.open("zasoby.txt", ios::out | ios::app);

	plik << (gry->wypisz());

	plik.close();

}
void Wypozyczenia::dodajMuzyke()
{
	string autor_, gatunek_, tytul_, typ_zasobu_;
	int rok_powstania_, ilosc_utw_;

	cin.clear();
	cin.sync();

	cout << "Podaj autora: ";   					 cin.ignore();	getline(cin, autor_);
	cout << "Podaj tytul: ";   							getline(cin, tytul_);
	cout << "Podaj gatunek: ";   						getline(cin, gatunek_);
	cout << "Podaj typ zasobu: ";   					getline(cin, typ_zasobu_);
	cout << "Podaj rok powstania plyty: ";			cin >> rok_powstania_;
	cout << "Podaj ilosc utworow na plycie: ";		  cin >> ilosc_utw_;

	Muzyka *muz = new Muzyka(++z, autor_, gatunek_, tytul_, typ_zasobu_, rok_powstania_, ilosc_utw_);
	auto_ptr<Muzyka> muz_ptr = auto_ptr<Muzyka>(muz);
	zasoby.push_back(muz_ptr);

	fstream plik;
	plik.open("zasoby.txt", ios::out | ios::app);

	plik << (muz->wypisz());

	plik.close();

}

void Wypozyczenia::dodajKlienta()
{
	string imie_, nazwisko_, email_, nr_tel_;

	cin.clear(); 
	cin.sync();

	cout << "Podaj imie: ";   		cin.ignore();		getline(cin, imie_);
	cout << "Podaj nazwisko: ";   					getline(cin, nazwisko_); 
	cout << "Podaj numer telefonu (bez spacji): "; 	getline(cin, nr_tel_);  
	cout << "Podaj adres e-mail: ";   				getline(cin, email_);  
	
	Klient *kl = new Klient(++k, imie_, nazwisko_, email_, nr_tel_);
	klienci.push_back(kl);

	fstream plik;
	plik.open("klienci.txt", ios::out | ios::app);

	plik << k << ")" << imie_ << "|" << nazwisko_ << "|" << nr_tel_
		<< "|" << email_ << endl;

	plik.close();
}
void Wypozyczenia::usunZasob()
{
	int ID;
	cout << "Podaj numer zasobu, ktory chcesz usunac: ";			cin >> ID;

	for (vector<auto_ptr<Zasob>>::iterator it = zasoby.begin(); it != zasoby.end(); ++it)
	{
		if ((*it)->ID() == ID) {
			zasoby.erase(it);
			break;
		}
	}
	zapiszZasoby();
}

void Wypozyczenia::usunKlienta()
{
	int ID;
	cout << "Podaj numer klienta, ktorego dane chcesz usunac: ";			cin >> ID;

	for (vector<Klient*>::iterator it = klienci.begin(); it != klienci.end(); ++it)
	{
		if ((*it)->ID() == ID) {
			klienci.erase(it);
			break;
		}
	}
	zapiszKlientow();
}

void Wypozyczenia::wyswietlZasob()
{
	int IDZasobu;
	cout << "Podaj numer zasobu: ";			cin >> IDZasobu;

	for (vector<auto_ptr<Zasob>>::iterator it = zasoby.begin(); it != zasoby.end(); ++it)
	{
		if ((*it)->ID() == IDZasobu)
		{
			if ((*it)->typ() == "film")
			{
				Filmy *f = dynamic_cast<Filmy*>(it->get());
				f->wyswietlZasob();
			}
			else if ((*it)->typ() == "gra")
			{
				Gry *g = dynamic_cast<Gry*>(it->get());
				g->wyswietlZasob();
			}
			else if ((*it)->typ() == "muzyka")
			{
				Muzyka *m = dynamic_cast<Muzyka*>(it->get());
				m->wyswietlZasob();
			}
			else
			{
				cout << "Nieprawidlowy typ zasobu!";
			}
			system("pause");
			return;
		}
	}
	cout << "Nie ma takiego numeru zasobu!" << endl;
	system("pause");
}

void Wypozyczenia::wyswietlKlienta()
{
	int IDKlienta;
	cout << "Podaj numer klienta: ";			cin >> IDKlienta;

	for (vector<Klient*>::iterator it = klienci.begin(); it != klienci.end(); ++it)
	{
		if ((*it)->ID() == IDKlienta)
		{
			(*it)->wyswietlKlienta();
			system("pause");
			return;
		}
	}
	cout << "Nie ma takiego klienta!" << endl;
}

void Wypozyczenia::edytujZasob()
{
	bool n = true;
	int IDZasobu;

	while (n)
	{
		cout << "Podaj numer zasobu: ";			cin >> IDZasobu;

		for (vector<auto_ptr<Zasob>>::iterator it = zasoby.begin(); it != zasoby.end(); ++it)
		{
			if ((*it)->ID() == IDZasobu) {
				if ((*it)->typ() == "film")
				{
					Filmy *f = dynamic_cast<Filmy*>(it->get());
					f->menu_edytuj();
				}
				else if ((*it)->typ() == "gra")
				{
					Gry *g = dynamic_cast<Gry*>(it->get());
					g->menu_edytuj();
				}
				else if ((*it)->typ() == "muzyka")
				{
					Muzyka *m = dynamic_cast<Muzyka*>(it->get());
					m->menu_edytuj();
				}
				else
				{
					cout << "Nieprawidlowy typ zasobu!";
				}
				zapiszZasoby();
				system("pause");
				return;
			}
		}
		cout << "Nie ma takiego numeru zasobu!\nCzy chcesz wpisac jeszcze raz numer klienta i zasobu? (tak - 1, nie - 0): ";
		cin >> n;
	}
}

void Wypozyczenia::edytujKlienta()
{
	bool n = true;
	int IDKlienta;

	while (n)
	{
		cout << "Podaj numer klienta: ";			cin >> IDKlienta;

		for (vector<Klient*>::iterator it = klienci.begin(); it != klienci.end(); ++it)
		{
			if ((*it)->ID() == IDKlienta) {
				(*it)->menu_edytuj();
				zapiszKlientow();
				return;
			}
		}
		cout << "Nie ma takiego klienta!\nCzy chcesz wpisac jeszcze raz numer klienta i zasobu? (tak - 1, nie - 0): ";
		cin >> n;
	}
}

void Wypozyczenia::wypozycz()
{

	//int x;
	//cout << "Jaki typ zasobu chcesz wypozyczyc? \n\n";
	//cout << "1) Wypozyczenie filmu\n";
	//cout << "2) Wypozyczenie gry\n";
	//cout << "3) Wypozyczenie plyty muzycznej\n";
	//cout << "Wpisz odpowiednia cyfre: ";

	//cin >> x;
	//switch (x)
	//{
	//case 1: dodajFilm(); break;
	//case 2: dodajGre(); break;
	//case 3: dodajMuzyke(); break;
	//default: cout << "Wpisano zla cyfre!"; break;
	//}

	int ID_k, ID_z;
	bool n;
	bool wybrane = false;
	while (!wybrane)
	{
		cout << "Podaj numer klienta: ";		cin >> ID_k;
		cout << "Podaj numer zasobu: ";			cin >> ID_z;

		wybrane = true;
		for (vector<pair<int, int>>::iterator it = wypozyczenia.begin(); it != wypozyczenia.end(); ++it)
		{
			if (it->second == ID_z)
			{
				cout << "Ten zasob jest juz wypozyczony! \nCzy chcesz wpisac jeszcze raz numer klienta i zasobu? (tak - 1, nie - 0)";
				cin >> n;
				if (n)
				{
					wybrane = false;
					break;
				}
				else
				{
					return;
				}
			}
		}
	}
	pair<int, int> para = make_pair(ID_k, ID_z);
	wypozyczenia.push_back(para);

	fstream plik;
	plik.open("wypozyczenia.txt", ios::out | ios::app);
	plik << ID_k << "|" << ID_z;
	plik.close();
}

void Wypozyczenia::zwroc()
{
	// pytasz uzytkownika
	//int x;
	//cout << "Jaki typ zasobu chcesz zwocic? \n\n";
	//cout << "1) Zwrot filmu\n";
	//cout << "2) Zwrot gry\n";
	//cout << "3) Zwrot plyty muzycznej\n";
	//cout << "Wpisz odpowiednia cyfre: ";

	//cin >> x;
	//switch (x)
	//{
	//case 1: zwrocFilm(); break;
	//case 2: zwrocGre(); break;
	//case 3: zwrocMuzyke(); break;
	//default: cout << "Wpisano zla cyfre!"; break;
	//}

	int ID_k, ID_z;
	bool n = true;
	while (n)
	{
		cout << "Podaj numer klienta: ";		cin >> ID_k;
		cout << "Podaj numer zasobu: ";			cin >> ID_z;

		for (vector<pair<int, int>>::iterator it = wypozyczenia.begin(); it != wypozyczenia.end(); ++it)
		{
			if (it->first == ID_k && it->second == ID_z)
			{
				wypozyczenia.erase(it);
				zapiszWypozyczenia();
				return;
			}
		}
		cout << "Ten zasob nie jest wypozyczony przez tego klienta! \nCzy chcesz wpisac jeszcze raz numer klienta i zasobu? (tak - 1, nie - 0)";
		cin >> n;
		if (!n)
		{
			return;
		}
	}
}

void Wypozyczenia::wczytaj()
{
	// zasoby
	string linia;
	fstream plik;
	int maxID = 0;

	plik.open("zasoby.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Blad odczytu pliku!";
		getchar();
		exit(1);
	}
	while (getline(plik, linia)) {
		//auto_ptr<Zasob> zas = wczytajZasob(linia);
		/*if ((zas.get())->ID() > maxID)
		{
			maxID = (zas.get())->ID();
		}*/
		zasoby.push_back(wczytajZasob(linia));
	}
	plik.close();
	z = zasoby.size();

	// klienci
	maxID = 0;

	plik.open("klienci.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Blad odczytu pliku!";
		getchar();
		exit(1);
	}
	while (getline(plik, linia)) {
		Klient *kl = new Klient(linia);
		if (kl->ID() > maxID)
		{
			maxID = kl->ID();
		}
		klienci.push_back(kl);
	}
	plik.close();
	k = maxID;

	// wypozyczenia

	plik.open("wypozyczenia.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Blad odczytu pliku!";
		getchar();
		exit(1);
	}
	int ID_k, ID_z;
	while (getline(plik, linia, '|'))
	{
		ID_k = stoi(linia);
		if (getline(plik, linia))
		{
			ID_z = stoi(linia);
			wypozyczenia.push_back(make_pair(ID_k, ID_z));
		}
	}
	plik.close();
}

auto_ptr<Zasob> Wypozyczenia::wczytajZasob(string linia)
{
	auto_ptr<Zasob> zas = auto_ptr<Zasob>(new Zasob());
	int IDZasobu, rok_powstania;
	string autor, tytul, gatunek, typ_zasobu;
	char * pch;
	char * context = NULL;
	char * linia_c = new char[linia.length() + 1];
	strcpy_s(linia_c, linia.length() + 1, linia.c_str());
	pch = strtok_s(linia_c, ")|", &context);
	if (pch != NULL) { IDZasobu = atoi(pch); pch = strtok_s(NULL, "|", &context); }
	else { return zas; }
	if (pch != NULL) { autor = pch; pch = strtok_s(NULL, "|", &context); }
	else { return zas; }
	if (pch != NULL) { tytul = pch; pch = strtok_s(NULL, "|", &context); }
	else { return zas; }
	if (pch != NULL) { gatunek = pch; pch = strtok_s(NULL, "|", &context); }
	else { return zas; }
	if (pch != NULL) { typ_zasobu = pch; pch = strtok_s(NULL, "|", &context); }
	else { return zas; }
	if (pch != NULL) { rok_powstania = atoi(pch); }
	else { return zas; }

	if (typ_zasobu == "film")
	{
		 zas = auto_ptr<Zasob>(new Filmy(IDZasobu, autor, tytul, gatunek, typ_zasobu, rok_powstania, context));
	}
	else if (typ_zasobu == "gra")
	{
		zas = auto_ptr<Zasob>(new Gry(IDZasobu, autor, tytul, gatunek, typ_zasobu, rok_powstania, context));
	}
	else if (typ_zasobu == "muzyka")
	{
		zas = auto_ptr<Zasob>(new Muzyka(IDZasobu, autor, tytul, gatunek, typ_zasobu, rok_powstania, context));
	}
	return zas;
}

void Wypozyczenia::zapiszZasoby()
{
	fstream plik;
	// chyba trzeba bêdzie usun¹æ plik
	plik.open("zasoby.txt", ios::out);

	for (vector<auto_ptr<Zasob>>::iterator it = zasoby.begin(); it != zasoby.end(); ++it)
	{
		plik << ((*it)->wypisz());
	}
	plik.close();
}

void Wypozyczenia::zapiszKlientow()
{
	fstream plik;
	// chyba trzeba bêdzie usun¹æ plik
	plik.open("klienci.txt", ios::out);

	for (vector<Klient*>::iterator it = klienci.begin(); it != klienci.end(); ++it)
	{
		plik << ((*it)->wypisz());
	}
	plik.close();
}


void Wypozyczenia::zapiszWypozyczenia()
{
	fstream plik;
	// chyba trzeba bêdzie usun¹æ plik
	plik.open("wypozyczenia.txt", ios::out);

	for (vector<pair<int, int>>::iterator it = wypozyczenia.begin(); it != wypozyczenia.end(); ++it)
	{
		plik << (it->first) << "|" << (it->second);
	}
	plik.close();

}

void Wypozyczenia::MenuGlowne()
{
	int x;
	for (; ;)
	{
		cout << "         ***Wypozyczalna filmow, muzyki i gier***\n\n";

		{
			cout << "-------MENU GLOWNE-------\n";
			cout << "1) Dodanie filmu, muzyki lub gry \n";
			cout << "2) Usuniecie filmu, muzyki lub gry \n";
			cout << "3) Edycja danych filmu, muzyki lub gry \n";
			cout << "4) Wyswietlenie danych filmu, muzyki lub gry \n";
			cout << "5) Dodanie nowego klienta \n";
			cout << "6) Usuniecie danych klienta \n";
			cout << "7) Edycja danych klienta \n";
			cout << "8) Wyswietlenie danych klienta \n";
			cout << "9) Wypozyczenie zasobu \n";
			cout << "10) Zwrot zasobu \n";
			cout << "11) Koniec programu \n\n";

			cout << "Podaj odpowiednia cyfre: ";
			cin >> x;

			switch (x)
			{
			case 1: dodajZasob(); break;
			case 2: usunZasob(); break;
			case 3: edytujZasob(); break;
			case 4: wyswietlZasob();  break;
			case 5: dodajKlienta(); break;
			case 6: usunKlienta(); break;
			case 7: edytujKlienta(); break;
			case 8: wyswietlKlienta(); break;
			case 9: wypozycz(); break;
			case 10: zwroc(); break;
			case 11: cout << "Koniec programu \n"; exit(0); break;
			default: "Podano zly znak!"; break;
			}
			system("cls");
		}
	}
}

Wypozyczenia::~Wypozyczenia()
{
}
