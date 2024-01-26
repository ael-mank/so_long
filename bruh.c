#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 15
#define WALL '1'
#define PATH '0'

void generate_maze(char maze[HEIGHT][WIDTH], int x, int y) {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; ++i) {
        int rnd = rand() % 4;
        int temp = directions[i][0];
        directions[i][0] = directions[rnd][0];
        directions[rnd][0] = temp;
        temp = directions[i][1];
        directions[i][1] = directions[rnd][1];
        directions[rnd][1] = temp;
    }

    for (int i = 0; i < 4; ++i) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int nx = x + dx * 2;
        int ny = y + dy * 2;

        if (nx > 0 && nx < WIDTH - 1 && ny > 0 && ny < HEIGHT - 1 && maze[ny][nx] == WALL) {
            maze[ny - dy][nx - dx] = PATH;
            maze[ny][nx] = PATH;
            generate_maze(maze, nx, ny);
        }
    }
}

int main() {
    srand(time(NULL));
    char maze[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            maze[y][x] = WALL;
        }
    }

    int start_x = 1 + rand() % ((WIDTH - 3) / 2) * 2;
    int start_y = 1 + rand() % ((HEIGHT - 3) / 2) * 2;
    maze[start_y][start_x] = PATH;
    generate_maze(maze, start_x, start_y);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            putchar(maze[y][x]);
        }
        putchar('\n');
    }

    return 0;
}