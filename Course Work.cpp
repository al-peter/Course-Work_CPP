#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>

using namespace std;

struct Airport
 {
   string full_name;
   string flight_number;
   int baggage_receipt;
   int pieces_of_baggage;
   int total_weight_baggage;
 };

void MainMenu()
{
  cout << "   MENU\n"
       << "(0) Exiting the program.\n"
       << "(1) Create and fill an infobase.\n"
       << "Input choosen number: ";
};

void Manipulation_Filled_Base()
{
  Sleep(1000);
  cout << "   \nWhat would you like to do?\n"
       << "(0) Checking general inforamtion of existing DataBase (without added or deleted records).\n"
       << "(1) Adding records to the database.\n"
       << "(2) Deleting database records (passengers with a certain surname).\n"
       << "(3) Editing database records.\n"
       << "Input choosen number: ";
};

void DataBase_WindowText()
{
  cout << "\nINFOBASE:\n\n"
       << "======FULL NAME===="
       << "==FLIGH NUMBER===="
       << "==BAGGAGE RECEIPT===="
       << "==BAGGAGE ITEMS===="
       << "==TOTAL WEIGHT OF BAGGAGE" << "\n";
};

void DataBase_Display(int &number_of_passengers, Airport *&my_airport)
{
  for(int i = 0; i < number_of_passengers; i++)
  {
    cout << my_airport[i].full_name << "\t"
	       << my_airport[i].flight_number  << " \t \t "
	       << my_airport[i].baggage_receipt << " \t \t"
	       << my_airport[i].pieces_of_baggage
	       << " pieces" << " \t \t"
	       << my_airport[i].total_weight_baggage << "kg\n";
  }
};

int get_variant(int count) 
{
   int variant;
   string s;
   getline(cin, s);

   while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 0 || variant > count) 
   {
      cout << "Incorrect input. Try again: ";
      getline(cin, s);
   }

   return variant;
};

void resize(int &number_of_passengers, Airport *&my_airport) 
 {
    int newSize = number_of_passengers + 1;
    Airport* newArr = new Airport[newSize];

    copy(my_airport, my_airport + number_of_passengers, newArr);

    number_of_passengers = newSize;
    delete[] my_airport;
    my_airport = newArr;
}

void GeneralInforamtion(int &number_of_passengers, Airport *&my_airport)
{
   int key = 30;
	
   Sleep(1000);
	
   cout << "\n\n (*) Issuance of information about passengers whose baggage weight exceeds 30 kg:\n";
	
   Sleep(1500);
	
    multimap <int, string> name;
    for (int i = 0; i < number_of_passengers; i++)
    {  
      if (my_airport[i].total_weight_baggage > key)
      {
        name.insert(pair <int, string> (my_airport[i].total_weight_baggage, my_airport[i].full_name));
      }
    }
	
    cout << "\n";
	
    multimap <int, string> :: iterator it = name.begin();
    for (int i = 0; it != name.end(); it++, i++)
    {
      Sleep(200);
      cout << i+1 << ") Total Weight: " << it->first << ", Name: " << it->second << "\n" << endl;
    }

    multimap <int, string> number;
    for (int i = 0; i < number_of_passengers; i++)
    {   
      if (my_airport[i].total_weight_baggage > key)
      {
        number.insert(pair <int, string> (my_airport[i].total_weight_baggage, my_airport[i].flight_number));
      }
    }
	
    cout << "\n";
	
    multimap <int, string> :: iterator it1 = number.begin();
    for (int i = 0; it1 != number.end(); it1++, i++)
    {
      Sleep(200);
      cout << i+1 << ") Flight Number: " << it1->second << "\n" << endl;
    }

    multimap <int, int> receipt;
    for (int i = 0; i < number_of_passengers; i++)
    {   
      if (my_airport[i].total_weight_baggage > key)
      {
	      receipt.insert(pair <int, int> (my_airport[i].total_weight_baggage, my_airport[i].baggage_receipt));
      }
    }
	
    cout << "\n";
	
    multimap <int, int> :: iterator it2 = receipt.begin();
    for (int i = 0; it2 != receipt.end(); it2++, i++)
    {
      Sleep(200);
      cout << i+1 << ") Baggage Receipt: " << it2->second << "\n" << endl;
    }

    multimap <int, int> pieces;
    for (int i = 0; i < number_of_passengers; i++)
    {   
      if (my_airport[i].total_weight_baggage > key)
      {
        pieces.insert(pair <int, int> (my_airport[i].total_weight_baggage, my_airport[i].pieces_of_baggage));
      }
    }
	
    cout << "\n";
	
    multimap <int, int> :: iterator it3 = pieces.begin();
    for (int i = 0; it3 != pieces.end(); it3++, i++)
    {
      Sleep(200);
      cout << i+1 << ") Pieces of Baggage: " << it3->second << " pieces\n" << endl;
    }

   Sleep(1000);
	
   cout << "\n\n (*) Issuance of information about the location of baggage (flight number) according to the specified number of baggage receipt: ";
	
   Sleep(1500);
	
    multimap <int, string> location;
    for (int i = 0; i < number_of_passengers; i++)
    { 
      location.insert(pair <int, string> (my_airport[i].baggage_receipt, my_airport[i].flight_number));
    }
	
    cout << "\n";
	
    multimap <int, string> :: iterator it4 = location.begin();
    for (int i = 0; it4 != location.end(); it4++, i++)
    {
      Sleep(200);
      cout << "\nBaggage receipt: "  << it4->first << ", Flight Number: "  << it4->second << endl;
    }

   Sleep(1000);
	
   cout << "\n\n (*) Issuance of information on the total weight of the baggage of all passengers:\n";
	
   Sleep(1500);
	
    float sum = 0.0;
    for(int i = 0; i < number_of_passengers; i++)
    {
      sum += my_airport[i].total_weight_baggage;
    }

  Sleep(200);
   cout << "==========================================================";
   cout << "\nThe total weight of the baggage of all passengers: " << sum << "kg.|";
   cout << "\n==========================================================";
};

void Adding_Records(int &number_of_passengers, Airport *&my_airport)
{
  char name1[20];
  string number1;
  int receipt1;
  int pieces1;
  int weight1;
  int count = 1;
	
  for(int i = 0; i < count; i++)
  {
    cout << "\nInput passenger's full name (put at the end of the name ';'): ";
    cin.getline(name1,20,';');

    cout << "Input the amount of passenger's baggage (must be no more than 10 pieces): ";
    cin >> pieces1;

   if(pieces1 > 10)
   {
     cout << "The amount of baggage cannot exceed 10 pieces!\nPlease, enter valid number:";
     cin >> pieces1;
   }

   cout << "Input total weight of passenger's baggage (must not be heavier than 35 kg):";
   cin >> weight1;

   if(weight1 > 35)
   {
     cout << "The total weight of baggage cannot exceed 35 kg!\nPlease, enter valid number:";
     cin >> weight1;
   }

     switch (rand() % 4)
     {
        case 0: number1 = "AC" + to_string(rand() % 1000 + 1000); break;
        case 1: number1 = "SK" + to_string(rand() % 1000 + 1000); break;
        case 2: number1 = "AM" + to_string(rand() % 1000 + 1000); break;
        case 3: number1 = "SU" + to_string(rand() % 1000 + 1000); break;
     }

       receipt1 = rand() % 1000000 + 1000000000;
  }

  resize(number_of_passengers, my_airport);

  for (int i = 0; i < number_of_passengers; i++)
  {
    my_airport[20].full_name = name1;
    my_airport[20].flight_number = number1;
    my_airport[20].baggage_receipt = receipt1;
    my_airport[20].pieces_of_baggage = pieces1;
    my_airport[20].total_weight_baggage = weight1;
  }

  ofstream fout_added;

  string PATH_add = "C:\\Users\\HP\\Desktop\\Kursach\\DataBase after Adding.txt";

  fout_added.open(PATH_add);

  for(int i = 0; i < number_of_passengers; i++)
  {
    fout_added << my_airport[i].full_name << "\t"
               << my_airport[i].flight_number  << " \t \t "
               << my_airport[i].baggage_receipt << " \t \t"
               << my_airport[i].pieces_of_baggage
               << " pieces" << " \t \t"
               << my_airport[i].total_weight_baggage << "kg\n";
  }
 fout_added.close();

 DataBase_WindowText();
 DataBase_Display(number_of_passengers, my_airport);

 cout << "\nGeneral inforamtion of edited DataBase (added record):\n";
};

void Editing_Records(int &number_of_passengers, Airport *&my_airport)
{
  cout << "\nSelect the person whose information you want to edit in the database: ";

  for (int i = 0; i < number_of_passengers; i++)
  {
    cout << "\n" << i << ")" << my_airport[i].full_name;
  }

  cout << "\n\nEnter the number of the line that you want to edit: ";
  int line;
  cin >> line;

  int pieces2;
  int weight2;
  int count = 1;
	
  for(int i = 0; i < count; i++)
  {
      cout << "Input the amount of passenger's baggage (must be no more than 10 pieces): ";
      cin >> pieces2;

      if(pieces2 > 10)
      {
        cout << "The amount of baggage cannot exceed 10 pieces!\nPlease, enter valid number:";
        cin >> pieces2;
      }

      cout << "Input total weight of passenger's baggage (must not be heavier than 35 kg):";
      cin >> weight2;

      if(weight2 > 35)
      {
        cout << "The total weight of baggage cannot exceed 35 kg!\nPlease, enter valid number:";
        cin >> weight2;
      }
  }

  for (int i = 0; i < number_of_passengers; i++)
  {
    my_airport[line].pieces_of_baggage = pieces2;
    my_airport[line].total_weight_baggage = weight2;
  }
	
  ofstream fout_edited;

  string PATH_edit = "C:\\Users\\HP\\Desktop\\Kursach\\DataBase after Editing.txt";

  fout_edited.open(PATH_edit);

  for(int i = 0; i < number_of_passengers; i++)
 {
   fout_edited << my_airport[i].full_name << "\t"
               << my_airport[i].flight_number  << " \t \t "
               << my_airport[i].baggage_receipt << " \t \t"
               << my_airport[i].pieces_of_baggage
               << " pieces" << " \t \t"
               << my_airport[i].total_weight_baggage << "kg\n";
 }
 fout_edited.close();

 DataBase_WindowText();
 DataBase_Display(number_of_passengers, my_airport);
};

void Deleting_Records(int &number_of_passengers, Airport *&my_airport)
{
  cout << "\nSelect the person whose information you want to remove from the database: ";

  for (int i = 0; i < number_of_passengers; i++)
  {
    cout << "\n" << i+1 << ")" << my_airport[i].full_name;
  }
  string PATH_delete = "C:\\Users\\HP\\Desktop\\Kursach\\Database after Deleting.txt";
  ofstream fout_delete(PATH_delete);
  for(int i = 0; i < number_of_passengers; i++)
  {
    fout_delete << my_airport[i].full_name << "\t"
                << my_airport[i].flight_number  << " \t \t "
                << my_airport[i].baggage_receipt << " \t \t"
                << my_airport[i].pieces_of_baggage
                << " pieces" << " \t \t"
                << my_airport[i].total_weight_baggage << "kg\n";
  }
  fout_delete.close();

  ifstream file_in;

  file_in.open(PATH_delete);

  if(!file_in)
  {
    cout << "Error, the file cannot be opened!" << endl;
  }

  cout <<"\n\nEnter the number under whose name the data you want to delete: ";
  int i_number_line_delete = 0;
  cin >> i_number_line_delete;

  while (i_number_line_delete < 1 || i_number_line_delete > 20)
  {
    cout << "Incorrect number, try again: ";
    cin >> i_number_line_delete;
  }

  int i_number_line_now = 0;
  string line;
  string line_file_text;

  while(getline(file_in,line))
  {
    i_number_line_now++;

    if(!(i_number_line_now == i_number_line_delete))
    {
      line_file_text.insert(line_file_text.size(),line);
      line_file_text.insert(line_file_text.size(),"\r\n");
    }
   }

  file_in.close();

  ofstream file_out;

  file_out.open (PATH_delete,::ios::trunc | ::ios::binary);

  file_out.write(line_file_text.c_str(), line_file_text.size());
  file_out.clear();

  fout_delete.close();

  DataBase_WindowText();
	
  for (int i = 0; i < number_of_passengers; i++)
  {
    if (i != i_number_line_delete-1)
    {
      cout << my_airport[i].full_name << "\t"
           << my_airport[i].flight_number  << " \t \t "
           << my_airport[i].baggage_receipt << " \t \t"
           << my_airport[i].pieces_of_baggage
           << " pieces" << " \t \t"
           << my_airport[i].total_weight_baggage << "kg\n";
    }
  }

};

void InfoBase()
{
  cout << "\nBefore creating an infobase, create a password to access data changes: ";
  string password;
  getline(cin,password);

  int number_of_passengers = 20;

  Airport *my_airport = new Airport[number_of_passengers];

  cout << "Enter the path with the file where the Names.txt are located: ";
  string PATH1;
  cin >> PATH1;
  //"C:\\Users\\HP\\Desktop\\Kursach\\Names.txt"

  ifstream fin_names(PATH1);

  if (!fin_names.is_open())
  {
    cout << "File open error" << endl;
  }

  for (int i = 0; i < number_of_passengers; i++)
  {
    getline(fin_names, my_airport[i].full_name);
  }
  fin_names.close();

  ofstream fout_flight_numbers;

  string PATH2 = "C:\\Users\\HP\\Desktop\\Kursach\\Flight numbers.txt";

  fout_flight_numbers.open(PATH2);

  for (int i = 0; i < number_of_passengers; i++)
  {
    switch (rand() % 4)
    {
      case 0: my_airport[i].flight_number = "AC" + to_string(rand() % 1000 + 1000); break;
      case 1: my_airport[i].flight_number = "SK" + to_string(rand() % 1000 + 1000); break;
      case 2: my_airport[i].flight_number = "AM" + to_string(rand() % 1000 + 1000); break;
      case 3: my_airport[i].flight_number = "SU" + to_string(rand() % 1000 + 1000); break;
    }
    fout_flight_numbers << my_airport[i].flight_number << "\n";
  }
  fout_flight_numbers.close();

  ofstream fout_baggage_receipt;

  string PATH3 = "C:\\Users\\HP\\Desktop\\Kursach\\Baggage receipts.txt";

  fout_baggage_receipt.open(PATH3);

  for (int i = 0; i < number_of_passengers; i++)
  {
    my_airport[i].baggage_receipt = rand() % 1000000 + 1000000000;
    fout_baggage_receipt << my_airport[i].baggage_receipt << "\n";
  }
  fout_baggage_receipt.close();

  ofstream fout_pieces_of_baggage;

  string PATH4 = "C:\\Users\\HP\\Desktop\\Kursach\\Pieces of baggage.txt";

  fout_pieces_of_baggage.open(PATH4);

  for (int i = 0; i < number_of_passengers; i++)
  {
    my_airport[i].pieces_of_baggage = rand() % 9 + 3;
    fout_pieces_of_baggage << my_airport[i].pieces_of_baggage << "\n";
  }
  fout_pieces_of_baggage.close();

  ofstream fout_total_weight_baggage;

  string PATH5 = "C:\\Users\\HP\\Desktop\\Kursach\\Total baggage weight.txt";

  fout_total_weight_baggage.open(PATH5);

  for (int i = 0; i < number_of_passengers; i++)
  {
    if (my_airport[i].pieces_of_baggage < 5)
    {
      my_airport[i].total_weight_baggage = rand() % 25 + 4;
    }
    else
    {
      my_airport[i].total_weight_baggage = rand() % 10 + 25;
    }
    fout_total_weight_baggage << my_airport[i].total_weight_baggage << "\n";
  }
  fout_total_weight_baggage.close();

  ofstream fout_DataBase;

  string PATH6 = "C:\\Users\\HP\\Desktop\\Kursach\\Database.txt";

  fout_DataBase.open(PATH6);

  for(int i = 0; i < number_of_passengers; i++)
  {
    fout_DataBase << my_airport[i].full_name << "\t"
                  << my_airport[i].flight_number  << " \t \t "
                  << my_airport[i].baggage_receipt << " \t \t"
                  << my_airport[i].pieces_of_baggage
                  << " pieces" << " \t \t"
                  << my_airport[i].total_weight_baggage << "kg\n";
  }
  fout_DataBase.close();

  system("cls");
  DataBase_WindowText();
  DataBase_Display(number_of_passengers, my_airport);

  Manipulation_Filled_Base();

 int variant;
 variant = get_variant(4);
 switch(variant)
 {
   case 0: GeneralInforamtion(number_of_passengers, my_airport); break;
   case 1:
   {
     cout << "\nPlease, input the password created before: ";
     string password_check;
     getline(cin, password_check);

     while (password_check != password)
     {
         cout << "\nIncorrect password, try again: ";
         cin >> password_check;
     }
     if (password_check == password)
     {
       cout << "Correct password.\n";
       Adding_Records(number_of_passengers, my_airport); Sleep(1000); GeneralInforamtion(number_of_passengers, my_airport);
     }

   }break;
   case 2:
   {
     cout << "\nPlease, input the password created before: ";
     string password_check;
     getline(cin, password_check);

     while (password_check != password)
     {
         cout << "\nIncorrect password, try again: ";
         cin >> password_check;
     }
     if (password_check == password)
     {
       cout << "Correct password.\n";
       Deleting_Records(number_of_passengers, my_airport); Sleep(1000); //GeneralInforamtion(number_of_passengers, my_airport);
     }
   }break;
   case 3:
   {
     cout << "\nPlease, input the password created before: ";
     string password_check;
     getline(cin, password_check);

     while (password_check != password)
     {
       cout << "\nIncorrect password, try again: ";
       cin >> password_check;
     }
     if (password_check == password)
     {
       cout << "Correct password.\n";
       Editing_Records(number_of_passengers, my_airport); Sleep(1000); GeneralInforamtion(number_of_passengers, my_airport);
     }
   }break;
 };
}

int main()
{
  MainMenu();

  int variant;
  variant = get_variant(1);

  switch(variant)
  {
   case 0: exit(0); break;
   case 1: InfoBase(); break;
  }
}
