#include <stdio.h>
#include <locale.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'

#define NULL_C '_'

#define LINE_QTY 3
#define COLUMN_QTY 3

int check_line_win(char board[LINE_QTY][COLUMN_QTY], char player);
int check_column_win(char board[LINE_QTY][COLUMN_QTY], char player);
int check_diagonal_win(char board[LINE_QTY][COLUMN_QTY], char player);
int check_draw(char board[LINE_QTY][COLUMN_QTY]);

int main()
{
    setlocale(LC_ALL, "Portuguese-Brazilian");

    int line;
    int column;
    int position;
    char currentPlayer = PLAYER_X;

    char board[LINE_QTY][COLUMN_QTY];
    for (line = 0; line < LINE_QTY; line++)
    {
        for (column = 0; column < COLUMN_QTY; column++)
        {
            board[line][column] = NULL_C;
        }
    }

    while (1)
    {
        printf("Player %c it's your turn! Choose a position: (1-9):\n", currentPlayer);
        scanf("%d", &position);

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (position < 1 || position > 9 || board[row][col] != NULL_C)
        {
            printf("Invalid position or already filled! Please try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        printf("\nBoard:\n");
        for (line = 0; line < LINE_QTY; line++)
        {
            for (column = 0; column < COLUMN_QTY; column++)
            {
                printf("%c ", board[line][column]);
            }
            printf("\n");
        }

        if (check_line_win(board, currentPlayer) || check_column_win(board, currentPlayer) || check_diagonal_win(board, currentPlayer))
        {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (check_draw(board))
        {
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}

int check_line_win(char board[LINE_QTY][COLUMN_QTY], char player)
{
    for (int line = 0; line < LINE_QTY; line++)
    {
        if (board[line][0] == player && board[line][1] == player && board[line][2] == player)
        {
            return 1;
        }
    }
    return 0;
}

int check_column_win(char board[LINE_QTY][COLUMN_QTY], char player)
{
    for (int column = 0; column < COLUMN_QTY; column++)
    {
        if (board[0][column] == player && board[1][column] == player && board[2][column] == player)
        {
            return 1;
        }
    }
    return 0;
}

int check_diagonal_win(char board[LINE_QTY][COLUMN_QTY], char player)
{
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }
    return 0;
}

int check_draw(char board[LINE_QTY][COLUMN_QTY])
{
    for (int line = 0; line < LINE_QTY; line++)
    {
        for (int column = 0; column < COLUMN_QTY; column++)
        {
            if (board[line][column] == NULL_C)
            {
                return 0;
            }
        }
    }
    return 1;
}
