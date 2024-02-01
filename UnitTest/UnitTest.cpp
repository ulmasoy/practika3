#include "pch.h"
#include "CppUnitTest.h"
#include "..\pr1\cars.h"
#include "..\pr1\date.h"
#include <sstream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(ValidAlphabetFormat)
        {
            std::vector<std::string> cases{
                "B123GC24"
                "E814CB03"
                "Y666CT99"
                "O623YB03"
            };
            for (int i = 0; i < cases.size(); i++) {
                istringstream ist(cases[i]);
                Car car;
                try {
                    car.validateNumber(cases[i]);
                }
                catch (runtime_error& e) {
                    Assert::AreEqual(e.what(), "Invalid alphabet format in numbers!");
                }
            }
        };
        TEST_METHOD(InvalidAlphabetFormat)
        {
            std::vector<std::string> cases{
                "B1234C24 2023i3.31"
            };
            for (int i = 0; i < cases.size(); i++) {
                istringstream ist(cases[i]);
                Car car;
                try {
                    car.load(ist);
                    Assert::Fail();
                }
                catch (runtime_error& e) {
                    return;
                }
            }
        };
        TEST_METHOD(ValidateNumberInvalidFormat) {
            vector<string> invalidNumbers{
              "B1~3BC24",
              "B123G@24"
            };

            for (auto& number : invalidNumbers) {
                try {
                    Car().validateNumber(number);
                    Assert::Fail();
                }
                catch (runtime_error&) {
                }
            }
        }
        TEST_METHOD(LoadValidNumber) {
            string valid = "B123AC24 2023.11.11";
            istringstream iss(valid);

            Car car;
            car.load(iss);

            string str = "B123AC24";
            Assert::AreEqual(car.numberOfCar, str);
            Assert::AreEqual(car.date.year, 2023);
            Assert::AreEqual(car.date.month, 11);
            Assert::AreEqual(car.date.day, 11);
        };
        TEST_METHOD(LoadInvalidNumber) {
            string invalid = "B123GC24.2022.99.99";
            istringstream iss(invalid);

            Car car;

            try {
                car.load(iss);
                Assert::Fail();
            }
            catch (runtime_error&) {
            }
        }
        TEST_METHOD(ValidateDateInvalid) {
            std::vector<std::vector<int>> cases({ {2022, 11, 40} });

            try {
                Date::validateDate(2022, 13, 40);
                Assert::Fail();
            }
            catch (out_of_range&) {
            }
        };
        TEST_METHOD(LoadValidDate) {
            string valid = "2022.11.11";
            istringstream iss(valid);

            Date date;
            date.load(iss);

            Assert::AreEqual(date.year, 2022);
            Assert::AreEqual(date.month, 11);
            Assert::AreEqual(date.day, 11);
        };
        TEST_METHOD(LoadInvalidDate) {
            istringstream iss("2022 99 99");

            Date date;

            try {
                date.load(iss);
            }
            catch (runtime_error&) {
                return;
            }

            Assert::Fail();
        }
    };
}
