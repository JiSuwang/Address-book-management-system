#include<iostream>
#include<string>
using namespace std;
#define Max 1000

//联系人结构
struct linkMan
{
    string name;
    int sex;
    int age;
    string tele;
    string address;
};

//通讯录结构
struct List
{
    struct linkMan Arry[Max];
    int size;
};

void showMenu();
void add(List*);
void showLinkMan(List*);
int checkLinkMan(List*,string);
void deleteLinkMan(List*);
void seekLinkMan(List*);
void changeLinkMan(List*);
void clearLinkMan(List*);

//主函数
int main()
{
    showMenu();
    List list;
    list.size=0;
    int select = 0;
    while(true)
    {
        cin>>select;//输入选择
        switch (select)
        {
        case 0://退出
            cout<<"已退出"<<endl;
            return 0;
            break;
        case 1://添加
            add(&list);
            break;
        case 2 ://显示
            showLinkMan(&list);
            break;
        case 3 ://删除
            deleteLinkMan(&list);
            break;
        case 4 ://查找
            seekLinkMan(&list);
            break;
        case 5 ://修改
            changeLinkMan(&list);
            break;
        case 6 ://清空
            clearLinkMan(&list);
            break;
        default:
            break;
        }
    }
    return 0;
}

//菜单界面
void showMenu()
{
    cout<<"****************"<<endl;
    cout<<"**1.添加联系人**"<<endl;
    cout<<"**2.显示联系人**"<<endl;
    cout<<"**3.删除联系人**"<<endl;
    cout<<"**4.查找联系人**"<<endl;
    cout<<"**5.修改联系人**"<<endl;
    cout<<"**6.清空联系人**"<<endl;
    cout<<"**0.退出通讯录**"<<endl;
    cout<<"****************"<<endl;
}

//通讯录添加
void add(List* st)
{
    if(st->size<Max)
    {
        linkMan man;
        cout<<"请输入姓名"<<endl;
        cin>>man.name;
        cout<<"请输入性别"<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while(true)
        {
            cin>>man.sex;
            if(man.sex!=1&&man.sex!=2)
            {
                cout<<"输入有误，请重新输入"<<endl;
            }
            else
            {
                break;
            }
        }
        cout<<"请输入年龄"<<endl;
        cin>>man.age;
        cout<<"请输入电话号"<<endl;
        cin>>man.tele;
        cout<<"请输入地址 "<<endl;
        cin>>man.address;
        st->Arry[st->size]=man;
        st->size++;
        cout<<"添加成功"<<endl;
    }
    else
    {
        cout<<"通讯已满"<<endl;
        return;
    }
}

//通讯录显示
void showLinkMan(List* st)
{
    if (st->size<=0)
    {
        cout<<"通讯录中无人"<<endl;
    }
    else
    {
        cout<<"通讯录中的联系人有："<<endl; 
        for(int i =0; i < st->size; i++)
            {
                cout<<st->Arry[i].name<<endl;
            }
    }
}

//检测联系人是否存在，如果存在，返回数组的下标，否则返回-1
int checkLinkMan(List* st,string cName)
{
    int j = -1;
    for(int i = 0; i<st->size;i++)
    {
        if (cName==st->Arry[i].name)
        {
            j = i;
        }
    }
    return j==-1? -1:j;
}

//删除联系人
void deleteLinkMan(List* st)
{
    cout<<"请输入删除人的姓名"<<endl;
    string name;
    cin>>name;
    int check = checkLinkMan(st,name);
    if (check==-1)
    {
        cout<<"查无此人"<<endl;
    }
    else
    {
        for(check;check<st->size-1;check++)
        {
            st->Arry[check] = st->Arry[check+1];
        }
        st->size--;
        cout<<"删除成功"<<endl;
    }
}

//查找联系人
void seekLinkMan(List* st)
{
    cout<<"请输入查找人的姓名"<<endl;
    string name;
    cin>>name;
    int seek = checkLinkMan(st,name);
    if(seek==-1)
    {
        cout<<"查无此人"<<endl;
    }
    else
    {
        cout<<"联系人姓名："<<st->Arry[seek].name<<"\t";
        cout<<"联系人性别："<<(st->Arry[seek].sex==1? "男":"女")<<"\t";
        cout<<"联系人年龄："<<st->Arry[seek].age<<"\t";
        cout<<"联系人电话："<<st->Arry[seek].tele<<"\t";
        cout<<"联系人地址："<<st->Arry[seek].address<<endl;
    }
}

//修改联系人
void changeLinkMan(List* st)
{
    cout<<"请输入修改人的姓名"<<endl;
    string name;
    cin>>name;
    int change = checkLinkMan(st,name);
    if(change==-1)
    {
        cout<<"查无此人"<<endl;
    }
    else
    {
        cout<<"请输入修改的姓名"<<endl;
        cin>>st->Arry[change].name;
        cout<<"请输入修改的性别"<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while(true)
        {
            cin>>st->Arry[change].sex;
            if(st->Arry[change].sex!=1&&st->Arry[change].sex!=2)
            {
                cout<<"输入有误，请重新输入"<<endl;
            }
            else
            {
                break;
            }
        }
        cout<<"请输入修改的年龄"<<endl;
        cin>>st->Arry[change].age;
        cout<<"请输入修改的电话号"<<endl;
        cin>>st->Arry[change].tele;
        cout<<"请输入修改的地址 "<<endl;
        cin>>st->Arry[change].address;
        cout<<"修改成功"<<endl;
    }
}

//清空通讯录
void clearLinkMan(List* st)
{
    st->size=0;
    cout<<"清除成功"<<endl;
}