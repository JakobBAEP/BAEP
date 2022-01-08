#include "Fortbewegungsmittel.h"

using namespace std;

Fortbewegungsmittel::Fortbewegungsmittel(){
	Anzahl++;
	m_Geschwindigkeit=0;
	m_Marke = "unbekannt";
	cout << "Marke noch nicht eingetragen" << endl;
};

Fortbewegungsmittel::~Fortbewegungsmittel(){
	Anzahl--;
};

void Fortbewegungsmittel::Bewegen(){
	cout << "Fortbewegungsmittel in Bewegung" << endl;
}

void Fortbewegungsmittel::Stoppen(){
	cout << "Fortbewegungsmittel gestoppt" << endl;
}

float Fortbewegungsmittel::getGeschwindigkeit(){
	return m_Geschwindigkeit;
}

string Fortbewegungsmittel::getMarke(){
	return m_Marke;
}

void Fortbewegungsmittel::setMarke(string marke){
	m_Marke = marke;
}


// Fahrrad
Fahrrad::Fahrrad(){
	Fortbewegungsmittel::Anzahl++;
	m_Geschwindigkeit=0;
	m_Marke = "unbekannt";
	cout << "Marke noch nicht eingetragen" << endl;
	m_Gaenge=0;
};

Fahrrad::Fahrrad(int gaenge,float v,std::string marke){
	Fortbewegungsmittel::Anzahl++;
	setGeschwindigkeit(v);
	setMarke(marke);
	setGaenge(gaenge);
}

void Fahrrad::Einkaufenfahren(){
	cout << "Das Fahrrad fährt Einkaufen" << endl;
}

void Fahrrad::Bergtour(){
	if(m_Gaenge>=18){
		cout << "Das Fahrrad fährt eine Bergtour" << endl;
	} else {
		cout << "Das Fahrrad hat zu wenig Gänge" << endl;
	}
}

int Fahrrad::getGaenge(){
	return m_Gaenge;
}

void Fahrrad::setGaenge(int g){
	if(g<0){
		m_Gaenge = 0;
		} else if (g>36){
			m_Gaenge = 36;
		} else {
			m_Gaenge = g;
		}
	cout << "Das Fahrrad hat " << m_Gaenge << " Gänge" << endl;
}

void Fahrrad::setGeschwindigkeit(float v){
	if(v<0){
		m_Geschwindigkeit = 0;
	} else if (v>50){
		m_Geschwindigkeit = 50;
	} else {
		m_Geschwindigkeit = v;
	}

}


// Flugzeug
Flugzeug::Flugzeug(){
	Fortbewegungsmittel::Anzahl++;
	m_Geschwindigkeit=0;
	m_Marke = "unbekannt";
	cout << "Marke noch nicht eingetragen" << endl;
	m_Kapazitaet=0;
	m_Passagiere=0;
};

Flugzeug::Flugzeug(int kapazitaet,float v,std::string marke){
	Fortbewegungsmittel::Anzahl++;
	setGeschwindigkeit(v);
	setMarke(marke);
	setKapazitaet(kapazitaet);
	m_Passagiere=0;
}

void Flugzeug::Flug_buchen(){
	if (m_Passagiere<m_Kapazitaet){
		string name;
		cout << "Wie ist ihr Name? " ;
		cin >> name;
		cout << endl;
		m_Passagiere++;
	} else {
		cout << "Keine freien Plätze" << endl;
	}
}

void Flugzeug::Freie_Plaetze(){
	cout << "Es sind noch " << (m_Kapazitaet-m_Passagiere) << " Plätze frei" << endl;
}

int Flugzeug::getKapazitaet(){
	return m_Kapazitaet;
}

void Flugzeug::setKapazitaet(int k){
	if(k<0){
		m_Kapazitaet = 0;
		} else if (k>300){
			m_Kapazitaet = 300;
		} else {
			m_Kapazitaet = k;
		}
	cout << "Das Flugzeug hat " << m_Kapazitaet << " Plätze" << endl;
}

void Flugzeug::setGeschwindigkeit(float v){
	if(v<0){
		m_Geschwindigkeit = 0;
	} else if (v>1000){
		m_Geschwindigkeit = 50;
	} else {
		m_Geschwindigkeit = v;
	}
}


// Auto
Auto::Auto(){
	Fortbewegungsmittel::Anzahl++;
	m_Geschwindigkeit=0;
	m_Marke = "unbekannt";
	cout << "Marke noch nicht eingetragen" << endl;
	m_Gaenge=0;
	m_Gang=1;
};

Auto::Auto(int gaenge,float v,std::string marke){
	Fortbewegungsmittel::Anzahl++;
	setGeschwindigkeit(v);
	setMarke(marke);
	setGaenge(gaenge);
	m_Gang=1;
}

void Auto::raufschalten(){
	if(m_Gang<m_Gaenge){
		m_Gang++;
		cout << "Es wurde in den " << m_Gang << " hochgeschaltet" << endl;
	}
	cout << "Das Auto ist schon im höchsten Gang" << endl;
}

void Auto::runterschalten(){
	if(m_Gang>1){
		m_Gang--;
		cout << "Es wurde in den " << m_Gang << " runtergeschaltet" << endl;
	}
	cout << "Das Auto ist schon im höchsten Gang" << endl;
}

int Auto::getGaenge(){
	return m_Gaenge;
}

void Auto::setGaenge(int g){
	if(g<0){
		m_Gaenge = 0;
		} else if (g>6){
			m_Gaenge = 6;
		} else {
			m_Gaenge = g;
		}
	cout << "Das Auto hat " << m_Gaenge << " Gänge" << endl;
}

void Auto::setGeschwindigkeit(float v){
	if(v<0){
		m_Geschwindigkeit = 0;
	} else if (v>200){
		m_Geschwindigkeit = 200;
	} else {
		m_Geschwindigkeit = v;
	}

}

