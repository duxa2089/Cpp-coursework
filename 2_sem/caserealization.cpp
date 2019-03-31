#include "header.h" //���������� ������� ���� ���������
void Case1(vector <Product*> &productvector) //������ ������� �����
{
    productvector.push_back (new Product()); //������ � ������ ������ ������� � ������� ������������
}
int Case2(vector <Product*> &productvector) //������ ������� �����
{
    int flag_check=0; //���� �������� ������� ������
    int flag2=1; //���� ����� while
    int choice_change;
    if (productvector.size()<1) //�������� �� ������� �������
    {
        return 3;
    }
    else
    {
        Product prod_choice(0,0); //���������� ��� �������� ��������
        for (int i=0; i<productvector.size(); i++)
        {
            if (strcmp( productvector[i]->article, prod_choice.article) == 0) //����� ������� ��������
            {
                flag_check=1;
                while (flag2!=0) //���� ��������� ���������� � ������
                {
                    cout<<"����� ���������� ������� ��������?"<<endl;
                    cout<<"1.������������ ������"<<endl;
                    cout<<"2.������� ������"<<endl;
                    cout<<"3.���������� ������"<<endl;
                    cout<<"4.���� ������"<<endl;
                    cin>>choice_change;
                    switch(choice_change)
                    {
                    case 1:
                    {
                        cout<<"������� ����� ������������ ������"<<endl;
                        cin.ignore();
                        cin.getline(productvector[i]->name,100);
                        break;
                    }
                    case 2:
                    {
                        cout<<"������� ����� ������� ������"<<endl;
                        cin.ignore();
                        cin.getline(productvector[i]->article,100);
                        break;
                    }
                    case 3:
                    {
                        cout<<"������� ����� ���������� ������ (��.):"<<endl;
                        while(!(cin>>productvector[i]->count) || cin.get() != '\n')
                        {
                            cout<<"������� �����, � �� ������� !"<<endl;
                            cin.clear(); // ���������� ��� ���� ������, ������ ����� ���������� "�������"
                            cin.sync();//������ ������ �� �������
                            cout<<"������� ����� ���������� ������ (��.):"<<endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        cout<<"������� ����� ���� ������ (���.):"<<endl;
                        while(!(cin>>productvector[i]->price) || cin.get() != '\n')
                        {
                            cout<<"������� �����, � �� ������� !"<<endl;
                            cin.clear();
                            cin.sync();
                            cout<<"������� ����� ���� ������ (���.):"<<endl;
                        }
                        break;
                    }
                    default: //������� ��� ������������ �����
                    {
                        cout<<"������������ ����, ���������� �����"<<endl;
                        break;
                    }
                    }
                    char choise_exit2; //���������� ����������� ������
                    cout<<"���������� �������������� ������� ������?(Y/N)"<<endl;
                    cin>>choise_exit2;
                    switch(choise_exit2)
                    {
                    case'n':
                    case'N':
                    {
                        flag2=0;
                        break;
                    }
                    case'y':
                    case'Y':
                    {
                        flag2=1;
                        break;
                    }
                    default:
                    {
                        cout<<"�������� ������, ��������� �����"<<endl;
                        break;
                    }
                    }
                }
            }
        }
        if (flag_check==0)
        {
            return 2;
        }
    }
}
int Case3(vector <Product*> &productvector) //������ ������� � �����
{
    int flag_check=0; //���� ���������� ������� ��������
    if (productvector.size()<1) //�������� ������� �� �������
    {
        return 3;
    }
    else
    {
        Product prod_choice(0,0); //���������� �������� ��������
        for (int i=0; i<productvector.size(); i++)
        {
            if (strcmp( productvector[i]->article, prod_choice.article) == 0) //����� ������� ��������
            {
                flag_check=1; //���� ������ �������, ��������� ���� � ������ ���������
                productvector.erase(productvector.begin()+i); //�������� ������� �����
            }
        }
        if (flag_check==0) //�������� �� ���������� ������� ��������
        {
            return 2;
        }
    }
}
void Case4(vector <Product*> &productvector) //�������� ������� � �����
{
    Product swap(0); //���������� ������
    for (int i=0; i<productvector.size(); i++) //���������� �� ��������
        for(int j=i+1; j<productvector.size(); j++)
        {
            if (strcmp( productvector[i]->name, productvector[j]->name)>0)
            {
                swap=*productvector[i];
                *productvector[i]=*productvector[j];
                *productvector[j]=swap;
            }
        }
}
void Case5(vector <Product*> &productvector) //����� ������� � �����
{
    if (productvector.size()==0)  //�������� �� ������� �������
        cout<<"������ ����"<<endl;
    for (int i = 0; i < productvector.size(); i++) //����� ���� ������� � ������� ������� ������
    {
        cout<<i+1<<")";
        productvector[i]->printInfo();
    }
}
