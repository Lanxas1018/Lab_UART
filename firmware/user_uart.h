#ifndef _USER_UART_H_
#define _USER_UART_H_

#include <stdint.h>
#include <stdbool.h>

#define reg_rx_data          (*(volatile uint32_t*)0x30000000)
#define reg_tx_data          (*(volatile uint32_t*)0x30000004)
//#define reg_uart_rst_tx_fifo (*(volatile uint32_t*)0x30000008)
//#define reg_uart_rst_rx_fifo (*(volatile uint32_t*)0x3000000c)
#define reg_uart_stat        (*(volatile uint32_t*)0x30000010)
#define reg_uart_clkdiv      (*(volatile uint32_t*)0x30000014)


#endif