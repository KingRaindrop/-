#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "InfoInput.h"
#include "InfoEdit.h" 
#include "InfoQuery.h"
#include "InfoAnalysis.h"

int z_index = 0;          // 菜单层级
int Select_Menu_ID = -1;  // 主菜单选择
int Chosen_ID = -1;       // 子菜单选择

void menu_Main()
{
    if (z_index == 0)
    {
        system("cls");
        printf("* * * * * * * * * * * * * *\n");
        printf("*        1.数据录入       *\n");
        printf("*        2.数据修改       *\n");
        printf("*        3.数据查询       *\n");
        printf("*        4.统计分析       *\n");
        printf("*        0.退出           *\n");
        printf("* * * * * * * * * * * * * *\n");
    }
}

void menu_DataInput()
{
    system("cls");
    printf("* * * * * * * * * * * * * * * * *\n");
    printf("*      1.学生信息录入           *\n");
    printf("*      2.学籍信息录入           *\n");
    printf("*      3.院系信息录入           *\n");
    printf("*      4.成绩信息录入           *\n");
    printf("*      5.培养计划信息录入       *\n");
    printf("*      0.返回上一级菜单         *\n");
    printf("* * * * * * * * * * * * * * * * *\n");
    z_index = 1;
}

void menu_DataEdit()
{
    system("cls");
    printf("* * * * * * * * * * * * * * * * *\n");
    printf("*      1.学生信息修改           *\n");
    printf("*      2.学籍信息修改           *\n");
    printf("*      3.院系信息修改           *\n");
    printf("*      4.成绩信息修改           *\n");
    printf("*      5.培养计划信息修改       *\n");
    printf("*      0.返回上一级菜单         *\n");
    printf("* * * * * * * * * * * * * * * * *\n");
    z_index = 2;
}

void menu_InfoSearch()
{
    system("cls");
    printf("* * * * * * * * * * * * * * * * *\n");
    printf("*      1.学生信息查询           *\n");
    printf("*      2.学籍信息查询           *\n");
    printf("*      3.院系信息查询           *\n");
    printf("*      4.成绩信息查询           *\n");
    printf("*      5.培养计划信息查询       *\n");
    printf("*      0.返回上一级菜单         *\n");
    printf("* * * * * * * * * * * * * * * * *\n");
    z_index = 3;
}

void menu_InfoAnalysis()
{
    system("cls");
    printf("* * * * * * * * * * * * * * * * *\n");
    printf("*      1.学生信息分析           *\n");
    printf("*      2.学籍信息分析           *\n");
    printf("*      3.院系信息分析           *\n");
    printf("*      4.成绩信息分析           *\n");
    printf("*      5.培养计划信息分析       *\n");
    printf("*      0.返回上一级菜单         *\n");
    printf("* * * * * * * * * * * * * * * * *\n");
    z_index = 3;
}

void menu_Logic()
{
    int exit_flag = 0;

    while (!exit_flag)
    {
        menu_Main();
        printf("输入数字以选择功能 -> ");
        scanf("%d", &Select_Menu_ID);

        switch (Select_Menu_ID)
        {
            case 0:
                printf("程序退出\n");
                exit_flag = 1;
                break;

            case 1: // 数据录入
                menu_DataInput();
                printf("选择功能(再次输入数字) -> ");
                scanf(" %d", &Chosen_ID);
                switch (Chosen_ID)
                {
                    case 1: printf("当前选择的是 学生信息录入系统\n"); system("pause"); Stu_Basic_InfoInput(); break;
                    case 2: printf("当前选择的是 学籍信息录入系统\n"); system("pause"); Stu_Origin_InfoInput(); break;
                    case 3: printf("当前选择的是 院系信息录入系统\n"); system("pause"); Stu_Major_InfoInput(); break;
                    case 4: printf("当前选择的是 成绩信息录入系统\n"); system("pause"); Stu_Grade_InfoInput(); break;
                    case 5: printf("当前选择的是 培养计划信息录入系统\n"); system("pause"); Stu_PTP_InfoInput(); break;
                    case 0: printf("返回上一级\n"); system("pause"); 
                }
                break;

            case 2: // 数据修改
                menu_DataEdit();
                printf("选择功能(再次输入数字) -> ");
                scanf(" %d", &Chosen_ID);
                switch (Chosen_ID)
                {
                    case 1: printf("当前选择的是 学生信息修改系统\n"); system("pause"); Stu_Basic_InfoEdit(); break;
                    case 2: printf("当前选择的是 学籍信息修改系统\n"); system("pause"); Stu_Origin_InfoEdit(); break;
                    case 3: printf("当前选择的是 院系信息修改系统\n"); system("pause"); Stu_Major_InfoEdit(); break;
                    case 4: printf("当前选择的是 成绩信息修改系统\n"); system("pause"); Stu_Grade_InfoEdit(); break;
                    case 5: printf("当前选择的是 培养计划信息修改系统\n"); system("pause"); Stu_PTP_InfoEdit(); break;
                    case 0: printf("返回上一级\n"); system("pause"); 
                }
                break;

            case 3: // 数据查询
            menu_InfoSearch();
            printf("选择功能(再次输入数字) -> ");
            scanf(" %d", &Chosen_ID);
                switch (Chosen_ID)
                {
                    case 1:
                        printf("当前选择的是 学生信息查询系统\n");
                        system("pause");
                        Stu_Basic_InfoQuery();
                        break;

                    case 2:
                        printf("当前选择的是 学籍信息查询系统\n");
                        system("pause");
                        Stu_Origin_InfoQuery();
                        break;

                    case 3:
                        printf("当前选择的是 院系信息查询系统\n");
                        system("pause");
                        Stu_Major_InfoQuery();
                        break;

                    case 4:
                        printf("当前选择的是 成绩信息查询系统\n");
                        system("pause");
                        Stu_Grade_InfoQuery();
                        break;

                    case 5:
                        printf("当前选择的是 培养计划信息查询系统\n");
                        system("pause");
                        Stu_PTP_InfoQuery();
                        break;

                    case 0:
                        printf("返回上一级菜单\n");
                        system("pause");
                        break;

                    default:
                        printf("输入有误\n");
                        system("pause");
                        break;
                }
            break;

            case 4:
            menu_InfoAnalysis();
            printf("选择功能(再次输入数字) -> ");
            scanf(" %d", &Chosen_ID);
                switch (Chosen_ID)
                {
                    case 1:
                        printf("当前选择的是 学生信息分析系统\n");
                        system("pause");
                        Stu_Basic_InfoAnalysis();
                        break;

                    case 2:
                        printf("当前选择的是 学籍信息分析系统\n");
                        system("pause");
                        Stu_Origin_InfoAnalysis();
                        break;

                    case 3:
                        printf("当前选择的是 院系信息分析系统\n");
                        system("pause");
                        Stu_Major_InfoAnalysis();
                        break;

                    case 4:
                        printf("当前选择的是 成绩信息分析系统\n");
                        system("pause");
                        Stu_Grade_InfoAnalysis();
                        break;

                    case 5:
                        printf("当前选择的是 培养计划信息分析系统\n");
                        system("pause");
                        Stu_PTP_InfoAnalysis();
                        break;

                    case 0:
                        printf("返回上一级菜单\n");
                        system("pause");
                        break;

                    default:
                        printf("输入有误\n");
                        system("pause");
                        break;
                }
    }
        z_index = 0; // 返回主菜单
    }
}
