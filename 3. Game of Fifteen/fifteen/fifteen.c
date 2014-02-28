/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;
int found_row, found_col = 0;
int blank_row, blank_col = 0;
int swap_row,  swap_col  = 0;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);
bool findTile(int t);
void swap_tiles();

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    int values = d*d;
    
    for (int rows = 0; rows < d; rows++)
    {
        for (int columns = 0; columns < d; columns++)
        {
            board[rows][columns] = --values;
        }
    }
    
    // Simple function to swap "2" and "1"
    // If the dimensions of the board is found to be even
    if (d % 2 == 0)
    {
        int tmp = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = tmp;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int rows = 0; rows < d; rows++)
    {
        for (int columns = 0; columns < d; columns++)
        {   
            if (board[rows][columns] != 0)
            {
                printf("%3d", board[rows][columns]);
            }
            else
            {
                blank_row = rows;
                blank_col = columns;
                printf("  *");
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // Check whether tile is on the board
    if (findTile(tile))
    {
        // Check to see if blank tile's row position is equal to selected tile's row position
        if (blank_row + 1 == found_row || blank_row - 1 == found_row)
        {
            // To ensure only selecting tile below or above blank tile (column position stays the same)
            if (blank_col == found_col)
            {
                swap_tiles();
                return true;
            }
        }
        // Check to see if blank tile's column position is equal to selected tile's column position   
        if (blank_col + 1 == found_col || blank_col - 1 == found_col)
        {
            // To ensure only selecting tiles left or right of blank tile (row position stays the same)
            if (blank_row == found_row)
            {
                swap_tiles();
                return true;
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    return false;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}

/*
 *  A simple function to find the position of a tile
 *  Will return true if the tile is found, otherwise false if not found
 */
bool findTile(int tile)
{
    for (int rows = 0; rows < d; rows++)
    {
        for (int columns = 0; columns < d; columns++)
        {   
            if (board[rows][columns] == tile)
            {
                found_row = rows;
                found_col = columns;
                return true;
            }
        }
    }
    return false;
}

/*
 *  A simple function to swap the position of two tiles
 */
void swap_tiles()
{
    int tmp = board[found_row][found_col];
    board[found_row][found_col] = board[blank_row][blank_col];
    board[blank_row][blank_col] = tmp;
}