#include <stdio.h>

char board[3][3];

void initBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("  %c | %c | %c \n",
            board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf(" ---|---|---\n");
    }
    printf("\n");
}

int checkWin(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==p && board[i][1]==p && board[i][2]==p) return 1;
        if (board[0][i]==p && board[1][i]==p && board[2][i]==p) return 1;
    }
    if (board[0][0]==p && board[1][1]==p && board[2][2]==p) return 1;
    if (board[0][2]==p && board[1][1]==p && board[2][0]==p) return 1;
    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

int main() {
    initBoard();
    char current = 'X';
    int pos;

    printf("=== TIC TAC TOE ===\n");
    printf("Player 1 = X\n");
    printf("Player 2 = O\n");

    while (1) {
        printBoard();
        printf("Player %c - Enter position (1-9): ", current);
        scanf("%d", &pos);

        int r = (pos - 1) / 3;
        int c = (pos - 1) % 3;

        if (pos < 1 || pos > 9 ||
            board[r][c] == 'X' || board[r][c] == 'O') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[r][c] = current;

        if (checkWin(current)) {
            printBoard();
            printf("*** Player %c WINS! ***\n", current);
            break;
        }

        if (checkDraw()) {
            printBoard();
            printf("*** It's a DRAW! ***\n");
            break;
        }

        current = (current == 'X') ? 'O' : 'X';
    }

    return 0;
}
