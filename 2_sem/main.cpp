#include "header.h" // Создание вектора, вызов функций, очистка вектора
int main()
{
    SetConsoleCP(1251);             // Корректное изображение
    SetConsoleOutputCP(1251);        // Кириллицы
    vector <Product*> productvector;   // Задание вектора
    FileInput(productvector);           // Проверка файла на уже имеющиеся в нём товары
    Main(productvector);            // Меню
    FileOutput(productvector);      // Запись новых товаров в файл
    productvector.clear();          // Очистка вектора
    return 0;
}
