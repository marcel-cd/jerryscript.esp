<!-- SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH ;
SPDX-License-Identifier: MIT -->
# Using JerryScript on ESP32

JerryScript is the lightweight JavaScript engine intended to run on a very constrained devices such as microcontrollers:

- Only few kilobytes of RAM available to the engine (<64 KB RAM)
- Constrained ROM space for the code of the engine (<200 KB ROM)

The engine supports on-device compilation, execution and provides access to peripherals from JavaScript.

## Using JerryScript

JerryScript needs a heap, if you have external PSRAM, add the following configuration to your ```sdkconfig.defaults```

``` sh
CONFIG_JERRYSCRIPT_MALLOC_STRATEGY_SPIRAM=y
CONFIG_JERRYSCRIPT_HEAP_SIZE=128
```

Have a look at the example code: [hello_world](https://github.com/marcel-cd/jerryscript.esp/tree/main/examples/hello_world)

## Contributing

We welcome contributions in the form of code, bug reports, and feedback.

- See [CONTRIBUTING.md](https://github.com/marcel-cd/jerryscript.esp/blob/main/CONTRIBUTING.md) for guidelines.

## Contact

Join the conversation on:
- **[GitHub Discussions](https://github.com/marcel-cd/jerryscript.esp/discussions)** – For general chat or questions.
- **[GitHub Issues](https://github.com/marcel-cd/jerrryscript.esp/issues)** – To report bugs or suggest features.
