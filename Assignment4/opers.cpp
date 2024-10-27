// the realisation of all the operators

#include "opers.hpp"

std::ostream& operator<<(std::ostream& os, const Transformer& tran) {
    os << tran.getLabel();
    return os;
}

bool operator<(const Transformer& t1, const Transformer& t2) {
    if (t1.getHp() < t2.getHp()) {
        return true;
    }
    return false;
}

bool operator==(const Transformer& t1, const Transformer& t2) {
    if (t1.getHp() == t2.getHp()) {
        return true;
    }
    return false;
}

bool operator<=(const Transformer& t1, const Transformer& t2) {
    if ((t1 < t2) || (t1 == t2)) {
        return true;
    }
    return false;
}

bool operator>=(const Transformer& t1, const Transformer& t2) {
    if (!(t1 < t2)) {
        return true;
    }
    return false; 
}

bool operator>(const Transformer& t1, const Transformer& t2) {
    if (!(t1 < t2) && !(t1 == t2)) {
        return true;
    }
    return false;
}
