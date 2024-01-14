import random

class Area:
    def __init__(self):
        self.area = [
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        [" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "],
        ]
        self.i = 0
        self.j = 0
    def showArea(self):
        while self.i<23:
            print(self.area[self.i][self.j],end=" ")
            self.i += 1
            while self.j < 20:
                 print(self.area[self.i-1][self.j],end=" ")
                 self.j += 1
            print()
            self.j = 0
        self.i = 0
        
class LivingThing:
    def __init__(self):
        self.body = " "
        self.sex = " "
        self.type =" "
        self.x = 0
        self.y = 0
        self.lifeSpan = 100
        self.actualLifeSpan = 100
    def Appear(self,area):
        area[self.x][self.y]= self.body
    def mouveLeft(self,area):
        if self.y > 0:
            area[self.x][self.y]= " "
            self.y -= 1
            area[self.x][self.y]= self.body
    def mouveRight(self,area):
        if self.y+1 <= 20:
            area[self.x][self.y]= " "
            self.y += 1
            area[self.x][self.y]= self.body
    def mouveUp(self,area):
        if self.x < 22:
            area[self.x][self.y]= " "
            self.x += 1
            area[self.x][self.y]= self.body
    def mouveDown(self,area):
        if self.y > 0:
            area[self.x][self.y]= " "
            self.x -= 1
            area[self.x][self.y]= self.body
    def mouvement(self,area):
        rand = random.randint(1,4)
        if rand == 1:
            try:
                self.mouveLeft(area)
            except:
                print("Est sorti de la zone de jeu donc est mort ")
        elif rand == 2:
            try:
                self.mouveRight(area)
            except:
                print("Est sorti de la zone de jeu donc est mort ")
        elif rand == 3:
            try:
                self.mouveUp(area)
            except:
                print("Est sorti de la zone de jeu donc est mort ")
        elif rand == 4:
            try:
                self.mouveDown(area)
            except:
                print("Est sorti de la zone de jeu donc est mort ")
    def getTypeOf(self,animal):
        return animal.type
    def Die(self):
        self.body = " "
    def Living(self):
        self.actualLifeSpan -= 1
        if self.actualLifeSpan <= 0:
            self.Die()
class Cat(LivingThing):
    def __init__(self,sexe,x,y):
        super().__init__()
        self.body = ":=D"
        self.sex = sexe     
        self.x = x
        self.y = y
        self.id = "cat"
    def EatMouse(self,animal):
        if (self.x and self.y) == (animal.x and animal.y):
            if animal.id == "mse":
                animal.body = " "
                if animal.actualLifeSpan + self.actualLifeSpan > 100:
                    self.actualLifeSpan = 100
                else:
                    self.actualLifeSpan += animal.actualLifeSpan
class Mouse(LivingThing):
    def __init__(self,sexe,x,y):
        super().__init__()
        self.body = "-|x)"
        self.sex = sexe     
        self.x = x
        self.y = y
        self.id = "mse"
    def EatMaise(self,maise,mouse):
        if (self.x and self.y) == (maise.x and maise.y):
            maise.beEaten(mouse)

class Maise:
    def __init__(self):
        self.energyValue = 5
        self.body = "O"
        self.id = "maise"
    def Appear(self,area):
        randX = random.randint(1,15)
        randY = random.randint(5,18)
        area[randX][randY]= self.body 
    def beEaten(self,mouse):
        self.body = " "
        if mouse.actualLifeSpan + self.energyValue > 100:
            mouse.actualLifeSpan = 100
        else:
            mouse.actualLifeSpan += self.energyValue
