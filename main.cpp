#include <iostream>
#include <systemc.h>

#include "kpn.h"

int sc_main(int, char**)
{
    sc_signal<unsigned int> e;
    kpn kahn("kpn");
    kahn.e.bind(e);
    sc_start();
    return 0;
}
