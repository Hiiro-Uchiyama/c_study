#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "glut.h"

#define PI 3.141592653589793

typedef  struct {
    double pos_0;	// �ʒux���W
    double pos_1;	// �ʒuy���W
    double size;	// �T�C�Y
    double sign1;	// ����
    double sign2;	// ����
    double param1;	// �p�����[�^1
    double param2;	// �p�����[�^2
    double param3;	// �p�����[�^3
    double color[3];// �J���[
    int  startangle;// �~�̊J�n�p�x
    int  endangle;	// �~�̏I���p�x
} face;

face brow_left = { 0.2, 0.2, 0.3, -1.0, 1.0, 0.3, 0.4, 0.1, { 0.9, 0.5, 0.2 }, 0, 180 };
face brow_right = { 0.2, 0.2, 0.3, 1.0, 1.0, 0.3, 0.4, 0.1, { 0.9, 0.5, 0.2 }, 0, 180 };
face eye_left = { 0.2, 0.2, 0.3, -1.0, 1.0, 0.3, 0.3, 0.05, { 0.9, 0.5, 0.2 }, 0, 360 };
face eye_right = { 0.2, 0.2, 0.3, 1.0, 1.0, 0.3, 0.3, 0.05, { 0.9, 0.5, 0.2 }, 0, 360 };
face nose = { 0.2, 0.2, 0.3, 1.0, -1.0, 0, 0.1, 0.2, { 0.9, 0.5, 0.2 }, 70, 290 };
face mouth_t0 = { 0.2, 0.2, 0.3, 1.0, 1.0, 0, 0.2, 0.7, { 0.9, 0.5, 0.2 }, 225, 315 };
face mouth_t1 = { 0.2, 0.2, 0.3, 1.0, -1.0, 0, 1.2, 0.7, { 0.9, 0.5, 0.2 }, 45, 135 };
face faceline = { 0.2, 0.2, 0.3, 1.0, 1.0, 0, 0, 1.0, { 0.9, 0.5, 0.2 }, 0, 360 };


//�������֐�
void init(void) {
    //�w�i�F���w��
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void drawCircle(double pos_x, double pos_y, double color[3], double radius, int startAngle, int endAngle) {

    int i;

    glBegin(GL_LINE_STRIP); //�܂���̕`��J�n

    for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
        glColor3d(color[0], color[1], color[2]); //�`��F���w��
        glVertex2d(
            pos_x + radius * cos(3.14 * i / 180), //������x���W
            pos_y + radius * sin(3.14 * i / 180)  //������y���W
        );
    }
    glEnd(); //�`��I��
}

//��̕`��
void drawFace3(int type) {
    double pos[2] = { 0.2,0.2 };
    double size = 0.3;
    double color_f[3] = { 0.9,0.5,0.2 };

    drawCircle(pos[0] - size * 0.3, pos[1] + size * 0.4, color_f, size * 0.1, 0, 180);   //���i���j
    drawCircle(pos[0] + size * 0.3, pos[1] + size * 0.4, color_f, size * 0.1, 0, 180);   //���i�E�j
    drawCircle(pos[0] - size * 0.3, pos[1] + size * 0.3, color_f, size * 0.05, 0, 360);   //�ځi���j
    drawCircle(pos[0] + size * 0.3, pos[1] + size * 0.3, color_f, size * 0.05, 0, 360);   //�ځi�E�j
    drawCircle(pos[0], pos[1] + size * 0.1, color_f, size * 0.2, 70, 290);   //�@
    drawCircle(pos[0], pos[1], color_f, size * 1.0, 0, 360);   //�֊s

    //�^�C�v
    if (type == 0) {
        drawCircle(pos[0], pos[1] + size * 0.2, color_f, size * 0.7, 225, 315);  //��
    }
    else if (type == 1) {
        drawCircle(pos[0], pos[1] - size * 1.2, color_f, size * 0.7, 45, 135);  //��
    }

}


//�`��֐�
void disply(void) {
    //�o�b�t�@���N���A
    glClear(GL_COLOR_BUFFER_BIT);
    drawFace3(1);
    glFlush();  //���ߎ��s
}


int main(int argc, char* argv[]) {
    //GlUT���C�u������������
    glutInit(&argc, argv);

    //�\�����[�h��ݒ�
    glutInitDisplayMode(GLUT_RGBA);

    //�E�B���h�E�𐶐�
    glutCreateWindow(argv[0]);

    //�`����s���֐�
    glutDisplayFunc(disply);

    //������
    init();

    //���C�����[�v
    glutMainLoop();

    return EXIT_SUCCESS;
}
