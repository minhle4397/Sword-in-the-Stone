#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
void readData_Events(const string& fileName, int& n, int*& arr);
bool isPrime(int n);
bool isPythagorasTriplet(int n);
void readData_Army(const string &fileName, int &n, int **&army);
enum ItemType {Anti = 0, PhoenixI, PhoenixII, PhoenixIII, PhoenixIV};

class BaseItem;
class BaseKnight;
class Antidote;
class PhoenixDownI;
class PhoenixDownII;
class PhoenixDownIII;
class PhoenixDownIV;
class ArmyKnights;
class Events;
class KnightAdventure;
class BaseOpponent;
class BaseBag;
class PaladinKnight;
class PaladinBag;
class LancelotKnight;
class LancelotBag;
class DragronKnight;
class DragonBag;
class NormalKnight;
class NormalBag;
class Node;
class Madbear;
class Bandit;
class LordLupin;
class Elf;
class Troll;
class Tornbery;
class QueenOfCards;
class NinaDeRings;
class DurianGarden;
class OmegaWeapon;
class Hades;
class PDII;
class PDIII;
class PDIV;
class Shield;
class Spear;
class Hair;
class Excalibur;
class Ultimecia;

class BaseItem {
public:
    ItemType type;
    BaseItem(ItemType t) : type(t){}
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
};
class Node{ // tạo head túi đồ
public:
    ItemType item;
    Node * next;
};
class BaseBag {
protected:
    BaseKnight * knight;
    int n_bag;
    Node * node;
public:
    int getN_Bag() {return n_bag;}
    Node * getHead_Node() {return node;}
    void setHead_Node(Node * t) {node = t;}
    void setN_Bag(int k) { n_bag = k; }
    virtual bool isFull()=0;//full đồ hay không
    virtual bool insertFirst(BaseItem * item)=0;
    virtual BaseItem * get(ItemType itemType)=0;
    virtual string toString() const=0;
};

class DragonBag : public BaseBag{
public:
    DragonBag(BaseKnight * bk, int a,int b);//khong bi anh huong boi doc nen khong chua thuoc giai Antidote
    ~DragonBag();
    bool isFull() override;
    bool insertFirst(BaseItem * item) override;
    BaseItem * get(ItemType itemType) override;
    string toString() const override;
};
class LancelotBag : public BaseBag{
public:
    LancelotBag(BaseKnight * bk, int a, int b);
    ~LancelotBag();
    bool isFull() override;
    bool insertFirst(BaseItem * item) override;
    BaseItem * get(ItemType itemType) override;
    string toString() const override;
};
class PaladinBag : public BaseBag{
public:
    PaladinBag(BaseKnight * bk, int a, int b);
    ~PaladinBag();
    bool isFull() override;
    bool insertFirst(BaseItem * item) override;
    BaseItem * get(ItemType itemType) override;
    string toString() const override;
};
class NormalBag : public BaseBag{
public:
    NormalBag(BaseKnight * bk, int a, int b);
    ~NormalBag();
    bool isFull() override;
    bool insertFirst(BaseItem * item) override;
    BaseItem * get(ItemType itemType) override;
    string toString() const override;
};


class BaseOpponent{
protected:
    int event_id;
    int levelO;
    int baseDamage;
    int hold_gil; //so gil nắm giữ
public:
    int getEvent_id() const {return this->event_id;}
    int getLevelO() const {return this->levelO;}
    int getDamage() const {return this->baseDamage;}
    int getGil() const {return this->hold_gil;}
};
class Madbear : public BaseOpponent{
public:
    Madbear(int i){ //thứ tự sự kiên, bắt đầu bằng 0
        this->event_id = 1;
        this->levelO = (i+event_id)%10+1;
        this->baseDamage = 10;
        this->hold_gil = 100;
    }

};
class Bandit : public BaseOpponent{
public:
    Bandit(int i){
        this->event_id = 2;
        this->levelO = (i+event_id)%10+1;
        this->baseDamage = 15;
        this->hold_gil = 150;
    }

};
class LordLupin : public BaseOpponent{
public:
    LordLupin(int i){
        this->event_id = 3;
        this->levelO = (i+event_id)%10+1;
        this->baseDamage = 45;
        this->hold_gil = 450;
    }

};
class Elf : public BaseOpponent{
public:
    Elf(int i){
        this->event_id = 4;
        this->levelO = (i+event_id)%10+1;
        this->baseDamage = 75;
        this->hold_gil = 750;
    }

};
class Troll : public BaseOpponent{
public:
    Troll(int i){
        this->event_id = 5;
        this->levelO = (i+event_id)%10+1;
        this->baseDamage = 95;
        this->hold_gil = 800;
    }

};
class Tornbery : public BaseOpponent{
public:
    Tornbery(int i){
        this->event_id = 6;
        this->levelO = (i+event_id)%10+1;
    }


};
class QueenOfCards : public BaseOpponent{
public:
    QueenOfCards(int i){
        this->event_id = 7;
        this->levelO = (i+event_id)%10+1;

    }


};
class NinaDeRings : public BaseOpponent{
public:
    NinaDeRings(){
        this->event_id = 8;

    }


};
class DurianGarden : public BaseOpponent{
public:
    DurianGarden(){
        this->event_id = 9;
    }

};
class OmegaWeapon : public BaseOpponent{
public:
    OmegaWeapon(){
        this->event_id = 10;

    }


};
class Hades : public BaseOpponent{
public:
    Hades(){
        this->event_id = 11;

    }
};
class Ultimecia : public BaseOpponent{
public:
    Ultimecia(){
        this->event_id = 99;
    }
};
class Shield : public BaseOpponent{
public:
    Shield(){
        this->event_id = 95;
    }
};
class Spear : public BaseOpponent{
public:
    Spear(){
        this->event_id = 96;
    }
};
class Hair : public BaseOpponent{
public:
    Hair(){
        this->event_id = 97;
    }
};
class Excalibur : public BaseOpponent{
public:
    Excalibur(){
        this->event_id = 98;
    }
};
class PDII : public BaseOpponent{
public:
    PDII(){
        this->event_id = 112;
    }
};
class PDIII : public BaseOpponent{
public:
    PDIII(){
        this->event_id = 113;
    }
};
class PDIV : public BaseOpponent{
public:
    PDIV(){
        this->event_id = 114;
    }
};
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    bool isPoison = false ;
    BaseBag * bag;
    KnightType knightType;

public:
    void setId(int i) {this->id=i;}
    void setHP(int h) {this->hp=h;}
    void setLevel(int l) {this->level=l;}
    void setGil (int g) {this->gil=g;}
    void setPoison (bool t) {this->isPoison = t;}
    void setKnightType (KnightType k) {this->knightType = k;}
    int getId() const {return id;}
    int getHp() const {return hp;}
    int getMaxhp() const {return maxhp;}
    int getLevel() const {return level;}
    int getGil() const  {return gil;}
    bool getIsPoison() const {return isPoison;}

    BaseBag *getBag() const {return bag;}
    KnightType getKnightType() const    {return knightType;}
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;

};
class PaladinKnight : public BaseKnight{
public:
    PaladinKnight() { id = 0; hp = 0; maxhp = 0; level = 0; gil = 0; }

};
class LancelotKnight : public BaseKnight{
public:
    LancelotKnight() { id = 0; hp = 0; maxhp = 0; level = 0; gil = 0; }

};
class DragronKnight : public BaseKnight{
public:
    DragronKnight() { id = 0; hp = 0; maxhp = 0; level = 0; gil = 0; }
  
};
class NormalKnight : public BaseKnight{
public:
    NormalKnight() { id = 0; hp = 0; maxhp = 0; level = 0; gil = 0; }
};
class Events {
public:
    int n_events; //số lượng sự kiện (dòng đầu trong file)
    int *arr_events; //mảng sự kiện
    Events(const string & file_events){
        readData_Events(file_events, n_events, arr_events);
    }
    ~Events(){
        delete[] arr_events;
    }
    int count() const{
        return n_events;
    }
    int get(int i) const{
        return arr_events[i];
    }
};
class ArmyKnights {
public:
    int n_knights;
    BaseKnight **army_knights;
    int **mat_army; //ma trận lấy từ file
    bool isOmega = false; // sự kiện gặp Omega Weapon
    bool isHades = false; //sự kiện gặp thần chết Hades
    bool shield = false; // khiên của Paladin
    bool sword = false; //gươm Excalibur
    bool spear = false; //giáo của Lancelot
    bool hair = false; //tóc của công chúa
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);
    bool adventure (Events *events);
    int count() const;
    BaseKnight * lastKnight() const;

    bool hasPaladinShield() const {return shield;}
    bool hasLancelotSpear() const {return spear;}
    bool hasGuinevereHair() const {return hair;}
    bool hasExcaliburSword() const {return sword;}

    void printInfo() const;
    void printResult(bool win) const;
};



class Antidote : public BaseItem{
public:

    Antidote() : BaseItem(ItemType::Anti){}
    bool canUse (BaseKnight * knight) override{
        if(knight->getIsPoison()){
            return true;
        }
        else false;
    }
    void use (BaseKnight * knight) override {
        knight->setPoison(false);
    }

};
class PhoenixDownI : public BaseItem{
public:
    PhoenixDownI() : BaseItem(ItemType::PhoenixI){}
    bool canUse ( BaseKnight * knight ) override{
        if(knight->getHp()<=0)
            return true;
        else return false;
    }
    void use ( BaseKnight * knight ) override{
        knight->setHP(knight->getMaxhp());
    }

};
class PhoenixDownII : public BaseItem{
public:
    PhoenixDownII() : BaseItem(ItemType::PhoenixII){}
    bool canUse ( BaseKnight * knight ) override{
        if((knight->getHp())<(knight->getMaxhp()/4))
            return true;
        else return false;
    }
    void use ( BaseKnight * knight ) override{
        knight->setHP(knight->getMaxhp());
    }

};
class PhoenixDownIII : public BaseItem{
public:
    PhoenixDownIII() : BaseItem(ItemType::PhoenixIII){}
     bool canUse ( BaseKnight * knight ) override{
        if((knight->getHp())<(knight->getMaxhp()/3))
            return true;
        else return false;
    }
    void use ( BaseKnight * knight ) override{
        if(knight->getHp()<=0)
            knight->setHP(knight->getMaxhp()/3);
        else knight->setHP((knight->getMaxhp()/4)+knight->getHp());
    }
};
class PhoenixDownIV : public BaseItem{
public:
    PhoenixDownIV() : BaseItem(ItemType::PhoenixIV){}
    bool canUse ( BaseKnight * knight ) override{
        if((knight->getHp())<(knight->getMaxhp()/2))
            return true;
        else return false;
    }
    void use ( BaseKnight * knight ) override{
        if(knight->getHp()<=0)
            knight->setHP(knight->getMaxhp()/2);
        else knight->setHP((knight->getMaxhp()/5)+knight->getHp());
    }
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string & file_armyknights);
    void loadEvents(const string & file_events);
    void run();
};

#endif // __KNIGHT2_H__
