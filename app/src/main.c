/*
 * main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1

#include "BTN.h"
#include "LED.h"

#ifndef LED0
#define LED0 0
#endif

#define SLEEP_MS 50  /* small delay to debounce button polling */

int main(void) {
    int ret;

    if (0 > BTN_init()) {
        return 0;
    }
    if (0 > LED_init()) {
        return 0;
    }

    while (1) {
        if (BTN_check_clear_pressed(BTN0)) {
            LED_toggle(LED0);
            printk("Button 0 pressed!\n");
        }
        k_msleep(SLEEP_MS);
    }

    return 0;
}
