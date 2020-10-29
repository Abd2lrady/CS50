#include<stdio.h>
#include<cs50.h>

int main(void)
{
    // ask user of his/her name 
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}