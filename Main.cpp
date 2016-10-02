
// include files
#include <iostream>
#include "Globals.h"
using namespace std;

// the GLUT header automatically includes gl.h and glu.h
#include <GL/freeglut.h>

// keypresses
const int EscapeKey = 27;


// OpenGL callback function prototypes
void display();
void reshape( int w, int h );
void keyboard( unsigned char key, int x, int y );
void mouseclick( int button, int state, int x, int y );

// useful graphics function prototypes
void initOpenGL();

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
    glutMouseFunc( mouseclick );                        // how to handle mouse events
}

/******************************************************************************/
/*                          OpenGL callback functions                         */
/******************************************************************************/

// callback function that tells OpenGL how to redraw windowu
void display( void )
{
    // clear the display
    glClear( GL_COLOR_BUFFER_BIT );

    glColor3f(1.0,0.0,1.0);
    //glRectd(0,0,800,400);
    //glColor3f(0.0,1.0,1.0);
    glRectd(0,0,ScreenWidth,ScreenHeight);

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
}


/******************************************************************************/

// callback function for mouse button click events
void mouseclick( int button, int state, int x, int y )
{
    switch ( button )
    {
        case GLUT_LEFT_BUTTON:              // left button
            if ( state == GLUT_DOWN )           // press
                cerr << "mouse click: left press at    (" << x << "," << y << ")\n";
            else if ( state == GLUT_UP )        // release
                cerr << "mouse click: left release at  (" << x << "," << y << ")\n";
            break;

        case GLUT_RIGHT_BUTTON:             // right button
            if ( state == GLUT_DOWN )           // press
                cerr << "mouse click: right press at   (" << x << "," << y << ")\n";
            else if ( state == GLUT_UP )        // release
                cerr << "mouse click: right release at (" << x << "," << y << ")\n";
            break;
    }
}
