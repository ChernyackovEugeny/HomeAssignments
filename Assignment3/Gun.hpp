#ifndef GUN
#define GUN

class Gun {
	public:
	    Gun();
	    void setGun(std::string gun);
	    std::string getGun();
	    ~Gun();
	private:
	    std::string gun_name_
};

#endif

