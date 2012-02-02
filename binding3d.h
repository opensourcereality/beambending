#ifndef BINDING3D_H
#define BINDING3D_H

#include <QtOpenGL/QGLWidget>

class binding3d : public QGLWidget
{
    Q_OBJECT
public:
    explicit binding3d(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    void draw();
    int faceAtPosition(const QPoint &pos);
    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;

signals:

public slots:

};

#endif // BINDING3D_H
