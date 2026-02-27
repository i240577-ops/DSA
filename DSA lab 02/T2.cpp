#include "pch.h"
#include"C:\Users\HP Elite book\OneDrive\Desktop\SEMESTER 3\OOP\DSAlab-2\DSAlab-2\Q2.cpp"
TEST(InventoryWalletNecessary, CreateInstances_IntFloatDouble) {
    InventoryWallet<int> wi(10, 3);
    EXPECT_EQ(wi.getCurrentQuantity(), 10);

    InventoryWallet<float> wf(10.5f, 2);
    EXPECT_NEAR(wf.getCurrentQuantity(), 10.5f, 1e-6f);

    InventoryWallet<double> wd(100.25, 4);
    EXPECT_NEAR(wd.getCurrentQuantity(), 100.25, 1e-12);
}
TEST(InventoryWalletNecessary, ValidAdditionsWithinLimit) {
    InventoryWallet<int> wi(0, 3);
    EXPECT_TRUE(wi.addItems(5));
    EXPECT_TRUE(wi.addItems(2));
    EXPECT_EQ(wi.getCurrentQuantity(), 7);

    InventoryWallet<float> wf(1.5f, 2);
    EXPECT_TRUE(wf.addItems(0.25f));
    EXPECT_TRUE(wf.addItems(1.00f));
    EXPECT_NEAR(wf.getCurrentQuantity(), 2.75f, 1e-6f);

    InventoryWallet<double> wd(10.0, 2);
    EXPECT_TRUE(wd.addItems(2.5));
    EXPECT_TRUE(wd.addItems(1.25));
    EXPECT_NEAR(wd.getCurrentQuantity(), 13.75, 1e-12);
}
TEST(InventoryWalletNecessary, ValidRemovalsWithinQuantity) {
    InventoryWallet<int> wi(10, 3);
    EXPECT_TRUE(wi.removeItems(3));
    EXPECT_TRUE(wi.removeItems(1));
    EXPECT_EQ(wi.getCurrentQuantity(), 6);

    InventoryWallet<float> wf(5.5f, 2);
    EXPECT_TRUE(wf.removeItems(2.25f));
    EXPECT_TRUE(wf.removeItems(3.25f));
    EXPECT_NEAR(wf.getCurrentQuantity(), 0.0f, 1e-6f);

    InventoryWallet<double> wd(8.75, 2);
    EXPECT_TRUE(wd.removeItems(5.0));
    EXPECT_TRUE(wd.removeItems(3.75));
    EXPECT_NEAR(wd.getCurrentQuantity(), 0.0, 1e-12);
}
TEST(InventoryWalletNecessary, InvalidRemovalGreaterThanCurrent) {
    InventoryWallet<int> wi(4, 5);
    EXPECT_FALSE(wi.removeItems(5));
    EXPECT_EQ(wi.getCurrentQuantity(), 4);

    InventoryWallet<float> wf(2.0f, 5);
    EXPECT_FALSE(wf.removeItems(2.01f));
    EXPECT_NEAR(wf.getCurrentQuantity(), 2.0f, 1e-6f);

    InventoryWallet<double> wd(2.0, 5);
    EXPECT_FALSE(wd.removeItems(2.0000001));
    EXPECT_NEAR(wd.getCurrentQuantity(), 2.0, 1e-12);
}
TEST(InventoryWalletNecessary, ExceedAdditionAndRemovalLimits) {
    InventoryWallet<int> w(10, 2);
    EXPECT_TRUE(w.addItems(1));
    EXPECT_TRUE(w.addItems(1));
    EXPECT_FALSE(w.addItems(1));
    EXPECT_EQ(w.getCurrentQuantity(), 12);
    EXPECT_TRUE(w.removeItems(2));
    EXPECT_TRUE(w.removeItems(1));
    EXPECT_FALSE(w.removeItems(1));
    EXPECT_EQ(w.getCurrentQuantity(), 9);
}
TEST(InventoryWalletNecessary, MixedAddRemoveRandomOrder) {
    InventoryWallet<int> w(10, 3);

    EXPECT_TRUE(w.addItems(2));
    EXPECT_TRUE(w.removeItems(5));
    EXPECT_TRUE(w.addItems(1));   
    EXPECT_FALSE(w.removeItems(20));
    EXPECT_TRUE(w.removeItems(8));  

    EXPECT_EQ(w.getCurrentQuantity(), 0);
}

TEST(InventoryWalletNecessary, BoundaryZeroAndExactRemoval) {
    InventoryWallet<int> w(0, 3);
    EXPECT_FALSE(w.removeItems(1)); 
    EXPECT_TRUE(w.addItems(3));
    EXPECT_TRUE(w.removeItems(3));  
    EXPECT_EQ(w.getCurrentQuantity(), 0);

    InventoryWallet<double> wd(0.000001, 2);
    EXPECT_TRUE(wd.removeItems(0.000001));
    EXPECT_NEAR(wd.getCurrentQuantity(), 0.0, 1e-12);
}

TEST(InventoryWalletNecessary, TypeSpecificBehavior_IntVsFloatDouble) {
    InventoryWallet<int> wi(5, 2);
    EXPECT_TRUE(wi.addItems(3));
    EXPECT_TRUE(wi.removeItems(2));
    EXPECT_EQ(wi.getCurrentQuantity(), 6); 

    InventoryWallet<float> wf(1.5f, 2);
    EXPECT_TRUE(wf.addItems(0.75f));
    EXPECT_TRUE(wf.removeItems(1.0f));
    EXPECT_NEAR(wf.getCurrentQuantity(), 1.25f, 1e-6f); 

    InventoryWallet<double> wd(2.5, 2);
    EXPECT_TRUE(wd.addItems(0.125));
    EXPECT_TRUE(wd.removeItems(1.625));
    EXPECT_NEAR(wd.getCurrentQuantity(), 1.0, 1e-12); 
}