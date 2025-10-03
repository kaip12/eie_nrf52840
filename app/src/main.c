#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)
#define LED3_NODE DT_ALIAS(led3)

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec led3 = GPIO_DT_SPEC_GET(LED3_NODE, gpios);

int main(void)
{
    if (!gpio_is_ready_dt(&led0) || !gpio_is_ready_dt(&led1) ||
        !gpio_is_ready_dt(&led2) || !gpio_is_ready_dt(&led3)) {
        return -1;
    }

    int ret  = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_INACTIVE);
    int ret1 = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_INACTIVE);
    int ret2 = gpio_pin_configure_dt(&led2, GPIO_OUTPUT_INACTIVE);
    int ret3 = gpio_pin_configure_dt(&led3, GPIO_OUTPUT_INACTIVE);
    if (ret || ret1 || ret2 || ret3) {
        return -2;
    }

    while (1) {
        gpio_pin_toggle_dt(&led0);
        gpio_pin_toggle_dt(&led1);
        gpio_pin_toggle_dt(&led2);
        gpio_pin_toggle_dt(&led3);
        k_msleep(1000);
    }
}
