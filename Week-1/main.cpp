#include <iostream>
#include <string>

using namespace std;

namespace test {
    string text;

    void test(const string& text) {
        cout << text;
    }
}

int main() {
    test::test("Hello World");
    return 0;
}