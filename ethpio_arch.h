/*
    RP2040 Ethernet/PIO lwIP Driver
    This software is released under the same license, terms and conditions as the RP2040 "Pico" SDK
    0.1.0-beta - https://github.com/holysnippet/pico_eth/
*/

#ifndef __ETHPIO_ARCH_H__
#define __ETHPIO_ARCH_H__

#include <stdbool.h>
#include <stdint.h>

#include "lwip/ip_addr.h"

#include "picopioeth.h"

#define MAC_ADDR(m, a, b, c, d, e, f) \
    do {                              \
        m[0] = a;                     \
        m[1] = b;                     \
        m[2] = c;                     \
        m[3] = d;                     \
        m[4] = e;                     \
        m[5] = f;                     \
    } while (0)

#define LWIP_TO_CHK_PERIOD_US 1000

struct ethpio_parameters
{
    uint8_t pio_num;
    uint8_t mac_address[6];
    uint8_t tx_neg_pin;
    uint8_t rx_pin;
    char hostname[16];
};

typedef struct ethpio_parameters ethpio_parameters_t;

bool eth_pio_arch_init(ethpio_parameters_t *params);
void eth_pio_arch_poll(void);

extern struct netif netif;

#endif
