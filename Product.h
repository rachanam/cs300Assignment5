/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Product.h: Class to hold information about a product's upc code and description
 * */

#ifndef _PRODUCT_
#define _PRODUCT_
#include <string>
#include <functional>
using namespace std;

// Product class to store UPC code and description
class Product
{
    string upcCode, description;

  public:
    Product() {}
    Product(string _upcCode, string _description)
    {
        upcCode = _upcCode;
        description = _description;
    }

    string getDescription()
    {
        return description;
    }

    // operator< overlaoding for comparing products
    bool operator<(const Product &product)
    {
        return upcCode < product.upcCode;
    }

    // operator> overlaoding for comparing products
    bool operator>(const Product &product)
    {
        return upcCode > product.upcCode;
    }

    // operator== overlaoding for comparing products
    bool operator==(const Product &product)
    {
        return upcCode == product.upcCode;
    }

    int operator%(const int i)
    {
        hash<string> hasher;
        return hasher(upcCode) % i;
    }
};

#endif // _PRODUCT_