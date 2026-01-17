#ifndef _INFOINPUT_H_
#define _INFOINPUT_H_

struct Stu_Basic_Info
{
    char ID_Card[19];//身份证
    char Stu_ID[10];//学号
    char Stu_Name[32];//姓名
    char Sex[4];//性别
    char Birthday[9];//出生日期
};

struct Stu_Major_Info
{
    char Stu_ID[10];//学号
    char Stu_Name[32];//姓名
    char Stu_College[64];//学院
    char Stu_Major[64];//专业
    char Stu_Class[32];//班级
    char Stu_Address[128];//地址
    char Stu_Phonum[12];//电话
    char Stu_Origin[32];//籍贯
    char Stu_EmrollTime[9];//入学时间
};

struct Stu_Grade_Info
{
    char Stu_ID[10];//学号
    char Class_ID[9];//课程编号
    char Class_Name[64];//课程名称
    char Stu_Credit[4];//学分
    char Stu_RegularGrade[4];//平时成绩
    char Stu_FinalGrade[4];//期末成绩
    char Stu_Rating[4];//总评
    char Semester[4];//学期
    char GPA[4];//绩点
};

struct Stu_Origin_Info
{
    char Stu_ID[10];//学号
    char Stu_Name[32];//姓名
    char Stu_College[64];//学院
    char Stu_Major[64];//专业
    char Stu_Class[32];//班级
    char Stu_NowAddress[128];//现住址
    char Stu_Sex[4];//性别
    char Stu_Phonum[12];//电话号码
    char Stu_HomeAddress[128];//家庭住址
    char Stu_PostAddress[7];//邮政编码
    char Stu_Origin[32];//籍贯
};

struct Stu_PTP_Info
{
    char Class_ID[9];//课程编号
    char Class_Name[64];//课程名称
    char Class_Credit[4];//学分
    char Semester[4];//开课学期
    char Class_Nature[128];//课程性质
};

// 数据录入函数
void Stu_Basic_InfoInput();
void Stu_Grade_InfoInput();
void Stu_Origin_InfoInput();
void Stu_PTP_InfoInput();
void Stu_Major_InfoInput();
void Directory_Create();

void menu_DataInput(void);

#endif
