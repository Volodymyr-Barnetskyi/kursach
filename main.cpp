#include <iostream>
#include "class.h"
using namespace std;
int main()
{
    system("color B");
    system("chcp 1251 > nul");
    setlocale(0,"");
    cout<<"\t\t\t\  =====A3 DENTAL=====\n\n";

    while(1)
    {
        cout <<"\n\tКлiєнти|1|, Послуги|2|, Стоматологи|3|, Замовлення|4|, Вийти|5|" << endl;
        int choose;
        cin >> choose;
        switch(choose)
        {
        case 1:
            TABLE_CLIENT.menu();
            break;
        case 2:
            TABLE_SERVICES.menuServices();
            break;
        case 3:
            TABLE_DANTIST.menu_dantists();
            break;
        case 4:
            TABLE_ORDER.menuOrder();
            break;
        case 5:
            return 0;
            // break;
        }
    }

    return 0;
}
