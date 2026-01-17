#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "InfoInput.h"
#include "InfoEdit.h"

void EditField(char *field, int size, const char *tip)//安全输入函数
{
    char buf[256];

    printf("%s（原值：%s，回车=清空）：",
           tip, field[0] ? field : "空");

    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0';

    if (strlen(buf) == 0)
    {
        field[0] = '\0';     // 清空
    }
    else
    {
        strncpy(field, buf, size - 1);
        field[size - 1] = '\0';
    }
}

int ConfirmModify()//修改确认函数
{
    printf("是否确认修改？(Y/N)：");
    char confirm;
    scanf(" %c", &confirm);
    return (confirm == 'Y' || confirm == 'y');
}



// ===== 1. 学生基本信息修改 =====
void Stu_Basic_InfoEdit()
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_Basic_Info_Data.dat", "r+");
    if (!fp) { printf("文件打开失败\n"); return; }

    struct Stu_Basic_Info stu[100];
    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s",
           stu[count].ID_Card,
           stu[count].Stu_ID,
           stu[count].Stu_Name,
           stu[count].Sex,
           stu[count].Birthday) != EOF)
        count++;

    char targetID[10];
    printf("输入学号："); scanf("%s", targetID); getchar();

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(stu[i].Stu_ID, targetID))
        {
            found = 1;

            printf("回车=清空记录，输入任意字符=重新录入\n");
            char buf[2]; fgets(buf, sizeof(buf), stdin);

            if (buf[0] == '\n') memset(&stu[i], 0, sizeof(stu[i]));
            else
            {
                printf("重新输入：[身份证 学号 姓名 性别 出生日期]\n");
                scanf("%18s %9s %31s %3s %8s",
                      stu[i].ID_Card, stu[i].Stu_ID, stu[i].Stu_Name,
                      stu[i].Sex, stu[i].Birthday);
            }

            if (!ConfirmModify())
            {
                printf("已取消修改\n");
                fclose(fp);
                return;
            }
            break;
        }
    }

    if (!found) { printf("未找到该学生\n"); fclose(fp); return; }

    rewind(fp);
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s %s %s %s %s\n",
                stu[i].ID_Card, stu[i].Stu_ID, stu[i].Stu_Name,
                stu[i].Sex, stu[i].Birthday);

    fclose(fp);
    printf("修改完成\n");
}


// ===== 2. 学生学籍信息修改 =====
void Stu_Origin_InfoEdit()
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_Origin_Info.dat", "r+");
    if (!fp) { printf("文件打开失败\n"); return; }

    struct Stu_Origin_Info stu[100];
    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s %s %s %s %s %s",
           stu[count].Stu_ID, stu[count].Stu_Name, stu[count].Stu_College,
           stu[count].Stu_Major, stu[count].Stu_Class, stu[count].Stu_NowAddress,
           stu[count].Stu_Phonum, stu[count].Stu_HomeAddress, stu[count].Stu_PostAddress,
           stu[count].Stu_Origin) != EOF)
        count++;

    char targetID[10];
    printf("输入学号："); scanf("%s", targetID); getchar();

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(stu[i].Stu_ID, targetID))
        {
            found = 1;

            printf("回车=清空记录，输入任意字符=重新录入\n");
            char buf[2]; fgets(buf, sizeof(buf), stdin);

            if (buf[0] == '\n') memset(&stu[i], 0, sizeof(stu[i]));
            else
            {
                printf("重新输入：[学号 姓名 学院 专业 班级 现住址 电话 家庭住址 邮政编码 籍贯]\n");
                scanf("%s %s %s %s %s %s %s %s %s %s",
                      stu[i].Stu_ID, stu[i].Stu_Name, stu[i].Stu_College,
                      stu[i].Stu_Major, stu[i].Stu_Class, stu[i].Stu_NowAddress,
                      stu[i].Stu_Phonum, stu[i].Stu_HomeAddress, stu[i].Stu_PostAddress,
                      stu[i].Stu_Origin);
            }

            if (!ConfirmModify()) { printf("已取消修改\n"); fclose(fp); return; }
            break;
        }
    }

    if (!found) { printf("未找到该学生\n"); fclose(fp); return; }

    rewind(fp);
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s %s %s %s %s %s %s %s %s %s\n",
                stu[i].Stu_ID, stu[i].Stu_Name, stu[i].Stu_College,
                stu[i].Stu_Major, stu[i].Stu_Class, stu[i].Stu_NowAddress,
                stu[i].Stu_Phonum, stu[i].Stu_HomeAddress, stu[i].Stu_PostAddress,
                stu[i].Stu_Origin);

    fclose(fp);
    printf("修改完成\n");
}



// ===== 3. 学生成绩信息修改 =====
void Stu_Grade_InfoEdit()
{
    FILE *fp;
    struct Stu_Grade_Info stu[100];
    int count = 0;
    char id[10], cid[9];

    fp = fopen("E:\\Data_Save\\Stu_Grade_Info_Data.dat", "r+");
    if (!fp) return;

    while (fscanf(fp, "%s %s %s %s %s %s %s %s %s",
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

    printf("输入学号：");
    scanf("%s", id);
    printf("输入课程编号：");
    scanf("%s", cid);
    getchar();

    int found = 0;

    for (int i = 0; i < count; i++)
    {
        if (!strcmp(stu[i].Stu_ID, id) &&
            !strcmp(stu[i].Class_ID, cid))
        {
            found = 1;

            printf("回车=清空该成绩，输入任意字符=重新录入：");
            char buf[4];
            fgets(buf, sizeof(buf), stdin);

            if (buf[0] == '\n')
            {
                memset(&stu[i], 0, sizeof(stu[i]));
            }
            else
            {
                printf("重新输入：[学号 课程号 课程名 学分 平时 期末 总评 学期 绩点]\n");
                scanf("%s %s %s %s %s %s %s %s %s",
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

            // ★ 确认修改
            printf("是否确认修改？(Y/N)：");
            char confirm;
            scanf(" %c", &confirm);

            if (confirm != 'Y' && confirm != 'y')
            {
                printf("已取消修改\n");
                fclose(fp);
                return;
            }

            break;
        }
    }

    if (!found)
    {
        printf("未找到该成绩记录\n");
        fclose(fp);
        return;
    }

    rewind(fp);
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s %s %s %s %s %s %s %s\n",
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

    fclose(fp);
    printf("成绩信息修改完成\n");
}




// ===== 4. 学生院系信息修改 =====
void Stu_Major_InfoEdit()
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_Major_Info_Data.dat", "r+");
    if (!fp) { printf("文件打开失败\n"); return; }

    struct Stu_Major_Info stu[100];
    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s %s %s %s %s",
           stu[count].Stu_ID, stu[count].Stu_Name, stu[count].Stu_College,
           stu[count].Stu_Major, stu[count].Stu_Class, stu[count].Stu_Address,
           stu[count].Stu_Phonum, stu[count].Stu_Origin, stu[count].Stu_EmrollTime) != EOF)
        count++;

    char targetID[10];
    printf("输入学号："); scanf("%s", targetID); getchar();

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(stu[i].Stu_ID, targetID))
        {
            found = 1;

            printf("回车=清空记录，输入任意字符=重新录入\n");
            char buf[2]; fgets(buf, sizeof(buf), stdin);

            if (buf[0] == '\n') memset(&stu[i], 0, sizeof(stu[i]));
            else
            {
                printf("重新输入：[学号 姓名 学院 专业 班级 地址 电话 籍贯 入学时间]\n");
                scanf("%s %s %s %s %s %s %s %s %s",
                      stu[i].Stu_ID, stu[i].Stu_Name, stu[i].Stu_College,
                      stu[i].Stu_Major, stu[i].Stu_Class, stu[i].Stu_Address,
                      stu[i].Stu_Phonum, stu[i].Stu_Origin, stu[i].Stu_EmrollTime);
            }

            if (!ConfirmModify()) { printf("已取消修改\n"); fclose(fp); return; }
            break;
        }
    }

    if (!found) { printf("未找到该学生\n"); fclose(fp); return; }

    rewind(fp);
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s %s %s %s %s %s %s %s %s\n",
                stu[i].Stu_ID, stu[i].Stu_Name, stu[i].Stu_College,
                stu[i].Stu_Major, stu[i].Stu_Class, stu[i].Stu_Address,
                stu[i].Stu_Phonum, stu[i].Stu_Origin, stu[i].Stu_EmrollTime);

    fclose(fp);
    printf("修改完成\n");
}


// ===== 5. 培养计划信息修改 =====
void Stu_PTP_InfoEdit()
{
    FILE *fp = fopen("E:\\Data_Save\\Stu_PTP_Info_Data.dat", "r+");
    if (!fp) { printf("文件打开失败\n"); return; }

    struct Stu_PTP_Info ptp[100];
    int count = 0;
    while (fscanf(fp, "%s %s %s %s %s",
           ptp[count].Class_ID, ptp[count].Class_Name, ptp[count].Class_Credit,
           ptp[count].Semester, ptp[count].Class_Nature) != EOF)
        count++;

    char targetID[9];
    printf("输入课程编号："); scanf("%s", targetID); getchar();

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(ptp[i].Class_ID, targetID))
        {
            found = 1;

            printf("回车=清空记录，输入任意字符=重新录入\n");
            char buf[2]; fgets(buf, sizeof(buf), stdin);

            if (buf[0] == '\n') memset(&ptp[i], 0, sizeof(ptp[i]));
            else
            {
                printf("重新输入：[课程编号 课程名 学分 学期 课程性质]\n");
                scanf("%s %s %s %s %s",
                      ptp[i].Class_ID, ptp[i].Class_Name,
                      ptp[i].Class_Credit, ptp[i].Semester, ptp[i].Class_Nature);
            }

            if (!ConfirmModify()) { printf("已取消修改\n"); fclose(fp); return; }
            break;
        }
    }

    if (!found) { printf("未找到该课程\n"); fclose(fp); return; }

    rewind(fp);
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s %s %s %s %s\n",
                ptp[i].Class_ID, ptp[i].Class_Name, ptp[i].Class_Credit,
                ptp[i].Semester, ptp[i].Class_Nature);

    fclose(fp);
    printf("修改完成\n");
}

