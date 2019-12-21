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
    //����ұ߲�Ϊ�����ұ�Ԫ��ָ��ǰԪ�ص����
    if(this->templeft!=NULL)
    this->templeft->tempright = this-> tempright;
    //ͬ��
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
//�½�һ����1��2������ڵ�
cout<<"�½�һ����1��2������ڵ�"<<endl;
DNode *test = new DNode(1,2);
test->printNode();
//չʾ�ýڵ�Ԫ��
test->insertLeft();
//test�ڵ�������һ���սڵ�
test->nextNodeLeft()->setDNodeValues(2,3);
cout<<"�����루2��3���ڵ�"<<endl;
//�����սڵ㸳ֵ��2��3��
test->nextNodeLeft()->printNode();
//չʾ���սڵ㸳ֵ
test->insertRight();
//test�ڵ��Ҳ����һ���սڵ�
test->nextNodeRight()->setDNodeValues(3,4);
//���Ҳ�սڵ㸳ֵ��3��4��
cout<<"�Ҳ���루3��4���ڵ�"<<endl;
test->nextNodeRight()->printNode();
//չʾ�Ҳ�սڵ㸳ֵ
//��ʱ����Ϊ��2��3��-��1��2��-��3��4��
DNode *a = test->nextNodeRight();
//aΪ�ڵ��Ҳ�Ԫ�ص�ָ��
DNode *b = test->nextNodeLeft();
cout<<"��ʱ����Ϊ��2��3��-��1��2��-��3��4��"<<endl;
//bΪ�ڵ����Ԫ�ص�ָ��
cout<<"ɾ���м�Ԫ��"<<endl;
test->deleteNode();
//ɾ��test�ڵ㼴��1��2���ڵ�
//��ʱ����Ϊ��2��3��-��3��4��
cout<<"��ʱ����Ϊ��2��3��-��3��4��"<<endl;
cout<<"չʾ��3��4���ڵ�����Ԫ��"<<endl;
a->nextNodeLeft()->printNode();
//չʾ��3��4���ڵ�����Ԫ��
cout<<"չʾ��2��3���ڵ���Ҳ�Ԫ��"<<endl;
b->nextNodeRight()->printNode();
return 0;
}
