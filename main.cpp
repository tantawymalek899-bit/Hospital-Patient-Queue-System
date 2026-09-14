#include <iostream>
using namespace std;

const int MAX_SPECIALIZATION = 20;
const int MAX_QUEUE = 5;

int status[MAX_SPECIALIZATION + 1][MAX_QUEUE];
string names[MAX_SPECIALIZATION + 1][MAX_QUEUE];
int length_queue[MAX_SPECIALIZATION + 1];

void shift_left(int spec, string names_sp[], int status_sp[])
{
    int pos = length_queue[spec];
    for (int i = 0; i < pos; i++)
    {
        names_sp[i - 1] = names_sp[i];
        status_sp[i - 1] = status_sp[i];
    }
    length_queue[spec]--;
}

void shift_right(int spec, string names_sp[], int status_sp[])
{
    int len = length_queue[spec];
    for (int i = len - 1; i >= 0; --i)
    {
        names_sp[i + 1] = names_sp[i];
        status_sp[i + 1] = status_sp[i];
    }
    length_queue[spec]++;
}

bool Add_patient()
{
    int spec;
    string name;
    int st;
    cout << "Enter specializatin, name, status: ";
    cin >> spec >> name >> st;

    int pos = length_queue[spec];
    if (pos >= MAX_QUEUE)
    {
        cout << "Sorry we can't add more patient to this specialization\n";
        return false;
    }

    if (st == 0)
    {
        names[spec][pos] = name;
        status[spec][pos] = st;
        length_queue[spec]++;
    }

    else
    {
        shift_right(spec, names[spec], status[spec]);
        names[spec][0] = name;
        status[spec][0] = st;
    }
    return true;
}

void print_patient(int spec, string name_sp[], int status_sp[])
{
    int len = length_queue[spec];
    if (len == 0)
        return;
    cout << "There are " << length_queue[spec] << " patients in specialization " << spec << endl;

    for (int i = 0; i < len; i++)
    {
        cout << names[spec][i] << " ";
        if (status_sp[i] == 0)
            cout << "regular\n";
        else
            cout << "uregant\n";
    }
}

void print_patients()
{
    cout << "\n*****************************\n";
    for (int spec = 0; spec < MAX_SPECIALIZATION; spec++)
    {
        print_patient(spec, names[spec], status[spec]);
    }
}

void get_next_patient()
{
    int spec;
    cout << "Enter specialization: ";
    cin >> spec;
    int pos = length_queue[spec];
    if (pos == 0)
    {
        cout << "There is no patient for now, take a rest ,DR\n";
        return;
    }

    cout << names[spec][0] << " please go with Dr\n";
    shift_left(spec, names[spec], status[spec]);
}

int menu()
{
    int choice = -1;
    while (choice == -1)
    {
        cout << "\nEnter your choice:\n";
        cout << "1)Add new patient\n";
        cout << "2)Print All Patient\n";
        cout << "3)Get next patient\n";
        cout << "4)Exis\n";

        cin >> choice;

        if (!(1 <= choice && choice <= 4))
        {
            cout << "Invalid input try again\n";
            choice = -1;
        }
    }

    return choice;
}
void hospital_system()
{
    while (true)
    {
        int choice = menu();
        if (choice == 1)
            Add_patient();
        else if (choice == 2)
            print_patients();
        else if (choice == 3)
            get_next_patient();
        else
            break;
    }
}

int main()
{
    hospital_system();
    return 0;
}