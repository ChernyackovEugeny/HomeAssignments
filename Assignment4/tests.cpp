// tests

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Transformer.hpp"
#include "Autobots.hpp"
#include "Bbee.hpp"
#include "Deceptikon.hpp"
#include "opers.hpp"

TEST(TransformerTest, Transformer)
{
    Transformer boop("BumbleBee", 10, 20, 30, 40);
    Gun bush("boom");
    EXPECT_EQ(boop.getHp(), 40);
    EXPECT_EQ(boop.getArmor(), 10);
    boop.setHp(100);
    EXPECT_EQ(boop.getHp(), 100);
    boop.setGun(&bush);
    EXPECT_EQ(boop.getGun(), "boom");
}

TEST(AutobotTest, Autobot)
{
    Autobots beep("Miki", 10, 20, 30, 40, 91, 92);
    EXPECT_EQ(beep.getLabel(), "Miki");
    EXPECT_EQ(beep.getRarm(), 91);
    beep.setRarm(100);
    EXPECT_EQ(beep.getRarm(), 100);
}

TEST(DeceptikonTest, Deceptikon)
{
    Deceptikon buck("Pop", 10, 20, 30, 40, 91, 92);
    EXPECT_EQ(buck.getLabel(), "Pop");
    EXPECT_EQ(buck.getRleg(), 91);
    buck.setRleg(100);
    EXPECT_EQ(buck.getRleg(), 100);
}

TEST(BbeeTest, Bbee)
{
    Bbee be("Bbee", 10, 20, 30, 40, 91, 92);
    EXPECT_EQ(be.getLabel(), "Bbee");
    EXPECT_EQ(be.getRear(), 91);
    be.setRear(100);
    EXPECT_EQ(be.getRear(), 100);
}

TEST(OperatorcoutTest, Cout)
{
    Transformer bub("BumbleBee", 10, 20, 30, 40);

    std::ostringstream output;
    std::streambuf* oldcout = std::cout.rdbuf(output.rdbuf());

    std::cout << bub;

    std::cout.rdbuf(oldcout);
    EXPECT_EQ(output.str(), "BumbleBee");
}

TEST(OperatorequalTest, Equal)
{
    Transformer bub("BumbleBee", 10, 20, 30, 40);
    Transformer err("Bee", 10, 20, 30, 100);

    EXPECT_EQ(bub < err, true);
    EXPECT_EQ(err >= bub, true);
}

TEST(ConstructorTest, Construct)
{
    Transformer f(true);
    EXPECT_EQ(f.getLabel(), "Dead");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
