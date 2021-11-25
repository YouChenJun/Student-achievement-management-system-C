#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
//#Copyright (c) 2021 Huang yu xiang
int d;//学生个数
struct student { //就是简简单单学生的结构体
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
//分割线
void sr(struct student* sr) { //输入函数 显示器输入
	int i = 0;
	printf("请输入学生的个数:");
	scanf("%d", &d);
	for (; i < d; i++) {
		printf("请输入学生的姓名:");
		scanf("%s", (*(sr + i)).NAME);
		printf("请输入学生的学号:");
		scanf("%d", &(*(sr + i)).num);
		printf("请输入学生的语文成绩:");
		scanf("%f", &(*(sr + i)).chinese);
		printf("请输入学生的数学成绩:");
		scanf("%f", &(*(sr + i)).math);
		printf("请输入学生的英语成绩:");
		scanf("%f", &(*(sr + i)).english);
		printf("请输入学生的计算机成绩");
		scanf("%f", &(*(sr + i)).computer);
		(*(sr + i)).total = (*(sr + i)).computer + (*(sr + i)).english + (*(sr + i)).math + (*(sr + i)).chinese;
	}
}
void inputfile(struct student m[10]) {  //暂时没有实现的功能  已经实现了！！
	char sel, ch[60];
	FILE* fp;
	int i, j;
	printf("要从文件里面读取数据吗？(Y/N)\n");
	scanf(" %c", &sel);


	if (sel == 'Y' || sel == 'y') {
		printf("输入文件路径：");
		scanf("%s", ch);
		if ((fp = fopen(ch, "r")) == NULL) {
			void sr();//调用到输入那个函数体
		}

		else {
			for (i = 0; i < d; i++) {
				fscanf(fp, "%s %s", m[i].NAME, m[i].num); //学生的循环
				for (j = 0; j < d; j++) {
					fscanf(fp, "%f %f %f %f", &m[i].chinese, &m[i].math, &m[i].english, &m[i].computer);
				}
			}
			fclose(fp);
		}
	} else if (sel == 'N' || sel == 'n') {
		void sc();
	} else
		printf("你的输入不合法啊！\n");


}
void sc(struct student m[10]) { //基本程序输出（显示器）
	int i = 0;
	for (; i < d; i++)
		printf("学号:%d    姓名:%s  数学:%.2f  英语:%.2f  计算机:%.2f  \n总成绩:%.2f  \n", m[i].num, m[i].NAME, m[i].chinese, m[i].math, m[i].english, m[i].computer, m[i].total );
}
void outputfile(struct student m[10]) {
	char sel, ch[60];
	FILE *fp;
	int i, j;

	sc(m);
	getchar();
	printf("要把数据写入到文件里面吗？(Y/N)\n");

	scanf("%c", &sel);
	if (sel == 'Y' || sel == 'y') { //交互界面
		printf("请输入文件的路径\n");
		scanf("%s", &ch);


		if ((fp = fopen(ch, "w")) == NULL) { //只写方式打开文件
			printf("打开文件错误！");
			return;
		}

		else {
			for (i = 0; i < d; i++) {
				fprintf(fp, "%s %d", m[i].NAME, m[i].num);
				for (j = 0; j < 5; j++) { //成绩循环
					fprintf(fp, "%f %f %f %f", m[i].chinese, m[i].math, m[i].english, m[i].computer);
				}
			}
			printf("恭喜你，数据写入成功！可以到 %s 查看学生成绩\n", ch);
			fclose(fp);
		}
	} else if (sel == 'N' || sel == 'n') {
		return;
	} else {
		printf("你输的不对！\n");
	}
}
void cx(struct student m[10]) { //按照学号查询
	int i, n;
	int j = 0; //信号
	printf("请输入你需要查询的学号：");
	scanf("%d", &n);
	for (i = 0; i < d; i++) {
		if (n == m[i].num) {
			printf("学号:%d    姓名:%s  数学:%.2f  英语:%.2f  计算机:%.2f  \n总成绩:%.2f  \n", m[i].num, m[i].NAME, m[i].math, m[i].english, m[i].computer, m[i].total);
			j++;
		}
	}
	if (j == 0) {
		printf("没有这个学生哦！\n");
	}
}

void pl(struct student* p) { //成绩高到低排名
	int i, j;
	for (i = 0; i < d - 1; i++) {
		for (j = i + 1; j < d; j++) {
			if ((*(p + i)).total < (*(p + j)).total) { //按总成绩排序
				*(p + d) = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = *(p + d);
			}
		}
	}
	for (i = 0; i < d; i++)
		printf("学号:%d    姓名:%s  数学:%.2f  英语:%.2f  计算机:%.2f  \n总成绩:%.2f  \n", (*(p + i)).num, (*(p + i)).NAME, (*(p + i)).chinese, (*(p + i)).math, (*(p + i)).english, (*(p + i)).computer, (*(p + i)).total);
}
void add(struct student* p) { //添加学生
	d++;
	printf("请输入姓名:");
	scanf("%s", (*(p + d - 1)).NAME);
	printf("请输入学号:");
	scanf("%d", &(*(p + d - 1)).num);
	printf("请输入语文成绩:");
	scanf("%f", &(*(p + d - 1)).chinese);
	printf("请输入数学成绩:");
	scanf("%f", &(*(p + d - 1)).math);
	printf("请输入英语成绩:");
	scanf("%f", &(*(p + d - 1)).english);
	printf("请输入计算机成绩");
	scanf("%f", &(*(p + d - 1)).computer);
	(*(p + d - 1)).total = (*(p + d - 1)).computer + (*(p + d - 1)).english + (*(p + d - 1)).math;

}
void delete (struct student m[10]) { //删除学生
	int x, i;
	printf("输入删除学生的学号:");
	scanf("%d", &x);
	for (i = x; i < d; i++) {
		m[i] = m[i + 1];
	}
	d--;//总学生数要减少一个

}
void dayu(struct student m[10]) { //输出平均分大于80分
	int i, j = 0;
	for (i = 0; i < d; i++) {
		if (80 <( (m[i].total) / 4.0) ){
			printf("学号:%d    姓名:%s  数学:%.2f  英语:%.2f  计算机:%.2f  \n总成绩:%.2f  \n\n", m[i].num, m[i].NAME, m[i].chinese, m[i].math, m[i].english, m[i].computer, m[i].total);
			j++;
		}
	}
	if (j = 0) {
		printf("啊哦，没有");
	}

}
void main() { //主函数

	struct student m[10];
	int choice;
	do {
		printf("******欢迎使用学生成绩管理系统******\n");
		printf("      0.退出\n");
		printf("      1.学生基本信息录入\n");
		printf("      2.学生基本信息的输出\n");
		printf("      3.按照学号查询学生信息\n");
		printf("      4.按成绩总分由高到低排名\n");
		//printf("      5.按学号修改某学生信息并输出\n");
		printf("      5.删除某学生信息\n");
		printf("      6.添加某学生信息\n");
		printf("      7.输出平均分大于80分的同学信息\n");
		printf("---------------------------------------\n");
		printf("请输入你的操作:");
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
