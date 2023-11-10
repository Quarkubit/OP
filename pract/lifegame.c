#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// параметры поля
#define ROWS 10
#define COLS 10

//распределяем клетки(живой/мёртвый)
int generate_random(int max);

// генерируем поле
void create_grid(int grid[ROWS][COLS]);

// выводим поле
void print_grid(int grid[ROWS][COLS]);

// проводим игру
void game_of_life(int grid[ROWS][COLS]);



int main() {
    int grid[ROWS][COLS];
    int generation = 0;
    srand(time(NULL));//устанавливаем текущее время как seed для генерации
    create_grid(grid);// генерируем поле
    printf("Generation %d\n", generation);
    print_grid(grid);// выводим поле
    while (1) {
        char choice;
        printf("Next generation? ( Y / N ): ");
        scanf(" %c", &choice);// генерация идёт по команде пользователя(пока не остановят командой "n" или "N")
        if ((choice == 'n') || (choice == 'N')) 
            break;
        game_of_life(grid);// проводим игру
        printf("Generation %d\n", ++generation);// выводим результат
        print_grid(grid);// выводим поле после геерации
    }
    return 0;
}



//распределяем клетки(живой/мёртвый)
int generate_random(int max) {
    return rand() % max;
}

// генерируем поле
void create_grid(int grid[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = generate_random(2);
        }
    }
}

// выводим поле
void print_grid(int grid[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// начинаем игру
void game_of_life(int grid[ROWS][COLS]) {
    int i, j, count, next_grid[ROWS][COLS];

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            count = 0;
            // проверка наличия "соседей"
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) 
                        continue;
                    int nx = (i + x + ROWS) % ROWS;
                    int ny = (j + y + COLS) % COLS;

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
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}