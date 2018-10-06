import pygame, math
from pygame import *
from math import *
import sys as sys

WIN_WIDTH = 800
WIN_HEIGHT = 640
PLANET_WIDTH = 20
PLANET_HEIGHT = 20
DISPLAY = (WIN_WIDTH, WIN_HEIGHT)
SPACE_COLOR = "#000022"
SUN_COLOR = "yellow"
PLANET_COLOR = "blue"

DELTA_T = 0.1

# TO DO LIST
# 1: Передача аргументов (начальной скорости, ускорения и координаты) из консоли - done
# 2: Рисовать след траектории - done
# 3: Реализовать метод Эйлера - ? - зависимость от дельта Т. Норма?
# 4: Реализовать метод Рунге - Кутты - ? -  с ним явно что-то не так

#Sun position
X0 = WIN_WIDTH // 2
Y0 = WIN_HEIGHT // 2
#Sun mass
M0 = 5000
#Stop conditions
CRASH_DIST = 10
OUT_DIST = 1000


class object:
    def __init__(self, x, y, vx, vy):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
    
    
    def Euler(self):
        r = sqrt((self.x - X0)**2 + (self.y - Y0)**2)
        ax = M0 * (X0 - self.x) / r**3
        ay = M0 * (Y0 - self.y) / r**3

        self.vx += ax*DELTA_T
        self.vy += ay*DELTA_T

        self.x += self.vx*DELTA_T
        self.y += self.vy*DELTA_T

    def f(self,local_x,local_y):
        r = sqrt((local_x - X0)**2 + (local_y - Y0)**2)
        ax = M0 *(X0 - local_x) / r ** 3
        ay = M0 *(Y0 - local_y) / r ** 3
        return ax,ay

    def Runge(self):

        fx, fy = self.f(self.x, self.y) 
        v1x = fx * DELTA_T
        v1y = fy * DELTA_T
        x1 = self.vx* DELTA_T
        y1 = self.vy* DELTA_T

        fx, fy = self.f(self.x + x1/2, self.y + y1/2)
        v2x = fx * DELTA_T
        v2y = fy * DELTA_T
        x2 = DELTA_T * (self.vx + v1x/2)
        y2 = DELTA_T * (self.vy + v1y/2)

        fx, fy = self.f(self.x + x2/2, self.y + y2/2)
        v3x = fx * DELTA_T
        v3y = fy * DELTA_T
        x3 = DELTA_T * (self.vx + v2x/2)
        y3 = DELTA_T * (self.vy + v2y/2)

        fx, fy = self.f(self.x + x3, self.y + y3)
        v4x = fx * DELTA_T 
        v4y = fy * DELTA_T
        x4 = DELTA_T * (self.vx + v3x)
        y4 =DELTA_T * (self.vy + v3y) 

        self.x += (x1 + 2*x2 + 2*x3 + x4 )/6
        self.vx += (v1x + 2*v2x + 2*v3x + v4x )/6
        self.y += (y1 + 2*y2 + 2*y3 + y4 )/6
        self.vy += (v1y + 2*v2y + 2*v3y + v4y )/6

    def Energy(self):
        return (self.vx**2 + self.vy**2)/2 - 5001/sqrt((self.x - X0)**2 + (self.y - Y0)**2) 






def main(x=100.0,y=290.0,vx=0.1,vy=1.5, mode=1):
    #PyGame init
    pygame.init()
    screen = pygame.display.set_mode(DISPLAY)
    pygame.display.set_caption("Solar Mechanics v0.1")
    
    #Space init
    bg = Surface((WIN_WIDTH,WIN_HEIGHT))
    bg.fill(Color(SPACE_COLOR))     
    draw.circle (bg, Color(SUN_COLOR), (X0, Y0), 10)
                    
    #Timer init                     
    timer = pygame.time.Clock()
    
    #Planet init
    planet = Surface((PLANET_WIDTH, PLANET_HEIGHT))
    planet.fill(Color(SPACE_COLOR))
    draw.circle (planet,
        Color(PLANET_COLOR),
        (PLANET_WIDTH // 2, PLANET_HEIGHT // 2),
        5)

    #Planet to Sun distance
    r = 0.0

    earth = object(x,y,vx,vy)
    FullEnergy = []

    done = False
    while not done:
        timer.tick(50)
        for e in pygame.event.get():
            if e.type == QUIT:
                done = True
                break        

        
        if mode == 0: # Euler mode 
            earth.Euler()
            FullEnergy.append(earth.Energy())
        
        else: # метод Рунге-Кутты
            earth.Runge()
            FullEnergy.append(earth.Energy())



        #
        draw.circle (bg, Color('white'), (int(earth.x), int(earth.y)), int(1))
        # 
        screen.blit(bg, (0, 0))      
        screen.blit(planet, (int(earth.x), int(earth.y)))
        pygame.display.update()     


        r = sqrt((x - X0)**2 + (y - Y0)**2)

        if r < CRASH_DIST:
            done = True
            print("Crashed")
            break
        if r > OUT_DIST:
            done = True
            print("Out of system")
            break

    #Farewell
    print (":-)")
    return(FullEnergy)

if __name__ == "__main__":
    if len(sys.argv) == 6:
        main(
            float(sys.argv[1]),
            float(sys.argv[2]),float(sys.argv[3]),
            float(sys.argv[4]),float(sys.argv[5])
            )
    else:
        print('Error\nLoad with by default')
        main()