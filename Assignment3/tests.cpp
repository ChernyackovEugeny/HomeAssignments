// tests

#include <gtest/gtest.h>
#include <iostream>
#include "Transformer.hpp"
#include "Autobots.hpp"
#include "Bbee.hpp"
#include "Deceptikon.hpp"

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
