#include "gtest/gtest.h"
#include "MiniPlayer.hpp"
#include "MiniAbility.hpp"
#include "MiniEffect.hpp"

// Test the constructor and getters
TEST(MiniAbilityTest, ConstructorTest) {
    // Create an ability with name "Fireball", damage 50, and mana cost 20
    MiniAbility ability("Fireball", 50, 20);
    
    // Check that the name, damage, and mana cost are correctly set
    EXPECT_EQ(ability.getName(), "Fireball");
    EXPECT_EQ(ability.getDamage(), 50);
    EXPECT_EQ(ability.getManaCost(), 20);
}

// Test getters with different values
TEST(MiniAbilityTest, GettersTest) {
    // Create an ability with name "Ice Blast", damage 40, and mana cost 15
    MiniAbility ability2("Ice Blast", 40, 15);
    
    // Verify that the getters return the correct values
    EXPECT_EQ(ability2.getName(), "Ice Blast");
    EXPECT_EQ(ability2.getDamage(), 40);
    EXPECT_EQ(ability2.getManaCost(), 15);
}

// Test getters with empty values (edge case)
TEST(MiniAbilityTest, EmptyStringTest) {
    // Create an ability with an empty name, 0 damage, and 0 mana cost
    MiniAbility ability3("", 0, 0);
    
    // Check that the empty string is handled correctly
    EXPECT_EQ(ability3.getName(), "");
    EXPECT_EQ(ability3.getDamage(), 0);
    EXPECT_EQ(ability3.getManaCost(), 0);
}

// Test negative values for damage and mana cost
TEST(MiniAbilityTest, NegativeValuesTest) {
    // Create an ability with name "Shadow Strike", negative damage and mana cost
    MiniAbility ability4("Shadow Strike", -10, -5);
    
    // Verify that negative values are correctly returned
    EXPECT_EQ(ability4.getName(), "Shadow Strike");
    EXPECT_EQ(ability4.getDamage(), -10);
    EXPECT_EQ(ability4.getManaCost(), -5);
}

// Test zero values for damage and mana cost
TEST(MiniAbilityTest, ZeroValuesTest) {
    // Create an ability with name "Heal", 0 damage, and 0 mana cost
    MiniAbility ability5("Heal", 0, 0);
    
    // Verify that zero values are correctly handled
    EXPECT_EQ(ability5.getName(), "Heal");
    EXPECT_EQ(ability5.getDamage(), 0);
    EXPECT_EQ(ability5.getManaCost(), 0);
}

// Test for the constructor and getter methods
TEST(MiniPlayerTest, ConstructorAndGettersTest) {
    // Create a player with name "Hero", mana 100, and HP 200
    MiniPlayer player("Hero", 100, 200);
    
    // Verify that the constructor initializes the player correctly
    EXPECT_EQ(player.getName(), "Hero");
    EXPECT_EQ(player.getMana(), 100);
    EXPECT_EQ(player.getHP(), 200);
}

// Test adding abilities to the player
TEST(MiniPlayerTest, AddAbilityTest) {
    MiniPlayer player("Hero", 100, 200);
    MiniAbility ability("Fireball", 50, 20);
    
    // Add an ability to the player
    player.addAbility(ability);
    
    // Verify that the player now has 1 ability
    EXPECT_EQ(player.getAbilities().size(), 1);
    EXPECT_EQ(player.getAbilities()[0].getName(), "Fireball");
}

// Test using an ability when the player has enough mana
TEST(MiniPlayerTest, UseAbilityWithSufficientManaTest) {
    MiniPlayer player("Hero", 100, 200);
    MiniAbility ability("Fireball", 50, 20);
    player.addAbility(ability);
    
    // Use the ability
    player.useAbility(0, player);
    
    // Verify that the mana is correctly reduced
    EXPECT_EQ(player.getMana(), 80);  // Mana should be reduced by 20 (the mana cost of Fireball)
}

// Test using an ability when the player does not have enough mana
TEST(MiniPlayerTest, UseAbilityWithInsufficientManaTest) {
    MiniPlayer player("Hero", 10, 200);  // Not enough mana
    MiniAbility ability("Fireball", 50, 20);
    player.addAbility(ability);
    
    // Try to use the ability
    player.useAbility(0, player);
    
    // Verify that the mana was not reduced and a message is printed
    EXPECT_EQ(player.getMana(), 10);  // Mana should still be 10
}

// Test the takeDamage method
TEST(MiniPlayerTest, TakeDamageTest) {
    MiniPlayer player("Hero", 100, 200);
    
    // Apply damage to the player
    player.takeDamage(50);
    
    // Verify that the HP is reduced correctly
    EXPECT_EQ(player.getHP(), 150);
    
    // Apply damage that reduces HP to 0
    player.takeDamage(200);
    
    // Verify that the HP does not go below 0
    EXPECT_EQ(player.getHP(), 0);
}

// Test using an invalid ability index (out of bounds)
TEST(MiniPlayerTest, UseAbilityWithInvalidIndexTest) {
    MiniPlayer player("Hero", 100, 200);
    MiniAbility ability("Fireball", 50, 20);
    player.addAbility(ability);
    
    // Try to use an ability with an invalid index (e.g., index 1, which does not exist)
    player.useAbility(1, player);
    
    // Verify that the HP and mana have not been modified
    EXPECT_EQ(player.getMana(), 100);
    EXPECT_EQ(player.getHP(), 200);
}

// Test using an ability with negative damage
TEST(MiniPlayerTest, UseAbilityWithNegativeDamageTest) {
    MiniPlayer player("Hero", 100, 200);
    MiniAbility ability("Healing", -50, 20);  // Ability with negative damage (healing)
    player.addAbility(ability);
    
    // Use the healing ability
    player.useAbility(0, player);
    
    // Verify that the player's HP is increased (healed)
    EXPECT_EQ(player.getHP(), 250);  // HP should have increased by 50 (negative damage)
}

// Test for the constructor and getter methods of MiniEffect
TEST(MiniEffectTest, ConstructorAndGettersTest) {
    // Create an effect with the name "Poison" and a duration of 5 turns
    MiniEffect effect("Poison", 5);
    
    // Verify that the effect's name and duration are correctly set
    EXPECT_EQ(effect.getName(), "Poison");
    EXPECT_EQ(effect.getDuration(), 5);
}

// Test for the default case where the effect has a short duration
TEST(MiniEffectTest, DefaultDurationTest) {
    // Create an effect with the name "Stun" and a duration of 1 turn
    MiniEffect effect("Stun", 1);
    
    // Verify that the effect's name and duration are correctly set
    EXPECT_EQ(effect.getName(), "Stun");
    EXPECT_EQ(effect.getDuration(), 1);
}

// Test for an effect with a very long duration
TEST(MiniEffectTest, LongDurationTest) {
    // Create an effect with the name "Regeneration" and a duration of 100 turns
    MiniEffect effect("Regeneration", 100);
    
    // Verify that the effect's name and duration are correctly set
    EXPECT_EQ(effect.getName(), "Regeneration");
    EXPECT_EQ(effect.getDuration(), 100);
}

