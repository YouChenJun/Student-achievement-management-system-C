#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
//#Copyright (c) 2021 Huang yu xiang
int d;//ѧ������
struct student { //���Ǽ�򵥵�ѧ���Ľṹ��
	int num;
	char NAME[10];
	float chinese;
	float math;
	float english;
	float computer;
	float total;
};
void sr(struct student* sr);
void sc(struct student m[10]);
void cx(struct student m[10]);
void cx2(struct student m[10]);
void pl(struct student* p);
void delete (struct student m[10]);
void sc2(struct student* p);
//�ָ���
void sr(struct student* sr) { //���뺯�� ��ʾ������
	int i = 0;
	printf("������ѧ���ĸ���:");
	scanf("%d", &d);
	for (; i < d; i++) {
		printf("������ѧ��������:");
		scanf("%s", (*(sr + i)).NAME);
		printf("������ѧ����ѧ��:");
		scanf("%d", &(*(sr + i)).num);
		printf("������ѧ�������ĳɼ�:");
		scanf("%f", &(*(sr + i)).chinese);
		printf("������ѧ������ѧ�ɼ�:");
		scanf("%f", &(*(sr + i)).math);
		printf("������ѧ����Ӣ��ɼ�:");
		scanf("%f", &(*(sr + i)).english);
		printf("������ѧ���ļ�����ɼ�");
		scanf("%f", &(*(sr + i)).computer);
		(*(sr + i)).total = (*(sr + i)).computer + (*(sr + i)).english + (*(sr + i)).math + (*(sr + i)).chinese;
	}
}
void inputfile(struct student m[10]) {  //��ʱû��ʵ�ֵĹ���  �Ѿ�ʵ���ˣ���
	char sel, ch[60];
	FILE* fp;
	int i, j;
	printf("Ҫ���ļ������ȡ������(Y/N)\n");
	scanf(" %c", &sel);


	if (sel == 'Y' || sel == 'y') {
		printf("�����ļ�·����");
		scanf("%s", ch);
		if ((fp = fopen(ch, "r")) == NULL) {
			void sr();//���õ������Ǹ�������
		}

		else {
			for (i = 0; i < d; i++) {
				fscanf(fp, "%s %s", m[i].NAME, m[i].num); //ѧ����ѭ��
				for (j = 0; j < d; j++) {
					fscanf(fp, "%f %f %f %f", &m[i].chinese, &m[i].math, &m[i].english, &m[i].computer);
				}
			}
			fclose(fp);
		}
	} else if (sel == 'N' || sel == 'n') {
		void sc();
	} else
		printf("������벻�Ϸ�����\n");


}
void sc(struct student m[10]) { //���������������ʾ����
	int i = 0;
	for (; i < d; i++)
		printf("ѧ��:%d    ����:%s  ��ѧ:%.2f  Ӣ��:%.2f  �����:%.2f  \n�ܳɼ�:%.2f  \n", m[i].num, m[i].NAME, m[i].chinese, m[i].math, m[i].english, m[i].computer, m[i].total );
}
void outputfile(struct student m[10]) {
	char sel, ch[60];
	FILE *fp;
	int i, j;

	sc(m);
	getchar();
	printf("Ҫ������д�뵽�ļ�������(Y/N)\n");

	scanf("%c", &sel);
	if (sel == 'Y' || sel == 'y') { //��������
		printf("�������ļ���·��\n");
		scanf("%s", &ch);


		if ((fp = fopen(ch, "w")) == NULL) { //ֻд��ʽ���ļ�
			printf("���ļ�����");
			return;
		}

		else {
			for (i = 0; i < d; i++) {
				fprintf(fp, "%s %d", m[i].NAME, m[i].num);
				for (j = 0; j < 5; j++) { //�ɼ�ѭ��
					fprintf(fp, "%f %f %f %f", m[i].chinese, m[i].math, m[i].english, m[i].computer);
				}
			}
			printf("��ϲ�㣬����д��ɹ������Ե� %s �鿴ѧ���ɼ�\n", ch);
			fclose(fp);
		}
	} else if (sel == 'N' || sel == 'n') {
		return;
	} else {
		printf("����Ĳ��ԣ�\n");
	}
}
void cx(struct student m[10]) { //����ѧ�Ų�ѯ
	int i, n;
	int j = 0; //�ź�
	printf("����������Ҫ��ѯ��ѧ�ţ�");
	scanf("%d", &n);
	for (i = 0; i < d; i++) {
		if (n == m[i].num) {
			printf("ѧ��:%d    ����:%s  ��ѧ:%.2f  Ӣ��:%.2f  �����:%.2f  \n�ܳɼ�:%.2f  \n", m[i].num, m[i].NAME, m[i].math, m[i].english, m[i].computer, m[i].total);
			j++;
		}
	}
	if (j == 0) {
		printf("û�����ѧ��Ŷ��\n");
	}
}

void pl(struct student* p) { //�ɼ��ߵ�������
	int i, j;
	for (i = 0; i < d - 1; i++) {
		for (j = i + 1; j < d; j++) {
			if ((*(p + i)).total < (*(p + j)).total) { //���ܳɼ�����
				*(p + d) = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = *(p + d);
			}
		}
	}
	for (i = 0; i < d; i++)
		printf("ѧ��:%d    ����:%s  ��ѧ:%.2f  Ӣ��:%.2f  �����:%.2f  \n�ܳɼ�:%.2f  \n", (*(p + i)).num, (*(p + i)).NAME, (*(p + i)).chinese, (*(p + i)).math, (*(p + i)).english, (*(p + i)).computer, (*(p + i)).total);
}
void add(struct student* p) { //����ѧ��
	d++;
	printf("����������:");
	scanf("%s", (*(p + d - 1)).NAME);
	printf("������ѧ��:");
	scanf("%d", &(*(p + d - 1)).num);
	printf("���������ĳɼ�:");
	scanf("%f", &(*(p + d - 1)).chinese);
	printf("��������ѧ�ɼ�:");
	scanf("%f", &(*(p + d - 1)).math);
	printf("������Ӣ��ɼ�:");
	scanf("%f", &(*(p + d - 1)).english);
	printf("�����������ɼ�");
	scanf("%f", &(*(p + d - 1)).computer);
	(*(p + d - 1)).total = (*(p + d - 1)).computer + (*(p + d - 1)).english + (*(p + d - 1)).math;

}
void delete (struct student m[10]) { //ɾ��ѧ��
	int x, i;
	printf("����ɾ��ѧ����ѧ��:");
	scanf("%d", &x);
	for (i = x; i < d; i++) {
		m[i] = m[i + 1];
	}
	d--;//��ѧ����Ҫ����һ��

}
void dayu(struct student m[10]) { //���ƽ���ִ���80��
	int i, j = 0;
	for (i = 0; i < d; i++) {
		if (80 <( (m[i].total) / 4.0) ){
			printf("ѧ��:%d    ����:%s  ��ѧ:%.2f  Ӣ��:%.2f  �����:%.2f  \n�ܳɼ�:%.2f  \n\n", m[i].num, m[i].NAME, m[i].chinese, m[i].math, m[i].english, m[i].computer, m[i].total);
			j++;
		}
	}
	if (j = 0) {
		printf("��Ŷ��û��");
	}

}
void main() { //������

	struct student m[10];
	int choice;
	do {
		printf("******��ӭʹ��ѧ���ɼ�����ϵͳ******\n");
		printf("      0.�˳�\n");
		printf("      1.ѧ��������Ϣ¼��\n");
		printf("      2.ѧ��������Ϣ�����\n");
		printf("      3.����ѧ�Ų�ѯѧ����Ϣ\n");
		printf("      4.���ɼ��ܷ��ɸߵ�������\n");
		//printf("      5.��ѧ���޸�ĳѧ����Ϣ�����\n");
		printf("      5.ɾ��ĳѧ����Ϣ\n");
		printf("      6.����ĳѧ����Ϣ\n");
		printf("      7.���ƽ���ִ���80�ֵ�ͬѧ��Ϣ\n");
		printf("---------------------------------------\n");
		printf("��������Ĳ���:");
		scanf("%d", &choice);
		if (choice == 0)
			return 0;
		switch (choice) {
			case 0:
				exit(0);
			case 1:
				inputfile(m);
				break;
			case 2:
				outputfile(m);
				break;
			case 3:
				cx(m);
				break;
			case 4:
				pl(m);
				break;
			/*	case 5:
					xg(m);
					break;
			*/
			case 5:
				delete (m);
				break;
			case 6:
				add(m);
				break;
			case 7:
				dayu(m);
				break;
		}
	} while (1);

}