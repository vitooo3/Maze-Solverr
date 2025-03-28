#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define R 23
#define C 78
int cntEXIT = 0;
int direction[C*2];



int explore(int Ir, int Ic,int Ur, int Uc, char L[R][C], int cnt)
{
    int lunghezzapercorso = 0;
    int i = Ir;
    int j = Ic;
    int cntchar;
    int decision[4];
    int chain = 1;
 //array direction



    for(size_t k = 0; k < 3; k++)
    decision[k] = 0;

    if(cnt == 96)
    cnt++;

    char s[3];
    char c;
    // sprintf(s, "%d", cnt);
    // c = s[0];
    c = cnt; 

    cnt=c;
    
    int percs_uscita;
    int numC = c - 97;
    int lunghezza = 0;
    int distanze[C*2];

        for(size_t i = 0; i < 2*C; i++)
        distanze[i] = -1;

    if( i == Ur && (j-1) == Uc)
    {
        cntEXIT++;
      printf("\npercorso/i che arrivano all'uscita: %c (%d)\n\n", cnt, cnt);
    


        distanze[numC] = cnt;
        int MIN = 9999999;
        int pos;
        int results[C/2];
        for(size_t i = 0; i < C/2; i++)
        results[i] = -1;
    
        for(size_t i = 0; i < 2*C; i++)
            {
            if(distanze[i] != -1 && (distanze[i] < MIN ) )
            {
                MIN = distanze[i];
                pos = i;
            }
    
           }
    
        results[pos] = MIN;
    
        printf("lunghezza percorso più breve per l'uscita: %d\n\n",MIN);

        for(size_t i = 0; i < 2*C; i++)
        {
        if(distanze[i] != -1 && (distanze[i] <= distanze[i+1] && i != pos) )
        {
            results[i] = distanze[i]; 
        }

        }
    
        return 1;
        
    }else
    {
        if(L[i][j] != '#' && L[i][j] != 'U'){

      if((i >= 0 && (j>= 0 && j < C)) && L[i][j+1] == ' ')
      {
            decision[3] = 1;    
      }

      if((i >= 0 && j> 0) && L[i][j-1] == ' ')
      {
        decision[1] = 1;  
      }
      
      if((i > 0 &&  j>= 0) && L[i-1][j] == ' ')
      { 
       decision[0] = 1;
      
      }
    
      if(((i >= 0 && i < R) && j>= 0) && L[i+1][j] == ' ')
      {
        decision[2] = 1;
      }

      if(decision[0])
      {
        if(L[i-1][j] == ' ')
        L[i-1][j] = c;
        //putchar(L[i-1][j]);
        cnt+=chain;
        chain+=1;
        explore(i-1,j , Ur, Uc, L, cnt-1);
      }

      if(decision[1])
      {
        if(L[i][j-1] == ' ')
        L[i][j-1] = c;
        //putchar(c);
        cnt+=chain;
        chain+=1;
        explore(i,j-1 , Ur, Uc, L, cnt-1); 
      }
      
      if(decision[2])
      {
        if(L[i+1][j] == ' ')
        L[i+1][j] = c;
        //putchar(c);
        cnt+=chain;
        chain+=1;
        explore(i+1,j , Ur, Uc, L, cnt-1);      
      }

      if(decision[3])
      {
        if(L[i][j+1] == ' ')
        L[i][j+1] = c;
        //putchar(c);
        cnt+=chain;
        chain+=1;
        explore(i,j+1, Ur, Uc, L, cnt-1); 
      } 

    }
    
    }
    

    


    return -1;

    }
   

    
        
         /*
         if((i > 0 &&  j>= 0) && L[i-1][j] == ' ')
         { 
              L[i-1][j] = 'd';
              exp(--i,j , Ur, Uc, L);
                
          }else
          {

              if(((i >= 0 && i < 23) && j>= 0) && L[i+1][j] == ' ')
          {
              L[i+1][j] = 'u';
              exp(++i,j, Ur, Uc, L);

          }else 
          {
              if((i >= 0 && j> 0) && L[i][j-1] == ' ')
          {

              L[i][j-1] = 'l';
              exp(i,--j , Ur, Uc, L);
              
          }else 
          {
              if((i >= 0 && (j>= 0 && j < 23)) && L[i][j+1] == ' ')
              {

                  L[i][j+1] = 'r';
                  exp(i,++j , Ur, Uc, L);
              }

             }
            }
          }
          */

        void clear(int Ir, int Ic, int Ur, int Uc, char L[R][C], int cnt)
          {
              int i = Ir;
              int j = Ic;
              
              char c = ' ';

              for(size_t i = Ic; i < R; i++)
              {
        
              for(size_t j = Ir; j < C; j++)
                {
                if( (L[i][j] != '#' && L[i][j] != 'U' &&  L[i][j] != 'I'  && L[i][j] != 'o'  && L[i][j] != 'a'  && L[i][j] != 'i'  && L[i][j] != 'm'  && L[i][j] != 'q'  && L[i][j] != 'k')!=0) //&& L[i][j] != 'k' && L[i][j] != 'a' && L[i][j] != 'j' && L[i][j] != 'i')!= 0)
                  
                L[i][j] = c;
                  printf("%c", L[i][j]);
                // shift array distanza e logica per salvare l
            
          
                }
                printf("\n");

              } 
              
            }
            
              
              
              
              
          
              


int main()
{
    char buffer[1024];
    char L[R][C];


    FILE *file = fopen("gge.txt", "r");
    char th1[R],th2[R],th3[R],th4[R];
    int cnt = 0;
    int mycnt = 96;
    int rigaI = -1, rigaU = -1;
    int i = 0;


    while(fscanf(file, "%s %s ", &th1,&th2) == 2) {
    
    fgets(buffer, sizeof(buffer), file);
    //printf("\n%s\n\n", buffer);
    
    //memmove(buffer, buffer+9, strlen(buffer));

    buffer[strlen(buffer)-3] = '\0'; 
    
    for(size_t j = 0; j < C; j++)
    {
        L[i][j] = buffer[j];
        printf("%c", L[i][j]);
    }
        printf("\n");
        i++;
    }

    

 
  fclose(file);  
    int Ir, Ic, Ur, Uc;
    
  for(size_t i = 0; i < R; i++)
    {

      for(size_t j = 0; j < C; j++)
      {
        if(L[i][j] == 'I')
        {
        Ir = i;
        Ic = j;
        }
        if(L[i][j] == 'U') 
        {
        Ur = i;
        Uc = j;
        }

        }
        
    } 

    printf("\n");
      explore(Ir, Ic, Ur, Uc, L, mycnt);

      for(size_t i = 0; i < R; i++)
      {

      for(size_t j = 0; j < C; j++)
        {
        printf("%c", L[i][j]);

        }
        printf("\n");
      } 


      printf("\nn° percorso/i che arrivano all'uscita: %d\n\n", cntEXIT);

      clear(0, 0, Ur, Uc, L, cnt);
     

      

    
      //ripulire il labirinto lasciando i perc
      //devo inizializzare tutti gli elementi di distanze a -1
//shift da ASCII code a int 

    
    
// /*
// PARTI DALLA CASELLA ACCANTO ALLA I CHE NON è UN #.
// SPOSTATI NELLA DIREZIONE OPPOSTA DI DOVE SI TROVA LA I (ES. SE SI TROVA ALLA TUA SINISTRA, VAI A DESTRA ECC)
// CONTINUA SU QUELLA STRADA FINCHè NON TROVI UN #
// SE TI TROVI CIRCONDATO DA #, TORNA INDIETRO FINO A QUANDO NON TI TROVI IN UNA STRADA CON PIù CASELLE LIBERE
// PROVA UNA DELLE VIE FINCHè NON TROVI UN #
// CONTINUA COSì FINCHè NON TROVI IL CARATTERE U
// */



  /*
  COSE CHE MANCANO
  -funzione per ripulire è tipo explore con j o
  -SALVARE IN UN ARRAY DI CHAR IL PERCORSO CHE ARRIVA ALLA U PIù CORTO
  -STAMPARE SOLAMENTE IL PERCORSO PIù CORTO
  
  */

  // for(size_t i = 0; i < R; i++)
  // {

  // for(size_t j = 0; j < C; j++)
  //   {
  //     char c;
  //     cnt=c;
  //     int perc_uscita;
  //     char distanze[C*2];
  //     if(strchr(distanze, 'I' && 'U') != NULL)
  // {
  //   perc_uscita = 1;
  // }

  //   printf("%d\n", perc_uscita);
      
  // }
  //  printf("\n");
  //   } 
   






    return 0;
}

          






