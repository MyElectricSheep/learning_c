#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race
{
    int numberOfLaps;
    int currentLap;
    char *firstPlaceDriverName;
    char *firstPlaceRaceCarColor;
};

struct RaceCar
{
    char driverName[25];
    char raceCarColor[25];
    int totalLapTime;
};

// Print functions section
void printIntro(void)
{
    printf("\n*********************************************************\n");
    printf("Welcome to our main event digital race fans!\n");
    printf("I hope everybody has their snacks because we are about to begin!\n");
    printf("*********************************************************\n");
}

void printCountDown(void)
{
    printf("\nRacers ready! In...\n");
    printf("5\n");
    printf("4\n");
    printf("3\n");
    printf("2\n");
    printf("1\n");
    printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race)
{
    printf("\nAfter lap number %d\n", race.currentLap);
    printf("First place is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race)
{
    printf("\nLet's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    printf("It truly was a great race and everybody have a goodnight!\n");
}

// Logic functions section
int randomNumber(void)
{
    return (rand() % 3) + 1;
}

int calculateTimeToCompleteLap(void)
{
    int speed = randomNumber();
    int acceleration = randomNumber();
    int nerves = randomNumber();
    // printf("%d.%d.%d\n", speed, acceleration, nerves);
    return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar *raceCarPointer)
{
    int timeToCompleteLap = calculateTimeToCompleteLap();
    raceCarPointer->totalLapTime += timeToCompleteLap;
}

struct RaceCar *getFirstPlaceCar(struct RaceCar *raceCarPointer1, struct RaceCar *raceCarPointer2)
{
    struct RaceCar *winner;
    winner = raceCarPointer1->totalLapTime > raceCarPointer2->totalLapTime ? raceCarPointer1 : raceCarPointer2;
    return winner;
}

void updateFirstPlace(struct Race *racePointer, struct RaceCar *raceCarPointer1, struct RaceCar *raceCarPointer2)
{
    struct RaceCar *firstPlaceRacer = getFirstPlaceCar(raceCarPointer1, raceCarPointer2);
    racePointer->firstPlaceDriverName = firstPlaceRacer->driverName;
    racePointer->firstPlaceRaceCarColor = firstPlaceRacer->raceCarColor;
}

void startRace(struct RaceCar *raceCarPointer1, struct RaceCar *raceCarPointer2)
{
    struct Race race = {5, 1, "", ""};

    for (int i = race.currentLap; i < race.numberOfLaps; i++)
    {
        printf("\n****************************************\n");
        printf("Start of lap %d", race.currentLap);
        printf("\n****************************************\n");
        updateRaceCar(raceCarPointer1);
        updateRaceCar(raceCarPointer2);
        updateFirstPlace(&race, raceCarPointer1, raceCarPointer2);
        printFirstPlaceAfterLap(race);
        race.currentLap++;
    }

    updateFirstPlace(&race, raceCarPointer1, raceCarPointer2);
    printCongratulation(race);
}

int main(void)
{

    struct RaceCar car1 = {"Benito", "Orange", 0};
    struct RaceCar car2 = {"Pepito", "Blue", 0};

    srand(time(NULL));
    printIntro();
    printCountDown();
    startRace(&car1, &car2);
}