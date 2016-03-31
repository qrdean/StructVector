//Quinton Dean
//Test1A
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

struct product
{
    string sku;
    string description;
    float price;
};

int main()
{
    string junk;
    float total=0;
    int count=0, i;
    vector <product> vpro(10);
    product pro1;
    int quantity, id;
    string sku2;
    ifstream store;
    ifstream sales;
    store.open("products.txt");
    sales.open("purchases.txt");
    if(!store.is_open())
    {
        cout << "Can not Open 'products.txt'";
        return 10;
    }
    if(!sales.is_open())
    {
        cout << "Can not open 'purchases.txt'";
        return 10;
    }

    getline(store, junk);
    store >> pro1.sku >> pro1.price;
    getline(store, pro1.description);
    while(!store.eof())
    {

        if(count >= vpro.size())
        {
            vpro.resize(2*(count-1));
        }
        vpro.at(count)=pro1;
        count++;
        store >> pro1.sku >> pro1.price;
        getline(store, pro1.description);
    }
    getline(sales, junk);
    sales >> id >> sku2 >> quantity;

    cout << setw(50) << "Acme Flow Industries" << '\n' << setw(50) << "Christmas Sales Report" << '\n';
    cout << "ID" << setw(10) <<"SKU" << setw(20) << "Description" << setw(20) << "Quantity" << setw(10) << "Price" << setw(15)
    << "Ext. Price" << '\n';
    float extprice;
    while(!sales.eof())
    {
    for(i=0; i<count; i++)
    {

        pro1=vpro.at(i);
        if(sku2 == pro1.sku)
        {
           extprice = quantity*pro1.price;
           cout << id << setw(10) << pro1.sku << setw(10) << pro1.description << setw(15) << quantity << setw(10) << pro1.price << setw(10) << extprice << '\n';
           total = extprice + total;
           sales >> id >> sku2 >> quantity;
        }



    }
    }
    cout << '\n' << setw(40) << "Total Sales" << setw(40) << total;
    //couldn't get formatting to cooperate properly with this problem. Maybe due to way loop was written?
}
