/*
 * References:
 *
 *   [turner2017optional] C++ Weekly - Ep 87 - std::optional
 *     https://youtu.be/PiaZkNp_fIM
 *
 *   [gregory2017cppcon] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=32m17s
 *
 *   [fertig2017overload] About the C++ Core Guidelines, Andreas Fertig, Overload 140, page 26.
 *     https://accu.org/var/uploads/journals/Overload140.pdf
 *
 *   [sutter2013factories] GotW #90: Factories
 *     https://herbsutter.com/2013/05/29/gotw-90-factories/
 *     https://herbsutter.com/2013/05/30/gotw-90-solution-factories/
 */

#include <iostream>
#include <optional>
#include <string>
 
// std::optional can be used as the return type of a factory that may fail.
std::optional<std::string> create(bool b)
{
    if (b)
    {
        return "Godzilla";
    }
    return {};
}
 
int main()
{
    std::cout << "create(false) returned "
              << create(false).value_or("empty") << '\n';

    std::cout << "create(true) returned "
              << create(true).value_or("empty") << '\n';
 

    // Optional-returning factory functions are usable as conditions of
    // while and if.

    if (auto str = create(true)) {
        std::cout << "create(true) returned " << *str << '\n';
    }
}
