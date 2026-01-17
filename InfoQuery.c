#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "InfoQuery.h"
#include "InfoInput.h"

void Stu_Basic_InfoQuery()//基本信息查询
{
    FILE *fp;
    struct Stu_Basic_Info stu;
    int mode, found = 0;
    char key[32];

    fp = fopen("E:\\Data_Save\\Stu_Basic_Info_Data.dat", "r");
    if (!fp)
    {
        printf("学生信息文件不存在\n");
        system("pause");
        return;
    }

    printf("查询方式：1.按学号  2.按姓名 ：");
    scanf("%d", &mode);
    printf("请输入查询内容：");
    scanf("%31s", key);

    printf("\n查询结果：\n");

    while (fscanf(fp, "%18s %9s %31s %3s %8s",
                  stu.ID_Card,
                  stu.Stu_ID,
                  stu.Stu_Name,
                  stu.Sex,
                  stu.Birthday) != EOF)
    {
        if ((mode == 1 && strcmp(stu.Stu_ID, key) == 0) ||
            (mode == 2 && strcmp(stu.Stu_Name, key) == 0))
        {
            printf("%s %s %s %s %s\n",
                   stu.ID_Card, stu.Stu_ID, stu.Stu_Name, stu.Sex, stu.Birthday);
            found = 1;
        }
    }

    if (!found)
        printf("未查询到相关学生信息\n");

    fclose(fp);
    system("pause");
}

void Stu_Origin_InfoQuery()//学籍信息查询
{
    FILE *fp;
    struct Stu_Origin_Info stu;
    int mode, found = 0;
    char key[32];

    fp = fopen("E:\\Data_Save\\Stu_Origin_Info_Data.dat", "r");
    if (!fp)
    {
        printf("学籍信息文件不存在\n");
        system("pause");
        return;
    }

    printf("查询方式：1.按学号  2.按姓名 ：");
    scanf("%d", &mode);
    printf("请输入选择的查询方式的内容：");
    scanf("%31s", key);

    printf("\n查询结果：\n");

    while (fscanf(fp,
                  "%9s %31s %63s %63s %31s %127s %3s %11s %127s %6s %31s",
                  stu.Stu_ID,
                  stu.Stu_Name,
                  stu.Stu_College,
                  stu.Stu_Major,
                  stu.Stu_Class,
                  stu.Stu_NowAddress,
                  stu.Stu_Sex,
                  stu.Stu_Phonum,
                  stu.Stu_HomeAddress,
                  stu.Stu_PostAddress,
                  stu.Stu_Origin) != EOF)
    {
        if ((mode == 1 && strcmp(stu.Stu_ID, key) == 0) ||
            (mode == 2 && strcmp(stu.Stu_Name, key) == 0))
        {
            printf("%s %s %s %s %s %s %s %s %s %s %s\n",
                   stu.Stu_ID, stu.Stu_Name, stu.Stu_College, stu.Stu_Major,
                   stu.Stu_Class, stu.Stu_NowAddress, stu.Stu_Sex,
                   stu.Stu_Phonum, stu.Stu_HomeAddress,
                   stu.Stu_PostAddress, stu.Stu_Origin);
            found = 1;
        }
    }

    if (!found)
        printf("未查询到学籍信息\n");

    fclose(fp);
    system("pause");
}

void Stu_Major_InfoQuery()//院系专业信息查询
{
    FILE *fp;
    struct Stu_Major_Info stu;
    int mode, found = 0;
    char key[32];

    fp = fopen("E:\\Data_Save\\Stu_Major_Info_Data.dat", "r");
    if (!fp)
    {
        printf("专业信息文件不存在\n");
        system("pause");
        return;
    }

    printf("查询方式：1.按学号  2.按姓名 ：");
    scanf("%d", &mode);
    printf("请输入选择的查询方式的内容：");
    scanf("%31s", key);

    printf("\n查询结果：\n");

    while (fscanf(fp,
                  "%9s %31s %63s %63s %31s %127s %11s %31s %8s",
                  stu.Stu_ID,
                  stu.Stu_Name,
                  stu.Stu_College,
                  stu.Stu_Major,
                  stu.Stu_Class,
                  stu.Stu_Address,
                  stu.Stu_Phonum,
                  stu.Stu_Origin,
                  stu.Stu_EmrollTime) != EOF)
    {
        if ((mode == 1 && strcmp(stu.Stu_ID, key) == 0) ||
            (mode == 2 && strcmp(stu.Stu_Name, key) == 0))
        {
            printf("%s %s %s %s %s %s %s %s %s\n",
                   stu.Stu_ID, stu.Stu_Name, stu.Stu_College, stu.Stu_Major,
                   stu.Stu_Class, stu.Stu_Address, stu.Stu_Phonum,
                   stu.Stu_Origin, stu.Stu_EmrollTime);
            found = 1;
        }
    }

    if (!found)
        printf("未查询到专业信息\n");

    fclose(fp);
    system("pause");
}

void Stu_Grade_InfoQuery()//成绩查询
{
    FILE *fp;
    struct Stu_Grade_Info stu;
    char stuID[20];
    int found = 0;

    fp = fopen("E:\\Data_Save\\Stu_Grade_Info_Data.dat", "r");
    if (!fp)
    {
        printf("成绩文件不存在\n");
        system("pause");
        return;
    }

    printf("请输入学生学号：");
    scanf("%19s", stuID);

    printf("\n查询结果：\n");

    while (fscanf(fp,
                  "%9s %8s %63s %3s %3s %3s %3s %3s %3s",
                  stu.Stu_ID,
                  stu.Class_ID,
                  stu.Class_Name,
                  stu.Stu_Credit,
                  stu.Stu_RegularGrade,
                  stu.Stu_FinalGrade,
                  stu.Stu_Rating,
                  stu.Semester,
                  stu.GPA) != EOF)
    {
        if (strcmp(stu.Stu_ID, stuID) == 0)
        {
            printf("%s %s %s %s %s %s %s %s %s\n",
                   stu.Stu_ID, stu.Class_ID, stu.Class_Name,
                   stu.Stu_Credit, stu.Stu_RegularGrade,
                   stu.Stu_FinalGrade, stu.Stu_Rating,
                   stu.Semester, stu.GPA);
            found = 1;
        }
    }

    if (!found)
        printf("未查询到该学生成绩\n");

    fclose(fp);
    system("pause");
}

void Stu_PTP_InfoQuery()//培养计划查询
{
    FILE *fp;
    struct Stu_PTP_Info stu;
    char classID[20];
    int found = 0;

    fp = fopen("E:\\Data_Save\\Stu_PTP_Info_Data.dat", "r");
    if (!fp)
    {
        printf("培养计划文件不存在\n");
        system("pause");
        return;
    }

    printf("请输入课程编号：");
    scanf("%19s", classID);

    printf("\n查询结果：\n");

    while (fscanf(fp,
                  "%8s %63s %3s %3s %127s",
                  stu.Class_ID,
                  stu.Class_Name,
                  stu.Class_Credit,
                  stu.Semester,
                  stu.Class_Nature) != EOF)
    {
        if (strcmp(stu.Class_ID, classID) == 0)
        {
            printf("%s %s %s %s %s\n",
                   stu.Class_ID, stu.Class_Name,
                   stu.Class_Credit, stu.Semester,
                   stu.Class_Nature);
            found = 1;
        }
    }

    if (!found)
        printf("未查询到培养计划信息\n");

    fclose(fp);
    system("pause");
}





