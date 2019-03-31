#ifndef headerh // заголовочный файл. Подключение необходимых библиотек, создание классов и функций
#define headerh
#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class  Product //класс товаров
{
 public:
    char name[100]; //имя товара
    char article[100]; //артикул товара
    int count; //количество товара
    double price; //цена товара
    ~Product() {};//деструктов товара
    Product(); // конструктор ввода информации о товаре
    Product(int empty); // конструктор для обмена
    Product(int empty1, int empty2); //конструктор для указания артикула
    printInfo(); //функция вывода информации о товаре
    friend istream& operator>>(istream &s,Product &v); //перегрузка операции ввода
};
void FileInput(vector <Product*> &productvector); //проверка файла на уже имеющиеся в нём товары
void FileOutput(vector <Product*> &productvector); //Запись товаров в файл
void Main(vector <Product*> &productvector); //Меню
void Case1(vector <Product*> &productvector); //первая функция кейса
int Case2(vector <Product*> &productvector);  //вторая функция в кейсе
int Case3(vector <Product*> &productvector);  //третья функция в кейсе
void Case4(vector <Product*> &productvector); //четвёртая функция в кейсе
void Case5(vector <Product*> &productvector); //пятая функция в кейсе
#endif
