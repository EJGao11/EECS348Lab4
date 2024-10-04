#include <stdio.h>

// Function to print the current combination
void printCombination(int combination[], int count) 
{
    int TD2 =0;
    int TD1 = 0;
    int TD = 0;
    int FG = 0;
    int safty = 0;

    for (int i = 0; i < count; i++) 
    {
        switch( combination[i])
        {
            case 8:
                TD2++;
                break;

            case 7:
                TD1++;
                break;
            
            case 6:
                TD++;
                break;
            case 3:
                FG++;
                break;
            case 2:
                safty++;
                break;
                
            default:
                break;
        }
    }
    printf("TD 2pt Conversion: %d ", TD2);
    printf(" TD Fieldgoal: %d ", TD1);
    printf(" Towndown: %d ", TD);
    printf(" Fieldgoal: %d ", FG);
    printf(" Safty : %d ", safty);
    printf("\n");
}


void findCombinations(int points[], int n, int sum, int combination[], int index) 
{
   
    // Find vaild comb than sends to print
    if (sum == 0) 
    {
        printCombination(combination, index);
        return;
    }

    // Over the point count or ran out of options
    if (sum < 0 || n <= 0) 
    {
        return;
    }

    // Puts the play into comb
    combination[index] = points[n - 1];
   
    // Inculde or exclude play
    findCombinations(points, n, sum - points[n - 1], combination, index + 1);

    findCombinations(points, n - 1, sum, combination, index);
}

// Sets up points and calls the recursive function
int main() 
{
    int points[] = {2, 3, 6, 7, 8};

    int targetScore = 0;
    int combination[1000];

    printf("Enter NFL Score: ");
    scanf("%d", &targetScore);

    if(targetScore == 0 || targetScore == 1)
    {
        printf("Invaild Score Enter something Higher than 2");
    }
    else
    {
        printf("Combinations of plays that sum to %d:\n", targetScore);
        findCombinations(points, 5, targetScore, combination, 0);
    }
    return 0;
}