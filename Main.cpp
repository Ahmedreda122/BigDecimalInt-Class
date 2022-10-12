#include "BigDecimalInt.cpp"

int main()
{

 /*
  99
   2
  11
  101
 */
    BigDecimalInt num1("-600");
    BigDecimalInt num2("500");

    BigDecimalInt num3("5"); 

    cout << (num1+num2).get_str();



    // if (BigDecimalInt("9") == BigDecimalInt("9"))
    // {
    //     cout << "yes\n";
    // }
    // else
    // {
    //     cout << "No\n";
    // // }
    // if (BigDecimalInt("1999") > BigDecimalInt("9"))
    // {
    //     cout << "bigger\n";
    // }
    // else
    // {
    //     cout << "smaller\n";
    //}
    // BigDecimalInt x("0");
    // BigDecimalInt c("-789");
    // BigDecimalInt v = c;
    // cout << v.get_str() << '\n'<< v.size() << '\n' << v.sign();
    // cout << '\n' << v;
}