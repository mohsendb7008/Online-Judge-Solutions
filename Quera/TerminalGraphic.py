import pygame

if __name__ == '__main__':
    pygame.init()
    screen = pygame.display.set_mode((300, 300))
    screen.fill((255, 255, 255))
    pen_thickness, pen_color = 1, (0, 0, 0)
    while True:
        pygame.event.pump()
        cmd = input()
        if cmd.startswith('change size'):
            pen_thickness = int(cmd.split()[2])
        elif cmd.startswith('change color'):
            pen_color = tuple(map(int, cmd.split()[2:]))
        elif cmd.startswith('draw line'):
            p1 = tuple(map(int, cmd.split()[2:4]))
            p2 = tuple(map(int, cmd.split()[4:6]))
            pygame.draw.line(screen, pen_color, p1, p2, pen_thickness)
        elif cmd.startswith('draw circle'):
            c = tuple(map(int, cmd.split()[2:4]))
            r = int(cmd.split()[4])
            pygame.draw.circle(screen, pen_color, c, r, pen_thickness)
        elif cmd.startswith('draw polygon'):
            rest = list(map(int, cmd.split()[2:]))
            poly = []
            for i in range(0, len(rest), 2):
                poly.append((rest[i], rest[i+1]))
            pygame.draw.polygon(screen, pen_color, poly, pen_thickness)
        elif cmd.startswith('end drawing'):
            pygame.image.save(screen, 'draw.png')
            pygame.quit()

