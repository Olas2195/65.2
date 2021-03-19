#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Nieskracalne{
	ifstream we;
	ofstream wy;
	vector <string> obraz;
	int licznik, mianownik;
	
	public:
		Nieskracalne();
		~Nieskracalne();
		void wczytaj();
		vector <int> rozklad(int);
		void skracalne(vector <int>, vector<int>);
};

Nieskracalne::Nieskracalne() {
	we.open("dane_ulamki.txt");
	wy.open("wyniki_ulamki.txt");
}

void Nieskracalne::wczytaj() {
	vector <int> czynniki_licznika;
	vector <int> czynniki_mianownika;
 	int suma_licznikow=0;
	if(we.good()) {
		while(!we.eof()) {
			we>>licznik;
			czynniki_licznika = rozklad(licznik);
			we>>mianownik;
			czynniki_mianownika = rozklad(mianownik);	
			this->skracalne(czynniki_licznika, czynniki_mianownika);
			suma_licznikow += licznik;
		}
		wy<<suma_licznikow;
		cout<<suma_licznikow;
	}
}
	
vector <int> Nieskracalne::rozklad(int liczba) {
	vector <int> czynniki;
		for (int i=2; i<=liczba; i++) {
	   		while (liczba%i == 0) {
	        	liczba/=i;
	        	czynniki.push_back(i);
	    	}
	 	}
	return czynniki;
}

void Nieskracalne::skracalne(vector <int> czynniki_licznika, vector <int> czynniki_mianownika) {
	for (int i=0; i<czynniki_licznika.size(); i++) {
		for (int j=0; j<czynniki_mianownika.size(); j++) {
			if(czynniki_licznika[i]==czynniki_mianownika[j] && czynniki_mianownika[j]!=0) {
				licznik/=czynniki_licznika[i];
				mianownik/=czynniki_mianownika[j];
				czynniki_licznika[i]=0;
				czynniki_mianownika[j]=0;
			}
		}
	}
}

Nieskracalne::~Nieskracalne() {
	we.close();
	wy.close();
}

int main(int argc, char** argv) {
	Nieskracalne n;
	n.wczytaj();
	
	return 0;
}

