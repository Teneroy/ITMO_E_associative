//
// Created by alexc on 1/14/2019.
//

#ifndef ITMO_E_ASSOCIATIVE_ASSOCIATIVE_H
#define ITMO_E_ASSOCIATIVE_ASSOCIATIVE_H
#include "../ITMO_E_listmerge/List.h"
using namespace arrlist;

namespace atdlist {

    class Associative {
    public:
        void makenull();
        void assign(char * d, char * r);
        bool compute(char * d, char * r);
        void print();
    private:
        elem clean_name(elem x, char * d);
        List _ob;
    };

}

namespace dlist {

    class Associative {
    public:

    private:

    };

}

#endif //ITMO_E_ASSOCIATIVE_ASSOCIATIVE_H
