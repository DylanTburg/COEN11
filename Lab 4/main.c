#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef union
{
    int retired_years;
    float salary;
    char school[100];
} Attributes;
typedef struct
{
    char firstName[100];
    char lastName[100];
    int age;
    Attributes human;
} Person;
Person people[10];
char number = '6';
int entry = 0;
void insert()
{
    Person *new_person = &people[entry];
    if (entry >= 10)
    {
        printf("No more spaces!");
        return;
    }
    char str[100];
    char str2[100];
    printf("Enter your first name: \n");
    scanf("%s", &str);
    printf("Enter your last name: \n");
    scanf("%s", &str2);
    if (check_duplicate(str, str2) == 1)
    {
        return;
    }
    strcpy(&new_person->firstName, str);
    strcpy(&new_person->lastName, str2);
    printf("Enter your age: \n");
    scanf("%d", &new_person->age);
    if ((new_person->age) <= 18)
    {
        printf("Type the school you go to (one name): \n");
        scanf("%s", &new_person->human.school);
    }
    else if ((new_person->age) > 18 && (new_person->age) <65)
    {
        printf("Type your salary (no commas): \n");
        scanf("%f", &new_person->human.salary);
    }
    else if ((new_person->age) >=65)
    {
        printf("Type how many years you've been retired: \n");
        scanf("%d", &new_person->human.retired_years);
    }
    for (int j=entry - 1; j >= 0; j--)
    {
        int e = strcmp(people[j + 1].lastName, people[j].lastName);
        if (e < 0)
        {
            Person temp = people[j];
            people[j]= people[j + 1];
            people[j + 1] = temp;
        }
    }
    entry++;

}

int check_duplicate(char *string, char *string2)
{
    int d;
    Person *p = people;
    for (d=0; d < 10; d++, p++)
    {
        int val = strcmp(string, p->firstName);
        int val2 = strcmp(string2, p->lastName);
        if (val == 0 && val2 == 0)
        {
            printf("No duplicates!");
            return 1;
        }
    }
    return 0;
}
void list()
{
    Person *p;
    for (p=people; strcmp(p->firstName,""); p++)
    {
        if (p->age <= 18)
        {
            printf("%s %s is %d years old and goes to %s.\n", p->firstName, p->lastName, p->age, p->human.school);
        }
        else if (p->age > 18 && p->age < 65)
        {
            printf("%s %s is %d years old and earns $%.2f annually.\n", p->firstName, p->lastName, p->age, p->human.salary);
        }
        else if (p->age >= 65)
        {
            printf("%s %s is %d years old and has been retired for %d years.\n", p->firstName, p->lastName, p->age, p->human.retired_years);
        }

    }
}
void list_age()
{
    Person *p;
    int test1 = 0;
    int age1 = 0;
    printf("What age are you looking for?\n");
    scanf("%d", &age1);
    for (p=people; strcmp(p->firstName,""); p++)
    {
        if (age1 == p->age)
        {
            printf("%s %s is %d years old. \n",p->firstName, p->lastName, p->age);
            test1 = 1;
        }

    }
    if (test1 == 0)
    {
        printf("No one is %d years old. \n", age1);
    }
}
void remove1()
{
    int d = 0;
    Person *p = &people[d];
    char remove2[100];
    int choice;
    char remove3[100];
    printf("Enter a first name to remove (type first name): \n");
    scanf("%s", &remove2);
    printf("Enter a last name to remove (type last name): \n");
    scanf("%s", &remove3);
    for (d; d < entry; d++, p++)
    {
        int z;
        int y;
        z = strcmp(remove2, p->firstName);
        y = strcmp(remove3, p->lastName);
        if (z == 0 && y ==0)
        {
            printf("Are you sure you want to get rid of %s %s from the list? 0 for yes, 1 for no. \n", p->firstName, p->lastName);
            scanf("%d", &choice);
            if (choice == 0)
            {
                for(int x = d; x < entry; x++)
                {
                    Person *q = &people[x+1];
                    Person *o = &people[x];
                    strcpy(o->firstName,q->firstName);
                    strcpy(o->lastName,q->lastName);
                    o->age = q->age;
                    o->human = q->human;
                }
                printf("Removed.");
                entry--;
                return;
            }

            else if (choice == 1)
            {
                printf("You have chosen to keep %s %s in the list\n", p->firstName, p->lastName);
                return;
            }
            else
            {
                printf("Not a valid option.");
            }
        }
    }
    return;
}
void remove_age()
{
    int d = 0;
    Person *p = &people[d];
    int age0;
    printf("Enter an age to remove all names associated: \n");
    scanf("%d", &age0);
    while (d < entry)
    {
        if (age0 == p->age)
        {
            for(int x = d; x < entry; x++)
            {
                Person *q = &people[x+1];
                Person *o = &people[x];
                strcpy(o->firstName,q->firstName);
                strcpy(o->lastName,q->lastName);
                o->age = q->age;
                o->human = q->human;
            }
            printf("Removed.");
            entry--;
            p = people;
            d = 0;
        }
        else
        {
            d++;
            p++;
        }
    }
    return;
}
int main()
{
    while(number != 0)
    {
        printf("\n");
        printf("Type \"1\" to add first name, last name, and age. \n");
        printf("Type \"2\" to show the list in alphabetical order. \n");
        printf("Type \"3\" to see what people have a specific age. \n");
        printf("Type \"4\" to remove a name. \n");
        printf("Type \"5\" to remove a name by using its age. \n");
        printf("Type \"0\" to quit \n");
        scanf("%s", &number);
        switch(number)
        {
        case '1':
            insert();
            break;

        case '2':
            list();
            break;

        case '3':
            list_age();
            break;

        case '4':
            remove1();
            break;

        case '5':
            remove_age();
            break;

        case '0':
            printf("Goodbye then! \n");
            return;
            break;

        default:
            printf("Not a valid option \n");
        }
    }
    return 0;
}
