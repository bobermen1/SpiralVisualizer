#include "DrawSpiral.h"

using namespace std;

enum direction {RIGHT, UP, LEFT, DOWN};

void drawSquareSpiral(ll start)
{
    ll y = ScreenHeight / 2;
    ll x = ScreenWidth % 2 == 0 ? y - 1 : y;//shift left for even n's
    ll currNumber = 0;
    ll size = ScreenWidth;
    ll fLeft,fRight, fUp, fDown;
    fLeft = fRight = x;
    fUp = fDown = y;

    //get to start of numbers
    while(currNumber < numbers.size() && numbers.at(currNumber) < start)
    {
        currNumber++;
    }
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POINTS);
    for(ll j = start; j < ScreenWidth * ScreenHeight - 1 + start && j < numbers.size(); j++)
    {
        if(j == numbers.at(currNumber))
        {
            //TODO test scaling
            glVertex2i(x,y);
            currNumber++;
        }

        switch(dir)
        {
            case RIGHT:
                if(x <= size - 1 && x > fRight)
                {
                    fRight = x;
                    dir = UP;
                }
                break;
            case UP:
                if(y > fUp)
                {
                    fUp = y;
                    dir = LEFT;
                }
                break;
            case LEFT:
                if(x < fLeft)
                {
                    fLeft = x;
                    dir = DOWN;
                }
                break;
            case DOWN:
                if(y < fDown)
                {
                    fDown = y;
                    dir = RIGHT;
                }
        }

        //increment direction
        switch(dir)
        {
            case RIGHT:
                x += 1;
                break;
            case UP:
                y -= 1;
                break;
            case LEFT:
                x -= 1;
                break;
            case DOWN:
                y += 1;
                break;
        }
    }
    glEnd();
}
