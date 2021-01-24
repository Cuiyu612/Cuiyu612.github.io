#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>
void menu()
{
	system("cls");
    printf("\n\n\n");
    printf("\t|    #####                                                           ^ ^          |\n");
    printf("\t|  ########               study!        study!     study!          @  ~~  @       |\n");
    printf("\t|  ####    *   *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *      |\n");
    printf("\t|   ###$$$                                                                        |\n");
    printf("\t|                      西安邮电大学学生管理系统                                   |\n");
    printf("\t|                                                                                 |\n");
    printf("\t|                                                                                 |\n");
    printf("\t|                            0.退出系统                                           |\n ");
    printf("\t|                            1.登录                                               |\n");
    printf("\t|                            2.用户注册                                           |\n");
    printf("\t|                            3.创建学生表                                         |\n");
    printf("\t|                            4.查询信息                                           |\n");
    printf("\t|                            5.添加信息                                           |\n");
    printf("\t|                            6.修改信息                                           |\n");
    printf("\t|                            7.删除信息                                           |\n");
    printf("\t|                            8.打印学生信息                                       |\n");
    printf("\t|                            9.保存学生信息                                       |\n");
    printf("\t|      @   @                                                                      |\n");
    printf("\t|  、、  ^    、、                                                     ###        |\n");
    printf("\t|   ***********                                                       #@##@#      |\n");
    printf("\t|  *  *  *  *  *  *  *  *————————————*  *  *  *  *   *    ##~~##      |\n");
    printf("\t|                                                                     ######      |\n");
    printf("\t|                                                                                 |\n");
    printf("\t|                                choose(0-9):                                      \n");
}

int ver(char ch1[11])//验证账号是否被注册过；
{
	FILE *fp;
	int g=0;
	char a[11];
	if((fp=fopen("F:\\users.txt","rb"))==NULL)
	{
		printf("文件打开失败\n");
	}
	while(feof(fp)==0)//判断账户是否已经存在 
	{
		fread(a,10*sizeof(char),1,fp);
		a[10]='\0';
		if(strcmp(a,ch1)==0)
		g=1;
	}
	fclose(fp);
	if(g==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
 } 
 
void create()
{
	system("cls");
	FILE *fp;
	char ch1[11],ch2[11],ch3[11];
	int i,k=0,h=0,g=0,n;
	
	if((fp=fopen("F:\\users.txt","ab"))==NULL)
	{
		printf("文件打开失败\n");
	}
	printf("**********************     注册      **********************\n\n\n");
	do
	{
		printf("账号和密码均为10位\n");
		printf("密码只能含有数字和字母\n"); 
		printf("请输入账号:\n");
		for(i=0;i<10;i++)
		{
			ch1[i]=getch();//getch()的功能是从控制台读取一个字符，但是不显示在屏幕上，函数自动读取； 
			printf("%c",ch1[i]);
		}
		ch1[10]='\0';
		if(ver(ch1)==0)
		{
			h=1;
			fwrite(ch1,10*sizeof(char),1,fp);
		}
		else
		{
			printf("账号已经被注册，请重新输入账号\n");
		}
	}while(h==0);
	putchar(10);//具有换行的作用，'\n'的ascll 码为10；
	do{
		do{
			n=0;
			g=0;
			printf("请输入密码:\n");
			for(i=0;i<10;i++)
			{
				ch2[i]=getch();
				printf("*");
			}
			ch2[10]='\0';
			for(i=0;ch2[i];i++)
			{
				if(isalpha(ch2[i]))
                g=1;
                if(!(('1'<=ch2[i] && ch2[i]<='9') ||( 'a'<=ch2[i] && 'z'>=ch2[i]) || ('A'<=ch2[i] && 'Z'>=ch2[i])))
                {
                	printf("密码只能包含数字和字母\n");
                	n=1;
                	break;
				}
			}
			if(g==0 && n==0)
			{
				printf("密码至少含有一个字母\n");
				}	
		}while(g==0);
		putchar(10);
		printf("再次输入密码:\n");
		for(i=0;i<10;i++)
		{
			ch3[i]=getch();
			printf("*");
		 } 
		 ch3[10]='\0';
		 putchar(10);
		 if(strcmp(ch2,ch3)==0)
		 {
		 	k=1;
		 	fwrite(ch2,10*sizeof(char),1,fp);
		 }
		 else
		 {
		 	printf("两次密码不一致\n");
		 }
	} while(k==0);
	fclose(fp);
    printf("注册成功！\n");
	system("pause");
	return;
}

int password(char ch1[11],char ch2[11])//验证账户是否正确； 
{
	FILE *fp;
	int g=0,k=0,h=0;
	char a[11],b[11];
	if((fp=fopen("F:\\users.txt","rb"))==NULL)
	{
		printf("打开文件失败\n");
	}
	while(g==0 && feof(fp)==0)
	{
		fread(a,10*sizeof(char),1,fp);
		a[10]='\0';
		if(strcmp(a,ch1)==0)
		{
			fread(b,10*sizeof(char),1,fp);
			b[10]='\0';
			if(strcmp(b,ch2)==0)
			h=1;
			g=1;
		}
	}
	fclose(fp);
	if(g==1 && h==1)
	return 1;
	else
	return 0;
}
void entry()
{
	system("cls");
	int i,k=0;
	char ch1[11],ch2[11];
	printf("**********************     登录      **********************\n\n\n");
	do
	{
		
		printf("账号:\n");
		for(i=0;i<10;i++)
		{
			ch1[i]=getch();
			printf("%c",ch1[i]);
		}
		printf("\n");
		ch1[10]='\0';
		printf("密码:\n");
		for(i=0;i<10;i++)
		{
			ch2[i]=getch();
			printf("*");
		}
		printf("\n");
		ch2[10]='\0';
		if(password(ch1,ch2)==1)
		k=1;
		else
		{
			printf("账户错误或者密码错误，请重新登录\n");
		 } 
	}while(k==0);
	printf("登录成功\n");
    system("pause");
	return;
}
int count;
typedef struct Message{
	char name[20];
	char subject[20];
	int number;
	int score;
}message; 

struct Student{
	message stu;
	struct Student*pnext;
};

struct Student*manage()
{
	system("cls");
	struct Student*phead=NULL;
	struct Student*pend,*pnew;
	count=0;
	pend = pnew=(struct Student*)malloc(sizeof(struct Student));
	printf("\t**********************     创建信息      **********************\n\n\n");
	printf("\t\t请输入学生的姓名,学号，科目，成绩\n");
	printf("\t    姓名            学号           科目           成绩\n ");
	printf("\t例：qwqw             01            math            100  \n");
	printf("结束录入需填:exit             0            other            00\n"); 
	scanf("%s",&pnew->stu.name);
	scanf("%d",&pnew->stu.number);
	scanf("%s",&pnew->stu.subject);
	scanf("%d",&pnew->stu.score);
	while(pnew->stu.number!=0)
	{
		count++;
		if(count==1)
		{
			pnew->pnext=phead;
			pend=pnew;
			phead=pnew;
		}
		else
		{
			pnew->pnext=NULL;
			pend->pnext=pnew;
			pend=pnew;
		}
		pnew=(struct Student*)malloc(sizeof(struct Student));
		scanf("%s",&pnew->stu.name);
		scanf("%d",&pnew->stu.number);
		scanf("%s",&pnew->stu.subject);
		scanf("%d",&pnew->stu.score);
	}
	free(pnew);
	system("pause");
	return phead;

}
void print(struct Student*phead)//打印 
{
	system("cls");
	struct Student*ptemp;
	int ilndex=1;
	ptemp=phead;
	while(ptemp!=NULL)
	{
		printf("**********************     信息结果展示      **********************\n\n\n");
		printf("the NO:%d member is:\n",ilndex );
		printf("学生的姓名为: %s\n",ptemp->stu.name);
		printf("学生的学号为: %d\n",ptemp->stu.number);
		printf("学生的科目为:%s\n",ptemp->stu.subject);
		printf("学生的成绩为:%d\n",ptemp->stu.score);
		ptemp=ptemp->pnext;
		ilndex++;
	}
	system("pause");
}
struct Student*insert(struct Student*phead)
{
	system("cls");
	struct Student*pnew;
	pnew=(struct Student*)malloc(sizeof(struct Student));
	printf("**********************     增加学生      **********************\n\n\n");
	printf("请输入学生的姓名:\n");
	scanf("%s",&pnew->stu.name);
	printf("请输入学生的学号:\n");
	scanf("%d",&pnew->stu.number);
	printf("请输入科目的名称:\n");
	scanf("%s",&pnew->stu.subject);
	printf("请输入科目的成绩:\n");
	scanf("%d",&pnew->stu.score);
	
	pnew->pnext=phead;
	phead=pnew;
	count++;
	system("pause");
	return phead;
}

void change(struct Student*phead,int xuehao )
{
	system("cls");
	int n,i;
	struct Student*p;
	p=phead;//得到头节点；
	if(p==NULL)
	{
		printf("输入错误\n");//链表为空； 
	 } 
	 else
	 {
	 	printf("**********************     修改信息      **********************\n\n\n");
	 	printf("你要修改的学生信息的学号\n");
	 	scanf("%d",&n);
	 	for(i=0;i<count;i++)
	 	{
	 		p=p->pnext;
	 		if(p->stu.number==n)
	 		{
	 			printf("查找成功\n");
	 			printf("姓名修改为:\n");
	 			scanf("%s",&p->stu.name);
	 			printf("学号修改为:\n");
	 			scanf("%d",&p->stu.number);
	 			printf("科目修改为:\n");
	 			scanf("%s",&p->stu.subject);
	 			printf("成绩修改为:\n");
	 			scanf("%d",&p->stu.score);
	 			printf("修改成功\n");
	 			break;
			 }
			 else{
			 	printf("学号输入有误，无法找到该学生\n");
			 }
		 }
	 }
	system("pause");
}


void search(struct Student*phead,int xuehao) //根据学号查找学生的相关信息 
{
	system("cls");
	int n;
	printf("**********************     查询信息      **********************\n\n\n");
	printf("请输入查找学生学号：");
	scanf("%d", &n);
	struct Student*p;
	p=phead;
	if(phead != NULL)
	{
		while(p != NULL)
		{
			if(p->stu.number==n)
			{
		    	printf("该学生的姓名为: %s\n",p->stu.name);
		    	printf("该学生的科目为: %s\n",p->stu.subject);
		    	printf("该学生的成绩为: %d \n",p->stu.score);
		    	break;
		    }
			p = p->pnext;
		}
	}
	system("pause");
}
void Delete(struct Student*phead,int xuehao)
{
	system("cls");
	int n;//学生的学号； 
	printf("**********************     删除信息      **********************\n\n\n");
	printf("请输入需删除的学生的学号:\n");
	scanf("%d",&n);
	struct Student*pre;
	struct Student*temp;
	temp=phead;
	pre=temp;
	if(phead==NULL)
	{
		printf("输入错误\n");//链表为空； 
	}
	if(phead->stu.number==n)//不可用strcmp函数，strcmp函数比较的是字符串； 
	{
		temp=phead;
		phead=phead->pnext;
		free(temp);
		count--;
		printf("删除成功!\n");
	}//表示删除的是头节点；
	else{
		pre=phead;
		temp=phead->pnext;//临时节点；temp非空 
		while (temp) {
            if (temp->stu.number== n) {
                pre->pnext = temp->pnext;
                free(temp);
                count--;
                break;
            }
            temp = temp->pnext;
            pre = pre->pnext;
	      } //中间的节点；
		  printf("删除成功!\n"); 
    } 
    if(!temp)
	printf("学号输入有误，无法找到该学生\n"); 
	system("pause");
 } 
 void save()//用文件保存学生的信息
 {
 	struct Student*phead=NULL;
 	FILE*fp;
 	fp=fopen("F:\\student.txt","w");
 	if(fp==NULL)
 	{
 		printf("打开文件失败\n");
 		return;
	 }
	 struct Student*p=phead;
	 while(p!=NULL)
	 {
	 	fprintf(fp,"*\t%s\t*\t%d\t*\t%s\t*\t%d\t*\n",p->stu.name,p->stu.number,p->stu.subject,p->stu.score);
	 	p=p->pnext;
	 }
	 fclose(fp);
	 printf("数据保存成功\n");
	 system("pause");
	 system("cls");
 }
 
int main()
{
	int xuehao;
	int n;
	struct Student*phead;
	menu();
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{
			case 0:
				system("cls");
				printf("退出系统\n");
				break;
			case 1:
				entry();
				break;
			case 2:
				create();
				break;
			case 3: 
				phead=manage();//创建；
				break; 
			case 4:
				search(phead,xuehao);//搜索 
				break;
			case 5:
				phead=insert(phead);//插入 
				break;
			case 6:
				change(phead,xuehao);//修改 
				break;
		    case 7:
			    Delete(phead,xuehao);//删除 
				break;
			case 8:
				print(phead);
				break;
			case 9:
				save();//将学生的信息保存在文件中；
				break; 
			default:
				system("cls");
				printf("输入错误，请重新输入\n");
				system("pause");
			break;	
		}
		menu();
		scanf("%d",&n);
    }
}//要将函数的创建放在前面，不会出现隐式声明和类型冲突的问题。 
