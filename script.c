#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
 
void delay(int number_of_seconds)
{
int milli_seconds = 1000 * number_of_seconds;
clock_t start_time = clock();
while (clock() < start_time + milli_seconds) ;
}
struct Race {
	int numberOflaps;
	int currentLap;
	char firstPlaceDriverName[100];
	char firstPlaceRaceCarColor[100];
};
struct RaceCar {
	char driverName [100];
	char raceCarColor [100];
	int totalLapTime;
	
};
void printIntro(){
printf("Bienvenue a notre evenement principal, les fans de course numerique ! \n J'espere que tout le monde a pris son gouter car nous allons commencer !\n");

}
void printCountDown(){ printf("Coureurs prets ! Dans...\n");
int i;
for(i=5;i>0;i--){
	delay(1);
printf("\n%d\n",i);}
printf("Course !");
	
}
void printFirstPlaceAfterLap(struct Race race){
	printf("Apres le tour numero :%d \n La premiere place est occupee par:%s dans la voiture de course %s !\n",race.currentLap,race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}
void printCongratulation( struct Race race){
    printf("Felicitons tous %s, dans la voiture de course %s, \n pour son incroyable performance.\n C etait vraiment une belle course et bonne nuit a tous !",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}
int calculateTimeToCompleteLap(){
    int vitesse,acceleration,nerves;
    vitesse=(rand()%3)+1;
    acceleration= (rand()%3)+1;
    nerves=(rand()%3)+1;
    return vitesse+acceleration+nerves;
}
void updateRaceCar(struct RaceCar *raceCar ){
    (*raceCar).totalLapTime=calculateTimeToCompleteLap()+(*raceCar).totalLapTime;
}
void updateFirstPlace(struct Race *race,struct RaceCar *raceCar1,struct RaceCar *raceCar2){
    if ((*raceCar1 ).totalLapTime> (*raceCar2 ).totalLapTime)
    { strcpy(race->firstPlaceDriverName,raceCar1->driverName);
    strcpy(race->firstPlaceRaceCarColor,raceCar1->raceCarColor);}
    else {
    strcpy(race->firstPlaceDriverName,raceCar2->driverName);
    strcpy(race->firstPlaceRaceCarColor,raceCar2->raceCarColor);
    }
}
void startRace( struct RaceCar *raceCar1,struct RaceCar *raceCar2 ){
  struct Race race ={5,1,"",""};
  int i;
 for(i=0;i<race.numberOflaps;i++){
      updateRaceCar(raceCar1);
      updateRaceCar(raceCar2);
      updateFirstPlace(&race,raceCar1,raceCar2);
      printFirstPlaceAfterLap(race);
      race.currentLap++;
 }
 printCongratulation(race);
}

int main(){

    struct RaceCar raceCar1={"fatima","rouge",0},raceCar2={"nouhaila","blue",0};
	printIntro();
	printCountDown();
    srand(time(0));
    startRace(&raceCar1,&raceCar2);

	// struct Race race1;
	// race1.currentLap=2;
	// strcpy(race1.firstPlaceDriverName,"DARIM");
    // strcpy(race1.firstPlaceRaceCarColor,"Rouge");
	
	// printFirstPlaceAfterLap(race1);
    // printCongratulation(race1);
	// printf("%d",calculateTimeToCompleteLap());
	}


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>

// // Structures section
// struct Race
// {
//     int numberOfLaps;
//     int currentLap;
//     char firstPlaceDriverName[20];
//     char firstPlaceRaceCarColor[20];
// };

// struct RaceCar
// {
//     int totalLapTime;
//     char driverName[20];
//     char raceCarColor[20];
// };

// // Print functions section
// void printIntro()
// {
//     printf("Bienvenue a notre evenement principal, les fans de course numerique !\n J'espere que tout le monde a pris son gouter car nous allons commencer !");
// }
// void printCountDown()
// {
//     int i;
//     printf("Coureurs prets ! Dans...\n");
//     for (i = 5; i <= 1; i--)
//     {
//         printf("%d\n", i);
//     }
// }
// void printFirstPlaceAfterLap(struct Race race)
// {
//     printf("tour en cours %d avec le pilote %s en tete et la couleur de son voiture est %s \n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
// }
// void printCongratulation(struct Race race)
// {
//     printf("Felicitons tous  %s, dans la voiture de course %s, pour son incroyable performance.C etait vraiment une belle course et bonne nuit a tous ! \n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
// }
// void print2Congratulation(struct Race race1, struct Race race2)
// {
//     printf("Felicitons au deux pilots %s et  %s, dans la voiture de course %s et %s, pour leur incroyable performance.C etait vraiment une belle course et bonne nuit a tous ! \n", race1.firstPlaceDriverName, race2.firstPlaceDriverName, race1.firstPlaceRaceCarColor, race2.firstPlaceRaceCarColor);
// }
// int calculateTimeToCompleteLap()
// {
//     int vitesse, acceleration, nerves;
//     time_t t;
//     srand((unsigned)time(&t));
//     vitesse = rand() % 2 + 1;
//     acceleration = rand() % 2 + 1;
//     nerves = rand() % 2 + 1;
//     return (nerves + vitesse + acceleration);
// }

// // Logic functions section

// void updateRaceCar(struct RaceCar *race, int a)
// {
//     int i;
//     for (i = 0; i < a; i++)
//     {
//         (*race).totalLapTime = calculateTimeToCompleteLap() + (*race).totalLapTime;
//     }
// }
// void updateFirstPlace(struct Race *race, struct RaceCar *race1, struct RaceCar *race2)
// {
//     if ((*race1).totalLapTime > (*race2).totalLapTime)
//     {
//         strcpy((*race).firstPlaceDriverName, (*race1).driverName);
//         strcpy((*race).firstPlaceRaceCarColor, (*race1).raceCarColor);
//     }
//     else if ((*race1).totalLapTime <= (*race2).totalLapTime)
//     {
//         strcpy((*race).firstPlaceDriverName, (*race2).driverName);
//         strcpy((*race).firstPlaceRaceCarColor, (*race2).raceCarColor);
//     }
// }
// void startRace( struct RaceCar *raceCar1, struct RaceCar *courseCar2)
// {
//     struct Race *race;
//     int i;
//     strcpy((*race).firstPlaceDriverName, "");
//     strcpy((*race).firstPlaceRaceCarColor, "");
//     strcpy((*race).numberOfLaps, 5);
//     strcpy((*race).currentLap, 1);
//     for(i=0;i<(*race).numberOfLaps;i++){
//     updateRaceCar(raceCar1, (*race).currentLap);
//     updateRaceCar(courseCar2, (*race).currentLap);
//     updateFirstPlace(&race, &courseCar2, &raceCar1);
//     printFirstPlaceAfterLap(*race);
//     (*race).currentLap++;
//     }
//         printCongratulation(*race);
// }

// int main()
// {
//     struct RaceCar race1 = {calculateTimeToCompleteLap(), "hind", "rouge"};
//     struct RaceCar race2 = {calculateTimeToCompleteLap(), "nouhaila", "blue"};
//     struct Race race;
//     // int a;
//     printIntro();
//     printCountDown();
//     startRace(&race,&race1,&race2);
//     // if (race1.totalLapTime > race2.totalLapTime)
//     //     a = 1;
//     // else if (race1.totalLapTime < race2.totalLapTime)
//     //     a = 2;
//     // else
//     //     a = 0;
//     // switch (a)
//     // {
//     // case 1:
//     //     strcpy(race.firstPlaceDriverName, race1.driverName);
//     //     strcpy(race.firstPlaceRaceCarColor, race1.raceCarColor);
//     //     break;
//     // case 2:
//     //     strcpy(race.firstPlaceDriverName, race2.driverName);
//     //     strcpy(race.firstPlaceRaceCarColor, race2.raceCarColor);
//     //     break;
//     // }
//     // if (a != 0)
//     // {

//     // }
//     // else
//     // {
//     //     strcpy(race12.firstPlaceDriverName, race1.driverName);
//     //     strcpy(race12.firstPlaceRaceCarColor, race1.raceCarColor);
//     //     strcpy(race22.firstPlaceDriverName, race2.driverName);
//     //     strcpy(race22.firstPlaceRaceCarColor, race2.raceCarColor);
//     //     print2Congratulation(race12, race22);
//     // }
//     // printf("%d", calculateTimeToCompleteLap());
// }