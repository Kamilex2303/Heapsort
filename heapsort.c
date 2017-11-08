#include <stdio.h>
 
int main(int argc, char **argv)
{
  int N ;  // liczebność zbioru
  int i,j,k,m,x;
 
  //Czytanie pliku
 
 FILE *plik = fopen("dane.txt", "r");
 
    int licz = 0;
    char ch;
 
    do {
      ch = fgetc(plik);                                      
        if(ch == '\n')  
        licz++;                                    
    } while (ch != EOF); // liczy dlugosc
fclose(plik);
 
 
N = licz;
int tab[N + 1];
 
 
plik = fopen("dane.txt", "r");
int n;
for( i=1; i<=licz; i++){
        fscanf( plik, "%d", &tab[i]); // wpisujemy w tablice dane pokolei z pliku
    }
fclose(plik);
 
for(i=1 ; i<=licz ; i++)
printf("%d ",tab[i]);
 
 
 
// Budujemy kopiec
 
  for(i = 2; i <= N; i++)
  {
    j = i; k = j / 2;
    x = tab[i];
    while((k > 0) && (tab[k] < x))
    {
      tab[j] = tab[k];
      j = k; k = j / 2;
    }
    tab[j] = x;
  }
 
// Rozbieramy kopiec
  int buffor;
  int buffor2;
  for(i = N; i > 1; i--)
  {
   
    buffor = tab[i];
    tab[i] = tab[1];
    tab[1] = buffor;
    j = 1; k = 2;
   
    while(k < i)
    {
      if((k + 1 < i) && (tab[k + 1] > tab[k]))
        m = k + 1;
      else
        m = k;
      if(tab[m] <= tab[j]) break;
     
      buffor2 = tab[m];
      tab[m] = tab[j];
      tab[j] = buffor2;
      j = m; k = j + j;
    }
  }
 
// Wyświetlamy wynik sortowania
 
  printf("\n");
  for(i = 1; i <= N; i++)  printf("%d ",tab[i]);
 
  return 0;

}
