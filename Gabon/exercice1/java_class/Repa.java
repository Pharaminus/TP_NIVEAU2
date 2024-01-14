package java_class;

public class Repa extends Plat{

    Complement complement = new Complement(name, name, name, 0);
    Sauce sauce = new Sauce(name, name, name, quantiy);
    Condiment condiment = new Condiment(name, name, name, name, quantiy);
    Viande viande = new Viande(name, name, name, quantiy);
    
    
    public Repa(String nom, int quantite){
        super(nom, quantite);
    }



   
    
}
