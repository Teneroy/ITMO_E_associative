//
// Created by alexc on 1/16/2019.
//

#ifndef ITMO_E_ASSOCIATIVE_BASE_TYPES_H
#define ITMO_E_ASSOCIATIVE_BASE_TYPES_H
struct elem {
    elem()
    {
        domaintype = 0;
        rangetype = 0;
    }
    elem(int d, int r):domaintype(d),rangetype(r) {};
    int rangetype;
    int domaintype;
    bool operator == ( const elem &ob ) const
    {
        return domaintype == ob.domaintype;
    };
    friend std::ostream& operator<< ( std::ostream& out, const elem& x )
    {
        out << x.rangetype << " " << x.domaintype;
    };
};
#endif //ITMO_E_ASSOCIATIVE_BASE_TYPES_H
