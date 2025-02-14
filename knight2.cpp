#include "knight2.h"
void readData_Events(const string& fileName, int& n, int*& arr) {
    ifstream file;
    file.open(fileName);
    if (file.is_open()) {
        file >> n;


        arr = new int[n];


        for (int i = 0; i < n; i++) {
            file >> arr[i];
        }

       
    } else {
        cout << "Khong the mo file " << fileName << " de doc du lieu!" << endl;
    }
    file.close();
}
void readData_Army(const string &fileName, int &n, int **&army){
    ifstream file;
    file.open(fileName);
    if(file.is_open()){
    file >> n;
    army = new int*[n];

    for(int i=0 ; i<n ; i++)
        army[i] = new int[5];


    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<5 ; j++)
            file >> army[i][j];
    }
    else {
        cout<<"Khong the mo file "<<fileName<<" de doc du lieu!"<<endl;
    }
    file.close();
}
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
bool isPythagorasTriplet(int n){
    int a,b,c;
    if(n<100 || n>999) return false;
    else{
        a = n%10;
        n = n/10;
        b = n%10;
        c = n/10;
    }
    return ((pow(a,2) == pow(b,2) + pow(c,2)) || (pow(b,2) == pow(a,2) + pow(c,2)) || (pow(c,2) == pow(b,2) + pow(a,2)));
}
/* * * BEGIN implementation of class BaseBag * * */
//DragronBag class's method
DragonBag::DragonBag(BaseKnight * bk, int a,int b){
        n_bag = 0;
        if(a<=0){
            node = nullptr;
        }
        else{
        node = new Node();
        node->next = nullptr;
        node->item = ItemType::PhoenixI;
        Node * curr = node;
        n_bag++;
        if(a>1){
        for(int i=0;i<a-1;i++){
            if(n_bag==5)
                return;
            else{
            Node * n = new Node();
            n->item = ItemType::PhoenixI;
            n->next = nullptr;
            curr->next = n;
            curr = n;
            n_bag++;
            }
        }
        }
        }
}
DragonBag::~DragonBag() {
    Node* curr = node;
    while (curr != nullptr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}
 bool DragonBag::isFull() {
     if (this->getN_Bag() == 14)
         return true;
     else return false;
 }
bool DragonBag::insertFirst(BaseItem * item){
     if(this->getN_Bag()>=14) //túi đồ của kỵ sĩ rồng chỉ chứa được 14 món
            return false;
        else{
            Node * n = new Node();
            n->item = item->type;
            n->next = node;
            node = n;
            n_bag++;
            return true;
        }
}
BaseItem * DragonBag::get(ItemType itemType){
        Node * curr = node;
        while(curr!=nullptr){
            if(curr->item == itemType){
                ItemType t = curr->item;
                curr->item = node->item;
                node->item = t;
                Node * n = node->next;
                delete node;
                node = n;
                n_bag--;
                if(itemType == 0)
                    return new Antidote();
                else if(itemType == 1)
                    return new PhoenixDownI();
                else if(itemType == 2)
                    return new PhoenixDownII();
                else if(itemType == 3)
                    return new PhoenixDownIII();
                else return new PhoenixDownIV();
            }
            curr = curr->next;
        }
        return nullptr;
}
string DragonBag::toString() const{
    string s("");
    stringstream t;
    t<<n_bag;
    s+= "Bag[count=" + t.str() + ";";
    Node * curr = node;
    while(curr!=nullptr){
        if(curr->item == 0)
            s+="Antidote,";
        else if(curr->item == 1)
            s+="PhoenixI,";
        else if(curr->item == 2)
            s+="PhoenixII,";
        else if(curr->item == 3)
            s+="PhoenixIII,";
        else s+="PhoenixIV,";
        curr = curr->next;
    }
    if(!s.empty() && s.substr(s.length()-1)!=";")
        s.erase(s.size()-1);
    s+="]";
    return s;
}

//LancelotBag class'method
LancelotBag::LancelotBag(BaseKnight * bk, int a, int b){
        n_bag = 0;
        if(a<=0 && b<=0){
            node = nullptr;
        }
        else{
        if(a<=0){
        node = new Node();
        node->next = nullptr;
        node->item = ItemType::Anti;
        Node * curr = node;
        n_bag++;
        if(b>1){
        for(int i=0;i<b-1;i++){
            if(n_bag==5)
                return;
            else{
            Node * n = new Node();
            n->item = ItemType::Anti;
            n->next = nullptr;
            curr->next = n;
            curr = n;
            n_bag++;
            }
        }
        }
        }
        else{
        node = new Node();
        node->next = nullptr;
        node->item = ItemType::PhoenixI;
        Node * curr = node;
        n_bag++;
        if(a>1){
        for(int i=0;i<a-1;i++){
            if(n_bag==5)
                break;
            else{
            Node * n = new Node();
            n->item = ItemType::PhoenixI;
            n->next = nullptr;
            curr->next = n;
            curr = n;
            n_bag++;
            }
        }
        }
        for(int i=0;i<b;i++){
            if(n_bag==10)
                break;
            else insertFirst(new Antidote());
        }
        }
        }
}
LancelotBag::~LancelotBag() {
    Node* curr = node;
    while (curr != nullptr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}
bool LancelotBag::isFull(){
     if(this->getN_Bag()==16)
        return true;
     else return false;
}
bool LancelotBag::insertFirst(BaseItem * item){
        if(this->getN_Bag()>=16) //túi đồ của kỵ sĩ Lancelot chỉ chứa được 16 món
            return false;
        else{
            Node * n = new Node();
            n->item = item->type;
            n->next = node;
            node = n;
            n_bag++;
            return true;
        }
}
BaseItem * LancelotBag::get(ItemType itemType){
        Node * curr = node;
        while(curr!=nullptr){
            if(curr->item == itemType){
                ItemType t = curr->item;
                curr->item = node->item;
                node->item = t;
                Node * n = node->next;
                delete node;
                node = n;
                n_bag--;
                if(itemType == 0)
                    return new Antidote();
                else if(itemType == 1)
                    return new PhoenixDownI();
                else if(itemType == 2)
                    return new PhoenixDownII();
                else if(itemType == 3)
                    return new PhoenixDownIII();
                else return new PhoenixDownIV();
            }
            curr = curr->next;
        }
        return nullptr;
}
string LancelotBag::toString() const{
    string s("");
    stringstream t;
    t<<n_bag;
    s+= "Bag[count=" + t.str() + ";";
    Node * curr = node;
    while(curr!=nullptr){
        if(curr->item == 0)
            s+="Antidote,";
        else if(curr->item == 1)
            s+="PhoenixI,";
        else if(curr->item == 2)
            s+="PhoenixII,";
        else if(curr->item == 3)
            s+="PhoenixIII,";
        else s+="PhoenixIV,";
        curr = curr->next;
    }
    if(!s.empty() && s.substr(s.length()-1)!=";")
        s.erase(s.size()-1);
    s+="]";
    return s;
}
//PaladinBag class's method
PaladinBag::PaladinBag(BaseKnight * bk, int a, int b){
        n_bag = 0;
        if(a<=0 && b<=0){
            node = nullptr;
        }
        else{
        if(a<=0){
        node = new Node();
        node->next = nullptr;
        node->item = ItemType::Anti;
        Node * curr = node;
        n_bag++;
        if(b>1){
        for(int i=0;i<b-1;i++){
            if(n_bag==5)
                return;
            else{
            Node * n = new Node();
            n->item = ItemType::Anti;
            n->next = nullptr;
            curr->next = n;
            curr = n;
            n_bag++;
            }
        }
        }
        }
        else{
        node = new Node();
        node->next = nullptr;
        node->item = ItemType::PhoenixI;
        Node * curr = node;
        n_bag++;
        if(a>1){
        for(int i=0;i<a-1;i++){
            if(n_bag==5)
                break;
            else{
            Node * n = new Node();
            n->item = ItemType::PhoenixI;
            n->next = nullptr;
            curr->next = n;
            curr = n;
            n_bag++;
            }
        }
        }
        for(int i=0;i<b;i++){
            if(n_bag==10)
                break;
            else insertFirst(new Antidote());
        }
        }
        }
}
PaladinBag::~PaladinBag() {
    Node* curr = node;
    while (curr != nullptr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}
 bool PaladinBag::isFull(){
     return false;
}
bool PaladinBag::insertFirst(BaseItem * item){
    //túi đồ của kỵ sĩ Paladin chứa được vô hạn
    Node * n = new Node();
    n->item = item->type;
    n->next = node;
    node = n;
    n_bag++;
    return true;
}
BaseItem * PaladinBag::get(ItemType itemType){
        Node * curr = node;
        while(curr!=nullptr){
            if(curr->item == itemType){
                ItemType t = curr->item;
                curr->item = node->item;
                node->item = t;
                Node * n = node->next;
                delete node;
                node = n;
                n_bag--;
                if(itemType == 0)
                    return new Antidote();
                else if(itemType == 1)
                    return new PhoenixDownI();
                else if(itemType == 2)
                    return new PhoenixDownII();
                else if(itemType == 3)
                    return new PhoenixDownIII();
                else return new PhoenixDownIV();
            }
            curr = curr->next;
        }
        return nullptr;
}

string PaladinBag::toString() const{
    string s("");
    stringstream t;
    t<<n_bag;
    s+= "Bag[count=" + t.str() + ";";
    Node * curr = node;
    while(curr!=nullptr){
        if(curr->item == 0)
            s+="Antidote,";
        else if(curr->item == 1)
            s+="PhoenixI,";
        else if(curr->item == 2)
            s+="PhoenixII,";
        else if(curr->item == 3)
            s+="PhoenixIII,";
        else s+="PhoenixIV,";
        curr = curr->next;
    }
    if(!s.empty() && s.substr(s.length()-1)!=";")
        s.erase(s.size()-1);
    s+="]";
    return s;
}
//NormalBag class's method
NormalBag::NormalBag(BaseKnight * bk, int a, int b){
        n_bag = 0;
        if(a<=0 && b<=0){
            node = nullptr;
        }
        else{
        if(a<=0){
        node = new Node();
        node->next = nullptr;
        node->item = ItemType::Anti;
        Node * curr = node;
        n_bag++;
        if(b>1){
        for(int i=0;i<b-1;i++){
            if(n_bag==5)
                return;
            else{
            Node * n = new Node();
            n->item = ItemType::Anti;
            n->next = nullptr;
            curr->next = n;
            curr = n;
            n_bag++;
            }
        }
        }
        }
        else{
        node = new Node();
        node->next = nullptr;
        node->item = ItemType::PhoenixI;
        Node * curr = node;
        n_bag++;
        if(a>1){
        for(int i=0;i<a-1;i++){
            if(n_bag==5)
                break;
            else{
            Node * n = new Node();
            n->item = ItemType::PhoenixI;
            n->next = nullptr;
            curr->next = n;
            curr = n;
            n_bag++;
            }
        }
        }
        for(int i=0;i<b;i++){
            if(n_bag==10)
                break;
            else insertFirst(new Antidote());
        }
        }
        }
}
NormalBag::~NormalBag() {
    Node* curr = node;
    while (curr != nullptr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}
bool NormalBag::isFull(){
     if(this->getN_Bag()==19)
        return true;
     else return false;
}
bool NormalBag::insertFirst(BaseItem * item){
        if(this->getN_Bag()>=19) //túi đồ của kỵ sĩ thường chỉ chứa được 19 món
            return false;
        else{
            Node * n = new Node();
            n->item = item->type;
            n->next = node;
            node = n;
            n_bag++;
            return true;
        }
}
BaseItem * NormalBag::get(ItemType itemType){
        Node * curr = node;
        while(curr!=nullptr){
            if(curr->item == itemType){
                ItemType t = curr->item;
                curr->item = node->item;
                node->item = t;
                Node * n = node->next;
                delete node;
                node = n;
                n_bag--;
                if(itemType == 0)
                    return new Antidote();
                else if(itemType == 1)
                    return new PhoenixDownI();
                else if(itemType == 2)
                    return new PhoenixDownII();
                else if(itemType == 3)
                    return new PhoenixDownIII();
                else return new PhoenixDownIV();
            }
            curr = curr->next;
        }
        return nullptr;
}
string NormalBag::toString() const{
    string s("");
    stringstream t;
    t<<n_bag;
    s+= "Bag[count="  + t.str() + ";" ;
    Node * curr = node;
    while(curr!=nullptr){
        if(curr->item == 0)
            s+="Antidote,";
        else if(curr->item == 1)
            s+="PhoenixI,";
        else if(curr->item == 2)
            s+="PhoenixII,";
        else if(curr->item == 3)
            s+="PhoenixIII,";
        else s+="PhoenixIV,";
        curr = curr->next;
    }
    if(!s.empty() && s.substr(s.length()-1)!=";")
        s.erase(s.size()-1);
    s+="]";
    return s;
}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    stringstream i, h, mh, l, g;
    i<<id;
    h<<hp;
    mh<<maxhp;
    l<<level;
    g<<gil;
    string s("");
    s += "[Knight:id:" + i.str()
        + ",hp:" + h.str()
        + ",maxhp:" + mh.str()
        + ",level:" + l.str()
        + ",gil:" + g.str()
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    if (isPrime(maxhp)) {
        PaladinKnight* pk = new PaladinKnight();
        pk->id = id;
        pk->maxhp = maxhp;
        pk->hp = maxhp;
        pk->level = level;
        pk->gil = gil;
        pk->bag = new PaladinBag(pk, phoenixdownI, antidote);
        pk->knightType = KnightType::PALADIN;
        return pk;
    }
    else if(maxhp==888)
    {
        LancelotKnight* lk = new LancelotKnight();
        lk->id = id;
        lk->maxhp = maxhp;
        lk->hp = maxhp;
        lk->level = level;
        lk->gil = gil;
        lk->bag = new LancelotBag(lk, phoenixdownI, antidote);
        lk->knightType = KnightType::LANCELOT;
        return lk;
    }
    else if (isPythagorasTriplet(maxhp)) {
        DragronKnight* dk = new DragronKnight();
        dk->id = id;
        dk->maxhp = maxhp;
        dk->hp = maxhp;
        dk->level = level;
        dk->gil = gil;
        dk->bag = new DragonBag(dk, phoenixdownI, antidote);
        dk->knightType = KnightType::DRAGON;
        return dk;
    }
    else
    {
        NormalKnight* nk = new NormalKnight();
        nk->id = id;
        nk->maxhp = maxhp;
        nk->hp = maxhp;
        nk->level = level;
        nk->gil = gil;
        nk->bag = new NormalBag(nk, phoenixdownI, antidote);
        nk->knightType = KnightType::NORMAL;
        return nk;
    }
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

ArmyKnights::ArmyKnights(const string & file_armyknights){
    readData_Army(file_armyknights, n_knights, mat_army);
    army_knights = new BaseKnight*[n_knights];
    for(int i=0;i<n_knights;i++){
         army_knights[i] = BaseKnight::create(i+1,mat_army[i][0],mat_army[i][1],mat_army[i][3],mat_army[i][4],mat_army[i][2]);
    }
}
 ArmyKnights::~ArmyKnights(){
     for(int i=0;i<n_knights;i++){
        delete army_knights[i];
        delete mat_army[i];
     }
     delete[] army_knights;
     delete[] mat_army;
 }
bool ArmyKnights::fight(BaseOpponent * opponent){
     if (lastKnight() == nullptr)
        return false;
     else
        {
        if(opponent->getEvent_id()>=1 && opponent->getEvent_id()<=5){//bat dau su kien tu 1->5
            if(lastKnight()->getKnightType()==KnightType::LANCELOT || lastKnight()->getKnightType()==KnightType::PALADIN || lastKnight()->getLevel()>=opponent->getLevelO()){
                if(lastKnight()->getGil()<999){
                    int g = lastKnight()->getGil()+opponent->getGil();
                    if (g >= 999)
                        lastKnight()->setGil(999);
                    else{ lastKnight()->setGil(g);}
                }
                return true;
        }
        else{//xử lý khi thua
            int h = lastKnight()->getHp() - opponent->getDamage()*(opponent->getLevelO()-lastKnight()->getLevel());
            lastKnight()->setHP(h);
            if(lastKnight()->getHp()<=0){
                Node * curr = lastKnight()->getBag()->getHead_Node();
                while(curr!=nullptr){
                    if(curr->item!=ItemType::Anti){
                        BaseItem * tempI = lastKnight()->getBag()->get(curr->item);// lấy ra
                        if(tempI!=nullptr){
                            if (tempI->canUse(lastKnight())) {
                                tempI->use(lastKnight());
                                delete tempI;
                                return true;
                            }
                            else {
                                lastKnight()->getBag()->insertFirst(tempI);// bỏ vào lại nêu không sử dụng được
                            }
                        }
                        
                    }
                    curr = curr->next;
                }
                delete curr;
                if(lastKnight()->getGil()>=100){
                    lastKnight()->setHP(lastKnight()->getMaxhp()/2);
                    lastKnight()->setGil(lastKnight()->getGil()-100);
                    return true;
                }
                else {
                    lastKnight()->setHP(0);
                    return false;
                }
                }
            }
         }//ket thuc su kien tu 1->5
         else if(opponent->getEvent_id()==6){// bắt đầu sự kiện Tornbery
             if(lastKnight()->getLevel()>=opponent->getLevelO()){// thắng Tornbery
                 if(lastKnight()->getLevel()<10)
                    lastKnight()->setLevel(lastKnight()->getLevel()+1);
                 return true;
             }
             else{// thua Tornbery
                    if(lastKnight()->getKnightType() == KnightType::DRAGON)
                        return true;
                    else {
                        lastKnight()->setPoison(true);
                        BaseItem * tempI = lastKnight()->getBag()->get(ItemType::Anti);
                        if(tempI!=nullptr) {
                            tempI->use(lastKnight());
                            delete tempI;
                            return true;
                        }
                        else{// làm rơi 3 túi đồ
                            if(lastKnight()->getBag()->getN_Bag()<=3){
                               Node * curr =  lastKnight()->getBag()->getHead_Node();
                               
                               while(curr!=nullptr){
                                    Node* t = curr;
                                    curr = curr->next;
                                    delete t;
                               }
                               lastKnight()->getBag()->setHead_Node(nullptr);
                               lastKnight()->getBag()->setN_Bag(0);
                               delete curr;
                            }
                            else{
                            Node * curr = lastKnight()->getBag()->getHead_Node()->next;
                            delete lastKnight()->getBag()->getHead_Node();
                            lastKnight()->getBag()->setHead_Node(curr);//rơi 1 túi

                            curr = lastKnight()->getBag()->getHead_Node()->next;
                            delete lastKnight()->getBag()->getHead_Node();
                            lastKnight()->getBag()->setHead_Node(curr);//rơi túi thứ 2

                            curr = lastKnight()->getBag()->getHead_Node()->next;
                            delete lastKnight()->getBag()->getHead_Node();
                            lastKnight()->getBag()->setHead_Node(curr);//rơi túi thứ 3
                            delete curr;
                            lastKnight()->getBag()->setN_Bag(lastKnight()->getBag()->getN_Bag() - 3);
                            }
                            //giảm HP đi 10 đơn vị
                            int h = lastKnight()->getHp() - 10;
                            lastKnight()->setHP(h);
                            if(lastKnight()->getHp()<=0){
                                Node * curr = lastKnight()->getBag()->getHead_Node();
                                while(curr!=nullptr){
                                    if(curr->item!=ItemType::Anti){
                                        BaseItem * tempIt = lastKnight()->getBag()->get(curr->item);// lấy ra
                                        if(tempIt!=nullptr){
                                            if (tempIt->canUse(lastKnight())) {
                                                tempI->use(lastKnight());
                                                delete tempIt;
                                                return true;
                                            }
                                            else {
                                                lastKnight()->getBag()->insertFirst(tempIt);// bỏ vào lại nêu không sử dụng được
                                            }
                                        }
                                        
                                    }
                                    curr = curr->next;
                                }
                                delete curr;
                                if(lastKnight()->getGil()>=100){
                                    lastKnight()->setHP(lastKnight()->getMaxhp()/2);
                                    lastKnight()->setGil(lastKnight()->getGil()-100);
                                    return true;
                                }
                                else {
                                    lastKnight()->setHP(0);
                                    return false;
                                }
                            }
                        }

                    }
             }
         }//Kết thúc sự kiện Tornbery
         //Bắt đầu sự kiện Queen of Cards
         else if(opponent->getEvent_id() == 7){
                if(lastKnight()->getLevel()>=opponent->getLevelO()){// thắng
                    int ward = lastKnight()->getGil()*2;
                    int rem = 0;
                    if(ward>999){
                        lastKnight()->setGil(999);
                        rem = ward - 999;
                        int dem = 2; // dem số knight trong đội quân
                        while(rem>0 && dem <= count()){
                            if(army_knights[count()-dem]->getGil()+rem>=999){
                                army_knights[count()-dem]->setGil(999);
                                rem = rem - (999-army_knights[count()-dem]->getGil());
                            }
                            else{army_knights[count()-dem]->setGil(army_knights[count()-dem]->getGil()+rem);}
                            dem++;
                        }

                    }
                    else{lastKnight()->setGil(ward);}
                    return true;
                }
                else{//thua
                        if(lastKnight()->getKnightType()==KnightType::PALADIN)
                            return true;
                        lastKnight()->setGil(lastKnight()->getGil()/2);
                        return false;
                }
         }//kết thúc sự kiện Queen of Cards
         //Bắt đầu sự kiện Nina de Rings
         else if(opponent->getEvent_id() == 8){
            if(lastKnight()->getGil()<50){
                if(lastKnight()->getKnightType()==KnightType::PALADIN)
                    if(lastKnight()->getHp()<lastKnight()->getMaxhp()/3)
                        lastKnight()->setHP(lastKnight()->getHp()+lastKnight()->getMaxhp()/5);
                return true;
            }
            else{
                if(lastKnight()->getHp()<lastKnight()->getMaxhp()/3){
                    lastKnight()->setGil(lastKnight()->getGil()-50);
                    lastKnight()->setHP(lastKnight()->getHp()+lastKnight()->getMaxhp()/5);
                }
                return true;
            }
         }//kết thúc sự kiện Nina
         //Bắt đầu sự kiện vườn sầu riêng
         else if(opponent->getEvent_id()==9){
            lastKnight()->setHP(lastKnight()->getMaxhp());
            return true;
         }//kết thúc sự kiện vườn sầu riêng
         //Bắt đầu sự kiện Omega Weapon
         else if(opponent->getEvent_id()==10){
             if(isOmega)
                return true;//đã gặp Omega và bỏ qua
             else{
             if((lastKnight()->getKnightType()==KnightType::DRAGON) || (lastKnight()->getLevel()==10 && lastKnight()->getHp()==lastKnight()->getMaxhp())){//thắng omega weapon
                lastKnight()->setLevel(10);
                lastKnight()->setGil(999);
                isOmega = true;
                return true;
             }
             else{
                
                
                Node * curr = lastKnight()->getBag()->getHead_Node();
                while(curr!=nullptr){
                    if(curr->item!=ItemType::Anti){
                        BaseItem * tempI = lastKnight()->getBag()->get(curr->item);// lấy ra
                        if(tempI!=nullptr){
                            if (tempI->canUse(lastKnight())) {
                                tempI->use(lastKnight());
                                delete tempI;
                                isOmega = true;
                                delete curr;
                                return true;
                            }
                            else {
                                lastKnight()->getBag()->insertFirst(tempI);// bỏ vào lại nêu không sử dụng được
                            }
                        }
                        
                    }
                    curr = curr->next;
                }
                delete curr;
                if(lastKnight()->getGil()>=100){
                    lastKnight()->setHP(lastKnight()->getMaxhp()/2);
                    lastKnight()->setGil(lastKnight()->getGil()-100);
                    isOmega = true;
                    return true;
                }
                else {
                    lastKnight()->setHP(0);
                    return false;
                }
                
             }//ket thuc xu ly thua Omega
            }
         }//ket thuc su kien Omega
         //Bắt đầu sự kiên thần chết Hades
         else if(opponent->getEvent_id()==11){
                if(isHades)
                    return true;//đã gặp Hades
                else{//nếu chưa gặp sự kiện Hades
                        if(lastKnight()->getLevel()==10 || (lastKnight()->getKnightType()==KnightType::PALADIN && lastKnight()->getLevel()>=8)){//hiệp sĩ chiến thắng
                            if(hasPaladinShield()){
                                isHades = true;
                                return true;
                            }
                            else{
                                shield = true;
                                isHades = true;
                                return true;
                            }
                        }
                        else{//hiệp sĩ bại trận
                
                Node * curr = lastKnight()->getBag()->getHead_Node();
                while(curr!=nullptr){
                    if(curr->item!=ItemType::Anti){
                        BaseItem * tempI = lastKnight()->getBag()->get(curr->item);// lấy ra
                        if(tempI!=nullptr){
                            if (tempI->canUse(lastKnight())) {
                                tempI->use(lastKnight());
                                delete tempI;
                                isHades = true;
                                shield = true;
                                delete curr;
                                return true;
                            }
                            else {
                                lastKnight()->getBag()->insertFirst(tempI);// bỏ vào lại nêu không sử dụng được
                            }
                        }
                        
                    }
                    curr = curr->next;
                }
                delete curr;
                if(lastKnight()->getGil()>=100){
                    lastKnight()->setHP(lastKnight()->getMaxhp()/2);
                    lastKnight()->setGil(lastKnight()->getGil()-100);
                    isHades = true;
                    shield = true;
                    return true;
                }
                else {
                    lastKnight()->setHP(0);
                    return false;
                }
                
                        }
                }
         }//kết thúc sự kiện Hades
         //bắt đầu sự kiện Ultimecia
         else if(opponent->getEvent_id()==99){
                if(hasExcaliburSword())//có thanh gươm trong đá
                    return true;
                else if(hasPaladinShield() && hasGuinevereHair() && hasLancelotSpear()){// đủ 3 món bảo vật
                    int ulti_hp = 5000;
                    int i = 1;
                    int n = count();
                    while(ulti_hp>0 && i<=n){
                        if(army_knights[n-i]->getKnightType()==KnightType::DRAGON){
                            int damage = army_knights[n-i]->getHp()*army_knights[n-i]->getLevel()* 0.075;
                            ulti_hp-=damage;
                            if(ulti_hp<=0)
                                return true;
                            else army_knights[n-i]->setHP(0);
                        }
                        else if(army_knights[n-i]->getKnightType()==KnightType::LANCELOT){
                            int damage = army_knights[n-i]->getHp()*army_knights[n-i]->getLevel()* 0.05;
                            ulti_hp-=damage;
                            if(ulti_hp<=0)
                                return true;
                            else army_knights[n-i]->setHP(0);
                        }
                        else if(army_knights[n-i]->getKnightType()==KnightType::PALADIN){
                            int damage = army_knights[n-i]->getHp()*army_knights[n-i]->getLevel()* 0.06;
                            ulti_hp-=damage;
                            if(ulti_hp<=0)
                                return true;
                            else army_knights[n-i]->setHP(0);
                        }

                        i++;
                    }
                    n_knights = 0;
                    count();
                    return false;
                }
                else{// không đủ 3 món bảo vật -> thua
                        n_knights = 0;
                        count();
                        return false;
                }
         }//kết thúc sự kiện Ultimecia
         //bắt đầu sự kiện nhặt khiên Paladin
         else if(opponent->getEvent_id()==95){
            if(hasPaladinShield())
                return true;
            else {
                shield = true;
                return  true;
            }
         }//kết thúc sự kiện nhặt khiên Paladin
         //bắt đầu sự kiện nhặt ngọn giáo Lancelot
         else if(opponent->getEvent_id()==96){
            if(hasLancelotSpear())
                return true;
            else {
                spear = true;
                return  true;
            }
         }//kết thúc sự kiện nhặt ngọn giáo Lancelot
         //bắt đầu sự kiện nhặt tóc của công chúa
         else if(opponent->getEvent_id()==97){
            if(hasGuinevereHair())
                return true;
            else {
                hair = true;
                return  true;
            }
         }//kết thúc sự kiện nhặt ngọn giáo Lancelot
         //bắt đầu sự kiện nhặt thanh gươm trong đá
         else if(opponent->getEvent_id()==98){
            if(hasGuinevereHair() && hasLancelotSpear() && hasPaladinShield()){
                sword = true;
                return true;
            }
            else {
                return false;
            }
         }//kết thúc sự kiện thanh gươm trong đá
         //bắt đầu sự kiện nhặt nước mắt phượng hoàng loại 2
         else if(opponent->getEvent_id()==112){
            return lastKnight()->getBag()->insertFirst(new PhoenixDownII());
         }//kết thúc sự kiện nhặt nước mắt phượng hoàng loại 2
         //bắt đầu sự kiện nhặt nước mắt phượng hoàng loại 3
         else if(opponent->getEvent_id()==113){
            return lastKnight()->getBag()->insertFirst(new PhoenixDownIII());
         }//kết thúc sự kiện nhặt nước mắt phượng hoàng loại 3
         //bắt đầu sự kiện nhặt nước mắt phượng hoàng loại 4
         else if(opponent->getEvent_id()==114){
            return lastKnight()->getBag()->insertFirst(new PhoenixDownIV());
         }//kết thúc sự kiện nhặt nước mắt phượng hoàng loại 4
    }
    return true;
 }

bool ArmyKnights::adventure(Events *events){
        for(int i=0;i<events->n_events;i++){
        if(events->arr_events[i]==1){
            Madbear *md = new Madbear(i);
            this->fight(md);
            if(count()==0){
               printInfo();
               return false;
             }
            delete md;
        }
        else if(events->arr_events[i]==2){
            Bandit *bd = new Bandit(i);
            this->fight(bd);
                if(count()==0){
                    printInfo();
                    return false;
                }
            delete bd;
        }
        else if(events->arr_events[i]==3){
            LordLupin *lupin = new LordLupin(i);
            this->fight(lupin);
                if(count()==0){
                    printInfo();
                    return false;
                }
            delete lupin;
        }
        else if(events->arr_events[i]==4){
            Elf *elf = new Elf(i);
            this->fight(elf);
                if(count()==0){
                    printInfo();
                    return false;
                }
            delete elf;
        }
        else if(events->arr_events[i]==5){
            Troll *troll = new Troll(i);
            this->fight(troll);
                if(count()==0){
                    printInfo();
                    return false;
                }
            delete troll;
        }
        else if(events->arr_events[i]==6){
            Tornbery *torn = new Tornbery(i);
            this->fight(torn);
                if(count()==0){
                    printInfo();
                    return false;
                }
            delete torn;
        }
        else if(events->arr_events[i]==7){
            QueenOfCards *queen = new QueenOfCards(i);
            this->fight(queen);
            delete queen;
        }
        else if(events->arr_events[i]==8){
            NinaDeRings * nina = new NinaDeRings();
            this->fight(nina);
            delete nina;
        }
        else if(events->arr_events[i]==9){
            DurianGarden * duri = new DurianGarden();
            this->fight(duri);
            delete duri;
        }
        else if(events->arr_events[i]==10){
            OmegaWeapon * om = new OmegaWeapon();
            this->fight(om);
                if(count()==0){
                    printInfo();
                    printResult(false);
                    return false;
                }
            delete om;
        }
        else if(events->arr_events[i]==11){
            Hades * had = new Hades();
            this->fight(had);
                if(count()==0){
                    printInfo();
                    printResult(false);
                    return false;
                }
            delete had;
        }
        else if(events->arr_events[i]==99){
            Ultimecia * ulti = new Ultimecia();
            if(this->fight(ulti)){
                printInfo();
                printResult(true);
                delete ulti;
                return true;
            }
            else {
                printInfo();
                printResult(false);
                delete ulti;
                return false;
            }
        }
        else if(events->arr_events[i]==95){
            Shield * sh = new Shield();
            this->fight(sh);
            delete sh;

        }
        else if(events->arr_events[i]==96){
            Spear * sp = new Spear();
            this->fight(sp);
            delete sp;

        }
        else if(events->arr_events[i]==97){
            Hair * h = new Hair();
            this->fight(h);
            delete h;

        }
        else if(events->arr_events[i]==98){
            Excalibur * ex = new Excalibur();
            this->fight(ex);
            delete ex;
        }
        else if(events->arr_events[i]==112){
            PDII * pd2 = new PDII();
            this->fight(pd2);
            delete pd2;
        }
        else if(events->arr_events[i]==113){
            PDIII * pd3 = new PDIII();
            this->fight(pd3);
            delete pd3;
        }
        else if(events->arr_events[i]==114){
            PDIV * pd4 = new PDIV();
            this->fight(pd4);
            delete pd4;
        }
        printInfo();
    }

    return true;
}
int ArmyKnights::count() const{//dem so luong hiep si trong doi quan
    int c = 0;
    for(int i=0;i<n_knights;i++){
        if(army_knights[i]->getHp()!=0)
            c++;
    }
    return c;
}
BaseKnight * ArmyKnights::lastKnight() const{ //hiep si cuoi cung
    if(count()==0)
        return nullptr;
    else {
        return army_knights[count() - 1];
    }

}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
void KnightAdventure::loadArmyKnights(const string & file_armyknights){
    if (armyKnights != nullptr) {
        delete armyKnights;
    }
    armyKnights = new ArmyKnights(file_armyknights);
}
void KnightAdventure::loadEvents(const string & file_events){
    if (events != nullptr) {
        delete events;
    }
    events = new Events(file_events);
}
void KnightAdventure::run(){
    armyKnights->adventure(events);
}
KnightAdventure::~KnightAdventure(){
    delete armyKnights;
    delete events;
}
/* * * END implementation of class KnightAdventure * * */
