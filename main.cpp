/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void optionOne (void);
void optionTwo (void);
void optionThree (void);
void optionFour (void);

int main()
{
    
    double x1, x2, y1, y2;

    int option;
    char again;
    
    cout << "Enter x1" << endl;
    cin >> x1;
    cout << "Enter x2" << endl;
    cin >> x2;
    cout << "Enter y1" << endl;
    cin >> y1;
    cout << "Enter y2" << endl;
    cin >> y2;
    
    cout << "(1) Given two points, compute the distance between the two points" << endl;
    cout << "(2) Given two points, compute the horizonatal angle from the first point to the second" << endl;
    cout << "(3) Given the elevation angle and velocity, comute the horizonatal distance on object travels" << endl;
    cout << "(4) GIven a starting point, a distance, and a horizonatal angle, compute the destination point." << endl;
    cin >> option;
    do
    { 
        if (option == 1)
        {
            optionOne( x1,  x2,  y1,  y2, distance);
            cout << "would you like to do it again?(y/n)";
            cin >> again;
        }
        else if (option == 2)
        {
            optionTwo();
            cout << "would you like to do it again?(y/n)";
            cin >> again;
        }
        else if (option == 3)
        {
            optionThree();
            cout << "would you like to do it again?(y/n)";
            cin >> again;
        }
        else if (option == 4)
        {
            optionFour();
            cout << "would you like to do it again?(y/n)";
            cin >> again;
        }
        else
        {
            cout << "Please enter an vaild option." << endl;
            cout << "would you like to do it again?(y/n)";
            cin >> again;
        }
        
    }while (again = 'y');
    return 0;
}

void optionOne(double x1, double x2, double y1, double y2, double distance)
{
    distance = ((pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0))); 
    distance = sqrt (distance);
    cout << distance << endl;
}

void optionTwo()
{
    double disX, disY, angle, angleRad, x1, x2, y1, y2;
    const double PI  = 3.14159;
    
    cout << "Enter x1" << endl;
    cin >> x1;
    cout << "Enter x2" << endl;
    cin >> x2;
    cout << "Enter y1" << endl;
    cin >> y1;
    cout << "Enter y2" << endl;
    cin >> y2;
    
    disX = (x2 - x1);
    disY = (y2 - y1);
    
    if (disX > 0.0)
    {
        angle = atan( disY / disX);
    }
    else if (disX < 0.0)
    {
        angle = atan (disY / disX) * (PI);
    }
    else if (disX = 0.0 && disY >= 0.0)
    {
        angle = (PI/2);
    }
    else if (disX = 0.0 && disY < 0.0)
    {
        angle = (-1.0 * PI) / 2.0;
    }
    else 
    {
        cout << "WEll idk" << endl;
    }
    
    angleRad = angle * 180.0;
    
    cout << angleRad << endl;
    
}

void optionThree()
{
    double angleRad, angle, velMph, velFps, horiz;
    const double gravity = 32.172 ;
    const double feetPerMil = 5280 ;
    const double secondPerMil = 3600 ;
    const double PI  = 3.14159;
    
    cout << "what is the elevation (in degrees)" << endl;
    cin >> angle;
    cout << "What is the inital velocity (in miles per hour)" << endl;
    cin >> velMph;
    
    angleRad = (angle * (PI / 180.0));
    velFps = (velMph * (feetPerMil / secondPerMil));
    horiz = (pow(velFps,2.0)) * sin(2.0 * angleRad) / gravity; 
    
    cout << horiz << endl;
    
}

void optionFour()
{
    double horiz, horizRad, distance, dX, dY, x1, x2, y1, y2;
    const double PI = 3.14159;
    
    cout << "What is the horizonatal angle(in degrees)" << endl;
    cin >> horiz;
    cout << "What is the distance between the two points? (in feet)" << endl;
    cin >> distance;
    cout << "Enter x1" << endl;
    cin >> x1;
    cout << "Enter y1" << endl;
    cin >> y1;
    
    horizRad = horiz * (PI / 180.0);
    dX = distance * cos(horiz);
    dY = distance * sin(horiz);
    x2 = x1 + dX ;
    y2 = y1 + dY ;
    
    cout << "(" << x1 << "," << y1 << ")" << endl;
    cout << "(" << x2 << "," << y2 << ")" <<  endl;
    
}



