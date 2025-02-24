# Nonsense Hello World Logger  

This is a **rather nonsense example** that logs `"Hello World"` to the console.  
Why? Because we can 🚀 —and because it demonstrates the basic usage of JerryScript.  

## Running the Example  

To run this masterpiece on a Linux host, simply use:  

```sh
make linux
```

## Code  

``` c
#include <jerryscript-ext/handlers.h>
#include <jerryscript-ext/properties.h>
#include <jerryscript.h>
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
```

## Output

```
I (307) main_task: Started on CPU0
I (317) main_task: Calling app_main()
I (317) JS: This test run the following script code: 
I (317) JS: let hello='Hello World!';print(hello, 1/3);
Hello World! 0.3333333333333333
```
