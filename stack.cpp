#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

struct element
{
    int data;
    element* next = nullptr;
};

void push(element* &stack, int value);
void pop(element* &stack);
bool isEmpty(element* stack);
int top(element* stack);
void clearStack(element* &stack);

int main()
{
    element* stack_top = nullptr;
    string menu = "Menu:\n"
                  "1. PUSH\n"
                  "2. POP\n"
                  "3. IS EMPTY?\n"
                  "4. TOP\n"
                  "5. CLEAR STACK\n"
                  "6. STOP\n"
    ;
    cout<<menu;
    int a;
    while(a)
    {
        cin>>a;
        switch(a){
            case 1:
                {
                    srand(time(NULL));
                    int t = rand()%31;
                    push(stack_top, t);
                }
                break;
            case 2:
                {
                    pop(stack_top);
                }
                break;
            case 3:
                {
                    if(isEmpty(stack_top))
                    {
                        cout<<"It is empty"<<endl;
                    }
                    else
                    {
                        cout<<"It is not empty"<<endl;
                    }
                }
                break;
            case 4:
                {
                    if(top(stack_top))
                    {
                        cout<<"TOP ELEMENT: "<<top(stack_top)<<endl;
                    }
                    else
                    {
                        cout<<"NO ELEMENT ON TOP"<<endl;
                    }
                }
                break;
            case 5:
                {
                    clearStack(stack_top);
                }
                break;
            case 6:
                {
                    a = 0;
                }
                break;
            }
    }
    return 0;
}

void push(element* &stack, int value)
{
    element *el = new element;
    el->data = value;
    el->next = stack;
    stack = el;
}
void pop(element* &stack)
{
    if(stack == nullptr)
    {
        cout<<"Nothing to POP"<<endl;
    }
    else
    {
        cout<<"POP ELEMENT"<<endl;
        element *temp = stack;
        stack = stack->next;
        delete temp;
    }
}
bool isEmpty(element* stack)
{
    return stack == nullptr;
}
int top(element* stack)
{
    if(stack != nullptr)
    {
        return stack->data;
    }
    else
    {
        return 0;
    }
}
void clearStack(element* &stack)
{
    while(stack != nullptr)
    {
        element *temp = stack;
        stack = stack->next;
        delete temp;
    }
    cout<<"STACK IS CLEAR"<<endl;
}
