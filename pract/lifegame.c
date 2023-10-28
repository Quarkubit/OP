#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// параметры поля
#define MAX_ROWS 5
#define MAX_COLS 5

//распределяем клетки(живой/мёртвый)
int generate_random(int max);

// генерируем поле
void create_grid(int grid[MAX_ROWS][MAX_COLS]);

// выводим поле
void print_grid(int grid[MAX_ROWS][MAX_COLS]);

// начинаем игру
void game_of_life(int grid[MAX_ROWS][MAX_COLS]);



int main() {
    int grid[MAX_ROWS][MAX_COLS];
    int generation = 0;
    srand(time(NULL));
    create_grid(grid);
    printf("Generation %d\n", generation);
    print_grid(grid);
    while (1) {
        char choice;
        printf("Next generation? ( Y / N ): ");
        scanf(" %c", &choice);
        if (choice == 'n') 
            break;
        game_of_life(grid);
        printf("Generation %d\n", ++generation);
        print_grid(grid);
    }
    return 0;
}

//распределяем клетки(живой/мёртвый)
int generate_random(int max) {
    return rand() % max;
}

// генерируем поле
void create_grid(int grid[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            grid[i][j] = generate_random(2);
        }
    }
}

// выводим поле
void print_grid(int grid[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// начинаем игру
void game_of_life(int grid[MAX_ROWS][MAX_COLS]) {
    int i, j, count, next_grid[MAX_ROWS][MAX_COLS];

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            count = 0;
            // проверка наличия "соседей"
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int nx = (i + x + MAX_ROWS) % MAX_ROWS;
                    int ny = (j + y + MAX_COLS) % MAX_COLS;

                    count += grid[nx][ny];//т.к. живая клетка = 1
                }
            }
            //проверка живой клетки
            if (grid[i][j] == 1) {
                if (count < 2 || count > 3) {
                    next_grid[i][j] = 0;
                } else {
                    next_grid[i][j] = 1;
                }
            //проверка мёртвой клетки
            } else {
                if (count == 3) {
                    next_grid[i][j] = 1;
                } else {
                    next_grid[i][j] = 0;
                }
            }
        }
    }
    // обновляем сетку следующей генерацией
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}