# ****** CLASS PLAT *******

class Plat():
    # constructeur de la class plat
    def __init__(self,nom):
        self.nom = nom
   

# ****** CLASS COMPLEMENT *******

class Complement(Plat):
    def __init__(self,types,couleur, nom):  
        Plat.__init__(self, nom)        # constructeur de ma classe  Complement
        self.types = types
        self.couleur = couleur
       


# ********* CLASS SAUCE *********

class Viande(Plat):              # constructeur de ma classe Sauce
     def __init__(self, nom, categorie):
        Plat.__init__(self, nom)
        self.categorie = categorie

#********  CLASS CONDIMENT *******
# class condiment qui herite de la class plat

class Condiment(Plat):         # constructeur de ma classe Condiment
    def __init__(self,nom,types,etat,couleur):
       Plat.__init__(self,nom)
       self.types = types
       self.etat = etat
       self.couleur = couleur

# ********* CLASS SAUCE ******

class Sauces(Plat):
    def __init__(self,nom,couleur,etat):
        Plat.__init__(self,nom)
        self.couleur = couleur
        self.etat = etat

#  ******* CLASS REPAS *******
class Repas(Plat):         # constructeur de ma classe Condiment
    def __init__(self,types,nom):
       Plat.__init__(self,nom)
       self.categorie = types


       

        