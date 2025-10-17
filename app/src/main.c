<<<<<<< HEAD
/*
 *main.c
 */


=======
>>>>>>> 30b7fef1dd8bc25bad74a973b0466c4e8314c692
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)
#define LED3_NODE DT_ALIAS(led3)
<<<<<<< HEAD
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE,gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE,gpios);
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED2_NODE,gpios);
static const struct gpio_dt_spec led3 = GPIO_DT_SPEC_GET(LED3_NODE,gpios);



int main(void){
    int ret, ret1, ret2, ret3;

    if(!gpio_is_ready_dt(&led0) || !gpio_is_ready_dt(&led1) || !gpio_is_ready_dt(&led2)|| !gpio_is_ready_dt(&led3)){
        return -1;
    }

    ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);
    ret1 = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
    ret2 = gpio_pin_configure_dt(&led2, GPIO_OUTPUT_ACTIVE);
    ret3 = gpio_pin_configure_dt(&led3, GPIO_OUTPUT_ACTIVE);

    if (ret < 0) {
        return ret;
    }
    while(1){
        gpio_pin_toggle_dt(&led0);
        k_msleep(200);
        gpio_pin_toggle_dt(&led1);
        k_msleep(350);
        gpio_pin_toggle_dt(&led3);
        k_msleep(500);
        gpio_pin_toggle_dt(&led2);
        
        k_msleep(500);

    }
    return 0;
    
}
=======

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
        k_msleep(200);
        gpio_pin_toggle_dt(&led1);
        k_msleep(300);
        gpio_pin_toggle_dt(&led2);
        k_msleep(400);
        gpio_pin_toggle_dt(&led3);
        k_msleep(500);
    }
}
>>>>>>> 30b7fef1dd8bc25bad74a973b0466c4e8314c692
