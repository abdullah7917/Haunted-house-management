// Abdullah ali khan 
// this file contains classes,structs 

const int MAX =5;
struct prop
{
    char * name;          
    int scare_level;       
    int battery_percent;   
    int time;     
};

struct group
{
    char * full_name; // leader's full name
    int group_size;
    char * costume_theme;
    int ticket_number;
    int scare_intensity;
};


struct stack_node
{
    prop * props;          // dynamically allocated array        
    stack_node * next;    
};

class stack
{
public:

    stack();
    ~stack();

    int push(prop & to_add);
    int pop(prop & remove);
    int peek(prop & found);
    int display_all();

private:
    stack_node * top;
    int top_index;
    void display_all_recursive (stack_node *head , int index);
};

struct queue_node
{
    group data;
    queue_node * next;
};

class queue
{
public:
    queue();              
    ~queue();              

    int enqueue(group & to_add);
    int dequeue(group & remove);
    int peek(group & found);
    int display_all();

private:
    queue_node * rear;     

    // helper function
    void display_all_recursive(queue_node * rear, queue_node * start); // for recursion
};
