#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void Input(int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],int iSortScore[][7],long lSortNum[],char cEachName[40][20],char cSortName[40][20]);
void List(int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],char cEachName[40][20],int iSumStudent[],float fAverStudent[]);
void CalcCourse(int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumCourse[],float fAverCourse[]);
void CalcStudent(int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumStudent[],float fAverStudent[],int iSortSumStudent[]);
void Sort(int iStudentNum,long lSortNum[],int (*FuncPoint)(int a,int b),char cSortName[40][20],int iSortSumStudent[],int iSortScore[][7]);
void SortNum(int iStudentNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[]);
void SortName(int iStudentNum,int iSubjectNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[]);
void Search(int iLeft,int iRight,int iSortScore[][7],long lSortNum[],long lSearchNum,int iSumStudent[]);
void SearchName(int iStudentNum,int iSortScore[][7],char cSortName[40][20],int iSumStudent[]);
void Analysis(int iStudentNum,int iSortScore[][7]);

int iDescendScore(int a,int b);
int iAscendScore(int a,int b);
int iDescendNum(long a,long b);

int iChoice=-1,iStudentNum,iSubjectNum,iInputFinish=0,i,j,k;
int main()
{
    int iEachScore[40][7],iSortScore[40][7];
    int iSumStudent[40]={0},iSumCourse[7]={0},iSortSumStudent[7]={0};
    long lEachNum[40],lSortNum[40];
    float fAverStudent[40]={0},fAverCourse[7]={0};
    char cEachName[40][20],cSortName[40][20];
    long lSearchNum;
    int iRet,lRet;

    printf("\n-------------------------\n\
           \n1.Input record \n\
2.List record\n\
3. Calculate total and average score of every course\n\
4. Calculate total and average score of every student\n\
5. Sort in descending order by total score of every student\n\
6. Sort in ascending order by total score of every student\n\
7. Sort in ascending order by StudentID\n\
8. Sort in dictionary order by name\n\
9. Search by StudentID\n\
10.Search by name\n\
11.Statistic analysis for every course\n\
0.Exit\n\
-------------------------\n\
Please enter your choice:");
    while (iChoice!=0)//当用户输入0时结束程序
    {
        iRet=scanf("%d",&iChoice);
        if (iRet==1)
        {
            if (iChoice==1) iInputFinish=1;
            if (iInputFinish==0)
            {
                printf("温馨提示：请先执行指令1输入数据\n");
            }
            else
            {
                switch(iChoice)
                {
                case 1:
                    printf("请输入学生人数");
                    scanf("%d",&iStudentNum);
                    printf("请输入学科门数");
                    scanf("%d",&iSubjectNum);
                    Input(iStudentNum,iSubjectNum,lEachNum,iEachScore,iSortScore,lSortNum,cEachName,cSortName);
                    break;//跳出switch
                case 2:
                    List(iStudentNum,iSubjectNum,lEachNum,iEachScore,cEachName,iSumStudent,fAverStudent);
                    break;
                case 3:
                    CalcCourse(iStudentNum,iSubjectNum,iEachScore,iSumCourse,fAverCourse);
                    break;
                case 4:
                    CalcStudent(iStudentNum,iSubjectNum,iEachScore,iSumStudent,fAverStudent,iSortSumStudent);
                    break;
                case 5:
                    Sort(iStudentNum,lSortNum,iDescendScore,cSortName,iSortSumStudent,iSortScore);
                    break;
                case 6:
                    Sort(iStudentNum,lSortNum,iAscendScore,cSortName,iSortSumStudent,iSortScore);
                    break;
                case 7:
                    SortNum(iStudentNum,iSortScore,lSortNum,cSortName,iSortSumStudent);
                    for (i=0;i<iStudentNum;i++)
                    {

                        printf("学号：%d \n",lSortNum[i]);
                        for (j=0;j<iSubjectNum;j++)
                        {
                            printf("各科分数：%d ",iSortScore[i][j]);
                        }
                        printf("总分：%d 姓名：",iSortSumStudent[i]);
                        puts(cSortName[i]);
                    }
                    break;
                case 8:
                    SortName(iStudentNum,iSubjectNum,iSortScore,lSortNum,cSortName,iSortSumStudent);
                    break;
                case 9:
                    printf("请输入要查询的学生学号\n");
                    lRet=scanf("%ld",&lSearchNum);
                    while (lRet!=1 || lSearchNum<=0 )
                    {
                        printf("请输入有效的学号:\n");//当没有读到数字时提示用户
                        fflush(stdin);//清空缓存区
                        lRet=scanf("%ld",&lSearchNum);
                    }

                    SortNum(iStudentNum,iSortScore,lSortNum,cSortName,iSortSumStudent);//先调用学号排序函数
                    Search(0,iStudentNum,iSortScore,lSortNum,lSearchNum,iSortSumStudent);//二分法查找
                    break;
                case 10:
                    SearchName(iStudentNum,iSortScore,cSortName,iSumStudent);
                    break;
                case 11:
                    Analysis(iStudentNum,iSortScore);
                    break;
                case 0:
                    break;
                default:
                    printf("Wrong!!!!");
                    fflush(stdin);//输入错误时清空缓存区

                }
            }
        }
        else
        {
            printf("输入非法字符请重新输入\n");
            fflush(stdin);//输入错误时清空缓存区
        }

        system("pause");//用户按任意键继续
        system("cls"); //输入结束时清空屏幕
        printf("\n-------------------------\n\
           \n1.Input record \n\
2.List record\n\
3. Calculate total and average score of every course\n\
4. Calculate total and average score of every student\n\
5. Sort in descending order by total score of every student\n\
6. Sort in ascending order by total score of every student\n\
7. Sort in ascending order by StudentID\n\
8. Sort in dictionary order by name\n\
9. Search by StudentID\n\
10.Search by name\n\
11.Statistic analysis for every course\n\
0.Exit\n\
-------------------------\n\
Please enter your choice:");
    }



}
/**********************************
** 函数名: Input
** 输 入:int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],int iSortScore[][7],long lSortNum[],char cEachName[40][20],char cSortName[40][20]
** iStudentNum--学生人数
** int iSubjectNum--科目数
** lEachNum[]--按输入顺序的学号数组
** iEachScore[][7]--按输入顺序的各科分数数组
** iSortScore[]--用于重新排序的各科分数数组
** lSortNum[]--用于重新排序的学号数组
** cEachName[][]--按输入顺序的姓名数组
** cSortName[][]--用于重新排序的姓名数组
** 功能描述: 读取用户输入的学号和各科分数

************************************/
Input(int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],int iSortScore[][7],long lSortNum[],char cEachName[40][20],char cSortName[40][20])
{
    int i,j;
    char a[]="a";
    for (i=0;i<iStudentNum;i++)
    {
        fflush(stdin);
        printf("输入姓名");
        gets(cEachName[i]);
        strcpy(cSortName[i],cEachName[i]);//把按输入顺序的姓名数组复制到用于重新排序的姓名数组
        printf("输入学号");
        scanf("%d",&lEachNum[i]);
        lSortNum[i]=lEachNum[i];//把按输入顺序的学号数组复制到用于重新排序的学号数组
        printf("输入该生各科分数");
        for (j=0;j<iSubjectNum;j++)
        {
            scanf("%d",&iEachScore[i][j]);
            iSortScore[i][j]=iEachScore[i][j];//把按输入顺序的分数数组复制到用于重新排序的分数数组
        }



    }
}
/**********************************
** 函数名: List
** 输 入: int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],char cEachName[40][20],int iSumStudent[],float fAverStudent[]
** 输出：long lEachNum[],int iEachScore[][7],char cEachName[40][20],int iSumStudent[],float fAverStudent[]
** iStudentNum--学生人数
** int iSubjectNum--科目数
** lEachNum[]--按输入顺序的学号数组
** iEachScore[][7]--按输入顺序的各科分数数组
** iSortScore[]--用于重新排序的各科分数数组
** lSortNum[]--用于重新排序的学号数组
** cEachName[][]--按输入顺序的姓名数组
** cSortName[][]--用于重新排序的姓名数组
** 功能描述:按输入顺序输出学号姓名，各科分数，总分，平均分
************************************/
void List(int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],char cEachName[40][20],int iSumStudent[],float fAverStudent[])
{
    int i;
    for (i=0;i<iStudentNum;i++)
    {
        printf("学号%d ",lEachNum[i]);
        printf("各科分数： ");
        for (j=0;j<iSubjectNum;j++)
        {
            printf("%d ",iEachScore[i][j]);
        }
        printf("总分：%d ",iSumStudent[i]);
        printf("平均分：%.1f 姓名：",fAverStudent[i]);
        puts(cEachName[i]);
    }
}
/**********************************
** 函数名: CalcCourse
** 输入：int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumCourse[],float fAverCourse[]
** iStudentNum--学生人数
** iSubjectNum--学科科数
** iEachScore[][7]--按输入顺序的分数数组
** iSumCourse[]--每门课程的总分
** fAverCourse[]--每门课程的平均分
** 功能描述:计算每门课程的总成绩和平均分
************************************/
void CalcCourse(int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumCourse[],float fAverCourse[])
{
    int i,j;
    for (i=0;i<iSubjectNum;i++)
    {
        for (j=0;j<iStudentNum;j++)
        {
            iSumCourse[i]+=iEachScore[j][i];
        }
        fAverCourse[i]=(float)iSumCourse[i]/iStudentNum;

    }


}


/**********************************
** 函数名: CalcStudent
** 输入：int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumStudent[],float fAverStudent[],int iSortSumStudent[]
** iStudentNum--学生人数
** iSubjectNum--学科科数
** iEachScore[][7]--按输入顺序的分数数组
** iSumStudent[]--每个学生的总分
** fAverStudent[]--每个学生的平均分
** iSortSumStudent[]--用于排序的每个学生的总分
** 功能描述:计算每个学生的总成绩和平均分

************************************/
void CalcStudent(int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumStudent[],float fAverStudent[],int iSortSumStudent[])
{
    int i,j;
    for (i=0;i<iStudentNum;i++)
    {
        iSumStudent[i]=0;//将总分归零避免重新计算时发生错误
        for (j=0;j<iSubjectNum;j++)
        {
            iSumStudent[i]+=iEachScore[i][j];

        }
        iSortSumStudent[i]=iSumStudent[i];
        fAverStudent[i]=(float)iSumStudent[i]/iSubjectNum;

    }


}


/**********************************
** 函数名: Sort
** 输 入: int iStudentNum,long lSortNum[],int (*FuncPoint)(int a,int b),char cSortName[40][20],int iSortSumStudent[]
** 输 出：i+1 iStudentNum-i lSortNum[] cSortName[40][20]
** iStudentNum--学生人数
** iSortSumStudent[]--用于重新排序的总分数组
** lSortNum[]--用于重新排序的学号数组
** (*FuncPoint)(int a,int b)--指向两个按不同排序标准返回真假值的函数指针
** i+1 iStudentNum-i--两种不同情况对应的排名
** cSortName[40][20]--用于重新排序的姓名数组
** iSumStudent[]--每个学生的总分
** 功能描述: 按总成绩由高到低(或由低到高)排出名次表
************************************/
void Sort(int iStudentNum,long lSortNum[],int (*FuncPoint)(int a,int b),char cSortName[40][20],int iSortSumStudent[],int iSortScore[][7])
{
    int i,iMax,j,iTemp;
    long lTemp;
    char cTemp[20];
    for (i=0;i<iStudentNum;i++)//排序采用选择排序
    {
        iMax=i;//将首个元素坐标置为最值坐标
        for (j=i+1;j<iStudentNum;j++)//遍历从i往后的元素
        {
            if ((*FuncPoint)(iSortSumStudent[j],iSortSumStudent[iMax]))//将j对应的值与当前最值比较
            {
                iMax=j;//符合条件时将j置为最值坐标
            }

        }
        if (iMax!=i)
        {
            //交换最值与本轮首个元素及其对应的学号的位置
            lTemp=lSortNum[iMax];
            lSortNum[iMax]=lSortNum[i];
            lSortNum[i]=lTemp;
            iTemp=iSortSumStudent[iMax];
            iSortSumStudent[iMax]=iSortSumStudent[i];
            iSortSumStudent[i]=iTemp;
            strcpy(cTemp,cSortName[iMax]);
            strcpy(cSortName[iMax],cSortName[i]);
            strcpy(cSortName[i],cTemp);
            for (k=0;k<iSubjectNum;k++)
            {
                iTemp=iSortScore[iMax][k];
                iSortScore[iMax][k]=iSortScore[i][k];
                iSortScore[i][k]=iTemp;
            }
        }


    }
    for (i=0;i<iStudentNum;i++)
    {
        if (iChoice==5)//分不同的排序标准输出结果
        {
            printf("排名： %d 学号：%d 姓名：",i+1,lSortNum[i]);
            puts(cSortName[i]);
        }

        else
        {
            printf("排名： %d 学号：%d 姓名：",iStudentNum-i,lSortNum[i]);
            puts(cSortName[i]);
        }
    }
}
/**********************************
** 函数名: SortNum
** 输 入: int iStudentNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[]
** iStudentNum--学生人数
** iSortScore[][7]--用于重新排序的分数数组
** lSortNum[]--用于重新排序的学号数组
** cSortName[40][20]--用于重新排序的姓名数组
** iSortSumStudent[]--用于重新排序的总分数组
** 功能描述: 按学号由小到大排出成绩表
************************************/
void SortNum(int iStudentNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[])
{
    int i,iMax,j,iTemp,k;
    long lTemp;
    char cTemp[20];
    for (i=0;i<iStudentNum;i++)//排序采用选择排序
    {
        iMax=i;//将首个元素坐标置为最值坐标
        for (j=i+1;j<iStudentNum;j++)//遍历从i往后的元素
        {
            if (lSortNum[j]<lSortNum[iMax])//将j对应的值与当前最值比较
            {
                iMax=j;//符合条件时将j置为最值坐标
            }

        }
        if (iMax!=i)
        {
            //交换最值与本轮首个元素及其对应的各科分数的位置
            for (k=0;k<iSubjectNum;k++)
            {
                iTemp=iSortScore[iMax][k];
                iSortScore[iMax][k]=iSortScore[i][k];
                iSortScore[i][k]=iTemp;
            }
            //交换学号，姓名，总分位置
            lTemp=lSortNum[iMax];
            lSortNum[iMax]=lSortNum[i];
            lSortNum[i]=lTemp;
            iTemp=iSortSumStudent[iMax];
            iSortSumStudent[iMax]=iSortSumStudent[i];
            iSortSumStudent[i]=iTemp;
            strcpy(cTemp,cSortName[iMax]);
            strcpy(cSortName[iMax],cSortName[i]);
            strcpy(cSortName[i],cTemp);
        }

    }

}
/**********************************
** 函数名: Search
** 输 入: int iLeft,int iRight,int iSortScore[][7],long lSortNum[],long lSearchNum,int iSortSumStudent[]
** 输 出: iRank iSortScore[iCount_1][7],iSortSumStudent[iCount_1]
** lSearchNum--查询的学号
** iStudentNum--学生人数
** iSortScore[][7]--用于重新排序的各科分数数组
** iSortSumStudent[]--用于重新排序的总分数组
** lSortNum[]--用于重新排序的学号数组
** iRank--学生排名
** iSortScore[iCount_1][7]--被查找学生的各科分数
** iSortSumStudent[iCount_1]--被查找学生的总分
** 功能描述: 按学号查询学生排名，各科成绩及总成绩
************************************/
void Search(int iLeft,int iRight,int iSortScore[][7],long lSortNum[],long lSearchNum,int iSortSumStudent[])
{
    int iCount_1,iCount_2,iRank=1,iMid,iFlag=0;
    if (iLeft>iRight)//当左坐标大于右坐标时仍未找到，提示用户
    {
        printf("未找到该学号对应的同学");

    }
    else
    {
        iMid=(iLeft+iRight)/2;
        if (lSortNum[iMid]==lSearchNum)
        {
            iCount_1=iMid;
            iFlag=1;//一旦找到，将标志变量置为1
        }
        else if (lSortNum[iMid]>lSearchNum)
        {
            Search(iLeft,iMid-1,iSortScore,lSortNum,lSearchNum,iSortSumStudent);//更改右坐标，左坐标不变
        }
        else
        {
            Search(iMid+1,iRight,iSortScore,lSortNum,lSearchNum,iSortSumStudent);//更改左坐标，右坐标不变
        }
    }

    if (iFlag==1)
    {
        for (iCount_2=0;iCount_2<iStudentNum;iCount_2++)
        {
            if (iSortSumStudent[iCount_2]>iSortSumStudent[iCount_1])
            {
                iRank+=1;//每当有其余分数高于本分数，排名加1
            }
        }
        printf("排名：%d ",iRank);
        for (i=0;i<iSubjectNum;i++)
        {
            printf("各科分数：%d ",iSortScore[iCount_1][i]);
        }
        printf("总分：%d\n",iSortSumStudent[iCount_1]);
    }

}
/**********************************
** 函数名: Analysis
** 输 入: int iStudentNum,int iSortScore[][7]
** 输 出: cGrade[iCount_1] iTotal[iCount_1] (float)iTotal[i][iCount_1]*100/iStudentNum
** iStudentNum--学生人数
** iSortScore[][7]--用于重新排序的各科分数数组
** cGrade[]--不同的等级的名称数组
** iTotal[][]--统计各科不同等级人数的数组
** (float)iTotal[i][iCount_1]*100/iStudentNum--各科不同等级人数所占百分比
** 功能描述: 按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格 (0—59分)5个类别，统计每个类别的人数以及所占的百分比
************************************/
void Analysis(int iStudentNum,int iSortScore[][7])
{
    int iTotal[7][5]={0};
    char cGrade[5][10]={"优秀","良好","中等","及格","不及格"};//从第1到第5位分别对应五个不同等级
    int iCount_1;
    for (i=0;i<iSubjectNum;i++)
    {
        for (iCount_1=0;iCount_1<iStudentNum;iCount_1++)
        {
            if (iSortScore[iCount_1][i]>=90)
            {
                iTotal[i][0]+=1;
            }
            else if (iSortScore[iCount_1][i]>=80)
            {
                iTotal[i][1]+=1;
            }
            else if (iSortScore[iCount_1][i]>=70)
            {
                iTotal[i][2]+=1;
            }
            else if (iSortScore[iCount_1][i]>=60)
            {
                iTotal[i][3]+=1;
            }
            else
            {
                iTotal[i][4]+=1;
            }
        }
    }
    for (i=0;i<iSubjectNum;i++)
    {
        printf("科目%d: ",i+1);
        for (iCount_1=0;iCount_1<5;iCount_1++)
        {
            //输出等级名称，符合该等级的分数个数，以及所占比例
            printf(" %s: %d %.2f %% ",cGrade[iCount_1],iTotal[i][iCount_1],(float)iTotal[i][iCount_1]*100/iStudentNum);
        }
        printf("\n");
    }

}
int iDescendScore(int a,int b)
{
    return a>b;//若左元素大于右元素，返回真；否则返回假
}
int iAscendScore(int a,int b)
{
    return a<b;
}
/**********************************
** 函数名: SortName
** 输 入: int iStudentNum,int iSubjectNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[]
** 输 出: int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[]
** iStudentNum--学生人数
** iSortScore[][7]--用于重新排序的分数数组
** lSortNum[]--用于重新排序的学号数组
** cSortName[40][20]--用于重新排序的姓名数组
** iSortSumStudent[]--用于重新排序的总分数组
** 功能描述: 按姓名字典序由小到大排出成绩表
************************************/

void SortName(int iStudentNum,int iSubjectNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[])
{
    int i,iMax,j,iTemp;
    long lTemp;
    char cTemp[20];
    for (i=0;i<iStudentNum-1;i++)//排序采用选择排序
    {
        iMax=i;//将首个元素坐标置为最值坐标
        for (j=i+1;j<iStudentNum;j++)//遍历从i往后的元素
        {
            if (strcmp(cSortName[j],cSortName[iMax])<=0)//将j对应的值与当前最值比较
            {
                iMax=j;//符合条件时将j置为最值坐标
            }

        }
        if (iMax!=i)
        {
            //交换最值与本轮首个元素对应的各科分数的位置
            for (k=0;k<iSubjectNum;k++)
            {
                iTemp=iSortScore[iMax][k];
                iSortScore[iMax][k]=iSortScore[i][k];
                iSortScore[i][k]=iTemp;
            }
            //交换最值与本轮首个元素对应的总分，学号，姓名的位置
            lTemp=lSortNum[iMax];
            lSortNum[iMax]=lSortNum[i];
            lSortNum[i]=lTemp;
            iTemp=iSortSumStudent[iMax];
            iSortSumStudent[iMax]=iSortSumStudent[i];
            iSortSumStudent[i]=iTemp;
            strcpy(cTemp,cSortName[iMax]);
            strcpy(cSortName[iMax],cSortName[i]);
            strcpy(cSortName[i],cTemp);
        }

    }
    for (i=0;i<iStudentNum;i++)
    {
        printf("学号%d \n",lSortNum[i]);
        for (j=0;j<iSubjectNum;j++)
        {
            printf("各科分数：%d ",iSortScore[i][j]);
        }
        printf("总分：%d ",iSortSumStudent[i]);
        puts(cSortName[i]);
    }
}
/**********************************
** 函数名: SearchName
** 输 入: int iStudentNum,int iSortScore[][7],char cSortName[40][20],int iSumStudent[]
** 输 出: iRank iSortScore[iCount_1][7] iSumStudent[]
** iStudentNum--学生人数
** iSortScore[][7]--用于重新排序的各科分数数组
** iSortSumStudent[]--用于重新排序的总分数组
** lSortNum[]--用于重新排序的学号数组
** iRank--学生排名
** iSortScore[iCount_1][7]--被查找学生的各科分数
** iSortSumStudent[iCount_1]--被查找学生的总分
** 功能描述: 按姓名查询学生排名及成绩
************************************/
void SearchName(int iStudentNum,int iSortScore[][7],char cSortName[40][20],int iSumStudent[])
{
    int iCount_1,iCount_2,iRank=1;
    char cSearchName[20];
    printf("请输入要查询的学生名字");
    fflush(stdin);
    gets(cSearchName);

    for (iCount_1=0;iCount_1<iStudentNum;iCount_1++)//遍历姓名数组中的每个元素
    {

        if (strcmp(cSortName[iCount_1],cSearchName)==0)//一旦找到立刻跳出循环，此时iCount记录下姓名对应的坐标
        {
            break;
        }

    }
    if (iCount_1<iStudentNum)
    {
        for (iCount_2=0;iCount_2<iStudentNum;iCount_2++)
        {
            if (iSumStudent[iCount_2]>iSumStudent[iCount_1])
            {
                iRank+=1;//每当有其余分数高于本分数，排名加1
            }
        }

        printf("%d ",iRank);
        for (i=0;i<iSubjectNum;i++)
        {
            printf("%d ",iSortScore[iCount_1][i]);
        }
        printf("%d\n",iSumStudent[iCount_1]);
    }

}

