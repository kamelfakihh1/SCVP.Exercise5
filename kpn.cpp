#include <unistd.h>
#include <systemc.h>

#include "kpn.h"

void kpn::add()
{
    while(true)
    {        
        b.write(a.read() + c.read());
    }
}

void kpn::split()
{
    // int count = 0;

    while(true)
    {        
        unsigned int temp = b.read();
        a.write(temp);
        d.write(temp);
        e.write(temp);

        // std::cout << sc_time_stamp() << " e = " << temp << std::endl;

        // count ++;        
        // if(count == 10)
        // {
        //     sc_abort();
        // }
    }
}

void kpn::delay()
{
    while(true)
    {        
        c.write(d.read());
    }
}

// helping methods

void kpn::debug_thread()
{
    while(true)
    {
        system("clear");
        std::cout << "Kahn Process Network with SystemC" << std::endl;
        std::cout << "Kamel Fakih (2024)" << std::endl;

        std::cout << std::endl << "@" << sc_time_stamp() << std::endl;
        std::cout << "a";
        a.print();
        std::cout << "b";
        a.print();
        std::cout << "c";
        a.print();
        std::cout << "d";
        a.print();        

        usleep(300000);

        // if(y.num_free()==0)
        // {
        //     sc_stop();
        // }
        wait();
    }
}