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
    printf("\t|                      �����ʵ��ѧѧ������ϵͳ                                   |\n");
    printf("\t|                                                                                 |\n");
    printf("\t|                                                                                 |\n");
    printf("\t|                            0.�˳�ϵͳ                                           |\n ");
    printf("\t|                            1.��¼                                               |\n");
    printf("\t|                            2.�û�ע��                                           |\n");
    printf("\t|                            3.����ѧ����                                         |\n");
    printf("\t|                            4.��ѯ��Ϣ                                           |\n");
    printf("\t|                            5.�����Ϣ                                           |\n");
    printf("\t|                            6.�޸���Ϣ                                           |\n");
    printf("\t|                            7.ɾ����Ϣ                                           |\n");
    printf("\t|                            8.��ӡѧ����Ϣ                                       |\n");
    printf("\t|                            9.����ѧ����Ϣ                                       |\n");
    printf("\t|      @   @                                                                      |\n");
    printf("\t|  ����  ^    ����                                                     ###        |\n");
    printf("\t|   ***********                                                       #@##@#      |\n");
    printf("\t|  *  *  *  *  *  *  *  *������������������������*  *  *  *  *   *    ##~~##      |\n");
    printf("\t|                                                                     ######      |\n");
    printf("\t|                                                                                 |\n");
    printf("\t|                                choose(0-9):                                      \n");
}

int ver(char ch1[11])//��֤�˺��Ƿ�ע�����
{
	FILE *fp;
	int g=0;
	char a[11];
	if((fp=fopen("F:\\users.txt","rb"))==NULL)
	{
		printf("�ļ���ʧ��\n");
	}
	while(feof(fp)==0)//�ж��˻��Ƿ��Ѿ����� 
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
		printf("�ļ���ʧ��\n");
	}
	printf("**********************     ע��      **********************\n\n\n");
	do
	{
		printf("�˺ź������Ϊ10λ\n");
		printf("����ֻ�ܺ������ֺ���ĸ\n"); 
		printf("�������˺�:\n");
		for(i=0;i<10;i++)
		{
			ch1[i]=getch();//getch()�Ĺ����Ǵӿ���̨��ȡһ���ַ������ǲ���ʾ����Ļ�ϣ������Զ���ȡ�� 
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
			printf("�˺��Ѿ���ע�ᣬ�����������˺�\n");
		}
	}while(h==0);
	putchar(10);//���л��е����ã�'\n'��ascll ��Ϊ10��
	do{
		do{
			n=0;
			g=0;
			printf("����������:\n");
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
                	printf("����ֻ�ܰ������ֺ���ĸ\n");
                	n=1;
                	break;
				}
			}
			if(g==0 && n==0)
			{
				printf("�������ٺ���һ����ĸ\n");
				}	
		}while(g==0);
		putchar(10);
		printf("�ٴ���������:\n");
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
		 	printf("�������벻һ��\n");
		 }
	} while(k==0);
	fclose(fp);
    printf("ע��ɹ���\n");
	system("pause");
	return;
}

int password(char ch1[11],char ch2[11])//��֤�˻��Ƿ���ȷ�� 
{
	FILE *fp;
	int g=0,k=0,h=0;
	char a[11],b[11];
	if((fp=fopen("F:\\users.txt","rb"))==NULL)
	{
		printf("���ļ�ʧ��\n");
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
	printf("**********************     ��¼      **********************\n\n\n");
	do
	{
		
		printf("�˺�:\n");
		for(i=0;i<10;i++)
		{
			ch1[i]=getch();
			printf("%c",ch1[i]);
		}
		printf("\n");
		ch1[10]='\0';
		printf("����:\n");
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
			printf("�˻��������������������µ�¼\n");
		 } 
	}while(k==0);
	printf("��¼�ɹ�\n");
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
	printf("\t**********************     ������Ϣ      **********************\n\n\n");
	printf("\t\t������ѧ��������,ѧ�ţ���Ŀ���ɼ�\n");
	printf("\t    ����            ѧ��           ��Ŀ           �ɼ�\n ");
	printf("\t����qwqw             01            math            100  \n");
	printf("����¼������:exit             0            other            00\n"); 
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
void print(struct Student*phead)//��ӡ 
{
	system("cls");
	struct Student*ptemp;
	int ilndex=1;
	ptemp=phead;
	while(ptemp!=NULL)
	{
		printf("**********************     ��Ϣ���չʾ      **********************\n\n\n");
		printf("the NO:%d member is:\n",ilndex );
		printf("ѧ��������Ϊ: %s\n",ptemp->stu.name);
		printf("ѧ����ѧ��Ϊ: %d\n",ptemp->stu.number);
		printf("ѧ���Ŀ�ĿΪ:%s\n",ptemp->stu.subject);
		printf("ѧ���ĳɼ�Ϊ:%d\n",ptemp->stu.score);
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
	printf("**********************     ����ѧ��      **********************\n\n\n");
	printf("������ѧ��������:\n");
	scanf("%s",&pnew->stu.name);
	printf("������ѧ����ѧ��:\n");
	scanf("%d",&pnew->stu.number);
	printf("�������Ŀ������:\n");
	scanf("%s",&pnew->stu.subject);
	printf("�������Ŀ�ĳɼ�:\n");
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
	p=phead;//�õ�ͷ�ڵ㣻
	if(p==NULL)
	{
		printf("�������\n");//����Ϊ�գ� 
	 } 
	 else
	 {
	 	printf("**********************     �޸���Ϣ      **********************\n\n\n");
	 	printf("��Ҫ�޸ĵ�ѧ����Ϣ��ѧ��\n");
	 	scanf("%d",&n);
	 	for(i=0;i<count;i++)
	 	{
	 		p=p->pnext;
	 		if(p->stu.number==n)
	 		{
	 			printf("���ҳɹ�\n");
	 			printf("�����޸�Ϊ:\n");
	 			scanf("%s",&p->stu.name);
	 			printf("ѧ���޸�Ϊ:\n");
	 			scanf("%d",&p->stu.number);
	 			printf("��Ŀ�޸�Ϊ:\n");
	 			scanf("%s",&p->stu.subject);
	 			printf("�ɼ��޸�Ϊ:\n");
	 			scanf("%d",&p->stu.score);
	 			printf("�޸ĳɹ�\n");
	 			break;
			 }
			 else{
			 	printf("ѧ�����������޷��ҵ���ѧ��\n");
			 }
		 }
	 }
	system("pause");
}


void search(struct Student*phead,int xuehao) //����ѧ�Ų���ѧ���������Ϣ 
{
	system("cls");
	int n;
	printf("**********************     ��ѯ��Ϣ      **********************\n\n\n");
	printf("���������ѧ��ѧ�ţ�");
	scanf("%d", &n);
	struct Student*p;
	p=phead;
	if(phead != NULL)
	{
		while(p != NULL)
		{
			if(p->stu.number==n)
			{
		    	printf("��ѧ��������Ϊ: %s\n",p->stu.name);
		    	printf("��ѧ���Ŀ�ĿΪ: %s\n",p->stu.subject);
		    	printf("��ѧ���ĳɼ�Ϊ: %d \n",p->stu.score);
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
	int n;//ѧ����ѧ�ţ� 
	printf("**********************     ɾ����Ϣ      **********************\n\n\n");
	printf("��������ɾ����ѧ����ѧ��:\n");
	scanf("%d",&n);
	struct Student*pre;
	struct Student*temp;
	temp=phead;
	pre=temp;
	if(phead==NULL)
	{
		printf("�������\n");//����Ϊ�գ� 
	}
	if(phead->stu.number==n)//������strcmp������strcmp�����Ƚϵ����ַ����� 
	{
		temp=phead;
		phead=phead->pnext;
		free(temp);
		count--;
		printf("ɾ���ɹ�!\n");
	}//��ʾɾ������ͷ�ڵ㣻
	else{
		pre=phead;
		temp=phead->pnext;//��ʱ�ڵ㣻temp�ǿ� 
		while (temp) {
            if (temp->stu.number== n) {
                pre->pnext = temp->pnext;
                free(temp);
                count--;
                break;
            }
            temp = temp->pnext;
            pre = pre->pnext;
	      } //�м�Ľڵ㣻
		  printf("ɾ���ɹ�!\n"); 
    } 
    if(!temp)
	printf("ѧ�����������޷��ҵ���ѧ��\n"); 
	system("pause");
 } 
 void save()//���ļ�����ѧ������Ϣ
 {
 	struct Student*phead=NULL;
 	FILE*fp;
 	fp=fopen("F:\\student.txt","w");
 	if(fp==NULL)
 	{
 		printf("���ļ�ʧ��\n");
 		return;
	 }
	 struct Student*p=phead;
	 while(p!=NULL)
	 {
	 	fprintf(fp,"*\t%s\t*\t%d\t*\t%s\t*\t%d\t*\n",p->stu.name,p->stu.number,p->stu.subject,p->stu.score);
	 	p=p->pnext;
	 }
	 fclose(fp);
	 printf("���ݱ���ɹ�\n");
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
				printf("�˳�ϵͳ\n");
				break;
			case 1:
				entry();
				break;
			case 2:
				create();
				break;
			case 3: 
				phead=manage();//������
				break; 
			case 4:
				search(phead,xuehao);//���� 
				break;
			case 5:
				phead=insert(phead);//���� 
				break;
			case 6:
				change(phead,xuehao);//�޸� 
				break;
		    case 7:
			    Delete(phead,xuehao);//ɾ�� 
				break;
			case 8:
				print(phead);
				break;
			case 9:
				save();//��ѧ������Ϣ�������ļ��У�
				break; 
			default:
				system("cls");
				printf("�����������������\n");
				system("pause");
			break;	
		}
		menu();
		scanf("%d",&n);
    }
}//Ҫ�������Ĵ�������ǰ�棬���������ʽ���������ͳ�ͻ�����⡣ 
