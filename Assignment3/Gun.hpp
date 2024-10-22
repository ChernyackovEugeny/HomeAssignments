#ifndef GUN
#define GUN
#include <string>
class Gun {
	public:
	    Gun(std::string name);
	    void setGun(std::string gun);
	    std::string getGun();
	    ~Gun();
	private:
	    std::string gun_name_;
};

#endif

