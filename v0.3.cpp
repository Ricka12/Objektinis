#include "Mylib.h"
#include "Fun.h"

int paz_sk;
int atsitiktinai;

int main() {
	char uzkl, duomenu_suvedimas_ranka, duomenu_Isvedimas;
	vector<studentas> grupe;
	int n = 1;
	studentas laikinas;
	do {
		cout << "Ar norite suvesti duomenis ranka ?(t jei taip, n jei ne): ";
		cin >> duomenu_suvedimas_ranka;
	} while (duomenu_suvedimas_ranka != 't' && duomenu_suvedimas_ranka != 'T' && duomenu_suvedimas_ranka != 'n' && duomenu_suvedimas_ranka != 'N');
	if (duomenu_suvedimas_ranka == 't' || duomenu_suvedimas_ranka == 'T')
	{
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
		} while (uzkl != 'n' && uzkl != 'N');
		do {
			cout << "Ar norite isvesti duomenis ant ekrano(t) ar i faila(n): ";
			cin >> duomenu_Isvedimas;
		} while (duomenu_Isvedimas != 't' && duomenu_Isvedimas != 'T' && duomenu_Isvedimas != 'N' && duomenu_Isvedimas != 'n');
		sort(grupe.begin(), grupe.end(), pal);
		if (duomenu_Isvedimas == 't' || duomenu_Isvedimas == 'T')
		{
			cout << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(Vid.)" << " /" << " Galutinis(Med)" << endl;
			for (auto& i : grupe)
			{
				print(i);
			}
		}
		else {
			cout << "Isvedimas pradetas" << endl;
			ofstream failas("kursiokai.txt");
			failas << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(Vid.)" << " /" << " Galutinis(Med)" << endl;
			for (auto& i : grupe)
			{
				isvestiFailus(i);
			}
			cout << "Failas uzpildytas" << endl;
		}
	}
	else {
		try {
			skaitytFailus(grupe);
			do {
				cout << "Ar norite isvesti duomenis ant ekrano(t) ar i faila(n): ";
				cin >> duomenu_Isvedimas;
				sort(grupe.begin(), grupe.end(), pal);
			} while (duomenu_Isvedimas != 't' && duomenu_Isvedimas != 'T' && duomenu_Isvedimas != 'N' && duomenu_Isvedimas != 'n');
			if (duomenu_Isvedimas == 't' || duomenu_Isvedimas == 'T')
			{
				cout << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(Vid.)" << " /" << " Galutinis(Med)" << endl;
				for (auto& i : grupe)
				{
					print(i);
				}
			}
			else {
				cout << "Isvedimas pradetas" << endl;
				ofstream failas("kursiokai.txt");
				failas << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis(Vid.)" << " /" << " Galutinis(Med)" << endl;
				for (auto& i : grupe)
				{
					isvestiFailus(i);
				}
				cout << "Failas uzpildytas" << endl;
			}
		}
		catch (const std::exception& e) {
			// Handle the exception here
			cerr << "Klaida: " << e.what() << endl;
		}
	}
	grupe.clear();
}
