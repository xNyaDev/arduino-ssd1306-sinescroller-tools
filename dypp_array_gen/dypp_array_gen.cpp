// MIT License
//
// Copyright (c) 2021 xNyaDev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#include <cmath>
#include <iostream>
#include <numbers>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::numbers::pi;
using std::stoi;
using std::string;

int main(int argc, char *argv[])
{
    int array_size;
    int wave_height;
    int y_offset;

    if (argc == 1) // Read the values from stdin if there were none provided as arguments.
    {
        cout << "Array size: ";
        cin >> array_size;
        cout << "Wave height multiplier: ";
        cin >> wave_height;
        cout << "Y offset: ";
        cin >> y_offset;
    }
    else if (argc == 4) // Read the values from arguments if there's a correct number of them.
    {
        array_size = stoi(string(argv[1]));
        wave_height = stoi(string(argv[2]));
        y_offset = stoi(string(argv[3]));
    }
    else // Print out usage if there's an incorrect number of arguments.
    {
        cout << "Usage:" << endl
             << argv[0] << " <array size> <wave height multiplier> <y offset>" << endl;
        return 1;
    }

    cout << "const int kDYPPScrollLimit = " << array_size << ";" << endl // Print out the variables and generate the array.
         << "const unsigned char kDYPPScrollArray[" << array_size << "] PROGMEM = {";
    for (int i = 0; i < array_size; i++)
    {
        int pixel_position = static_cast<int>(round(-sin(static_cast<double>(i) * 2.0 * pi / -array_size) * wave_height + y_offset)); // Generate the Y pixel position value.
        if (pixel_position != (pixel_position & 0xFF)) // Check if the Y pixel position value fits in one byte and notify the user if it doesn't.
        {
            cerr << "Cutting off value at " << i << ": " << pixel_position << " to " << (pixel_position & 0xFF) << endl;
        }
        cout << (pixel_position & 0xFF);
        if (i != array_size - 1)
        {
            cout << ", ";
        }
    }
    cout << "};" << endl;

    return 0;
}