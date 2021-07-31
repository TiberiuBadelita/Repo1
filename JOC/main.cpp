#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <graphics.h>
#include <winbgim.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <MMSystem.h>

using namespace std;

#define MAX 50
struct inf
{
    FILE *fptr , *fcont;

    int T[15][15],jucator1=1,jucator2=1,nr=0,pozi=0, pozj=0 , cond1=0, cond2=0, col=0,col1=0,col2=0,col3=0,col4=0,col5=0,coln=0,col21=0,ok=1,okk=1,cont;

    char p1[MAX], p2[MAX],ch3;
} Game;

void tabla(int x , int y)
{


    initwindow(x,y+100,"CINCI IN LINIE");

    int nrc, nrl;

    nrc=x/10;
    nrl=y/10;

    for(int i=0; i<x; i+=nrc)
        for(int j=nrl; j<=y; j+=nrl)
        {
            setfillstyle(1,COLOR(255, 229, 229));
            bar(i,j-nrl,i+nrc,j);
        }

    setlinestyle(0,2,2);
    setcolor(BLACK);

    for(int i=0; i<x; i+=nrc)
        for(int j=nrl; j<=y; j+=nrl)
        {
            line(i,j,i+nrc,j);
            line(i,j-nrl,i,j);
        }

    for(int i=0; i<=x; i+=nrc)
        line(i,y-1,i+nrc,y-1);

    for(int j=0; j<=y; j+=nrl)
        line(x-1,j-nrl,x-1,j);



}

void tabla1(int x , int y)
{


    initwindow(x,y,"CINCI IN LINIE");

    int nrc, nrl;

    nrc=x/10;
    nrl=y/10;

    for(int i=0; i<x; i+=nrc)
        for(int j=nrl; j<=y; j+=nrl)
        {
            setfillstyle(1,COLOR(255, 229, 229));
            bar(i,j-nrl,i+nrc,j);
        }

    setlinestyle(0,2,2);
    setcolor(BLACK);

    for(int i=0; i<x; i+=nrc)
        for(int j=nrl; j<=y; j+=nrl)
        {
            line(i,j,i+nrc,j);
            line(i,j-nrl,i,j);
        }

    for(int i=0; i<=x; i+=nrc)
        line(i,y-1,i+nrc,y-1);

    for(int j=0; j<=y; j+=nrl)
        line(x-1,j-nrl,x-1,j);



}

int interx(int a , int x )
{
    int nrc , k=0;

    nrc=x/10;

    while(a>nrc)
    {
        a=a-nrc;
        k++;
    }

    return k;

}

int intery(int a , int x )
{
    int nrc , k=0;

    nrc=x/10;

    while(a>nrc)
    {
        a=a-nrc;
        k++;
    }

    if(a>nrc/2)
        return k;
    else
        return k-1;


}

void loading(int x , int y)
{

    initwindow(x,y,"CINCI IN LINIE");
    setbkcolor(COLOR(38, 72, 89));
    setfillstyle(1,COLOR(38, 72, 89));
    bar(0,0,x,y);
    rectangle(200,200,500,230);
    settextstyle(2,HORIZ_DIR,15);
    setcolor(COLOR(172, 83, 83));
    outtextxy(x/3-30,y/5,"CINCI IN LINIE");
    settextstyle(6,HORIZ_DIR,2);
    for(int i=0; i<300; i++)
    {
        setcolor(BLUE);
        line(200+i,200,200+i,230);
        outtextxy(300,250,"Loading...");
        delay(1);
    }

    closegraph();
}

void init()
{
    for(int i=0; i<=9; i++)
        for(int j=0; j<=9; j++)
            Game.T[i][j]=-1;

    Game.jucator1=1;
    Game.jucator2=1;
    Game.nr=0;
    Game.pozi=0;
    Game.cond1=0;
    Game.cond2=0;
    Game.col=0;
    Game.col1=0;
    Game.col2=0;
    Game.col3=0;
    Game.col4=0;
    Game.col5=0;
    Game.coln=0;
    Game.col21=0;
    Game.ok=1;
    Game.okk=1;
    Game.cont;


    srand((unsigned int)time(NULL));
    Game.pozi=rand()%5;
    Game.pozj=rand()%8;

}

int checkwin(int T[15][15],int p)
{
    int k=1,jos=1,sus=1,stanga=1,dreapta=1,l,d,ok,ok1,jos1=1,sus1=1,stanga1=1,dreapta1=1,digstjos=1,digstjos1=1,digstsus=1,digstsus1=1;

    if(p==1)
    {
        for(int j=0; j<=9; j++)
            for(int i=0; i<=9; i++)
                if(Game.T[i][j]==1)
                {

                    for(l=j+1; l<=9; l++)
                    {
                        if(jos==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }

                        if(Game.T[i][l]==1) jos++;
                        else if(jos==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }
                        else
                        {
                            jos=1;
                            break;
                        }
                    }

                    if(jos==5)
                    {
                        Game.jucator1=0;
                        return 1;
                    }
                    else jos=1;

                    for(l=j-1; l>=0; l--)
                    {
                        if(sus==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }
                        if(Game.T[i][l]==1) sus++;
                        else if(sus==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }
                        else
                        {
                            sus=1;
                            break;
                        }
                    }

                    if(sus==5)
                    {
                        Game.jucator1=0;
                        return 1;
                    }
                    else sus=1;

                    for(l=i-1; l>=0; l--)
                    {
                        if(stanga==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }

                        if(Game.T[l][j]==1) stanga++;
                        else if(stanga==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }
                        else
                        {
                            stanga=1;
                            break;
                        }
                    }


                    if(stanga==5)
                    {
                        Game.jucator1=0;
                        return 1;
                    }
                    else stanga=1;


                    for(l=i+1; l<=9; l++)
                    {
                        if(dreapta==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }

                        if(Game.T[l][j]==1) dreapta++;
                        else if(dreapta==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }
                        else
                        {
                            dreapta=1;
                            break;
                        }
                    }

                    if(dreapta==5)
                    {
                        Game.jucator1=0;
                        return 1;
                    }
                    else dreapta=1;


                    l=i+1;
                    d=j+1;
                    ok=1;
                    while(l<=9&&d<=9&&ok==1)
                    {
                        if(digstjos==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }

                        if(Game.T[l][d]==1) digstjos++;
                        else if(digstjos==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }
                        else
                        {
                            digstjos=1;
                            ok=0;
                        }

                        l++;
                        d++;
                    }


                    if(digstjos==5)
                    {
                        Game.jucator1=0;
                        return 1;
                    }
                    else digstjos=1;

                    l=i-1;
                    d=j+1;
                    ok=1;
                    while(l>=0&&d<=9&&ok==1)
                    {
                        if(digstsus==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }

                        if(Game.T[l][d]==1) digstsus++;
                        else if(digstsus==5)
                        {
                            Game.jucator1=0;
                            return 1;
                        }
                        else
                        {
                            digstsus=1;
                            ok=0;
                        }


                        l--;
                        d++;
                    }

                    if(digstsus==5)
                    {
                        Game.jucator1=0;
                        return 1;
                    }
                    else digstsus=1;
                }
    }
    else
    {
        for(int j=0; j<=9; j++)
            for(int i=0; i<=9; i++)
                if(Game.T[i][j]==0)
                {
                    for(l=j+1; l<=9; l++)
                    {
                        if(jos1==5)
                        {
                            Game.jucator2=0;
                            return 1;
                        }

                        if(Game.T[i][l]==0) jos1++;
                        else if(jos1==5)
                        {
                            Game.jucator2=0;
                            return 1;
                        }
                        else
                        {
                            jos1=1;
                            break;
                        }
                    }
                    if(jos1==5)
                    {
                        Game.jucator2=0;
                        return 1;

                    }
                    else jos1=1;
                    for(l=j-1; l>=0; l--)
                    {
                        if(sus1==5)
                        {
                            Game.jucator2=0;
                            return 1;

                        }
                        if(Game.T[i][l]==0) sus1++;
                        else if(sus1==5)
                        {
                            Game.jucator2=0;
                            return 1;
                        }
                        else
                        {
                            sus1=1;
                            break;
                        }

                    }
                    if(sus1==5)
                    {
                        Game.jucator2=0;
                        return 1;
                    }
                    else sus1=1;


                    for(l=i-1; l>=0; l--)
                    {
                        if(stanga1==5)
                        {
                            Game.jucator2=0;
                            return 1;

                        }
                        if(Game.T[l][j]==0) stanga1++;
                        else if(stanga1==5)
                        {
                            Game.jucator2=0;
                            return 1;

                        }
                        else
                        {
                            stanga1=1;
                            break;
                        }

                    }
                    if(stanga1==5)
                    {
                        Game.jucator2=0;
                        return 1;

                    }
                    else stanga1=1;
                    for(l=i+1; l<=9; l++)
                    {
                        if(dreapta1==5)
                        {
                            Game.jucator2=0;
                            return 1;

                        }
                        if(Game.T[l][j]==0) dreapta1++;
                        else if(dreapta1==5)
                        {
                            Game.jucator2=0;
                            return 1;
                        }
                        else
                        {
                            dreapta1=1;
                            break;
                        }

                    }
                    if(dreapta1==5)
                    {
                        Game.jucator2=0;
                        return 1;

                    }
                    else dreapta1=1;

                    l=i+1;
                    d=j+1;
                    ok1=1;
                    while(l<=9&&d<=9&&ok1==1)
                    {
                        if(digstjos1==5)
                        {
                            Game.jucator2=0;
                            return 1;

                        }
                        if(Game.T[l][d]==0) digstjos1++;
                        else if(digstjos1==5)
                        {
                            Game.jucator2=0;
                            return 1;

                        }
                        else
                        {
                            digstjos1=1;
                            ok1=0;
                        }
                        l++;
                        d++;
                    }
                    if(digstjos1==5)
                    {
                        Game.jucator2=0;
                        return 1 ;

                    }
                    else digstjos1=1;
                    l=i-1;
                    d=j+1;
                    ok1=1;
                    while(l>=0&&d<=9&&ok1==1)
                    {
                        if(digstsus1==5)
                        {
                            Game.jucator2=0;
                            return 1;
                        }
                        if(Game.T[l][d]==0) digstsus1++;
                        else if(digstsus1==5)
                        {
                            Game.jucator2=0;
                            return 1;

                        }
                        else
                        {
                            digstsus1=1;
                            ok1=0;
                        }
                        l--;
                        d++;

                    }
                    if(digstsus1==5)
                    {
                        Game.jucator2=0;
                        return 1;

                    }
                    else digstsus1=1;



                }


    }
    Game.nr++;
    return 0;


}

void afisA()
{

    if(Game.T[Game.pozi+1][Game.pozj]==-1)
        Game.pozi++;
    else if(Game.T[Game.pozi][Game.pozj+1]==-1)
        Game.pozj++;
    else if(Game.T[Game.pozi-1][Game.pozj]==-1)
        Game.pozi++;
    else if(Game.T[Game.pozi][Game.pozj-1]==-1)
        Game.pozj--;
    else if(Game.T[Game.pozi+1][Game.pozj+1]==-1)
    {
        Game.pozi++;
        Game.pozj++;
    }
    else if(Game.T[Game.pozi+1][Game.pozj-1]==-1)
    {
        Game.pozi++;
        Game.pozj--;
    }
    else if(Game.T[Game.pozi-1][Game.pozj-1]==-1)
    {
        Game.pozi--;
        Game.pozj--;
    }
    else if(Game.T[Game.pozi-1][Game.pozj+1]==-1)
    {
        Game.pozi--;
        Game.pozj++;
    }
    else
    {
        do
        {
            srand((unsigned int)time(NULL));
            Game.pozi=rand()%8;
            Game.pozj=rand()%8;
        }
        while(Game.T[Game.pozi][Game.pozj]!=-1);
    }



}

void afisOinc(int x , int y)
{
    delay(1000);

    if(Game.T[Game.pozi][Game.pozj]!=0)
        outtextxy((Game.pozi*(x/10))+x/40,(Game.pozj*(y/10))+y/50,"O");
    else
    {
        afisA();
        outtextxy((Game.pozi*(x/10))+x/40,(Game.pozj*(y/10))+y/50,"O");

    }

}

void afisOD(int mx , int my , int x , int y , int p)
{

    int k=0, ok=0;

    for(int i=0; i<=9; i++)
    {

        if(Game.T[i][Game.pozj]==1)
            k++;

        if(k==4)
            if(Game.T[i+1][Game.pozj]==-1 && ok==0)
            {
                delay(1000);
                outtextxy(((i+1)*(x/10))+x/40,(Game.pozj*(y/10))+y/50,"O");
                Game.T[i+1][Game.pozj]=1;
                Game.cond1=1;
                k=1;
                Game.pozi=i+1;
                ok=1;
            }
            else
            {
                k=0;
                for(int i=9; i>=0; i--)
                {

                    if(Game.T[i][Game.pozj]==1)
                        k++;

                    if(k==4)
                        if(Game.T[i-1][Game.pozj]==-1 && ok==0)
                        {
                            delay(1000);
                            outtextxy(((i-1)*(x/10))+x/40,(Game.pozj*(y/10))+y/50,"O");
                            Game.T[i-1][Game.pozj]=1;
                            Game.cond1=1;
                            k=1;
                            Game.pozi=i-1;
                            ok=1;
                        }

                }
            }

    }


    k=0;


    for(int i=0; i<=9; i++)
    {

        if(Game.T[Game.pozi][i]==1)
            k++;

        if(k==4)
            if(Game.T[Game.pozi][i+1]==-1 && ok==0)
            {
                delay(1000);
                outtextxy((Game.pozi*(x/10))+x/40,((i+1)*(y/10))+y/50,"O");
                Game.T[Game.pozi][i+1]=1;
                Game.cond1=1;
                Game.pozj=i+1;
                k=1;
                ok=1;
            }
            else
            {
                k=0;
                for(int i=9; i>=0; i--)
                {

                    if(Game.T[Game.pozi][i]==1)
                        k++;

                    if(k==4)
                        if(Game.T[Game.pozi][i-1]==-1 && ok==0)
                        {
                            delay(1000);
                            outtextxy((Game.pozi*(x/10))+x/40,((i-1)*(y/10))+y/50,"O");
                            Game.T[Game.pozi][i-1]=1;
                            Game.cond1=1;
                            k=1;
                            Game.pozj=i-1;
                            ok=1;
                        }

                }
            }
    }

    k=0;


    for(int i=0; i<=9; i++)
    {

        if(Game.T[i][intery(my,y)]==p)
            k++;

        if(k>=3)
            if(Game.T[i+1][intery(my,y)]==-1 && ok==0)
            {
                delay(1000);
                outtextxy(((i+1)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"O");
                Game.T[i+1][intery(my,y)]=1;
                Game.cond1=1;
                k=1;
                ok=1;
            }
            else
            {
                k=0;
                for(int i=9; i>=0; i--)
                {

                    if(Game.T[i][intery(my,y)]==p)
                        k++;

                    if(k>=3)
                        if(Game.T[i-1][intery(my,y)]==-1 && ok==0)
                        {
                            delay(1000);
                            outtextxy(((i-1)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"O");
                            Game.T[i-1][intery(my,y)]=1;
                            Game.cond1=1;
                            k=1;
                            ok=1;
                        }

                }
            }

    }


    k=0;


    for(int i=0; i<=9; i++)
    {

        if(Game.T[interx(mx,x)][i]==p)
            k++;

        if(k>=3)
            if(Game.T[interx(mx,x)][i+1]==-1 && ok==0)
            {
                delay(1000);
                outtextxy((interx(mx,x)*(x/10))+x/40,((i+1)*(y/10))+y/50,"O");
                Game.T[interx(mx,x)][i+1]=1;
                Game.cond1=1;
                k=1;
                ok=1;
            }
            else
            {
                k=0;
                for(int i=9; i>=0; i--)
                {

                    if(Game.T[interx(mx,x)][i]==p)
                        k++;

                    if(k>=3)
                        if(Game.T[interx(mx,x)][i-1]==-1 && ok==0)
                        {
                            delay(1000);
                            outtextxy((interx(mx,x)*(x/10))+x/40,((i-1)*(y/10))+y/50,"O");
                            Game.T[interx(mx,x)][i-1]=1;
                            Game.cond1=1;
                            k=1;
                            ok=1;
                        }

                }
            }
    }


}

void Rezultat(int x , int y)
{
    Game.fptr=fopen("istoric.txt","a");

    settextstyle(2,HORIZ_DIR,20);

    if(Game.jucator1==0)
    {
        setfillstyle(1,GREEN);
        bar(0,0,x/2,y/2+10);
        setbkcolor(GREEN);
        outtextxy((x/6)-(10*(strlen(Game.p2)-5)),y/7,Game.p2);
        rectangle(x/5-x/52,y/3+y/40,x/5+x/9+x/50,y/3+3*(y/40));
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(x/5-x/300,y/3+y/30,"RETRY");

        rectangle(x/5-x/52,y/3+y/20+y/20,x/5+x/9+x/50,y/3+3*(y/20));
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(x/5-x/300,y/3+y/9,"MENIU");

        if(Game.ok==0)
        {
            fwrite("0-1", 3, 1, Game.fptr);

            Game.fcont=fopen("contor.txt","r");

            fscanf(Game.fcont,"%d",&Game.cont);

            Game.cont++;

            fclose(Game.fcont);

            Game.fcont=fopen("contor.txt","w");

            fprintf(Game.fcont,"%d",Game.cont);

            fclose(Game.fcont);

            Game.ok=1;
        }
    }
    else if(Game.jucator2==0)
    {
        setfillstyle(1,RED);
        bar(0,0,x/2,y/2+10);
        setbkcolor(RED);
        outtextxy((x/6)-(10*(strlen(Game.p1)-5)),y/7,Game.p1);
        rectangle(x/5-x/52,y/3+y/40,x/5+x/9+x/50,y/3+3*(y/40));
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(x/5-x/300,y/3+y/30,"RETRY");

        rectangle(x/5-x/52,y/3+y/20+y/20,x/5+x/9+x/50,y/3+3*(y/20));
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(x/5-x/300,y/3+y/9,"MENIU");

        if(Game.ok==0)
        {
            fwrite("1-0", 3, 1, Game.fptr);

            Game.fcont=fopen("contor.txt","r");

            fscanf(Game.fcont,"%d",&Game.cont);

            Game.cont++;

            fclose(Game.fcont);

            Game.fcont=fopen("contor.txt","w");

            fprintf(Game.fcont,"%d",Game.cont);

            fclose(Game.fcont);

            Game.ok=1;
        }
    }
    else
        outtextxy(x/6,y/7,"Remiza");
}

void colorButton2(int x , int y)
{

    int mx=0,my=0;

    if(ismouseclick(WM_MOUSEMOVE)==1)
    {
        getmouseclick(WM_MOUSEMOVE,mx,my);

        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/40 && my<=y/3+3*(y/40))
        {
            if(Game.col==1)
            {
                setlinestyle(0,1,5);
                rectangle(x/5-x/52,y/3+y/40,x/5+x/9+x/50,y/3+3*(y/40));
                Game.col=0;
            }
        }
        else if(Game.col==0)
        {
            setlinestyle(0,0,1);
            Rezultat(x,y);
            delay(2);
            Game.col=1;
        }


        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/20+y/20 && my<=y/3+3*(y/20))
        {
            if(Game.col21==1)
            {
                setlinestyle(0,1,5);
                rectangle(x/5-x/52,y/3+y/20+y/20,x/5+x/9+x/50,y/3+3*(y/20));
                Game.col21=0;
            }
        }
        else if(Game.col21==0)
        {
            setlinestyle(0,0,1);
            Rezultat(x,y);
            delay(2);
            Game.col21=1;
        }



    }


}

void IstoricAf(int x , int y)
{
    char s1[MAX],s2[MAX],r[MAX],c;
    int i;

    closegraph();

    initwindow(x,y,"ISTORIC");

    setbkcolor(COLOR(38, 72, 89));

    setfillstyle(1,COLOR(38, 72, 89));
    bar(0,0,x,y);

    outtextxy(250,500,"Apasa ESC pentru a reveni in MENIU.");

    settextstyle(4,HORIZ_DIR,15);
    setcolor(WHITE);

    outtextxy(x/4,y/15,"ISTORIC MECIURI");

    settextstyle(3,HORIZ_DIR,3);

    Game.fptr=fopen("istoric.txt" , "r");

    Game.fcont=fopen("contor.txt" , "r");

    fscanf(Game.fcont,"%d",&Game.cont);

    i=15-Game.cont+1;

    do
    {

        while(!feof(Game.fptr))
            if(fscanf(Game.fptr,"%s",&s1)==1 && fscanf(Game.fptr,"%s",&s2)==1 && fscanf(Game.fptr,"%s",&r)==1 && (strcmp(r,"1-0")==0 || strcmp(r,"0-1")==0) && i<=15 && i>=1)
            {
                outtextxy(250,120+i*20,s1);
                outtextxy(350,120+i*20,s2);
                outtextxy(450,120+i*20,r);
                i++;
            }
            else
                i++;


        if(c==27)
            break;
        else
            c=getch();

    }
    while(1);


    fclose(Game.fptr);
}

void citesteNume(char s[MAX],int x, int y)
{
    int mx=0, my=0;
    strcpy(s,"");
    char s1[MAX];
    char t[2];
    char tasta;
    t[0]='\0';
    t[1]='\0';
    strcat(s,t);
    strcpy(s1,s);
    strcat(s1,"_");
    setcolor(BLUE);
    outtextxy(x,y,s1);
    do
    {
        tasta=getch();
        if (tasta==8)
            if (strlen(s)>0)
            {
                setcolor(COLOR(38, 72, 89));
                strcpy(s1,s);
                strcat(s1,"_");
                outtextxy(x,y,s1);
                s[strlen(s)-1]='\0';
                strcpy(s1,s);
                strcat(s1,"_");
                outtextxy(x,y,s1);
                setcolor(BLUE);
                outtextxy(x,y,s1);
            }
            else
                Beep(1000,100);
        else
        {
            t[0]=tasta;
            t[1]='\0';
            strcat(s,t);
            strcpy(s1,s);
            strcat(s1,"_");
            setcolor(BLUE);
            outtextxy(x,y,s1);
        }

    }
    while (tasta!=13);

    t[0]=tasta;
    t[1]='\0';
    strcat(s,t);
    strcpy(s1,s);
    strcat(s1,"_");
    setcolor(COLOR(38, 72, 89));
    outtextxy(x,y,s1);


}

void Numejucatori(int x , int y)
{
    int mx=0,my=0;
    FILE *frt;

    closegraph();
    initwindow(x,y,"Cinci pe Linie");
    settextstyle(6,HORIZ_DIR,2);
    setcolor(BLUE);
    setbkcolor(COLOR(38, 72, 89));
    setfillstyle(1,COLOR(38, 72, 89));
    bar(0,0,x,y);
    settextstyle(6,HORIZ_DIR,3);
    outtextxy(x/12 , y/12 , "JUCATOR 1:");
    outtextxy(x/2 , y/12 , "JUCATOR 2:");

    citesteNume(Game.p1,x/12,y/8);
    setcolor(BLUE);
    if(Game.p1[0]==13)
        strcpy(Game.p1,"NoName\n");
    outtextxy(x/12,y/8,Game.p1);

    citesteNume(Game.p2,x/2,y/8);
    setcolor(BLUE);
    if(Game.p2[0]==13)
        strcpy(Game.p2,"NoName\n");
    outtextxy(x/2,y/8,Game.p2);

    rectangle(x/3,y/10+(4*(y/9)),x/3+x/4+x/30,y/5+(5*(y/9)));
    settextstyle(6,HORIZ_DIR,5);
    outtextxy(x/3+x/40,y/2+y/9,"START");

    while(1)
    {
        if(ismouseclick(WM_LBUTTONDOWN)==1)
        {
            getmouseclick(WM_LBUTTONDOWN,mx,my);
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/10+(4*(y/9)) && my<=y/5+(5*(y/9)))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            break;
        }
    }

    Game.fptr=fopen("istoric.txt","a");


    fwrite("\n", sizeof(char) , 1, Game.fptr);
    fwrite("\n", sizeof(char) , 1, Game.fptr);
    fwrite(Game.p1, strlen(Game.p1), 1, Game.fptr);
    fwrite(Game.p2, strlen(Game.p2), 1, Game.fptr);

    Game.ok=0;
    frt=fopen("Numar jucator 1","a+");
    fprintf(frt,"%s",&Game.p1);
    fclose(frt);
    frt=fopen("Numar jucator 1","a+");
    fprintf(frt,"%s",&Game.p2);

    strcat(Game.p1,"-Wins");
    strcat(Game.p2,"-Wins");


}

void startPVP(int x , int y)
{
    closegraph();
    loading(x,y);

    tabla(x,y);

    init();

    POINT cursorPosition;
    int mx, my, ok=0 , p=0;
    FILE *frt;

    settextstyle(2,HORIZ_DIR,20);
    setcolor(WHITE);
    outtextxy(x/4,y+10,"Muta:");
    setcolor(RED);
    outtextxy(x/4+200,y+10,"X");

    while(1)
    {
        GetCursorPos(&cursorPosition);

        mx=cursorPosition.x;
        my=cursorPosition.y;

        if(ismouseclick(WM_LBUTTONDOWN)==1 )
        {
            ok=1;

            if(Game.T[interx(mx,x)][intery(my,y)]==-1)
                Game.T[interx(mx,x)][intery(my,y)]=p;
            else if(Game.T[interx(mx,x)][intery(my,y)]==1)
                p=1;
            else
                p=0;

            clearmouseclick(WM_LBUTTONDOWN);

            if(checkwin(Game.T,p))
            {
                if(p==1)
                {
                    setcolor(GREEN);
                    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                    outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"O");
                    break;
                }
                else
                {
                    setcolor(RED);
                    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                    outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");
                    break;
                }
            }
            else if(Game.nr==100)
            {
                closegraph();
                initwindow(x/2,y/2);
                settextstyle(2,HORIZ_DIR,20);
                outtextxy(x/6,y/6,"Remiza");
                getch();
                break;
            }

        }

        if(ismouseclick(WM_LBUTTONUP)==1)
        {
            ok=0;
            clearmouseclick(WM_LBUTTONUP);

            if(p==0)
            {
                p=1;
                settextstyle(2,HORIZ_DIR,20);
                setcolor(WHITE);
                setfillstyle(1,BLACK);
                setbkcolor(BLACK);
                bar(0,y+1,x,y+100);
                outtextxy(x/4,y+10,"Muta:");
                setcolor(GREEN);
                outtextxy(x/4+200,y+10,"O");

            }
            else
            {
                p=0;
                settextstyle(2,HORIZ_DIR,20);
                setcolor(WHITE);
                setfillstyle(1,BLACK);
                setbkcolor(BLACK);
                bar(0,y+1,x,y+100);
                outtextxy(x/4,y+10,"Muta:");
                setcolor(RED);
                outtextxy(x/4+200,y+10,"X");

            }

        }


        setbkcolor(COLOR(255, 229, 229));

        if(ok==1 && p==0)
        {
            setcolor(RED);
            settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
            outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");

            PlaySound(TEXT("Muzica piesa2.wav"),NULL,SND_SYNC);
            frt=fopen("Resume","a+");
            fprintf(frt,"%d%d%c",interx(mx,x),intery(my,y),'x');
            fclose(frt);
            frt=fopen("Raspuns","a+");
            fprintf(frt,"%d",1);
            fclose(frt);

        }
        else if(p==1 && ok==1)
        {
            setcolor(GREEN);
            settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
            outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"O");
            PlaySound(TEXT("Muzica piesa2.wav"),NULL,SND_SYNC);
            frt=fopen("Resume","a+");
            fprintf(frt,"%d%d%c",interx(mx,x),intery(my,y),'o');
            fclose(frt);
            frt=fopen("Raspuns","a+");
            fprintf(frt,"%d",1);
            fclose(frt);


        }



    }
    frt=fopen("Resume","w+");
    fclose(frt);
    frt=fopen("Raspuns","w+");
    fclose(frt);
    initwindow(x/2,y/2+10,"REZULTAT",x);
    Rezultat(x,y);
    Game.ok=0;
    PlaySound(TEXT("Win sound1.wav"),NULL,SND_SYNC);
    while(1)
    {

        if(ismouseclick(WM_LBUTTONDOWN)==1)
        {
            getmouseclick(WM_LBUTTONDOWN,mx,my);
            clearmouseclick(WM_LBUTTONDOWN);
        }

        colorButton2(x,y);

        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/40 && my<=y/3+3*(y/40))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            closegraph();
            Numejucatori(x,y);
            startPVP(x,y);
            break;

        }

        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/20+y/20 && my<=y/3+3*(y/20))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            closegraph();
            break;

        }




    }


}

void startPVEe(int x , int y)
{
    closegraph();
    loading(x,y);

    tabla1(x,y);

    init();

    POINT cursorPosition;
    int mx, my, ok=0 , p=0;


    while(1)
    {
        GetCursorPos(&cursorPosition);

        mx=cursorPosition.x;
        my=cursorPosition.y;

        if(ismouseclick(WM_LBUTTONDOWN)==1)
        {
            ok=1;
            Game.T[interx(mx,x)][intery(my,y)]=p;
            if(Game.T[Game.pozi][Game.pozj]!=p)
                Game.T[Game.pozi][Game.pozj]=1;


            if(checkwin(Game.T,1))
            {
                setcolor(GREEN);
                outtextxy((Game.pozi*(x/10))+x/40,(Game.pozj*(y/10))+y/50,"O");

                break;
            }
            else if(checkwin(Game.T,0))
            {
                setcolor(RED);
                outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");
                break;
            }


            else if(Game.nr==100)
            {
                closegraph();
                initwindow(x/2,y/2);
                settextstyle(2,HORIZ_DIR,20);
                outtextxy(x/6,y/6,"Remiza");
                getch();
                break;
            }


            clearmouseclick(WM_LBUTTONDOWN);

        }

        if(ismouseclick(WM_LBUTTONUP)==1)
        {
            ok=0;
            clearmouseclick(WM_LBUTTONUP);

        }


        setbkcolor(COLOR(255, 229, 229));

        if(ok==1 && p==0)
        {
            setcolor(RED);
            settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
            outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");
            PlaySound(TEXT("Muzica piesa2.wav"),NULL,SND_SYNC);

            setcolor(GREEN);

            do
            {
                srand((unsigned int)time(NULL));
                Game.pozi=rand()%8;
                Game.pozj=rand()%8;
            }
            while(Game.T[Game.pozi][Game.pozj]!=-1);

            afisOinc(x,y);


        }



    }

    initwindow(x/2,y/2+10,"REZULTAT",x);
    strcpy(Game.p1,"You-Won");
    strcpy(Game.p2,"AI-Won");
    Rezultat(x,y);
    PlaySound(TEXT("Win sound1.wav"),NULL,SND_SYNC);

    while(1)
    {

        if(ismouseclick(WM_LBUTTONDOWN)==1)
        {
            getmouseclick(WM_LBUTTONDOWN,mx,my);
            clearmouseclick(WM_LBUTTONDOWN);
        }

        colorButton2(x,y);

        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/40 && my<=y/3+3*(y/40))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            closegraph();
            startPVEe(x,y);
            break;

        }

        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/20+y/20 && my<=y/3+3*(y/20))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            closegraph();
            break;

        }


    }


}

void startPVEn(int x , int y)
{
    closegraph();
    loading(x,y);

    tabla1(x,y);

    init();

    POINT cursorPosition;
    int mx, my, ok=0;


    while(1)
    {
        GetCursorPos(&cursorPosition);

        mx=cursorPosition.x;
        my=cursorPosition.y;

        if(ismouseclick(WM_LBUTTONDOWN)==1)
        {
            ok=1;
            Game.T[interx(mx,x)][intery(my,y)]=0;

            if(checkwin(Game.T,1))
            {
                setcolor(GREEN);
                outtextxy((Game.pozi*(x/10))+x/40,(Game.pozj*(y/10))+y/50,"O");

                break;
            }
            else if(checkwin(Game.T,0))
            {
                setcolor(RED);
                outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");
                break;
            }


            else if(Game.nr==100)
            {
                closegraph();
                initwindow(x/2,y/2);
                settextstyle(2,HORIZ_DIR,20);
                outtextxy(x/6,y/6,"Remiza");
                getch();
                break;
            }
            clearmouseclick(WM_LBUTTONDOWN);



        }

        if(ismouseclick(WM_LBUTTONUP)==1)
        {
            ok=0;
            clearmouseclick(WM_LBUTTONUP);

        }


        setbkcolor(COLOR(255, 229, 229));

        if(ok==1)
        {
            setcolor(RED);
            settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
            outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");
            PlaySound(TEXT("Muzica piesa2.wav"),NULL,SND_SYNC);

            setcolor(GREEN);

            Game.cond1=0;
            afisOD(mx,my,x,y,0);

            if(Game.cond1==0)
            {
                afisA();
                afisOinc(x,y);
                Game.cond1=1;
            }

            if(Game.T[Game.pozi][Game.pozj]==-1)
                Game.T[Game.pozi][Game.pozj]=1;



        }






    }

    initwindow(x/2,y/2+10,"REZULTAT",x);
    strcpy(Game.p1,"You-Won");
    strcpy(Game.p2,"AI-Won");
    Rezultat(x,y);
    PlaySound(TEXT("Win sound1.wav"),NULL,SND_SYNC);

    while(1)
    {

        if(ismouseclick(WM_LBUTTONDOWN)==1)
        {
            getmouseclick(WM_LBUTTONDOWN,mx,my);
            clearmouseclick(WM_LBUTTONDOWN);
        }

        colorButton2(x,y);

        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/40 && my<=y/3+3*(y/40))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            closegraph();
            startPVEn(x,y);
            break;

        }

        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/20+y/20 && my<=y/3+3*(y/20))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            closegraph();
            break;

        }


    }


}

void MENIU(int x , int y)
{
    setbkcolor(COLOR(38, 72, 89));

    setfillstyle(1,COLOR(38, 72, 89));
    bar(0,0,x,y);

    settextstyle(2,HORIZ_DIR,15);
    setcolor(COLOR(172, 83, 83));
    outtextxy(x/3,y/5,"CINCI IN LINIE");

    setcolor(WHITE);
    rectangle(x/3,y/5+y/9,x/3+x/4+x/30,y/5+2*(y/9));

    rectangle(x/3,y/5+(3*(y/9)),x/3+x/4+x/30,y/5+(4*(y/9)));

    rectangle(x/3,y/5+(5*(y/9)),x/3+x/4+x/30,y/5+(6*(y/9)));

    settextstyle(6,HORIZ_DIR,2);
    setcolor(WHITE);
    outtextxy(x/3+x/40,y/5+y/7,"START GAME");

    outtextxy(x/3+x/60,y/5+3*(y/8.1),"REGULAMENT");

    outtextxy(x/3+(x/10.5),y/5+3*(y/5.1),"EXIT");

}

void MODdeJOC(int x,int y)
{


    setbkcolor(COLOR(38, 72, 89));
    setfillstyle(1,COLOR(38, 72, 89));
    bar(0,0,x,y);

    settextstyle(2,HORIZ_DIR,17);
    outtextxy(x/4,y/15,"MOD DE JOC");

    rectangle(x/6,y/10+y/9,x/3+x/4+x/30+x/6,y/5+3*(y/9));
    rectangle(x/3+x/50,4*(y/10),x/3+x/4+x/50,5*(y/10));
    rectangle(x/6,y/5+(4*(y/9)),x/3+x/4+x/30+x/6,y/5+(6*(y/10)));

    settextstyle(6,HORIZ_DIR,4);
    setcolor(WHITE);
    outtextxy(x/5,y/4+y/30," PLAYER VS PLAYER");
    outtextxy(x/3+x/25,6*(y/14),"ISTORIC");
    outtextxy(x/5,y/2+(2*y/10)," PLAYER VS BOT");

    settextstyle(6,HORIZ_DIR,3);
    rectangle(x/3+x/30,y/5+(5*(y/8))+y/30,x/3+x/4,y/5+(6*(y/8)));
    outtextxy(x/4+(x/6),y/4+3*(y/4.7),"BACK");


}

void colorButton(int x , int y)
{
    int mx=0,my=0;

    if(ismouseclick(WM_MOUSEMOVE)==1)
    {
        getmouseclick(WM_MOUSEMOVE,mx,my);

        if(mx>=x/3 && mx<=x/3+x/4+x/30 && my>=y/5+y/9 && my<=y/5+2*(y/9))
        {
            if(Game.col==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/3,y/5+y/9,x/3+x/4+x/30,y/5+2*(y/9));
                Game.col=0;
            }
        }
        else if(Game.col==0)
        {
            setlinestyle(0,0,1);
            MENIU(x,y);
            delay(2);
            Game.col=1;
        }



        if(mx>=x/3&&mx<=x/3+x/4+x/30&&my>=y/5+(3*(y/9)-10)&&my<=y/5+(4*(y/9)))
        {
            if(Game.col1==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/3,y/5+(3*(y/9)),x/3+x/4+x/30,y/5+(4*(y/9)));
                Game.col1=0;
            }
        }
        else if(Game.col1==0)
        {
            setlinestyle(0,0,1);
            MENIU(x,y);
            Game.col1=1;
        }





        if(mx>=x/3&&mx<=x/3+x/4+x/30&&my>=y/5+(5*(y/9))&&my<=y/5+(6*(y/9)))
        {
            if(Game.col2==0)
            {
                setlinestyle(0,1,10);
                rectangle(x/3,y/5+(5*(y/9)),x/3+x/4+x/30,y/5+(6*(y/9)));
                Game.col2=1;
            }
        }
        else if(Game.col2==1)
        {
            setlinestyle(0,0,1);
            MENIU(x,y);
            Game.col2=0;
        }

    }



}

void colorButton1(int x , int y)
{
    int mx=0,my=0;

    if(ismouseclick(WM_MOUSEMOVE)==1)
    {
        getmouseclick(WM_MOUSEMOVE,mx,my);

        if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/10+y/9 && my<=y/5+3*(y/9) && !(mx>=x/3+x/50 && mx<=x/3+x/4+x/50 && my>=4*(y/10) && my<=5*(y/10)))
        {
            if(Game.col==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/6,y/10+y/9,x/3+x/4+x/30+x/6,y/5+3*(y/9));
                Game.col=0;
            }
        }
        else if(Game.col==0)
        {
            setlinestyle(0,0,1);
            MODdeJOC(x,y);
            delay(2);
            Game.col=1;
        }



        if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/5+(4*(y/9)) && my<=y/5+(6*(y/10)))
        {
            if(Game.col1==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/6,y/5+(4*(y/9)),x/3+x/4+x/30+x/6,y/5+(6*(y/10)));
                Game.col1=0;
            }
        }
        else if(Game.col1==0)
        {
            setlinestyle(0,0,1);
            MODdeJOC(x,y);
            Game.col1=1;
        }

        if(mx>=x/3+x/30 && mx<=x/3+x/4 && my>=y/5+(5*(y/8))+y/30 && my<=y/5+(6*(y/8)))
        {
            if(Game.col2==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/3+x/30,y/5+(5*(y/8))+y/30,x/3+x/4,y/5+(6*(y/8)));
                Game.col2=0;
            }
        }
        else if(Game.col2==0)
        {
            setlinestyle(0,0,1);
            MODdeJOC(x,y);
            Game.col2=1;
        }


        if(mx>=x/3+x/50 && mx<=x/3+x/4+x/50 && my>=4*(y/10) && my<=5*(y/10))
        {
            if(Game.coln==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/3+x/50,4*(y/10),x/3+x/4+x/50,5*(y/10));
                Game.coln=0;
            }
        }
        else if(Game.coln==0)
        {
            setlinestyle(0,0,1);
            MODdeJOC(x,y);
            delay(2);
            Game.coln=1;
        }


    }



}

void Regulament(int x,int y)
{

    setbkcolor(COLOR(38, 72, 89));
    setfillstyle(1,COLOR(38, 72, 89));
    bar(0,0,x,y);
    settextstyle(6,HORIZ_DIR,2);
    rectangle(x/200,y/60,x/5,y/12);
    outtextxy(x/20,y/30,"BACK");
    outtextxy(x/3.2,y/15,"CINCI IN LINIE");
    outtextxy(x/2.711864406779661,y/7.5,"-REGULI-");
    outtextxy(1,y/5,"Pozitia de start si obiectul jocului:");
    outtextxy(1,y/3.75,"Este un joc foarte popular,deoarece regulile sunt foarte simple si");
    outtextxy(1,y/3.33,"jocul ofera distractie un timp indelungat.Obiectul jocului este sa a-");
    outtextxy(1,y/3,"sezi cinci piese pe un rand pe verticala,orizontala sau diagonala.");
    outtextxy(1,y/2.72,"Se joaca pe o tabla de 10x10 careuri si incepe cu tabla goala.");
    outtextxy(1,y/2.30,"Modul de asezare a pieselor:");
    outtextxy(1,y/2,"Fiecare jucator aseaza o piesa pe rand,regula este de sus în jos");
    outtextxy(1,y/1.7647,"Sfarsitul jocului");
    outtextxy(1,y/1.57,"Jocul se termina daca:");
    outtextxy(1,y/1.42,"-unul dintre jucatori aseaza 5 sau mai multe piese pe un rand verti-");
    outtextxy(1,y/1.36,"cal,orizontal sau in diagonala,acesta castiga jocul.");
    outtextxy(1,y/1.25,"-daca toate careurile au fost ocupate de piese si nici unul dintre ju-");
    outtextxy(1,y/1.2,"catori nu are 5 pe linie, jocul se termina cu remiza.");

}

void colorButton3(int x,int y)
{
    int mx=0,my=0;

    if(ismouseclick(WM_MOUSEMOVE)==1)
    {
        getmouseclick(WM_MOUSEMOVE,mx,my);

        if(mx>=x/200 && mx<=x/5 && my>=y/60 && my<=y/12)
        {
            if(Game.col5==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/200,y/60,x/5,y/12);
                Game.col5=0;
            }
        }
        else if(Game.col5==0)
        {
            setlinestyle(0,0,1);
            Regulament(x,y);
            Game.col5=1;
        }

    }

}

bool fisier()
{
    char ch;
    FILE*frt;
    frt=fopen("Raspuns","r+");
    ch=getc(frt);
    if(ch==EOF) return false ;
    else return true ;
    fclose(frt);


}

void Resume(int x,int y)
{
    tabla(x,y);
    FILE*trf;
    char ch1,ch2,k;
    trf=fopen("Resume","a+");
    while(1)
    {
        ch1=getc(trf);
        ch2=getc(trf);
        Game.ch3=getc(trf);
        if(Game.ch3==EOF)
            break;
        else k=Game.ch3;
        if(Game.ch3=='x')
        {
            setbkcolor(COLOR(255, 229, 229));
            settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
            setcolor(RED);
            outtextxy(((ch1-'0')*(x/10))+x/40,((ch2-'0')*(y/10))+y/50,"X");
            Game.T[ch1-'0'][ch2-'0']=0;
        }
        else
        {
            setbkcolor(COLOR(255, 229, 229));
            settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
            setcolor(GREEN);
            outtextxy(((ch1-'0')*(x/10))+x/40,((ch2-'0')*(y/10))+y/50,"O");
            Game.T[ch1-'0'][ch2-'0']=1;
        }

    }
    fclose(trf);
    Game.ch3=k;
}

void Alegere(int x,int y)
{
    setbkcolor(COLOR(38, 72, 89));
    setfillstyle(1,COLOR(38, 72, 89));
    settextstyle(6,HORIZ_DIR,2);
    bar(0,0,x,y);
    outtextxy(250,150,"Doresti sa reiei jocul anterior?");
    rectangle(250,250,350,200);
    outtextxy(284,215,"Da");
    rectangle(515,249,610,199);
    outtextxy(543,212,"Nu");

}

void RezultatR(int x , int y)
{
    char s1[100],s2[100];
    FILE *frt;
    Game.fptr=fopen("istoric.txt","a");
    frt=fopen("Numar jucator 1","a+");
    fscanf(frt,"%s",s1);
    fscanf(frt,"%s",s2);
    fclose(frt);
    strcat(s1,"-Win");
    strcat(s2,"-Win");
    settextstyle(2,HORIZ_DIR,20);

    if(Game.jucator1==0)
    {

        setfillstyle(1,GREEN);
        bar(0,0,x/2,y/2+10);
        setbkcolor(GREEN);
        outtextxy((x/6)-(10*(strlen(Game.p2)-5))-50,y/7,s2);
        rectangle(x/5-x/52,y/3+y/40,x/5+x/9+x/50,y/3+3*(y/40));
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(x/5-x/300,y/3+y/30,"RETRY");

        rectangle(x/5-x/52,y/3+y/20+y/20,x/5+x/9+x/50,y/3+3*(y/20));
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(x/5-x/300,y/3+y/9,"MENIU");

        if(Game.okk==0)
        {
            fwrite("0-1", 3, 1, Game.fptr);

            Game.fcont=fopen("contor.txt","r");

            fscanf(Game.fcont,"%d",&Game.cont);

            Game.cont++;

            fclose(Game.fcont);

            Game.fcont=fopen("contor.txt","w");

            fprintf(Game.fcont,"%d",Game.cont);

            fclose(Game.fcont);

            Game.okk=1;
        }
    }
    else if(Game.jucator2==0)
    {
        setfillstyle(1,RED);
        bar(0,0,x/2,y/2+10);
        setbkcolor(RED);
        outtextxy((x/6)-(10*(strlen(Game.p1)-5))-50,y/7,s1);
        rectangle(x/5-x/52,y/3+y/40,x/5+x/9+x/50,y/3+3*(y/40));
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(x/5-x/300,y/3+y/30,"RETRY");

        rectangle(x/5-x/52,y/3+y/20+y/20,x/5+x/9+x/50,y/3+3*(y/20));
        settextstyle(6,HORIZ_DIR,2);
        outtextxy(x/5-x/300,y/3+y/9,"MENIU");

        if(Game.okk==0)
        {
            fwrite("1-0", 3, 1, Game.fptr);

            Game.fcont=fopen("contor.txt","r");

            fscanf(Game.fcont,"%d",&Game.cont);

            Game.cont++;

            fclose(Game.fcont);

            Game.fcont=fopen("contor.txt","w");

            fprintf(Game.fcont,"%d",Game.cont);

            fclose(Game.fcont);

            Game.okk=1;
        }
    }
    else
        outtextxy(x/6,y/7,"Remiza");
}

void colorButton21(int x , int y)
{

    int mx=0,my=0;

    if(ismouseclick(WM_MOUSEMOVE)==1)
    {
        getmouseclick(WM_MOUSEMOVE,mx,my);

        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/40 && my<=y/3+3*(y/40))
        {
            if(Game.col==1)
            {
                setlinestyle(0,1,5);
                rectangle(x/5-x/52,y/3+y/40,x/5+x/9+x/50,y/3+3*(y/40));
                Game.col=0;
            }
        }
        else if(Game.col==0)
        {
            setlinestyle(0,0,1);
            RezultatR(x,y);
            delay(2);
            Game.col=1;
        }


        if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/20+y/20 && my<=y/3+3*(y/20))
        {
            if(Game.col21==1)
            {
                setlinestyle(0,1,5);
                rectangle(x/5-x/52,y/3+y/20+y/20,x/5+x/9+x/50,y/3+3*(y/20));
                Game.col21=0;
            }
        }
        else if(Game.col21==0)
        {
            setlinestyle(0,0,1);
            RezultatR(x,y);
            delay(2);
            Game.col21=1;
        }



    }


}

void startPVPR(int x,int y)
{
    init();
    closegraph();
    loading(x,y);

    Resume(x,y);
    POINT cursorPosition;
    int mx, my, ok=0 , p=0;
    FILE *frt;
    if(Game.ch3=='x')
    {
        settextstyle(2,HORIZ_DIR,20);
        setcolor(WHITE);
        setfillstyle(1,BLACK);
        setbkcolor(BLACK);
        outtextxy(x/4,y+10,"Muta:");
        setcolor(GREEN);
        outtextxy(x/4+200,y+10,"O");
        p=1;
        while(1)
        {
            GetCursorPos(&cursorPosition);

            mx=cursorPosition.x;
            my=cursorPosition.y;

            if(ismouseclick(WM_LBUTTONDOWN)==1)
            {
                ok=1;
                Game.T[interx(mx,x)][intery(my,y)]=p;
                clearmouseclick(WM_LBUTTONDOWN);

                if(checkwin(Game.T,p))
                {
                    if(p==1)
                    {
                        setcolor(GREEN);
                        settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                        outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"O");
                        break;
                    }
                    else
                    {
                        setcolor(RED);
                        settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                        outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");
                        break;
                    }
                }
                else if(Game.nr==100)
                {
                    closegraph();
                    initwindow(x/2,y/2);
                    settextstyle(2,HORIZ_DIR,20);
                    outtextxy(x/6,y/6,"Remiza");
                    getch();
                    break;
                }

            }

            if(ismouseclick(WM_LBUTTONUP)==1)
            {
                ok=0;
                clearmouseclick(WM_LBUTTONUP);

                if(p==0)
                {
                    p=1;
                    settextstyle(2,HORIZ_DIR,20);
                    setcolor(WHITE);
                    setfillstyle(1,BLACK);
                    setbkcolor(BLACK);
                    bar(0,y+1,x,y+100);
                    outtextxy(x/4,y+10,"Muta:");
                    setcolor(GREEN);
                    outtextxy(x/4+200,y+10,"O");

                }
                else
                {
                    p=0;
                    settextstyle(2,HORIZ_DIR,20);
                    setcolor(WHITE);
                    setfillstyle(1,BLACK);
                    setbkcolor(BLACK);
                    bar(0,y+1,x,y+100);
                    outtextxy(x/4,y+10,"Muta:");
                    setcolor(RED);
                    outtextxy(x/4+200,y+10,"X");

                }

            }


            setbkcolor(COLOR(255, 229, 229));

            if(ok==1 && p==0)
            {
                setcolor(RED);
                settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");

                PlaySound(TEXT("Muzica piesa2.wav"),NULL,SND_SYNC);
                frt=fopen("Resume","a+");
                fprintf(frt,"%d%d%c",interx(mx,x),intery(my,y),'x');
                fclose(frt);
                frt=fopen("Raspuns","a+");
                fprintf(frt,"%d",1);
                fclose(frt);

            }
            else if(p==1 && ok==1)
            {
                setcolor(GREEN);
                settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"O");
                PlaySound(TEXT("Muzica piesa2.wav"),NULL,SND_SYNC);
                frt=fopen("Resume","a+");
                fprintf(frt,"%d%d%c",interx(mx,x),intery(my,y),'o');
                fclose(frt);
                frt=fopen("Raspuns","a+");
                fprintf(frt,"%d",1);
                fclose(frt);


            }



        }
        frt=fopen("Resume","w+");
        fclose(frt);
        frt=fopen("Raspuns","w+");
        fclose(frt);
        initwindow(x/2,y/2+10,"REZULTAT",x);
        Game.okk=0;
        RezultatR(x,y);
        frt=fopen("Numar jucator 1","+w");
        fclose(frt);
        PlaySound(TEXT("Win sound1.wav"),NULL,SND_SYNC);

        while(1)
        {

            if(ismouseclick(WM_LBUTTONDOWN)==1)
            {
                getmouseclick(WM_LBUTTONDOWN,mx,my);
                clearmouseclick(WM_LBUTTONDOWN);
            }

            colorButton21(x,y);

            if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/40 && my<=y/3+3*(y/40))
            {
                PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                closegraph();
                Numejucatori(x,y);
                startPVP(x,y);
                break;

            }

            if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/20+y/20 && my<=y/3+3*(y/20))
            {
                PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                closegraph();
                break;

            }




        }


    }

    else
    {
        setbkcolor(BLACK);
        settextstyle(2,HORIZ_DIR,20);
        setcolor(WHITE);
        setfillstyle(1,BLACK);
        outtextxy(x/4,y+10,"Muta:");
        setcolor(RED);
        outtextxy(x/4+200,y+10,"X");

        while(1)
        {
            GetCursorPos(&cursorPosition);

            mx=cursorPosition.x;
            my=cursorPosition.y;

            if(ismouseclick(WM_LBUTTONDOWN)==1)
            {
                ok=1;
                Game.T[interx(mx,x)][intery(my,y)]=p;
                clearmouseclick(WM_LBUTTONDOWN);

                if(checkwin(Game.T,p))
                {
                    if(p==1)
                    {
                        setcolor(GREEN);
                        settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                        outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"O");
                        break;
                    }
                    else
                    {
                        setcolor(RED);
                        settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                        outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");
                        break;
                    }
                }
                else if(Game.nr==100)
                {
                    closegraph();
                    initwindow(x/2,y/2);
                    settextstyle(2,HORIZ_DIR,20);
                    outtextxy(x/6,y/6,"Remiza");
                    getch();
                    break;
                }

            }

            if(ismouseclick(WM_LBUTTONUP)==1)
            {
                ok=0;
                clearmouseclick(WM_LBUTTONUP);

                if(p==0)
                {
                    p=1;
                    settextstyle(2,HORIZ_DIR,20);
                    setcolor(WHITE);
                    setfillstyle(1,BLACK);
                    setbkcolor(BLACK);
                    bar(0,y+1,x,y+100);
                    outtextxy(x/4,y+10,"Muta:");
                    setcolor(GREEN);
                    outtextxy(x/4+200,y+10,"O");

                }
                else
                {
                    p=0;
                    settextstyle(2,HORIZ_DIR,20);
                    setcolor(WHITE);
                    setfillstyle(1,BLACK);
                    setbkcolor(BLACK);
                    bar(0,y+1,x,y+100);
                    outtextxy(x/4,y+10,"Muta:");
                    setcolor(RED);
                    outtextxy(x/4+200,y+10,"X");

                }

            }


            setbkcolor(COLOR(255, 229, 229));

            if(ok==1 && p==0)
            {
                setcolor(RED);
                settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"X");

                PlaySound(TEXT("Muzica piesa2.wav"),NULL,SND_SYNC);
                frt=fopen("Resume","a+");
                fprintf(frt,"%d%d%c",interx(mx,x),intery(my,y),'x');
                fclose(frt);
                frt=fopen("Raspuns","a+");
                fprintf(frt,"%d",1);
                fclose(frt);

            }
            else if(p==1 && ok==1)
            {
                setcolor(GREEN);
                settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
                outtextxy((interx(mx,x)*(x/10))+x/40,(intery(my,y)*(y/10))+y/50,"O");
                PlaySound(TEXT("Muzica piesa2.wav"),NULL,SND_SYNC);
                frt=fopen("Resume","a+");
                fprintf(frt,"%d%d%c",interx(mx,x),intery(my,y),'o');
                fclose(frt);
                frt=fopen("Raspuns","a+");
                fprintf(frt,"%d",1);
                fclose(frt);


            }



        }
        frt=fopen("Resume","w+");
        fclose(frt);
        frt=fopen("Raspuns","w+");
        fclose(frt);
        initwindow(x/2,y/2+10,"REZULTAT",x);
        Game.okk=0;
        RezultatR(x,y);
        frt=fopen("Numar jucator 1","w+");
        fclose(frt);
        PlaySound(TEXT("Win sound1.wav"),NULL,SND_SYNC);

        while(1)
        {

            if(ismouseclick(WM_LBUTTONDOWN)==1)
            {
                getmouseclick(WM_LBUTTONDOWN,mx,my);
                clearmouseclick(WM_LBUTTONDOWN);
            }

            colorButton21(x,y);

            if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/40 && my<=y/3+3*(y/40))
            {
                PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                closegraph();
                Numejucatori(x,y);
                startPVP(x,y);
                break;

            }

            if(mx>=x/5-x/52 && mx<=x/5+x/9+x/50 && my>=y/3+y/20+y/20 && my<=y/3+3*(y/20))
            {
                PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                closegraph();
                break;

            }




        }


    }





}

void MeniuPVE(int x, int y)
{
    setbkcolor(COLOR(38, 72, 89));
    setfillstyle(1,COLOR(38, 72, 89));
    bar(0,0,x,y);

    settextstyle(2,HORIZ_DIR,17);
    outtextxy(x/4,y/15,"DIFICULTATE");

    rectangle(x/6,y/10+y/9,x/3+x/4+x/30+x/6,y/5+2*(y/9));
    rectangle(x/6,y/10+(4*(y/9)),x/3+x/4+x/30+x/6,y/5+(5*(y/9)));

    settextstyle(6,HORIZ_DIR,4);
    setcolor(WHITE);
    outtextxy(x/5,y/4+y/30," EASY");
    outtextxy(x/5,y/2+y/9," MEDIUM");

    settextstyle(6,HORIZ_DIR,3);
    rectangle(x/3+x/30,y/5+(5*(y/8))+y/30,x/3+x/4,y/5+(6*(y/8)));
    outtextxy(x/4+(x/6.5),y/4+3*(y/4.7),"MENIU");

}

void colorButton4(int x , int y)
{
    int mx=0,my=0;

    if(ismouseclick(WM_MOUSEMOVE)==1)
    {
        getmouseclick(WM_MOUSEMOVE,mx,my);

        if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/10+y/9 && my<=y/5+2*(y/9))
        {
            if(Game.col==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/6,y/10+y/9,x/3+x/4+x/30+x/6,y/5+2*(y/9));
                Game.col=0;
            }
        }
        else if(Game.col==0)
        {
            setlinestyle(0,0,1);
            MeniuPVE(x,y);
            delay(2);
            Game.col=1;
        }



        if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/10+(4*(y/9)) && my<=y/5+(5*(y/9)))
        {
            if(Game.col1==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/6,y/10+(4*(y/9)),x/3+x/4+x/30+x/6,y/5+(5*(y/9)));
                Game.col1=0;
            }
        }
        else if(Game.col1==0)
        {
            setlinestyle(0,0,1);
            MeniuPVE(x,y);
            Game.col1=1;
        }


        if(mx>=x/3+x/30 && mx<=x/3+x/4 && my>=y/5+(5*(y/8))+y/30 && my<=y/5+(6*(y/8)))
        {
            if(Game.col2==1)
            {
                setlinestyle(0,1,10);
                rectangle(x/3+x/30,y/5+(5*(y/8))+y/30,x/3+x/4,y/5+(6*(y/8)));
                Game.col2=0;
            }
        }
        else if(Game.col2==0)
        {
            setlinestyle(0,0,1);
            MeniuPVE(x,y);
            Game.col2=1;
        }



    }

}

int main()
{
    int x=800 , y=600 , mx=0 , my=0 ;

    PlaySound(TEXT("Vectorman Ocean1.wav"),NULL,SND_LOOP|SND_ASYNC);

    initwindow(x,y,"CINCI IN LINIE");

    MENIU(x,y);

    int ok=1;

    FILE*frt;

    while(1)
    {


        if(ismouseclick(WM_LBUTTONDOWN)==1)
        {
            getmouseclick(WM_LBUTTONDOWN,mx,my);
            clearmouseclick(WM_LBUTTONDOWN);
        }

        colorButton(x,y);

        if(mx>=x/3 && mx<=x/3+x/4+x/30 && my>=y/5+y/9 && my<=y/5+2*(y/9))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            mx=0;
            my=0;
            closegraph();
            initwindow(x,y,"CINCI IN LINIE");
            MODdeJOC(x,y);

            while(1)
            {

                if(ismouseclick(WM_LBUTTONDOWN)==1)
                {
                    getmouseclick(WM_LBUTTONDOWN,mx,my);
                    clearmouseclick(WM_LBUTTONDOWN);
                }

                colorButton1(x,y);

                if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/10+y/9 && my<=y/5+3*(y/9) && !(mx>=x/3+x/50 && mx<=x/3+x/4+x/50 && my>=4*(y/10) && my<=5*(y/10)))
                {
                    PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);

                    if(fisier()==true)
                    {
                        closegraph();
                        initwindow(x,y,"Resume CINCI PE LINIE");
                        Alegere(x,y);

                        while(1)
                        {
                            if(ismouseclick(WM_LBUTTONDOWN)==1)
                            {
                                getmouseclick(WM_LBUTTONDOWN,mx,my);
                                clearmouseclick(WM_LBUTTONDOWN);
                            }
                            if(mx>=250&&mx<=350&&my>=200&&my<=250)
                            {
                                Resume(x,y);
                                startPVPR(x,y);
                                main();
                                break;
                            }
                            else if(mx>=515&&mx<=610&&my>=199&&my<=249)
                            {
                                closegraph();
                                frt=fopen("Resume","w+");
                                fclose(frt);
                                frt=fopen("Raspuns","w+");
                                fclose(frt);
                                Game.fptr=fopen("istoric.txt","a");
                                fwrite("---", 3, 1, Game.fptr);
                                fclose(Game.fptr);
                                frt=fopen("Numar jucator 1","w+");
                                fclose(frt);
                                Numejucatori(x,y);
                                startPVP(x,y);
                                main();
                                break;

                            }
                        }

                    }
                    else

                    {
                        Numejucatori(x,y);
                        startPVP(x,y);
                        main();
                    }
                    break;
                }

                if(mx>=x/3+x/50 && mx<=x/3+x/4+x/50 && my>=4*(y/10) && my<=5*(y/10))
                {
                    PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                    IstoricAf(x,y);
                    main();
                    break;
                }


                if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/10+(4*(y/9)) && my<=y/5+(5*(y/9)))
                {
                    PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                    mx=0;
                    my=0;

                    closegraph();
                    initwindow(x,y,"CINCI IN LINIE");

                    MeniuPVE(x,y);

                    while(1)
                    {

                        if(ismouseclick(WM_LBUTTONDOWN)==1)
                        {
                            getmouseclick(WM_LBUTTONDOWN,mx,my);
                            clearmouseclick(WM_LBUTTONDOWN);
                        }

                        colorButton4(x,y);

                        if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/10+y/9 && my<=y/5+2*(y/9))
                        {
                            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                            startPVEe(x,y);
                            main();
                            break;
                        }

                        if(mx>=x/6 && mx<=x/3+x/4+x/30+x/6 && my>=y/10+(4*(y/9)) && my<=y/5+(5*(y/9)))
                        {
                            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                            startPVEn(x,y);
                            main();
                            break;
                        }

                        if(mx>=x/3+x/30 && mx<=x/3+x/4 && my>=y/5+(5*(y/8))+y/30 && my<=y/5+(6*(y/8)))
                        {
                            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                            closegraph();
                            main();
                            break;
                        }



                    }

                    break;
                }

                if(mx>=x/3+x/30 && mx<=x/3+x/4 && my>=y/5+(5*(y/8))+y/30 && my<=y/5+(6*(y/8)))
                {
                    PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                    closegraph();
                    main();
                    break;
                }

            }

            break;

        }

        if(mx>=x/3 && mx<=x/3+x/4+x/30&&my>=y/5+(3*(y/9))&&my<=y/5+(4*(y/9)))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            closegraph();
            my=0;
            mx=0;
            initwindow(x,y,"CINCI IN LINIE REGULAMENT");
            Regulament(x,y);
            while(1)
            {
                if(ismouseclick(WM_LBUTTONDOWN)==1)
                {
                    getmouseclick(WM_LBUTTONDOWN,mx,my);
                    clearmouseclick(WM_LBUTTONDOWN);
                }

                colorButton3(x,y);

                if(mx>=x/266.666 && mx<=x/5 && my>=y/60 && my<=y/12)
                {
                    PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
                    closegraph();
                    main();

                }

            }

            break;

        }



        if(mx>=x/3 && mx<=x/3+x/4+x/30 && my>=y/5+(5*(y/9)) && y/5+(6*(y/9)))
        {
            PlaySound(TEXT("ButtonPlate Click1.wav"),NULL,SND_SYNC);
            closegraph();
            break;
        }

    }



    closegraph();

    return 0;
}
