#include "BigDecimalInt.cpp"

int main()
{

    /*
     99
      2
     11
     101
    */
    BigDecimalInt num1("364");
    BigDecimalInt num2("-194");

    BigDecimalInt num3(5);
    BigDecimalInt num4("3");

    // cout << (num1 + num2).get_str();
    // cout << (num3 - num4).get_str();
    cout << num1 << " " << num2 << " " << num3<<'\n';

    // if (BigDecimalInt("9") == BigDecimalInt("9"))
    // {
    //     cout << "yes\n";
    // }
    // else
    // {
    //     cout << "No\n";
    // // }
    if (BigDecimalInt("-1999") > BigDecimalInt("9"))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    // BigDecimalInt x("0");
    // BigDecimalInt c("-789");
    // BigDecimalInt v = c;
    // cout << v.get_str() << '\n'<< v.size() << '\n' << v.sign();
    // cout << '\n' << v;
}