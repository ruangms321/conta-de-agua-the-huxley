/*Num tabuleiro NxM, uma peça é colocada na posição (0, 0). Tal peça só pode
mover-se para cima (C), baixo (B), esquerda (E), e direita (D). Cada casa do
tabuleiro tem um valor inteiro. A peça só pode mover-se para uma casa adjacente
se essa casa tiver valor 0. Senão, a casa para onde a peça tentou se mover terá
seu valor decrementado por 1.

Por exemplo, se a casa à esquerda da peça tiver valor 5 e a peça tentar mover-se
para a esquerda, a casa à esquerda ficará com valor 4 e a peça não se move.


- Se a peça tentar mover-se para uma casa com valor 0, ela consegue (o 0 não é
decrementado).
- A peça não consegue ir para fora dos limites do tabuleiro.


Serão dados os movimentos da peça. Será também dada uma coordenada no tabuleiro.
Se a peça conseguiu chegar nessa coordenada, seu código deve printar "Cheguei
com N movimentos", sendo N o número de movimentos que foram feitos para chegar
na coordenada. Se a peça não conseguiu chegar na coordenada, deve-se printar
"Nao cheguei".



OBS: Pode ser que a peça não necessite usar todos os movimentos dados para
chegar na coordenada dada.





    ENTRADAS DE EXMPLOS: SO COLAR NO CONSOLE
tamanho da matriz(tabuleiro)
valores de posicao da matriz(tabuleiro)
numero de movimentos
movimentos(
     'C' movimenta a peça para cima.       [i-1] [j]
     'D' movimenta a peça para a direita.  [i] [j+1]
     'B' movimenta a peça para baixo.      [i+1] [j]
     'E' movimenta a peça para a esquerda. [i] [j-1]
)
posicao final no tabuleiro

SAIDA

  -se chegou na posicao da ultima linha da entrada print "Cheguei com %d
movimentos" %d é a       quantidade de movimentos pra conseguir chegar na ultima
linha da entrada

  -se nao "Nao cheguei"

****comeco da entrada nao copiar****
5 5
0 0 0 3 5
9 8 2 5 1
0 0 1 1 2
5 9 9 8 1
0 1 0 0 0
14
D
D
D
D
D
D
B
B
B
B
B
B
B
B
2 3
 ****fim da entrada nao copiar****

*/
#include <stdio.h>
int main() {
  int n, m, movimentos;

  scanf("%d %d", &n, &m);     // scanea o tamanho do tabuleiro
  int tabu[n][m];             // tamanho do tabuleiro
  for (int i = 0; i < n; i++) // preencher tabuleiro com valores das casas
  {
    for (int j = 0; j < m; j++) {
      scanf("%d", &tabu[i][j]);
    }
  }

  scanf("%d", &movimentos); // scanea a quantidade de movimentos maxima
  int i = 0, j = 0;
  char realtime[movimentos];
  // ****************AKI*************
  int t = 0 , o = 0;
  int w = 0;
  for (int l = 0; l < movimentos; l++) // andar no tabuleiro
    {
    scanf(" %c%*[^\n]", &realtime[l]);
    }
    scanf("%d %d", &t, &o);
    int c_movi = 0;
    
    for (int l = 0; l < movimentos; l++) // andar no tabuleiro
  {
    if (t == i && o == j) break;
     // quando o for reperir zera a variavel"realtime"
    if (c_movi <= movimentos) // movimenta ate a quantidade maxima dada na entrada
    {  //esse if na iria precisa
      //n to lembrando porque o for ta "for (int l = 0; l < n; l++)"
      // acho q era pra repetir ate movimentos
        // scanea a a letra do movimento(ex: D move pra direita,)
      //printf("você pressionou %c", realtime);    // so debug, pra ver qual letra foi lido
      if (realtime[l] == 'C') // se a entrada for "C" executa
      {
        if (i - 1 != -1) // se o movimento nao sair do tabuleiro ele executa
        {
          i -= 1; /* entrada "C"== subir subia na posicao da matriz se
                  tiver em (1, 0) iria para (0, 0) *sendo (i, j) padrao
                  de posicao na matriz da matematica */

          if (tabu[i][j] >
              0) // se o valor na posicao atual da matriz for maior que zero
          {
            tabu[i][j] -= 1; // o valor da posicao diminuiria 1
            i += 1;          // e desfaz o movimento
            
            c_movi++;
            continue;        // acrescenta 1 na quantidade de movimentos feito
            //printf("\nD3 MOVIMENTOS: %d I: %d J: %d", c_movi, i, j);
          }
          c_movi++;
          //printf("\nD4 MOVIMENTOS: %d I: %d J: %d", c_movi, i, j);
        } else
          continue; // se sair da matriz simplesmente ignora
      }
      if (realtime[l] == 'D') // se a entrada for "D" executa
      {
        if ((j + 1) != m) // se o movimento nao sair do tabuleiro ele executa
               // OBS: ME ATRAPALHO COM AS POSICOES DA MATRIZ NESSE CASO
        // POIS A MATRIZ COMECA DE 0
        {
          j += 1; // o valor da posicao aumenta 1 "D" iria pra direita ou seja
                  // aumentaria posicao em uma coluna ex: antes estava em (2, 3)
                  // FICARIA (2, 4)
          if (tabu[i][j] >
              0) // se o valor na posicao atual da matriz for maior que zero
          {
            tabu[i][j] -= 1; // o valor da posicao diminuiria 1
            j -=
                1; // e desfaz o movimento o movimento esta fora desse IF j += 1
            c_movi++;
            continue; // conta os movimentos
          }

            c_movi++;
         
        } else
          continue; // se sair da matriz simplesmente ignora
      }
      if (realtime[l] == 'B') // se a entrada for "B" executa
      {
        if (i + 1 != n) {
          i += 1;                 // fez o movimento
          if (tabu[i][j] > 0) {   // o valor dessa posicao é maior que 0
            tabu[i][j] -= 1;       // essa posicao perde 1
            i -= 1;               //e a peca desfez o movimento
            c_movi++;
            continue;
            
          }
          c_movi++;
        } else
          continue; // se sair da matriz simplesmente ignora
      }
      if (realtime[l] == 'E') {
        if (j - 1 !=
            -1) { // se o movimento nao sair do tabuleiro ele executa
                  // OBS: ME ATRAPALHO COM AS POSICOES DA MATRIZ NESSE CASO
                  // POIS A MATRIZ COMECA DE 0
                  // se estivesse na posicao 0 executando esse movimento ficaria
                  // -1                             //entao sairia do
                  // tabuleiro(matriz), por isso nao entra nesse if

          j -= 1; // o valor da posicao diminui 1 ex: (1, 2) ficaria (1, 1)
          if (tabu[i][j] > 0) {
            tabu[i][j] -= 1;
            j += 1;
            c_movi++;
            continue;
            //printf("\nD5 MOVIMENTOS: %d I: %d J: %d", c_movi, i, j);
          }
          c_movi++;
          //printf("\nD6 MOVIMENTOS: %d I: %d J: %d", c_movi, i, j);
        } else
          continue; // se sair da matriz simplesmente ignora
      }
    }
  }
  
  //scanf("%d %d", &t, &o);
  // printf("debug linha: %d coluna: %d linha: %d coluna: %d /", t, o, i, j);
  // //debug
    if (t == i && o == j) {
        printf("\nCheguei com %d movimentos", c_movi);
     } else {
      printf("\nNao cheguei");
     }
  return 0;
}
