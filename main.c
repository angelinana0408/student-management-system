//This program is a student system

#include "model.h"
#include<string.h>

void addStu()
{
    Student stu;

    printf("Add Student Information\nPlease input student ID:");
    fflush(stdin);
	scanf("%d", &stu.Num);

    printf("Please input student's name: ");
    fflush(stdin);
	scanf("%s", stu.Name);

	printf("Please input student's sex('M'stands for male & 'F'stands for female): ");
    fflush(stdin);
	scanf("%c", &stu.Sex);

	printf("Please input student's age: ");
    fflush(stdin);
	scanf("%d", &stu.Age);

	printf("Please input student's Math grade: ");
    fflush(stdin);
	scanf("%f", &stu.MScore);

	printf("Please input student's English grade: ");
    fflush(stdin);
	scanf("%f", &stu.EScore);

	printf("Please input student's C grade: ");
    fflush(stdin);
	scanf("%f", &stu.CScore);

	
	if(addNode(&stu)==1)
	{
		printf("Succeed!\n");
	}
	else
	{
		printf("Failed!\n");
	}
	
}


void displayStu()
{
    Student* pStu = NULL;
    int n = 0,i;

   
	printf("Student ID\tName\tSex\tAge\tMath Grade\tEnglish Grade\tC Grade\n");

	pStu = tra(&n);

	if(pStu==NULL)
	{
		printf("Failed!\n");
		return;
	}
	for(i = 0;i<n;i++)
	{
		printf("%d\t%s\t%c\t%d\t%0.1f\t%0.1f\t%0.1f\n", pStu[i].Num, pStu[i].Name,pStu[i].Sex,pStu[i].Age,pStu[i].MScore,pStu[i].EScore,pStu[i].CScore);
	}

	free(pStu);
    
	pStu = NULL;
	
}

void searchStu()
{
	pNode node = NULL;//定义动态节点
	
	char stuname[20];
	printf("Please input the student name you want to search:\t");
	scanf("%s",&stuname);

	node = stuList;
	
	while( node != NULL)
	{
        if(strcmp(stuname,node->data.Name) == 0)
		{
			break;
		}
		node = node->next;
	
	}

	if(node == NULL)
	{
		printf("The student is not exist!");
	}
	else
	{
		printf("************The Information of the student*************\n");
		printf("Student ID\tName\tSex\tAge\tMath Grade\tEnglish Grade\tC Grade\n");
		printf("%d\t%s\t%c\t%d\t%0.1f\t%0.1f\t%0.1f\n", node->data.Num, node->data.Name,node->data.Sex,node->data.Age,node->data.MScore,node->data.EScore,node->data.CScore);

	}

}


int saveStu()
{
	Student* pStu = NULL;
	Student* saStu = NULL;
    int n = 0,i;
	FILE* pFile;
	
	if((pFile=fopen("stuInfo.txt","a"))==NULL)
	{
		if((pFile=fopen("stuInfo.txt","w"))==NULL)
		{
			return 0;
		}
	}
	
	pStu = tra(&n);
	saStu = pStu;
	for(i=0;i < n ;i++)
	{

		fprintf(pFile, "%d %s %c %d %f %f %f\n",saStu[i].Num,saStu[i].Name,saStu[i].Sex,
			            saStu[i].Age,saStu[i].MScore,saStu[i].EScore,saStu[i].CScore);
		//saStu = (pStu)++;
	}
	
	fclose(pFile);

	return 1;
}

//将文档中的内容读入链表中(从首元节点开始)
int readText()
{
	int row = 0;
	int flag;
	FILE *pFile=NULL;
    Student* preadStu;//要添加的结构体
	release();
	init();
	if( ( pFile = fopen("stuInfo.txt","rt")) == NULL)//打开文件失败就立刻退出
	{
		printf("Failed to open the file!\n");
		return 0;
	}
	
	preadStu = (Student*)malloc(sizeof(Student));
	
	while((flag = fscanf(pFile,"%d %s %c %d %f %f %f\n",&preadStu->Num,preadStu->Name,&preadStu->Sex,
			                                  &preadStu->Age,&preadStu->MScore,
											  &preadStu->EScore,&preadStu->CScore)) != -1)
	{
		addNode(preadStu);
		row++;
		printf("%d\t%d\n", row, flag);
	}
	free(preadStu);
	
	fclose(pFile);
	return row;

}
void deleteStu()
{
    char stu[16];

	printf("Please input student ID you want to delete:");
    fflush(stdin);
	scanf("%s",stu);

    if(deleteNode(stu)==1)
	{
        printf("Succeed!\n");
        return;
    }
    else
	{
        printf("Failed!\n");
        return;
    }
}
void modiStu()
{
	int nNum;
    char nName[20];
    char nSex;
    int nAge;
    float nMScore;
    float nEScore;
    float nCScore;
	int choice ;
	pNode node = NULL;//定义动态节点@@@@@
	char stuname[16];
	node = (pNode)malloc(sizeof(Node));
	printf("Please input student name you want to modify:");
    fflush(stdin);
	scanf("%s",stuname);
	if(stuList==NULL)
	{
        if(0 == init())
		{
            printf("Failed!");
			return ;
        }
    }

	node = stuList -> next;
	
	while((node->next != NULL)&&(strcmp(node->data.Name,stuname)!=0))
	{
        
		node = node->next;
	
	}

	if(node==NULL)
	{
		printf("The student is not exist!");
	}
	else
	{
		printf("************The Information of the student*************\n");
		printf("Student ID\tName\tSex\tAge\tMath Grade\tEnglish Grade\tC Grade\n");
		printf("%d\t%s\t%c\t%d\t%0.1f\t%0.1f\t%0.1f\n", node->data.Num, node->data.Name,node->data.Sex,node->data.Age,node->data.MScore,node->data.EScore,node->data.CScore);
		
		printf("What do you want to modify?\n"
			"1)Student ID\t2)Name\t3)Sex\t4)Age\t5)Math Grade\t6)English Grade\t7)C Grade\t8)quit\n"
			"Enter your choice:");
		while(1)
		{
			fflush(stdin);
			if((scanf("%d",&choice)==1)&&((choice<8)&&(choice>0)))//&&从左往右 直到遇上0，，，||从左往右直到遇上1
			{
				switch(choice)
				{
				case 1:
					printf("Enter your new Student ID:");
					fflush(stdin);
					scanf("%d",&nNum);
					node->data.Num=nNum;
					break;
				case 2:
					printf("Enter your new Name:");
					fflush(stdin);
					scanf("%s",nName);
					strcpy(node->data.Name,nName);
					break;
				case 3:
					printf("Enter your new Sex:");
					fflush(stdin);
					scanf("%c",&nSex);
					node->data.Sex=nSex;
					break;
				case 4:
					printf("Enter your new Age:");
					fflush(stdin);
					scanf("%d",&nAge);
					node->data.Age=nAge;
					break;
				case 5:
					printf("Enter your new Math Grade:");
					fflush(stdin);
					scanf("%f",&nMScore);
					node->data.MScore=nMScore;
					break;
				case 6:
					printf("Enter your new English Grade:");
					fflush(stdin);
					scanf("%f",&nEScore);
					node->data.EScore=nEScore;
					break;
				case 7:
					printf("Enter your new C Grade:");
					fflush(stdin);
					scanf("%f",&nCScore);
					node->data.CScore=nCScore;
					break;
				
				}
				printf("What else do you want to choose? Enter the number:");
				continue;
			}
			if(choice==0)
			{
				break;
			}
			else
			{
				printf("Invalid Input!Enter the choice again:");
				continue;
			}
		}
	}

}
int main()
{
    pNode stuList = NULL;//将链表内容初始化为空
	int choice;
	int cho;
    
	
	
        do
		{
            printf("********************************\n");
			printf("Student Information Management\n");
			printf("********************************\n\n\n");
			printf("*************Menu***************\n");
			printf("1.Add Student Info\n"
				   "2.Display Student Info\n"
				   "3.Search Student Info\n"
				   "4.Save Student Info\n"
				   "5.Read Student Info\n"
				   "6.Modify personal information\n"
				   "7.Delete Student Info\n"
				   "8.Analyse the student information\n"
				   "0.Exit System\n");
			printf("********************************\n"
				"Hint:\n"
				"If It's your first time to use this programme,choose the menu item '1' first,and save before you read!\n"
				"If It's not your  first to use th programme,choose the menu item '5' first and you don't need to read again in the later operation!\n"
				);
            printf("Please enter your option: ");
            fflush(stdin);
			scanf("%d", &choice);
			
            switch(choice)
			{
            case 1:
				{system("cls");
				addStu();}
				break;
            case 2:
				{system("cls");
				displayStu();}
				break;
			case 3:
				{system("cls");
				searchStu();}
				break;
			case 4:
				{
					system("cls");
					if(saveStu()==1)
					{
						printf("Succeed!\n");
					}
					else
					{
						printf("Failed!\n");
					}
				}
					break;
			case 5:
				{
					system("cls");
					printf("If you read the txt,the original internal storage will lose!\n"
						"Are you sure you want to read the txt.Enter '1'to read,'0'to conduct other function:");
					fflush(stdin);
					scanf("%d",&cho);
					if(cho==1)
					{	
						if(readText()==0)
						{
							printf("Failed!\n");
						}
						else
						{
							printf("Succeed!\n");
						
						}
					}
					else
					{
						break;
					}
				}
				break;
			case 6:
				{system("cls");
				modiStu();}
				break;
            case 7:
				{system("cls");
				deleteStu();}
				break;
			case 8:
				{system("cls");
				printf("There are %d students in the txt list.",readText());}break;
            case 0:
				{release();
				exit(1);}
            default :
				{system("cls");
				printf("Invalid item,enter again!\n");}
            }
        }while(choice != 0);
        
    system("pause");
    return 0;
}