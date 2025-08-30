#include <stdio.h>

struct horario{
    int horas;
    int minutos;
    int segundos;
};

void setTime( struct horario *t1, int hrs, int min, int sec){
    t1->horas = (hrs >= 0 && hrs <24) ? hrs : 0;
    t1->minutos = (min >=0 && min <60) ? min :0;
    t1->segundos = (sec >=0 && sec<60) ? sec: 0;
}

void print12(struct horario *t1){
    if(t1->horas <= 12){
        printf("\n%d:%d:%d AM",t1->horas,t1->minutos, t1->segundos);
    }
    else{
        printf("\n%d:%d:%d PM",t1->horas-12,t1->minutos, t1->segundos);
    }
}

void print24(struct horario *t1){
    printf("\n%d:%d:%d",t1->horas,t1->minutos,t1->segundos);
}
int main(){
    struct horario h1;
    
    setTime(&h1, -12, 30, 40);
    print12(&h1);
    print24(&h1);

    return 0;
}
