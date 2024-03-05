#include "Mylib.h"
#include "Fun.h"

extern int paz_sk;
extern int atsitiktinai;
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
			temp.paz.push_back((rand() % 10) + 1);
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
void print(studentas& temp)
{
	cout << setw(15) << temp.vardas << setw(20) << temp.pavarde;
	cout << setw(20) << vid(temp) << setw(15) << mid(temp) << endl;
}
void isvestiFailus(studentas& temp)
{
	ofstream failas("kursiokai.txt", std::ios::app);
	failas << setw(15) << temp.vardas << setw(20) << temp.pavarde;
	failas << setw(20) << vid(temp) << setw(15) << mid(temp) << endl;
	failas.close();
}

bool pal(const studentas& a, const studentas& b)
{
	if (a.pavarde == b.pavarde)
	{
		return a.vardas < b.vardas;
	}
	else
	{
		return a.pavarde < b.pavarde;
	}
}

void skaitytFailus(vector<studentas>& grupe)
{
	system("dir /B /A-D *.txt");
	string failo_pavadinimas;
	cout << "Pasirinkite faila: ";
	cin >> failo_pavadinimas;
	int sk = 0;
	int bufDydis = 1024;
	vector<char> bufer;
	bufer.resize(bufDydis);
	ifstream f;
	f.rdbuf()->pubsetbuf(&bufer[0], bufDydis);
	f.open(failo_pavadinimas);
	if (!f.is_open()) {
		cout << "Nepavyko atverti failo " << failo_pavadinimas << " skaitymui.\n";
		exit(1);
	}
	else {
		cout << "Skaitomas failas" << endl;
		int rezervuota = 10000000;
		grupe.reserve(rezervuota);
		studentas laik;
		int laikpaz;
		string line;
		getline(f, line);

		while (f.peek() != EOF)
		{
			if (grupe.size() == grupe.capacity())
			{
				grupe.reserve(rezervuota * 2);
			}

			getline(f, line);
			stringstream ss(line);
			ss >> laik.vardas >> laik.pavarde;
			vector<int> paz_vec;
			sk = 0;
			while (ss >> laikpaz)
			{
				laik.paz.push_back(laikpaz);
				sk++;
			}
			laik.egz = laik.paz.back();
			laik.paz.pop_back();
			grupe.push_back(laik);
			laik.paz.clear();
		}
		paz_sk = sk - 1;
		grupe.shrink_to_fit();
		f.close();
		bufer.clear();
		cout << "Duomenys nuskaityti" << endl;
	}
}

double vid(studentas& temp)
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
double mid(studentas& temp)
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