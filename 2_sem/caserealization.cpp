#include "header.h" //реализация функций меню программы
void Case1(vector <Product*> &productvector) //первая функция кейса
{
    productvector.push_back (new Product()); //запись в вектор нового объекта с помощью конструктора
}
int Case2(vector <Product*> &productvector) //первая функция кейса
{
    int flag_check=0; //флаг проверки наличия товара
    int flag2=1; //флаг цикла while
    int choice_change;
    if (productvector.size()<1) //проверка на пустоту вектора
    {
        return 3;
    }
    else
    {
        Product prod_choice(0,0); //переменная для указания артикула
        for (int i=0; i<productvector.size(); i++)
        {
            if (strcmp( productvector[i]->article, prod_choice.article) == 0) //поиск нужного артикула
            {
                flag_check=1;
                while (flag2!=0) //меню изменения информации о товаре
                {
                    cout<<"Какую информацию следует поменять?"<<endl;
                    cout<<"1.Наименование товара"<<endl;
                    cout<<"2.Артикул товара"<<endl;
                    cout<<"3.Количество товара"<<endl;
                    cout<<"4.Цену товара"<<endl;
                    cin>>choice_change;
                    switch(choice_change)
                    {
                    case 1:
                    {
                        cout<<"Введите новое наименование товара"<<endl;
                        cin.ignore();
                        cin.getline(productvector[i]->name,100);
                        break;
                    }
                    case 2:
                    {
                        cout<<"Введите новый артикул товара"<<endl;
                        cin.ignore();
                        cin.getline(productvector[i]->article,100);
                        break;
                    }
                    case 3:
                    {
                        cout<<"Введите новое количество товара (шт.):"<<endl;
                        while(!(cin>>productvector[i]->count) || cin.get() != '\n')
                        {
                            cout<<"Введите число, а не символы !"<<endl;
                            cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
                            cin.sync();//Удалим данные из буффера
                            cout<<"Введите новое количество товара (шт.):"<<endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        cout<<"Введите новую цену товара (руб.):"<<endl;
                        while(!(cin>>productvector[i]->price) || cin.get() != '\n')
                        {
                            cout<<"Введите число, а не символы !"<<endl;
                            cin.clear();
                            cin.sync();
                            cout<<"Введите новую цену товара (руб.):"<<endl;
                        }
                        break;
                    }
                    default: //подменю при некорректном вводе
                    {
                        cout<<"Некорректный ввод, попробуйте снова"<<endl;
                        break;
                    }
                    }
                    char choise_exit2; //переменная продолжения работы
                    cout<<"Продолжить редактирование данного товара?(Y/N)"<<endl;
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
                        cout<<"Неверный запрос, повторите снова"<<endl;
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
int Case3(vector <Product*> &productvector) //третья функция в кейсе
{
    int flag_check=0; //флаг нахождения нужного артикула
    if (productvector.size()<1) //проверка вектора на пустоту
    {
        return 3;
    }
    else
    {
        Product prod_choice(0,0); //переменная указание артикула
        for (int i=0; i<productvector.size(); i++)
        {
            if (strcmp( productvector[i]->article, prod_choice.article) == 0) //поиск нужного артикула
            {
                flag_check=1; //если найден артикул, перевести флаг в другое положение
                productvector.erase(productvector.begin()+i); //удаление нужного файла
            }
        }
        if (flag_check==0) //проверка на нахождение нужного артикула
        {
            return 2;
        }
    }
}
void Case4(vector <Product*> &productvector) //четвёртая функция в кейсе
{
    Product swap(0); //переменная обмена
    for (int i=0; i<productvector.size(); i++) //сортировка по алфавиту
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
void Case5(vector <Product*> &productvector) //пятая функция в кейсе
{
    if (productvector.size()==0)  //проверка на пустоту вектора
        cout<<"Список пуст"<<endl;
    for (int i = 0; i < productvector.size(); i++) //вывод всех товаров с помощью функции класса
    {
        cout<<i+1<<")";
        productvector[i]->printInfo();
    }
}
