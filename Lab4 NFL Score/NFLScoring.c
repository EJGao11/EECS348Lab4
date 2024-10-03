#include <stdio.h>
#include <string.h>
void recScore(int scores[], int team[], int currentScore, int targetScore);

int main()
{
    int targetScore = 0;
    int currentScore = 0;

    int scores[] = {8,7,6,3,2};
    int teamPlays[] ={0,0,0,0,0};
    int currentPath = 0;
    
    printf("Enter NFL Score: ");
    scanf("%d", &targetScore);
    
    recScore(scores, teamPlays, currentScore, targetScore);
    return 0;
}

void recScore(int scores[], int team[], int currentScore, int targetScore)
{
    int copyTeam[strlen(team)*sizeof(int)];
    memcpy(copyTeam,team,strlen(team)*sizeof(int));
    for ( int i = 0; i < 5; i++)
    {
        if(currentScore + scores[i] <= targetScore)
        {
            copyTeam[i] +=  1;
            recScore(scores, copyTeam, currentScore += scores[i], targetScore);
        }
    }
    if(currentScore == targetScore)
    {
        printf("Twopoint Touchdown: %d", copyTeam[0]);
        printf(" Fieldgoal Touchdown: %d", copyTeam[1]);
        printf(" Touchdown: %d", copyTeam[2]);
        printf(" Fieldgoal: %d", copyTeam[3]);
        printf(" Safty: %d", copyTeam[4]);
        printf("\n");
    }
}
