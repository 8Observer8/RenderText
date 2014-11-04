#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent )
{
}

void Scene::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void Scene::paintGL()
{
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    // Set current drawing color to red
    //		   R	 G	   B
    glColor3f( 0.0f, 1.0f, 0.0f );

    // Draw a filled rectangle with current color
    //glRectf( -25.0f, 25.0f, 25.0f, -25.0f );

    QFont myFont("Verdana", 24);
    //myFont.setStyleStrategy(QFont.OpenGLCompatible);
    const int xInit = -20;
    int yInit = 20;
    const int xOffset = 15;
    const int yOffset = 15;
    renderText( xInit-10, yInit, 0, "Меню:", myFont);
    renderText( xInit, yInit -= yOffset, 0, "Новая игра", myFont);
    renderText( xInit, yInit -= yOffset, 0, "Правила", myFont);
    renderText( xInit, yInit -= yOffset, 0, "Управление", myFont);
    renderText( xInit, yInit -= yOffset, 0, "Выход", myFont);
}

void Scene::resizeGL( int w, int h )
{
    // Prevent a divide by zero
    if( h == 0 ) {
        h = 1;
    }

    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    GLfloat aspectRatio = ( GLfloat )w / ( GLfloat )h;
    if ( w <= h ) {
        glOrtho( -100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio,
                  1.0, -1.0);
    } else {
        glOrtho( -100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0,
                 1.0, -1.0 );
    }

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}
