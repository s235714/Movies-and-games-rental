// Proj1_WCzarnecki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Wypozyczenia.h"

int main()
{
	Wypozyczenia wyp;

	wyp.wczytaj();

	wyp.MenuGlowne();

	system("pause");

	return 0;
}

