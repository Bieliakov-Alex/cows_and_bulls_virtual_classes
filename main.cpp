#include <iostream>

struct CowsAndBullsAnswer{
    unsigned char cows;
    unsigned char bulls;
};

class IAskNumber{
    virtual CowsAndBullsAnswer Ask(unsigned char number[4]) const = 0;
};

/*class CowsAndBullsPlayer{
public:
    explicit CowsAndBullsPlayer(unsigned char n[4]):
    number{*n}{}
protected:
    unsigned char operator[](size_t index);
private:
    unsigned char number[4];
};*/

class CowsAndBullsPlayer{
    CowsAndBullsPlayer() = delete;
protected:
    explicit CowsAndBullsPlayer(unsigned char n[4]):
    number{*n}{}
    unsigned char operator[](size_t index);
private:
    unsigned char number[4];
};

class CowsAndBullsComputerPlayer: private CowsAndBullsPlayer, public IAskNumber{
public:
    CowsAndBullsComputerPlayer(unsigned char n[4]): CowsAndBullsPlayer(*n){}
    CowsAndBullsAnswer Ask(unsigned char number[4]) const override;
};

class CowsAndBullsLivePlayer: private CowsAndBullsPlayer, public IAskNumber{
public:
    CowsAndBullsLivePlayer(unsigned char n[4]): CowsAndBullsPlayer(*n){}
    CowsAndBullsAnswer Ask(unsigned char number[4]) const override;
};

int main(){
    unsigned char n[] = {0, 1, 2, 3};
    //CowsAndBullsPlayer p{n};
    return 0;
}