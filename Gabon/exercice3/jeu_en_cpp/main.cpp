#include "jeu.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<time.h>

using namespace std;
bool debut;
static Animale tableauDanimaux[6][6];
static Maiis tableauDeMaiis[6][6];
const Coordonne cord = {-1, -1};
int main(int argc, const char **argv)
{
    system("clear");
    interfaceAcceuille();
    sleep(4);
    system("clear");

    srand(time(NULL));
    int nbreDEntite = 8;

    int direction, direction2, x, y, x1, y1; // declaration des variable pour le positionement et la direction

    Tuile tuile;        // on declare notre tuile qui nous servira d'interface
    Animale enfantChat; // on declare l'enfant animale en apelant le constructeur par defaut

    /******* creation des animaux 03 chats 05 souris  *******/

    Coordonne cord1 = {0, 0};
    Animale chat1("chat", "M", "\033[1m\033[96m[=|D\033[0m", " ", "sourie", cord1);
    Coordonne cord2 = {2, 4};
    Animale chat2("chat", "M", "\033[1m\033[96m[=|D\033[0m", " ", "sourie", cord2);
    Coordonne cord3 = {1, 3};
    Animale chat3("chat", "F", "\033[1m\033[96m]=|D\033[0m", " ", "sourie", cord3);

    Maiis maiis1("\033[1m\033[93m<00>\033[0m", {0, 3});
    Maiis maiis2("\033[1m\033[93m<00>\033[0m", {4, 3});
    Maiis maiis3("\033[1m\033[93m<00>\033[0m", {2, 1});

    Coordonne cord_s1 = {4, 0};
    Animale souris1("souris", "F", "\033[1m\033[91m]=|>\033[0m", "chat", "maiis", cord_s1);
    Coordonne cord_s2 = {3, 0};
    Animale souris2("souris", "F", "\033[1m\033[91m]=|>\033[0m", "chat", "maiis", cord_s2);
    Coordonne cord_s3 = {1, 0};
    Animale souris3("souris", "F", "\033[1m\033[91m]=|>\033[0m", "chat", "maiis", cord_s3);
    Coordonne cord_s4 = {4, 2};
    Animale souris4("souris", "M", "\033[1m\033[91m[=|>\033[0m", "chat", "maiis", cord_s4);
    Coordonne cord_s5 = {1, 1};
    Animale souris5("souris", "M", "\033[1m\033[91m[=|>\033[0m", "chat", "maiis", cord_s5);

    /***** initialisation de la tuile avec 03 chats et 05 souris **********/

    tableauDanimaux[chat1.get_position().x][chat1.get_position().y] = chat1;
    tableauDanimaux[chat2.get_position().x][chat2.get_position().y] = chat2;
    tableauDanimaux[chat3.get_position().x][chat3.get_position().y] = chat3;

    tableauDeMaiis[maiis1.get_position().x][maiis1.get_position().y] = maiis1;
    tableauDeMaiis[maiis2.get_position().x][maiis2.get_position().y] = maiis2;
    tableauDeMaiis[maiis3.get_position().x][maiis3.get_position().y] = maiis3;

    tableauDanimaux[souris1.get_position().x][souris1.get_position().y] = souris1;
    tableauDanimaux[souris2.get_position().x][souris2.get_position().y] = souris1;
    tableauDanimaux[souris3.get_position().x][souris3.get_position().y] = souris1;
    tableauDanimaux[souris4.get_position().x][souris4.get_position().y] = souris1;
    tableauDanimaux[souris5.get_position().x][souris5.get_position().y] = souris1;
    system("clear");

    /******* debut des operation dans la tuile ******/
    do
    {
        // fonction permettant de netoyer l'ecran avant d'afficher une nouvelle tuile
        if (debut == true)
        {
            system("clear");
            tuile.Afficher(tableauDanimaux, tableauDeMaiis); // on affiche la tuile
            debut == false;
        }

        for (int i = 0; i < 5; i++) // on lance une boucle qui va parcourir la tuile en ligne
        {

            for (int j = 0; j < 5; j++) // on lance la boucle qui va parcourir la tuile en colonne
            {

                // on teste si celle [i][j] de la tuile est vide
                // en effet , etand donne que toutes les position son initialiser a (-1,-1),
                // si un animale de la case a c'set coordonne, alors il ne fait pas partie de la tuile affichable
                if (tableauDanimaux[i][j].get_position().x != cord.x and tableauDanimaux[i][j].get_position().y != cord.y and tableauDeMaiis[i][j].get_position().y == cord.x and tableauDeMaiis[i][j].get_position().y == cord.y)
                {
                    // on verifie si l'entite trouver dans la case durant le parcour a deja ete deplace .
                    // on le fait en fin deviter de redeplacer une entiter qui a ete deplacer a la ligne ou colonne inferieur
                    if (tableauDanimaux[i][j].get_dejaDeplace() == false)
                    {
                        // si l'entite presente dans la case a une vie egale a zero, il meurt
                        if (tableauDanimaux[i][j].get_vie() == 0)
                        {
                            // std::cout << "le " << tableauDanimaux[i][j].get_type() << "est mort !" << std::endl;

                            tableauDanimaux[i][j] = tableauDanimaux[5][5];
                        }

                        /******** bloc permettant de generer des coordonnees aleatoirement *****/
                        // en effet, c'est une direction gener aleatiorement
                        // et c'est vers elle que l'animale ira;
                        direction = rand() % 4;
                        x = i + (direction % 2) * (direction - 2);
                        y = j + ((direction + 1) % 2) * (direction - 1);
                        /****---------------------------------------*****/

                        // on teste si la direction genere est ne fait pas partir de la tuile
                        if (x <= -1 or y <= -1)
                        { // comme l'animale s'est deplacer hors de la tuile il meurt
                            // std::cout << "le " << tableauDanimaux[i][j].get_type() << " est sortie de la tuile" << std::endl; // on precise qu'il est mort
                            tableauDanimaux[i][j] = tableauDanimaux[5][5]; // on affecte l'animale vide a la position de l'entiter qui meurt
                            nbreDEntite -= 1;                              // on decremente le nombre d'entite vivante
                        }

                        // comme la direction generer n'est pas situer hors de la tuile on continue le processus de deplacement
                        // on teste si il n'y a aucune entiter a l'emplacement ou veut se deplacer l'animale
                        else if (tableauDanimaux[x][y].get_position().x == cord.x and tableauDanimaux[x][y].get_position().y == cord.y and tableauDeMaiis[x][y].get_position().x == cord.x and tableauDeMaiis[x][y].get_position().y == cord.y)
                        {
                            // comme nous sommes entre alors il n'y a personne
                            // on peut donc deplacer notre animale
                            // std::cout << "le " << tableauDanimaux[i][j].get_type() << " s' est deplace !" << std::endl; // on affiche le message decrivant son operation

                            tableauDanimaux[x][y] = tableauDanimaux[i][j];  // on deplace l'animale a la position generer aleatoirement
                            tableauDanimaux[i][j] = tableauDanimaux[5][5];  // on deplace l'animale vide a son ancien emplacement
                            tableauDanimaux[i][j].set_dejaDeplace() = true; // on precise qu'il a deja ete deplacer pour eviter de le faire dans un meme parcour de tuile
                        }

                        // si nous somme ici c'est parceque le tableau est occupe.
                        // il faudrait donc se renseigner sur quel animale l'occupe; afin de determiner les rapport entre les deux
                        else if (tableauDanimaux[x][y].get_type() == tableauDanimaux[i][j].get_type())
                        { // nous connaissont le type d'annimale present dans la cellule

                            // on demande le sexe de l'animale afin de voir si l'on peut se reproduir
                            if (tableauDanimaux[x][y].get_sexe() != tableauDanimaux[i][j].get_sexe())
                            { // ca tombe bien on dirait ce sont des amesoeur

                                // on gener une position (un environnement qui recevra le nouveau ne ) aleatiorement que le nouveau nee occupera
                                direction2 = rand() % 4;
                                x1 = i + (direction2 % 2) * (direction2 - 2);
                                y1 = j + ((direction2 + 1) % 2) * (direction2 - 1);
                                /*----------------------------------------------------*/
                                // on deplace donc le nouveau ne dans la cellule qui lui a ete offer par ...Dieu..(...Moi...)
                                Animale animale(tableauDanimaux[i][j].get_type(), tableauDanimaux[i][j].get_sexe(), tableauDanimaux[i][j].get_idAnimale(), tableauDanimaux[i][j].get_predateur(), tableauDanimaux[x][y].get_proie(), {x1, y1});
                                // std::cout << "le bebe" << tableauDanimaux[i][j].get_type() << " est neee !!!!!" << std::endl;
                                tableauDanimaux[x1][y1] = tableauDanimaux[i][j]; // on affecte l'animale vide a la position de l'entiter qui meurt
                                nbreDEntite += 1;                                // on decremente le nombre d'entite vivante
                                tableauDanimaux[i][j] = tableauDanimaux[5][5];   // on deplace l'animale vide a son ancien emplacement
                            }

                            // si l'animale est du meme sexe que lui il ne fait rien on ne veut pas les ...
                        }

                        // Domage les entites(animaux) ne sont pas de meme type
                        // verifions au moins si il est mangable (c'est vrai que le sexe et la nouriture font partir des chose speciale dans la vie)
                        else
                        {
                            // on verifie si cet animale peut etre manger
                            if (tableauDanimaux[x][y].get_predateur() == tableauDanimaux[i][j].get_type())
                            {
                                if (tableauDanimaux[x][y].get_type() == "souris")
                                {
                                    // on deplace l'entite
                                    tableauDanimaux[x][y] = tableauDanimaux[i][j];
                                    // std::cout << "le " << tableauDanimaux[i][j].get_type() << " a ete manger !" << std::endl;

                                    tableauDeMaiis[i][j] = tableauDeMaiis[5][5];
                                    tableauDanimaux[i][j].set_dejaDeplace() = true;
                                    nbreDEntite -= 1;
                                    tableauDanimaux[x][y].set_vie() += 1;
                                    //---------------------------------
                                }
                                else
                                {
                                    // on deplace l'entite
                                    tableauDanimaux[x][y] = tableauDanimaux[i][j];
                                    // std::cout << "le " << tableauDanimaux[i][j].get_type() << " a ete manger !" << std::endl;

                                    tableauDanimaux[i][j] = tableauDanimaux[5][5];
                                    tableauDanimaux[i][j].set_dejaDeplace() = true;
                                    nbreDEntite -= 1;
                                    tableauDanimaux[x][y].set_vie() += 1;
                                    //---------------------------------
                                }
                            }
                        }
                    }
                }
                // on retire le maiis aleatiorement

                tableauDeMaiis[i][j] = tableauDeMaiis[5][5];
            }
        }

        // on remet la valeur de dejaDeplacer a false et on insere le maiis;
        int k = 0;
        for (int i = 0; i < 5; i++)
        {
            int r = rand() % 10;
            k++;
            for (int j = 0; j < 5; j++)
            {

                if (tableauDanimaux[i][j].get_dejaDeplace() == true)
                {
                    tableauDanimaux[i][j].set_dejaDeplace() = false;
                }
            }
            if (r == 9)
            {
                if (tableauDanimaux[i][k].get_position().x == cord.x and tableauDanimaux[i][k].get_position().y == cord.y and tableauDeMaiis[i][k].get_position().y == cord.x and tableauDeMaiis[i][k].get_position().y == cord.y)
                {
                    Maiis maiis("\033[1m\033[94m\033[1m\033[93m<00>\033[0m\033[0m", {i, k});
                    tableauDeMaiis[i][k] = maiis;
                }
            }
        }
        tuile.Afficher(tableauDanimaux, tableauDeMaiis); // on affiche la tuile

        sleep(2);
        system("clear");
    } while (nbreDEntite != 0);

    return 0;
}
