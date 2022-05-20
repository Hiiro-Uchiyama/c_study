//
//  main.c
//  C_C
//
//  Created by Hiiro Uchiyama on 2021/05/07.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#define PI 3.141592653589793

double posBegin[2];
double posEnd[2];

struct rectangle{
    double pos[2];
    double size[2];
    double color[3];
    struct rectangle *next;
};
struct rectangle *root = NULL;

void drawRect (struct rectangle *r){
    glColor3d(r->color[1], r->color[1], r->color[2]);
    glBegin(GL_POLYGON);
    glVertex2d(r->pos[0], r->pos[1]);
    glVertex2d(r->pos[0] + r->size[0], r->pos[1]);
    glVertex2d(r->pos[0] + r->size[0], r->pos[1] - r->size[1]);
    glVertex2d(r->pos[0], r->pos[1] - r->size[1]);
    glEnd();
    if(r->next != NULL){
        drawRect(r->next);
    }
}

void insert(struct rectangle *p){
    struct rectangle *curRect;
    curRect = (struct rectangle *)malloc(sizeof(struct rectangle));
    if(root == NULL){
        root = p;
        return;
    }
    curRect = root;
    while(curRect->next!=NULL){
        curRect = curRect->next;
    }
    curRect->next = p;
}

void mouse(int button, int state, int x, int y){
    int i;
    struct rectangle *newRect;
    newRect = (struct rectangle *)malloc(sizeof(struct rectangle));
    if (button != GLUT_LEFT_BUTTON){
        return;
    }
    if(state == GLUT_DOWN){
        ;
    }
    else if (state == GLUT_UP){
        posBegin[0] = (double)x / glutGet(GLUT_WINDOW_WIDTH) * 2 - 1;
        posBegin[1] = -(double)y / glutGet(GLUT_WINDOW_WIDTH) * 2 + 1;
    }
    for (i = 0; i < 2; i++){
        newRect->pos[i] = posBegin[i];
        newRect->size[i] = posEnd[i] - posBegin[i];
        if (i == 1){
            newRect->size[i] *= -1;
        }
    }
    for (i = 0; i < 3; i++){
        newRect->color[i] = (double)rand() / RAND_MAX;
    }
    newRect->next = NULL;
    insert(newRect);
    glutPostRedisplay();
}

void disply(void){
    glClear(GL_COLOR_BUFFER_BIT);
    if (root != NULL){
        drawRect(root);
    }
    glFlush();
    glutPostRedisplay();
}

void init (void){
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main (int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(disply);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return EXIT_SUCCESS;
}
