#include "funkc.h"
#include <iostream>
#include <tuple>

float nm2au(float nm){
    return nm*18.89726133921252;
};

float eV2au(float eV){
    return eV*0.03674932587122423;
};

int nlg_fun(int i_kom, int i_wewn, int N){ //zwraca numer wezla globalnie z numeru komorki i numeru wezla lokalnego
    if(i_wewn <= 0 || i_wewn >= 5 ){
        throw std::invalid_argument("i_wewn must be between 1 and 4");
    }    
    switch (i_wewn)
    {
    case 1:
        return i_kom;
        break;
    case 2:
        if(float(i_kom)/(N*N) > (2*N-1) ){
            return i_kom + 2*(2*N);
        }
        return i_kom + (2*N);
        break;
    case 3:
        if( i_kom%(2*N) == 0){
            return (4*N*N) + int(i_kom / (2*N)); 
        }
        return i_kom + 1;
        break;
    case 4:
        if(float(i_kom)/(N*N) > (2*N-1) ){
            return i_kom + 2*(2*N) + 1;
        }
        if( i_kom%(2*N) == 0){
            return (4*N*N) + int(i_kom / (2*N)) + 1;
        }
        return i_kom + (2*N)+ 1;
        break;
    
    default:
    return -99;
        break;
    }

};

int index_kom2i_kom(int i, int j, int N){
    return 2*N-i + j*2*N;
};

std::vector<int> i_kom_i_wewn2index_kom(int i_kom, int i_wewn, int N){
    int i, j;

    switch (i_wewn)    {
    case 1:
        if(i_kom%(2*N) == 0){
            i = i_kom%(2*N)+1;
        }else{
            i = 2*N - i_kom%(2*N)+1;
        }
        j = int((i_kom - 0.1)/(2*N)); //xD chyba będzie działać
        break;
    case 2:
        if(i_kom%(2*N) == 0){
            i = i_kom%(2*N)+1;
        }else{
            i = 2*N - i_kom%(2*N)+1;
        }
        j = int((i_kom - 0.1)/(2*N)) + 1; //xD chyba będzie działać
        break;
    case 3:
        if(i_kom%(2*N) == 0){
            i = i_kom%(2*N);
        }else{
            i = 2*N - i_kom%(2*N);
        }
        j = int((i_kom - 0.1)/(2*N)); //xD chyba będzie działać
        break;
    case 4:
        if(i_kom%(2*N) == 0){
            i = i_kom%(2*N);
        }else{
            i = 2*N - i_kom%(2*N);
        }
        j = int((i_kom - 0.1)/(2*N))+1; //xD chyba będzie działać
        break;
    default:
    throw std::invalid_argument(" błąd w i_kom_iwewn2index_kom, podano zle i_wewn");
        i = -99;
        j = -99;
        break;
    }


    std::vector<int> ret = {i, j};
    return ret;
};


int index_node2node_name(int i, int j, int N){
    if(i!=2*N && j != 2*N){
        return nlg_fun(index_kom2i_kom(i, j, N), 3);
    }
    if(i == 2*N && j!= 2*N){
        return nlg_fun(index_kom2i_kom(i-1, j, N), 1);
    }
    if( i!=0 && j == 2*N){
        return nlg_fun(index_kom2i_kom(i-1, j-1, N), 2);
    }
    //if( i == 0 && j == 2*N){
    return nlg_fun(index_kom2i_kom(i, j-1, N), 4);
    
};

float g(float eps1, float eps2, int i){
    switch(i){
    case 1:
        return f1(eps1)*f1(eps2);
        break;
    case 2:
        return f2(eps1)*f1(eps2);
        break;
    case 3:
        return f1(eps1)*f2(eps2);
        break;
    case 4:
        return f2(eps1)*f2(eps2);
        break;
    default:
        throw std::out_of_range("i out of range");
        break;
    }
};


float f1(float x){
    return (1.0 - x)/2.0;
};

float f2(float x){
    return (1.0 + x)/2.0;
};

std::vector<float> i_kom_i_wewn2pos(int i_kom, int i_wewn, float Lnm, float anm){
    std::vector<int> indexes = i_kom_i_wewn2index_kom(i_kom, i_wewn);

    std::vector<float> pos(2);
    pos[0] = -Lnm/2 + indexes[1] * anm;  //x 
    pos[1] = Lnm/2 - indexes[0] * anm;   //y

    return pos;
}

