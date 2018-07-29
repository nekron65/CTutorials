#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <fstream>

using namespace std;

int places[10][2];
int beings[100][10];
int rating[100][2];

int mesures()
{
    int fx =0;
    int fy=0;
    int ft=0;

    for(int a=0; a<100; a++)
    {
        rating[a][0] = a;   //Setting being ID
        rating[a][1] = 0;   //Reseting Distance value
    for(int i=0; i<9; i++)
    {
    fx  = places[beings[a][i]][0]-places[beings[a][i+1]][0]; //Calculating X distance
    fy = places[beings[a][i]][1]-places[beings[a][i+1]][1];  //Calculating Y distance

    if(fx<0)                    //
        fx *= -1;               //
                                //Making sure there is no negative
    if(fy<0)                    //As distance is always positive
        fy *= -1;               //

        ft = fx+fy;                 //Adding X and Y axis to get final distance

        rating[a][1] += ft;         //Summing all distances
    }
    cout << endl << a << ": " << rating[a][1];
    }


    system("PAUSE");

}

int creation()//Generating beings
{
    for(int i=0; i<100; i++)
    {
        for(int a=0; a<10; a++)
        {
            beings[i][a]=( rand() % 10 ) + 0;
            for(int b=0; b<a; b++)
            {
                if(beings[i][a]==beings[i][b])
                {
                    beings[i][a]=( rand() % 10 ) + 0;
                    b=-1;
                }

            }
        }
    }


    system("PAUSE");
}

int correction()
{
for (int i=0; i<99; i++)
        for (int j=0; j<99; j++)
            if (rating[j][1]>rating[j+1][1])
            {
                swap(rating[j][0], rating[j+1][0]);
                swap(rating[j][1], rating[j+1][1]);
            }


   for(int a=0; a<100; a++)
    {
         cout << endl << rating[a][0] << ": " << rating[a][1];
    }
}

int algoritm()
{
    system("cls");



    for(int i =0; i<10; i++)//Last record in second column always get value of int i in given inclination !!REPAIR!!
    {
        places[i][1]=( rand() % 10 ) + 1;
        places[i][2]=( rand() % 10 ) + 1;

    }

    for(int a =0; a<10; a++)
    {
        cout << places[a][1] << "   ";
        cout << places[a][2] << endl;
    }

    creation();
    mesures();
    correction();

    system("PAUSE");
    return 0;
}

int main()
{
    char menu;
    srand( time( NULL ) );
    while(true)
    {
        system("cls");

    cout << "[1]Start" << endl;
    cout << "[2]Exit" << endl;
    menu = getch();

    switch(menu)
    {
    case '1':
        algoritm();
        break;
    case '2':
        return 0;
        break;
    default:
        cout << "ERROR";

    }
    }

}
