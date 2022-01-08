#ifndef FORTBEWEGUNGSMITTEL_H_
#define FORTBEWEGUNGSMITTEL_H_
#include <iostream>

class Fortbewegungsmittel {

protected:
	static int Anzahl=0;
	float m_Geschwindigkeit;
	std::string m_Marke;

public:
	Fortbewegungsmittel();
	~Fortbewegungsmittel();
	void Bewegen();
	void Stoppen();
	float getGeschwindigkeit();
	std::string getMarke();
	void setMarke(std::string);
};

class Fahrrad : public Fortbewegungsmittel{
private:
	int m_Gaenge;
	void setGaenge(int);

public:
	Fahrrad();
	Fahrrad(int gaenge,float v,std::string marke);
	void Einkaufenfahren();
	void Bergtour();
	int getGaenge();
	void setGeschwindigkeit(float);
};

class Flugzeug : public Fortbewegungsmittel{
private:
	int m_Kapazitaet;
	int m_Passagiere;
	void setKapazitaet(int);

public:
	Flugzeug();
	Flugzeug(int kapazitaet,float v,std::string marke);
	void Flug_buchen();
	void Freie_Plaetze();
	int getKapazitaet();
	void setGeschwindigkeit(float);
};

class Auto : public Fortbewegungsmittel{
private:
	int m_Gaenge;
	int m_Gang;
	void setGaenge(int);

public:
	Auto();
	Auto(int gaenge,float v,std::string marke);
	void raufschalten();
	void runterschalten();
	int getGaenge();
	void setGeschwindigkeit(float);
};
#endif
