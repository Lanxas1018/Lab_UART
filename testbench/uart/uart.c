#include <defs.h>
#include <user_uart.h>
#include <irq_vex.h>

/*void __attribute__ ( ( section ( ".mprj" ) ) ) uart_reset_read_fifo()
{
    reg_uart_rst_rx_fifo = 1;
}*/

void __attribute__ ( ( section ( ".mprj" ) ) ) uart_write(int n)
{
    while(((reg_uart_stat>>3) & 1));
    reg_tx_data = n;
}

void __attribute__ ( ( section ( ".mprj" ) ) ) uart_write_char(char c)
{
	if (c == '\n')
		uart_write_char('\r');

    // wait until tx_full = 0
    while(((reg_uart_stat>>3) & 1));
    reg_tx_data = c;
}

void __attribute__ ( ( section ( ".mprj" ) ) ) uart_write_string(const char *s)
{
    while (*s)
        uart_write_char(*(s++));
}


char* __attribute__ ( ( section ( ".mprj" ) ) ) uart_read_char()
{

}

int __attribute__ ( ( section ( ".mprj" ) ) ) uart_read()
{
    int num;
    if(((reg_uart_stat>>5) | 0) && ((reg_uart_stat>>4) | 0))
        num = reg_rx_data;

    return num;
}

int __attribute__ ( ( section ( ".mprj" ) ) ) uart_isr()
{
    int num;
    uint32_t irqs = irq_pending() & irq_getmask();

    if ( irqs & (1 << USER_IRQ_0_INTERRUPT)) {
        num = uart_read();
        user_irq_0_ev_pending_write(1); //Clear Interrupt Pending Event
    }

    return num;
}