#include <iostream>
#include "Characteristic.h"

using namespace std;

void testCharacteristicAndMantissa();
void shouldConvert(const char number[], int expectedCharacteristic, int expectedNumerator, int expectedDenominator);
void shouldNotConvert(const char number[]);

void testMath();

int main()
{
    cout<<"In-class Code Review"<<endl;

    //characteristic and mantissa test
    testCharacteristicAndMantissa();
    
    //math function tests

    return 0;
}
//--
void testCharacteristicAndMantissa()
{
    //number with a non-zero characteristic a decimal point and a non-zero mantissa
    shouldConvert("123.456", 123, 456, 1000);
    shouldConvert("    123.456", 123, 456, 1000);
    shouldConvert("123.456    ", 123, 456, 1000);
    shouldConvert("    123.456    ", 123, 456, 1000);
    //unary plus/minus
    shouldConvert("+123.456", 123, 456, 1000);
    shouldConvert("   +123.456", 123, 456, 1000);
    shouldConvert("+123.456   ", 123, 456, 1000);
    shouldConvert("   +123.456   ", 123, 456, 1000);
    shouldConvert("-123.456", -123, 456, 1000);
    shouldConvert("   -123.456", -123, 456, 1000);
    shouldConvert("-123.456   ", -123, 456, 1000);
    shouldConvert("    -123.456   ", -123, 456, 1000);

    //number with a zero characteristic and a non-zero mantissa
    shouldConvert("0.456", 0, 456, 1000);
    shouldConvert("   0.456", 0, 456, 1000); 
    shouldConvert("0.456   ", 0, 456, 1000);
    shouldConvert("   0.456   ", 0, 456, 1000);
    //unary plus/minus
    shouldConvert("-0.456", 0, -456, 1000);
    shouldConvert("   -0.456", 0, -456, 1000);
    shouldConvert("-0.456   ", 0, -456, 1000);
    shouldConvert("   -0.456   ", 0, -456, 1000);
    shouldConvert("+0.456", 0, -456, 1000);
    shouldConvert("   +0.456", 0, -456, 1000);
    shouldConvert("+0.456   ", 0, -456, 1000);
    shouldConvert("   +0.456   ", 0, -456, 1000);

    //number with no characteristic digits and a non-zero mantissa
    shouldConvert(".456", 0, 456, 1000);
    shouldConvert("    .456", 0, 456, 1000);
    shouldConvert(".456   ", 0, 456, 1000);
    shouldConvert("   .456   ", 0, 456, 1000);
    //unary plus/minus
    shouldConvert("-.456", 0, -456, 1000);
    shouldConvert("    -.456", 0, -456, 1000);
    shouldConvert("-.456   ", 0, -456, 1000);
    shouldConvert("   -.456   ", 0, -456, 1000);
    shouldConvert("+.456", 0, +456, 1000);
    shouldConvert("    +.456", 0, +456, 1000);
    shouldConvert("+.456   ", 0, +456, 1000);
    shouldConvert("   +.456   ", 0, +456, 1000);

    //number with a non-zero characteristic and no mantissa
    shouldConvert("123456", 123456, 0, 10);
    shouldConvert("   123456", 123456, 0, 10);
    shouldConvert("123456   ", 123456, 0, 10);
    shouldConvert("   123456   ", 123456, 0, 10);
    //unary plus/minus
    shouldConvert("-123456", -123456, 0, 10);
    shouldConvert("   -123456", -123456, 0, 10);
    shouldConvert("-123456   ", -123456, 0, 10);
    shouldConvert("   -123456   ", -123456, 0, 10);
    shouldConvert("+123456", +123456, 0, 10);
    shouldConvert("   +123456", +123456, 0, 10);
    shouldConvert("+123456   ", +123456, 0, 10);
    shouldConvert("   +123456   ", +123456, 0, 10);

    //number with a non-zero characteristic and a zero mantissa
    shouldConvert("123456.0", 123456.0, 0, 10);
    shouldConvert("   123456.0", 123456.0, 0, 10);
    shouldConvert("123456.0   ", 123456.0, 0, 10);
    shouldConvert("   123456.0   ", 123456.0, 0, 10);
    //unary plus/minus
    shouldConvert("-123456.0", -123456, 0, 10);
    shouldConvert("   -123456.0", -123456, 0, 10);
    shouldConvert("-123456.0   ", -123456, 0, 10);
    shouldConvert("   -123456.0   ", -123456, 0, 10);
    shouldConvert("+123456.0", +123456, 0, 10);
    shouldConvert("   +123456.0", +123456, 0, 10);
    shouldConvert("+123456.0   ", +123456, 0, 10);
    shouldConvert("   +123456.0   ", +123456, 0, 10);

    //check leading and trailing zeros
    shouldConvert("000123.456", 123, 456, 1000);
    shouldConvert("123.45600000"	, 123, 456, 1000);
    shouldConvert("00000123.45600000", 123, 456, 1000);
    //unary plus/minus
    shouldConvert("-000123.456", -123, 456, 1000);
    shouldConvert("-123.45600000", -123, 456, 1000);
    shouldConvert("-00000123.45600000", -123, 456, 1000);
    shouldConvert("+000123.456", +123, 456, 1000);
    shouldConvert("+123.45600000", +123, 456, 1000);
    shouldConvert("+00000123.45600000", +123, 456, 1000);

    //significant zeros in mantissa
    shouldConvert("123.00000456", 123, 456, 100000000);
    shouldConvert("-123.00000456", -123, 456, 100000000);
    shouldConvert("+123.00000456", +123, 456, 100000000);

    //these should fail
    shouldNotConvert("");
    shouldNotConvert("+");
    shouldNotConvert("-");
    shouldNotConvert(".");
    shouldNotConvert("cat");
    shouldNotConvert("    ");
    shouldNotConvert("123.cat");
    shouldNotConvert("cat.123");
    shouldNotConvert("-cat");
}
//--
void shouldConvert(const char number[], int expectedCharacteristic, int expectedNumerator, int expectedDenominator)
{
	int c;

    //if the conversion from C string to integers can take place
    if (characteristic(number, c))
    {
        if (c == expectedCharacteristic)
        {
            //test passes, do not print anything on a successful test
        }
        else
        {
            cout << "Test failed: '" << number << "' "
                << "was parsed but did not produce the expected results" << endl;

            if (expectedCharacteristic != c)
            {
                cout << "expected characteristic: " << expectedCharacteristic << " "
                    << "actual characteristic: " << c << endl;
            }

        }
    }
    else
    {
        cout << "Test failed: '" << number << "' "
            << "was NOT parsed when it should have been." << endl;
    }
}
//--
void shouldNotConvert(const char number[])
{
    int c;

    //if the conversion from C string to integers can take place
    if (characteristic(number, c))
    {
        cout << "Test failed: '" << number << "' "
            << "was parsed when it should NOT have been." << endl;
    }
}
//--
void testMath()
{
}
