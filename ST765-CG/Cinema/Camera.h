#include <GL/glut.h>
#include <math.h>
#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
private:
    float x, y, z;
    float yaw, pitch;

public:
    Camera(float x, float y, float z, float yaw, float pitch) : x(x), y(y), z(z), yaw(yaw), pitch(pitch) {}

    void reshape(int w, int h)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);
    }

    void placeCamera()
    {
        float radYaw   = yaw   * 3.14159265f / 180.0f;
        float radPitch = pitch * 3.14159265f / 180.0f;

        float fx = cosf(radYaw) * cosf(radPitch);
        float fy = sinf(radPitch);
        float fz = sinf(radYaw) * cosf(radPitch);

        float cx = x + fx;
        float cy = y + fy;
        float cz = z + fz;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x, y, z,          // posição da câmera
                  cx, cy, cz, // para onde olha
                  0.0, 1.0, 0.0);            // vetor up (cima)
    }

    void moveForward(float dist) {
        float radYaw = yaw * 3.14159265f / 180.0f;
        x += cosf(radYaw) * dist;
        z += sinf(radYaw) * dist;
    }

    void moveRight(float dist) {
        float radYaw = yaw * 3.14159265f / 180.0f;
        x += cosf(radYaw + 3.14159265f/2.0f) * dist;
        z += sinf(radYaw + 3.14159265f/2.0f) * dist;
    }

    void moveUp(float dist) {
        y += dist;
    }

    void rotateYaw(float deg) {
        yaw += deg;
    }

    void rotatePitch(float deg) {
        pitch += deg;
        if (pitch > 89.0f)  pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;
    }
};

#endif