#include "header.h" // �������� �������, ����� �������, ������� �������
int main()
{
    SetConsoleCP(1251);             // ���������� �����������
    SetConsoleOutputCP(1251);        // ���������
    vector <Product*> productvector;   // ������� �������
    FileInput(productvector);           // �������� ����� �� ��� ��������� � �� ������
    Main(productvector);            // ����
    FileOutput(productvector);      // ������ ����� ������� � ����
    productvector.clear();          // ������� �������
    return 0;
}
