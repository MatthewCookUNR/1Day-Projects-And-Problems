import pygame

#define constants (RGB colors)
BLACK = (0,0,0)
WHITE = (255,255,255)
RED = (255,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)

pygame.init() #start pygame

#Create a display screen of 400x400 Pixels
screen = pygame.display.set_mode((400,400))

pygame.display.set_caption("Matts Coolest Game")

done = False

while not done:
    #Checks to see if user hit x to quit
    for event in pygame.event.get(): #Checks event list
        if event.type == pygame.QUIT: #User clicks x
            done = True

    #Fill with new background color
    screen.fill(GREEN)

    #Draw stuff:

    #Update screen
    pygame.display.update()

pygame.quit()
