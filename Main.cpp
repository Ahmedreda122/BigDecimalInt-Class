#include "BigDecimalInt.cpp"
int main()
{
    BigDecimalInt("9");
    if (BigDecimalInt("9") == BigDecimalInt("9"))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "No\n";
    }
    if (BigDecimalInt("9") > BigDecimalInt("7"))
    {
        cout << "bigger\n";
    }
    else
    {
        cout << "smaller\n";
    }
    BigDecimalInt x("0");
    BigDecimalInt c("-789");
    BigDecimalInt v = c;
    cout << v.get_str() << '\n'<< v.size() << '\n' << v.sign();
    cout << '\n' << v;
}