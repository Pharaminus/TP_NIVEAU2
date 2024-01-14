import json
class Json:
    def __init__(self):
        pass
    
    def searchInJson(self):
        i=0
        j=0
        k=0
        with open('1.json') as test:
            data1= json.load(test)
        with open('Ofula (Sel indigène Téké).json') as test:
            data2 = json.load(test)
        with open('Okana (les asperges).json') as test:
            data3 = json.load(test)
        with open('Okana (wild aspargus).json') as test:
            data4 = json.load(test)
        with open('Ongwèlè (Manioc Batéké).json') as test:
            data5 = json.load(test)
        with open('Oyaba (caviar datanga-safou Téké).json') as test:
            data6 = json.load(test)
        with open('plat-feuilles-de-manioc-poisson-fume-345x460.json') as test:
            data7 = json.load(test)
        with open('poisson-braise.json') as test:
            data8 = json.load(test)
        with open('poisson-fume-aubergines.json') as test:
            data9 = json.load(test)
        with open('poisson-sale-3-500x375.json') as test:
            data10 = json.load(test)
        with open('poisson salé crevettes aubergines.json') as test:
            data11 = json.load(test)
            
        fichiersJson = [data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11]

        #print(len(data["annotations"]))

        search = input("entrer une chose que voyez dans votre plat")
        while i < len(fichiersJson):
            while j < len(fichiersJson[i]["annotations"]):
                if search == fichiersJson[i]["annotations"][j]["label"]:
                    print()
                    print("vous etes entrain peut etre de manger " +fichiersJson[i]["image"])
                    print("il contient :")
                    while k < len(fichiersJson[i]["annotations"]):
                        print(fichiersJson[i]["annotations"][k]["label"])
                        k+=1
                    k=0
                j+=1
            i+=1
            j=0