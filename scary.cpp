// Abdullah ali khan 
// this file define all the fuctions
#include "scary.h"
#include <iostream>
#include <cstring>

using namespace std;

stack::stack()
{
	top = nullptr;
	top_index =0;
}

int stack::push(prop & to_add)
{
	if (top == nullptr || top_index == MAX)
	{
		stack_node * new_node = new stack_node;
		new_node->next = top;
		new_node->props = new prop[MAX];
		top = new_node;
		top_index = 0;
	}

	top->props[top_index].name = new char[strlen(to_add.name) + 1];
   	strcpy (top->props[top_index].name, to_add.name);

	top->props[top_index].scare_level = to_add.scare_level;
	
	top->props[top_index].battery_percent = to_add.battery_percent;
	
	top->props[top_index].time = to_add.time;

	++top_index;

	return 1;

}

int stack::display_all()
{
	if (top == nullptr)
	{
		cout << "Stack is empty.\n";
        	return 0;
	}
	display_all_recursive(top, top_index);
	return 1;
}

void stack::display_all_recursive(stack_node * head , int index)
{
	if (head == nullptr)
	{
		return;
	}

	for (int i = index -1 ; i >=0; --i)
	{
	        cout << "Prop: " << head->props[i].name << endl;
        	cout << "Scare Level: " << head->props[i].scare_level << endl;
        	cout << "Battery percentage : " << head->props[i].battery_percent << endl;
        	cout << "Time: " << head->props[i].time << endl;	
	}

	display_all_recursive(head->next, MAX);
}

int stack::pop(prop & remove)
{
	if (top == nullptr)
	{
		cout<<"Stact is empty "<<endl;
		return 0;
	}

	--top_index;
	remove.name = new char[strlen(top->props[top_index].name) + 1];
    	strcpy(remove.name, top->props[top_index].name);

    	remove.scare_level = top->props[top_index].scare_level;
	 
	remove.battery_percent = top->props[top_index].battery_percent;

	remove.time = top->props[top_index].time;

	if (top_index == 0)
	{
		stack_node * temp = top;
		top = top->next;
		delete [] temp->props;
		delete temp;

		if (top != nullptr)
			top_index = MAX;
	}
	return 1;
}	

int stack::peek(prop & found)
{
	if (top == nullptr)
	{
		cout<<"Stack is empty"<<endl;
		return 0;
	}
	int index = top_index-1;

	found.name = new char[strlen(top->props[index].name) + 1];
   	strcpy(found.name, top->props[index].name);

   	found.scare_level = top->props[index].scare_level;
    	
	found.battery_percent = top->props[index].battery_percent;

	found.time = top->props[index].time;

	return 1;

}
stack::~stack()
{
    
    while (top != nullptr)
    {
       
        stack_node * temp = top;
        top = top->next;

   
        for (int i = 0; i < MAX; ++i)
        {
            delete [] temp->props[i].name;
        }

        
        delete [] temp->props;
        delete temp;
    }

    
    top = nullptr;
    top_index = 0;
}

queue::queue()
{
	rear = nullptr;
}

int queue::enqueue(group & to_add)
{
	queue_node * new_node = new queue_node;
	  
	new_node->data.full_name = new char[strlen(to_add.full_name) + 1];
    	strcpy(new_node->data.full_name, to_add.full_name);

	new_node->data.group_size = to_add.group_size;

	new_node->data.costume_theme = new char[strlen(to_add.costume_theme) + 1];
	strcpy(new_node->data.costume_theme, to_add.costume_theme);

	new_node->data.ticket_number = to_add.ticket_number;
	
	new_node->data.scare_intensity = to_add.scare_intensity;	
	

	if (rear == nullptr)
	{
		rear = new_node;
		rear->next = rear;
	}
	else
	{
		new_node->next = rear->next;
		rear->next = new_node;
		rear = new_node;
	}

	return 1;
}

int queue::display_all()
{
	if (rear == nullptr)
	{
		cout << "Queue is empty.\n";
		return 0;
	}

	display_all_recursive(rear, rear->next);
	return 1;
}

void queue::display_all_recursive(queue_node * rear, queue_node * head)
{
	if (head == nullptr)
		return;

	  cout << "Leader: " << head->data.full_name << endl;
	  cout << "Group Size: " << head->data.group_size << endl;
          cout << "Costume Theme: " << head->data.costume_theme << endl;
	  cout << "Ticket #: " << head->data.ticket_number << endl;
          cout << "Scare intencity: " << head->data.scare_intensity << endl << endl;

	  if (head == rear)
		  return;

	  display_all_recursive(rear, head->next);

}

int queue::dequeue(group & removed)
{
    if (rear == nullptr)
    {
        cout << "Queue is empty.\n";
        return 0;
    }

    queue_node * front = rear->next;  

   
    removed.full_name = new char[strlen(front->data.full_name) + 1];
    strcpy(removed.full_name, front->data.full_name);

    removed.group_size = front->data.group_size;

    removed.costume_theme = new char[strlen(front->data.costume_theme) + 1];
    strcpy(removed.costume_theme, front->data.costume_theme);

    removed.ticket_number = front->data.ticket_number;

    removed.scare_intensity = front->data.scare_intensity;


    
    if (rear == front)
    {
        delete [] front->data.full_name;
        delete [] front->data.costume_theme;
        delete front;
        rear = nullptr;
    }
    else
    {
        rear->next = front->next; 
        delete [] front->data.full_name;
        delete [] front->data.costume_theme;
        delete front;
    }

    return 1;
}

int queue::peek(group & found)
{
    if (rear == nullptr)
    {
        cout << "Queue is empty.\n";
        return 0;
    }

    queue_node * front = rear->next;

    found.full_name = new char[strlen(front->data.full_name) + 1];
    strcpy(found.full_name, front->data.full_name);

    found.group_size = front->data.group_size;

    found.costume_theme = new char[strlen(front->data.costume_theme) + 1];
    strcpy(found.costume_theme, front->data.costume_theme);

    found.ticket_number = front->data.ticket_number;

    found.scare_intensity = front->data.scare_intensity;

    return 1;
}

queue::~queue()
{
    if (rear == nullptr)
        return;

    queue_node * current = rear->next; 
    rear->next = nullptr;             

    while (current)
    {
        queue_node * temp = current->next;

        delete [] current->data.full_name;
        delete [] current->data.costume_theme;

        delete current;
        current = temp;
    }

    rear = nullptr;
}

