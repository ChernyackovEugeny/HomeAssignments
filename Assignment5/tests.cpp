/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
home assignment 5
*/

#include <gtest/gtest.h>

#include <iostream>
#include <sstream>
#include <vector>

#include "Autobots.hpp"
#include "Bbee.hpp"
#include "Deceptikon.hpp"
#include "Transformer.hpp"

TEST(TransformerTest, Transformer) {
    Transformer boop("BumbleBee", 10, 20, 30, 40);
    Gun bush("boom");
    EXPECT_EQ(boop.getHp(), 40);
    EXPECT_EQ(boop.getArmor(), 10);
    boop.setHp(100);
    EXPECT_EQ(boop.getHp(), 100);
    boop.setGun(&bush);
    EXPECT_EQ(boop.getGun(), "boom");
}

TEST(AutobotTest, Autobot) {
    Autobots beep("Miki", 10, 20, 30, 40, 91, 92);
    EXPECT_EQ(beep.getLabel(), "Miki");
    EXPECT_EQ(beep.getRarm(), 91);
    beep.setRarm(100);
    EXPECT_EQ(beep.getRarm(), 100);
}

TEST(DeceptikonTest, Deceptikon) {
    Deceptikon buck("Pop", 10, 20, 30, 40, 91, 92);
    EXPECT_EQ(buck.getLabel(), "Pop");
    EXPECT_EQ(buck.getRleg(), 91);
    buck.setRleg(100);
    EXPECT_EQ(buck.getRleg(), 100);
}

TEST(BbeeTest, Bbee) {
    Bbee be("Bbee", 10, 20, 30, 40, 91, 92);
    EXPECT_EQ(be.getLabel(), "Bbee");
    EXPECT_EQ(be.getRear(), 91);
    be.setRear(100);
    EXPECT_EQ(be.getRear(), 100);
}

TEST(VirtualTest, Vtest) {
    Transformer a;
    Autobots b;
    Transformer *p = &b;
    Transformer e, ee, eee;
    Autobots t, tt, ttt;
    Deceptikon y, yy, yyy;
    std::vector<Transformer *> q = {&e, &ee, &eee, &t, &tt, &ttt, &y, &yy, &yyy};

    std::ostringstream output;
    std::streambuf *oldcout = std::cout.rdbuf(output.rdbuf());

    a.Optransform();
    EXPECT_EQ(output.str(), "class Transformer -> Optransform\n");

    output.str("");

    b.Opfire();
    EXPECT_EQ(output.str(), "class Autobots -> Opfire\n");

    output.str("");
    p->Opfire();
    EXPECT_EQ(output.str(), "class Autobots -> Opfire\n");

    for (int i = 0; i < int(q.size()); i++) {
        output.str("");
        q[i]->Opfire();
        if (i < 3) {
            EXPECT_EQ(output.str(), "class Transformer -> Opfire\n");
        } else if (i >= 3 && i < 6) {
            EXPECT_EQ(output.str(), "class Autobots -> Opfire\n");
        } else if (i >= 6) {
            EXPECT_EQ(output.str(), "class Deceptikon -> Opfire\n");
        }
    }

    std::cout.rdbuf(oldcout);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
