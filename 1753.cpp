#include <stdio.h>

int field[6]={0};
int state[][4]={{8,4,2,1},{12,14,7,3}};

void read() {
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            field[i]<<=1;
            if(getchar()=='b')
                field[i]|=1;
        }
        getchar();
    }
}

void flip(int i, int j) {--j;
    field[i-1]^=state[0][j];
    field[i]  ^=state[1][j];
    field[i+1]^=state[0][j];
}

bool check() {
    return (field[1]==0||field[1]==15)
         && field[1]==field[2]
         && field[2]==field[3]
         && field[3]==field[4];
}

bool find(int n, int i, int j) {
    if(n==0) return check();
    j+=1; if(j>4) i+=1, j=1;
    if(i>4) return false;
    for(; i<=4; i++) {
        for(; j<=4; j++) {
            flip(i, j);
            if(find(n-1,i,j))
                return true;
            flip(i, j);
        }
        j=1;
    }
    return false;
}

void work() {
    for(int i=0; i<=16; i++)
        if(find(i,1,0)) {
            printf("%d\n", i);
            return;
        }
    puts("Impossible");
}

int main() {
    read();
    work();
    return 0;
}


