#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

int randomim(int n)
{
    int r,t,p,tp;
    double d=RAND_MAX;

    t=time(NULL);
    p=_getpid();
    tp=round(t/p);

    srand(tp);
    r=round(n*(rand()/d));

    return r;
}

void dobavlenie_elementa(int a[100][100],int n,int m)
{
    int i,j,k=0,r;

    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
           if (a[i][j]==0) k++;

    r=randomim(k-1)+1;

    k=0;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
           if (a[i][j]==0){
              k++;
              if (k==r){
                    a[i][j]=2;
                    break;
              }
           }
}

void raspechatka(int a[100][100],int n,int m)
{
    int i,j;

    printf("\n");
    printf("\n  Use arrows on your keyboard to move the matrix");
    printf("\n  Press Esc to close the game");
    printf("\n\n");

    for(i=0;i<n;i++)
    {
       printf("\n\n               ");
       for(j=0;j<m;j++)
           printf(" %d ",a[i][j]);
    }
}

int proverka(int a[100][100],int n,int m)
{
    int i,j,flag=0;

    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
           if (a[i][j]==0){
                flag=1;
                break;
           }

    return flag;
}

int dvijenie_vpravo(int a[100][100],int n, int m)
{
    int i,j,k,flag_dvijenia=0;

    for(i=0;i<n;i++)
    {
        j=(m-1);
        k=(m-1);
        do{
          if((a[i][j]==a[i][j-1])&&(a[i][j]!=0)){
             a[i][j]+=a[i][j-1];
             a[i][j-1]=0;
             flag_dvijenia=1;
             k=j;
             continue;
          }
          if((a[i][j]==0)&&(a[i][j-1]!=0)){
             a[i][j]=a[i][j-1];
             a[i][j-1]=0;
             flag_dvijenia=1;
             j=k;
             continue;
          }
          j--;
        }while(j!=0);
    }
    return flag_dvijenia;
}

int dvijenie_vlevo(int a[100][100],int n, int m)
{
    int i,j,k,flag_dvijenia=0;

    for(i=0;i<n;i++)
    {
        j=0;
        k=0;
        do{
          if((a[i][j]==a[i][j+1])&&(a[i][j]!=0)){
             a[i][j]+=a[i][j+1];
             a[i][j+1]=0;
             flag_dvijenia=1;
             k=j;
             continue;
          }
          if((a[i][j]==0)&&(a[i][j+1]!=0)){
             a[i][j]=a[i][j+1];
             a[i][j+1]=0;
             flag_dvijenia=1;
             j=k;
             continue;
          }
          j++;
        }while(j!=(m-1));
    }
    return flag_dvijenia;
}

int dvijenie_vniz(int a[100][100],int n, int m)
{
    int i,j,k,flag_dvijenia=0;

    for(j=0;j<m;j++)
    {
        i=(n-1);
        k=(n-1);
        do{
          if((a[i][j]==a[i-1][j])&&(a[i][j]!=0)){
             a[i][j]+=a[i-1][j];
             a[i-1][j]=0;
             flag_dvijenia=1;
             k=i;
             continue;
          }
          if((a[i][j]==0)&&(a[i-1][j]!=0)){
             a[i][j]=a[i-1][j];
             a[i-1][j]=0;
             flag_dvijenia=1;
             i=k;
             continue;
          }
          i--;
        }while(i!=0);
    }
    return flag_dvijenia;
}

int dvijenie_vverh(int a[100][100],int n, int m)
{
    int i,j,k,flag_dvijenia=0;

    for(j=0;j<m;j++)
    {
        i=0;
        k=0;
        do{
          if((a[i][j]==a[i+1][j])&&(a[i][j]!=0)){
             a[i][j]+=a[i+1][j];
             a[i+1][j]=0;
             flag_dvijenia=1;
             k=i;
             continue;
          }
          if((a[i][j]==0)&&(a[i+1][j]!=0)){
             a[i][j]=a[i+1][j];
             a[i+1][j]=0;
             flag_dvijenia=1;
             i=k;
             continue;
          }
          i++;
        }while(i!=(n-1));
    }
    return flag_dvijenia;
}

int main()
{
    int a[100][100],m,n,i,j,deistvie,flag_dvijenia;

    printf("\n\n   Select the length of the game box:");
    scanf("%d",&n);
    printf("   Select the width of the game box:");
    scanf("%d",&m);

    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
           a[i][j]=0;

    dobavlenie_elementa(a,n,m);

    do{
       system("cls");
       raspechatka(a,n,m);

       deistvie=getch();

       switch(deistvie) {

       case 80: flag_dvijenia=dvijenie_vniz(a,n,m);
                if (flag_dvijenia==1) dobavlenie_elementa(a,n,m);
           break;
       case 77: flag_dvijenia=dvijenie_vpravo(a,n,m);
                if (flag_dvijenia==1) dobavlenie_elementa(a,n,m);
           break;
       case 72: flag_dvijenia=dvijenie_vverh(a,n,m);
                if (flag_dvijenia==1) dobavlenie_elementa(a,n,m);
           break;
       case 75: flag_dvijenia=dvijenie_vlevo(a,n,m);
                if (flag_dvijenia==1) dobavlenie_elementa(a,n,m);
           break;
       default:
           break;
       }
    }while((proverka(a,n,m)==1)&&(deistvie!=27));

    if (proverka(a,n,m)==0){
            system("cls");
            printf("\n\n\n\n             YOU LOOSE !!!   \n\n\n ");
    }

    return 0;
}
