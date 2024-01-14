package java_class;

public class Viande extends Plat{
public
    String type;
    String categorie;
    public Viande(String types, String categories, String non, int quantite){

        super(non, quantite);
        this.type = types;
        this.categorie = categories;

    }

}
