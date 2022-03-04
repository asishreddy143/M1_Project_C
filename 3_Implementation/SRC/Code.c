#include <stdio.h>
#include <stdlib.h>

char** creatematrix();
void print(char** Matrix);
int istie(char** Matrix);
char victorystep(char** Matrix, int a, int b);

int main() {
  char** Matrix = creatematrix();
  char victory = '\0';
  char line;
  char column;
  char chance = 'X';

  while(!victory && !istie(Matrix)) {
    printf("Mini Project-C Language\n");
    printf("Let's Play Tic-Tac-Toe.\n");
    print(Matrix);
    printf("Player %c, make your move: ", chance);
    fflush(stdout);
    scanf(" %c %c", &line, &column);

    int rowind = line - 'P';
    int colind = column - '1';
    if (Matrix[rowind][colind] == ' ') {
      Matrix[rowind][colind] = chance;
      if (chance == 'X') {
	chance = 'O';
      } else {
	chance = 'X';
      }
      victory = victorystep(Matrix, rowind, colind);
    } else {
      printf("Block occupied; Please retry.\n");
    }
  }

  print(Matrix);
  if (victory == 'X' || victory == 'O') {
    printf("Congratulations Player %c!\n", victory);
    printf("Thank you for playing Tic-Tac-Toe\n");
  } else {
    printf("Game ends in a draw.\n");
  }

  return 0;
}

char** creatematrix() {
  char** Q = calloc(3, sizeof(char*));
  for(int a = 0; a < 3; ++a) {
    Q[a] = calloc(3, sizeof(char));
  }

  for(int b=0; b < 3; ++b) {
    for(int c=0; c < 3; ++c) {
      Q[b][c] = ' ';
    }
  }

  return Q;
}

void print(char** Matrix) {
  printf(" |1|2|3|\n");
  for(int a = 0; a < 3; ++a) {
    printf("%c|", 'P' + a);
    for(int b = 0; b < 3; ++b) {
      printf("%c|", Matrix[a][b]);
    }
    printf("\n");
  }
}

int istie(char** Matrix) {
  for(int a = 0; a < 3; ++a) {
    for(int b = 0; b < 3; ++b) {
      if (Matrix[a][b] == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

char victorystep(char** Matrix, int a, int b) {
  if (Matrix[a][b] == Matrix[a][(b+1)%3]
   && Matrix[a][b] == Matrix[a][(b+2)%3])
  {
    return Matrix[a][b];
  }
  else if (Matrix[a][b] == Matrix[(a+1)%3][b]
          && Matrix[a][b] == Matrix[(a+2)%3][b])
  {
    return Matrix[a][b];
  }
  else if (a == b && Matrix[a][b] == Matrix[(a+1)%3][(b+1)%3]
                  && Matrix[a][b] == Matrix[(a+2)%3][(b+2)%3])
  {
    return Matrix[a][b];
  }
  else if (a+b == 2 && Matrix[a][b] == Matrix[(a+2)%3][(b+1)%3]
                    && Matrix[a][b] == Matrix[(a+1)%3][(b+2)%3])
  {
    return Matrix[a][b];
  }
  else {
    return 0;
  }
}
