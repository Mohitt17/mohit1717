#include<stdio.h> 

        //user defined function for Q7  to concatenate two strings
        void strconcat(char str1[], char str2[]) {
            int i = 0, j = 0;
        
            while (str1[i] != '\0') {
                i++;
            }
        
            while (str2[j] != '\0') {
                str1[i] = str2[j];
                i++;
                j++;
            }
        
            str1[i] = '\0';// to end of string
        }
        //user defined function for Q8  to Count Frequency
          void count_freq(char str[]) {
            int freq[256] = {0};  
            int i;
            char ch;
        
            // Count each character (case-insensitive)
            for (i = 0; str[i] != '\0'; i++) {
                ch = str[i];
        
                // Convert uppercase to lowercase manually
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch + 32;  // A→a, B→b, etc.
                }
        
                freq[(unsigned char)ch]++;  // increment count of this character
            }
        
            // Print only letters (a–z)
            printf("\nCharacter frequencies:\n");
            for (i = 'a'; i <= 'z'; i++) {
                if (freq[i] > 0) {
                    printf("%c = %d\n", i, freq[i]);
                }
            }
        }
        
        //Q9 user-defined function to find and print the longest word
        void find_longest_word(char str[]) {
            int i = 0, start = 0, end = 0;
            int maxLength = 0, currLength = 0, maxStart = 0;
        
            while (str[i] != '\0') {
                if (str[i] != ' ' && str[i] != '\n') {
                    currLength++;
                } else {
                    if (currLength > maxLength) {
                        maxLength = currLength;
                        maxStart = i - currLength;
                    }
                    currLength = 0;
                }
                i++;
            }
        
            // check for last word (if sentence doesn't end with space)
            if (currLength > maxLength) {
                maxLength = currLength;
                maxStart = i - currLength;
            }
        
            printf("Longest word: ");
            for (i = 0; i < maxLength; i++) {
                printf("%c", str[maxStart + i]);
            }
            printf("\n");
        }
        
int main()
{

//1 Count Vowels and Consonants
    char arr1[100];
    int vowels = 0, consonants = 0;
    int i;
    printf("Enter a string: ");
    fgets(arr1, sizeof(arr1), stdin);  

    
    for (i = 0; arr1[i] != '\0'; i++) {
         if (arr1[i] >= 'A' && arr1[i] <= 'Z')
          {
            arr1[i] = arr1[i] + 32;   
          } 

        if (arr1[i] >= 'a' && arr1[i] <= 'z') {  
            if (arr1[i] == 'a' || arr1[i] == 'e' || arr1[i] == 'i' || arr1[i] == 'o' || arr1[i] == 'u')
                vowels++;         
            else
                consonants++;     
    }}

    
    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);

//2   Reverse a character array
    
     int length = 0;
     char arr2[100];
    
     printf("Enter a word: ");
     fgets(arr2, sizeof(arr2), stdin);

      while (arr2[length] != '\0') {
        length++;
    }

    
    printf("Reversed word: ");
     for (i = length - 1; i >= 0; i--) {
         printf("%c", arr2[i]);
    }
 
    printf("\n");

//3 Check Palindrome String

    char arr3[100];
    
    length = 0;
    int isPalindrome = 1;

    printf("Enter a word: ");
    scanf("%99s", arr3);   

    
    while (arr3[length] != '\0') length++;

    
    for (int i = 0; i < length / 2; i++) {
        if (arr3[i] != arr3[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("The word is a palindrome.\n");
    else
        printf("The word is not a palindrome.\n");

//4 Count Words in a character array 
   char arr4[200];
   int count = 0;

    printf("Enter a sentence: ");
    fgets(arr4, sizeof(arr4), stdin);  

    
    for (int i = 0; arr4[i] != '\0'; i++) {
       // for space ,line change, double space 
        if (arr4[i] == ' ' && arr4[i + 1] != ' ' && arr4[i + 1] != '\0' && arr4[i + 1] != '\n') {
            count++;
        }
    }
     //for last word
    if (arr4[0] != '\n' && arr4[0] != '\0' && arr4[0] != ' ')
        count++;

    printf("Word Count = %d\n", count);

//5 Convert to Uppercase and Lowercase
  
    char arr5[100];
    char lower[100];
    char upper[100];

    printf("Enter a word: ");
    scanf("%99s", arr5);  
    for (i = 0; arr5[i] != '\0'; i++) {
    
        if (arr5[i] >= 'A' && arr5[i] <= 'Z') {
            lower[i] = arr5[i] + 32;   
            upper[i] = arr5[i];       
        }

        else if (arr5[i] >= 'a' && arr5[i] <= 'z') {
            upper[i] = arr5[i] - 32;  
            lower[i] = arr5[i];       
        }

        else {
            upper[i] = arr5[i];
            lower[i] = arr5[i];
        }
    }

    lower[i] = '\0';
    upper[i] = '\0';

    
    printf("Lowercase: %s\n", lower);
    printf("Uppercase: %s\n", upper);

//6 Sort Names Alphabetically
//7 Concatenate Two character arrays (without strcat)

    char str1[100], str2[100];

    
    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // function to join them
    strconcat(str1, str2);

    
    printf("Concatenated String: %s\n", str1);

//8 Count Frequency of Each Character

  char arr8[100];

    printf("Enter a word: ");
    scanf("%s", arr8);   

    count_freq(arr8);

//9 Find the Longest Word
   char arr9[200];

    printf("Enter a sentence: ");
    fgets(arr9, sizeof(arr9), stdin);  // read string including spaces

    find_longest_word(arr9);
    
    

//10  Anagram Checker (Two character arrays)
//11  Menu Based Text Application

    return 0;
}