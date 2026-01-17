#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "InfoInput.h"
#include "InfoEdit.h"
#include "InfoAnalysis.h"
#include <string.h>

#define MAX 200
#define SORT_BY_STUID   1
#define SORT_BY_NAME    2
#define ORDER_ASC       1
#define ORDER_DESC      2



void Sort_Stu_Basic_Info(struct Stu_Basic_Info stu[], int n, int key, int order)
{
    int i, j;
    struct Stu_Basic_Info temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            int cmp = 0;

            if (key == SORT_BY_STUID)
            {
                cmp = strcmp(stu[j].Stu_ID, stu[j + 1].Stu_ID);
            }
            else if (key == SORT_BY_NAME)
            {
                cmp = strcmp(stu[j].Stu_Name, stu[j + 1].Stu_Name);
            }

            if ((order == ORDER_ASC && cmp > 0) ||
                (order == ORDER_DESC && cmp < 0))
            {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}


void Stu_Basic_InfoAnalysis(void)
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_Basic_Info_Data.dat", "r");
    if (!fp)
    {
        printf("学生信息文件打开失败\n");
        system("pause");
        return;
    }

    struct Stu_Basic_Info stu[200];
    int count = 0;
    while (fscanf(fp, "%18s %9s %31s %3s %8s",
                  stu[count].ID_Card,
                  stu[count].Stu_ID,
                  stu[count].Stu_Name,
                  stu[count].Sex,
                  stu[count].Birthday) != EOF)
    {
        count++;
    }
    fclose(fp);

    if (count == 0)
    {
        printf("学生信息文件为空\n");
        system("pause");
        return;
    }

    int sortBy, ascending;
    printf("====== 学生信息分析系统 ======\n");
    printf("1. 按学号排序\n");
    printf("2. 按姓名排序\n");
    printf("请选择排序方式：");
    scanf("%d", &sortBy);

    printf("\n1. 升序\n2. 降序\n请选择排序顺序：");
    int order;
    scanf("%d", &order);
    ascending = (order == 1) ? 1 : 0;

    Sort_Stu_Basic_Info(stu, count, sortBy, ascending);

    printf("\n%-20s%-15s%-15s%-8s%-12s\n", "身份证号", "学号", "姓名", "性别", "出生日期");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-20s%-15s%-15s%-8s%-12s\n",
               stu[i].ID_Card,
               stu[i].Stu_ID,
               stu[i].Stu_Name,
               stu[i].Sex,
               stu[i].Birthday);
    }

    printf("\n分析完成，原文件未修改。\n");
    system("pause");
}

void Sort_Stu_Origin_Info(struct Stu_Origin_Info *stu, int count, int sortBy, int ascending)
{
    struct Stu_Origin_Info temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            int cmp = 0;
            if (sortBy == 1)  // 按学号
                cmp = strcmp(stu[i].Stu_ID, stu[j].Stu_ID);
            else if (sortBy == 2) // 按姓名
                cmp = strcmp(stu[i].Stu_Name, stu[j].Stu_Name);

            if ((ascending && cmp > 0) || (!ascending && cmp < 0))
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
}

void Stu_Origin_InfoAnalysis(void)
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_Origin_Info_Data.dat", "r");
    if (!fp)
    {
        printf("学籍信息文件打开失败\n");
        system("pause");
        return;
    }

    struct Stu_Origin_Info stu[200];
    int count = 0;

    while (fscanf(fp, "%9s %31s %63s %63s %31s %127s %3s %11s %127s %6s %31s",
                  stu[count].Stu_ID,
                  stu[count].Stu_Name,
                  stu[count].Stu_College,
                  stu[count].Stu_Major,
                  stu[count].Stu_Class,
                  stu[count].Stu_NowAddress,
                  stu[count].Stu_Sex,
                  stu[count].Stu_Phonum,
                  stu[count].Stu_HomeAddress,
                  stu[count].Stu_PostAddress,
                  stu[count].Stu_Origin) != EOF)
    {
        count++;
    }
    fclose(fp);

    if (count == 0)
    {
        printf("学籍信息文件为空\n");
        system("pause");
        return;
    }

    int sortBy, ascending;
    printf("====== 学生籍贯分析系统 ======\n");
    printf("1. 按学号排序\n");
    printf("2. 按姓名排序\n");
    printf("请选择排序方式：");
    scanf("%d", &sortBy);

    printf("1. 升序\n2. 降序\n请选择排序顺序：");
    int order;
    scanf("%d", &order);
    ascending = (order == 1) ? 1 : 0;

    Sort_Stu_Origin_Info(stu, count, sortBy, ascending);

    // 输出表格头
    printf("\n%-10s\t%-15s\t%-15s\t%-15s\t%-10s\t%-15s\t%-5s\t%-12s\t%-15s\t%-8s\t%-10s\n",
           "学号", "姓名", "学院", "专业", "班级", "现住址", "性别", "电话", "家庭住址", "邮编", "籍贯");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");

    // 输出内容
    for (int i = 0; i < count; i++)
    {
        printf("%-10s\t%-15s\t%-15s\t%-15s\t%-10s\t%-15s\t%-5s\t%-12s\t%-15s\t%-8s\t%-10s\n",
               stu[i].Stu_ID,
               stu[i].Stu_Name,
               stu[i].Stu_College,
               stu[i].Stu_Major,
               stu[i].Stu_Class,
               stu[i].Stu_NowAddress,
               stu[i].Stu_Sex,
               stu[i].Stu_Phonum,
               stu[i].Stu_HomeAddress,
               stu[i].Stu_PostAddress,
               stu[i].Stu_Origin);
    }

    printf("\n分析完成，原文件未修改。\n");
    system("pause");
}


void Sort_Stu_Grade_Info(struct Stu_Grade_Info *stu, int count, int sortBy, int ascending)
{
    struct Stu_Grade_Info temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            int cmp = 0;
            if (sortBy == 1)  // 按学号
                cmp = strcmp(stu[i].Stu_ID, stu[j].Stu_ID);
            else if (sortBy == 2) // 按课程编号
                cmp = strcmp(stu[i].Class_ID, stu[j].Class_ID);

            if ((ascending && cmp > 0) || (!ascending && cmp < 0))
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
}


void Stu_Grade_InfoAnalysis(void)
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_Grade_Info_Data.dat", "r");
    if (!fp)
    {
        printf("成绩文件打开失败\n");
        system("pause");
        return;
    }

    struct Stu_Grade_Info stu[500];
    int count = 0;

    while (fscanf(fp, "%9s %8s %63s %3s %3s %3s %3s %3s %3s",
                  stu[count].Stu_ID,
                  stu[count].Class_ID,
                  stu[count].Class_Name,
                  stu[count].Stu_Credit,
                  stu[count].Stu_RegularGrade,
                  stu[count].Stu_FinalGrade,
                  stu[count].Stu_Rating,
                  stu[count].Semester,
                  stu[count].GPA) != EOF)
    {
        count++;
    }
    fclose(fp);

    if (count == 0)
    {
        printf("成绩文件为空\n");
        system("pause");
        return;
    }

    int sortBy, ascending;
    printf("====== 学生成绩分析系统 ======\n");
    printf("1. 按学号排序\n");
    printf("2. 按课程编号排序\n");
    printf("请选择排序方式：");
    scanf("%d", &sortBy);

    printf("1. 升序\n2. 降序\n请选择排序顺序：");
    int order;
    scanf("%d", &order);
    ascending = (order == 1) ? 1 : 0;

    Sort_Stu_Grade_Info(stu, count, sortBy, ascending);

    // 输出表格头
    printf("\n%-10s\t%-10s\t%-20s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n",
           "学号", "课程号", "课程名", "学分", "平时", "期末", "总评", "学期", "绩点");
    printf("---------------------------------------------------------------------------------------------\n");

    // 输出内容
    for (int i = 0; i < count; i++)
    {
        printf("%-10s\t%-10s\t%-20s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n",
               stu[i].Stu_ID,
               stu[i].Class_ID,
               stu[i].Class_Name,
               stu[i].Stu_Credit,
               stu[i].Stu_RegularGrade,
               stu[i].Stu_FinalGrade,
               stu[i].Stu_Rating,
               stu[i].Semester,
               stu[i].GPA);
    }

    printf("\n分析完成，原文件未修改。\n");
    system("pause");
}


void Sort_Stu_Major_Info(struct Stu_Major_Info *stu, int count, int sortBy, int ascending)
{
    struct Stu_Major_Info temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            int cmp = 0;
            if (sortBy == 1)       // 按学号
                cmp = strcmp(stu[i].Stu_ID, stu[j].Stu_ID);
            else if (sortBy == 2)  // 按姓名
                cmp = strcmp(stu[i].Stu_Name, stu[j].Stu_Name);

            if ((ascending && cmp > 0) || (!ascending && cmp < 0))
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
}

void Stu_Major_InfoAnalysis(void)
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_Major_Info_Data.dat", "r");
    if (!fp)
    {
        printf("专业信息文件打开失败\n");
        system("pause");
        return;
    }

    struct Stu_Major_Info stu[500];
    int count = 0;

    while (fscanf(fp,
                  "%9s %31s %63s %63s %31s %127s %11s %31s %8s",
                  stu[count].Stu_ID,
                  stu[count].Stu_Name,
                  stu[count].Stu_College,
                  stu[count].Stu_Major,
                  stu[count].Stu_Class,
                  stu[count].Stu_Address,
                  stu[count].Stu_Phonum,
                  stu[count].Stu_Origin,
                  stu[count].Stu_EmrollTime) != EOF)
    {
        count++;
    }
    fclose(fp);

    if (count == 0)
    {
        printf("专业信息文件为空\n");
        system("pause");
        return;
    }

    int sortBy, ascending;
    printf("====== 学生专业信息分析系统 ======\n");
    printf("1. 按学号排序\n");
    printf("2. 按姓名排序\n");
    printf("请选择排序方式：");
    scanf("%d", &sortBy);

    printf("1. 升序\n2. 降序\n请选择排序顺序：");
    int order;
    scanf("%d", &order);
    ascending = (order == 1) ? 1 : 0;

    Sort_Stu_Major_Info(stu, count, sortBy, ascending);

    // 输出表格头
    printf("\n%-10s\t%-20s\t%-15s\t%-15s\t%-10s\t%-20s\t%-12s\t%-10s\t%-10s\n",
           "学号", "姓名", "学院", "专业", "班级", "地址", "电话", "籍贯", "入学时间");
    printf("------------------------------------------------------------------------------------------------------------\n");

    // 输出内容
    for (int i = 0; i < count; i++)
    {
        printf("%-10s\t%-20s\t%-15s\t%-15s\t%-10s\t%-20s\t%-12s\t%-10s\t%-10s\n",
               stu[i].Stu_ID,
               stu[i].Stu_Name,
               stu[i].Stu_College,
               stu[i].Stu_Major,
               stu[i].Stu_Class,
               stu[i].Stu_Address,
               stu[i].Stu_Phonum,
               stu[i].Stu_Origin,
               stu[i].Stu_EmrollTime);
    }

    printf("\n分析完成，原文件未修改。\n");
    system("pause");
}




void Sort_Stu_PTP_Info(struct Stu_PTP_Info *stu, int count, int sortBy, int ascending)
{
    struct Stu_PTP_Info temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            int cmp = 0;
            if (sortBy == 1)       // 按课程编号
                cmp = strcmp(stu[i].Class_ID, stu[j].Class_ID);
            else if (sortBy == 2)  // 按课程名称
                cmp = strcmp(stu[i].Class_Name, stu[j].Class_Name);

            if ((ascending && cmp > 0) || (!ascending && cmp < 0))
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
}

void Stu_PTP_InfoAnalysis(void)
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_PTP_Info_Data.dat", "r");
    if (!fp)
    {
        printf("培养计划文件打开失败\n");
        system("pause");
        return;
    }

    struct Stu_PTP_Info stu[200];
    int count = 0;

    while (fscanf(fp,
                  "%8s %63s %3s %3s %127s",
                  stu[count].Class_ID,
                  stu[count].Class_Name,
                  stu[count].Class_Credit,
                  stu[count].Semester,
                  stu[count].Class_Nature) != EOF)
    {
        count++;
    }
    fclose(fp);

    if (count == 0)
    {
        printf("培养计划文件为空\n");
        system("pause");
        return;
    }

    int sortBy, ascending;
    printf("====== 培养计划信息分析系统 ======\n");
    printf("1. 按课程编号排序\n");
    printf("2. 按课程名称排序\n");
    printf("请选择排序方式：");
    scanf("%d", &sortBy);

    printf("1. 升序\n2. 降序\n请选择排序顺序：");
    int order;
    scanf("%d", &order);
    ascending = (order == 1) ? 1 : 0;

    Sort_Stu_PTP_Info(stu, count, sortBy, ascending);

    // 输出表格头
    printf("\n%-10s\t%-20s\t%-5s\t%-5s\t%-20s\n",
           "课程编号", "课程名称", "学分", "学期", "课程性质");
    printf("---------------------------------------------------------------\n");

    // 输出内容
    for (int i = 0; i < count; i++)
    {
        printf("%-10s\t%-20s\t%-5s\t%-5s\t%-20s\n",
               stu[i].Class_ID,
               stu[i].Class_Name,
               stu[i].Class_Credit,
               stu[i].Semester,
               stu[i].Class_Nature);
    }

    printf("\n分析完成，原文件未修改。\n");
    system("pause");
}