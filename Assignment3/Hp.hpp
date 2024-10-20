#ifndef HP
#define HP

class Hp {
    public:
        Hp(int healthpoints = 100);
        int getHp();
        void setHp(int hp);

        ~Hp();
    private:
        int healthpoints_;
};

#endif
