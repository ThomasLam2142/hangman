#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> // for isalpha


void show_man(int health){
    switch (health){
        case 3:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 1:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("=========\n");
            break;
    }
}

bool check_ans(char choice, char word[7]){
    for (int i = 0; i < 6; i++){
        if (word[i]== choice){
            return true;
        }
    }
    return false;
}

int main(){
    printf("Welcome to Hangman!\n");
    /*
    printf("Please select a difficulty: \n");
    printf("1. Easy (5 letters)\n");
    printf("2. Medium (7 letters)\n");
    printf("3. Hard (9 letters)\n");
    */
    //char* answer = "tester";
    int remaining = 6;
    int health = 3;
    char choice;
    char word[7] = "tester";

    do{
        show_man(health);
        printf("%d characters remaining: \n", remaining);
        printf("Enter a Letter\n");
        int valid_input = 0;

        while (!valid_input) {
            printf("Enter a letter: ");
            scanf(" %c", &choice);

            // Clear rest of input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            if (!isalpha(choice)) {
                printf("Invalid input. Please enter a letter (A-Z or a-z).\n");
            } else {
                choice = tolower(choice);
                valid_input = 1;
            }
        }
        printf("You have guessed : %c\n", choice);

        if (check_ans(choice, word)) {
            printf("Correct guess!\n");
            remaining -= 1;
        } else {
            printf("Wrong guess!\n");
            health -= 1;
            printf("Remaining health: %d\n",health);
        }
    }while(health > 0 && remaining > 0);

    if (health == 0){
        printf("You Lose!\n");
    }else{
        printf("You Win!\n");
    }
    
    
    return 0;
}

