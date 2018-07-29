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

int beings[100][10];

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


    for(int i=0; i<100; i++)
    {
        for(int a=0; a<10; a++)
        {
            cout << beings[i][a];
        }
        cout << endl;
    }
    system("PAUSE");
}

int algoritm()
{
    system("cls");

    int places[10][2];

    for(int i =0; i<10; i++)//Last value in second column always get value of int i in given inclination !!REPAIR!!
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
