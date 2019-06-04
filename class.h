#include <iostream>
#include<fstream>
#include<cstdlib>   //�������� ��� exit
#include <vector>
using namespace std;

class Client //����
{
private: // ������������ ������� private
    string name,
           lastname,
           email,
           tel;
public: // ������������ ������� public
    string getName()
    {
        return name;
    }
    string getLastname()
    {
        return lastname;
    }
    void message() // ������� (����� �����), ��� �������� ����������� �� �����
    {
        cout << "\t���i ���������!\n\n";
    }
    void getCl(); //������� ��� ��������� �� ����� ����� ��� �볺���
    void zdClient(); //������� ��� �������� ����

    void write_to_file(ofstream &file);
    void read_from_file(ifstream &file);
};

class table_client
{
public:
    vector <Client> vec;
    void print_all_clients();

    void add_new_client();

    int search_client(bool mozhna_povernutus=true);

    void poshuk();

    void edit_client();

    void delete_client();

    void write_clients_to_file();

    void read_clients_from_file();

    void menu();
    table_client()
    {
        read_clients_from_file();   //�����������
    }
    ~table_client()
    {
        write_clients_to_file();   //����������
    }
};

class Dantist //����
{
private: // ������������ ������� private
    string NameDantist,  //��'�
           SNameDantist,  //�������
           adress,     //������
           posada,      //������
           email,     //email
           pd,     //�������� ���
           tel,      //����� ��������
           salary;      //��������
public: // ������������ ������� public
    string getfNameR()
    {
        return NameDantist;
    }
    string getlNameR()
    {
        return SNameDantist;
    }
    void message() // ������� (����� �����), ��� �������� ����������� �� �����
    {
        cout << "\t���i ���������!\n\n";
    }
    void getRl(); //������� ��� ��������� �� ����� ����� ��� �볺���

    void zkDantist(); //������� ��� �������� ����

    void write_to_file(ofstream &file);
    void read_from_file(ifstream &file);
};

class table_dantist
{
public:
    vector <Dantist> vec;
    void print_all_dantists();

    void add_new_dantists();

    int search_dantists(bool mozhna_povernutus=true);

    void poshuk();
    void edit_dantists();

    void delete_dantists();

    void write_dantists_to_file();

    void read_dantists_from_file();

    void menu_dantists();
    table_dantist()
    {
        read_dantists_from_file();   //�����������
    }
    ~table_dantist()
    {
        write_dantists_to_file();   //����������
    }
};

class Services //����
{
private: // ������������ ������� private
    string services;
    int    price;
public: // ������������ ������� public
    string getServices()
    {
        return services;
    }

    void message() // ������� (����� �����), ��� �������� ����������� �� �����
    {
        cout << "\t���i ���������!\n\n";
    }
    void getSer(); //������� ��� ��������� �� ����� ����� ��� �볺���
    void zdServices(); //������� ��� �������� ����

    void write_to_file(ofstream &file);
    void read_from_file(ifstream &file);
};

class table_services
{
public:
    vector <Services> vec;
    void print_all_services();

    void add_new_services();

    int search_services(bool mozhna_povernutus=true);

    void poshuk();

    void edit_services();

    void delete_services();

    void write_services_to_file();

    void read_services_from_file();

    void menuServices();
    table_services()
    {
        read_services_from_file();   //�����������
    }
    ~table_services()
    {
        write_services_to_file();   //����������
    }
};

extern table_client TABLE_CLIENT;
extern table_services TABLE_SERVICES;
extern table_dantist TABLE_DANTIST;


class Order: public Client, public Dantist, public Services
{
private:
    string orderData,      //���� ����������
           dataOfIssue;    //���� ������ ����������
    int client_id, dantist_id, service_id;
    /*��� �� ���� �� � ������� �볺��� �� �����������
    */

public: // ������������ ������� public
    string getOrderData()
    {
        return orderData;
    }

    void message() // ������� (����� �����), ��� �������� ����������� �� �����
    {
        cout << "\t���i ���������!\n\n";
    }
    void getOrder(); //������� ��� ��������� �� ����� ����� ��� �볺���
    void zdOrder(); //������� ��� �������� ����
    void write_to_file(ofstream &file);
    void read_from_file(ifstream &file);
};

class table_order
{
public:
    vector <Order> vec;

    void print_all_orders();
    void add_new_orders();

    int search_orders();

    void poshuk();

    void edit_orders();

    void delete_orders();

    void write_orders_to_file();

    void read_orders_from_file();

    void menuOrder();
    table_order()
    {
        read_orders_from_file();   //�����������
    }
    ~table_order()
    {
        write_orders_to_file();   //����������
    }
};
extern table_order TABLE_ORDER;
