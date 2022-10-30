// FCAI – OOP – 2022 - Assignment 1
// Program: BigDecimalInt Class
// Author: Abdallah Hussein Ibrahim Hussein - Ahmad Reda Bayoumi - Esraa Mahmoud Abdelmohsen
// IDs: 20210235 - 20210019 - 20210063
// Date: October  2022
// ...........................................................................................

#include "BigDecimalInt.cpp"

int main()
{
  BigDecimalInt num1("364");
  BigDecimalInt num2 (-194);
  
  if (num1.get_str() == "364")
  {
    cout << "Test 1 Accepted\n";
  }
  if ((num2.sign() == -1) && (num2.get_str() == "194"))
  {
    cout << "Test 2 Accepted\n";
  }
  if (BigDecimalInt("0000555").get_str() == "555")
  {
    cout << "Test 3 Accepted\n";
  }
  if (BigDecimalInt(455).get_str() == "455")
  {
    cout << "Test 4 Accepted\n";
  }
  if (BigDecimalInt("op").get_str() == "")
  {
    cout << " ,Test 5 Accepted\n";
  }
  if (BigDecimalInt("0000").get_str() == "0")
  {
    cout << "Test 6 Accepted\n";
  }
  if (BigDecimalInt("256") + BigDecimalInt(564) == BigDecimalInt("820"))
  {
    cout << "Test 7 Accepted\n";
  }
  if ((BigDecimalInt("-256") + BigDecimalInt(564)) == BigDecimalInt("308"))
  {
    cout << "Test 8 Accepted\n";
  }
  if ((BigDecimalInt("666") + BigDecimalInt("-1000")) == BigDecimalInt("-334"))
  {
    cout << "Test 9 Accepted\n";
  }
  if ((BigDecimalInt("-256") + BigDecimalInt("-559")) == BigDecimalInt("-815"))
  {
    cout << "Test 10 Accepted\n";
  }
  if ((BigDecimalInt("-777") + BigDecimalInt("-456")) == BigDecimalInt("-1233"))
  {
    cout << "Test 11 Accepted\n";
  }
  if ((BigDecimalInt("-000100")) < BigDecimalInt("300"))
  {
    cout << "Test 12 Accepted\n";
  }
  if ((BigDecimalInt("-100")) < BigDecimalInt("-1"))
  {
    cout << "Test 13 Accepted\n";
  }
  if ((BigDecimalInt("000770")) > BigDecimalInt("-77"))
  {
    cout << "Test 14 Accepted\n";
  }
  if ((BigDecimalInt("000151")) > BigDecimalInt("15"))
  {
    cout << "Test 15 Accepted\n";
  }
  if ((BigDecimalInt("-0077")) > BigDecimalInt("-770"))
  {
    cout << "Test 16 Accepted\n";
  }
  if ((BigDecimalInt("-00110")) < BigDecimalInt("-100"))
  {
    cout << "Test 17 Accepted\n";
  }
}
