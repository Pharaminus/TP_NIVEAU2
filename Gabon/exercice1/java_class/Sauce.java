package java_class;

public class Sauce extends Plat {

        String state;
        String color;
    public Sauce(String etat, String couleur, String nom, int quantite){

            super(nom, quantite);
            this.state = etat;
            this.color = couleur;
    }    
}
