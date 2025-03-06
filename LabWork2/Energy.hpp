/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#ifndef ENERGY
#define ENERGY

#include <chrono>

class Game;

/**
 * @brief class describes the player's energy
 */
class Energy {
    friend class Game;

  public:
    Energy();
    ~Energy();

  protected:
    void change_energy(std::chrono::steady_clock::time_point last_time);

    double cur_energy_;
    double energy_psecond_;
    int energy_mult_;
};

#endif
