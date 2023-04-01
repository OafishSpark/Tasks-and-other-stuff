#include <iostream>

#include "avltree.cpp"
#include <gtest/gtest.h>

/*******************************************************************************
                 FUNNCTIONS FOR TESTS
*******************************************************************************/

int PrintInMass1(node* p, int* mass, int index = 0)
{
	if (p->left != NULL)
	{
		index = PrintInMass1(p->left, mass, index);
	}
	mass[index] = p->key;
	index += 1;
	if (p->right != NULL)
	{
		index = PrintInMass1(p->right, mass, index);
	}
	return index;
}

void PrintInMass(node* p, int* mass)
{
    int a;
    a = PrintInMass1(p, mass);
}

bool IsAVL(node* p)
{
    bool ans = 1;
    if (p->left != NULL)
    {
        ans = IsAVL(p->left);
    }
    ans = ((bfactor(p) < 2) && (bfactor(p) > -2)) ? (true) : (false);
    if (p->right != NULL)
    {
        ans = IsAVL(p->right);
    }
    return ans;
}

bool IfTheSame(node* p, int* mass, int n)
{
    int mass1[n];
    PrintInMass(p, mass1);
    for (int i = 0; i < n; i++)
    {
        if (mass1[i] != mass[i])
        {
            return false;
        }
    }
    return IsAVL(p);
}

/*******************************************************************************
                                TESTS 
*******************************************************************************/

TEST(Insert, TestA)
{
    node root(0);
	node* tree = &root;    
    for (int i = 1; i < 10; i++)
    {
        tree = Insert(tree, i);
    }
    int mass[10];
    for (int i = 0; i < 10; i++)
    {
        mass[i] = i;
    }
    ASSERT_TRUE(IfTheSame(tree, mass, 10));
}

TEST(Insert, TestB)
{
    node root(0);
	node* tree = &root;    
    for (int i = 1; i < 11; i++)
    {
        tree = Insert(tree, i);
    }
    int mass[11];
    for (int i = 0; i < 11; i++)
    {
        mass[i] = i;
    }
    ASSERT_TRUE(IfTheSame(tree, mass, 11));
}

TEST(Remove, TestA)
{
    node root(0);
	node* tree = &root;    
    for (int i = 1; i < 10; i++)
    {
        tree = Insert(tree, i);
    }
    int mass[9];
    for (int i = 0; i < 9; i++)
    {
        mass[i] = i;
    }
    tree = Remove(tree, 10);
    ASSERT_TRUE(IfTheSame(tree, mass, 9));
}

TEST(Delete, TestA)
{
    node root(0);
	node* tree = &root;    
    for (int i = 1; i < 10; i++)
    {
        tree = Insert(tree, i);
    }
    int mass[9];
    for (int i = 0; i < 9; i++)
    {
        mass[i] = i;
    }
    tree = Remove(tree, 10);
    ASSERT_TRUE(IfTheSame(tree, mass, 9));
}

TEST(Insert, TestA1)
{
    AVLTree tree(2);
    tree.insert(4); tree.insert(1);
    int mass[3] = {1, 2, 4};
    ASSERT_TRUE(IfTheSame(tree.root, mass, 3));
    tree.insert(6);
    int mass1[4] = {1, 2, 4, 6};
    ASSERT_TRUE(IfTheSame(tree.root, mass1, 4));
    tree.insert(10);
    int mass2[5] = {1, 2, 4, 6, 10};
    ASSERT_TRUE(IfTheSame(tree.root, mass2, 5));
}

TEST(Delete, TestA1)
{
    AVLTree tree(2);
    tree.insert(4); tree.insert(1); tree.deleteByVal(4);
    int mass[2] = {1, 2};
    ASSERT_TRUE(IfTheSame(tree.root, mass, 2));
    tree.insert(4); tree.insert(6); tree.deleteByVal(1);
    int mass1[3] = {2, 4, 6};
    ASSERT_TRUE(IfTheSame(tree.root, mass1, 3));
    tree.insert(10); tree.deleteByVal(6);
    int mass2[3] = {2, 4, 10};
    ASSERT_TRUE(IfTheSame(tree.root, mass2, 3));
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}