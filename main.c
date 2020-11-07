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
    while (iChoice!=0)//���û�����0ʱ��������
    {
        iRet=scanf("%d",&iChoice);
        if (iRet==1)
        {
            if (iChoice==1) iInputFinish=1;
            if (iInputFinish==0)
            {
                printf("��ܰ��ʾ������ִ��ָ��1��������\n");
            }
            else
            {
                switch(iChoice)
                {
                case 1:
                    printf("������ѧ������");
                    scanf("%d",&iStudentNum);
                    printf("������ѧ������");
                    scanf("%d",&iSubjectNum);
                    Input(iStudentNum,iSubjectNum,lEachNum,iEachScore,iSortScore,lSortNum,cEachName,cSortName);
                    break;//����switch
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

                        printf("ѧ�ţ�%d \n",lSortNum[i]);
                        for (j=0;j<iSubjectNum;j++)
                        {
                            printf("���Ʒ�����%d ",iSortScore[i][j]);
                        }
                        printf("�ܷ֣�%d ������",iSortSumStudent[i]);
                        puts(cSortName[i]);
                    }
                    break;
                case 8:
                    SortName(iStudentNum,iSubjectNum,iSortScore,lSortNum,cSortName,iSortSumStudent);
                    break;
                case 9:
                    printf("������Ҫ��ѯ��ѧ��ѧ��\n");
                    lRet=scanf("%ld",&lSearchNum);
                    while (lRet!=1 || lSearchNum<=0 )
                    {
                        printf("��������Ч��ѧ��:\n");//��û�ж�������ʱ��ʾ�û�
                        fflush(stdin);//��ջ�����
                        lRet=scanf("%ld",&lSearchNum);
                    }

                    SortNum(iStudentNum,iSortScore,lSortNum,cSortName,iSortSumStudent);//�ȵ���ѧ��������
                    Search(0,iStudentNum,iSortScore,lSortNum,lSearchNum,iSortSumStudent);//���ַ�����
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
                    fflush(stdin);//�������ʱ��ջ�����

                }
            }
        }
        else
        {
            printf("����Ƿ��ַ�����������\n");
            fflush(stdin);//�������ʱ��ջ�����
        }

        system("pause");//�û������������
        system("cls"); //�������ʱ�����Ļ
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
** ������: Input
** �� ��:int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],int iSortScore[][7],long lSortNum[],char cEachName[40][20],char cSortName[40][20]
** iStudentNum--ѧ������
** int iSubjectNum--��Ŀ��
** lEachNum[]--������˳���ѧ������
** iEachScore[][7]--������˳��ĸ��Ʒ�������
** iSortScore[]--������������ĸ��Ʒ�������
** lSortNum[]--�������������ѧ������
** cEachName[][]--������˳�����������
** cSortName[][]--���������������������
** ��������: ��ȡ�û������ѧ�ź͸��Ʒ���

************************************/
Input(int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],int iSortScore[][7],long lSortNum[],char cEachName[40][20],char cSortName[40][20])
{
    int i,j;
    char a[]="a";
    for (i=0;i<iStudentNum;i++)
    {
        fflush(stdin);
        printf("��������");
        gets(cEachName[i]);
        strcpy(cSortName[i],cEachName[i]);//�Ѱ�����˳����������鸴�Ƶ����������������������
        printf("����ѧ��");
        scanf("%d",&lEachNum[i]);
        lSortNum[i]=lEachNum[i];//�Ѱ�����˳���ѧ�����鸴�Ƶ��������������ѧ������
        printf("����������Ʒ���");
        for (j=0;j<iSubjectNum;j++)
        {
            scanf("%d",&iEachScore[i][j]);
            iSortScore[i][j]=iEachScore[i][j];//�Ѱ�����˳��ķ������鸴�Ƶ�������������ķ�������
        }



    }
}
/**********************************
** ������: List
** �� ��: int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],char cEachName[40][20],int iSumStudent[],float fAverStudent[]
** �����long lEachNum[],int iEachScore[][7],char cEachName[40][20],int iSumStudent[],float fAverStudent[]
** iStudentNum--ѧ������
** int iSubjectNum--��Ŀ��
** lEachNum[]--������˳���ѧ������
** iEachScore[][7]--������˳��ĸ��Ʒ�������
** iSortScore[]--������������ĸ��Ʒ�������
** lSortNum[]--�������������ѧ������
** cEachName[][]--������˳�����������
** cSortName[][]--���������������������
** ��������:������˳�����ѧ�����������Ʒ������ܷ֣�ƽ����
************************************/
void List(int iStudentNum,int iSubjectNum,long lEachNum[],int iEachScore[][7],char cEachName[40][20],int iSumStudent[],float fAverStudent[])
{
    int i;
    for (i=0;i<iStudentNum;i++)
    {
        printf("ѧ��%d ",lEachNum[i]);
        printf("���Ʒ����� ");
        for (j=0;j<iSubjectNum;j++)
        {
            printf("%d ",iEachScore[i][j]);
        }
        printf("�ܷ֣�%d ",iSumStudent[i]);
        printf("ƽ���֣�%.1f ������",fAverStudent[i]);
        puts(cEachName[i]);
    }
}
/**********************************
** ������: CalcCourse
** ���룺int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumCourse[],float fAverCourse[]
** iStudentNum--ѧ������
** iSubjectNum--ѧ�ƿ���
** iEachScore[][7]--������˳��ķ�������
** iSumCourse[]--ÿ�ſγ̵��ܷ�
** fAverCourse[]--ÿ�ſγ̵�ƽ����
** ��������:����ÿ�ſγ̵��ܳɼ���ƽ����
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
** ������: CalcStudent
** ���룺int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumStudent[],float fAverStudent[],int iSortSumStudent[]
** iStudentNum--ѧ������
** iSubjectNum--ѧ�ƿ���
** iEachScore[][7]--������˳��ķ�������
** iSumStudent[]--ÿ��ѧ�����ܷ�
** fAverStudent[]--ÿ��ѧ����ƽ����
** iSortSumStudent[]--���������ÿ��ѧ�����ܷ�
** ��������:����ÿ��ѧ�����ܳɼ���ƽ����

************************************/
void CalcStudent(int iStudentNum,int iSubjectNum,int iEachScore[][7],int iSumStudent[],float fAverStudent[],int iSortSumStudent[])
{
    int i,j;
    for (i=0;i<iStudentNum;i++)
    {
        iSumStudent[i]=0;//���ֹܷ���������¼���ʱ��������
        for (j=0;j<iSubjectNum;j++)
        {
            iSumStudent[i]+=iEachScore[i][j];

        }
        iSortSumStudent[i]=iSumStudent[i];
        fAverStudent[i]=(float)iSumStudent[i]/iSubjectNum;

    }


}


/**********************************
** ������: Sort
** �� ��: int iStudentNum,long lSortNum[],int (*FuncPoint)(int a,int b),char cSortName[40][20],int iSortSumStudent[]
** �� ����i+1 iStudentNum-i lSortNum[] cSortName[40][20]
** iStudentNum--ѧ������
** iSortSumStudent[]--��������������ܷ�����
** lSortNum[]--�������������ѧ������
** (*FuncPoint)(int a,int b)--ָ����������ͬ�����׼�������ֵ�ĺ���ָ��
** i+1 iStudentNum-i--���ֲ�ͬ�����Ӧ������
** cSortName[40][20]--���������������������
** iSumStudent[]--ÿ��ѧ�����ܷ�
** ��������: ���ܳɼ��ɸߵ���(���ɵ͵���)�ų����α�
************************************/
void Sort(int iStudentNum,long lSortNum[],int (*FuncPoint)(int a,int b),char cSortName[40][20],int iSortSumStudent[],int iSortScore[][7])
{
    int i,iMax,j,iTemp;
    long lTemp;
    char cTemp[20];
    for (i=0;i<iStudentNum;i++)//�������ѡ������
    {
        iMax=i;//���׸�Ԫ��������Ϊ��ֵ����
        for (j=i+1;j<iStudentNum;j++)//������i�����Ԫ��
        {
            if ((*FuncPoint)(iSortSumStudent[j],iSortSumStudent[iMax]))//��j��Ӧ��ֵ�뵱ǰ��ֵ�Ƚ�
            {
                iMax=j;//��������ʱ��j��Ϊ��ֵ����
            }

        }
        if (iMax!=i)
        {
            //������ֵ�뱾���׸�Ԫ�ؼ����Ӧ��ѧ�ŵ�λ��
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
        if (iChoice==5)//�ֲ�ͬ�������׼������
        {
            printf("������ %d ѧ�ţ�%d ������",i+1,lSortNum[i]);
            puts(cSortName[i]);
        }

        else
        {
            printf("������ %d ѧ�ţ�%d ������",iStudentNum-i,lSortNum[i]);
            puts(cSortName[i]);
        }
    }
}
/**********************************
** ������: SortNum
** �� ��: int iStudentNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[]
** iStudentNum--ѧ������
** iSortScore[][7]--������������ķ�������
** lSortNum[]--�������������ѧ������
** cSortName[40][20]--���������������������
** iSortSumStudent[]--��������������ܷ�����
** ��������: ��ѧ����С�����ų��ɼ���
************************************/
void SortNum(int iStudentNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[])
{
    int i,iMax,j,iTemp,k;
    long lTemp;
    char cTemp[20];
    for (i=0;i<iStudentNum;i++)//�������ѡ������
    {
        iMax=i;//���׸�Ԫ��������Ϊ��ֵ����
        for (j=i+1;j<iStudentNum;j++)//������i�����Ԫ��
        {
            if (lSortNum[j]<lSortNum[iMax])//��j��Ӧ��ֵ�뵱ǰ��ֵ�Ƚ�
            {
                iMax=j;//��������ʱ��j��Ϊ��ֵ����
            }

        }
        if (iMax!=i)
        {
            //������ֵ�뱾���׸�Ԫ�ؼ����Ӧ�ĸ��Ʒ�����λ��
            for (k=0;k<iSubjectNum;k++)
            {
                iTemp=iSortScore[iMax][k];
                iSortScore[iMax][k]=iSortScore[i][k];
                iSortScore[i][k]=iTemp;
            }
            //����ѧ�ţ��������ܷ�λ��
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
** ������: Search
** �� ��: int iLeft,int iRight,int iSortScore[][7],long lSortNum[],long lSearchNum,int iSortSumStudent[]
** �� ��: iRank iSortScore[iCount_1][7],iSortSumStudent[iCount_1]
** lSearchNum--��ѯ��ѧ��
** iStudentNum--ѧ������
** iSortScore[][7]--������������ĸ��Ʒ�������
** iSortSumStudent[]--��������������ܷ�����
** lSortNum[]--�������������ѧ������
** iRank--ѧ������
** iSortScore[iCount_1][7]--������ѧ���ĸ��Ʒ���
** iSortSumStudent[iCount_1]--������ѧ�����ܷ�
** ��������: ��ѧ�Ų�ѯѧ�����������Ƴɼ����ܳɼ�
************************************/
void Search(int iLeft,int iRight,int iSortScore[][7],long lSortNum[],long lSearchNum,int iSortSumStudent[])
{
    int iCount_1,iCount_2,iRank=1,iMid,iFlag=0;
    if (iLeft>iRight)//�����������������ʱ��δ�ҵ�����ʾ�û�
    {
        printf("δ�ҵ���ѧ�Ŷ�Ӧ��ͬѧ");

    }
    else
    {
        iMid=(iLeft+iRight)/2;
        if (lSortNum[iMid]==lSearchNum)
        {
            iCount_1=iMid;
            iFlag=1;//һ���ҵ�������־������Ϊ1
        }
        else if (lSortNum[iMid]>lSearchNum)
        {
            Search(iLeft,iMid-1,iSortScore,lSortNum,lSearchNum,iSortSumStudent);//���������꣬�����겻��
        }
        else
        {
            Search(iMid+1,iRight,iSortScore,lSortNum,lSearchNum,iSortSumStudent);//���������꣬�����겻��
        }
    }

    if (iFlag==1)
    {
        for (iCount_2=0;iCount_2<iStudentNum;iCount_2++)
        {
            if (iSortSumStudent[iCount_2]>iSortSumStudent[iCount_1])
            {
                iRank+=1;//ÿ��������������ڱ�������������1
            }
        }
        printf("������%d ",iRank);
        for (i=0;i<iSubjectNum;i++)
        {
            printf("���Ʒ�����%d ",iSortScore[iCount_1][i]);
        }
        printf("�ܷ֣�%d\n",iSortSumStudent[iCount_1]);
    }

}
/**********************************
** ������: Analysis
** �� ��: int iStudentNum,int iSortScore[][7]
** �� ��: cGrade[iCount_1] iTotal[iCount_1] (float)iTotal[i][iCount_1]*100/iStudentNum
** iStudentNum--ѧ������
** iSortScore[][7]--������������ĸ��Ʒ�������
** cGrade[]--��ͬ�ĵȼ�����������
** iTotal[][]--ͳ�Ƹ��Ʋ�ͬ�ȼ�����������
** (float)iTotal[i][iCount_1]*100/iStudentNum--���Ʋ�ͬ�ȼ�������ռ�ٷֱ�
** ��������: �����㣨90��100�֣������ã�80��89�֣����еȣ�70��79�֣�������60һ69�֣��������� (0��59��)5�����ͳ��ÿ�����������Լ���ռ�İٷֱ�
************************************/
void Analysis(int iStudentNum,int iSortScore[][7])
{
    int iTotal[7][5]={0};
    char cGrade[5][10]={"����","����","�е�","����","������"};//�ӵ�1����5λ�ֱ��Ӧ�����ͬ�ȼ�
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
        printf("��Ŀ%d: ",i+1);
        for (iCount_1=0;iCount_1<5;iCount_1++)
        {
            //����ȼ����ƣ����ϸõȼ��ķ����������Լ���ռ����
            printf(" %s: %d %.2f %% ",cGrade[iCount_1],iTotal[i][iCount_1],(float)iTotal[i][iCount_1]*100/iStudentNum);
        }
        printf("\n");
    }

}
int iDescendScore(int a,int b)
{
    return a>b;//����Ԫ�ش�����Ԫ�أ������棻���򷵻ؼ�
}
int iAscendScore(int a,int b)
{
    return a<b;
}
/**********************************
** ������: SortName
** �� ��: int iStudentNum,int iSubjectNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[]
** �� ��: int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[]
** iStudentNum--ѧ������
** iSortScore[][7]--������������ķ�������
** lSortNum[]--�������������ѧ������
** cSortName[40][20]--���������������������
** iSortSumStudent[]--��������������ܷ�����
** ��������: �������ֵ�����С�����ų��ɼ���
************************************/

void SortName(int iStudentNum,int iSubjectNum,int iSortScore[][7],long lSortNum[],char cSortName[40][20],int iSortSumStudent[])
{
    int i,iMax,j,iTemp;
    long lTemp;
    char cTemp[20];
    for (i=0;i<iStudentNum-1;i++)//�������ѡ������
    {
        iMax=i;//���׸�Ԫ��������Ϊ��ֵ����
        for (j=i+1;j<iStudentNum;j++)//������i�����Ԫ��
        {
            if (strcmp(cSortName[j],cSortName[iMax])<=0)//��j��Ӧ��ֵ�뵱ǰ��ֵ�Ƚ�
            {
                iMax=j;//��������ʱ��j��Ϊ��ֵ����
            }

        }
        if (iMax!=i)
        {
            //������ֵ�뱾���׸�Ԫ�ض�Ӧ�ĸ��Ʒ�����λ��
            for (k=0;k<iSubjectNum;k++)
            {
                iTemp=iSortScore[iMax][k];
                iSortScore[iMax][k]=iSortScore[i][k];
                iSortScore[i][k]=iTemp;
            }
            //������ֵ�뱾���׸�Ԫ�ض�Ӧ���ܷ֣�ѧ�ţ�������λ��
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
        printf("ѧ��%d \n",lSortNum[i]);
        for (j=0;j<iSubjectNum;j++)
        {
            printf("���Ʒ�����%d ",iSortScore[i][j]);
        }
        printf("�ܷ֣�%d ",iSortSumStudent[i]);
        puts(cSortName[i]);
    }
}
/**********************************
** ������: SearchName
** �� ��: int iStudentNum,int iSortScore[][7],char cSortName[40][20],int iSumStudent[]
** �� ��: iRank iSortScore[iCount_1][7] iSumStudent[]
** iStudentNum--ѧ������
** iSortScore[][7]--������������ĸ��Ʒ�������
** iSortSumStudent[]--��������������ܷ�����
** lSortNum[]--�������������ѧ������
** iRank--ѧ������
** iSortScore[iCount_1][7]--������ѧ���ĸ��Ʒ���
** iSortSumStudent[iCount_1]--������ѧ�����ܷ�
** ��������: ��������ѯѧ���������ɼ�
************************************/
void SearchName(int iStudentNum,int iSortScore[][7],char cSortName[40][20],int iSumStudent[])
{
    int iCount_1,iCount_2,iRank=1;
    char cSearchName[20];
    printf("������Ҫ��ѯ��ѧ������");
    fflush(stdin);
    gets(cSearchName);

    for (iCount_1=0;iCount_1<iStudentNum;iCount_1++)//�������������е�ÿ��Ԫ��
    {

        if (strcmp(cSortName[iCount_1],cSearchName)==0)//һ���ҵ���������ѭ������ʱiCount��¼��������Ӧ������
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
                iRank+=1;//ÿ��������������ڱ�������������1
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

