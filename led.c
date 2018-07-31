/*
 * 程序清单：LED灯
 *
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <finsh.h>


static rt_uint8_t led_inited = 0;

#define LEDG_PIN 24
#define LEDB_PIN 41 
#define LEDY_PIN 25
#define LEDR_PIN 43

void rt_hw_led_control_init(void)
{
    rt_pin_mode(LEDB_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LEDG_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LEDR_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LEDY_PIN, PIN_MODE_OUTPUT);
}

void rt_hw_led_control_on(rt_uint32_t n)
{
    switch (n)
    {
    case 0:
        rt_pin_write(LEDR_PIN, 0);
        break;
    case 1:
        rt_pin_write(LEDY_PIN, 0);
        break;
    case 2:
        rt_pin_write(LEDB_PIN, 0);
        break;
    case 3:
        rt_pin_write(LEDG_PIN, 0);
        break;
    default:
        break;
    }
}

void rt_hw_led_control_off(rt_uint32_t n)
{
    switch (n)
    {
    case 0:
        rt_pin_write(LEDR_PIN, 1);
        break;
    case 1:
        rt_pin_write(LEDY_PIN, 1);
        break;
    case 2:
        rt_pin_write(LEDB_PIN, 1);
        break;
    case 3:
        rt_pin_write(LEDG_PIN, 1);
        break;
    default:
        break;
    }
}


void led_control(rt_uint32_t led, rt_uint32_t value)
{
    /* init led configuration if it's not inited. */
    if (!led_inited)
    {
        rt_hw_led_control_init();
        led_inited = 1;
    }
    
    if (led == 1)
    {
       rt_hw_led_control_on(value);
    }
    else
    {
        rt_hw_led_control_off(value);
    }
    }
   
    
}


/* 导出到 msh 命令列表中 */
FINSH_FUNCTION_EXPORT(led_control, led test);

