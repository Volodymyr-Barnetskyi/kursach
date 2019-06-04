#include "class.h"
void Client::getCl() //������� ��� ��������� �� ����� ����� ��� �볺���
{
    cout<<"\n\tI�'�:           "<<name<<"\n\t��i�����:       "<<lastname<<"\n\tEmail:          "<<email<<"\n\t����� ��������: "<<tel<<endl;
}

void Client::zdClient() //������� ��� �������� ����
{
    cout << "\t����i�� ���i ��� ��i����\n";
    cout << "\tI�'�: ";
    cin >> name;
    cout << "\t��i�����: ";
    cin >> lastname;
    cout << "\tEmail: ";
    cin >> email;
    cout << "\t�����: ";
    cin >> tel;
    message();
}

void Client::write_to_file(ofstream &file)
{
    file<<name<<"\t"<<lastname<<"\t"<<email<<"\t"<<tel<<endl;
}

void Client::read_from_file(ifstream &file)
{
    file >> name >> lastname >> email >> tel;
}


void table_client::print_all_clients()
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i].getCl(); /*cout<<endl;*/
    }
}

void table_client::add_new_client()
{
    Client temp;
    temp.zdClient();
    vec.push_back(temp);
}

int table_client::search_client(bool mozhna_povernutus)
{
    string firstNameC;
    string lastNameC;
    int id=-1;
    while(true)
    {
        cout << "\n\tI�'�: ";
        cin >> firstNameC;
        cout << "\t��i�����: ";
        cin >> lastNameC;
        for(int i=0; i<vec.size(); i++)
        {
            if((vec[i].getName()==firstNameC)&&(vec[i].getLastname()==lastNameC))id=i;
        }
        if(id==-1)
        {
            if(!mozhna_povernutus)
            {
                cout << "\t�볺��� �� ��������. ��������� �� ���." << endl;
                continue;
            }
            cout<<"\t�볺��� �� ��������. ��������� �� ��� |1|, ��� ���������� � �������� ���� |2|" << endl;
            int in;
            cin >> in;
            switch(in)
            {
            case 1:
                break;
            case 2:
                return -1;
                break;
            }
        }
        else return id;
    }
}

void table_client::poshuk()
{
    int id;
    id=search_client();
    if(id!=-1)vec[id].getCl();
}

void table_client::edit_client()
{
    int id;
    id=search_client();
    if(id!=-1)vec[id].zdClient();
}

void table_client::delete_client()
{
    int id;
    id=search_client();
    if(id!=-1)
    {
        vec.erase(vec.begin()+id);
        cout << "\t��i���� ��������" <<endl;
    }
    else cout << "\t�볺��� �� ��������" <<endl;
}

void table_client::write_clients_to_file()
{
    ofstream fClient("client1.txt");
    for(int i=0; i<vec.size(); i++) vec[i].write_to_file(fClient);//��� ������� �������� ��������� ������� ��� ������ � ����
    fClient.close();
}

void table_client::read_clients_from_file()
{
    ifstream fClient("client1.txt");
    if(fClient.is_open())
    {
        Client temp;
        while(!fClient.eof())
        {
            temp.read_from_file(fClient);
            vec.push_back(temp);
        }
        vec.erase(vec.end()); //��������� ���������� ��'����, �� ���� ������
        fClient.close();
    }

}

void table_client::menu()
{
    while(1)
    {
        cout <<"\n\t������� ��i� ��i���i�------>|1|\n\t������ ��i����------------->|2|\n\t������ ��i����------------->|3|\n\t���������� ���i ��� ��i����>|4|\n\t�������� ��i����----------->|5|\n\t�����---------------------->|6|" << endl;
        int inC;
        cin >> inC;
        switch(inC)
        {
        case 1:
            print_all_clients();
            break;
        case 2:
            poshuk();
            break;
        case 3:
            add_new_client();
            break;
        case 4:
            edit_client();
            break;
        case 5:
            delete_client();
            break;
        case 6:
            return;
        }
    }
}


void Dantist::getRl() //������� ��� ��������� �� ����� ����� ��� �볺���
{
    cout<<"\n\tI�'�:           "<<NameDantist<<"\n\t��i�����:       "<<SNameDantist<<"\n\tEmail:          "<< email<<"\n\t����� ��������: "<<tel<<"\n\t��������i ���i: "<<pd<<"\n\t�����:          "<<adress<<"\n\t������:         "<<posada<<"\n\t��������:       "<<salary<<endl<<endl;
}

void Dantist::zkDantist() //������� ��� �������� ����
{
    cout << "\n\t����i�� ���i ��� �����������\n";
    cout << "\tI�'�: ";
    cin >> NameDantist;
    cout << "\t��i�����: ";
    cin >> SNameDantist;
    cout << "\tEmail: ";
    cin >> email;
    cout << "\t�����: ";
    cin >> tel;
    cout << "\t��������i ���i: ";
    cin >> pd;
    cout << "\t�����: ";
    cin >> adress;
    cout << "\t������: ";
    cin >> posada;
    cout << "\t��������: ";
    cin >> salary;
    message();
}

void Dantist::write_to_file(ofstream &file)
{
    file<<NameDantist<<"\t"<<SNameDantist<<"\t"<<email<<"\t"<<tel<<"\t"<<pd<<"\t"<<adress<<"\t"<<posada<<"\t"<<salary<<endl;
}
void Dantist::read_from_file(ifstream &file)
{
    file >> NameDantist >> SNameDantist >> email >> tel >> pd >> adress >> posada >> salary;
}


void table_dantist::print_all_dantists()
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i].getRl(); /*cout<<endl;*/
    }
}

void table_dantist::add_new_dantists()
{
    Dantist temp;
    temp.zkDantist();
    vec.push_back(temp);
}

int table_dantist::search_dantists(bool mozhna_povernutus)
{
    string NameDantist;
    string SNameDantist;
    int id=-1;
    while(true)
    {
        cout << "\n\tI�'�: ";
        cin >> NameDantist;
        cout << "\t��i�����: ";
        cin >> SNameDantist;
        for(int i=0; i<vec.size(); i++)
        {
            if((vec[i].getfNameR()==NameDantist)&&(vec[i].getlNameR()==SNameDantist))id=i;
        }
        if(id==-1)
        {
            if(!mozhna_povernutus)
            {
                cout << "\t����������� �� ��������. ��������� �� ���." << endl;
                continue;
            }
            cout<<"\t����������� �� ��������. ��������� �� ��� |1|, ��� ���������� � �������� ���� |2|" << endl;
            int in;
            cin >> in;
if(cin.get()!='\n'){cout << "������� �����, ��������� �� ���." << endl; cin.clear(); cin.ignore();}
            switch(in)
            {
            case 1:
                break;
            case 2:
                return -1;
                break;
            }
        }
        else return id;
    }
}

void table_dantist::poshuk()
{
    int id;
    id=search_dantists();
    if(id!=-1)vec[id].getRl();
}

void table_dantist::edit_dantists()
{
    int id;
    id=search_dantists();
    if(id!=-1)vec[id].zkDantist();
}

void table_dantist::delete_dantists()
{
    int id;
    id=search_dantists();
    if(id!=-1)
    {
        vec.erase(vec.begin()+id);
        cout << "\t����������� ��������" <<endl;
    }
    else cout << "\t����������� �� ��������" <<endl;
}

void table_dantist::write_dantists_to_file()
{
    ofstream fRepresentative("Representatives.txt");
    for(int i=0; i<vec.size(); i++) vec[i].write_to_file(fRepresentative);//��� ������� �������� ��������� ������� ��� ������ � ����
    fRepresentative.close();
}

void table_dantist::read_dantists_from_file()
{
    ifstream fRepresentative("Representatives.txt");
    if(fRepresentative.is_open())
    {
        Dantist temp;
        while(!fRepresentative.eof())
        {
            temp.read_from_file(fRepresentative);
            vec.push_back(temp);
        }
        vec.erase(vec.end());
        fRepresentative.close();
    }

}

void table_dantist::menu_dantists()
{
    while(1)
    {
        cout <<"\t������� ��i� �����������------>|1|\n\t������ �����������------------>|2|\n\t������ �����������------------>|3|\n\t���������� ���i ��� �����������>|4|\n\t�������� �����������----------->|5|\n\t�����--------------------------->|6|" << endl;
        int inR;
        cin >> inR;
        switch(inR)
        {
        case 1:
            print_all_dantists();
            break;
        case 2:
            poshuk();
            break;
        case 3:
            add_new_dantists();
            break;
        case 4:
            edit_dantists();
            break;
        case 5:
            delete_dantists();
            break;
        case 6:
            return;
        }
    }
}


void Services::getSer() //������� ��� ��������� �� ����� ����� ��� �볺���
{
    cout<<"\n\t�������:    "<<services<<"\n\t�i��:       "<<price<<endl;
}
void Services::zdServices() //������� ��� �������� ����
{
    cout << "\t����i�� ���i ��� �������\n";
    cout << "\t�������: ";
    cin >> services;
    cout << "\t�i��: ";
    cin >> price;
    message();
}
void Services::write_to_file(ofstream &file)
{
    file<<services<<"\t"<<price<<endl;
}
void Services::read_from_file(ifstream &file)
{
    file >> services>>price;
}


void table_services::print_all_services()
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i].getSer(); /*cout<<endl;*/
    }
}

void table_services::add_new_services()
{
    Services temp;
    temp.zdServices();
    vec.push_back(temp);
}

int table_services::search_services(bool mozhna_povernutus)
{
    string services;
    int id=-1;
    while(true)
    {
        cout << "\n\t�������: ";
        cin >> services;
        for(int i=0; i<vec.size(); i++)
        {
            if((vec[i].getServices()==services))id=i;
        }
        if(id==-1)
        {
            if(!mozhna_povernutus)
            {
                cout << "\t������� �� ��������. ��������� �� ���." << endl;
                continue;
            }
            cout<<"\t������� �� ��������. ��������� �� ��� |1|, ��� ���������� � �������� ���� |2|" << endl;
            int in;
            cin >> in;
if(cin.get()!='\n'){cout << "������� �����, ��������� �� ���." << endl; cin.clear(); cin.ignore();}
            switch(in)
            {
            case 1:
                break;
            case 2:
                return -1;
                break;
            }
        }
        else return id;
    }
}

void table_services::poshuk()
{
    int id;
    id=search_services();
    if(id!=-1)vec[id].getSer();
}

void table_services::edit_services()
{
    int id;
    id=search_services();
    if(id!=-1)vec[id].zdServices();
}

void table_services::delete_services()
{
    int id;
    id=search_services();
    if(id!=-1)
    {
        vec.erase(vec.begin()+id);
        cout << "\t������� ��������" <<endl;
    }
    else cout << "\t������� �� ��������" <<endl;
}

void table_services::write_services_to_file()
{
    ofstream fServices("Services.txt");
    for(int i=0; i<vec.size(); i++) vec[i].write_to_file(fServices);//��� ������� �������� ��������� ������� ��� ������ � ����
    fServices.close();
}

void table_services::read_services_from_file()
{
    ifstream fServices("Services.txt");
    if(fServices.is_open())
    {
        Services temp;
        while(!fServices.eof())
        {
            temp.read_from_file(fServices);
            vec.push_back(temp);
        }
        vec.erase(vec.end()); //��������� ���������� ��'����, �� ���� ������
        fServices.close();
    }
}

void table_services::menuServices()
{
    while(1)
    {
        cout <<"\n\t������� ��i �������-------->|1|\n\t������ �������------------->|2|\n\t������ �������------------->|3|\n\t���������� ���i ��� �������>|4|\n\t�������� �������----------->|5|\n\t�����---------------------->|6|" << endl;
        int inC;
        cin >> inC;
        switch(inC)
        {
        case 1:
            print_all_services();
            break;
        case 2:
            poshuk();
            break;
        case 3:
            add_new_services();
            break;
        case 4:
            edit_services();
            break;
        case 5:
            delete_services();
            break;
        case 6:
            return;
        }
    }
}


void Order::getOrder() //������� ��� ��������� �� ����� ����� ��� �볺���
{
    cout<<"\n\t���� ���������:        "<<orderData<<"\n\t���� ������� � �����������: "<<dataOfIssue<<endl;
    cout<<"\tI�'� ��i����:           " << TABLE_CLIENT.vec[client_id].getName()
        << "\n\t��i����� ��i����:       " << TABLE_CLIENT.vec[client_id].getLastname() << endl;
    cout<<"\tI�'� �����������:      " << TABLE_DANTIST.vec[dantist_id].getfNameR()
        << "\n\t��i����� �����������:  " << TABLE_DANTIST.vec[dantist_id].getlNameR() << endl;
    cout<<"\t�������:                " << TABLE_SERVICES.vec[service_id].getServices() << endl;
}
void Order::zdOrder() //������� ��� �������� ����
{
    cout << "\t����i�� ���i ��� ����������\n";
    cout << "\t���� ���������: ";
    cin >> orderData;
    cout << "\t���� ������� � �����������: ";
    cin >> dataOfIssue;
    cout << "\t����i�� ���i ��� ��i����";
    client_id=TABLE_CLIENT.search_client(false);
    cout << "\t����i�� ���i ��� �����������";
    dantist_id=TABLE_DANTIST.search_dantists(false);
    cout << "\t����i�� ���i ��� �������";
    service_id=TABLE_SERVICES.search_services(false);

    message();
}
void Order::write_to_file(ofstream &file)
{
    file<<orderData<<"\t"<<dataOfIssue<<"\t"<<client_id<<"\t"<<dantist_id<<"\t"<<service_id<<endl;
}
void Order::read_from_file(ifstream &file)
{
    file >> orderData>>dataOfIssue>>client_id>>dantist_id>>service_id;
}


void table_order::print_all_orders()
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i].getOrder(); /*cout<<endl;*/
    }
}

void table_order::add_new_orders()
{
    Order temp;
    temp.zdOrder();
    vec.push_back(temp);
}

int table_order::search_orders()
{
    string orderData;
    int id=-1;
    while(true)
    {
        cout << "\n\t���� ���������: ";
        cin >> orderData;
        for(int i=0; i<vec.size(); i++)
        {
            if((vec[i].getOrderData()==orderData))id=i;
        }
        if(id==-1)
        {
            cout<<"\t���������� �� ��������. ��������� �� ��� |1|, ��� ���������� � �������� ���� |2|" << endl;
            int in;
            cin >> in;
            switch(in)
            {
            case 1:
                break;
            case 2:
                return -1;
                break;
            }
        }
        else return id;
    }
}

void table_order::poshuk()
{
    int id;
    id=search_orders();
    if(id!=-1)vec[id].getOrder();
}

void table_order::edit_orders()
{
    int id;
    id=search_orders();
    if(id!=-1)vec[id].zdOrder();
}

void table_order::delete_orders()
{
    int id;
    id=search_orders();
    if(id!=-1)
    {
        vec.erase(vec.begin()+id);
        cout << "\t���������� ��������" <<endl;
    }
    else cout << "\t���������� �� ��������" <<endl;
}

void table_order::write_orders_to_file()
{
    ofstream fOrder("Order.txt");
    for(int i=0; i<vec.size(); i++) vec[i].write_to_file(fOrder);//��� ������� �������� ��������� ������� ��� ������ � ����
    fOrder.close();
}

void table_order::read_orders_from_file()
{
    ifstream fOrder("Order.txt");
    if(fOrder.is_open())
    {
        Order temp;
        while(!fOrder.eof())
        {
            temp.read_from_file(fOrder);
            vec.push_back(temp);
        }
        vec.erase(vec.end()); //��������� ���������� ��'����, �� ���� ������
        fOrder.close();
    }
}
void table_order::menuOrder()
{
    while(1)
    {
        cout <<"\n\t������� ��i ����������-------->|1|\n\t������ ����������------------->|2|\n\t������ ����������------------->|3|\n\t���������� ���i ��� ����������>|4|\n\t�������� ����������----------->|5|\n\t�����------------------------->|6|" << endl;
        int inO;
        cin >> inO;
if(cin.get()!='\n') {cout << "������� �����, ��������� �� ���." << endl; cin.clear(); cin.ignore();}
        switch(inO)
        {
        case 1:
            print_all_orders();
            break;
        case 2:
            poshuk();
            break;
        case 3:
            add_new_orders();
            break;
        case 4:
            edit_orders();
            break;
        case 5:
            delete_orders();
            break;
        case 6:
            return;
        }
    }
}
table_client TABLE_CLIENT;
table_services TABLE_SERVICES;
table_dantist TABLE_DANTIST;
table_order TABLE_ORDER;
