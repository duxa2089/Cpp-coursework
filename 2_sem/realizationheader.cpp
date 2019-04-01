#include "header.h" // ���������� ������� � �������������
Product :: Product() // ����������� ����� ���������� � ������
{
    cout << "������� ������������ ������:" << endl;
    cin.ignore();  // ������������� ��������
    cin.getline(name,100); // ���������� ���� ������
    cout << "������� ������� ������:" << endl;
    cin.getline(article,100);
    cout << "������� ���������� ������ (��.):" << endl;
    while(!(cin >> count) || cin.get() != '\n')
    {
        cout << "������� �����, � �� ������� !" << endl;
        cin.clear(); // ���������� ��� ���� ������, �� ���� ����� ���������� "�������"
        cin.sync();// ������ ������ �� �������
        cout << "������� ���������� ������ (��.):" << endl;
    }
    cout << "������� ���� ������ (���.):" << endl;
    while(!(cin >> price) || cin.get() != '\n')
    {
        cout << "������� �����, � �� ������� !" << endl;
        cin.clear();
        cin.sync();
        cout << "������� ���� ������ (���.):" << endl;
    }
}
Product :: Product(int empty) {} // ����������� ��� ������
Product :: Product(int empty1, int empty2) // ����������� ��� �������� ��������
{
    cout << "������� ������� ������, ������� ����� ��������:" << endl;
    cin.ignore();
    cin.getline(article,100);
}
Product :: printInfo() // ����������� ����� ���������� � ������
{
    cout << "������������ ������: " << name << endl;
    cout << "������� ������: " << article << endl;
    cout << "���������� ������: " << count << " ��." << endl;
    cout << "���� ������: " << price << " ���." << endl << endl;
}
