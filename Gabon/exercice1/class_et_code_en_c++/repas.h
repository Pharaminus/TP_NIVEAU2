#ifndef _REPAS_
#define _REPAS_ 

#include <iostream>
#include <string>
#include "repas.h"

using namespace std;

/********* CLASS PLAT ********/
class Plat
{
public:
	Plat(string nom); /**** constructeur de la class plat*/
	string get_nom() const; /*** accesseur ****/
	string &set_nom(); /***** mutateur *******/
protected:
	string nom;

};

/******* CLASS Complement *********/

class complement: public Plat
{
public:
	Complement(string type, string couleur);  /**** constructeur de la class CONDIMENT*/
	string get_type() const; /*** accesseur ****/
	string &set_type(); /***** mutateur *******/

	string get_couleur() const;
	string set_couleur() const;
private:
	string type;
	string couleur;
};

/********* CLASS VIANDE ********/
class Viande: public Plat
{
public:
	Viande(string categorie); /***** constructeur de la class categorie *******/
	string get_categorie() const; /*** accesseur ****/
	string &set_categorie();	  /***** mutateur *******/	
private:
	string categorie;	/***** variable pour stocker la categorie *****/
	
};


/****** CLASS CONDIMENT ********/

class Condiment:public plat
{
public:

	Condiment(string type, string etat, string couleur); /**** contructeur *******/
	string get_type() const; /*** accesseur ****/
	string &set_type(); /***** mutateur *******/

	string get_couleur() const; /*** accesseur ****/
	string set_couleur(); /***** mutateur *******/

	string get_etat() const; /*** accesseur ****/
	string &set_etat();		/***** mutateur *******/

private:
	string type;
	string etat;
	string couleur;

};

/******* CLASS SAUCE *******/

class Sauce:public plat
{
public:
	Sauce(string couleur, string etat); /***** constructeur *******/

	string get_couleur() const; /*** accesseur ****/
	string set_couleur(); /***** mutateur *******/

	string get_etat() const; /*** accesseur ****/
	string &set_etat();		/***** mutateur *******/
private:
	string couleur;
	string etat;		
	
};

/********* CLASS REPAS ********/

class Repas: public Plat
{
public:	
	Sauce sauce;
	Complement complement;
	Condiment condiment;
	Viande viande;	
	
};


#endif



