#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE]; // Game board 3x3

// Initialize the board with spaces
void initializeBoard() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

// Print the game board
void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Check for a winner. Returns 'X', 'O', or ' ' if none
char checkWin() {
    // Check rows
    for (int i = 0; i < SIZE; i++)
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return board[i][0];

    // Check columns
    for (int i = 0; i < SIZE; i++)
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return board[0][i];

    // Check diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}

// Check if the board is full (draw)
int isDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return 0; // Empty cells exist
    return 1; // Board full
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ';

    initializeBoard();

    while (1) {
        printBoard();
        printf("Player %c, enter your move (row and column, 0-2): ", currentPlayer);

        if (scanf("%d %d", &row, &col) != 2) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter two numbers separated by a space.\n");
            continue;
        }

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Coordinates must be between 0 and 2. Try again.\n");
            continue;
        }

        if (board[row][col] != ' ') {
            printf("That cell is already taken. Choose another one.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        winner = checkWin();
        if (winner != ' ') {
            printBoard();
            printf("Player %c wins!\n", winner);
            break;
        }

        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
