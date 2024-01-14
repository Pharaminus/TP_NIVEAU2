package java_class;

public class Condiment extends Sauce{
    public
        String type;
    
    public Condiment(String type1, String etat, String couleur, String nom, int quantite){

        super(etat, couleur, nom, quantite);
        this.type = type1;
    }    
    
}
