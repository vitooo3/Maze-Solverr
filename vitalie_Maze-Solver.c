#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define R 23
#define C 78
int percorsi = 0;

int exp(int Ir, int Ic, int Ur, int Uc, char L[R][C], int cnt1){
       int i = Ir;
       int j = Ic;
       int cntchar;
       int decision[4];
       int chain = 1;

       for(size_t k = 0; k < 3; k++)
       decision[k] = 0;


       if(cnt1 == 96)
           cnt1++;


       char s[3];
       char c;
    //   sprintf(s, "%d", cnt1);
      c = cnt1;
         
    
      // v


      
      
      // v
      
   
    
    
    
      if( i == Ur && (j-1) == Uc)
          {
             
            percorsi++;
            printf("\nPERCORSO NR : %c %d\n", cnt1, cnt1);


              return 1;
          }else
          {
              if(L[i][j] != '#' && L[i][j] != 'U'){
      
           if((i >=0 &&  (j>= 0 && j < C)) && L[i][j+1] == ' ')
           { 
                decision[3] = 1;
                
            }
                if((i >= 0 && j > 0) && L[i][j-1] == ' ')
            {
                decision[1] = 1;
            }
      
                if((i > 0 && j>= 0) && L[i-1][j] == ' ')
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
              cnt1++;
              chain=
              exp(i-1,j,Ur,Uc, L, cnt1-1);
            }

            if(decision[1])
       {
          if(L[i][j-1] == ' ')
          L[i][j-1] = c;
          //putchar(c);
          cnt1++;
         chain+=1;
         exp(i,j-1 , Ur, Uc, L, cnt1-1); 
       }
      
        if(decision[2])
        {
         if(L[i+1][j] == ' ')
         L[i+1][j] = c;
         //putchar(c);
         cnt1++;
         chain+=1;
        exp(i+1,j , Ur, Uc, L, cnt1-1);      
        }

       if(decision[3])
       {
         if(L[i][j+1] == ' ')
         L[i][j+1] = c;
        //putchar(c);
         cnt1++;
          chain+=1;
          exp(i,j+1, Ur, Uc, L, cnt1-1); 
       } 

    }
    
    }


     
         return -1;

       }
     



char buffer2[1024];
void cleaner(int Ir, int Ic, int Ur , int Uc, char L[R][C])
{
    int i = Ir;
    int j = Ic;
    
    char c = ' ';


    
      for(size_t i = Ic; i < R; i++)
      {
        for(size_t j = Ir; j < C; j++)
        {
        if( (L[i][j] != '#' && L[i][j] != 'U' &&  L[i][j] != 'I'  && L[i][j] != 'o' && L[i][j] != 'a' && L[i][j] != 'e' && L[i][j] != 'h')!=0)
        L[i][j] = c;
        printf("%c", L[i][j]);
      
      }
      printf("\n");

    } 


    printf("valore di c: %c\n",c);

    int numC = c - 97;
    printf("num: %d\n\n\n",numC);

    int lunghezza = 0;
    int distanze[2*C];
    for(size_t i = 0; i < 2*C; i++)
    distanze[i] = -1;
    int myCnt = 0;
    distanze[numC] = cnt1;
    myCnt++;


    int MIN = 9999999;
    int pos;
    int results[C/2];
    
    for(size_t i = 0; i < C/2; i++)
    results[i] = -1;
    
    for(size_t i = 0; i < 2*C; i++)
    {
        if(distanze[i] != -1 && (distanze[i] <= distanze[i+1] && i!= pos) )
        {
            MIN = distanze[i];
            pos = i;

          
        }
    }


    for(size_t i = 0; i < 2*C; i++)
    {
        if(distanze[i] != -1 && (distanze[i] <= distanze[i+1] && i!= pos) )
        {

            results[i] = distanze[i];

        }
    }

    puts(" ");
    for(size_t i = 0; i < C/2; i++)
    {
        if(results[i] != -1)
        {
            printf("lunghezza %d: %d\n",i, results[i]);
        }
    }


     
    for(size_t i = 0; i < 2*C; i++)
{
  if(distanze[i] != -1 && (distanze[i] <= distanze[i+1] && i!= pos) )
  {
      results[i] = distanze[i]; 
  }

}


puts(" ");
  for(size_t i = 0; i < C/2; i++)
  printf("%d ",results[i]);









    
  }
  


int main(){
    char buffer[1024];
    char L[R][C];
   

    // PARTI DALLA LETTERA I
    // vai dritto fino al ostacolo (#)
    // verifica se a destra o a sinistra sia libero , se e libero a destra o a sinistra vai in una delle due
    // e se nessuna delle due e libera
    //  torna indietro prendi la prima uscita che trovi per prima (destra o sinistra) ,
    // vai dritto fino al ostacolo
    // se la destra o la sinistra e libera prendi una delle due
    // e vai dritto fino al ostacolo ,
    // se la destra e la sinistra non e libera ,
    // torna indietro finche non trovi una uscita (a destra o a sinistra)
    // prendi la destra o la sinistra e vai dritto fino al ostacolo ,
    // verifica la destra e la sinistra , prendi quella libera
    // (cosi in loop fino a quando non esce dal labirinto)
    // LUSCITA DEL LABIRINTO E INDICATA CON LA LETTERA U


    FILE *lab = fopen("labirinto1.txt" , "r");  


char th1[R],th2[R],th3[R],th4[R];
int cnt = 0;
int cnt1 = 97;
char c;
c = cnt1;
int mycnt = 96;
int inzio_i = -1, fine_u = -1;




int i = 0;
while(fscanf(lab, "%s %s ", &th1,&th2) == 2) {
   
    fgets(buffer, sizeof(buffer), lab);
       


    buffer[strlen(buffer)-3] = '\0';


                for(size_t j = 0; j < C; j++)
        {
            L[i][j] = buffer[j];
            printf("%c", L[i][j]);              }
        printf("\n");
        i++;
}


fclose(lab);


   
int Ir,Ic,Ur,Uc;
for(size_t i = 0; i < R; i++){


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

    

exp(Ir,Ic,Ur,Uc,L, mycnt);
for(size_t i = 0; i < R; i++){


    for(size_t j = 0; j < C; j++)
    {
        printf("%c", L[i][j]);

  }
  printf("\n");

}





      
      








printf("Percosi totali che portato alla fine del labirinto : %d \n", percorsi);


cleaner(0,0,Ur, Uc, L);


return 0;
}
