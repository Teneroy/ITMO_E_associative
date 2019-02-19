//
// Created by alexc on 1/14/2019.
//

#ifndef ITMO_E_ASSOCIATIVE_ASSOCIATIVE_H
#define ITMO_E_ASSOCIATIVE_ASSOCIATIVE_H

#include <iostream>
#include <iomanip>
#include "string.h"

#include "../ITMO_E_listmerge/List.h"
using namespace arrlist;

struct domaintype
{
    char dtype[20];
    domaintype(char * d) {strcpy(dtype, d);};
};

struct rangetype
{
    char rtype[20];
    rangetype(char * r) {strcpy(rtype, r);};
};

namespace atdlist { //АТД список

    class Associative {
    public:
        void makenull();
        void assign(const elem &x);
        bool compute(domaintype key, const rangetype &value);
        void print() const;
    private:
        List _ob;
    };

}

namespace dlist { //Список пар

    struct node {
        elem data;
        node * next;
    };

    class Associative {
    public:
        Associative();
        ~Associative();
        void makenull();
        void assign(const elem &x);
        bool compute(domaintype key, const rangetype &value);
        void print() const;
    private:
        node * _head;
        node * search_same_pos(node * list, const elem &x); //Поиск ключа
        node * deleteList(node * list); //Удаление списка
        node * add_to_tail(node * list, elem x); //Добавление элемента в хвост списка
    };

}

#endif //ITMO_E_ASSOCIATIVE_ASSOCIATIVE_H
