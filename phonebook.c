#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
  char name[11];
  char num[11];
  int id;
};
int refid = 1;
int count = 0;
int size = 20;
typedef struct contact CAT;

CAT read(CAT *);
void display(CAT *);
void insertfront(CAT *);
void insertrear(CAT *);
void insertbynameorder(CAT *);
void deletefront(CAT *);
void deleterear(CAT *);
void searchbyid(CAT *);
void searchbynumber(CAT *);
void searchbyname(CAT *);
void readbyfile(CAT *);
void writetofile(CAT *);
void addtodatabase(CAT *);
void readfromdatabase(CAT *);
void deletebyname(CAT *);
void deletebynumber(CAT *);

void main()
{
  system("cls");
  CAT s[10];
  int ch;
  printf("\t\t*******************************************************************************************************\t\t\n");
  printf("\n\t\t\t\t\t\tWELCOME TO PHONE BOOK\n\n");
  printf("\t\t*******************************************************************************************************\t\t\n");
  printf("\n\t\t\t\t\t\tTHE PROJECT IS DEVELOPED BY\n");
  printf("\n\t\t\t\t\t\t> ABHISHEK M B\n\n");
  printf("\n\t\t\t\t\t\t> ANURAG G\n\n");
  printf("\t\t*******************************************************************************************************\t\t\n");
l1:
  printf("ENTER 1 TO CREATE NEW PHONE BOOK AND 2 TO GET OLD PHONE BOOK\n");
  scanf("%d", &ch);
  if (ch == 1 || ch == 2)
  {
    if (ch == 2)
      readfromdatabase(s);
  }
  else
  {

    printf("ENTER THE VALID CHOICE\n");
    goto l1;
  }

  for (;;)
  {
    printf("ENTER THE CHOICE\n\n1.INSERT FRONT\n2.INSERT REAR\n3.INSERT BY ORDER OF NAME\n4.DELETE FRONT\n");
    printf("5.DELETE REAR\n6.DELeTE BY NAME\n7.DELETE BY NUMBER\n8.SEARCH BY ID\n9.SEARCH BY NAME\n10.SEARCH BY NUMBER\n");
    printf("11.TO READ FROM FILE\n12.DISPLAY\n");
    printf("0.TOEXIT\n");
    scanf("%d", &ch);
    switch (ch)
    {

    case 1:
      insertfront(s);
      addtodatabase(s);
      break;
    case 2:
      insertrear(s);
      addtodatabase(s);
      break;
    case 3:
      insertbynameorder(s);
      addtodatabase(s);
      break;
    case 4:
      deletefront(s);
      addtodatabase(s);
      break;
    case 5:
      deleterear(s);
      addtodatabase(s);
      break;
    case 6:
      deletebyname(s);
      addtodatabase(s);
      break;
    case 7:
      deletebynumber(s);
      addtodatabase(s);
      break;
    case 12:
      display(s);
      break;
    case 8:
      searchbyid(s);
      break;
    case 9:
      searchbyname(s);
      break;
    case 10:
      searchbynumber(s);
      break;
    case 11:
      readfromdatabase(s);
      break;
    default:
      printf("PLEASE ENTER THE CORRECT ORDER");
      break;
    case 0:
      printf("THE PROGRAM GOT TERMINATED\n");
      exit(0);
    }
  }
}

void deletebyname(CAT *c)
{
  if (count == 0)
  {
    printf("THE LIST IS EMPTY\n");
    return;
  }
  char name[20];
  int flag=0, i;
  printf("ENTER THE NAME\n");
  scanf("%s", name);

  for (i = 0; i < count; i++)
  {
    if (strcmp((c + i)->name, name) == 0)
    {
      flag = 1;
      break;
    }
  }
  if(flag!=1)
    printf("THE CONTACT NOT FOUND\n");
   else
  {
    printf("THE THR CONTACT IS FOUND THE DETAILS OF CONTACTS ARE\n");
    printf("NAME     \tNUMBER     \tID\n");
    printf("%s\t%s\t%d\n", (c + i)->name, (c + i)->num, (c + i)->id);
    int k;
    for (k = i;k < count - 1; k++)
  {
    strcpy((c + k)->name, (c + k + 1)->name);
    strcpy((c + k)->num, (c + k + 1)->num);
    (c + k)->id = (c + k + 1)->id;
  }
  count--;
}
}

void deletebynumber(CAT *c)
{
  if (count == 0)
  {
    printf("THE LIST IS EMPTY\n");
    return;
  }

  char num[11];
  int flag=0,i;
  printf("ENTER THE NUMBER\n");
  scanf("%s", num);

  for (i = 0; i < count; i++)
  {
    if (strcmp((c + i)->num, num) == 0)
    {
      flag = 1;
      break;
    }
  }
  if(flag!=1)
  printf("THE CONTACT NOT FOUND\n");
  else
  {
    printf("THE CONTACT IS FOUND. THE DETAILS OF CONTACTS ARE\n");
    printf("NAME     \tNUMBER     \tID\n");
    printf("%8s\t%s\t%d\n", (c + i)->name, (c + i)->num, (c + i)->id);

  int k;
  for (k = i; k < count - 1; k++)
  {
    strcpy((c + k)->name, (c + k + 1)->name);
    strcpy((c + k)->num, (c + k + 1)->num);
    (c + k)->id = (c + k + 1)->id;
  }
  count--;
}

}
void addtodatabase(CAT *c)
{
  FILE *f = fopen("DATABASE.txt", "w");
  int i;
  fprintf(f, "%d\n", count);
  for (i = 0; i < count; i++)
  {
    fprintf(f, "%s %s %d\n", (c + i)->name, (c + i)->num, (c + i)->id);
  }

  fclose(f);
}

void readfromdatabase(CAT *c1)
{
  int i;
  FILE *f = fopen("DATABASE.txt", "r");
  if (f == NULL)
  {
    printf("ERROR : COULD NOT OPEN DATABASE FILE\n");
  }
  rewind(f);
  fscanf(f, "%d", &count);

  for (i = 0; i < count; i++)
  {
    fscanf(f, "%s %s %d", &(c1 + i)->name, &(c1 + i)->num, &(c1 + i)->id);
  }
  printf("DATA RETIREVED SUCCESFFULY\n");

  fclose(f);
}

CAT read(CAT *c)
{
  CAT temp;
  if (size == count)
  {
    printf("THE ARRAY IS full\n");
    exit(0);
  }
  printf("ENTER THE NAME \n");
  scanf("%s", temp.name);
L1:
  printf("ENTER THE NUMBER \n");
  scanf("%s", temp.num);
  for (int i = 0; i < count; i++)
  {
    if (strcmp((c + i)->num, temp.num) == 0)
    {
      printf("CONTACT WITH SAME NUMBER FOUND\n");
      printf("CONTACT NAME: %s\n", (c + i)->name);
      printf("PLEASE ENTER A DIFFERENT NUMBER\n");
      goto L1;
    }
  }
  printf("THE ID IS : %d \n", refid);
  temp.id = refid++;
  return (temp);
}

void display(CAT *c)
{
  int i;
  if (count == 0)
  {
    printf("THE LIST IS EMPTY\n");
    return;
  }

  printf("\nTHE CONTACTS ARE\n\n");
  printf("\tNAME\t\t\tNUMBER\t\t\tID\n");

  for (i = 0; i < count; i++)
    printf("%10s\t\t\t%s\t\t%d\n", (c + i)->name, (c + i)->num, (c + i)->id);
  printf("\n");
  printf("\t\t\tPress any key to continue...");
  system("pause");
}

void insertfront(CAT *c)
{
  if (size == count)
  {
    printf("THE ARRAY IS full\n");
    return;
  }
  CAT f = read(c);
  int i;

  if (count != 0)
  {
    for (i = count - 1; i >= 0; i--)
    {
      strcpy((c + i + 1)->name, (c + i)->name);
      strcpy((c + i + 1)->num, (c + i)->num);
      (c + i + 1)->id = (c + i)->id;
    }
  }

  strcpy(c->num, f.num);
  strcpy(c->name, f.name);
  c->id = f.id;
  count++;
}

void insertrear(CAT *c)
{
  if (size == count)
  {
    printf("THE ARRAY IS full\n");
    return;
  }

  CAT f = read(c);
  strcpy((c + count)->name, f.name);
  strcpy((c + count)->num, f.num);
  (c + count)->id = f.id;
  count++;
}

void deleterear(CAT *c)
{
  if (count == 0)
    printf("THE LIST IS EMPTY\n");

  printf("THE CONTACT DELETED IS \n");
  printf("THE NAME %s\n", (c + count - 1)->name);
  printf("THE NUMBER %s\n", (c + count - 1)->num);
  printf("THE ID IS : %d \n", (c + count - 1)->id);
  count--;
}

void deletefront(CAT *c)
{
  if (count == 0)
  {
    printf("THE LIST IS EMPTY\n");
    return;
  }
  printf("THE CONTACT DELETED IS \n");
  printf("THE NAME %s\n", c->name);
  printf("THE NUMBER %s\n", c->num);
  printf("THE ID IS : %d \n", c->id);

  int i;
  for (i = 0; i < count - 1; i++)
  {
    strcpy((c + i)->name, (c + i + 1)->name);
    strcpy((c + i)->num, (c + i + 1)->num);
    (c + i)->id = (c + i + 1)->id;
  }
  count--;
}

void searchbyid(CAT *c)
{
  if (count == 0)
  {
    printf("THE LIST IS EMPTY\n");
    return;
  }

  int keyid, flag, i;
  printf("ENTER THE KEY ID\n");
  scanf("%d", &keyid);

  for (i = 0; i < count; i++)
  {
    if (keyid == (c + i)->id)
    {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
  {
    printf("THE DETAILS OF THE CONTACT ARE\n");
    printf("NAME:  %s\n", (c + i)->name);
    printf("NUMBER: %s\n", (c + i)->num);
    printf("ID: %d \n", (c + i)->id);
  }
  else
    printf("ID NOT FOUND\n");
  printf("\t\t\tPress any key to continue...");
  system("pause");
}

void searchbyname(CAT *c)
{
  if (count == 0)
  {
    printf("THE LIST IS EMPTY\n");
    return;
  }

  char name[10];
  int flag, i;
  printf("ENTER THE  NAME\n");
  scanf("%s", name);

  for (i = 0; i < count; i++)
  {
    if (strcmp((c + i)->name, name) == 0)
    {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
  {
    printf("THE DETAILS OF THE CONTACT ARE\n");
    printf("NAME:  %s\n", (c + i)->name);
    printf("NUMBER: %s\n", (c + i)->num);
    printf("ID: %d \n", (c + i)->id);
  }
  else
    printf("NAME NOT FOUND\n");
  printf("\t\t\tPress any key to continue...");
  system("pause");
}

void searchbynumber(CAT *c)
{
  if (count == 0)
  {
    printf("THE LIST IS EMPTY\n");
    return;
  }

  char num[11];
  int flag, i;
  printf("ENTER THE NUMBER\n");
  scanf("%s", num);

  for (i = 0; i < count; i++)
  {
    if (strcmp((c + i)->num, num) == 0)
    {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
  {
    printf("THE DETAILS OF THE CONTACT ARE\n");
    printf("NAME:  %s\n", (c + i)->name);
    printf("NUMBER: %s\n", (c + i)->num);
    printf("ID: %d \n", (c + i)->id);
  }
  else
    printf("NUMBER NOT FOUND\n");
  printf("\t\t\tPress any key to continue...");
  system("pause");
}

void insertbynameorder(CAT *c)
{
  if (size == count)
  {
    printf("THE ARRAY IS full\n");
    return;
  }
  CAT f = read(c);
  int i;

  for (i = count - 1; i >= 0; i--)
  {
    if (strcmp(f.name, (c + i)->name) < 0)
    {
      strcpy((c + i + 1)->num, (c + i)->num);
      strcpy((c + i + 1)->name, (c + i)->name);
      (c + i + 1)->id = (c + i)->id;
    }
    else
      break;
  }

  strcpy((c + i + 1)->num, f.num);
  strcpy((c + i + 1)->name, f.name);
  (c + i + 1)->id = f.id;
  count++;
}





