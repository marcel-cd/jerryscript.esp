/*
 *  JerryScript Test
 *
 *  SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
 *  SPDX-License-Identifier: MIT
 */

#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <jerryscript-ext/handlers.h>
#include <jerryscript-ext/properties.h>
#include <jerryscript.h>

const char *TAG = "main";

void jerry_test() {

  // this is the test script
  const jerry_char_t script[] = "let hello='Hello World!';print(hello, 1/3);";

  jerry_value_t ret_value = jerry_undefined();

  /* Initialize engine */
  jerry_init(JERRY_INIT_EMPTY);
  jerry_log_set_level(JERRY_LOG_LEVEL_DEBUG);
  jerry_log(JERRY_LOG_LEVEL_DEBUG,
            "This test run the following script code: %s", script);

  /* Register the print function in the global object */
  jerryx_register_global("print", jerryx_handler_print);

  /* Setup Global scope code */
  ret_value = jerry_parse(script, sizeof(script) - 1, NULL);

  if (!jerry_value_is_exception(ret_value)) {
    /* Execute the parsed source code in the Global scope */
    ret_value = jerry_run(ret_value);
  }

  if (jerry_value_is_exception(ret_value)) {
    jerry_log(JERRY_LOG_LEVEL_DEBUG, "Script error...\n\n");
  }

  jerry_value_free(ret_value);

  /* Cleanup engine */
  jerry_cleanup();
}

void app_main() {

  jerry_test();
  while (true) {
    // next event in 1 second
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}
