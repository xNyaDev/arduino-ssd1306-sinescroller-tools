# Arduino SSD1306 Sinescroller Tools
Command-line tools that simplify the configuration of [Arduino SSD1306 Sinescroller](https://github.com/xNyaDev/arduino-ssd1306-sinescroller)

## Usage

### DYPP Array Gen

Either run the program without any arguments for the interactive mode or use it like this:
```
./dypp_array_gen <array size> <wave height multiplier> <y offset>
```

### Text Array Gen

Either run the program without any arguments for the interactive mode or use it like this:
```
./text_array_gen <text>
```

## Building

### Windows

This project uses CMake. See [here](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio) for information on using it with Visual Studio.

### Linux

You will need CMake 3.12 or newer and a compiler with C++20 support.

```
mkdir build && cd build
cmake ..
make
```

## License
[MIT](https://choosealicense.com/licenses/mit/)