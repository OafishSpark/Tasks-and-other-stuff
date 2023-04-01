#include <iostream>

#include "blackredtree.cpp"
#include <gtest/gtest.h>

TEST(Insert, TestA)
{
    RBTree tree;
    tree.insert(2); tree.insert(4); tree.insert(1);
    COLOR mass[3] = {RED, BLACK, RED};
    ASSERT_TRUE(IfTheSame(tree.root, mass, 3));
    tree.insert(6);
    COLOR mass1[4] = {BLACK, BLACK, BLACK, RED};
    ASSERT_TRUE(IfTheSame(tree.root, mass1, 4));
    tree.insert(10);
    COLOR mass2[5] = {BLACK, BLACK, RED, BLACK, RED};
    ASSERT_TRUE(IfTheSame(tree.root, mass2, 5));
}

TEST(Delete, TestA)
{
    RBTree tree;
    tree.insert(2); tree.insert(4); tree.insert(1); tree.deleteByVal(4);
    COLOR mass[2] = {RED, BLACK};
    ASSERT_TRUE(IfTheSame(tree.root, mass, 2));
    tree.insert(4); tree.insert(6); tree.deleteByVal(1);
    COLOR mass1[3] = {BLACK, BLACK, BLACK};
    ASSERT_TRUE(IfTheSame(tree.root, mass1, 3));
    tree.insert(10); tree.deleteByVal(6);
    COLOR mass2[3] = {BLACK, BLACK, BLACK};
    ASSERT_TRUE(IfTheSame(tree.root, mass2, 3));
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}