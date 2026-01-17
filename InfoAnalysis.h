#ifndef _INFOANALYSIS_H_
#define _INFOANALYSIS_H_

void Sort_Stu_Basic_Info(struct Stu_Basic_Info stu[], int n, int key, int order);
void Sort_Stu_PTP_Info(struct Stu_PTP_Info *stu, int count, int sortBy, int ascending);
void Sort_Stu_Major_Info(struct Stu_Major_Info *stu, int count, int sortBy, int ascending);
void Sort_Stu_Grade_Info(struct Stu_Grade_Info *stu, int count, int sortBy, int ascending);
void Sort_Stu_Origin_Info(struct Stu_Origin_Info *stu, int count, int sortBy, int ascending);
void Stu_Basic_InfoAnalysis(void);
void Stu_Origin_InfoAnalysis(void);
void Stu_Grade_InfoAnalysis(void);
void Stu_Major_InfoAnalysis(void);
void Stu_PTP_InfoAnalysis(void);

#endif