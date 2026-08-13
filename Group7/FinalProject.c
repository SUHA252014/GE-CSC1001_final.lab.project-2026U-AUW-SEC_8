#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    int id;
    string name;
    float score;
    char grade;
}

Student;


char calculate_grade(float score)
{
    if (score >= 90)
    {
        return 'A';
    }
    else if (score >= 80)
    {
        return 'B';
    }
    else if (score >= 70)
    {
        return 'C';
    }
    else
    {
        return 'F';
    }
}


float sum_scores(Student students[], int count)
{
    if (count <= 0)
    {
        return 0;
    }
    return students[count - 1].score + sum_scores(students, count - 1);
}

int main(void)
{

    int total = get_int("How many students do you have? ");


    Student class_list[total];


    for (int i = 0; i < total; i++)
    {
        printf("\n--- Student %d ---\n", i + 1);
        class_list[i].id = get_int("Enter ID: ");
        class_list[i].name = get_string("Enter Name: ");
        class_list[i].score = get_float("Enter Score (0-100): ");
        class_list[i].grade = calculate_grade(class_list[i].score);
    }


    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (class_list[j].score < class_list[j + 1].score)
            {
                
                Student temp = class_list[j];
                class_list[j] = class_list[j + 1];
                class_list[j + 1] = temp;
            }
        }
    }


    printf("\n=== ALL STUDENTS (Sorted by Score) ===\n");
    for (int i = 0; i < total; i++)
    {
        printf("ID: %d | Name: %s | Score: %.1f | Grade: %c\n",
               class_list[i].id, class_list[i].name, class_list[i].score, class_list[i].grade);
    }


    printf("\n=== SEARCH FOR A STUDENT ===\n");
    string search_name = get_string("Who do you want to find? ");
    bool found = false;

    for (int i = 0; i < total; i++)
    {
        if (strcmp(class_list[i].name, search_name) == 0)
        {
            printf("Found them! %s has score %.1f and grade %c\n",
                   class_list[i].name, class_list[i].score, class_list[i].grade);
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Sorry, %s is not in the list.\n", search_name);
    }


    float total_score = sum_scores(class_list, total);
    printf("\nClass Average Score: %.2f\n", total_score / total);


    FILE *file = fopen("students.txt", "w");
    if (file != NULL)
    {
        for (int i = 0; i < total; i++)
        {
            fprintf(file, "ID: %d, Name: %s, Score: %.1f, Grade: %c\n",
                    class_list[i].id, class_list[i].name, class_list[i].score, class_list[i].grade);
        }
        fclose(file);
        printf("\nSaved records to 'students.txt' successfully!\n");
    }

    return 0;
}
