#include "iostream"

using namespace std;

void draw_board(char board[3][3])
{
    cout << "\n-------------\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool check_for_win(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (
            // horizontal
            (board[i][0] == player &&
             board[i][1] == player &&
             board[i][2] == player) ||
            // diagonal
            (board[i][0] == player &&
             board[i + 1][1] == player &&
             board[i + 2][2] == player) ||
            // diagonal
            (board[i + 2][0] == player &&
             board[i + 1][1] == player &&
             board[i][2] == player) ||
            // vertical
            (board[0][i] == player &&
             board[1][i] == player &&
             board[2][i] == player))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int active = 1, col, row, turn = 0;
    char player = 'X';

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    while (active && turn < 9)
    {
        draw_board(board);
        cout << player << "'s turn. " << "Please provide row (0 - 2) and column (0 - 2): ";
        cin >> col >> row;

        if (col < 0 || col > 2 || row < 0 || row > 2)
        {
            cout << "Invalid input. Please provide a row number and a column between 0 and 2. e.g. 1 2: ";
        }
        else if (board[col][row] != ' ')
        {
            cout << "Invalid input. That position is taken" << endl;
        }
        else
        {
            board[col][row] = player;
            if (check_for_win(board, player))
            {
                draw_board(board);
                cout << "\nPlayer " << player << " has won the game!" << endl;
                active = 0;
            }
            player = (player == 'X') ? 'O' : 'X';
            turn++;
        }
    }
    draw_board(board);
    cout << "game finished";
    return 1;
}