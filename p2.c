/*---Name: Parikh Shivam---*/
/*---Class: CSI333---*/
/*---Lab: Wednesday 9:20 AM---*/
/*---Programming Assignment 2---*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 16 // define the size of the max length of a word
int vowel_count(char word[]);
int is_palindrome(char palCheck[]);

  

//////////Define all the required global variable here///////////

  int totalLength = 0;
  int tempLength = 0;
  
  int tempVowelCount = 0;
  int vowelCount = 0;
  int avgVowel = 0;
  
  int maxVowelWord = 0;
  
  int avgLength = 0;
  int numWord = 0;

  int maxLengthWordCount = 0;

  int length10 = 0;
  int length11 = 0;
  int length12 = 0;
  int length13 = 0;
  int length14 = 0;
  int length15 = 0;
  
  int numPalindrome = 0;
  int truefalsePalindrome = 0;
  
  int count = 0;
  
  int x = 0;
  int y = 0;
  int z;
  
  int yesCheck = 0;
  int noCheck = 0;
  
  char copy1[SIZE];
  


/////////////////////////// Main method starts //////////////////////
  
int main(void) {
  
    char word[SIZE]; // Char array will be created of size 16

    printf("Enter your word(s): \n");
    fflush(stdout);
    
    /*
    While loop will take each word and does the calculation for length, vowels, and other required stats
    loop must read the words until it gets EOF
    
    */
    
    while(scanf("%s", word)==1){
    
    
    numWord++; // If the while loop continues then there is a word
    
    tempLength = strlen(word); // store the length of the word
    
    // if-else statement to check the size limit of the word entered
    // print out 10 >= i <=15, for each i.  
    
      
      if(tempLength == 10){
        length10++;
      }
      else if(tempLength == 11){
        length11++;
      }
      else if(tempLength == 12){
        length12++;
      }
      else if(tempLength == 13){
        length13++;
      }
      else if(tempLength == 14){
        length14++;
      }
      else if(tempLength == 15){
        length15++;
      }
    
    
    // vowelCount will be incremented by the number of vowels returned by the method
    vowelCount += vowel_count(word);
    
    // palindrome
    
    
    // if the palindrome method returns 1 then increment numPalindromw which keeps track of number of words that are palindrome
    
    if(is_palindrome(word) == 1){
    numPalindrome++;
    }
    else{
    }
    
    
    // if the word had more than 2 vowels then increment the number of words that has 3 or more vowels
    if(vowel_count(word) > 2){
    maxVowelWord++;
    }
    else{}
    
    
    // check for the punctuation
    // if there is a punctuation at the end of the word, then length will be decremented
    // if there no punctuation, then length will not change
    // and reset the tempLength to use it for next word
    
    if(ispunct(word[tempLength-1])){
    tempLength--;
    totalLength += tempLength;
    tempLength = 0;
    }
    else{
    totalLength += tempLength;
    tempLength = 0;
    }
    
    }
    // While Loop ends
    
    
    
    
   
   
    avgLength = totalLength/numWord; // Calculate average Length per word
    
    avgVowel = vowelCount/numWord; // Calculate average Vowels per word
  
    
    /////////// print out all required stats - Followed by fflush(stdout) ///////////////
    
    printf("Average Length: %d\n", avgLength);
    
    fflush(stdout);
        
    printf("Average Vowel: %d\n", avgVowel);
    
    fflush(stdout);

    printf("Words that contain at least three vowels: %d\n", maxVowelWord);
  
    fflush(stdout);
    
    printf("Number of Words Palindrome: %d\n", numPalindrome);
    
    fflush(stdout);
  
    printf("The number of words of length 10: %d\n", length10);
  
  fflush(stdout);
  
    printf("The number of words of length 11: %d\n", length11);
  
  fflush(stdout);
  
    printf("The number of words of length 12: %d\n", length12);
  
  fflush(stdout);
  
    printf("The number of words of length 13: %d\n", length13);
  
  fflush(stdout);
  
    printf("The number of words of length 14: %d\n", length14);
  
  fflush(stdout);
    
    printf("The number of words of length 15: %d\n", length15);
  
    fflush(stdout);
  
  
  
return 0;
}

   /////////////////////// Main method ends /////////////////////




    /////////////////////// vowel_count method starts //////////////////////
    
    int vowel_count(char word[]){
    int i;
    
    tempVowelCount = 0;
    
    // for loop will loop through the array and counts how many vowels there are in that word and returns number of vowels
    // This also needs to check for lower case or upper case vowel count
    
    for(i = 0; i < tempLength; i++){
    
    if(word[i] == 'a' || word[i] == 'A' || word[i] == 'e' || word[i] == 'E' || word[i] == 'i' || word[i] == 'I' || word[i] == 'o' || word[i] == 'O' || word[i] == 'u' || word[i] == 'U'){
    tempVowelCount++;
    }
    else{}
    }
    
    i = 0;
    
    return tempVowelCount;  
    }
    
    ///////////////// vowel count method ends and returns number of vowels in the word //////////////////
    
    




    ////////////////// is_palindrome starts //////////////////
    
    // this method will determine if the word has punctuation at the end or not
    // if there is then copies that into different word and will make a copy of that word backward
    // to compare it with original word
    
   
     int is_palindrome(char palCheck[]){
     
     char compare1[SIZE];
       
    x = 0;
    y = 0;
    
       
       // make first character lower case
       
      palCheck[0] = tolower(palCheck[0]); // make first letter lower case
    
    
       
       // if statement to check if the there is a punctuation at the end.
       // if there is then it will copy the word backword into compare1 withouy punctuation
       
    
       if(ispunct(palCheck[strlen(palCheck)-1])){
         
         //change the puctuation with \0.
         palCheck[strlen(palCheck)-1] = '\0'; 
         
         // for loop will copy the input word backword without punctuation
          for(x = (strlen(palCheck)-1), y = 0; x<1, y<strlen(palCheck); x--, y++){
           compare1[y] = palCheck[x];
           compare1[y+1] = '\0'; // this will put the word end notation at the last element of the array
          }
         }
       
       else{
         // we don't need to change puctuation, because there is none
         // for loop will copy the word backword.
         
          for(x = (strlen(palCheck)-1), y = 0; x<1, y<strlen(palCheck); x--, y++){
           compare1[y] = palCheck[x];
           compare1[y+1] = '\0'; // this will put the word end notation at the last element of the array
    }
       }
       
       
     
       
    
    // compare both words, if similar then return 1 or return 0
    
    if(strcmp(palCheck, compare1) == 0){
    return 1;
    }
    else{
    return 0;
    }
    
    
    
    }
    
////////////////// is_palindrome ends //////////////////


    
        
        