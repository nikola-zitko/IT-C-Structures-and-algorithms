#include<stdio.h>

typedef struct{
    int player;
    int vuk;
    int ovca;
    int kupus;
}State;

State NewGame(){
    State s;
    s.player = 0;
    s.vuk = 0;
    s.ovca = 0;
    s.kupus = 0;
    return s;
}

void PrintState(State* s){
    for(int i=0; i<2; i++){
        if(s->vuk == 0)
            printf("Vuk ");
        if(s->ovca == 0)
            printf("Ovca ");
        if(s->kupus == 0)
            printf("Kupus ");
        if(s->player == 0)
            printf("Brod ");
        printf("~~~~~~ ");
        if(s->player == 1)
            printf("Brod ");
        if(s->vuk == 1)
            printf("Vuk ");
        if(s->ovca == 1)
            printf("Ovca ");
        if(s->kupus == 1)
            printf("Kupus ");
        printf("\n");
    }
}

void NextStates(State* s, State* nstates){
    int ns = 0;
    for(int i = 0; i<4; i++){
        nstates[i] = *s;
    }
    if(s->vuk == s->player){
        nstates[0].vuk = !s->vuk;
        nstates[0].player = !s->player;
    }
    if(s->ovca == s->player){
        nstates[1].ovca = !s->ovca;
        nstates[1].player = !s->player;
    }
    if(s->kupus == s->player){
        nstates[2].kupus = !s->ovca;
        nstates[2].player = !s->player;
    }
    nstates[3].player = !s->player;
}

int WinState(State *s){
    return(s->vuk == 1 && s->ovca == 1 && s->kupus == 1);
}

int LoseState(State *s){
    return((s->vuk == s->ovca && s->ovca != s->player) || (s->ovca == s->kupus && s->kupus != s->player));
}

int Solve(State *s, int d){
    if(WinState(s)){
        PrintState(s);
        return 1;
    }

    if(LoseState(s) || d == 0){
        return 0;
    }
    State nstates[4];
    NextStates(s, nstates);
    for(int i = 0; i<4; i++){
        if(Solve(&nstates[i], d-1)){
            PrintState(s);
            return 1;
        }
    }
    return 0;
}

void main(){
    State s = NewGame();
    for(int d=1; d<20; d++){
        if(Solve(&s, d)){
            printf("Solved in %d\n", d);
            break;
        }
    }

}
