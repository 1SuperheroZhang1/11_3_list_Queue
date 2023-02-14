#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
//链表存储实现队列
typedef struct {
    LinkNode *front,*rear;//链表头 链表尾 也可以称队头 队尾
}LinkQueue;//先进先出
//初始化队列,使用带头结点的链表实现
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*) malloc(sizeof(LinkNode));//头和尾指向同一个结点
    Q.front->next=NULL;//头结点的next指针为NULL
}
//判断队列是否为空
bool IsEmpty(LinkQueue Q){
    if(Q.rear==Q.front){
        return true;
    }
    return false;
}
//入队,尾部插入法
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s=(LinkNode*) malloc(sizeof(LinkNode));//为新结点申请空间
    s->data=x;
    s->next=NULL;//要让next为NULL
    Q.rear->next=s;//rear始终指向尾部
    Q.rear=s;
}
//出队,头部删除法
bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.rear==Q.front){//判断队列是否为空
        return false;
    }
    LinkNode *p=Q.front->next;//头结点什么都没存，所以头结点的下一个结点才有数据
    x=p->data;//获取出队元素的值
    Q.front->next=p->next;//断链
    if(Q.rear==p){//当链表只剩余一个结点时，被删除后，要改变rear,置队列为空。删除的是最后一个结点
        Q.rear=Q.front;//队列置为空
    }
    free(p);
    return true;
}
//通过链表实现队列,头部删除法，尾部插入法
int main() {
    LinkQueue Q;
    InitQueue(Q);//初始化队列
    EnQueue(Q,3);
    EnQueue(Q,4);
//    EnQueue(Q,5);
//    EnQueue(Q,6);
//    EnQueue(Q,7);
    bool ret;
    ElemType element;//用于存储出队元素
    ret=DeQueue(Q,element);
    if(ret){
        printf("deQueue success element=%d\n",element);
    }else{
        printf("deQueue failed\n");
    }
    DeQueue(Q,element);
    ret=DeQueue(Q,element);
    if(ret){
        printf("deQueue success element=%d\n",element);
    }else{
        printf("deQueue failed\n");
    }
    return 0;
}
