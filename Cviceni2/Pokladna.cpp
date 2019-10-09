#include "Pokladna.h"
#include <iostream>
using namespace std;
//using namespace ;
int Pokladna::citacId = 1000;

Pokladna::Pokladna() {
	uctenky = new Uctenka[10];
}
Pokladna::~Pokladna()
{
	delete[] uctenky;
}
Uctenka& Pokladna::vystavUctenku(double castka, double dph) {
	//return *uctenka;
	//Uctenka* uctenka = new Uctenka(castka, dph);
	int noveId = citacId;
	uctenky[pocetVydanychUctenek].setCastka(castka);
	uctenky[pocetVydanychUctenek].setDph(dph);
	uctenky[pocetVydanychUctenek].setCisloUctenky(noveId);

	Pokladna::pocetVydanychUctenek++;

	return uctenky[pocetVydanychUctenek];
}
Uctenka& Pokladna::dejUctenka(int uctenka) {
	for (size_t i = 0; i < Pokladna::pocetVydanychUctenek; i++)
	{
		if (uctenky[i].getCisloUctenky() == uctenka) {
			
			return uctenky[i];
		}
	}
	throw "Chyba";
}
double  Pokladna::dejCastku() const  {
	double castka = 0;
	for (size_t i = 0; i <pocetVydanychUctenek ; i++)
	{
		castka +=uctenky[i].getCastka();
	}
	return castka;
}
double Pokladna::dejCastkuVcDph() const {
	double castka = 0;
	for (size_t i = 0; i < pocetVydanychUctenek; i++)
	{
		castka += Pokladna::uctenky[i].getCastka()+ uctenky[i].getCastka()*(uctenky[i].getDph()/100);
	}
	return castka;
}


//#include "Pokladna.h"
//#include <iostream>
int main(int argc, char** argv) {

	Pokladna pokladna;
	//Pokladna* pokladna = new Pokladna();
	Uctenka& uctenka1 = 
	pokladna.vystavUctenku(10.0, 20.0);
	pokladna.vystavUctenku(200.0, 20.0);
	cout << " castka je " << uctenka1.getCastka() << " dph je " << uctenka1.getDph()<<endl;
	cout << "Celkem castka " << pokladna.dejCastku() << " celkem dph: " << pokladna.dejCastkuVcDph();
}