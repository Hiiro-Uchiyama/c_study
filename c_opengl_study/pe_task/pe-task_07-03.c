#include <stdio.h>
#include <stdlib.h>
#include "glut.h"
#include <math.h> //sin(), cos()���g�p���邽�߂̃w�b�_�t�@�C���̓ǂݍ���

//�_�̏����ݒ�
double posDot[2] = { 0.9, 0 }; //�|�W�V������\���ϐ�
GLfloat colDot[3] = { 1.0, 1.0, 1.0 }; //�F��\���ϐ�
double velDot[2] = { -0.05, 0.05 }; //�ړ��ʂ̂��߂̕ϐ�

//�~�̏����ݒ�
double posCir[2] = { -0.9, 0 }; //�|�W�V������\���ϐ�
GLfloat colCir[3] = { 1.0, 0.0, 0.0 }; //�F��\���ϐ�
double velCir[2] = { 0.1, 0.1 }; //�ړ��ʂ̂��߂̕ϐ�

//�L�[�̏�Ԃ�\���O���[�o���ϐ��i0�̂Ƃ��F������Ă��Ȃ��C1�̂Ƃ��F������Ă���j
int keyUp = 0, keyDown = 0, keyLeft = 0, keyRight = 0;

void checkSpecialKeyPressed(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		keyUp = 1; break;
	case GLUT_KEY_DOWN:
		keyDown = 1; break;
	case GLUT_KEY_LEFT:
		keyLeft = 1; break;
	case GLUT_KEY_RIGHT:
		keyRight = 1; break;
	}
}

//����L�[���߂��ꂽ���̏������s���֐����w��
void checkSpecialKeyReleased(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		keyUp = 0; break;
	case GLUT_KEY_DOWN:
		keyDown = 0; break;
	case GLUT_KEY_LEFT:
		keyLeft = 0; break;
	case GLUT_KEY_RIGHT:
		keyRight = 0; break;
	}
}

//�_��`��
void drawDot(double position[2]) {
	glPointSize(10); //�_�̑傫�����w��
	//�_�̕`����W���w��
	glBegin(GL_POINTS);
	glVertex2d(position[0], position[1]);
	glEnd();
}

//�~��`��
void drawCircle(double position[2], double radius, int startAngle, int endAngle) {
	int i;
	glBegin(GL_POLYGON); //
	for (i = startAngle; i <= endAngle; i += 360.0 / 36) {
		glVertex3f(
			position[0] + radius * cos(3.14 * i / 180),
			position[1] + radius * sin(3.14 * i / 180), 0.0);
	}
	glEnd(); //�`��I��
}

//�@�ĕ`��֐��i��莞�Ԃ��Ɓj
void updatePos(int value) {
	//�_�̈ʒu�̍X�V
	posDot[0] += velDot[0];
	posDot[1] += velDot[1];

	//��ʂ̒[�܂ňړ������Ƃ��͕����ϊ�
	if (posDot[0] >= 1.0 || posDot[0] <= -1.0)
		velDot[0] *= -1;
	if (posDot[1] >= 1.0 || posDot[1] <= -1.0)
		velDot[1] *= -1;

	//�~�̈ʒu���X�V
	if (keyUp == 1)
		posCir[1] += velCir[1];
	if (keyDown == 1)
		posCir[1] -= velCir[1];
	if (keyLeft == 1)
		posCir[0] -= velCir[0];
	if (keyRight == 1)
		posCir[0] += velCir[0];

	//�~����ʂ̒[�܂ňړ������Ƃ��͒�~
	if (posCir[0] >= 1.0)
		posCir[0] = 1.0;
	if (posCir[0] <= -1.0)
		posCir[0] = -1.0;
	if (posCir[1] >= 1.0)
		posCir[1] = 1.0;
	if (posCir[1] <= -1.0)
		posCir[1] = -1.0;

	glutPostRedisplay(); //��ʂ̍ĕ`��
	glutTimerFunc(100, updatePos, 0); //��莞�ԁi�~���b�j��ɁC���̊֐������s
}

//��ʂ�`��
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT); //�o�b�t�@���N���A
	glColor3d(colDot[0], colDot[1], colDot[2]); //�`��F�̎w��
	drawCircle(posDot, 0.05, 0, 360); //�_�i�h�b�g�j��`��

	glColor3d(colCir[0], colCir[1], colCir[2]); //�`��F�̎w��
	drawCircle(posCir, 0.05, 0, 360); //�~��`��
	glutSwapBuffers();
}

//������
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0); //�w�i�F���w��
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv); //GLUT���C�u������������
	//�\�����[�h���_�u���o�b�t�@�����O�ɐݒ�
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
	glutCreateWindow(argv[0]); //�E�B���h�E�𐶐�
	glutDisplayFunc(display); //�E�B���h�E�̕`����s���֐����w��
	
	//����L�[�������ꂽ�i�߂��ꂽ�j�Ƃ��̏������s���֐����w��
	glutSpecialFunc(checkSpecialKeyPressed);
	glutSpecialUpFunc(checkSpecialKeyReleased);
	
	init(); //������

	//��莞�Ԍ�Ɏ��s����֐����w��
	glutTimerFunc(1000, updatePos, 0);
	glutMainLoop(); //���C�����[�v

	return EXIT_SUCCESS;
}