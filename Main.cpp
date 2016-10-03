
// include files
#include <iostream>
#include "Globals.h"
#include "DrawSpiral.h"
#include "GenerateNumbers.h"
using namespace std;

// the GLUT header automatically includes gl.h and glu.h
#include <GL/freeglut.h>

// keypresses
const int EscapeKey = 27;


// OpenGL callback function prototypes
void display();
void reshape( int w, int h );
void keyboard( unsigned char key, int x, int y );
void mouseclick( int button, int state, int x, int y);

// useful graphics function prototypes
void initOpenGL();

// Menu Functions
void CreateMenus();
void MainMenuHandler(int item);
    void TypeMenuHandler(int item);
        void PrimeMenuHandler(int item);
        void RandomMenuHandler(int item);
        void OtherMenuHandler(int item);
            void EveryKthMenuHandler(int item);
    void StyleMenuHandler(int item);



/******************************************************************************/

// main() function
int main( int argc, char *argv[] )
{
    // perform various OpenGL initializations
    glutInit( &argc, argv );
    initOpenGL();

    // go into OpenGL/GLUT main loop, never to return
    glutMainLoop();

    // yeah I know, but it keeps compilers from bitching
    return 0;
}

/******************************************************************************/

// various commands to initialize OpenGL and GLUT
void initOpenGL( void )
{
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );     // 32-bit graphics and single buffering

    glutInitWindowSize( ScreenWidth, ScreenHeight );    // initial window size
    glutInitWindowPosition( 100, 50 );                  // initial window position
    glutCreateWindow( "Spiral" );                  // window title

    glClearColor( 0.0, 0.0, 0.0, 1.0 );                 // use black for glClear command


    // callback routines
    glutDisplayFunc( display );                         // how to redisplay window
    glutReshapeFunc( reshape );                         // how to resize window
    glutKeyboardFunc( keyboard );                       // how to handle key presses
    glutMouseFunc( mouseclick);

    //initialize random
    srand(time(NULL));

    CreateMenus();

}

/******************************************************************************/
//menu function
void CreateMenus()
{
    int value = 1;
    int PrimeMenu = glutCreateMenu(PrimeMenuHandler);
    glutAddMenuEntry( "All", value++);
    glutAddMenuEntry( "Twin Primes", value++);
    glutAddMenuEntry( "Triplet Primes", value++);
    glutAddMenuEntry( "Primes Separated By Four", value++);
    glutAddMenuEntry( "Primes Separated By Six", value++);
    glutAddMenuEntry( "Primes Separated By Twelve", value++);

    value = 1;
    int RandomMenu = glutCreateMenu(RandomMenuHandler);
    glutAddMenuEntry( " 5%", value++);
    glutAddMenuEntry( "10%", value++);
    glutAddMenuEntry( "15%", value++);
    glutAddMenuEntry( "20%", value++);
    glutAddMenuEntry( "30%", value++);
    glutAddMenuEntry( "40%", value++);
    glutAddMenuEntry( "50%", value++);
    glutAddMenuEntry( "Odd Numbers", value++);

    value = 1;
    int EveryKthMenu = glutCreateMenu(EveryKthMenuHandler);
    glutAddMenuEntry( "k = 01", value++);
    glutAddMenuEntry( "k = 02", value++);
    glutAddMenuEntry( "k = 03", value++);
    glutAddMenuEntry( "k = 04", value++);
    glutAddMenuEntry( "k = 05", value++);
    glutAddMenuEntry( "k = 06", value++);
    glutAddMenuEntry( "k = 07", value++);
    glutAddMenuEntry( "k = 08", value++);
    glutAddMenuEntry( "k = 09", value++);
    glutAddMenuEntry( "k = 10", value++);



    value = 1;
    int OtherMenu = glutCreateMenu(OtherMenuHandler);
    glutAddMenuEntry( "Fibonacci", value++);
    glutAddMenuEntry( "Squares", value++);
    glutAddSubMenu( "Every Kth Number", EveryKthMenu);



    //Menu for selecting number sequence type
    value = 1;
    int TypeMenu = glutCreateMenu(TypeMenuHandler);
    glutAddSubMenu( "Primes", PrimeMenu);
    glutAddSubMenu( "Random", RandomMenu);
    glutAddSubMenu( "Other", OtherMenu);


    value = 1;
    int StyleMenu = glutCreateMenu(StyleMenuHandler);
    glutAddMenuEntry( "Square Spiral", value++);
    glutAddMenuEntry( "Cicle Spiral", value++);

    value = 1;
    glutCreateMenu(MainMenuHandler);
    glutAddSubMenu( "Generation", TypeMenu);
    glutAddSubMenu( "Display", StyleMenu);
    glutAddMenuEntry( "Exit", value++);

    glutAttachMenu( GLUT_RIGHT_BUTTON );
}

void EveryKthMenuHandler(int item)
{
    currentGen = KTH_VALUE;
    kVal = item;
    GenerateNums(numMax + startNum - 1);
    glutPostRedisplay();
}

void OtherMenuHandler(int item)
{
    switch (item)
    {
        case 1: //regular primes
            currentGen = FIBONACCI;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 2:
            currentGen = SQUARES;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
    }
}

//handles selection of random number sequence generation
void RandomMenuHandler(int item)
{
    switch (item)
    {
        case 1:
            currentGen = FIVE_PERCENT;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 2:
            currentGen = TEN_PERCENT;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 3:
            currentGen = FIFTEEN_PERCENT;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 4:
            currentGen = TWENTY_PERCENT;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 5:
            currentGen = THIRTY_PERCENT;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 6:
            currentGen = FOURTY_PERCENT;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 7:
            currentGen = FIFTY_PERCENT;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 8:
            currentGen = RANDOM_ODDS;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
    }
}

//Handels selection of prime generation
void PrimeMenuHandler(int item)
{
    switch (item)
    {
        case 1: //regular primes
            currentGen = PRIMES;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 2:
            currentGen = TWIN_PRIMES;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 3:
            currentGen = TRIPLET_PRIMES;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 4:
            currentGen = SEPARATED_BY_FOUR;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 5:
            currentGen = SEPARATED_BY_SIX;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 6:
            currentGen = SEPARATED_BY_TWELVE;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
    }
}

//handels selection of type
void TypeMenuHandler(int item)
{

}


void StyleMenuHandler(int item)
{
    switch (item)
    {
        case 1:
            drawType = SQUARE_SPIRAL;
            setNumMax();
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 2:
            drawType = CIRCLE_SPIRAL;
            setNumMax();
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
    }
}


void MainMenuHandler(int item)
{
    switch (item)
    {
        case 1:
            exit(0);
            break;
    }
}


/******************************************************************************/
/*                          OpenGL callback functions                         */
/******************************************************************************/

// callback function that tells OpenGL how to redraw windowu
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );

    drawNumbers(startNum);

    // flush graphical output
    glutSwapBuffers();
    glFlush();
}

/******************************************************************************/

// callback function that tells OpenGL how to resize window
// note that this is called when the window is first created
void reshape( int w, int h )
{
    // store new window dimensions globally

    int xoffset = 0;
    int yoffset = 0;
    ScreenWidth = min(w,h);
    ScreenHeight = min(w,h);
    //cout << ScreenHeight << endl;
    setNumMax();
    GenerateNums(numMax + startNum - 1);

    // orthographic projection of 3-D scene onto 2-D, maintaining aspect ratio
    glMatrixMode( GL_PROJECTION );      // use an orthographic projection
    glLoadIdentity();                   // initialize transformation matrix
    if ( w > h )                        // use width:height aspect ratio to specify view extents
    {
        xoffset = (w - h) / 2; //calculate offset to keep screen centered
        gluOrtho2D(0, h, 0, h );
        glViewport( xoffset , 0, w - xoffset * 2, h );
    }
    else
    {
        yoffset = (h - w) / 2; //calculate offset to keep screen centered
        gluOrtho2D( 0, w, 0, w);
        glViewport( 0 , yoffset, w, h - yoffset * 2 );
    }
               // adjust viewport to new window

    // switch back to (default) model view mode, for transformations
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glutPostRedisplay();
}

// callback function that tells OpenGL how to handle keystrokes
void keyboard( unsigned char key, int x, int y )
{
    // correct for upside-down screen coordinates
    y = ScreenHeight - y;
    //cerr << "keypress: " << key << " (" << int( key ) << ") at (" << x << "," << y << ")\n";
    switch ( key )
    {
        // Escape quits program
        case EscapeKey:
            exit( 0 );
            break;
        case '=':                               //increase starting number
            startNum++;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case '-':                               //decrease starting number
            startNum = max(0, startNum - 1);
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 'p': //regular primes
            currentGen = PRIMES;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 't':
            currentGen = TWIN_PRIMES;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 'y':
            currentGen = TRIPLET_PRIMES;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case 'f': //fibonacci is boring
            currentGen = FIBONACCI;
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case '1':
            drawType = SQUARE_SPIRAL;
            setNumMax();
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
        case '2':
            drawType = CIRCLE_SPIRAL;
            setNumMax();
            GenerateNums(numMax + startNum - 1);
            glutPostRedisplay();
            break;
    }
}

void mouseclick( int button, int state, int x, int y)
{
}
