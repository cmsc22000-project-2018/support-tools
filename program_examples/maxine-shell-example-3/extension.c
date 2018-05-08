#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int abc()
{
  printf("a b c d e f g h i j k l m n o p q r s t u v w x y z\n");
  return 1;
}

int letter(char **args)
{
  if (args[0] == NULL){
    fprintf(stderr, "lsh: expected argument to \"letter\"\n");
  }
  else{
    int num = atoi(args[0]) + 64;
    if ((num > 90)||(num < 1)){
      printf("\"letter\" only acceptes values between 1 and 26\n");
    }
    else{
       printf("%c\n",(char)num);
    }
  }
  return 1;
}

int eviz(char **args)
{
  int ex;
  if (args[0] == NULL)
    ex = 0;
  else
     ex = atoi(args[0]);
  switch (ex){
    case 1: printf("a\na-p\na-p-e\na-p-p\na-p-p-l\na-p-p-l-e\na-p-p-l-e-s\n");
       break;
     default: printf("b\nb-e\nb-e-t\nb-e-t-s\nb-e-t-t\nb-e-t-t-e\nb-e-t-t-e-r\nb-e-t-t-e-r-s\n");
  }  
  return 1;
}

int lviz(char **args){
  int ex;
  if (args[0] == NULL)
    ex = 0;
  else
     ex = atoi(args[0]);
  switch (ex){
    case 1: printf("a-p-e\na-p-p-l-e-s\n");
       break;
     default: printf("b-e-t-t-e-r-e-d\nb-e-t-t-e-r-m-e-n-t\nb-e-t-t-e-r-s\n");
  }  
  return 1;
}

int wviz(char **args){
  int ex;
  if (args[0] == NULL)
    ex = 0;
  else
     ex = atoi(args[0]);
  switch (ex){
    case 1: printf("a-p-e\na-p-p-l-e\na-p-p-l-e-s\n");
       break;
     default: printf("b-e-t\nb-e-t-s\nb-e-t-t-e-r\nb-e-t-t-e-r-s\nb-e-t-t-e-r-m-e-n-t\n");
  }  
  return 1;
}

int sviz(char **args){
  int ex;
  if (args[0] == NULL)
    ex = 0;
  else
     ex = atoi(args[0]);
  switch (ex){
    case 1: printf("Input was: a-p\na-p\na-p-e\na-p-p\na-p-p-l\na-p-p-l-e\na-p-p-l-e-s\n");
       break;
     default: printf("Input was: b-e-t-t\nb-e-t-t\nb-e-t-t-e\nb-e-t-t-e-r\nb-e-t-t-e-r-m\nb-e-t-t-e-r-m-e\nb-e-t-t-e-r-m-e-n\nb-e-t-t-e-r-m-e-n-t\nb-e-t-t-e-r-s\n");
  }  
  return 1;
}
