#include <stdio.h>
#include <string.h>

struct library
{
    char book[100];
    char atnm[100];
    char title[100];
};

int main()
{
    struct library b[100];
    char input, input2, book[100], author[100], title[100];
    int i, nm, pos;

    while (1)
    {
        printf("\n\n|%-40s |", "  ARYA COLLEGE OF Engineering  LIBRARY ");
        printf("\nEnter the character (Q to quit ...)\n  1. Add a book\n  2. Delete a Book\n  3. Find a Book\n  4. Update a Book / author / title\n  5. Show all books\n //Enter : ");
        scanf(" %c", &input);

        switch (input)
        {
        case 'Q':
            printf("Quitting the program.....");
            goto end;

        case '1':
            // Adding books in liberary
            printf("How many books you want to add: ");
            scanf("%d", &nm);
            // Note :  instead of %s.
            // The %[^\n]{scanset specifier} specifier reads a string until a newline character
            // is encountered, allowing spaces in the input.
            for (i = 0; i < nm; i++)
            {
                printf("\n%d Book name: ", i + 1);
                scanf(" %[^\n]", b[i].book);
                printf("%d Author name: ", i + 1);
                scanf(" %[^\n]", b[i].atnm);
                printf("%d Title name: ", i + 1);
                scanf(" %[^\n]", b[i].title);
                printf("\n\n"); // spaces between each book entry
            }
            printf(" \n\n%d BOOKS ADDED IN LIBERARY......", nm);
            printf("\n\n");
            break;

        case '2':
            // code to delete a book
            printf("enter Position of  book to delete: ");
            scanf("%d", &pos);
            for (i = pos - 1; i < nm - 1; i++)
            {
                strcpy(b[i].book, b[i + 1].book);
                strcpy(b[i].atnm, b[i + 1].atnm);
                strcpy(b[i].title, b[i + 1].title);
            }
            nm--;
            printf("\n\n  %d POSITION BOOK IS DELETED.... \n\n   ", pos);
            break;

        case '3':
            // code for finding a book
            printf("please enter which book to find: ");
            char m[100];                
            getchar();                  
            fgets(m, sizeof(m), stdin); 
            m[strcspn(m, "\n")] = '\0'; 
            for (i = 0; i < nm; i++)
            {
                if (strcmp(m, b[i].book) == 0)
                {
                    printf("Book is found!\n\n\n");
                    break;
                }
            }
            if (i == nm)
            {
                printf("Book not found!.\n\n\n");
            }
            break;

        case '4':
            // code for updating a book
            printf("which one you want to update \n a. update a book\n b. update an author name \n c. update a title name\n");
            scanf(" %c", &input2);

            switch (input2)
            {
            case 'a':
                printf("enter which book to find : ");
                scanf(" %[^\n]", &book);
                for (i = 0; i < nm; i++)
                {
                    if (strcmp(book, b[i].book) == 0)
                    {
                        printf("enter the new book name: ");
                        scanf(" %[^\n]", &b[i].book);
                        printf("Book updated successfully!\n\n\n");
                        break;
                    }
                }
                if (i == nm)
                {
                    printf("Book not found!\n\n\n");
                }
                break;

            case 'b':
                printf("enter which author to find : ");
                scanf(" %[^\n]", &author);
                for (i = 0; i < nm; i++)
                {
                    if (strcmp(author, b[i].atnm) == 0)
                    {
                        printf("enter the new Author name: ");
                        scanf(" %[^\n]", &b[i].atnm);
                        printf("Author name updated successfully!\n\n\n");
                        break;
                    }
                }
                if (i == nm)
                {
                    printf("Author name not found!\n\n\n");
                }
                break;

            case 'c':
                printf("enter which Title to find : ");
                scanf(" %[^\n]", &title);
                for (i = 0; i < nm; i++)
                {
                    if (strcmp(title, b[i].title) == 0)
                    {
                        printf("enter the new book name: ");
                        scanf(" %[^\n]", &b[i].title);
                        printf("title updated successfully!\n\n\n");
                        break;
                    }
                }
                if (i == nm)
                {
                    printf("title not found!\n\n\n");
                }
                break;

            default:
                printf("Invalid input!!. \n");
                break;
            }
            break;

        case '5':
            // Show a book
            printf("\n\n\n");
            printf("| %-30s | %-30s | %-30s |\n", "BOOK NAME", "AUTHOR NAME", "TITLE NAME");
            printf("|--------------------------------|--------------------------------|--------------------------------|\n");
            for (i = 0; i < nm; i++)
            {
                printf("| %-30s | %-30s | %-30s |\n", b[i].book, b[i].atnm, b[i].title);
            }
            printf("\n\n\n");
            break;

        default:
            printf("Invalid input!!. \n");
            break;
        }
    }

end:
    return 0;
}