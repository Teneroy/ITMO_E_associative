//
// Created by alexc on 1/14/2019.
//

#include "Associative.h"

void atdlist::Associative::assign(char * d, char * r)
{
    elem x = elem(d, r);
    x = clean_name(x, d);
    int pos = _ob.locate(x);
    node err;
    if(err.next == pos)
    {
        _ob.insert(_ob.endL(), x);
    } else {
        _ob.insert(pos, x);
        _ob.deleteEl(_ob.next(pos));
    }
}

void atdlist::Associative::makenull()
{
    _ob.makenull();
}

bool atdlist::Associative::compute(char * d, char * r)
{
    elem x = elem(d, r);
    x = clean_name(x, d);
    int pos = _ob.locate(x);
    node err;
    if(err.next != pos)
    {
        _ob.insert(pos, x);
        _ob.deleteEl(_ob.next(pos));
        return true;
    } else {
        return false;
    }
}

void atdlist::Associative::print()
{
    std::cout << "_________________________________________________________" << std::endl;
    std::cout << std::setw(25) << "domaintype";
    std::cout << std::setw(25) << "rangetype" << std::endl;
    for (int i = 0; i < _ob.endL(); ++i) {
        std::cout << std::setw(25) << _ob.retrieve(i).name;
        std::cout << std::setw(25) << _ob.retrieve(i).adress << std::endl;
    }
    std::cout << "_________________________________________________________" << std::endl;
    std::cout << std::endl;
}

elem atdlist::Associative::clean_name(elem x, char * d)
{
    for(int i = 0; i < 20; i++)
    {
        if(x.name[i] == d[i])
        {
            x.name[i] = d[i];
        } else {
            x.name[i] = '\0';
        }
    }
    return x;
}