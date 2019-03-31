#include "header.h" //создание вектора, вызов функций, очистка вектора
int main()
{
    SetConsoleCP(1251);             // корректное изображение
    SetConsoleOutputCP(1251);        //кириллицы
    vector <Product*> productvector;   //задание вектора
    FileInput(productvector);           //проверка файла на уже имеющиеся в нём товары
    Main(productvector);            //Меню
    FileOutput(productvector);      //Запись новых товаров в файл
    productvector.clear();          //очистка вектора
    return 0;
}
