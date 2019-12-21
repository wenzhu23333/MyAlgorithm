#include<bits/stdc++.h>
using namespace std;

class DNode
{
public:
    int x;
    int y;
    DNode* templeft;
    DNode* tempright;
    DNode(int xx=0,int yy=0,DNode* templeft=NULL,DNode* tempright=NULL)
    {
        x = xx;
        y = yy;
        this->templeft = templeft;
        this->tempright = tempright;
    }
    void setDNodeValues(int a,int b)
    {
    x = a;
    y = b;
    }
    void insertLeft()
    {
    DNode *newDNode = new DNode();
    this->templeft = newDNode;
    }
    void insertRight()
    {
    DNode *newDNode = new DNode();
    this->tempright = newDNode;
    }
    void deleteNode()
    {
    if(this->tempright!=NULL)
    this->tempright->templeft= this->templeft;
    //如果右边不为空则将右边元素指向当前元素的左边
    if(this->templeft!=NULL)
    this->templeft->tempright = this-> tempright;
    //同理
    delete this;
    }
    DNode* nextNodeLeft()
    {
        return templeft;
    }
    DNode* nextNodeRight()
    {
        return  tempright;
    }
    void printNode()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

int main()
{
int x,y;
//新建一个（1，2）链表节点
cout<<"新建一个（1，2）链表节点"<<endl;
DNode *test = new DNode(1,2);
test->printNode();
//展示该节点元素
test->insertLeft();
//test节点左侧插入一个空节点
test->nextNodeLeft()->setDNodeValues(2,3);
cout<<"左侧插入（2，3）节点"<<endl;
//对左侧空节点赋值（2，3）
test->nextNodeLeft()->printNode();
//展示左侧空节点赋值
test->insertRight();
//test节点右侧插入一个空节点
test->nextNodeRight()->setDNodeValues(3,4);
//对右侧空节点赋值（3，4）
cout<<"右侧插入（3，4）节点"<<endl;
test->nextNodeRight()->printNode();
//展示右侧空节点赋值
//此时链表为（2，3）-（1，2）-（3，4）
DNode *a = test->nextNodeRight();
//a为节点右侧元素的指针
DNode *b = test->nextNodeLeft();
cout<<"此时链表为（2，3）-（1，2）-（3，4）"<<endl;
//b为节点左侧元素的指针
cout<<"删除中间元素"<<endl;
test->deleteNode();
//删除test节点即（1，2）节点
//此时链表为（2，3）-（3，4）
cout<<"此时链表为（2，3）-（3，4）"<<endl;
cout<<"展示（3，4）节点的左侧元素"<<endl;
a->nextNodeLeft()->printNode();
//展示（3，4）节点的左侧元素
cout<<"展示（2，3）节点的右侧元素"<<endl;
b->nextNodeRight()->printNode();
return 0;
}
