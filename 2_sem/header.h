#ifndef headerh // ������������ ����. ����������� ����������� ���������, �������� ������� � �������
#define headerh
#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class  Product //����� �������
{
 public:
    char name[100]; //��� ������
    char article[100]; //������� ������
    int count; //���������� ������
    double price; //���� ������
    ~Product() {};//���������� ������
    Product(); // ����������� ����� ���������� � ������
    Product(int empty); // ����������� ��� ������
    Product(int empty1, int empty2); //����������� ��� �������� ��������
    printInfo(); //������� ������ ���������� � ������
    friend istream& operator>>(istream &s,Product &v); //���������� �������� �����
};
void FileInput(vector <Product*> &productvector); //�������� ����� �� ��� ��������� � �� ������
void FileOutput(vector <Product*> &productvector); //������ ������� � ����
void Main(vector <Product*> &productvector); //����
void Case1(vector <Product*> &productvector); //������ ������� �����
int Case2(vector <Product*> &productvector);  //������ ������� � �����
int Case3(vector <Product*> &productvector);  //������ ������� � �����
void Case4(vector <Product*> &productvector); //�������� ������� � �����
void Case5(vector <Product*> &productvector); //����� ������� � �����
#endif
