#include "model.h"

pNode stuList = NULL;

//判断是否成功初始化链表
int init()
{
    pNode head = NULL;
    
	if(stuList==NULL)//如果第二行成功初始化
    {
        head = (pNode)malloc(sizeof(Node));

        if(NULL == head)//判断上一行的动态内存分配申请是否成功
		{
            return 0;
        }
        head->next = NULL;

        stuList = head;//将head赋值给stuList的头指针
        
		return 1;
    }
    return 0;
}

//在链表末尾添加节点,将结构体添加到链表中
int addNode(Student* pStu)
{
    pNode node = NULL;//定义动态节点
    pNode cur = NULL;//想要插入的节点

    //检查是否为stuList和cur分配空间
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
    
	//通过动态节点node定位到链表末尾节点，并把目标节点cur放到末尾节点node之后
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
//将Node中的data放入Student里面
Student* tra(int* pn)
{
    int i;
	pNode node = NULL;//定义一个动态节点
    Student* pStu = NULL;//定义一个Student类型的指针
    node = stuList->next;//定位首元节点的位置

    if(NULL == node)
	{
        return NULL;
	}

    node = stuList->next;
    //计算从首元节点开始有几个节点
	do
	{
        (*pn)++;
        node = node->next;
    }while(node != NULL);

    pStu = (Student*)malloc(sizeof(Student) * (*pn));

	node = stuList->next;
    //将Node中的data放入Student里面
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




