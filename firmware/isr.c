// This file is Copyright (c) 2020 Florent Kermarrec <florent@enjoy-digital.fr>
// License: BSD

#include <csr.h>
#include <soc.h>
#include <irq_vex.h>
#include <user_uart.h>
#include <defs.h>

void isr(void);

#ifdef CONFIG_CPU_HAS_INTERRUPT

#ifdef USER_PROJ_IRQ0_EN
uint32_t counter = 0xFFFF0000;
#endif

void isr(void)
{

#ifndef USER_PROJ_IRQ0_EN

    irq_setmask(0);


#else
    uint32_t irqs = irq_pending() & irq_getmask();
    int buf;

    if ( irqs & (1 << USER_IRQ_0_INTERRUPT)) {
        user_irq_0_ev_pending_write(1); //Clear Interrupt Pending Event
        if(((reg_uart_stat>>5) | 0) && ((reg_uart_stat>>4) | 0))
           //reg_mprj_datal = reg_rx_data;
           //buf = reg_rx_data;
           //for(int i = 0; i < 1; i++)
                asm volatile ("nop");

            reg_mprj_datal = reg_rx_data << 16;
        //counter = counter - 0x10000;
        //reg_mprj_datal = counter;
    }
#endif

    return;

}

#else

void isr(void){};

#endif
