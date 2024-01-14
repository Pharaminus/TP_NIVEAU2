#include <iostream>
#include <string>
#include "repas.h"

using namespace std;

/***  Plat *****/
Plat::Plat(string nom){
	this->nom = nom;
}
string Plat::Plat::get_nom() const{return nom}
string &Plat::Plat::set_nom(){return nom}

/**** complement *****/
Complement::Complement(string type, string couleur){
	this->type = type;
	this->couleur = couleur;
}

string Complement::get_type() const{return type}
string &Complement::set_type(){return type}

string Complement::get_couleur() const{return couleur}
string &Complement::set_couleur(){return couleur}

/***** Sauce ******/
Sauce::Sauce(string couleur, string etat){

	this->etat = etat;
	this->couleur = couleur;

}

string Sauce::get_couleur() const{return couleur}
string &Sauce::set_couleur(){return couleur}

string Sauce::get_etat() const{return nom}
string &Sauce::set_etat(){return nom}

/*--------------------------------*/
/**** condiment *******/
Condiment::Condiment(string type, string etat, string couleur){
	this-type = type;
	this->etat = etat;
	this->couleur = couleur;
}

string Condiment::get_type() const{return type}
string &Condiment::set_type(){return type}

string Condiment::get_couleur() const{return couleur}
string &Condiment::set_couleur(){return couleur}

string Condiment::get_etat() const{return etat}
string &Condiment::set_etat(){return etat}

/*---------------------------------*/
/**** class viande ******/
Viande::Viande(string categorie){
	this->categorie = categorie;
}
string Viande::get_categorie() const{return categorie}
string &Viande::get_categorie(){return categorie}


int main(int argc, char const *argv[])
{
	Sauce sauce("sauce d'arachide","jaune","liquide");

	cout<<sauce.get_nom()<<endl
		<<sauce.get_couleur()<<endl
		<<sauce.get_etat;

	return 0;
}
