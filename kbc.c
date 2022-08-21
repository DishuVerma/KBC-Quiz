#include <stdio.h>
#include <stdlib.h>

int c1 = 1; //lifeline 1 count
int c2 = 1; //lifeline 2 count
int score = 0; //variable to determine the prize money

char *q[16] = { //array of strings defined for questions

"Q1: which of the following is not a programming language?",
"Q2: which of the following is not an unary operator?",
"Q3: Who invented C Language?",
"Q4:C is a which level language? ",
"Q5:C is which type language?",
"Q6:C language was invented to develop which Operating System.?",
"Q7: What are the types of Constants in C Language.?",
"Q8: Find a integer constant.",
"Q9: Number of Keywords present in C Language are.?",
"Q10: Who is chancellor of Delhi technological university?",
"Q11: What is Scooby Doo's full name?",
"Q12: What is the name of bully Gian's sister?",
"Q13: What is the color of Dorami,Doreamon's sister?",
"Q14: Whom or what is Doreamon Scared of?",
"Q15: What is the color of Shinchan's dog Shiro?",
"Q16: What is the name of Ostwald dog?"

};

char *option[16][4] = { //array of options
{"Python", "JAVA", "Cobra", "KOTLIN"},
{"--", "++", "=", "!"},
{"Grahambel", "Dennis Ritchie", "Charles Babbage", "Steve Jobs"},
{"low level + high level", "High level", "low level", "none the above"},
{"Bit level language", "Object Oriented", "Procedural", "Functional"},
{"Android", "Unix", "Linux", "Ubuntu"},
{"Secondary Constants", "Primary Constants and Secondary Constants", "Basic Constants and Advanced Constants", "Primary Constants"},
{"'125'", "34", "1.34", " N.O.T"},
{"64", "32", "34", "62"},
{"Yogesh Singh", "Anil Baijal", "Sanjay Sharma", "Madhusudan Singh"},
{"Scooty Doo", "Scoobert Doo", "Scooshy Doo", "None of these"},
{"Artisia", "Hannah", "Jiako", "Gaini"},
{"Green", "Yellow", "Red", "Pink"},
{"Bat", "Suneo", "Rat", "Cat"},
{"Brown", "White", "Yellow", "Purle"},
{"Shishimaru", "tuffy", "Weenie", "Shiro"}

};

int key[16] = {3, 3, 2, 2, 3, 2, 2, 2, 3, 2, 2, 3, 2, 3, 2, 3}; //contains answer key to questions

int prize[15] = {1000, 5000, 10000, 20000, 40000, 80000, 160000, 320000, 640000, 1280000, 2500000, 5000000, 10000000, 30000000, 70000000}; //contains prizemoney to respective levels

void quit(int amount){ 
    //function to quit the game on answering incorrectly
        printf("\nSorry! You have chosen the wrong option");
        amount=score;
    do{
        if (amount == 0)
        amount = 0;
        else if (amount > 0 && amount < 10000)
        amount = 0;
        else if (amount >= 10000 && amount < 320000)
        amount = 10000;
        else if (amount >= 320000 && amount < 5000000)
        amount = 320000;
        else if (amount >= 5000000 && amount < 70000000)
        amount = 500000;
        else if (amount == 7000000)
        amount = 70000000;
        printf("\nCONGRATULATIONS!! You have won the cash prize of %d \n", amount);
        printf("\nGame end");
     }
      while (fgetc(stdin) != '\n');
exit(0);
}

void update_won(int y, int a){ 
    //function to update the prize money
     a =prize[y - 1];
     score=a;
     printf("\nYou answered correctly and you have won the amount of %d", a);
}

int question(int x, int amount){ 
    //function to print question
    printf("\nEnter the correct option for the following questions(1-4)");
    printf("\nEnter 5 for 50-50 Lifeline,6 for Flipping the question and 7 for quitting the game");
    printf("\n%s", q[x - 1]);
    printf("\nYour four options are-\n1)%s \n2)%s \n3)%s \n4)%s \n", option[x - 1][0],
    option[x - 1][1], option[x - 1][2], option[x - 1][3]);

    int user = 0; //choice entered by user
    scanf("%d", &user);

    if (user == key[x - 1]){ 
        //on correct answer
        update_won(x, amount);
    }

    else if (user == 5 && c1 > 0){ 
         //50-50 lifeline
        c1--;
         printf("you have chosen 50-50");
         printf("Two options will be deleted. here we go-");
         printf("Your two options are- \n2)%s \n3)%s \n", option[x - 1][1], option[x -1][2]);
         scanf("%d", &user);

         if (user == key[x - 1]){
           update_won(x, amount);
         }
         else{
          quit(amount);
        }
    }

    else if (user == 5 && c1 == 0){
         printf("\nyou have used your 50-50 lifeline\n");
         question(x, amount);
         //continue;
    }

    else if (user == 6 && c2 > 0){ 
         //flip question lifeline
        c2--;
         printf("You have chosen flip the question. Your new question is\n");
         printf("%s", q[15]);
         printf("\nYour four options are-\n 1. %s \n 2. %s\n 3. %s\n 4. %s \n",
         option[15][0], option[15][1], option[15][2], option[15][3]);
          scanf("%d", &user);

        if (user == key[15]){
          update_won(x, amount);
        }
        else{
          quit(amount);
        }
    }
    else if (user == 6 && c2 == 0){
         printf("\nyou have already used your flip question lifeline\n");
         question(x, amount);
    }

    else if (user == 7){ 
         //when user wants to quit
        printf("\nYou have chosen to quit. It was a pleasure to play with you");
        quit(amount);
    }

    else{
       quit(amount);
    }
}

int main(){
system( "Color 05");
printf("\n WELCOME TO KAUN BANEGA CROREPATI!!!!");
printf("\n\n Rules and Regulations");
printf("\n\n1.The maximum number of questions in this game is 15");
printf("\n2.Intermediate levels are present throughout the Questionnaire and upon answering wrongly");
printf(" to a question you shall fall back to the preceding immediate level immediately");

printf("\n3.There are a total of 3 intermediate levels in this Questionnaire at questions 3, 8, and 12 respectively.");
printf("\n4.Two lifelines are provided which can be availed only once each throughout the game: 50-50 and flip the question");

printf("\n\nTHE DISTRIBUTION OF PRIZE MONEY ACCORDING TO DIFFERENT QUESTIONS IS SHOWN BELOW:");
printf("\n QUESTION 1 Rs.1000");
printf("\n QUESTION 2 Rs.5000");
printf("\n QUESTION 3 Rs.10,000");
printf("\n QUESTION 4 Rs.20,000");
printf("\n QUESTION 5 Rs.40,000");
printf("\n QUESTION 6 Rs.80,000");
printf("\n QUESTION 7 Rs.1,60,000");
printf("\n QUESTION 8 Rs.3,20,000");
printf("\n QUESTION 9 Rs.6,40,000");
printf("\n QUESTION 10 Rs.12,50,000");
printf("\n QUESTION 11 Rs.25,00,000");
printf("\n QUESTION 13 Rs.50,00,000");
printf("\n QUESTION 13 Rs.1 crore");
printf("\n QUESTION 14 Rs.3 Crore");
printf("\n QUESTION 15 Rs.7 Crore");

  for (int i = 1; i < 16; i++){ 
    //loop printing the questions
     question(i, score);
   }
   return 0;
}