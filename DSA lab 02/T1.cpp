#include "pch.h"
#include"C:\Users\HP Elite book\OneDrive\Desktop\SEMESTER 3\OOP\DSAlab-2\DSAlab-2\Q1.cpp"

TEST(ParkingLotString, AssignAndRetrieveStringSlot) {
    ParkingLot<string> lot(2, 2);

    EXPECT_TRUE(lot.parkSlot(0, 0, "Ali"));

    string value;
    EXPECT_TRUE(lot.getSlot(0, 0, value));
    EXPECT_EQ(value, "Ali");
}
TEST(ParkingLotString, RemoveVehicleFromStringSlot) {
    ParkingLot<string> lot(2, 2);

    EXPECT_TRUE(lot.parkSlot(0, 1, "Sara"));
    EXPECT_TRUE(lot.removeVehicle(0, 1));

    EXPECT_TRUE(lot.isAvailable(0, 1));
}
TEST(ParkingLotInt, AssignAndRetrieveIntegerSlot) {
    ParkingLot<int> lot(2, 2);

    EXPECT_TRUE(lot.parkSlot(1, 0, 101));

    int value = 0;
    EXPECT_TRUE(lot.getSlot(1, 0, value));
    EXPECT_EQ(value, 101);
}

TEST(ParkingLotBool, ParkedAndAvailableSpecialization) {
    ParkingLot<bool> lot(1, 2);

    EXPECT_TRUE(lot.parkSlot(0, 0, true));
    EXPECT_TRUE(lot.parkSlot(0, 1, false));

    bool v00 = false;
    bool v01 = true;

    EXPECT_TRUE(lot.getSlot(0, 0, v00));
    EXPECT_TRUE(lot.getSlot(0, 1, v01));

    EXPECT_TRUE(v00);                
    EXPECT_TRUE(lot.isAvailable(0, 1));
}