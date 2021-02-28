#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NUM_LETTERS 26

static int REVERSED = 0;

typedef struct node
{
    int isWord;
    char letter;
    long unsigned int count;
    int numKids;
    struct node *children[NUM_LETTERS];
} node;
int findPlace_AtoZ(int length, node *head[], char *new_letter);
int findPlace_ZtoA(int length, node *head[], char *new_letter);
void addNode(char s[], node *curr);
void printInorder(node *head, char s[], int len);
void printInorder_r(node *head, char s[], int len);
void shift_element(node *arr[], int i, int last);
int main(int argc, char *argv[])
{
    REVERSED = 0;
    if (argc == 2 && *(argv[1]) == 'r')
    {
        REVERSED = 1;
    }
    // printf("REVERESED IS %d", REVERSED);
    node *head[NUM_LETTERS];
    int length = 0;

    int size=512;
    int counter=0;
    char *s;
    s=(char*)calloc(size,size*sizeof(char));
    if(s==NULL)
    {
        exit(1);
    }
    char tmp;
    // printf("enter text:");
    while(scanf("%c",&tmp)!=EOF)
    {
        // if(tmp==NULL)break;
        tmp=tolower(tmp);
        if(!isalpha(tmp)&&tmp!=' '&&tmp!='\t'&&tmp!='\n')continue;
        if(counter==size)
        {
            size*=2;
            s=(char*)realloc(s,size*sizeof(char));
            if(s==NULL)
            {
                exit(1);
            }
        }
        s[counter]=tmp;
        counter++;
    }
    // printf("my text is: %s\n",s);
    char delim [] = "\t \n";

    char *word = strtok(s, delim);
    while (word != NULL)
    {
        // printf("STARTED: %s\n", word);

        int flag = 1;
        for (int i = 0; i < length; i++)
        {
            // printf("FOR MAIN: s = %s, i =%d\n", word, i);
            node *curr = head[i];
            if (*(word) == curr->letter)
            {
                // printf("FOR MAIN: found match for first letter of %s \n", word);
                // printf("The match for %s is %c \n", word, curr->letter);
                addNode(word + 1, curr);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            node *newNode = (node *)calloc(1,sizeof(node));
            if (newNode == NULL)
            {
                exit(1);
            }
            newNode->letter = *word;
            // printf("FLAG MAIN: Added node to head for s=%s\n", word);
            addNode(word + 1, newNode);
            int i;
            if (REVERSED)
            {
                i = findPlace_ZtoA(length, head, word);
            }
            else
            {
                i = findPlace_AtoZ(length, head, word);
            }
            shift_element(head, i, length);
            head[i] = newNode;
            length++;
        }
        word = strtok(NULL, delim);
    }
    free(s);
    for (int i = 0; i < length; i++)
    {
        char let[2];
        let[0] = head[i]->letter;
        let[1] = 0;
        if(REVERSED)
        {
            printInorder_r(head[i], let, 2);
        }
        else
        {
           printInorder(head[i], let, 2);
        }
    }

    return 0;
}

int findPlace_AtoZ(int length, node *head[], char *new_letter)
{
    int i = 0;
    while (i < length && head[i]->letter < *new_letter)
    {
        i++;
    }
    return i;
}

int findPlace_ZtoA(int length, node *head[], char *new_letter)
{
    int i = 0;
    while (i < length && head[i]->letter >= *new_letter)
    {
        i++;
    }
    return i;
}
void shift_element(node *arr[], int i, int last)
{
    for (int j = last; j >= i; j--)
    {
        arr[j + 1] = arr[j];
    }
}

void addNode(char s[], node *curr)
{
    // printf("addNode: s =  %s, curr = %c, num kids = %d\n", s, curr->letter, curr->numKids);
    if (!s[0])
    {
        curr->isWord = 1;
        curr->count++;
        // printf("addNode: Equal Word ending with %c , count = %ld\n", curr->letter, curr->count);
    }
    else
    {
        int flag = 1;
        for (int i = 0; i < curr->numKids; i++)
        {
            node *let = curr->children[i];
            // printf("FOR addNode: s = %s, s[0] = %c, i =%d\n", s, s[0], i);
            // printf("FOR addNode: children[i] =%c\n", let->letter);
            if (s[0] == let->letter)
            {
                // printf("FOR addNode: found match for first letter of %s \n", s);
                // printf("The match for %s is %c \n", s, let->letter);
                addNode(s + 1, let);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            node *newNode = (node *)calloc(1,sizeof(node));
            if (newNode == NULL)
            {
                exit(1);
            }
            newNode->letter = s[0];
            // printf("FLAG addNode: Added node to head for s=%s\n", s);
            addNode(s + 1, newNode);
            int i;
            if (REVERSED)
            {
                i = findPlace_ZtoA(curr->numKids, curr->children, s);
            }
            else
            {
                i = findPlace_AtoZ(curr->numKids, curr->children, s);
            }
            shift_element(curr->children, i, curr->numKids);
            curr->children[i] = newNode;
            curr->numKids++;
            // printf("FLAG addNode: Curr is %c,  node[numkids] = %c\n", curr->letter, curr->children[curr->numKids - 1]->letter);
        }
    }
}
void printInorder_r(node *head, char s[], int len)
{
    int i = 0;
    while (i < head->numKids)
    {
        char s_new[len + 2];
        strcpy(s_new, s);
        char let[2];
        let[0] = head->children[i]->letter;
        let[1] = 0;
        strcat(s_new, let);
        printInorder_r(head->children[i], s_new, len + 2);
        i++;
    }
    if (head->isWord)
    {
        printf("%s %ld\n", s, head->count);
    }
    free(head);
}

void printInorder(node *head, char s[], int len)
{
        if (head->isWord)
    {
        printf("%s %ld\n", s, head->count);
    }

    int i = 0;
    while (i < head->numKids)
    {
        char s_new[len + 2];
        strcpy(s_new, s);
        char let[2];
        let[0] = head->children[i]->letter;
        let[1] = 0;
        strcat(s_new, let);
        printInorder(head->children[i], s_new, len + 2);
        i++;
    }
    free(head);
}