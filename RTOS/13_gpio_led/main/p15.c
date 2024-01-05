#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define LED_PIN GPIO_NUM_25 // Assuming the LED is connected to GPIO pin 25

void blink_task(void *pvParameter) {
    while (1) {
        // Turn on the LED
        gpio_set_level(LED_PIN, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Wait for 1 second

        // Turn off the LED
        gpio_set_level(LED_PIN, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS); // Wait for 1 second
    }
}

void app_main() {
    // Configure the GPIO for the LED
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << LED_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pull_down_en = 0,
        .pull_up_en = 0,
    };
    gpio_config(&io_conf);

    // Create a FreeRTOS task to blink the LED
    xTaskCreate(&blink_task, "blink_task", 2048, NULL, 5, NULL);
}
