#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "InfoInput.h"
#include "InfoEdit.h"

unsigned int N;

// 创建数据保存目录
void Directory_Create()
{
    const char *folderPath = "E:\\Data_Save";
    CreateDirectory(folderPath, NULL);
}

// ======================== 学生基本信息录入 ========================
void Stu_Basic_InfoInput()
{
    Directory_Create();
    const char* filePath = "E:\\Data_Save\\Stu_Basic_Info_Data.dat";

    int fileExists = 0;//文件存在检测标识
    FILE *fp = fopen(filePath,"r");
    if(fp){fileExists=1; fclose(fp);}

    char mode = 'a';
    if(fileExists)
    {
        printf("文件已存在，是否覆盖原有数据？ (O 覆盖 / A 追加): ");
        getchar();
        scanf("%c",&mode);
    }

    char lines[1000][256]; int lineCount=0;
    if(mode=='A' || mode=='a')
    {
        fp=fopen(filePath,"r");
        if(fp){while(fgets(lines[lineCount],256,fp)) lineCount++; fclose(fp);}
    }

    printf("请输入要录入的学生数量: ");
    scanf("%u",&N);

    struct Stu_Basic_Info emp;
    char newLines[N][256];
    for(int i=0;i<N;i++)
    {
        printf("录入第%d位学生:\n",i+1);
        printf("身份证号: "); scanf("%s", emp.ID_Card);
        printf("学号: "); scanf("%s", emp.Stu_ID);
        printf("姓名: "); scanf("%s", emp.Stu_Name);
        printf("性别: "); scanf("%s", emp.Sex);
        printf("出生日期: "); scanf("%s", emp.Birthday);
        snprintf(newLines[i],256,"%s %s %s %s %s\n", emp.ID_Card, emp.Stu_ID, emp.Stu_Name, emp.Sex, emp.Birthday);
    }

    printf("\n录入完成，但尚未保存文件。\n是否保存到文件？ (Y/N): ");
    char choice; getchar(); scanf("%c",&choice);

    if(choice=='Y'||choice=='y')
    {
        fp=fopen(filePath,"w");
        if(!fp){printf("文件写入失败\n"); return;}
        if(mode=='A'||mode=='a')
        {
            if(lineCount>=1) fputs(lines[0],fp);
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
            for(int i=1;i<lineCount;i++) fputs(lines[i],fp);
        }
        else
        {
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
        }
        fclose(fp);
        printf("新记录已保存到文件。\n");
    }
    else printf("未保存文件，数据仍在内存。\n");

    system("pause");
    system("cls");
    menu_DataInput();
}

// ======================== 学生成绩信息录入 ========================
void Stu_Grade_InfoInput()
{
    Directory_Create();
    const char* filePath = "E:\\Data_Save\\Stu_Grade_Info_Data.dat";

    int fileExists = 0;
    FILE *fp = fopen(filePath,"r");
    if(fp){fileExists=1; fclose(fp);}

    char mode='a';
    if(fileExists)
    {
        printf("文件已存在，是否覆盖原有数据？ (O 覆盖 / A 追加): ");
        getchar();
        scanf("%c",&mode);
    }

    char lines[1000][256]; int lineCount=0;
    if(mode=='A'||mode=='a')
    {
        fp=fopen(filePath,"r");
        if(fp){while(fgets(lines[lineCount],256,fp)) lineCount++; fclose(fp);}
    }

    printf("请输入要录入的学生数量: ");
    scanf("%u",&N);

    struct Stu_Grade_Info emp;
    char newLines[N][256];
    for(int i=0;i<N;i++)
    {
        printf("录入第%d位学生成绩:\n",i+1);
        scanf("%s %s %s %s %s %s %s %s %s",
              emp.Stu_ID, emp.Class_ID, emp.Class_Name, emp.Stu_Credit,
              emp.Stu_RegularGrade, emp.Stu_FinalGrade, emp.Stu_Rating, emp.Semester, emp.GPA);
        snprintf(newLines[i],256,"%s %s %s %s %s %s %s %s %s\n",
                 emp.Stu_ID, emp.Class_ID, emp.Class_Name, emp.Stu_Credit,
                 emp.Stu_RegularGrade, emp.Stu_FinalGrade, emp.Stu_Rating, emp.Semester, emp.GPA);
    }

    printf("\n录入完成，但尚未保存文件。\n是否保存到文件？ (Y/N): ");
    char choice; getchar(); scanf("%c",&choice);

    if(choice=='Y'||choice=='y')
    {
        fp=fopen(filePath,"w");
        if(!fp){printf("文件写入失败\n"); return;}
        if(mode=='A'||mode=='a')
        {
            if(lineCount>=1) fputs(lines[0],fp);
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
            for(int i=1;i<lineCount;i++) fputs(lines[i],fp);
        }
        else
        {
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
        }
        fclose(fp);
        printf("新记录已保存到文件。\n");
    }
    else printf("未保存文件，数据仍在内存。\n");

    system("cls");
    menu_DataInput();
}

// ======================== 学生籍贯信息录入 ========================
void Stu_Origin_InfoInput()
{
    Directory_Create();
    const char* filePath = "E:\\Data_Save\\Stu_Origin_Info_Data.dat";

    int fileExists = 0;
    FILE *fp = fopen(filePath,"r");
    if(fp){fileExists=1; fclose(fp);}

    char mode='a';
    if(fileExists)
    {
        printf("文件已存在，是否覆盖原有数据？ (O 覆盖 / A 追加): ");
        getchar();
        scanf("%c",&mode);
    }

    char lines[1000][256]; int lineCount=0;
    if(mode=='A'||mode=='a')
    {
        fp=fopen(filePath,"r");
        if(fp){while(fgets(lines[lineCount],256,fp)) lineCount++; fclose(fp);}
    }

    printf("请输入要录入的学生数量: ");
    scanf("%u",&N);

    struct Stu_Origin_Info emp;
    char newLines[N][256];
    for(int i=0;i<N;i++)
    {
        printf("录入第%d位学生:\n",i+1);
        scanf("%s %s %s %s %s %s %s %s %s %s",
              emp.Stu_ID, emp.Stu_Name, emp.Stu_College, emp.Stu_Major, emp.Stu_Class,
              emp.Stu_NowAddress, emp.Stu_Phonum, emp.Stu_HomeAddress, emp.Stu_PostAddress, emp.Stu_Origin);
        snprintf(newLines[i],256,"%s %s %s %s %s %s %s %s %s %s\n",
                 emp.Stu_ID, emp.Stu_Name, emp.Stu_College, emp.Stu_Major, emp.Stu_Class,
                 emp.Stu_NowAddress, emp.Stu_Phonum, emp.Stu_HomeAddress, emp.Stu_PostAddress, emp.Stu_Origin);
    }

    printf("\n录入完成，但尚未保存文件。\n是否保存到文件？ (Y/N): ");
    char choice; getchar(); scanf("%c",&choice);

    if(choice=='Y'||choice=='y')
    {
        fp=fopen(filePath,"w");
        if(!fp){printf("文件写入失败\n"); return;}
        if(mode=='A'||mode=='a')
        {
            if(lineCount>=1) fputs(lines[0],fp);
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
            for(int i=1;i<lineCount;i++) fputs(lines[i],fp);
        }
        else
        {
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
        }
        fclose(fp);
        printf("新记录已保存到文件。\n");
    }
    else printf("未保存文件，数据仍在内存。\n");

    system("cls");
    menu_DataInput();
}

// ======================== 学生课程培养信息录入 ========================
void Stu_PTP_InfoInput()
{
    Directory_Create();
    const char* filePath = "E:\\Data_Save\\Stu_PTP_Info_Data.dat";

    int fileExists = 0;
    FILE *fp = fopen(filePath,"r");
    if(fp){fileExists=1; fclose(fp);}

    char mode='a';
    if(fileExists)
    {
        printf("文件已存在，是否覆盖原有数据？ (O 覆盖 / A 追加): ");
        getchar();
        scanf("%c",&mode);
    }

    char lines[1000][256]; int lineCount=0;
    if(mode=='A'||mode=='a')
    {
        fp=fopen(filePath,"r");
        if(fp){while(fgets(lines[lineCount],256,fp)) lineCount++; fclose(fp);}
    }

    printf("请输入要录入的课程数量: ");
    scanf("%u",&N);

    struct Stu_PTP_Info emp;
    char newLines[N][256];
    for(int i=0;i<N;i++)
    {
        printf("录入第%d门课程:\n",i+1);
        scanf("%s %s %s %s %s", emp.Class_ID, emp.Class_Name, emp.Class_Credit, emp.Semester, emp.Class_Nature);
        snprintf(newLines[i],256,"%s %s %s %s %s\n",emp.Class_ID, emp.Class_Name, emp.Class_Credit, emp.Semester, emp.Class_Nature);
    }

    printf("\n录入完成，但尚未保存文件。\n是否保存到文件？ (Y/N): ");
    char choice; getchar(); scanf("%c",&choice);

    if(choice=='Y'||choice=='y')
    {
        fp=fopen(filePath,"w");
        if(!fp){printf("文件写入失败\n"); return;}
        if(mode=='A'||mode=='a')
        {
            if(lineCount>=1) fputs(lines[0],fp);
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
            for(int i=1;i<lineCount;i++) fputs(lines[i],fp);
        }
        else
        {
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
        }
        fclose(fp);
        printf("新记录已保存到文件。\n");
    }
    else printf("未保存文件，数据仍在内存。\n");

    system("cls");
    menu_DataInput();
}

// ======================== 学生院系信息录入 ========================
void Stu_Major_InfoInput()
{
    Directory_Create();
    const char* filePath = "E:\\Data_Save\\Stu_Major_Info_Data.dat";

    int fileExists = 0;
    FILE *fp = fopen(filePath,"r");
    if(fp){fileExists=1; fclose(fp);}

    char mode='a';
    if(fileExists)
    {
        printf("文件已存在，是否覆盖原有数据？ (O 覆盖 / A 追加): ");
        getchar();
        scanf("%c",&mode);
    }

    char lines[1000][256]; int lineCount=0;
    if(mode=='A'||mode=='a')
    {
        fp=fopen(filePath,"r");
        if(fp){while(fgets(lines[lineCount],256,fp)) lineCount++; fclose(fp);}
    }

    printf("请输入要录入的学生数量: ");
    scanf("%u",&N);

    struct Stu_Major_Info emp;
    char newLines[N][256];
    for(int i=0;i<N;i++)
    {
        printf("录入第%d位学生:\n",i+1);
        scanf("%s %s %s %s %s %s %s %s %s",
              emp.Stu_ID, emp.Stu_Name, emp.Stu_College, emp.Stu_Major, emp.Stu_Class,
              emp.Stu_Address, emp.Stu_Phonum, emp.Stu_Origin, emp.Stu_EmrollTime);
        snprintf(newLines[i],256,"%s %s %s %s %s %s %s %s %s\n",
                 emp.Stu_ID, emp.Stu_Name, emp.Stu_College, emp.Stu_Major, emp.Stu_Class,
                 emp.Stu_Address, emp.Stu_Phonum, emp.Stu_Origin, emp.Stu_EmrollTime);
    }

    printf("\n录入完成，但尚未保存文件。\n是否保存到文件？ (Y/N): ");
    char choice; getchar(); scanf("%c",&choice);

    if(choice=='Y'||choice=='y')
    {
        fp=fopen(filePath,"w");
        if(!fp){printf("文件写入失败\n"); return;}
        if(mode=='A'||mode=='a')
        {
            if(lineCount>=1) fputs(lines[0],fp);
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
            for(int i=1;i<lineCount;i++) fputs(lines[i],fp);
        }
        else
        {
            for(int i=0;i<N;i++) fputs(newLines[i],fp);
        }
        fclose(fp);
        printf("新记录已保存到文件。\n");
    }
    else printf("未保存文件，数据仍在内存。\n");

    system("cls");
    menu_DataInput();
}
