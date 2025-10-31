// Abdullah ali khan , khanab@pdx.edu ,cs1632
// this file calls the fuctions and displays all the promts 
#include "scary.h"

#include <iostream>
#include <cstring>
using namespace std;

     void get_prop_info(prop & new_prop)
     {
	char temp[100]; 

    	cout << "\nEnter prop name: ";
    	cin.getline(temp, 100);
    	new_prop.name = new char[strlen(temp) + 1];
    	strcpy(new_prop.name, temp);

    	cout << "Enter scare level (1–10): ";
    	cin >> new_prop.scare_level;
    	cin.ignore(100, '\n');

    	cout << "Enter battery percent (0–100): ";
   	cin >> new_prop.battery_percent;
    	cin.ignore(100, '\n');

    	cout << "Enter time duration in minutes:  ";
    	cin >> new_prop.time;
        cin.ignore(100, '\n');

     }

void get_group_info(group & new_group)
{
    char temp[100];

    cout << "\nEnter leader name: ";
    cin.getline(temp, 100);
    new_group.full_name = new char[strlen(temp) + 1];
    strcpy(new_group.full_name, temp);

    cout << "Enter group size: ";
    cin >> new_group.group_size;
    cin.ignore(100, '\n');

    cout << "Enter costume theme: ";
    cin.getline(temp, 100);
    new_group.costume_theme = new char[strlen(temp) + 1];
    strcpy(new_group.costume_theme, temp);

    cout << "Enter ticket number: ";
    cin >> new_group.ticket_number;
    cin.ignore(100, '\n');

    cout << "Enter scare intensity(1-5): ";
    cin >> new_group.scare_intensity;
    cin.ignore(100, '\n');

  
}



int main()
{

        stack my_stack;  
    	prop my_prop;
	prop remove;
	prop found;
	
	queue my_queue;
	group my_group;
	group remove_group;
	group found_group;
 
  int choice = 0;

  while (choice !=3)
  {
	  cout<<" 1. Work with the prop (stack)\n";
	  cout<<" 2. Work with the group (queue)\n";
	  cout<<" 3. Exit\n";
	  cout<<" Enter you choice: ";
	  cin >> choice;
          cin.ignore(100, '\n');

	if (choice == 1)
	  {
		int choice_2 =0;

		while (choice_2 != 5)
		{
			cout << "1. Push a new scary prop\n";
			cout << "2. Pop (use) the top prop\n";
			cout << "3. Peek at the top prop\n";
			cout << "4. Display all props (recursive)\n";
			cout << "5. Exit\n";
			cout << "Enter you choice: "<<endl;
			cin >> choice_2;
			cin.ignore(100, '\n');

			if (choice_2 == 1)
			{
				get_prop_info(my_prop);

				if (my_stack.push(my_prop))
					cout<<"Prop added\n";
				else
					cout<<"failed to add\n";

			}

			else if (choice_2 == 2)
			{	
		    
				prop remove;
				if (my_stack.pop(remove))
				{	
					cout << "\nRemoved Prop Details:\n";
					cout << "Name: " << remove.name << "\n";
					cout << "Scare Level: " << remove.scare_level << "\n";
					cout << "Battery: " << remove.battery_percent<< "%\n";
					cout << "Extra: " << remove.time << "\n";
				}
				else
					cout << "Stack is empty. Nothing to pop.\n";
			}

			else if (choice_2 == 3)
			{
				if (my_stack.peek(found))
				{
					cout << "\nTop Prop Details:\n";
					cout << "Name: " << found.name << "\n";
					cout << "Scare Level: " << found.scare_level << "\n";
					cout << "Battery: " << found.battery_percent << "%\n";
					cout << "Time: " << found.time << " minutes\n";
				}
				else
					cout<<"Stack is empty"<<endl;
			}

			else if (choice_2 == 4)
			{
				my_stack.display_all();
			}

			else if (choice_2 == 5)
			{
				cout<<"Thank You"<<endl;
			}

			else
			cout<<"Invalid choice";
        }
    }

  
  else if (choice == 2)
  {
      int choice_3 = 0;
      while (choice_3 !=5)
      {	      
	cout << "1. Enqueue a new visitor group\n";
        cout << "2. Dequeue a visitor group \n";
        cout << "3. Peek at next group\n";
        cout << "4. Display all groups \n";
        cout << "5. Exit program\n";
        cout << "Enter your choice: ";
        cin >> choice_3;
        cin.ignore(100,'\n');

	if (choice_3 == 1)
	{
		get_group_info(my_group);

		if (my_queue.enqueue(my_group))
			cout<<"Group added to queue\n";
		else
			cout<<"Failed to add the group";	

	}

	else if (choice_3 == 2)
	{
		if (my_queue.dequeue(remove_group))
			cout<<"Group led by "<< remove_group.full_name<<" entered the haunted house\n";
		else 
			cout<<"Queue is empty. \n";
	}

	else if (choice_3 == 3)
        {
                if (my_queue.peek(found_group))
    			cout << "Next group: " << found_group.full_name << " (" << found_group.group_size << " people)\n";
                else
     			cout << "Queue is empty.\n";
        }
        else if (choice_3 == 4)
	{
                    my_queue.display_all();
        }
        else if (choice_3 == 5)
        {
                cout << "Thank You\n";
        }
        else
        {
       		cout << "Invalid choice.\n";
	}


      }
   }
  

  else if (choice == 3)
  {
	  cout<<"Thank You\n";
  }

  else
  {
	  cout<<"Invalid choice \n";
  }


return 0;
}
}
