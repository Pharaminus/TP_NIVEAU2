#ifndef _JEU_
#define _JEU_ 

#include <string>
#include <iostream>
using namespace std;

typedef struct Coordonne
{
	int x;
	int y;
}Coordonne;




class Animale
{
public:
    Animale() = default;
	Animale(string typeA, string sexeA, string idAnimaleA, string predateurA, string proieA, Coordonne positionA):type(typeA),sexe(sexeA),idAnimale(idAnimaleA),predateur(predateurA),proie(proieA),position(positionA){}

    string get_type() const { return type; }
    string &set_type() { return type; }

    string get_sexe() const{return sexe;}
    string &set_sexe(){return sexe;}

    string get_idAnimale() const{return idAnimale;}
    string &set_idAnimale(){return idAnimale;}

    string get_predateur() const{return predateur;}
    string &set_predateur(){return predateur;}

    string get_proie() const{return proie;}
    string &set_proie(){return proie;}

    Coordonne get_position() const{return position;}
    Coordonne &set_position(){return position;}

    // int get_nbreDEntite() const{return nbreDEntite;}
    // int &get_nbreDEntite(){return nbreDEntite;}

    bool get_dejaDeplace() const { return dejaDeplace; }
    bool &set_dejaDeplace(){ return dejaDeplace; }


    int get_vie() const { return vie; }
    int &set_vie(){ return vie; }

private:
	string type;
	string idAnimale = "    ";
    
	string sexe;
	int vie = 10;
	Coordonne position = {-1,-1};
	string predateur;
	string proie;
	bool dejaDeplace = false;
    

};

class Maiis
{
public:
    Maiis() = default;
    Maiis(string idMaiisA, Coordonne positionM) : idMaiis(idMaiisA), position(positionM) {}

    string get_idMaiis() const{return idMaiis;}
	string &set_idMaiis(){return idMaiis;}
    int get_vie() const{return vie;}
    int &get_vie(){return vie;}

    string get_type() const { return type;}
    string &set_type(){ return type;}

    Coordonne get_position() const{return position;}
    Coordonne &set_position(){return position;}
private:
    string idMaiis = "    ";
    int vie = 20;
	string type = "maiis";
	Coordonne position = {-1,-1};


};

class Tuile
{
public:
    Tuile() = default;
    
    void Afficher(Animale animaleA[][6], Maiis maiisA[][6]){

        cout << "\t\t\t\t\t\t\033[93m|-----------|------------|------------|------------|------------|\033[0m\t" << endl;

        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + animaleA[0][0].get_idAnimale() + "        " + animaleA[0][1].get_idAnimale() + "         " + animaleA[0][2].get_idAnimale() + "         " + animaleA[0][3].get_idAnimale() + "         " + animaleA[0][4].get_idAnimale() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + maiisA[0][0].get_idMaiis() + "        " + maiisA[0][1].get_idMaiis() + "         " + maiisA[0][2].get_idMaiis() + "         " + maiisA[0][3].get_idMaiis() + "         " + maiisA[0][4].get_idMaiis() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|----   ----|----    ----|----    ----|----    ----|----    ----|\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + animaleA[1][0].get_idAnimale() + "        " + animaleA[1][1].get_idAnimale() + "         " + animaleA[1][2].get_idAnimale() + "         " + animaleA[1][3].get_idAnimale() + "         " + animaleA[1][4].get_idAnimale() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + maiisA[1][0].get_idMaiis() + "        " + maiisA[1][1].get_idMaiis() + "         " + maiisA[1][2].get_idMaiis() + "         " + maiisA[1][3].get_idMaiis() + "         " + maiisA[1][4].get_idMaiis() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|----   ----|----    ----|----    ----|----    ----|----    ----|\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + animaleA[2][0].get_idAnimale() + "        " + animaleA[2][1].get_idAnimale() + "         " + animaleA[2][2].get_idAnimale() + "         " + animaleA[2][3].get_idAnimale() + "         " + animaleA[2][4].get_idAnimale() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + maiisA[2][0].get_idMaiis() + "        " + maiisA[2][1].get_idMaiis() + "         " + maiisA[2][2].get_idMaiis() + "         " + maiisA[2][3].get_idMaiis() + "         " + maiisA[2][4].get_idMaiis() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|----   ----|----    ----|----    ----|----    ----|----    ----|\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + animaleA[3][0].get_idAnimale() + "        " + animaleA[3][1].get_idAnimale() + "         " + animaleA[3][2].get_idAnimale() + "         " + animaleA[3][3].get_idAnimale() + "         " + animaleA[3][4].get_idAnimale() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + maiisA[3][0].get_idMaiis() + "        " + maiisA[3][1].get_idMaiis() + "         " + maiisA[3][2].get_idMaiis() + "         " + maiisA[3][3].get_idMaiis() + "         " + maiisA[3][4].get_idMaiis() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|----   ----|----    ----|----    ----|----    ----|----    ----|\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + animaleA[4][0].get_idAnimale() + "        " + animaleA[4][1].get_idAnimale() + "         " + animaleA[4][2].get_idAnimale() + "         " + animaleA[4][3].get_idAnimale() + "         " + animaleA[4][4].get_idAnimale() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|   " + maiisA[4][0].get_idMaiis() + "        " + maiisA[4][1].get_idMaiis() + "         " + maiisA[4][2].get_idMaiis() + "         " + maiisA[4][3].get_idMaiis() + "         " + maiisA[4][4].get_idMaiis() + "     |   \033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|           |            |            |            |            |\033[0m\t" << endl;
        cout << "\t\t\t\t\t\t\033[93m|-----------|------------|------------|------------|------------|\033[0m\t" << endl;
        
    }; 

};

// interface d'acceuille du  jeu


void interfaceAcceuille(){
    cout <<"_____________   ______       ______         ______            _______________" << endl;
    cout <<"|            |  |    |       |    |        /      \\          |             |" << endl;
    cout <<"|    ________|  |    |       |    |       /    __  \\         |____     ____|" << endl;
    cout <<"|    |          |    |_______|    |      /    /  \\  \\             |    |" << endl;
    cout <<"|    |          |                 |     /    /    \\  \\            |    |" << endl;
    cout <<"|    |          |    ________     |    /    /______\\  \\           |    |" << endl;
    cout <<"|    |_______   |    |       |    |   /     _______    \\          |    |" << endl;
    cout <<"|            |  |    |       |    |  /     /       \\    \\         |    |" << endl;
    cout <<"|____________|  |____|       |____| /_____/         \\____\\        |____|" << endl;

    cout <<"                          <<  ET   >>" << endl;

    cout <<"__________   ________    ___    ___  ______________     _____    __________" << endl;
    cout <<"|   _____|   |       |   |  |  |  |  |   _____     |    |   |   |   _____|" << endl;
    cout <<"|  |         |  ___  |   |  |  |  |  |  |    |     |    |   |   |  |" << endl;
    cout <<"|  |_____    | |   | |   |  |  |  |  |  |____| ____|    |   |   |  |_____" << endl; 
    cout <<"|____   |    | |   | |   |  |  |  |  |   _____   \\     |   |   |____   |" << endl;
    cout <<"     |  |    | |___| |   |  |  |  |  |   |    \\  \\    |   |       |   |" << endl;
    cout <<"_____|  |    |       |   |  |__|  |  |   |     \\  \\   |   |   ____|   |" << endl;
    cout <<"|_______|    |_______|   |________|  |___|      \\__\\  |___|   |_______|" << endl;

}

#endif