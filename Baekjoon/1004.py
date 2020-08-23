import math

class Vector:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.R = 0
    
    def CompareDistance(self, v):
        num1 = (self.x - v.x) ** 2
        num2 = (self.y - v.y) ** 2

        return float(math.sqrt(num1 + num2))
        


    def SetVector(self, x, y, r):
        self.x = x
        self.y = y
        self.R = r


T = int(input())
while T > 0:
    result = 0
    T -= 1
    start = Vector()
    end = Vector()

    x1, y1, x2, y2 = map(int, input().split())
    start.SetVector(x1, y1, 0)
    end.SetVector(x2, y2, 0)

    N = int(input())
    while N > 0:
        N -= 1
        
        planet = Vector()
        x,y,r = map(int, input().split())
        planet.SetVector(x,y,r)

        if(start.CompareDistance(planet) < planet.R and end.CompareDistance(planet) < planet.R):
            continue
        else:
            if(start.CompareDistance(planet) <= float(planet.R) or end.CompareDistance(planet) <= float(planet.R)):
                result += 1
        
    
    print (result)


