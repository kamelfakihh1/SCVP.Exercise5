#ifndef KPN_H
#define KPN_H

#include <systemc.h>
#include <iostream>

template <class T>
class custom_sc_fifo : public sc_fifo<T>
{
    public : 

    custom_sc_fifo(int size) : sc_fifo<T>(size){}

    void print( ::std::ostream& out = ::std::cout ) const 
    {
        out << "[";

        // next read index 
        int j = this->m_ri; 
        for(int i=0; i<this->num_available(); i++)
        {
            int value = this->m_buf[j];
            j = ( j + 1 ) % this->m_size;            
            out << value;
        }

        for(int i = 0; i<this->num_free(); i++)
        {
            out << " ";
        }

        out << "]" << endl;
        out.flush();
    }
};

SC_MODULE(kpn)
{
private:    

    // buffers 
    custom_sc_fifo<unsigned int> a, b, c, d;

    // nodes
    void add();
    void split();
    void delay();    

    // debugging 
    void debug_thread();    

public:

    // output
    sc_out<unsigned int> e;

    SC_CTOR(kpn)
        : a(10), b(10), c(10), d(10), e("e")
    {        
        b.write(1);
        c.write(0);

        SC_THREAD(add);        
        SC_THREAD(split);
        SC_THREAD(delay);

        SC_THREAD(debug_thread);        
        sensitive << a.data_read_event() << a.data_written_event()
                 << b.data_read_event() << b.data_written_event()
                 << c.data_read_event() << c.data_written_event()
                 << d.data_read_event() << d.data_written_event();
    };
};

#endif // KPN_H
