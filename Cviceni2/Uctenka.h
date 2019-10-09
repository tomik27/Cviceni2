
#ifndef  Uctenka_H
#define Uctenka_H
class Uctenka {
private:
	int  cisloUctenky = 0;
	double castka;
	double dph;
public:
	Uctenka();
int getCisloUctenky()const;
void setCisloUctenky(int cislo);
Uctenka(double castka, double dph);
double getCastka()const;
void setCastka(double cislo);
double getDph()const;
void setDph(double cislo);

};
#endif //  Uctenka_H
