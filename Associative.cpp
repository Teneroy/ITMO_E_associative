//
// Created by alexc on 1/14/2019.
//

#include "Associative.h"
node err; //Создаем элемент для проверки(если нашли, нам вернет адрес фейка)

void atdlist::Associative::assign(const elem &x)
{
    int pos = _ob.locate(x); //Ищем ключ
    if(err.next == pos) //Если не нашли
    {
        _ob.insert(_ob.endL(), x); //Вставляем в конец
    } else {
        _ob.insert(pos, x); //Вставляем в позицию
        _ob.deleteEl(_ob.next(pos)); //Удаляем следующий, тк у нас добавление со смещением
    }
}

void atdlist::Associative::makenull()
{
    _ob.makenull();
}

bool atdlist::Associative::compute(domaintype key, const rangetype &value)
{
    elem x(key.dtype, value.rtype);
    int pos = _ob.locate(x);
    if(err.next != pos)
    {
        _ob.insert(pos, x);
        _ob.deleteEl(_ob.next(pos));
        return true;
    } else {
        return false;
    }
}

void atdlist::Associative::print() const
{
    std::cout << std::setw(25) << "domaintype ";
    std::cout << std::setw(25) << "rangetype" << std::endl;
    for (int i = 0; i < _ob.endL(); ++i) {
        std::cout << std::setw(25) << _ob.retrieve(i).name;
        std::cout << std::setw(25) << _ob.retrieve(i).adress << std::endl;
    }
    std::cout << std::endl;
}

dlist::Associative::Associative()
{
    _head = nullptr;
}

dlist::Associative::~Associative()
{
    _head = deleteList(_head);
}

void dlist::Associative::assign(const elem &x)
{
    if(_head == nullptr) //Если список пуст
    {
        _head = new node; //Добавляем новую голову
        _head -> data = x; //Записываем данные
        _head -> next = nullptr; //Следующий пустой
    } else {
        node * temp = search_same_pos(_head, x); //Ищем ключ
        if(temp == nullptr) //Если не нашли
        {
            _head = add_to_tail(_head, x); //Добавляем в конец
        } else {
            temp -> data = x; //Записываем в найденную ячейку
        }
    }
}

bool dlist::Associative::compute(domaintype key, const rangetype &value)
{
    elem x(key.dtype, value.rtype);
    node * temp = search_same_pos(_head, x); //Ищем ключ
    if(temp == nullptr) //Если не нашли
    {
        return false;
    } else {
        temp -> data = x; //Записываем в найденную ячейку
        return true;
    }

}

void dlist::Associative::print() const
{
    std::cout << std::setw(25) << "domaintype ";
    std::cout << "rangetype" << std::endl;
    node * temp = _head;
    while (temp != nullptr) {
        std::cout << std::setw(25) << temp -> data << std::endl;
        temp = temp -> next;
    }
    std::cout << std::endl;
}

//Удалить список
dlist::node * dlist::Associative::deleteList(node * list)
{
    node * temp1;
    node * temp2 = list;
    while (temp2 != nullptr)
    {
        temp1 = temp2;
        temp2 = temp2 -> next;
        delete temp1;
    }
    list = nullptr;
    return list;
}

void dlist::Associative::makenull()
{
    _head = deleteList(_head);
}

dlist::node * dlist::Associative::add_to_tail(node * list, elem x)
{
    node * temp1 = list; //Указатель на голову
    node * temp2 = temp1 -> next; //Указатель на второй элемент
    while (temp2 != nullptr)
    {
        temp1 = temp1 -> next;//Доходим до предпоследнего элемента
        temp2 = temp2 -> next;
    }
    temp1 -> next = new node; //Добавляем элемент в конец
    temp1 -> next -> data = x;
    temp1 -> next -> next = nullptr;
    return list;
}

dlist::node * dlist::Associative::search_same_pos(node * list, const elem &x)
{
    node * temp = list;
    while(temp != nullptr)
    {
        if(x == temp -> data) //Данные совпадают
        {
            return temp; //Возвращаем позицию
        }
        temp = temp -> next;
    }
    return nullptr;
}