#include<stdio.h> 
#include<string.h>

int main(){ 

   //FILE
   FILE *fp;
   char *sub[] = {"C Programming Tutorial\n", "C++ Tutorial\n", "Python Tutorial\n", "Java Tutorial\n"};
   fp = fopen("file2.txt", "w");

   for (int i = 0; i < 4; i++) {
      fputs(sub[i], fp);
   }

   fclose(fp);

   FILE *file;
   char *string;
   fp = fopen ("file2.txt", "r");
   printf("open file for reading \n");

   while (!feof(fp)) {
      fgets(string, 256, fp);
      printf ("%s", string) ;
   }
   fclose (fp);
     
return 0;
}