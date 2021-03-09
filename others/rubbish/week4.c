#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
//#define ss [ 1, 2, 'c', '1', [ 2, 'b' ], " asd " ]
typedef enum
{
    xulie = 100,
    charr = 1,
    strings = 10,
    intt = 4,
    doublee = 8,
    voidd = 40
} en;
typedef struct node
{
    struct node *next;
    /*union
    {
        char c;
        int i;
        char *s;
        double d;
        struct node *n;
    } un;
    */
    void *d;
    en ty;
} no;
no *addall(no **head, no *data)
{
    //no *data = *da;
    no *p = (no *)malloc(sizeof(no));
    no *temp = *head;
    if (*head == NULL)
    {
        *head = p;
        temp = *head;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    //
    if (data->ty == 0)
    {
        p->next = data->next; //
        no *frist = NULL;
        addall(frist, (no *)(data->d));
        temp->next = frist;
        while (frist->next != NULL)
            frist = frist->next;
        frist->next = p->next;
        free(p);
    }
    else
    {
        p->ty = data->ty;
        p->d = data->d;
        p->next = data->next;
    }
}
void see(no *he)
{
    no *head = he;
    while (head != NULL && head->d != NULL)
    {
        switch (head->ty)
        {
        case 4:
            printf("%d ", *(int *)(head->d));
            break;
        case 1:
            printf("%c ", *(char *)(head->d));
            break;
        case 40:

            see(head->d);
            break;
        }

        head = head->next;
    }
}
void *to(const char *s)
{ //[1,23,'c',[3,"wds"],'0']
    char fu[LEN];
    char yin[LEN];
    static int ii[LEN] = {0};
    no *temp = (no *)malloc(sizeof(no));
    no *head = temp;
    temp->d = NULL;
    temp->next = NULL;
    no *prev = head;
    en st[LEN];
    int j = 0, sm = 0, yi = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '[')
        {
            fu[j++] = s[i];
            st[sm++] = 100;
            continue;
        }

        else if (s[i] >= '0' && s[i] <= '9' && st[sm - 1] == 100)
        { //int

            //char

            prev = temp;
            temp = (no *)malloc(sizeof(no));
            temp->next = NULL;
            prev->next = temp;
            int len = 1;
            while (s[i + len] >= '0' && s[i + len] <= '9')
            {
                len++;
            }

            ii[i] = atoi(s[i]);
            printf("%d", ii[i]);
            exit(1);
            prev->d = &ii[i];
            prev->ty = 4;
        }
        /*else if (s[i] == '"')
        {
            if (yi != 0 || yin[yi - 1] == '"') //you
            {
                yi--;
                
            }
            else
            {
                yin[yi++] = '"';
                st[sm++] = 10;
                
                prev = temp;
                temp = (no *)malloc(sizeof(no));
                prev->next = temp;
                prev->d = strchr(&s[i+1]);
                prev->ty = 1;
            }
        }*/
        /*
        else if (s[i] ==)
        {
            if (yi != 0 || yin[yi - 1] == '"') //you
            {
                yi--;
            }
            else
            {
                yin[yi++] = '"';
                st[sm++] = 10;

                prev = temp;
                temp = (no *)malloc(sizeof(no));
                prev->next = temp;
                prev->d = strchr(&s[i + 1]);
                prev->ty = 1;
            }
        }*/
        else if (s[i] == ',')
        {
            continue;
        }
        else if (s[i] == '\'')
        {
            if (i - 2 > -1 && s[i - 2] == '\'' && st[sm - 1] == 1)
            {
                //char
                sm--;
                prev = temp;
                temp = temp->next;
                temp = (no *)malloc(sizeof(no));
                temp->next = NULL;
                prev->next = temp;

                prev->d = &s[i - 1];
                prev->ty = 1;
            }
            else
            {
                st[sm++] = 1;
            }
        }
        else if (s[i] == ']')
        {
            if (fu[j - 1] == '[')
            {
                sm -= 2;
            }
        }
    }
    free(temp);
    prev->next = NULL;
    //printf("%s\n", s);
    return head;
}
void del(no *head)
{
    no *temp = NULL;
    while (head)
    {
        temp = head;

        head = head->next;
        free(temp);
    }
}
int main(void)
{
    char s[LEN];
    scanf("%s", s);
    //[1,23,'c',[3,'s'],'0']
    //printf("%s", s);
    no *test = to(s);
    int da = 1;
    char ch = 'c';
    no list1[2][3] = {
        {{&list1[0][1], &da, 4},
         {&list1[1][0], &ch, 1},
         {NULL, &da, 4}},
        {{&list1[1][1], &list1[0][2], 0},
         {&list1[0][2], &ch, 1},
         {}}};
    no *head = NULL;

    //addall(&head, &list1[0][0]);
    //1 c [1] c 1
    //see(head);
    //  printf("\n");
    //free(head);
    // addall(&test, &test);
    see(test);
    printf("\n");
    del(test);
    return 0;
}
