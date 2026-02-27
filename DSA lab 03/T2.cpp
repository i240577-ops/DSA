//#include <iostream>
//using namespace std;
//
//template <typename T>
//class VitalsAnalytics
//{
//private:
//    int days;
//    int wards;
//    int patients;
//    T*** readings;
//
//public:
//     VitalsAnalytics(int d, int w, int p)
//    {
//        days = d;
//        wards = w;
//        patients = p;
//
//        readings = new T * *[days];
//
//        for (int i = 0; i < days; i++)
//        {
//            readings[i] = new T * [wards];
//            for (int j = 0; j < wards; j++)
//            {
//                readings[i][j] = new T[patients];
//                for (int k = 0; k < patients; k++)
//                    readings[i][j][k] = T{};
//            }
//        }
//    }
//
//    ~VitalsAnalytics()
//    {
//        for (int i = 0; i < days; i++)
//        {
//            for (int j = 0; j < wards; j++)
//                delete[] readings[i][j];
//
//            delete[] readings[i];
//        }
//        delete[] readings;
//    }
//
//    void setReading(int day, int ward, int patient, T value)
//    {
//        readings[day][ward][patient] = value;
//    }
//
//    T getReading(int day, int ward, int patient)
//    {
//        return readings[day][ward][patient];
//    }
//
//    T* patientTrend(int patientId)
//    {
//        T* trend = new T[days];
//
//        for (int d = 0; d < days; d++)
//        {
//            T sum = T{};
//            for (int w = 0; w < wards; w++)
//                sum += readings[d][w][patientId];
//
//            trend[d] = sum / wards;
//        }
//
//        return trend;
//    }
//
//    int wardPeakDay(int wardId)
//    {
//        T maxSum = T{};
//        int peakDay = 0;
//
//        for (int d = 0; d < days; d++)
//        {
//            T sum = T{};
//            for (int p = 0; p < patients; p++)
//                sum += readings[d][wardId][p];
//
//            if (d == 0 || sum > maxSum)
//            {
//                maxSum = sum;
//                peakDay = d;
//            }
//        }
//
//        return peakDay;
//    }
//
//    int comparePatients(int p1, int p2)
//    {
//        T sum1 = T{}, sum2 = T{};
//
//        for (int d = 0; d < days; d++)
//        {
//            for (int w = 0; w < wards; w++)
//            {
//                sum1 += readings[d][w][p1];
//                sum2 += readings[d][w][p2];
//            }
//        }
//
//        T avg1 = sum1 / (days * wards);
//        T avg2 = sum2 / (days * wards);
//
//        if (avg1 > avg2) return 1;
//        if (avg2 > avg1) return -1;
//        return 0;
//    }
//
//    void printReport()
//    {
//        cout << "\n=== Vitals Analytics Report ===\n";
//
//        for (int p = 0; p < patients; p++)
//        {
//            T sum = T{};
//            for (int d = 0; d < days; d++)
//                for (int w = 0; w < wards; w++)
//                    sum += readings[d][w][p];
//
//            cout << "Patient " << p
//                << " average = "
//                << sum / (days * wards) << endl;
//        }
//
//        for (int w = 0; w < wards; w++)
//            cout << "Ward " << w
//            << " peak day = "
//            << wardPeakDay(w) << endl;
//    }
//};
