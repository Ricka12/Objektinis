#include "Mylib.h"
struct studentas {
	string vardas = "", pavarde = "";
	vector<int> paz;
	int egz = 0;
};
void pildymas(studentas& temp);
void print( studentas& temp);
double vid( studentas& temp);
double mid( studentas& temp);

int paz_sk;
int atsitiktinai;

int main() {
	char uzkl;
	vector<studentas> grupe;
	int n = 1;
	studentas laikinas;
	do {
		cout << "Kiek pazymiu turi studentai?():  ";
		cin >> paz_sk;
		if (paz_sk <= 0)
		{
			cout << "Iveskite skaiciu didesni uz 0" << endl;
		}
	} while (paz_sk <= 0);

	cout << "Ar norite kad pazymiai butu generuojami atsitiktinai(1 jei taip, 0 jei ne):  ";
	cin >> atsitiktinai;
	do {
		cout << "Iveskite studento duomenys: \n";
		pildymas(laikinas);
		grupe.push_back(laikinas);
		cout << "Pabaigus spauskite n, kitaip nuspasukit koki kita klavisa ir iveskite studento duomenis: ";
		cin >> uzkl;
	} while (uzkl != 'n' && uzkl !='N');
	cout << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(Vid.)" << " /" << " Galutinis(Med)" << endl;
	for ( auto &i:grupe)	print(i);
	grupe.clear();
}

void pildymas(studentas& temp)
{
	int p;
	cout << "Iveskite varda ir pavarde: ";
	cin >> temp.vardas >> temp.pavarde;
	if (atsitiktinai == 1)
	{
		srand(time(NULL));
		for (int i = 0; i < paz_sk; i++)
		{
			temp.paz.push_back((rand() % 10) + 1) ;
		}
		temp.egz = (rand() % 10) + 1;
	}

	else
	{
		cout << "Iveskite " << paz_sk << " pazymius: ";
		for (int i = 0; i < paz_sk; i++)
		{
			cin >> p;
			temp.paz.push_back(p);
		}

		cin.clear();
		cout << "Iveskite egzamino pazymi: ";
		do
		{
			cin >> temp.egz;
			if (temp.egz <= 0 || temp.egz > 10)
			{
				cout << "Iveskite skaiciu tarp 1 ir 10" << endl;
			}
		} while (temp.egz <= 0 || temp.egz > 10);
	}
}
void print( studentas& temp)
{
	cout << setw(15) << temp.vardas << setw(20) << temp.pavarde;
	cout << setw(20) << vid(temp) << setw(15) << mid(temp) << endl;
}


double vid( studentas& temp)
{
	double rezultatas = 0;
	for (int i = 0; i < paz_sk; i++)
	{
		rezultatas += temp.paz[i];
	}
	rezultatas = rezultatas / paz_sk;
	rezultatas = 0.4 * rezultatas + 0.6 * temp.egz;
	return rezultatas;
}
double mid( studentas& temp)
{
	double rezultatas = 0;
	sort(&temp.paz[0], &temp.paz[0] + paz_sk);
	if (paz_sk % 2 == 1)
	{
		rezultatas = 0.4 * temp.paz[paz_sk / 2] + 0.6 * temp.egz;
	}

	else {
		rezultatas = 0.4 * ((temp.paz[paz_sk / 2] + temp.paz[paz_sk / 2 - 1]) / 2.0) + 0.6 * temp.egz;
	}

	return rezultatas;
}