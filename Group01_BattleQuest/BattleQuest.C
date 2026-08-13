#include <stdio.h>
#include <stdlib.h>

int main()
{
    char playerName[30];

    int playerHP=100;
    int enemyHP=100;
    int choice;
    int damage;
    int heal;

    printf("==================================\n");
    printf("          BATTLE QUEST\n");
    printf("==================================\n");

    printf("\nEnter your name: ");
    scanf("%s", playerName);

    printf("\nWelcome, %s!\n", playerName);
    printf("You have encountered a GOBLIN!\n");

    while(playerHP >0 && enemyHP>0)
    {
        printf("\n=====================================\n");
        printf("              BATTLE\n");
        printf("=====================================\n");

        printf("\n        %s           GOBLIN\n", playerName);

        printf("          O                    O\n");
        printf("         /|\\                  /|\\\n");
        printf("         / \\                  / \\\n");

        printf("\nPlayer HP: %d/100", playerHP);
        printf("\nEnemy HP: %d/100\n", enemyHP);

        printf("\nWhat will you do?\n");
        printf("1. Attack\n");
        printf("2. Heal\n");
        printf("3. Defend\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            damage = rand() % 11+10;
            enemyHP = enemyHP - damage;

            printf("\n");
            printf("          %s attacks!\n", playerName);
            printf("        ⚔️  --->  💥\n");

            printf("\nYou dealt %d damage to the Goblin!\n", damage);

            if(enemyHP > 0)
            {
                damage = rand()%11+5;
                playerHP = playerHP - damage;

                printf("\nThe Goblin attacks!\n");
                printf("        👹  --->  💥\n");
                printf("\nYou lost %d HP!\n", damage);
            }
        }

        else if (choice == 2)
        {
            heal = rand()%11+10;
            playerHP = playerHP+heal;

            if(playerHP>100)
            {
                playerHP=100;
            }
            printf("\n");
            printf("        ❤️ %s heals!\n", playerName);
            printf("You recovered %d HP!\n", heal);

            if (enemyHP > 0)
            {
                damage = rand()%11+5;
                playerHP = playerHP - damage;

                printf("\nThe Goblin attacks while you heal!\n");
                printf("you lost %d HP\n",damage);
            }

        }

        else if(choice == 3)
        {
            damage = rand()%6+5;
            playerHP = playerHP - damage;

            printf("\n");
            printf("        🛡️ %s defends!\n", playerName);
            printf("The Goblin's attack was reduced!\n");
            printf("You only lost %d HP!\n", damage);
        }

        else
        {
            printf("\nInvalid choice! Please choose 1,2 or 3.\n");
        }
    }

    printf("\n========================================\n");
    printf("              BATTLE OVER\n");
    printf("========================================\n");

    if (playerHP>0)
    {
        printf("\n🏆 VICTORY! 🏆\n");
        printf("\n%s defeated the Goblin!\n",playerName);
        printf("Remaining HP: %d\n", playerHP);
    }
    else
    {
        printf("\n💀 DEFEAT 💀\n");
        printf("\nThe Goblin defeated %s!\n",playerName);
    }
    printf("\nThe End!\n");

    return 0;
}
