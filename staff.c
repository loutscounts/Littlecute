#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h> 


#define SIZE 30     //ְ�����鳤��
char staff[SIZE][SIZE]={"001+123abc#13805034689","002+666abc#13805634689","003+888888#13505034689","004+567123#13705034689"};//ְ������

/*******************���ܺ�������*****************************/
/**************************************
��������˵������ӡ���˵�
�β�˵����void
����ֵ��void
**************************************/
void menu();

/**************************************
��������˵����ע��ְ����Ϣ
�β�˵����void
����ֵ��void
**************************************/
void registerInfo();

/**************************************
��������˵������¼�˵�
�β�˵����void
����ֵ��void
**************************************/
void logInMenu();

/**************************************
��������˵������ʾ����ְ������
�β�˵����void
����ֵ��void
**************************************/
void display();

/**************************************
��������˵�����õ�����
�β�˵����
        id:ְ����
        index:�ַ������ڵ����
����ֵ��void
**************************************/

void getID(char *id, int index);

/**************************************
��������˵�����õ�����
�β�˵����
        password:����
        index:�ַ������ڵ����
����ֵ��void
**************************************/
void getPassword(char *password, int index); 

/**************************************
��������˵�����õ��ֻ���
�β�˵����
        num:�ֻ���
        index:�ַ������ڵ����
����ֵ��void
**************************************/
void getNum(char *num, int index);

/**************************************
��������˵�����жϹ����Ƿ����
�β�˵����id:ְ����
����ֵ��ְ���Ŵ��ڷ���1,�����ڷ���0
**************************************/
int isIDexist(char *id);

/**************************************
��������˵�����ж��ֻ����Ƿ����
�β�˵����num:�ֻ���
����ֵ���ֻ��Ŵ��ڷ���1,�����ڷ���0
**************************************/
int isNumExist(char *num);

/**************************************
��������˵������¼ϵͳ
�β�˵����void
����ֵ��void
**************************************/
void login();

/**************************************
��������˵������������
�β�˵����void
����ֵ��void
**************************************/
void forgetPassword();

/**************************************
��������˵����ͨ��id�õ�����
�β�˵����
        id:ְ����
        password:��Ӧ������,û�ҵ�����"";
����ֵ��void
**************************************/
void getPasswordById(char *id, char *password);

/**************************************
��������˵����ͨ��id�õ��ֻ���
�β�˵����
        id:ְ����
        num:���ص��ֻ���,û�ҵ�����"";
����ֵ��void
**************************************/
void getNumById(char *id, char *num);//

/**************************************
��������˵�����жϹ����Ƿ���ȷ
�β�˵����id,ְ�����ַ���
����ֵ��int��,1��ʾ����,0��ʾ������
**************************************/
int isIdRight(char *id);

/**************************************
��������˵�����ж������Ƿ���ȷ
�β�˵����char *����������ַ���
����ֵ��int��,1��ʾ����,0��ʾ������
**************************************/
int isPasswordRight(char *password);

/**************************************
��������˵�����õ�ϵͳ��ְ����Ϣ����
�β�˵����void
����ֵ��int��,��ʾϵͳ���Ѵ��ڵ�ְ����
**************************************/
int getsize();

/*******************����ʵ��******************************/

//������
void main()
{
    int n,f;
    //�ж����������
	while(1)
	{
		do {
			menu(); //���ò˵�����
			scanf("%d", &n);
			if (n >= 0 && n <= 3)
            {          
				f = 1;
                break;
			}
			else 
            {
				f = 0; 
				printf("\n\t����������������ѡ��!");
                system("pause");
			}  
		}while(f == 0);
		switch(n)
        {
        case 0:
            system("cls");
            printf("\n\n\n\n\n\n\t\tThank you for using !\n\n\n\n\n\n");
            printf("\n");
            system("pause");
            exit(0);
            break;
        case 1:   
            printf("\n");
            registerInfo();
            printf("\n");
            system("pause");
            break;
        case 2: 
            printf("\n");
            logInMenu();
            printf("\n");
            system("pause");
            break;
        case 3:   
            printf("\n");
            printf("\t\t��ʾ����ְ����Ϣ\n");
            display();
            printf("\n");
            system("pause");
            break;
			}
	}
}
 
//��������
 
void menu()   /*�˵�����*/
{
    system("cls");
	printf("\n\n");
	printf("         ��Ŀ��:ְ��ע�����¼����ϵͳ                         \n");
    //printf("            Designed by HuangX                               \n");
    printf("\n");
	printf("         1.ְ��ע��                                           \n");
	printf("         2.ְ����¼                                           \n");
    printf("         3.��ʾ����ְ����Ϣ                                    \n");
    printf("         0.�˳�                                               \n");
	printf("         ��ѡ��: ");
}

//�жϹ��������Ƿ���ȷ
int isIdRight(char *id)
{
    int i = 0;
    if (strlen(id) != 3)
    {
        printf("\t����Ĺ��Ų��Ϲ�\n");
        return 0;
    }
    for (i = 0; i < 3; i++)
    {
        if (!(id[i] >= '0' && id[i] <= '9'))
        {
            printf("\t����Ĺ��Ų��Ϲ�\n");
            return 0;
        }
    }
    printf("\t����Ĺ��źϹ�\n");
    return 1;
}

int isPasswordRight(char *password)
{
    int len = (int)strlen(password);
    int i;
    if (len > 6 || len < 1)
    {
        printf("\t��������벻�Ϲ�\n");
        return 0;
    }
    for (i = 0; i < len; i++)
    {
        if (!(password[i] >='0' && password[i]<='9') && !(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= 'A' && password[i] <= 'Z'))
        {
            printf("\t��������벻�Ϲ�\n");
            return 0;
        }
    }
    printf("\t���������Ϲ�\n");
    return 1;
}

int isNumRight(char *num)
{
    int i;
    if (num[0] != '1')
    {
        printf("\t������ֻ��Ų��Ϲ�\n");
        return 0;
    }
    if (strlen(num) != 11)
    {
        printf("\t������ֻ��Ų��Ϲ�\n");
        return 0;
    }

    for (i = 0; i < 11; i++)
    {
        if (!(num[i] >='0' && num[i]<='9'))
        {
            printf("\t������ֻ��Ų��Ϲ�\n");
            return 0;
        }
    }
    printf("\t������ֻ��źϹ�\n");
    return 1;
}

int getsize()
{
    int sum = 0;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (strlen(staff[i]) > 0)
        {
            sum ++;
        }
    }
    return sum;
}

void getID(char *id, int index)
{
    int i = 0;
    while(staff[index][i] != '+')
    {
        id[i] = staff[index][i];
        i++;
    }
    id[i] = '\0';
}

//����ӵ������ʼ
void getpassword(char *password, int index)
{
    int i;
    for (i = 4; i < 10; i++)
    {
        if(staff[index][i] != '#')
        {
            password[i-4] = staff[index][i];
        }
        else
        {
            password[i] = '\0';
            return;
        }
    }
}

//�ֻ���ȡ���11λ
void getnum(char *num, int index)
{
    int i;
    for (i = 0; i < 11; i ++)
    {
        num[i] = staff[index][strlen(staff[index]) - 11 + i];
    }
    num[i] = '\0';
}


void getPasswordById(char *id, char *password)
{
    if (getsize() > 0)
    {
        int i;
        for(i = 0; i < getsize(); i++)
        {
            char a[4] = {0};
            getID(a, i);
            if (strcmp(a, id) == 0)
            {
                getpassword(password, i);
            }
        }
    }
}

void getNumById(char *id, char *num)
{
    if (getsize() > 0)
    {
        int i;
        for(i = 0; i < getsize(); i++)
        {
            char a[4] = {0};
            getID(a, i);
            if (strcmp(a, id) == 0)
            {
                getnum(num, i);
            }
        }
    }
}

int isIDexist(char *id)
{
    int flag = 0;
    if (getsize() > 0)
    {
        int i;
        for(i = 0; i < getsize(); i++)
        {
            char a[4] = {0};
            getID(a, i);
            if (strcmp(a, id) == 0)
            {
                printf("\t  �����Ѵ���");
                flag = 1;
            }
        }
    }
    return flag;
}

int isNumExist(char *num)
{
    int size = getsize();
    if (size > 0)
    {
        int i = 0;
        for(i = 0; i < size; i++)
        {
            char b[12] = {0};
            getnum(b, i);
            if (strcmp(b, num) == 0)
            {
                printf("\t  �ֻ����Ѵ���");
                return 1;
            }
        }
    }
    return 0;
}

void registerInfo()   /*ע�ắ��*/
{
    char id[20];//����
    char password[20];//����
    char num[20];//�ֻ���
    int size = 0;
    char stafftemp[30] = {0};
    while(1)
    {

        size = getsize();
        printf("\t�밴001+xxxxxx#13811112222��ʽ����ע����Ϣ\n");
        printf("\t1.�����빤��(��λ�����ַ�):");
        scanf("%s", id);
        while (!isIdRight(id) || isIDexist(id))
        {
            printf("\n\t���������빤��:");
            scanf("%s", id);
        }
        printf("\n\t2.��������λ����(ֻ�ܰ������ֻ��ַ�):");
        scanf("%s", password);
        while (!isPasswordRight(password))
        {
            printf("\t��������������:");
            scanf("%s", id);
        }
        printf("\n\t3.�������ֻ���(11λ�����ַ�):");
        scanf("%s", num);
        while (!isNumRight(num) || isNumExist(num))
        {
            printf("\n\t�����������ֻ���:");
            scanf("%s", num);
        }
        break;
    }

    //ְ���ַ�������
    strcat(stafftemp, id);
    strcat(stafftemp, "+");
    strcat(stafftemp, password);
    strcat(stafftemp, "#");
    strcat(stafftemp, num);

    //�ж�ϵͳ�Ƿ�����
    if (size >= 30)
    {
        printf("\n\tע��ϵͳ����, ����ϵ����Ա\n");
        return;
    }
    //д��ϵͳ
    strcpy(staff[size], stafftemp);
    printf("\n");
    printf("\n\tһ����ְ������Ϣ������ϣ�\n\n");
    return;

} 

void login()
{
    char id[10] = {0};
    char password[10] = {0};
    char passwordIn[10] = {0};//�Ѿ����������������

    int i = 0;
    int j  = 0;
    //�����������
    while (i <= 2 && j <= 2)
    {
        printf("\n\t  ����ְ����:");
        scanf("%s", id);
        if (!isIDexist(id))
        {
            printf("\n\t  ְ���Ų�����,����ְ����:");
            i++;
            continue;
        }

        printf("\n\t  ��������:");
        scanf("%s", password);
        getPasswordById(id, passwordIn);
        if (strcmp(password, passwordIn) == 0)
        {
            printf("\n\t  ��¼�ɹ�!��ӭʹ�ñ�ϵͳ!!\n");
            break;
        }
        else
        {
            printf("\n\t  �����������,�����µ�¼!!\n");
        }
        j ++;
    }
    if(i == 3 || j == 3)
    {
        printf("\n\t  �����������,���ѱ���ֹ����\n");
    }
}

void forgetPassword()
{
    char id[10];
    char num[20];   //������ֻ�����
    char numIn[20]; //ϵͳ�е��ֻ�����
    char password[10];
    char stafftemp[SIZE] = {0};
    printf("\n\t  ����ְ����:");
    scanf("%s", id);
    if(!isIDexist(id))
    {
        printf("\n\t  ְ���Ų�����,��������ʧ��");
        return;
    }
    else
    {
        printf("\n\t  �����ֻ���:");
        scanf("%s", num);
        getNumById(id, numIn);
        if (strcmp(numIn, num) != 0)
        {
            printf("\n\t  �ֻ��Ų�����,��������ʧ��");
            return;
        }
    }
    printf("\n\t  ����������!");
    while (1)
    {
        int i = 0;
        char tempId[10];
        printf("\n\t  ����������:");
        scanf("%s", password);
        if (isPasswordRight(password))
        {
            strcat(stafftemp, id);
            strcat(stafftemp, "+");
            strcat(stafftemp, password);
            strcat(stafftemp, "#");
            strcat(stafftemp, num);
            //�ҵ���id���±�
            for(i; i<SIZE; i++)
            {
                getID(tempId, i);
                if(strcmp(id, tempId) == 0)
                {
                    strcpy(staff[i], stafftemp);
                    printf("\n\t  ��������ɹ�.");
                    return;
                }
            }
            break;
        }
    }

}

void logInMenu()
{
    int n,f;
	while(1)
	{
		do {
            system("cls");
            printf("\n");
            printf("\n");
            printf("\t  1.��¼                      2.��������\n\t  0.�˳���¼\n");
            printf("\t  ��ѡ��:");
			scanf("%d", &n);
			if(n >= 0 && n <= 2)
            {
				f=1;
                break;
			}             
			else {
				f=0; 
				printf("\n\t\t����������������ѡ��!");
			}  
		}while(f==0);
		switch(n)
        {
        case 0:
            printf("\n");
            system("pause");
            return;
        case 1:   
            printf("\n");
            login();
            printf("\n");
            system("pause");
            break;
        case 2: 
            printf("\n");
            forgetPassword();
            printf("\n");
            system("pause");
            break;
			}
	}

}

void display()  /*��ʾ����*/
{
    int size = getsize();
    char id[4] = {0};
    char password[7] = {0};
    char num[12] = {0};
    int i,j;

    printf("\n\tְ��������Ϊ:%d", size);
    printf("\n\t����\t����\t�ֻ���\n");
    for (i = 0; i < size; i++)
    {
        getID(id, i);
        getnum(num, i);
        //��ʾʱ������*����
        for(j = 0; j < 6; j++)
        {
            password[j] = '*';
        }
        printf("\t%3s\t%s\t%11s\n", id, password, num);
    }
} 

