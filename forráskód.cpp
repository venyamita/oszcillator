// Nagy Péter
// M07ILF
//statfiz beadandó
//2018.03.12.
//oprendszer:windows10
//IDE:VS
//k=1,a=1

#include "stdafx.h"

#include <array>    
#include <numeric>  
#include <iomanip>  
#include <iostream> 
#include <fstream>
#include <random>   
#include <math.h>




//random szám 0 és 1 között
double veletlen() {
	std::random_device rd;
	std::mt19937 Generator(rd());
	std::uniform_real_distribution<double> Distribution(0, 1);
	return Distribution(Generator);
}

//választok egy random irányt
int lepes() {
	double c = veletlen();
	int a;
		if (c>0.5) {
			a = -1;
		}
		else {
			a = 1;
		}
		return a;
}

//kiszámolom az energia megváltozását
double energia(int a, int n) {
	double E=0.5*(pow(n + a, 2) - pow(n, 2));
	return E;
}



int main() {
	double b;
	int helyzet;
	int ciklusszam;

	//bekérem a szükséges változókat
	std::cout << "adja meg a megadott parametert" << std::endl;
	std::cin >> b;
	std::cout << "adja meg a kezdo poziciot" << std::endl;
	std::cin >> helyzet;
	std::cout << "adja meg hanyszor vegezzuk el a lepest" << std::endl;
	std::cin >> ciklusszam;
	std::ofstream dataFile("montecarlo.data");

	//léptető ciklus
	for (int i = 0; i < ciklusszam; i++) {
		int lep = lepes();
		double E = energia(lep, helyzet);
		if (E<0) {
			helyzet = helyzet + lep;
		}
		else {   //összehasonlítás a megadott paraméter és az energia változás szorzatával
			if (veletlen() < exp(-b*E)) {
				helyzet = helyzet + lep;

			}
		}
		dataFile << helyzet  << '\t' << lep <<'\n';
	}
	dataFile.close();
}
