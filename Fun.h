#pragma once

struct studentas {
	string vardas = "", pavarde = "";
	vector<int> paz;
	int egz = 0;
};

void pildymas(studentas& temp);
void print(studentas& temp);
double vid(studentas& temp);
double mid(studentas& temp);
bool pal(const studentas& a, const studentas& b);
void skaitytFailus(vector<studentas>& grupe);
void isvestiFailus(studentas& temp);
