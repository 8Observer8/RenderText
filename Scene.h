#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>

class Scene : public QGLWidget
{
public:
    Scene( QWidget *parent = 0 );

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );
};

#endif // SCENE_H
