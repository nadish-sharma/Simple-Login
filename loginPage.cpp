#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
using namespace std;

void registerAccount();
void login();
void forgotPassword();

int main()
{
  int choice;
  cout <<"Press 1 for Login" << endl << "Press 2 for Registration" << endl
       << "Press 3 to Change Password" << endl << "Press 4 to exit" << endl;
  cin >> choice;
  switch(choice)
  {
    case(1):
    {
      login();

      break;
    }
    case(2):
    {
      registerAccount();
      break;
    }
    case(3):
    {
      forgotPassword();

      break;
    }
    case(4):
    {
      cout << "Thank you!" << endl;

      break;
    }
    default:
    {

      cout << "You have entered a wrong choice" << endl;
      main();
    }
  }
  return 0;
}
void registerAccount()
{
  int counterID = 0;
  int c = 0;
  int counterPass = 0;
  int cSpecial, cNumeric, cLargeAlphabet, cSmallAlphabet;
  string user, pswd, userID, password;
  ifstream input;
  input.open("resource.txt");
  fstream temp;
  temp.open("tempResource.txt");
  cout << "Welcome, please enter the following information to register your account" << endl;
  do
  {
    cout << "Enter username" << endl;
    cin >> user;
    while(!input.eof() && c == 0 && counterID == 0)
    {
        input >> userID >> password;
        if (user == userID)
        {
          cout << "This username is already taken, please try another one" << endl;
          c = 1;
          user = "";
        }
        else
        {
            counterID = 1;
        }
    }

  }
  while(counterID == 0);

  while (counterPass == 0)
  {
    cout << "Enter password" << endl;
    cin >> pswd;
    for(unsigned int i = 0; i < pswd.length(); i++)
    {
      char check = pswd[i];
          if (('!'<=check && check<='/') || (':'<=check && check<= '@')
                || ('[' <=check && check <= '`') || ('{' <=check && check <= '~'))
          {
            cSpecial = 1;
          }
          if ('A'<=check && check <='Z')
          {
            cLargeAlphabet = 1;
          }
          if ('a'<=check && check <='z')
          {
            cSmallAlphabet = 1;
          }
          if ('0'<=check && check <='9')
          {
            cNumeric = 1;
          }
    }

        if (cSpecial == 1 && cNumeric == 1 && cLargeAlphabet == 1 && cSmallAlphabet == 1)
        {
          cout << user << " your account has been successfully created" << endl;
          counterPass = 1;

          if(counterID == 1 && counterPass == 1)
            {
              string tempLine;
              input.close();
              input.open("resource.txt");
              while(!input.eof())
              {
                getline(input, tempLine);
                if(tempLine != "")
                {
                    temp << tempLine << endl;
                }
              }
              temp << user << " " << pswd << endl;
            }
        }
        else
        {
            cout << "Error! Your password must have atleast one lower alphabet and one upper alphabet";
            cout << "one numeric and one special character and no spaces" << endl;
        }
  }
      input.close();
      temp.close();
      remove("resource.txt");
      rename("tempResource.txt", "resource.txt");
      main();
}

void login()
{
  string user, pswd, userID, password;
  int count = 0;
  cout << "Enter your username" << endl;
  cin >> user;
  cout <<"Enter your password" << endl;
  cin >> pswd;
  ifstream input;
  input.open("resource.txt");
  while(!input.eof()&&count == 0)
  {
      input>>userID>>password;
    if (userID == user && password == pswd)
    {
      count = 1;
    }
  }
    input.close();
    if (count == 1)
    {
        cout << user << " you have successfully logged in" << endl;
    }
    else
    {
      cout << "You have either entered a wrong username or password" << endl;
      main();
    }
}
void forgotPassword()
{
  string user, pswd, userID, password;
  int cSpecial,cNumeric,cLargeAlphabet, cSmallAlphabet;
  ifstream input;
  int counterPass= 0;
  input.open("resource.txt");
  fstream temp;
  temp.open("tempResource.txt");
  cout << "Please enter your username" <<endl;
  cin >> user;
  while(counterPass == 0)
  {
    cout << "Enter a new password" << endl;
    cin >> pswd;
    for(unsigned int i = 0; i < pswd.length(); i++)
    {
        char check = pswd[i];
        if (('!'<=check && check<='/') || (':'<=check && check<= '@')
             || ('[' <=check && check <= '`') || ('{' <=check && check <= '~'))
        {
            cSpecial = 1;
        }
        if ('A'<=check && check <='Z')
        {
            cLargeAlphabet = 1;
        }
        if ('a'<=check && check <='z')
        {
            cSmallAlphabet = 1;
        }
        if ('0'<=check && check <='9')
        {
            cNumeric = 1;
        }
    }
    if (cSpecial == 1 && cNumeric == 1 && cLargeAlphabet == 1 && cSmallAlphabet == 1)
    {
        cout << user << " your password has been successfully updated" << endl;
        counterPass = 1;
    }
    else
    {
        system("cls");
    }
   }

  input.close();
  input.open("resource.txt");

  while(!input.eof())
    {
     string tempLine;
     getline(input, tempLine);
     if(user != userID)
     {
        if(tempLine != "")
        {
          temp << tempLine << endl;
        }
     }
     else
     {
        temp << user << " " << pswd << endl;
     }
    }
    temp.close();
    input.close();
    remove("resource.txt");
    rename("tempResource.txt", "resource.txt");
    main();
}
