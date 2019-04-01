#include "header.h" //Реализация методов и конструкторов
Product :: Product() // конструктор ввода информации о товаре
{
    cout << "Введите наименование товара:" << endl;
    cin.ignore();  // игнорирование пробелов
    cin.getline(name,100); //считывание всей строки
    cout << "Введите артикул товара:" << endl;
    cin.getline(article,100);
    cout << "Введите количество товара (шт.):" << endl;
    while(!(cin >> count) || cin.get() != '\n')
    {
        cout << "Введите число, а не символы !" << endl;
        cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
        cin.sync();//Удалим данные из буффера
        cout << "Введите количество товара (шт.):" << endl;
    }
    cout << "Введите цену товара (руб.):" << endl;
    while(!(cin >> price) || cin.get() != '\n')
    {
        cout << "Введите число, а не символы !" << endl;
        cin.clear();
        cin.sync();
        cout << "Введите цену товара (руб.):" << endl;
    }
}
Product :: Product(int empty) {} // конструктор для обмена
Product :: Product(int empty1, int empty2) //конструктор для указания артикула
{
    cout << "Введите артикул товара, который нужно изменить:" << endl;
    cin.ignore();
    cin.getline(article,100);
}
Product :: printInfo() // конструктор ввода информации о товаре
{
    cout << "Наименование товара: " << name << endl;
    cout << "Артикул товара: " << article << endl;
    cout << "Количество товара: " << count << " шт." << endl;
    cout << "Цена товара: " << price << " руб." << endl << endl;
}
