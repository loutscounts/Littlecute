#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h> 


#define SIZE 30     //职工数组长度
char staff[SIZE][SIZE]={"001+123abc#13805034689","002+666abc#13805634689","003+888888#13505034689","004+567123#13705034689"};//职工数组

/*******************功能函数声明*****************************/
/**************************************
函数功能说明：打印主菜单
形参说明：void
返回值：void
**************************************/
void menu();

/**************************************
函数功能说明：注册职工信息
形参说明：void
返回值：void
**************************************/
void registerInfo();

/**************************************
函数功能说明：登录菜单
形参说明：void
返回值：void
**************************************/
void logInMenu();

/**************************************
函数功能说明：显示所有职工数据
形参说明：void
返回值：void
**************************************/
void display();

/**************************************
函数功能说明：得到工号
形参说明：
        id:职工号
        index:字符串所在的序号
返回值：void
**************************************/

void getID(char *id, int index);

/**************************************
函数功能说明：得到密码
形参说明：
        password:密码
        index:字符串所在的序号
返回值：void
**************************************/
void getPassword(char *password, int index); 

/**************************************
函数功能说明：得到手机号
形参说明：
        num:手机号
        index:字符串所在的序号
返回值：void
**************************************/
void getNum(char *num, int index);

/**************************************
函数功能说明：判断工号是否存在
形参说明：id:职工号
返回值：职工号存在返回1,不存在返回0
**************************************/
int isIDexist(char *id);

/**************************************
函数功能说明：判断手机号是否存在
形参说明：num:手机号
返回值：手机号存在返回1,不存在返回0
**************************************/
int isNumExist(char *num);

/**************************************
函数功能说明：登录系统
形参说明：void
返回值：void
**************************************/
void login();

/**************************************
函数功能说明：忘记密码
形参说明：void
返回值：void
**************************************/
void forgetPassword();

/**************************************
函数功能说明：通过id得到密码
形参说明：
        id:职工号
        password:对应的密码,没找到返回"";
返回值：void
**************************************/
void getPasswordById(char *id, char *password);

/**************************************
函数功能说明：通过id得到手机号
形参说明：
        id:职工号
        num:返回的手机号,没找到返回"";
返回值：void
**************************************/
void getNumById(char *id, char *num);//

/**************************************
函数功能说明：判断工号是否正确
形参说明：id,职工号字符串
返回值：int型,1表示存在,0表示不存在
**************************************/
int isIdRight(char *id);

/**************************************
函数功能说明：判断密码是否正确
形参说明：char *传入的密码字符串
返回值：int型,1表示存在,0表示不存在
**************************************/
int isPasswordRight(char *password);

/**************************************
函数功能说明：得到系统中职工信息数量
形参说明：void
返回值：int型,表示系统中已存在的职工数
**************************************/
int getsize();

/*******************函数实现******************************/

//主函数
void main()
{
    int n,f;
    //判断输入的数字
	while(1)
	{
		do {
			menu(); //调用菜单函数
			scanf("%d", &n);
			if (n >= 0 && n <= 3)
            {          
				f = 1;
                break;
			}
			else 
            {
				f = 0; 
				printf("\n\t您输入有误，请重新选择!");
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
            printf("\t\t显示所有职工信息\n");
            display();
            printf("\n");
            system("pause");
            break;
			}
	}
}
 
//其他函数
 
void menu()   /*菜单函数*/
{
    system("cls");
	printf("\n\n");
	printf("         项目三:职工注册与登录管理系统                         \n");
    //printf("            Designed by HuangX                               \n");
    printf("\n");
	printf("         1.职工注册                                           \n");
	printf("         2.职工登录                                           \n");
    printf("         3.显示所有职工信息                                    \n");
    printf("         0.退出                                               \n");
	printf("         请选择: ");
}

//判断工号输入是否正确
int isIdRight(char *id)
{
    int i = 0;
    if (strlen(id) != 3)
    {
        printf("\t输入的工号不合规\n");
        return 0;
    }
    for (i = 0; i < 3; i++)
    {
        if (!(id[i] >= '0' && id[i] <= '9'))
        {
            printf("\t输入的工号不合规\n");
            return 0;
        }
    }
    printf("\t输入的工号合规\n");
    return 1;
}

int isPasswordRight(char *password)
{
    int len = (int)strlen(password);
    int i;
    if (len > 6 || len < 1)
    {
        printf("\t输入的密码不合规\n");
        return 0;
    }
    for (i = 0; i < len; i++)
    {
        if (!(password[i] >='0' && password[i]<='9') && !(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= 'A' && password[i] <= 'Z'))
        {
            printf("\t输入的密码不合规\n");
            return 0;
        }
    }
    printf("\t输入的密码合规\n");
    return 1;
}

int isNumRight(char *num)
{
    int i;
    if (num[0] != '1')
    {
        printf("\t输入的手机号不合规\n");
        return 0;
    }
    if (strlen(num) != 11)
    {
        printf("\t输入的手机号不合规\n");
        return 0;
    }

    for (i = 0; i < 11; i++)
    {
        if (!(num[i] >='0' && num[i]<='9'))
        {
            printf("\t输入的手机号不合规\n");
            return 0;
        }
    }
    printf("\t输入的手机号合规\n");
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

//密码从第五个开始
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

//手机号取最后11位
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
                printf("\t  工号已存在");
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
                printf("\t  手机号已存在");
                return 1;
            }
        }
    }
    return 0;
}

void registerInfo()   /*注册函数*/
{
    char id[20];//工号
    char password[20];//密码
    char num[20];//手机号
    int size = 0;
    char stafftemp[30] = {0};
    while(1)
    {

        size = getsize();
        printf("\t请按001+xxxxxx#13811112222格式输入注册信息\n");
        printf("\t1.请输入工号(三位数字字符):");
        scanf("%s", id);
        while (!isIdRight(id) || isIDexist(id))
        {
            printf("\n\t请重新输入工号:");
            scanf("%s", id);
        }
        printf("\n\t2.请输入六位密码(只能包括数字或字符):");
        scanf("%s", password);
        while (!isPasswordRight(password))
        {
            printf("\t请重新输入密码:");
            scanf("%s", id);
        }
        printf("\n\t3.请输入手机号(11位数字字符):");
        scanf("%s", num);
        while (!isNumRight(num) || isNumExist(num))
        {
            printf("\n\t请重新输入手机号:");
            scanf("%s", num);
        }
        break;
    }

    //职工字符串连接
    strcat(stafftemp, id);
    strcat(stafftemp, "+");
    strcat(stafftemp, password);
    strcat(stafftemp, "#");
    strcat(stafftemp, num);

    //判断系统是否已满
    if (size >= 30)
    {
        printf("\n\t注册系统已满, 请联系管理员\n");
        return;
    }
    //写入系统
    strcpy(staff[size], stafftemp);
    printf("\n");
    printf("\n\t一个新职工的信息创建完毕！\n\n");
    return;

} 

void login()
{
    char id[10] = {0};
    char password[10] = {0};
    char passwordIn[10] = {0};//已经在数组里面的密码

    int i = 0;
    int j  = 0;
    //三次输入机会
    while (i <= 2 && j <= 2)
    {
        printf("\n\t  输入职工号:");
        scanf("%s", id);
        if (!isIDexist(id))
        {
            printf("\n\t  职工号不存在,重新职工号:");
            i++;
            continue;
        }

        printf("\n\t  输入密码:");
        scanf("%s", password);
        getPasswordById(id, passwordIn);
        if (strcmp(password, passwordIn) == 0)
        {
            printf("\n\t  登录成功!欢迎使用本系统!!\n");
            break;
        }
        else
        {
            printf("\n\t  密码输入错误,请重新登录!!\n");
        }
        j ++;
    }
    if(i == 3 || j == 3)
    {
        printf("\n\t  输入错误三次,您已被禁止输入\n");
    }
}

void forgetPassword()
{
    char id[10];
    char num[20];   //输入的手机号码
    char numIn[20]; //系统中的手机号码
    char password[10];
    char stafftemp[SIZE] = {0};
    printf("\n\t  输入职工号:");
    scanf("%s", id);
    if(!isIDexist(id))
    {
        printf("\n\t  职工号不存在,重置密码失败");
        return;
    }
    else
    {
        printf("\n\t  输入手机号:");
        scanf("%s", num);
        getNumById(id, numIn);
        if (strcmp(numIn, num) != 0)
        {
            printf("\n\t  手机号不存在,重置密码失败");
            return;
        }
    }
    printf("\n\t  请重置密码!");
    while (1)
    {
        int i = 0;
        char tempId[10];
        printf("\n\t  请输入密码:");
        scanf("%s", password);
        if (isPasswordRight(password))
        {
            strcat(stafftemp, id);
            strcat(stafftemp, "+");
            strcat(stafftemp, password);
            strcat(stafftemp, "#");
            strcat(stafftemp, num);
            //找到此id的下标
            for(i; i<SIZE; i++)
            {
                getID(tempId, i);
                if(strcmp(id, tempId) == 0)
                {
                    strcpy(staff[i], stafftemp);
                    printf("\n\t  重置密码成功.");
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
            printf("\t  1.登录                      2.忘记密码\n\t  0.退出登录\n");
            printf("\t  请选择:");
			scanf("%d", &n);
			if(n >= 0 && n <= 2)
            {
				f=1;
                break;
			}             
			else {
				f=0; 
				printf("\n\t\t您输入有误，请重新选择!");
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

void display()  /*显示函数*/
{
    int size = getsize();
    char id[4] = {0};
    char password[7] = {0};
    char num[12] = {0};
    int i,j;

    printf("\n\t职工总人数为:%d", size);
    printf("\n\t工号\t密码\t手机号\n");
    for (i = 0; i < size; i++)
    {
        getID(id, i);
        getnum(num, i);
        //显示时密码用*代替
        for(j = 0; j < 6; j++)
        {
            password[j] = '*';
        }
        printf("\t%3s\t%s\t%11s\n", id, password, num);
    }
} 

