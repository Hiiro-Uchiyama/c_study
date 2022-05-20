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

void drawCircle(face fval) {

    int i;
    glBegin(GL_LINE_STRIP); //�܂���̕`��J�n

    for (i = fval.startangle; i <= fval.endangle; i += 360.0 / 36) {
        glColor3d(fval.color[0], fval.color[1], fval.color[2]); //�`��F���w��
        glVertex2d(
            fval.pos_0 + fval.sign1 * fval.size * fval.param1 + fval.size * fval.param3 * cos(3.14 * i / 180), //������x���W
            fval.pos_1 + fval.sign2 * fval.size * fval.param2 + fval.size * fval.param3 * sin(3.14 * i / 180)  //������y���W
        );
    }
    glEnd(); //�`��I��
}

//��̕`��
void drawFace3(int type) {

    drawCircle(brow_left);
    drawCircle(brow_right);
    drawCircle(eye_left);
    drawCircle(eye_right);
    drawCircle(nose);
    drawCircle(faceline);

    //�^�C�v
    if (type == 0) {
        drawCircle(mouth_t0);  //��
    }
    else if (type == 1) {
        drawCircle(mouth_t1);  //��
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
