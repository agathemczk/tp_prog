#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    struct stop *stop;
    struct line *nxt;
} line ;
typedef line* Line;

typedef struct stop {
    char name;
    char destination;
    float time;
} stop ;
typedef stop* Stop;

stop * create_stop(char name, char destination, float time) {
    struct stop *S;
    S = malloc(sizeof(struct stop));
    S->name = name;
    S->destination = destination;
    S->time = time;   //durée du trajet entre les deux arrêts en h
                      // (destination étant le prochain arrêt après l'arrêt "name")
    return S;
}

Line add_stop(void *Line, stop *stop) {
    line* newLine = malloc(sizeof(line));
    newLine->stop=stop;
    newLine->nxt=NULL;

    if(Line == NULL) {
        return newLine;

    } else {
        line* temp = Line;
        while(temp->nxt != NULL) {
            temp =  temp->nxt;
        }
        temp->nxt = newLine;
        return Line;
    }
}

Line find_a_stop(line *Line, stop Stop, char value) {
    line *tmp =Line;
    while(tmp != NULL) {
        if(tmp->stop == value) {
            return tmp;
        }
        tmp = tmp ->nxt;
    }
    return NULL
}

int calculate_optimal_path(line Line, stop stop, char start, char end) {
    float time = 0.0;
    line *Line_1 = NULL;
    line *Line_2 = NULL;
    while(find_a_stop(Line_1, stop.destination, end) != NULL || find_a_stop(Line_2, stop.destination, end)) {
        while (find_a_stop(Line_1, stop.name, start) || find_a_stop(Line_2, stop.destination, start)) {
            printf("Prenez l'arrêt %c, direction %c \n", stop.name, stop.destination);
            time += stop.time;
            start = stop.destination;
        }
    }
    printf ("Votre trajet sera de %f \n", time);
    return 0;
}



int main(int argc, char **argv) {
    line *Line_1 = NULL;
    line *Line_2 = NULL;

    add_stop(Line_1,create_stop('A','B',1));
    add_stop(Line_1,create_stop('B','D',2));
    add_stop(Line_1,create_stop('D','E',0.5));
    add_stop(Line_2,create_stop('A','C',1.5));
    add_stop(Line_2, create_stop('C','D',1));

    char start;
    char end;

//    printf("De quelle ville voulez-vous partir ? (A,B,C,D ou E) \n");
//    scanf("%c",&start);
//
//    printf("Où allez-vous ? (A,B,C,D ou E) \n");
//    scanf("%c",&end);

    start = 'A';
    end = 'E';

    calculate_optimal_path(Line,stop,start,end);

    return 0;
}

