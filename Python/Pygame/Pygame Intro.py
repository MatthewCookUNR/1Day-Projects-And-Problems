import pygame

    
    
#define constants (RGB colors)
BLACK = (0,0,0)
WHITE = (255,255,255)
RED = (255,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)
BROWN = (156,84,14)

#Draws a house
def drawHouse():

    #Rectangles
    #Format is (surface, color, [x,y,length,width], width(outline) )
    pygame.draw.rect(screen,BLACK,[100,200,200,200],5) #House Base
    pygame.draw.rect(screen, BROWN, [260, 100, 25, 100]) #Chimney
    pygame.draw.rect(screen, GREEN, [130, 310, 50, 90], 4) #Door
    pygame.draw.rect(screen, BLUE, [220, 275, 20, 20], 4) #Window Top-Left
    pygame.draw.rect(screen, BLUE, [240, 275, 20, 20], 4) #Window Top-Right
    pygame.draw.rect(screen, BLUE, [220, 295, 20, 20], 4) #Window Bottom-Left
    pygame.draw.rect(screen, BLUE, [240, 295, 20, 20], 4) #Window Bottom-Right
    



    #Circle
    #Format is (surface, color, [x,y], radius of circle)
    pygame.draw.circle(screen, BLACK, [140, 355], 5) #Door Knob

    #Polygon (Triange)
    #Format is (surface, color, [ [x1,y1], [x2,y2], [x3,y3], ...], width)
    pygame.draw.polygon(screen, RED, [[50, 225], [200, 100], [350, 225]]) #Roof



pygame.init() #start pygame

#Used to manage game speed
clock = pygame.time.Clock()

#Create a display screen of 400x400 Pixels (tuple)
screen = pygame.display.set_mode((700,500))

pygame.display.set_caption("Drawing Shapes Intro")

done = False

#Runs game till user quits
while not done:
    #Checks to see if user hit x to quit
    for event in pygame.event.get(): #Checks event list
        if event.type == pygame.QUIT: #User clicks x
            done = True

    #Fill with new background color
    screen.fill(WHITE)

    #Draw stuff:
    drawHouse() 

    # Draw on the screen a green line from (0, 0) to (100, 100)
    # that is 5 pixels wide.
    #pygame.draw.line(screen, BLUE, [0, 0], [100, 200], 5)

    #Update screen
    clock.tick(60)
    pygame.display.update()

pygame.quit()
