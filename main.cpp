#include <iostream>
#include "include/func.hpp"

int main(int ac, char **av)
{

    Kekpm kek(av, ac);
    kek.exec_cmd();
    return 0;
}
