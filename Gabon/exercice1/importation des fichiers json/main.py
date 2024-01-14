from test import *
class plat:
	def __init__(self,nom,complement,viande,sauce):
		self.nom = nom
		self.complement = complement
		self.viande = viande
		self.sauce = sauce
		
first = Json()
plat1=plat("enkati","beignets","","sauce piment")
plat2=plat("feuille de manioc","riz"," ","sacasaca")
plat3=plat("bouillon viande","plantain","viande de boeuf","bouillon")
plat4=plat("nfouk owone","baton manioc","viande de porc","sauce arachide")
plat5=plat("manioc bateke","manioc","viande chevre","Sauce bateke")
plat6=plat("nkumu atanga","igname","poisson fume","Sauce nkumu")
plat6=plat("poisson sale crevette","banane plantain","poisson","banane plantain")
plat7=plat("poulet nyembwe"," ","poulet"," sauce aux noix")
plat8=plat("cot de porc braise","banane plantain","porc","Sauce piment")
plat9=plat("ndimba"," ","chenille","Sauce au chocolat indigene")
plat10=plat("capitaine a l'oseille"," ","poisson capitaine","Sauce a l'oseille")
tableau = []


tableau.append(plat1)
tableau.append(plat2)
tableau.append(plat3)
tableau.append(plat4)
tableau.append(plat5)
tableau.append(plat6)
tableau.append(plat7)
tableau.append(plat8)
tableau.append(plat9)
tableau.append(plat10)

choix = input("connaissez vous tout ce qui constitu votre repas? \n\n tapez 1 pour oui \n\n tapez 2 pour non je connais un seul\n\n")
choix = int(choix)
if choix == 1:
	n_complement=input("Entrer le nom du complement du plat donc vous voulez le nom:\n")
	n_viande=input("Entrer le nom de la viande du plat donc vous voulez le nom:\n")
	n_sauce=input("Entrer le nom de la sauce du plat donc vous voulez le nom :\n")

	i=0
	trouver = False
	for element in tableau:

		if element.complement == n_complement and element.viande == n_viande and element.sauce == n_sauce :
			print("Bon appetit,le nom du plat est:",element.nom)
			print("Vos ingredients correspondent a 99%  pour  plat")
			trouver = True
	if trouver == False:
		print("LES INGREDIENTS ENTRER NE CORRESPONDENT A AUCUN DES REPAS CONTENUE DANS NOS PLATS DISPONIBLES.MERCI!!!!!!!!!!!!!!!")
		
elif choix == 2:
	first.searchInJson()


	
 



		
		
		

