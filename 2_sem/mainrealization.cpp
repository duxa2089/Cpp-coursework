#include "header.h" // ���������� ���� ���������

void FileInput(vector <Product*> &productvector) //�������� ����� �� ��� ��������� � �� ������
{
    string n;
    int i = 0; //������� ��� �������� �������
    ifstream fin("File.txt"); //�������� ����� ��� ����������
    while (fin >> n) //���� ��������� ���� �������� ����������, �� �������� ����������
    {
        productvector.push_back (new Product(0)); //������� ������, ��� ������ � ���� ����������
        fin >> n; //������������� ������ ����
        fin >> n;
        fin.ignore(); //������������� �������
        fin.getline(productvector[i]->name,100); // ������� ������ �� �����
        fin >> n;
        fin >> n;
        fin.ignore();
        fin.getline(productvector[i]->article,100);
        fin >> n;
        fin >> n;
        fin >> productvector[i]->count;
        fin >> n;
        fin >> n;
        fin >> productvector[i]->price;
        i++; //������� ����� �������� �������
    }
    fin.close(); //�������� �����
}
void FileOutput(vector <Product*> &productvector){  //������ ������� � ����
ofstream fout;
  fout.open("File.txt",ios_base::out | ios_base::trunc); //������� ��� ������, �������������� ������� ���
  for (int i = 0; i < productvector.size(); i++) //������ ���� �������� � ����
            {
                fout<<i + 1<<")"<<endl;
                fout<<"����������� ������: " << productvector[i]->name<<endl;
                fout<<"������� ������: " << productvector[i]->article<<endl;
                fout<<"���������� ������: " << productvector[i]->count<<endl;
                fout<<"���� ������: " << productvector[i]->price<<endl;
            }
  fout.close(); //�������� �����
}

void Main(vector <Product*> &productvector)  //����
{
    char choice; //���������� ������
    int flag = 0; //���� while
    while (flag != 1) //��� ����������� ��������� ����
    {
        cout << "��������� ��� ���������� ������������� ������." << endl;
        cout << "1.�������� ����� � ������� �����." << endl;
        cout << "2.������������� ������ � ������ � ������� �����." << endl;
        cout << "3.�������� ������ � ������." << endl;
        cout << "4.������������� ������ � ���������� �������" << endl;
        cout << "5.������� ���������� ������ �������" << endl;
        cout << "6.����� �� ���������" << endl;
        cout << "�������� �����:" << endl;
        cin >> choice; //������������� ���������� ������
        int ClearConsole = 0; //���������� �������� �������� �������
        system("cls"); //������� �������
        switch (choice) //���������� ������ ��������
        {
        case '1':
        {
            Case1(productvector); //������ ������� �����
            break;
        }
        case '2':
        {
            int case2;
            case2 = Case2(productvector);   //������ ������� � �����
            if (case2 == 3) //�������� �� ������� �������
            {
                cout << "������ ������� ����" << endl;
                ClearConsole = 1; //��������� ��������, ����� ���� ����� ��������� ����
            }
            if (case2 == 2) //�������� �� ������� ������ �������� � �������
            {
                cout << "������ � ����� ��������� ��� � ������" << endl;
                ClearConsole = 1; //��������� ��������, ����� ���� ����� ��������� ����
            }
            break;
        }
        case '3':
        {
            int case3;
            case3 = Case3(productvector); //������ ������� � �����
            if (case3 == 3)   //�������� �� ������� �������
            {
                cout << "������ ������� ����" << endl;
                ClearConsole = 1; //��������� ��������, ����� ���� ����� ��������� ����
            }
            if (case3 == 2)   //�������� �� ������� ������ �������� � �������
            {
                cout << "������ � ����� ��������� ��� � ������" << endl;
                ClearConsole = 1; //��������� ��������, ����� ���� ����� ��������� ����
            }
            break;
        }
        case '4':
        {
            Case4(productvector); //�������� ������� � �����
            break;
        }
        case '5':
        {
            ClearConsole = 1; //��������� ��������, ����� ������� ������ �������
            Case5(productvector); //����� ������� � �����
            break;
        }
        case '6':
        {
            flag = 1; //��� ������ �� ����� While
            break;
        }
        default: //� ������ �������� �������, ������� ������� ����������� ������
        {
            char choice_exit; //������������� ���������� ������ �������
            int flag1 = 1; //���� while
            cout << "������ �����, ���������� ������ � ����������?(Y/N)" << endl;
            while (flag1!=0)
            {
                cin >> choice_exit;
                switch (choice_exit)
                {
                case 'Y':
                case 'y':
                {
                    flag1 = 0; //���� ������������ ����� �����, �������� ����
                    break;
                }
                case 'N':
                case 'n':
                {
                    flag1 = 0; //����� ���������� ������ � ����
                    flag = 1;
                    break;
                }
                default:
                {
                    cout << "�������� ������, ��������� �����" << endl; //��� �������� ��������, ��������� ���������� �����
                    break;
                }
                }
            }
            break;
        }
        }
        if (ClearConsole == 0) //���� ������� �� ���������, �� �������� �������
            system("cls"); //������� �������
    }
}
