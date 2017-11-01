#include "model.h"

pNode stuList = NULL;

//�ж��Ƿ�ɹ���ʼ������
int init()
{
    pNode head = NULL;
    
	if(stuList==NULL)//����ڶ��гɹ���ʼ��
    {
        head = (pNode)malloc(sizeof(Node));

        if(NULL == head)//�ж���һ�еĶ�̬�ڴ���������Ƿ�ɹ�
		{
            return 0;
        }
        head->next = NULL;

        stuList = head;//��head��ֵ��stuList��ͷָ��
        
		return 1;
    }
    return 0;
}

//������ĩβ��ӽڵ�,���ṹ����ӵ�������
int addNode(Student* pStu)
{
    pNode node = NULL;//���嶯̬�ڵ�
    pNode cur = NULL;//��Ҫ����Ľڵ�

    //����Ƿ�ΪstuList��cur����ռ�
	if(stuList==NULL)
	{
        if(0 == init())
		{
            return 0;
        }
    }
	cur = (pNode)malloc(sizeof(Node));
    
	if(cur==NULL)
	{
        return 0;
	}

    cur->data = *pStu;
    cur->next = NULL;

    node = stuList;
    
	//ͨ����̬�ڵ�node��λ������ĩβ�ڵ㣬����Ŀ��ڵ�cur�ŵ�ĩβ�ڵ�node֮��
	while(node->next != NULL)
	{
        node = node->next;
	}
    node->next = cur;
   
	return 1;
}

int deleteNode(char *n)
{
    pNode node = stuList;
    pNode pTemp = NULL;
    
	if(NULL == node)
	{
        return 0;
	}

    while(node->next != NULL)
	{
		if(strcmp(node->next->data.Name,n)==0)
		{
            pTemp = node->next;
            node->next = pTemp->next;

            free(pTemp);
            
			pTemp = NULL;
            
			return 1;
        }
        node = node->next;
    }
    return 0;
}
//��Node�е�data����Student����
Student* tra(int* pn)
{
    int i;
	pNode node = NULL;//����һ����̬�ڵ�
    Student* pStu = NULL;//����һ��Student���͵�ָ��
    node = stuList->next;//��λ��Ԫ�ڵ��λ��

    if(NULL == node)
	{
        return NULL;
	}

    node = stuList->next;
    //�������Ԫ�ڵ㿪ʼ�м����ڵ�
	do
	{
        (*pn)++;
        node = node->next;
    }while(node != NULL);

    pStu = (Student*)malloc(sizeof(Student) * (*pn));

	node = stuList->next;
    //��Node�е�data����Student����
	for(i = 0;node != NULL;i ++)
	{
        pStu[i] = node->data;
        node = node->next;
    }
    return pStu;
}

void release()
{
    pNode cur = stuList;
    pNode next = NULL;
    
	while(cur != NULL)
	{
        next = cur->next;
        
		free(cur);
        
		cur = next;
    }
    stuList = NULL;
}




