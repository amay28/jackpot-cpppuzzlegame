#include <iostream>
//#include<conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Start ();
void GetResults ();

int  i, j, life, maxrand;
char c;


void
Start ()
{
    cout << "\n\n\n\n______________________________ * * $ $ $ Jackpot game $ $ $ * * _____________________________________\n\n";
     cout << "  $ :-     The goal of this game is to guess a number. You will be ask to type\n";
     cout << "  $ :-     A number (you have guess depend on playing mode)\n";
     cout << "  $ :-     Jackpot will then tell you if this number is too big of too small compared to the secret number to find  \n";
     cout<<"|-------------||-------------||-------------||-------------||-------------||-------------||-------------||-------------||\n";
     i = 0;
     j = 0;
     life = 0;
     maxrand = 6;
        cout<<"\n\n                                $ $ $ Lets the Game Begin $ $ $     \n\n";
     cout << "  Select difficulty mode ______ :\n"; // the user has to select a difficutly level
     cout << "      1 : Easy          (0 - 20)\n";
     cout << "      2 : Medium        (0 - 50)\n";
     cout << "      3 : Difficult     (0 - 100)\n";
     cout << "      4 : Too Difficult (0 - 1000)\n";
     cout << "or type another key to quit\n";
     c = 30;

     cin >> c;                   // read the user's choice
     cout << "\n";

     switch (c)
     {
        case '1' : maxrand = 20; life = 4;  // the random number will be between 0 and maxrand
        break;
        case '2' : maxrand = 50; life = 5;
        break;
        case '3' : maxrand = 100; life = 6;
        break;
        case '4' : maxrand = 1000; life = 11;break;
        default : exit(0);
        break;
     }

              // number of lifes of the player
     srand( (unsigned)time( NULL ) ); // init Rand() function
     j = rand() % maxrand;  // j get a random value between 0 and maxrand

     GetResults();

}


void
GetResults ()
{
     if (life <= 0)
        // if player has no more life then he lose
     {
        cout << "You lose !\n\n"<<" Answer is $ "<<j<<endl;
        Start();
     }

     cout << "__________Type a number___________: \n";
     cin >> i;          // read user's number

     if ((i>maxrand) || (i<0)) // if the user number isn't correct, restart
     {
        cout << "Error : Number not between 0 and \n" << maxrand;
        GetResults();
     }

     if (i == j)
     {
        cout << "           ________  :) :p ~~...YOU WIN...~~ <: :p !___________        \n\n"; // the user found the secret number
        Start();
     }

     else if (i>j)
     {
        cout << "BIGGER NUMBER\n";
        life = life - 1;    // -1 to the user's "life"
        cout << "Number of remaining life: " << life << "\n\n";
        GetResults();
     }

     else if (i<j)
     {
        cout << "SMALLER NUMBER\n";
        life = life - 1;
        cout << "Number of remaining life: " << life << "\n\n";
        GetResults();
     }
}


int
main ()
{

     Start();
//     getch();
     return 0;
}

