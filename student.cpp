#include<string.h>
#include<stdio.h>
#define max 100
struct stu{
	char name[20];
	char no[20];
	int age;
	double sou;
	char phone[20];
};

struct stu s[max];

int count=0;

void keep(){
	FILE* fp = fopen("stu.txt", "wb");
	if (fp == NULL) {
		printf("worry");
		return;

	}
	fwrite(&count, sizeof(int), 1, fp);
	fwrite(s, sizeof(struct stu), count, fp);
	fclose(fp);
	printf("数据已保存");
}
void add()
{
    printf("请输入姓名：");
    scanf("%s", s[count].name);
    printf("请输入学号：");
    scanf("%s", s[count].no);
    printf("请输入年龄：");
    scanf("%d", &s[count].age);
    printf("请输入分数：");
    scanf("%lf", &s[count].sou);
    printf("请输入手机号：");
    scanf("%s", s[count].phone);
    count++;
    printf("添加成功！\n\n");
}
void manu() {
	printf("=============学生信息管理系统=============\n");
	printf("1.浏览信息\n");
	printf("2.通过学号查找学生\n");
	printf("3.添加信息\n");
	printf("4.修改信息\n");
	printf("5.删除信息\n");
	printf("6.保存\n");
	printf("7.主菜单\n");
	printf("8.退出程序\n");

}
void jiazai() {
	FILE* fp = fopen("stu.txt", "rb");
	if (fp == NULL) {
		printf("worry");
		return;
	}
	fread(&count, sizeof(int), 1, fp);
	fread(s, sizeof(struct stu), count, fp);
	fclose(fp);

}
void delet() {
	 char a[20];
	printf("请输入删除学生的学号\n");
	scanf("%s", a);
	for (int i = 0;i < count;i++) {
		if (strcmp(s[i].no,a)==0) {
			for (int y = i;y < count;y++) {
				s[y] = s[y + 1];
			}
		}
	}
	count--;
	printf("完成删除\n");
}
void change() {
	char b[20];
	printf("请输入改变学生的学号\n");
	scanf("%s", b);
	for (int i = 0;i < count;i++) {
		if (strcmp(s[i].no, b) == 0) {
			printf("名字:");
			scanf("%s", s[i].name);
			printf("学号:");
			scanf("%s", s[i].no);
			printf("年龄:");
			scanf("%d", &s[i].age);
			printf("分数:");
			scanf("%lf", &s[i].sou);
			printf("手机号:");
			scanf("%s", s[i].phone);

		}
	}
	printf("更改完成\n");
}
void look() {
	for (int i = 0;i < count;i++) {
		printf("名字：%s 学号：%s 年纪：%d 分数：%.2lf 手机号：%s\n", s[i].name, s[i].no, s[i].age, s[i].sou, s[i].phone);
	}
}
void find() {
	char c[20];
	printf("请输入需要查找的学生学号");
	scanf("%s", c);
	for (int i = 0;i < count;i++) {
		if (strcmp(s[i].no, c) == 0) {
			printf("名字：%s 学号：%s 年纪：%d 分数：%.2lf 手机号：%s\n", s[i].name, s[i].no, s[i].age, s[i].sou, s[i].phone);
		}
	}
}
int main() {
	int p;
	jiazai();
	manu();
	while(1){
	scanf("%d", &p);
	switch (p) {
	case 1:
		look();
		break;
	case 2:
		find();
		break;
	case 3:
		add();
		break;
	case 4:
		change();
		break;
	case 5:
		delet();
		break;
	case 6:
		keep();
		break;
	case 7:
		manu();
		break;
	case 8:
		return 0;
	}
}
}