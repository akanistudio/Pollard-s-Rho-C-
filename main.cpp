#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <cmath>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int nwd(int a, int b) {
	if (b == 0) return a;
	return nwd(abs(b),abs(a%b));
}

int main(int argc, char** argv) {
	int liczba;
	std::cout << "Podaj liczbe do podzialu: ";
	std::cin >> liczba;
	int random = std::rand();
	if(random<0) random = random - (2*random);
	int poprzedni_random = random;
	int znaleziony_dzielnik = 1;
	int wielkosc_obiegu = 2;
	int proba;
	
		while (znaleziony_dzielnik == 1) {
		for (int i=1;i <= wielkosc_obiegu && znaleziony_dzielnik <= 1;i++) {
			random = (random*random+1)%liczba;
			std::cout << " poprzedni_random " << poprzedni_random<<"\n";
			std::cout<<" random "<<random<<"\n";
			znaleziony_dzielnik = nwd(random - poprzedni_random, liczba);
		}

		wielkosc_obiegu *= 2;
		poprzedni_random = random;
	}
	std::cout << "\nJeden z dzielnikow to:  " << znaleziony_dzielnik<<"\n";
	
	system("PAUSE");
    return 0;
}
