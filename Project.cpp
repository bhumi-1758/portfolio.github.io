#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <map>


using namespace std;

struct Car {

    // Dealer selling the car
    string dealer;

    // Car's brand (e.g., Tesla, Ford)
    string brand;

    // Car's model name (e.g., Model X)
    string name;

    // Car type: Petrol/Electric
    string type;

    // Car's cost (e.g., 25000 USD)
    string cost;

    // Engine capacity in CC (e.g., 2000 CC)
    string cc;

    // Model year (e.g., 2021)
    string modelYear;

    // Mileage in km/l (e.g., 15 km/l)
    string mileage;

    // Track if the car is booked
    bool booked = false;

    // Track if the car is purchased
    bool purchased = false;

    // Store customer name and payment method for purchase

    string customerName;
      // Customer name who purchased or booked the car
    string paymentMethod;
      // Payment method chosen by the customer (Credit Card, Cash, etc.)

    // Method to display car details

    void display() const
    {
        cout << "\n------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Dealer: " << dealer << ", Brand: " << brand << ", Car: " << name
             << ", Type: " << type << ", Cost: " << cost
             << ", CC: " << cc << ", Model Year: " << modelYear
             << ", Mileage: " << mileage << " km/l\n";
        if (booked) cout << "Status: Booked\n";
        if (purchased) cout << "Status: Purchased\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n";
    }

};


// Structure to store bike details

struct Bike

{

    string dealer;

    string brand;

    string name;

    string type;

    // Petrol/Electric

    string cost;

    string cc;

     // Engine CC

    string modelYear;
     // Model Year

    string mileage;

     // Mileage


    void display() const
    {

        cout << "\n------------------------------------------------------------------------------------------------------------------------------------------\n";

        cout << "Dealer: " << dealer << ", Brand: " << brand << ", Bike: " << name

             << ", Type: " << type << ", Cost: " << cost

             << ", CC: " << cc << ", Model Year: " << modelYear

             << ", Mileage: " << mileage << " km/l\n";

        cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n";
    }


};
// Enhanced structures
struct Car1 {

    string id;

    string name;

    string brand;

    string dealer;

    string type;       // Add this

    string cost;       // Add this

    string cc;         // Add this

    string modelYear;  // Add this

    string mileage;

    double pricePerDay;

    bool isAvailable;

    string condition;  // New, Good, Fair

    int year;

    string color;



    void display() const

    {
        cout << "ID: " << id << " | Dealer: " << dealer << " | Brand: " << brand
             << " | Car: " << name << " | Price/Day: $" << fixed << setprecision(2)
             << pricePerDay << " | Available: " << (isAvailable ? "Yes" : "No")
             << " | Condition: " << condition << " | Year: " << year
             << " | Color: " << color << endl;
    }

};

struct Rental
{

    string rentalId;

    string username;

    string carId;

    string startDate;

    string endDate;

    double totalCost;

    bool isActive;
};

struct User
{

    string username;

    string password;

    string role;

    string fullName;

    string contact;

    string email;

    string securityQuestion;  // Added for password recovery

    string securityAnswer;    // Added for password recovery

    vector<string> rentalHistory;
};


vector<User> users;

// Global data

vector<Car1> cars;

vector<Rental> rentals;

const string userFile = "users.txt";

const string carFile = "cars.txt";

const string rentalFile = "rentals.txt";

const string loginHistoryFile = "login_history.txt";


// Function prototypes

void loadData();

void saveData();

void registerUser(const string& role);

bool userLogin();

bool dealerLogin();

void userDashboard(const string& username);

void dealerDashboard(const string& username);

void adminDashboard();

//void addCar(const string& dealer);

//void removeCar(const string& dealer);

void viewAllCars();



void viewAvailableCars();

void rentCar(const string& username);



void returnCar(const string& username);

void viewRentalHistory(const string& username);



void generateReport();

void manageUsers();



string generateId(const string& prefix);
void displayWelcomeMessage();



void logAction(const string& username, const string& action);

double calculateRentalCost(const Car1& car, int days);



void searchCars();

void displayUserProfile(const string& username);



void updateUserProfile(const string& username);

void displayCarStatistics();


void forgotPassword();
bool resetPassword(const string& username);

bool verifySecurityQuestion(const string& username);
void showDealerLocation(const std::string& dealerName);

void viewAllUsers();
void logLoginHistory(const string& username, const string& role);

const string userLoginHistoryFile = "user_login_history.txt";
const string dealerLoginHistoryFile = "dealer_login_history.txt";

const string adminLoginHistoryFile = "admin_login_history.txt";
 // Added declaration
void deleteUser();
 // Added declaration
string getCurrentTimestamp();
 // Added declaration


 #include <limits>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm> // For transform function
#include <iomanip>
#include <fstream>
using namespace std;

// Utility functions for date and time

std::string getCurrentTimestamp2()

{

    std::time_t now = std::time(nullptr);

    char buf[80];

    std::strftime(buf, sizeof(buf),
                   "%Y-%m-%d %H:%M:%S",
                   std::localtime(&now)
                  );


    return std::string(buf);

}

// Struct for user details

struct User2

{
    std::string name;

    std::string email;

    int rentedBikeId = -1;

    int rentalDurationHours = 0;

    std::string rentalStartDate;

    int totalRentalTime = 0;

    double totalRentalCost = 0.0;

    std::vector<int> rentalHistory;

    void rentBike(int bikeId,
                  const std::string& startDate,
                  int durationHours)

                   {

        rentedBikeId = bikeId;

        rentalStartDate = startDate;

        rentalDurationHours = durationHours;

    }


    void returnBike()
    {
        rentedBikeId = -1;
    }

    void addRentalHistory
    (int bikeId)

     {
        rentalHistory.push_back(bikeId);
    }

    void updateTotalRentalTime(int hours)

    {
        totalRentalTime += hours;
    }

    void updateTotalRentalCost(double cost)

     {
        totalRentalCost += cost;
    }

    void printDetails()
    const

    {
        std::cout << "Name: " << name << ", Email: " << email << std::endl;
    }
};


// Struct for bike details

struct Bike2

 {

    int id;
    std::string model;

    std::string type;

    double hourlyRate;

    bool available = true;

    void setAvailability(bool availability)

    {
        available = availability;
    }

    void printDetails()
    const

    {

        std::cout << "Bike ID: " << id << ", Model: " << model
                  << ", Type: " << type << ", Hourly Rate: $" << hourlyRate
                  << ", Available: " << (available ? "Yes" : "No") << std::endl;

    }

};

// Struct for dealer details

struct Dealer2

{
    std::string name;

    std::string location;

    void printDetails()
    const

    {

        std::cout << "Dealer: " << name << ", Location: " << location << std::endl;

    }

};

// Struct for managing the rental system
struct RentalManager2
{
    std::vector<User2> users;

    std::vector<Bike2> bikes;

    std::vector<Dealer2> dealers;

    void addUser
    (const User2& user)

     {
        users.push_back(user);
    }

    void addBike
    (const Bike2& bike)

    {

        bikes.push_back(bike);

    }

    void addDealer
    (const Dealer2& dealer)

    {

        dealers.push_back(dealer);

    }

    void listUsers()
    const

     {

        for (const auto& user : users)
        {

            user.printDetails();

        }

    }

    void listBikes()
    const

    {

        for (const auto& bike : bikes)
        {

            bike.printDetails();

        }

    }

    void listDealers()
    const

    {

        for (const auto& dealer : dealers)
        {

            dealer.printDetails();

        }

    }

    bool rentBike(const std::string& userName,
                  int bikeId,
                  const std::string& startDate,
                   int durationHours)

                   {

        for (auto& bike : bikes)
            {

            if (bike.id == bikeId && bike.available)
            {

                for (auto& user : users)
                {

                    if (user.name == userName)
                     {

                        user.rentBike(bikeId, startDate, durationHours);

                        bike.setAvailability(false);

                        user.updateTotalRentalTime(durationHours);

                        user.updateTotalRentalCost(calculateTotalRentalCost(durationHours, bike.hourlyRate));

                        return true;

                    }

                }

            }

        }


        return false;
    }


    bool returnBike(const std::string& userName)
    {
        for (auto& user : users)

            {

            if (user.name == userName)

            {

                int bikeId = user.rentedBikeId;

                if (bikeId != -1)

                 {

                    for (auto& bike : bikes)

                     {

                        if (bike.id == bikeId)

                         {

                            bike.setAvailability(true);

                            user.returnBike();

                            return true;
                        }

                    }

                }

            }

        }


        return false;
    }

    bool userExists(const std::string& userName)
    const

    {
        return std::any_of(users.begin(),
                           users.end(),
                           [&](const User2& user)

                           {


            return user.name == userName;
        }

        );
    }

    bool bikeExists(int bikeId)
     const

     {

        return std::any_of(bikes.begin(),
                            bikes.end(),
                            [&](const Bike2& bike)

                           {

            return bike.id == bikeId;
        }

        );

    }

    bool dealerExists(const std::string& dealerName)
     const

     {
        return std::any_of(dealers.begin(),
                            dealers.end(),
                           [&](const Dealer2& dealer)

                           {

            return dealer.name == dealerName;

        }

        );
    }

    void viewContract(const std::string& userName)
     const

     {
        for (const auto& user : users)

            {

            if (user.name == userName)

             {
                std::cout << "Rental Contract for " << userName << ":\n";

                std::cout << "Name: " << user.name << ", Email: " << user.email << std::endl;

                std::cout << "Rental Start Date: " << user.rentalStartDate << std::endl;

                std::cout << "Rental Duration: " << user.rentalDurationHours << " hours" << std::endl;

                double totalCost = calculateTotalRentalCost(user.rentalDurationHours, 10.0);

                std::cout << "Total Rental Cost: $" << totalCost << std::endl;

                return;
            }
        }

        std::cout << "User not found.\n";
    }

    double calculateTotalRentalCost(int durationHours, double hourlyRate)
     const

     {
        return durationHours * hourlyRate;
    }

    User2* searchUserByName
    (const std::string& userName)

    {
        for (auto& user : users)

            {

            if (user.name == userName)

            {
                return &user;
            }
        }

        return nullptr;
    }

    Bike2* findCheapestBike()
     const

      {
        if (bikes.empty()) return nullptr;

        return const_cast<Bike2*>(&(*std::min_element(bikes.begin(),
                                                     bikes.end(),
                                                     [](const Bike2& a,
                                                    const Bike2& b)

                                                      {

            return a.hourlyRate < b.hourlyRate;

        }
        )
        )
        );
    }

    void displayRentalSummary()
     const

      {

        std::cout << "Rental Summary:\n";

        for (const auto& user : users)

            {

            if (user.rentedBikeId != -1)

            {
                std::cout << "User Name: " << user.name << ", Bike ID: " << user.rentedBikeId
                          << ", Rental Start Date: " << user.rentalStartDate
                          << ", Rental Duration: " << user.rentalDurationHours << " hours\n";
            }
        }
    }
};

void clearScreen()

{
    std::cout << "\033[2J\033[1;1H";
}

void pause()
{
    std::cout << "Press Enter to continue...";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin.get();
}


void displayMenu()
{
    std::cout << "Bike Rental System Menu\n";

    std::cout << "1. Register User\n";

    std::cout << "2. List Users\n";

    std::cout << "3. Add Dealer\n";

    std::cout << "4. List Dealers\n";

    std::cout << "5. Add Bike\n";

    std::cout << "6. List Bikes\n";

    std::cout << "7. Rent a Bike\n";

    std::cout << "8. Return a Bike\n";

    std::cout << "9. View Contract\n";

    std::cout << "10. Search User by Name\n";

    std::cout << "11. Find Cheapest Bike\n";

    std::cout << "12. Display Rental Summary\n";

    std::cout << "13. Exit\n";

    std::cout << "Enter your choice: ";
}



struct Vehicle2 {
    string vehicleType;
    string fuelType;

    Vehicle2() : vehicleType(""), fuelType("") {} // Default constructor
    Vehicle2(string type, string fuel) : vehicleType(type), fuelType(fuel) {}

    virtual void displayDetails() const {
        cout << "Vehicle Type: " << vehicleType << ", Fuel Type: " << fuelType << endl;
    }
};

struct Traveller : public Vehicle2
{
    int capacity;

    Traveller(string fuel, int cap) : Vehicle2("Traveller", fuel), capacity(cap) {}

    void displayDetails() const override {
        cout << "Traveller, Fuel Type: " << fuelType << " Capacity: " << capacity << endl;
    }
};


struct Car4 :  Vehicle2 {
    string carType;
    string brand;
    string model;
    string dealer;
    int year;
    string mileage;
    string engineCapacity;
    double pricePerDay;
    string colors;
    bool isAvailable;
    string feedback;

    Car4(string type, string fuel, string br, string mo, string de, int yr, string mi, string en, double pd, string co)
        : Vehicle2("Car", fuel), carType(type), brand(br), model(mo), dealer(de), year(yr), mileage(mi),
          engineCapacity(en), pricePerDay(pd), colors(co), isAvailable(true), feedback("") {}

void displayDetails() const override {
    cout << "=========================================" << endl;
    cout << "              CAR DETAILS                " << endl;
    cout << "=========================================" << endl;
    cout << "Car Type        : " << carType << endl;
    cout << "Brand           : " << brand << endl;
    cout << "Model           : " << model << endl;
    cout << "Fuel Type       : " << fuelType << endl;
    cout << "Price Per Day   : $" << pricePerDay << endl;
    cout << "Dealer          : " << dealer << endl;
    cout << "Year            : " << year << endl;
    cout << "Mileage         : " << mileage << endl;
    cout << "Engine Capacity : " << engineCapacity << endl;
    cout << "Color(s)        : " << colors << endl;
    cout << "Availability    : " << (isAvailable ? "Yes" : "No") << endl;

    if (!feedback.empty())


    {
        cout << "-----------------------------------------" << endl;
        cout << "User Feedback: " << feedback << endl;
    }

    cout << "=========================================" << endl;
}
};



// Function prototypes (implement these functions based on your requirements)
bool compareByPrice(const Car4& car1, const Car4& car2);

bool compareByYear(const Car4& car1, const Car4& car2);

bool compareByFuelType(const Car4& car1, const Car4& car2);

void displayCars(const std::vector<Car4>& cars);

void filterCars(const std::vector<Car4>& cars);

void purchaseCar(std::vector<Car4>& cars);

void rentCar(std::vector<Car4>& cars); // Implement car rental functionality

void leaveFeedback(const std::vector<Car4>& cars); // Implement feedback functionality

void returnCar(std::vector<Car4>& cars); // Implement car return functionality

void generateInvoice(const Car4& car, const std::string& userName, bool toFile = false, int days = 0);


// Sorting function to sort cars by price
bool compareByPrice(const Car4& a, const Car4& b)
{

    return a.pricePerDay < b.pricePerDay;

}

// Sorting function to sort cars by year
bool compareByYear(const Car4& a, const Car4& b)
{

    return a.year < b.year;

}

// Sorting function to sort cars by fuel type
bool compareByFuelType(const Car4& a, const Car4& b)
{

    return a.fuelType < b.fuelType;

}

// Binary search function to find the first car matching a specific price range
int binarySearchByPrice(const vector<Car4>& cars, double price)
{

    int left = 0, right = cars.size() - 1;
    while (left <= right)
        {
        int mid = left + (right - left) / 2;
        if (cars[mid].pricePerDay == price)
        {
            return mid; // Found car with exact price
        }
        if (cars[mid].pricePerDay < price)
        {
            left = mid + 1;
        } else
        {
            right = mid - 1;
        }

    }

    return -1;
}

// Binary search function to find the first car matching a specific year
int binarySearchByYear(const vector<Car4>& cars, int year)
{
    int left = 0, right = cars.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].year == year)
        {
            return mid; // Found car with exact year
        }
        if (cars[mid].year < year)
        {
            left = mid + 1;
        } else
        {
            right = mid - 1;
        }

    }
    return -1;
}

// Binary search function to find the first car matching a specific fuel type
int binarySearchByFuelType(const vector<Car4>& cars, const string& fuelType)
{
    int left = 0, right = cars.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].fuelType == fuelType)
        {
            return mid; // Found car with exact fuel type
        }
        if (cars[mid].fuelType < fuelType)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }

    }

    return -1;
}

// Display cars by a given filter
void displayFilteredCarsByPrice(const vector<Car4>& cars, double price)
{
    int index = binarySearchByPrice(cars, price);
    if (index != -1)
    {
        cout << "\nCars with price " << price << " per day:\n";
        while (index < cars.size() && cars[index].pricePerDay == price)
        {
            cars[index].displayDetails();
            index++;
        }
    }
    else
    {

        cout << "No cars found with the price: " << price << endl;

    }

}

void displayFilteredCarsByYear(const vector<Car4>& cars, int year)
{
    int index = binarySearchByYear(cars, year);
    if (index != -1)
        {
        cout << "\nCars from year " << year << ":\n";
        while (index < cars.size() && cars[index].year == year)
        {
            cars[index].displayDetails();
            index++;
        }

    }
    else
    {

        cout << "No cars found for the year: " << year << endl;

    }
}

void displayFilteredCarsByFuelType(const vector<Car4>& cars, const string& fuelType)
{
    int index = binarySearchByFuelType(cars, fuelType);
    if (index != -1)
        {
        cout << "\nCars with fuel type " << fuelType << ":\n";
        while (index < cars.size() && cars[index].fuelType == fuelType)
        {
            cars[index].displayDetails();
            index++;
        }
    }
    else
    {

        cout << "No cars found with fuel type: " << fuelType << endl;

    }
}

vector<Car4> carss = {
    Car4{"SUV", "Petrol", "Toyota", "Fortuner", "Rohan", 2019, "10-12 km/l", "2694 cc", 8000, "White"},

    Car4{"SUV", "Petrol", "Toyota", "Land Cruiser", "Kiran", 2022, "7-10 km/l", "4600 cc", 15000, "Dark blue"},

    Car4{"SUV", "Petrol", "Mahindra", "Thar", "Simran", 2021, "12-14 km/l", "1997 cc", 5000, "Black"},

    Car4{"SUV", "Petrol", "Mahindra", "XUV700", "Kiran", 2021, "12-14 km/l", "1997 cc", 6000, "White"},

    Car4{"SUV", "Diesel", "Hyundai", "Creta", "Ankush", 2018, "19-21 km/l", "1493 cc", 3500, "Red"},

    Car4{"SUV", "Diesel", "Hyundai", "Tucson", "Rohan", 2019, "16-18 km/l", "1995 cc", 5500, "Grey"},

    Car4{"SUV", "Diesel", "BMW", "X1", "Anusha", 2015, "18-20 km/l", "1995 cc", 8200, "Grey"},

    Car4{"SUV", "Diesel", "BMW", "X5", "Anshuman", 2019, "12-15 km/l", "2993 cc", 11800, "Blue"},

    Car4{"SUV", "Diesel", "Audi", "Q3", "Kiran", 2017, "16-18 km/l", "1968 cc", 8000, "White"},

    Car4{"SUV", "Diesel", "Audi", "Q8", "Anusha", 2020, "10-12 km/l", "2967 cc", 22000, "Blue"},

    Car4{"SUV", "Electric", "BMW", "iX3", "Simran", 2021, "460-520 km", "210 kW", 17500, "Grey"},

    Car4{"SUV", "Electric", "Jaguar", "I pace", "Anusha", 2020, "470-500 km", "294 kW", 29000, "White"},

    Car4{"SUV", "Electric", "Ford", "Mustang Mach-E", "Ankush", 2020, "370-490 km", "357 kW", 23000, "Black"},

    Car4{"Sedan", "Petrol", "Toyota", "Corolla", "Rohan", 2022, "18-20 km/l", "", 2500, "White"},

    Car4{"Sedan", "Petrol", "Toyota", "Avalon", "Ankush", 2023, "14-16 km/l", "", 4500, "Black"},

    Car4{"Sedan", "Petrol", "Honda", "Civic", "Stephan", 2021, "16-18 km/l", "", 3000, "Silver"},

    Car4{"Sedan", "Petrol", "Honda", "Accord", "Vaishnavi", 2022, "14-16 km/l", "", 4000, "Black"},

    Car4{"Sedan", "Petrol", "Mercedes-Benz", "C-Class", "Kiran", 2018, "12-14 km/l", "", 7000, "White"},

    Car4{"Sedan", "Petrol", "Kia", "Optima K5", "Simran", 2021, "15-17 km/l", "", 3500, "Red"},

    Car4{"Sedan", "Diesel", "BMW", "3 Series", "Anshuman", 2023, "20-22 km/l", "", 6500, "Blue"},

    Car4{"Sedan", "Diesel", "BMW", "5 Series", "Ankush", 2019, "18-20 km/l", "", 8000, "Black"},

    Car4{"Sedan", "Diesel", "Audi", "A3", "Rohan", 2019, "20-22 km/l", "", 4500, "Red"},

    Car4{"Sedan", "Diesel", "Jaguar", "XE", "Rohan", 2020, "15-17 km/l", "", 7000, "Red"},

    Car4{"Sedan", "Diesel", "Jaguar", "XF", "Anusha", 2021, "12-14 km/l", "180 kW", 9000, "White"},

    Car4{"Sedan", "Electric", "BMW", "i4", "Anshuman", 2020, "480-590 km", "250 kW", 8000, "Blue"},

    Car4{"Sedan", "Electric", "Mercedes-Benz", "EQE", "Stephan", 2022, "450-550 km", "288 kW", 10000, "Silver"},

    Car4{"Sedan", "Electric", "Mercedes-Benz", "EQS", "Kiran", 2023, "620-700 km", "", 12000, "Black"},

    Car4{"Coupe", "Petrol", "Ford", "Mustang EcoBoost", "Stephan", 2021, "12-14 km/l", "224 kW", 9000, "Red"},

    Car4{"Coupe", "Petrol", "Porsche", "911", "Kiran", 2016, "9-11 km/l", "", 18000, "Yellow"},

    Car4{"Coupe", "Petrol", "Toyota", "GR Supra", "Simran", 2020, "11-13 km/l", "", 10000, "Red"},

    Car4{"Coupe", "Diesel", "BMW", "4 Series Coupe", "Vaishnavi", 2021, "18-20 km/l", "", 7500, "White"},

    Car4{"Coupe", "Diesel", "Mercedes-Benz", "C-Class Coupe", "Rohan", 2022, "15-17 km/l", "", 8000, "Blue"},

    Car4{"Coupe", "Diesel", "Mercedes-Benz", "E-Class Coupe", "Anshuman", 2023, "12-14 km/l", "", 9500, "Black"},

    Car4{"Coupe", "Diesel", "Audi", "A5 Coupe", "Ankush", 2019, "16-18 km/l", "", 7500, "Grey"},

    Car4{"Coupe", "Diesel", "Audi", "S5 Coupe", "Vaishnavi", 2022, "14-16 km/l", "", 9000, "Black"},

    Car4{"Hatchback", "Petrol", "Volkswagen", "Golf", "Ankush", 2022, "16-18 km/l", "", 3000, "White"},

    Car4{"Hatchback", "Petrol", "Volkswagen", "Polo", "Akush", 2021, "17-19 km/l", "", 2500, "Red"},

    Car4{"Hatchback", "Petrol", "Ford", "Fiesta", "Anshuman", 2017, "16-18 km/l", "", 3000, "White"},

    Car4{"Hatchback", "Petrol", "Ford", "Focus", "Simran", 2018, "15-17 km/l", "", 3500, "Grey"},

    Car4{"Hatchback", "Diesel", "Hyundai", "i20", "Rohan", 2020, "22-24 km/l", "", 2800, "White"},

    Car4{"Hatchback", "Diesel", "Hyundai", "i30", "Stephan", 2021, "20-22 km/l", "", 3200, "Blue"},

    Car4{"Hatchback", "Diesel", "Toyota", "Yaris", "Vaishnavi", 2022, "20-22 km/l", "", 3000, "White"},

    Car4{"Hatchback", "Diesel", "Toyota", "Corolla Hatchback", "Anusha", 2022, "18-20 km/l", "", 3500, "Grey"},

    Car4{"Hatchback", "Electric", "Mini", "Cooper Electric", "Simran", 2023, "270-290 km", "135 kW", 4500, "Yellow"}
};
void purchaseCar(vector<Car4>& cars)
{
    cout << "Select a car to purchase by index: ";
    int index;
    cin >> index;

    if (index >= 0 && index < cars.size() && cars[index].isAvailable)
    {

        cout << "You have successfully purchased the following car:\n";
        cout << "Brand: " << cars[index].brand << "\nModel: " << cars[index].model << "\nPrice: Rs" << cars[index].pricePerDay << "\n";
        cars[index].isAvailable = false; // Mark car as purchased

        // Generate Invoice for Purchase
        generateInvoice(cars[index], "User", true, 0); // Pass 0 for days as it's a purchase
    }
    else
    {

        cout << "Invalid index or car not available.\n";

    }

}

void rentCar(vector<Car4>& cars) {
    cout << "=========================================" << endl;
    cout << "             RENT A CAR                  " << endl;
    cout << "=========================================" << endl;

    cout << "Select a car to rent by index: ";
    int index;
    cin >> index;

    if (index >= 0 && index < cars.size() && cars[index].isAvailable)
    {
        cout << "\n-----------------------------------------\n";
        cout << "Enter rental duration (in days): ";
        int days;
        cin >> days;

        // Calculate total cost
        double totalCost = cars[index].pricePerDay * days;

        // Display rental confirmation
        cout << "\n=========================================" << endl;
        cout << "            RENTAL CONFIRMATION          " << endl;
        cout << "=========================================" << endl;
        cout << "Car Details:                             " << endl;
        cout << "Brand           : " << cars[index].brand << endl;
        cout << "Model           : " << cars[index].model << endl;
        cout << "Price Per Day   : Rs" << cars[index].pricePerDay << endl;
        cout << "Rental Duration : " << days << " days" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Total Cost      : Rs" << totalCost << endl;
        cout << "=========================================" << endl;

        // Display invoice
        cout << "\n------------- RENTAL INVOICE ------------" << endl;
        cout << "Model           : " << cars[index].model << endl;
        cout << "Brand           : " << cars[index].brand << endl;
        cout << "Rental Duration : " << days << " days" << endl;
        cout << "Price Per Day   : Rs" << cars[index].pricePerDay << endl;
        cout << "Total Cost      : Rs" << totalCost << endl;
        cout << "-----------------------------------------" << endl;

        // Mark the car as rented
        cars[index].isAvailable = false;

        cout << "\nThank you for renting with us! Enjoy your ride.\n";
        cout << "=========================================" << endl;
    }
    else
    {
        cout << "\n=========================================" << endl;
        cout << "          INVALID SELECTION              " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Error: Invalid index or car not available.\n";
        cout << "Please try again.\n";
        cout << "=========================================" << endl;
    }

}

void leaveFeedback(vector<Car4>& cars)
{
    cout << "Select a car to leave feedback on by index: ";
    int index;
    cin >> index;

    if (index >= 0 && index < cars.size()) {
        cout << "Enter your feedback for the car: ";
        cin.ignore();  // To clear the newline character
        string feedback;
        getline(cin, feedback);

        cars[index].feedback = feedback;
        cout << "Thank you for your feedback!\n";
    } else {
        cout << "Invalid car selection.\n";
    }
}

void returnCar(vector<Car4>& cars) {
    cout << "Enter the model of the car you want to return: ";
    string model;
    cin.ignore();  // Clear any lingering input
    getline(cin, model);

    auto it = find_if(cars.begin(), cars.end(), [&model](const Car4& car) {
        return car.model == model && !car.isAvailable;
    });

    if (it != cars.end()) {
        it->isAvailable = true;
        cout << "You have successfully returned the car: " << it->model << endl;
    } else {
        cout << "Car not found or not rented.\n";
    }
}

void filterCars(const std::vector<Car4>& cars) {
    cout << "Filter Options: \n";
    cout << "1. By Price Range\n2. By Year Range\n3. By Mileage Range\n4. By Color\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    vector<Car4> filteredCars;

    switch (choice) {
        case 1: {
            cout << "Enter price range (min max): ";
            double minPrice, maxPrice;
            cin >> minPrice >> maxPrice;
            for (const auto& car : cars) {
                if (car.pricePerDay >= minPrice && car.pricePerDay <= maxPrice) {
                    filteredCars.push_back(car);
                }
            }
            break;
        }
        case 2: {
            cout << "Enter year range (start end): ";
            int startYear, endYear;
            cin >> startYear >> endYear;
            for (const auto& car : cars) {
                if (car.year >= startYear && car.year <= endYear) {
                    filteredCars.push_back(car);
                }
            }
            break;
        }
        case 3: {
            cout << "Enter mileage range (min max): ";
            double minMileage, maxMileage;
            cin >> minMileage >> maxMileage;
            for (const auto& car : cars) {
                double carMileage = stod(car.mileage.substr(0, car.mileage.find("-"))); // Extract first number
                if (carMileage >= minMileage && carMileage <= maxMileage) {
                    filteredCars.push_back(car);
                }
            }
            break;
        }
        case 4: {
            cout << "Enter preferred color: ";
            string color;
            cin >> color;
            transform(color.begin(), color.end(), color.begin(), ::tolower); // Convert input to lowercase
            for (const auto& car : cars) {
                string carColor = car.colors;
                transform(carColor.begin(), carColor.end(), carColor.begin(), ::tolower); // Convert car color to lowercase
                if (carColor.find(color) != string::npos) {
                    filteredCars.push_back(car);
                }
            }
            break;
        }
        default:
            cout << "Invalid choice. No filtering applied.\n";
            return;
    }

    // Display filtered cars
    if (!filteredCars.empty()) {
        cout << "\nFiltered Cars:\n";
        for (const auto& car : filteredCars) {
            car.displayDetails();
        }
    } else {
        cout << "No cars match the filter criteria.\n";
    }
}




void rentVehicle(vector<Car4>& cars) {
    filterCars(cars);
    if (!cars.empty()) {
        cout << "Select a car by its index (starting from 0): ";
        int index;
        cin >> index;

        if (index >= 0 && index < cars.size()) {
            cout << "You have successfully rented the following car:\n";
            cout << "Brand: " << cars[index].brand << "\n";
            cout << "Model: " << cars[index].model << "\n";
            cout << "Price Per Day: " << cars[index].pricePerDay << "\n";
            cars.erase(cars.begin() + index); // Remove the rented car from the list
        } else {
            cout << "Invalid index selected.\n";
        }
    } else {
        cout << "No cars available to rent after filtering.\n";
    }
}

void displayMenu1() {
    cout << "\nCar Rental System\n";
    cout << "1. Display all cars\n";
    cout << "2. Filter cars\n";
    cout << "3. Purchase a Car\n";
    cout << "4. Rent a Car\n";
    cout << "5. Leave Feedback\n";
    cout << "6. Return a Car\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

string selectFuelType() {
    string fuelType;
    cout << "Choose Fuel Type:\n";
    cout << "1. Petrol\n2. Diesel\n3. Electric\n";
    int fuelChoice;
    cin >> fuelChoice;

    switch (fuelChoice) {
        case 1: fuelType = "Petrol"; break;
        case 2: fuelType = "Diesel"; break;
        case 3: fuelType = "Electric"; break;
        default:
            cout << "Invalid fuel type! Defaulting to Petrol.\n";
          fuelType = "Petrol";
    }
    return fuelType;
}

// Function to generate an invoice for a selected car
void generateInvoice(const Car4& car, const std::string& userName, bool toFile, int days) {
    double totalCost = car.pricePerDay * days;

    if (toFile) {
        // Write to a file
        std::ofstream invoice("invoice.txt");
        if (invoice.is_open()) {
            invoice << "\n--- Invoice ---\n";
            invoice << "Invoice for " << userName << "\n";
            invoice << "Car Model: " << car.model << "\nBrand: " << car.brand << "\nFuel Type: " << car.fuelType << "\n";
            invoice << "Price per Day: Rs" << car.pricePerDay << "\n";
            if (days > 0) {
                invoice << "Rental Duration: " << days << " days\n";
                invoice << "Total Rental Cost: Rs" << totalCost << "\n";
            } else {
                invoice << "Total Purchase Price: Rs" << car.pricePerDay << "\n";
            }
            invoice << "Thank you for your purchase/rental!\n";
            invoice.close();
        } else {
            std::cerr << "Error: Unable to open the file for writing.\n";
        }
    } else {
        // Print to console
        std::cout << "\n--- Invoice ---\n";
        std::cout << "Invoice for " << userName << "\n";
        std::cout << "Car Model: " << car.model << "\nBrand: " << car.brand << "\nFuel Type: " << car.fuelType << "\n";
        std::cout << "Price per Day: Rs" << car.pricePerDay << "\n";
        if (days > 0) {
            std::cout << "Rental Duration: " << days << " days\n";
            std::cout << "Total Rental Cost: Rs" << totalCost << "\n";
        } else {
            std::cout << "Total Purchase Price: Rs" << car.pricePerDay << "\n";
        }
        std::cout << "Thank you for your purchase/rental!\n";
    }
}



void displayCars(const std::vector<Car4>& cars) {
    cout << "\nList of Cars (Car2):\n";
    for (const auto& car : cars) {
        cout << "Car Type: " << car.carType << "\n";
        cout << "Brand: " << car.brand << "\n";
        cout << "Model: " << car.model << "\n";
        cout << "Fuel Type: " << car.fuelType << "\n";
        cout << "Price Per Day: Rs" << car.pricePerDay << "\n";
        cout << "Dealer: " << car.dealer << "\n";
        cout << "Year: " << car.year << "\n";
        cout << "Mileage: " << car.mileage << "\n";
        cout << "Engine Capacity: " << car.engineCapacity << "\n";
        cout << "Color: " << car.colors << "\n";
        cout << "Availability: " << (car.isAvailable ? "Yes" : "No") << "\n";
        cout << "-----------------------------------\n";
    }
}



// Additional function implementations
void viewAvailableCars()
{
    cout << "\nAvailable Cars:\n";
    bool found = false;
    for (const auto& car : cars)
     {
        if (car.isAvailable)
            {
            car.display();
            found = true;
        }

    }

    if (!found)
        {
        cout << "No cars available at the moment.\n";

    }

}

void loadData()
{
    ifstream file("C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\registration_login.txt");
    if (!file)
        {
        cout << "No existing data found. Starting fresh.\n";
        return;
    }

    User user;
    while (file >> user.username >> user.password >> user.role)
        {
        users.push_back(user);
    }
    file.close();
    cout << "User data loaded successfully.\n";
}

void saveData()
 {
    ofstream file("C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\registration_login.txt");
    if (!file)
        {
        cout << "Failed to open file for saving data.\n";
        return;
    }

    for (const auto& user : users)
        {
        file << user.username << " " << user.password << " " << user.role << "\n";
    }

    file.close();
    cout << "User data saved successfully.\n";
}

void rentCar(const string& username)
{
    cout << "\nAvailable Cars for Rent:\n";
    vector<Car1*> availableCars;
    for (auto& car : cars)
    {
        if (car.isAvailable)
            {
            car.display();
            availableCars.push_back(&car);
        }

    }

    if (availableCars.empty())
        {
        cout << "No cars available for rent.\n";
        return;
    }

    string carId;
    cout << "\nEnter Car ID to rent: ";
    cin >> carId;

    for (auto car : availableCars)
    {
        if (car->id == carId)
            {
            car->isAvailable = false;
            Rental newRental;
            newRental.rentalId = "R" + to_string(rentals.size() + 1);
            newRental.username = username;
            newRental.carId = carId;
            newRental.startDate = getCurrentTimestamp();
            newRental.isActive = true;
            rentals.push_back(newRental);
            cout << "Car rented successfully!\n";
            return;

        }

    }

    cout << "Invalid Car ID.\n";
}

void returnCar(const string& username)
 {
    cout << "\nYour Active Rentals:\n";
    bool found = false;
    for (auto& rental : rentals)
    {
        if (rental.username == username && rental.isActive)
            {
            for (auto& car : cars)
            {
                if (car.id == rental.carId)
                    {
                    car.display();
                    found = true;

                }

            }

        }

    }

    if (!found)
        {
        cout << "No active rentals found.\n";
        return;

    }

    string carId;
    cout << "\nEnter Car ID to return: ";
    cin >> carId;

    for (auto& rental : rentals)
    {
        if (rental.username == username && rental.carId == carId && rental.isActive)
            {
            rental.isActive = false;
            rental.endDate = getCurrentTimestamp();
            for (auto& car : cars)
             {
                if (car.id == carId)
                    {
                    car.isAvailable = true;
                }

            }

            cout << "Car returned successfully!\n";
            return;
        }

    }

    cout << "Invalid Car ID or no active rental found.\n";
}

void viewRentalHistory(const string& username)
{
    cout << "\nRental History:\n";
    bool found = false;
    for (const auto& rental : rentals)
     {
        if (rental.username == username)
            {
            for (const auto& car : cars)
            {
                if (car.id == rental.carId)
                    {
                    cout << "Rental ID: " << rental.rentalId
                         << " | Car: " << car.brand << " " << car.name
                         << " | Start: " << rental.startDate;
                    if (!rental.isActive)
                        {
                        cout << " | End: " << rental.endDate;
                    }
                    cout << " | Status: " << (rental.isActive ? "Active" : "Returned") << endl;
                    found = true;
                }

            }

        }

    }
    if (!found)
        {
        cout << "No rental history found.\n";
    }

}

void displayUserProfile(const string& username)
 {
    for (const auto& user : users)
     {
        if (user.username == username)
            {
            cout << "\nUser Profile:\n";
            cout << "Username: " << user.username << endl;
            cout << "Role: " << user.role << endl;
            cout << "Full Name: " << user.fullName << endl;
            cout << "Contact: " << user.contact << endl;
            cout << "Email: " << user.email << endl;
            return;

        }

    }
    cout << "User not found.\n";
}

void updateUserProfile(const string& username)
{
    for (auto& user : users)
        {
        if (user.username == username)
        {
            cout << "\nUpdate Profile:\n";
            cout << "Enter new full name (or press enter to skip): ";
            string input;
            cin.ignore();
            getline(cin, input);
            if (!input.empty()) user.fullName = input;

            cout << "Enter new contact (or press enter to skip): ";
            getline(cin, input);
            if (!input.empty()) user.contact = input;

            cout << "Enter new email (or press enter to skip): ";
            getline(cin, input);
            if (!input.empty()) user.email = input;

            saveData();
            cout << "Profile updated successfully!\n";
            return;
        }

    }

    cout << "User not found.\n";

}

void addCar(const string& dealer, const string& filePathCar) {
    Car1 newCar;
    newCar.dealer = dealer;

    cout << "\nAdd New Car:\n";
    cout << "Enter car brand: ";
    cin.ignore();
    getline(cin, newCar.brand);

    cout << "Enter car name: ";
    getline(cin, newCar.name);

    cout << "Enter car type (Petrol/Electric): ";
    getline(cin, newCar.type);

    cout << "Enter car cost: ";
    getline(cin, newCar.cost);

    cout << "Enter engine CC (or N/A for Electric): ";
    getline(cin, newCar.cc);

    cout << "Enter model year: ";
    getline(cin, newCar.modelYear);

    cout << "Enter mileage: ";
    getline(cin, newCar.mileage);

    cars.push_back(newCar); // This will work since cars is vector<Car1>

    ofstream outFile(filePathCar, ios::app);
    if (!outFile) {
        cout << "Error: Could not open the file for appending.\n";
        return;
    }

    outFile << "Dealer: " << newCar.dealer << "\n";
    outFile << "Brand: " << newCar.brand << "\n";
    outFile << "Car: " << newCar.name << "\n";
    outFile << "Type: " << newCar.type << "\n";
    outFile << "Cost: " << newCar.cost << "\n";
    outFile << "CC: " << newCar.cc << "\n";
    outFile << "Model Year: " << newCar.modelYear << "\n";
    outFile << "Mileage: " << newCar.mileage << "\n\n";

    outFile.close();
    cout << "Car added successfully!\n";
}

void removeCar(const string& dealer, const string& filePathCar) {
    cout << "\nYour Cars:\n";
    vector<Car1*> dealerCars;

    for (auto& car : cars) {
        if (car.dealer == dealer) {
            cout << "Car: " << car.name << " (" << car.brand << ")\n";
            dealerCars.push_back(&car);
        }
    }

    if (dealerCars.empty()) {
        cout << "You have no cars listed.\n";
        return;
    }

    string carName;
    cout << "\nEnter the name of the car to remove: ";
    cin.ignore();
    getline(cin, carName);

    auto it = remove_if(cars.begin(), cars.end(),
        [&](const Car1& car) { return car.name == carName && car.dealer == dealer; });

    if (it != cars.end()) {
        cars.erase(it, cars.end());
        cout << "Car removed successfully!\n";

        // Rewrite the file
        ofstream outFile(filePathCar);
        if (!outFile) {
            cout << "Error: Could not open the file for updating.\n";
            return;
        }

        for (const auto& car : cars) {
            outFile << "Dealer: " << car.dealer << "\n";
            outFile << "Brand: " << car.brand << "\n";
            outFile << "Car: " << car.name << "\n";
            outFile << "Type: " << car.type << "\n";
            outFile << "Cost: " << car.cost << "\n";
            outFile << "CC: " << car.cc << "\n";
            outFile << "Model Year: " << car.modelYear << "\n";
            outFile << "Mileage: " << car.mileage << "\n\n";
        }

        outFile.close();
    } else {
        cout << "Car not found or you don't have permission to remove it.\n";
    }
}

// Function to log login history
void logLoginHistory(const string& username, const string& role)
{
    string timestamp = getCurrentTimestamp();
    string logFile = (role == "User") ? userLoginHistoryFile : (role == "Dealer") ? dealerLoginHistoryFile : adminLoginHistoryFile;

    ofstream outFile(logFile, ios::app); // Open in append mode
    if (!outFile)
        {
        cout << "Could not open log file for writing: " << logFile << endl;
        return;
    }

    outFile << "Username: " << username << " | Role: " << role << " | Login Time: " << timestamp << endl;
    outFile.close();
}
// Function to display login history on the screen
void displayLoginHistory(const string& username, const string& role)
{
    string logFile = (role == "User") ? userLoginHistoryFile : (role == "Dealer") ? dealerLoginHistoryFile : adminLoginHistoryFile;

    ifstream inFile(logFile);
    if (!inFile)
        {
        cout << "Could not open log file for reading: " << logFile << endl;
        return;
    }

    string line;
    stringstream history;
    while (getline(inFile, line))
        {
        if (line.find("Username: " + username) != string::npos)
            {
            history << line << endl;
        }

    }

    if (history.str().empty())
        {
        cout << "\nNo login history found for " << username << " in " << role << " role." << endl;
    }
    else
    {
        cout << "----------------------------------------------------------------";
        cout << "\nLogin history for " << username << " (" << role << "):\n";
        cout << "----------------------------------------------------------------\n";
        cout << history.str();
        cout << "----------------------------------------------------------------\n";
    }


    inFile.close();
}

void displayCarStatistics()
{
    cout << "\nCar Statistics:\n";
    int totalCars = cars.size();
    int availableCars = count_if(cars.begin(), cars.end(),
        [](const Car1& car) { return car.isAvailable; });
    int rentedCars = totalCars - availableCars;


    cout << "Total Cars: " << totalCars << endl;
    cout << "Available Cars: " << availableCars << endl;
    cout << "Rented Cars: " << rentedCars << endl;


    if (totalCars > 0)
        {

        cout << "\nCar Brands Distribution:\n";
        map<string, int> brandCount;
        for (const auto& car : cars)
        {

            brandCount[car.brand]++;

        }

        for (const auto& pair : brandCount) {

            cout << pair.first << ": " << pair.second << " cars\n";

        }

    }

}

void viewAllCars()
 {
    cout << "\nAll Cars in System:\n";
    if (cars.empty())
        {
        cout << "No cars in the system.\n";
        return;
    }

    for (const auto& car : cars)
        {
        car.display();

    }

}

void generateReport()
{
    cout << "\nSystem Report:\n";
    cout << "1. User Statistics:\n";
    cout << "Total Users: " << users.size() << endl;
    int userCount = count_if(users.begin(), users.end(),
        [](const User& u) { return u.role == "User"; });
    int dealerCount = count_if(users.begin(), users.end(),
        [](const User& u) { return u.role == "Dealer"; });
    cout << "Regular Users: " << userCount << endl;
    cout << "Dealers: " << dealerCount << endl;

    cout << "\n2. Car Statistics:\n";
    displayCarStatistics();

    cout << "\n3. Rental Statistics:\n";
    int activeRentals = count_if(rentals.begin(), rentals.end(),
        [](const Rental& r) { return r.isActive; });
    cout << "Total Rentals: " << rentals.size() << endl;
    cout << "Active Rentals: " << activeRentals << endl;
    cout << "Completed Rentals: " << rentals.size() - activeRentals << endl;

}

void manageUsers()
{
    while (true)
        {
        cout << "\nUser Management:\n";
        cout << "1. View All Users\n";
        cout << "2. Delete User\n";
        cout << "3. Back to Admin Dashboard\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                viewAllUsers();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice!\n";

        }

    }

}
void addCar1(const string& dealer, const string& filePathCar) {
    Car1 newCar;
    newCar.dealer = dealer;

    cout << "\nAdd New Car:\n";
    cout << "Enter car brand: ";
    cin.ignore();
    getline(cin, newCar.brand);

    cout << "Enter car name: ";
    getline(cin, newCar.name);

    cout << "Enter car type (Petrol/Electric): ";
    getline(cin, newCar.type);

    cout << "Enter car cost: ";
    getline(cin, newCar.cost);

    cout << "Enter engine CC (or N/A for Electric): ";
    getline(cin, newCar.cc);

    cout << "Enter model year: ";
    getline(cin, newCar.modelYear);

    cout << "Enter mileage: ";
    getline(cin, newCar.mileage);

    cars.push_back(newCar); // This will work since cars is vector<Car1>

    ofstream outFile(filePathCar, ios::app);
    if (!outFile) {
        cout << "Error: Could not open the file for appending.\n";
        return;
    }

    outFile << "Dealer: " << newCar.dealer << "\n";
    outFile << "Brand: " << newCar.brand << "\n";
    outFile << "Car: " << newCar.name << "\n";
    outFile << "Type: " << newCar.type << "\n";
    outFile << "Cost: " << newCar.cost << "\n";
    outFile << "CC: " << newCar.cc << "\n";
    outFile << "Model Year: " << newCar.modelYear << "\n";
    outFile << "Mileage: " << newCar.mileage << "\n\n";

    outFile.close();
    cout << "Car added successfully!\n";
}

void removeCar1(const string& dealer, const string& filePathCar) {
    cout << "\nYour Cars:\n";
    vector<Car1*> dealerCars;

    for (auto& car : cars) {
        if (car.dealer == dealer) {
            cout << "Car: " << car.name << " (" << car.brand << ")\n";
            dealerCars.push_back(&car);
        }
    }

    if (dealerCars.empty()) {
        cout << "You have no cars listed.\n";
        return;
    }

    string carName;
    cout << "\nEnter the name of the car to remove: ";
    cin.ignore();
    getline(cin, carName);
}

void displayWelcomeMessage() {
    cout << "**********************************************************************************************************************************\n";
    cout << "*                                                                                                                                *\n";
    cout << "*                                                SECOND SPIN RENTALS                                                             *\n";
    cout << "*                                            Premium Car Rental Service                                                          *\n";
    cout << "*                                                                                                                                *\n";
    cout << "**********************************************************************************************************************************\n";
}

// Load cars from the file
// Load cars from the file

vector<Car> loadCars(const string& filePathCar) {
    vector<Car> cars;
    ifstream file(filePathCar);

    if (!file) {
        cout << "Error: Could not open the file '" << filePathCar << "'\n";
        return cars;
    }

    string line, dealer, brand, name, type, cost, cc, modelYear, mileage;

    while (getline(file, line)) {

        if (line.empty()) continue;

        if (line.rfind("Dealer:", 0) == 0 && line.size() > 8) {
            dealer = line.substr(8);
        } else if (line.rfind("Brand:", 0) == 0 && line.size() > 7) {
            brand = line.substr(7);
        } else if (line.rfind("Car:", 0) == 0 && line.size() > 5) {
            name = line.substr(5);
        } else if (line.rfind("Type:", 0) == 0 && line.size() > 6) {
            type = line.substr(6);
        } else if (line.rfind("Cost:", 0) == 0 && line.size() > 6) {
            cost = line.substr(6);
        } else if (line.rfind("CC:", 0) == 0 && line.size() > 3) {
            cc = line.substr(3);
        } else if (line.rfind("Model Year:", 0) == 0 && line.size() > 12) {
            modelYear = line.substr(12);
        } else if (line.rfind("Mileage:", 0) == 0 && line.size() > 8) {
            mileage = line.substr(8);
            cars.push_back({dealer, brand, name, type, cost, cc, modelYear, mileage});

            // Reset variables
            dealer = brand = name = type = cost = cc = modelYear = mileage = "";
        }
    }

    file.close();
    return cars;
}

// Load bikes from the file

vector<Bike> loadBikes(const string& filePathBike) {
    vector<Bike> bikes;
    ifstream file(filePathBike);

    if (!file) {
        cout << "Error: Could not open the file '" << filePathBike << "'\n";
        return bikes;
    }

    string line, dealer, brand, name, type, cost, cc, modelYear, mileage;
    while (getline(file, line)) {
        if (line.rfind("Dealer:", 0) == 0 && line.size() > 8) {
            dealer = line.substr(8);
        } else if (line.rfind("Brand:", 0) == 0 && line.size() > 7) {
            brand = line.substr(7);
        } else if (line.rfind("Bike:", 0) == 0 && line.size() > 5) {
            name = line.substr(5);
        } else if (line.rfind("Type:", 0) == 0 && line.size() > 6) {
            type = line.substr(6);
        } else if (line.rfind("Cost:", 0) == 0 && line.size() > 6) {
            cost = line.substr(6);
        } else if (line.rfind("Engine CC:", 0) == 0 && line.size() > 10) {
            cc = line.substr(10);
        } else if (line.rfind("Model Year:", 0) == 0 && line.size() > 12) {
            modelYear = line.substr(12);
        } else if (line.rfind("Mileage:", 0) == 0 && line.size() > 8) {
            mileage = line.substr(8);
            bikes.push_back({dealer, brand, name, type, cost, cc, modelYear, mileage});
        } else if (!line.empty()) {
            cout << "Warning: Skipping malformed line: " << line << endl;
        }
    }

    return bikes;
}


// Rabin-Karp algorithm for searching patterns

bool rabinKarpSearch(const string& text, const string& pattern)

{
    int m = pattern.size();
    int n = text.size();

    const int d = 256;
     // Number of characters in the input alphabet
    const int q = 101;
     // A prime number for hashing

    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;

    }

    int patternHash = 0, textHash = 0;
    for (int i = 0; i < m; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % q;
        textHash = (d * textHash + text[i]) % q;

    }

    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == textHash)
        {
            if (text.substr(i, m) == pattern)
            {
                return true;
            }
        }

        if (i < n - m)
            {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % q;
            if (textHash < 0)
            {
                textHash += q;
            }
        }
    }


    return false;
}

// KMP algorithm for searching patterns

bool kmpSearch(const string& text, const string& pattern)
{
    int m = pattern.size();
    int n = text.size();

    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m)

    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            } else
            {
                lps[i] = 0;
                i++;
            }

        }

    }

    i = 0;
    int j = 0;
    while (i < n)
        {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
            {
            return true;
        }
        else if (i < n && pattern[j] != text[i])
            {
            if (j != 0)
             {
                j = lps[j - 1];

            }
            else
                {
                i++;
            }

        }

    }

    return false;
}




// Function to search cars by brand
// Function to search cars by brand

void searchByBrand(const vector<Car>& cars, const string& type)

{
    cout << "\n-------------------------------------------------------\n";
    cout << "Enter brand to search for: ";
    string brandSearch;
    cin.ignore();

    getline(cin, brandSearch);
    cout << "\n-------------------------------------------------------\n";


    bool found = false;
    for (const auto& car : cars)
    {
        if (kmpSearch(car.type, type) && rabinKarpSearch(car.brand, brandSearch))
        {

            car.display();
            found = true;

        }

    }

    if (!found)
    {

        cout << "No cars found for the specified brand.\n";

    }

}




void registerUser(const string& role)
 {
    User newUser;
    cout << "\nEnter username: ";
    cin >> newUser.username;

    // Check if username already exists
    auto it = find_if(users.begin(), users.end(), [&](const User& u) { return u.username == newUser.username; });
    if (it != users.end()) {
        cout << "Username already exists! Please try again.\n";
        return;

    }

    cout << "Enter password: ";
    char ch;
    while ((ch = _getch()) != '\r') { // '\r' is Enter key
        if (ch == '\b') { // Handle backspace
            if (!newUser.password.empty()) {
                cout << "\b \b";
                newUser.password.pop_back();

            }

        }

        else
        {
            newUser.password.push_back(ch);
            cout << "*";

        }

    }

    cout << endl;

    newUser.role = role;
    users.push_back(newUser);
    saveData();
    cout << "Registration successful for " << role << ".\n";

}









// Function to search cars by name or dealer
// Function to search cars by name or dealer

void searchByCarOrDealer(const vector<Car>& cars, const string& type)

{
    cout << "\n======================================================================\n";
    cout << "Search by:\n";
    cout << "======================================================================\n";
    cout << "1. Car Name\n";
    cout << "2. Dealer\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    cout << "Enter search term: ";
    string searchTerm;
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (const auto& car : cars)

    {
        if (kmpSearch(car.type, type))
        {  // Match only the selected car type
            if ((choice == 1 && rabinKarpSearch(car.name, searchTerm)) ||
                (choice == 2 && rabinKarpSearch(car.dealer, searchTerm)))
            {
                car.display();
                found = true;
            }

        }

    }

    if (!found)
    {

        cout << "No matching cars found.\n";

    }

}




// Function to display bikes by type (Petrol or Electric)



void displayBikesByType(const vector<Bike>& bikes, const string& type)

{
    cout << "\nDisplaying " << type << " bikes:\n";
    for (const auto& bike : bikes)
    {
        if (rabinKarpSearch(bike.type, type))
        {
            // Use Rabin-Karp to match the type
            bike.display();

        }

    }

}







void userDashboard(const string& username)
{
    while (true) {
        cout << "\nUser Dashboard\n";
        cout << "1. View Available Cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n";
        cout << "4. View Rental History\n";
        cout << "5. Search Cars\n";
        cout << "6. View/Update Profile\n";
        cout << "7. Logout\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1: viewAvailableCars();
             break;
            case 2: rentCar(username);
            break;
            case 3: returnCar(username);
            break;
            case 4: viewRentalHistory(username);
            break;
            case 5: searchCars();
            break;
            case 6: {

                displayUserProfile(username);
                cout << "Update profile? (y/n): ";
                char update;
                cin >> update;
                if (update == 'y' || update == 'Y')
                    updateUserProfile(username);
                break;

            }
            case 7: return;
            default: cout << "Invalid choice!\n";
        }

    }

}




void dealerDashboard(const string& username)
 {
    while (true)
        {
        cout << "\nDealer Dashboard\n";
        //cout << "1. View My Cars\n";
        cout << "1. View Active Rentals\n";
        cout << "2. Car Statistics\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {

            /*case 1: {
                cout << "\nMy Cars:\n";
                for (const auto& car : cars)
                    {
                    if (car.dealer == username)
                        car.display();
                }

                break;

            }*/

            case 1: {
                cout << "\nActive Rentals:\n";
                for (const auto& rental : rentals)
                    {
                    if (rental.isActive) {
                        auto car = find_if(cars.begin(), cars.end(),
                            [&](const Car1& c) { return c.id == rental.carId && c.dealer == username; });
                        if (car != cars.end()) {
                            cout << "Rental ID: " << rental.rentalId
                                 << " | User: " << rental.username
                                 << " | Car: " << car->name << endl;
                        }

                    }

                }

                break;

            }

            case 2: displayCarStatistics();
            break;

            case 3:
                return;

            default: cout << "Invalid choice!\n";
        }

    }

}




void adminDashboard()
{
    while (true)
        {
        cout <<"==============================================================================\n";
        cout << "Admin Dashboard\n";
        cout <<"==============================================================================\n";
        cout << "1. View All Users\n";
        //cout << "2. View All Cars\n";
        //cout << "3. View All Rentals\n";
        cout << "2. Generate Reports\n";
        cout << "3. Manage Users\n";
        cout << "4. Logout\n";
        cout <<"------------------------------------------------------------------------------\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {

            case 1:
                {

                cout << "\nAll Users:\n";
                for (const auto& user : users)
                    {

                    cout << "Username: " << user.username
                         << " | Role: " << user.role
                         << " | Name: " << user.fullName << endl;

                }

                break;

            }

           // case 2: viewAllCars(); break;
            /*case 3: {
                cout << "\nAll Rentals:\n";
                for (const auto& rental : rentals)
                    {
                    cout << "ID: " << rental.rentalId
                         << " | User: " << rental.username
                         << " | Car ID: " << rental.carId
                         << " | Active: " << (rental.isActive ? "Yes" : "No") << endl;

                }

                break;

            }*/
            case 2: generateReport();
            break;

            case 3: manageUsers();
            break;

            case 4: return;
            default: cout << "Invalid choice!\n";

        }

    }

}




void searchCars()
{
    cout << "\nSearch by:\n";
    cout << "1. Brand\n";
    cout << "2. Price Range\n";
    cout << "3. Year\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1: {
            string brand;

            cout << "Enter brand: ";
            cin >> brand;

            for (const auto& car : cars)
                {

                if (car.brand == brand && car.isAvailable)
                    car.display();
            }

            break;

        }

        case 2: {
            double min, max;
            cout << "Enter min price: ";
            cin >> min;

            cout << "Enter max price: ";
            cin >> max;

            for (const auto& car : cars)
                {

                if (car.pricePerDay >= min && car.pricePerDay <= max && car.isAvailable)
                    car.display();
            }

            break;

        }

        case 3: {
            int year;

            cout << "Enter year: ";

            cin >> year;

            for (const auto& car : cars)
                {

                if (car.year == year && car.isAvailable)
                    car.display();

            }

            break;
        }

        default:
            cout << "Invalid choice!\n";

    }

}




string generateId(const string& prefix)
{

    static int counter = 1;

    stringstream ss;

    ss << prefix << setw(4) << setfill('0') << counter++;

    return ss.str();


}

void logAction(const string& username, const string& action)

{

    ofstream logFile(loginHistoryFile, ios::app);

    time_t now = time(0);

    char* dt = ctime(&now);

    logFile << username << " | " << action << " | " << dt;

    logFile.close();

}




void forgotPassword()
{

    string username;

    cout << "\nEnter your username: ";
    cin >> username;

    // Check if username exists
    auto it = find_if(users.begin(), users.end(),

        [&username](const User& user) { return user.username == username; });

    if (it == users.end())
        {
        cout << "Username not found!\n";
        return;
    }

    if (verifySecurityQuestion(username))

    {
        if (resetPassword(username))
            {
            cout << "Password has been successfully reset!\n";
        }
         else
         {
            cout << "Failed to reset password.\n";
        }
    }
     else
    {
        cout << "Incorrect security answer. Password reset failed.\n";

    }

}




//              Google Map
void showDealerLocation(const std::string& dealerName)
{

    std::map<std::string, std::string> dealerLocations = {
        {"Adesh", "https://www.google.com/maps?q=15.864476,74.480626"},
        {"Abhishek", "https://www.google.com/maps?q=15.838434,74.504389"},
        {"Shek", "https://www.google.com/maps?q=15.881335,74.524701"} // Coordinates for Shek
    };



    auto it = dealerLocations.find(dealerName);

    if (it != dealerLocations.end())
        {

        std::string url = "start chrome \"" + it->second + "\""; // For Windows; adjust for other OS
        system(url.c_str());
    }
    else
    {

        std::cout << "Location for dealer \"" << dealerName << "\" not found.\n";

    }
}






bool verifySecurityQuestion(const string& username)

{

    string answer;
    for (const auto& user : users)
    {

        if (user.username == username)
            {

            cout << "\nSecurity Question: " << user.securityQuestion << endl;
            cout << "Enter your answer: ";
            cin.ignore();
            getline(cin, answer);
            return (answer == user.securityAnswer);
        }

    }

    return false;
}






bool resetPassword(const string& username)
 {


    string newPassword;
    cout << "\nEnter new password: ";

    char ch;
    while ((ch = _getch()) != '\r')

        {
        if (ch == '\b')
        {
            if (!newPassword.empty())
                {
                cout << "\b \b";
                newPassword.pop_back();

            }



        }



        else
        {
            newPassword.push_back(ch);
            cout << "*";

        }



    }



    cout << endl;

    // Update password in users vector
    for (auto& user : users)
     {

        if (user.username == username)
            {
            user.password = newPassword;
            saveData();
            return true;

        }



    }



    return false;
}

string getCurrentTimestamp()
 {


    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);


}






void viewAllUsers()
{

    cout << "\nList of All Registered Users:\n";
    for (const auto& user : users)
        {

        cout << "Username: " << user.username << " | Role: " << user.role << "\n";

    }

}




void deleteUser()
 {


    string username;
    cout << "\nEnter username to delete: ";
    cin >> username;

    auto it = remove_if(users.begin(), users.end(),
        [&username](const User& user) { return user.username == username; });

    if (it != users.end())
        {
        users.erase(it, users.end());
        saveData();
        cout << "User " << username << " deleted successfully.\n";
    }


    else
    {
        cout << "User " << username << " not found.\n";
    }


}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                          Module 1 end here
//----------------------------------------------------------------------------------------------------------------------------------------------------------



// Function to search bikes by brand




void searchByBrandBike(const vector<Bike>& bikes, const string& type)

{


    cout << "\n-------------------------------------------------------\n";
    cout << "Enter brand to search for: ";
    string brandSearch;
    cin.ignore();

    getline(cin, brandSearch);
    cout << "\n-------------------------------------------------------\n";

    bool found = false;


    for (const auto& bike : bikes)
    {


        if (rabinKarpSearch(bike.type, type) && rabinKarpSearch(bike.brand, brandSearch))
        {

            bike.display();
            found = true;

        }

    }

    if (!found)
    {

        cout << "No bikes found for the specified brand.\n";

    }


}






// Function to search bikes by name or dealer

void searchByBikeOrDealer(const vector<Bike>& bikes, const string& type)
{


    cout << "\n======================================================================\n";
    cout << "Search by:\n";
    cout << "======================================================================\n";
    cout << "1. Bike Name\n";
    cout << "2. Dealer\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    cout << "Enter search term: ";
    string searchTerm;
    cin.ignore();

    getline(cin, searchTerm);

    bool found = false;
    for (const auto& bike : bikes)
    {

        if (rabinKarpSearch(bike.type, type))
        {

            // Match only the selected bike type

            if ((choice == 1 && rabinKarpSearch(bike.name, searchTerm)) ||
                (choice == 2 && rabinKarpSearch(bike.dealer, searchTerm)))
            {
                bike.display();
                found = true;
            }

        }

    }

    if (!found)
    {

        cout << "No matching bikes found.\n";

    }

}





// Function to make a booking Bike





void bookBike(vector<Bike>& bikes)

{

    cout << "\nEnter the bike name you want to book: ";
    string bikeName;

    cin.ignore();
     // Clear the input buffer

    getline(cin, bikeName);
      // Get the bike name entered by the user

    bool found = false;
    for (auto& bike : bikes)

    {

        if (bike.name == bikeName)

        {
            found = true;

            // Confirm booking

            cout << "\nBooking successful for: " << bike.name << " from dealer: " << bike.dealer << "\n";
            break;

        }

    }

    if (!found)

    {

        cout << "Bike not found.\n";

    }

}



// Function to cancel a booking Bike





void cancelBooking(vector<Bike>& bikes)
{

    cout << "\nEnter the bike name you want to cancel the booking for: ";
    string bikeName;
    cin.ignore();
     // Clear the input buffer
    getline(cin, bikeName);
    // Get the bike name entered by the user

    bool found = false;
    for (auto& bike : bikes)

    {

        if (bike.name == bikeName)
        {
            found = true;
            // Cancel booking
            cout << "\nBooking canceled for: " << bike.name << " from dealer: " << bike.dealer << "\n";
            break;

        }

    }

    if (!found)
    {

        cout << "Bike not found.\n";

    }

}



// Function to handle the purchase of a bike



void purchaseBike(vector<Bike>& bikes)

{

    cout << "\nEnter the name of the Bike you want to purchase: ";
    string bikeName;
    cin.ignore();
    // Clear the input buffer
    getline(cin, bikeName);

    vector<Bike> matchingBikes;
    for (const auto& bike : bikes)

    {

        if (rabinKarpSearch(bike.name, bikeName))

        {

            matchingBikes.push_back(bike);

        }

    }

    if (matchingBikes.empty())

    {
        cout << "No bikes found with that name.\n";
        return;
    }

    cout << "\nMatching bikes found:\n";
    for (size_t i = 0; i < matchingBikes.size(); ++i)

    {
        cout << i + 1 << ". ";
        matchingBikes[i].display();

    }

    cout << "\nChoose a dealer (enter the number): ";
    int dealerChoice;
    cin >> dealerChoice;

    if (dealerChoice < 1 || dealerChoice > matchingBikes.size())

    {

        cout << "Invalid choice.\n";
        return;

    }



    Bike selectedBike = matchingBikes[dealerChoice - 1];
    cout << "\nYou selected: ";
    selectedBike.display();
    cout << "\n======================================================================\n";
    cout << "Choose payment method:\n";
    cout << "======================================================================\n";
    cout << "1. Debit Card"<<endl;
    cout <<" 2. Credit Card"<<endl;
    cout <<" 3. Cash:"<<endl;
    cout <<"----------------------------------------------------------------------\n";
    int paymentMethod;
    cin >> paymentMethod;

    string payment;
    switch (paymentMethod)

    {
        case 1: payment = "Debit Card"; break;
        case 2: payment = "Credit Card"; break;
        case 3: payment = "Cash"; break;
        default: cout << "Invalid payment method.\n"; return;

    }

    cout << "\nPayment successful via " << payment << ".\n";

    // Collect feedback for the dealer
    cout << "\nEnter your feedback for the dealer: ";
    cin.ignore();  // Clear the input buffer
    string dealerFeedback;
    getline(cin, dealerFeedback);

    // Collect feedback for the system
    cout << "\nEnter your feedback for the system: ";
    string systemFeedback;
    getline(cin, systemFeedback);

    cout << "\nThank you for your feedback!\n";

}





// Function to display cars by type (Petrol or Electric)
void displayCarsByType(const vector<Car>& cars, const string& type)
{

    cout << "\nDisplaying " << type << " cars:\n";

    for (const auto& car : cars)
        {
        if (kmpSearch(car.type, type))

        {  // Use KMP to match the type
            car.display();

        }

    }

}

void savePurchaseAndBookingDetails(const vector<Car>& cars, const string& filePathCar)
{

    ofstream file(filePathCar, ios::app);
     // Open in append mode to keep old records

    if (!file)

    {

        cout << "Error: Could not open the file for saving purchase and booking details: " << filePathCar << "\n";
        return;

    }

    file << "-------------------- Purchase and Booking Details --------------------\n";

    // Loop through the cars and save details of booked and purchased cars
    for (const auto& car : cars)

    {


        if (car.booked || car.purchased)

        {

            file << "Dealer: " << car.dealer << "\n";
            file << "Brand: " << car.brand << "\n";
            file << "Car: " << car.name << "\n";
            file << "Type: " << car.type << "\n";
            file << "Cost: " << car.cost << "\n";
            file << "CC: " << car.cc << "\n";
            file << "Model Year: " << car.modelYear << "\n";
            file << "Mileage: " << car.mileage << "\n";

            // Add booking or purchase status
            if (car.purchased)

            {

                file << "Status: Purchased\n";

            }

            else if (car.booked)

            {
                file << "Status: Booked\n";

            }

            file << "--------------------------------------------------------------------\n";


        }


    }

    cout << "Purchase and booking details saved successfully to the file.\n";

}





void purchaseCar(std::vector<Car>& cars, const string& type)

{
    const string filePathPurchase = "C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\Purchase_and_booking.txt";  // File path

    cout << "\nEnter the car name you want to purchase: ";
    string carName;
    cin.ignore();
     // Clear the input buffer
    getline(cin, carName);
    // Get the car name entered by the user

    // Searching for the car in the list
    vector<Car*> matchingCars;
     // Changed to hold pointers to Car (non-const)
    for (auto& car : cars)

    {
        if (car.name == carName && car.type == type && !car.booked)
        {
            matchingCars.push_back(&car);

        }

    }

    if (matchingCars.empty())

    {
        cout << "Car not found or already booked.\n";
        return;
    }

    Car* selectedCar = nullptr;

    // If multiple dealers have the same car, ask the user to select a dealer
    if (matchingCars.size() > 1)

    {
        cout << "\nMultiple dealers have this car. Please choose the dealer from which you want to buy:\n";
        for (size_t i = 0; i < matchingCars.size(); ++i)

        {

            cout << i + 1 << ". Dealer: " << matchingCars[i]->dealer
                 << ", Price: " << matchingCars[i]->cost << "\n";
        }

        cout << "Enter the dealer number (1-" << matchingCars.size() << "): ";
        int dealerChoice;
        cin >> dealerChoice;

        if (dealerChoice < 1 || dealerChoice > matchingCars.size())

        {

            cout << "Invalid choice.\n";
            return;

        }

        selectedCar = matchingCars[dealerChoice - 1];
         // Select the chosen car
        cout << "\nYou selected " << selectedCar->name << " from dealer " << selectedCar->dealer << ".\n";

    }

    else

    {

        selectedCar = matchingCars[0];  // If only one dealer has the car, use that one
        cout << "\nYou selected " << selectedCar->name << " from dealer " << selectedCar->dealer << ".\n";

    }

    // Take customer's name
    cout << "\nEnter your name: ";
    string customerName;
    cin.ignore();
    // Clear input buffer before taking the name
    getline(cin, customerName);

    // Payment Methods
    cout << "\n======================================================================\n";
    cout << "Payment Methods:\n";
    cout << "\n======================================================================\n";
    cout << "1. Credit Card\n";
    cout << "2. Debit Card\n";
    cout << "3. Cash\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "Enter your choice: ";
    int paymentChoice;
    cin >> paymentChoice;

    string paymentMethod;
    switch (paymentChoice)

    {
        case 1: paymentMethod = "Credit Card";
        break;

        case 2: paymentMethod = "Debit Card";
        break;

        case 3: paymentMethod = "Cash";
        break;

        default: paymentMethod = "Invalid";
        break;

    }

    // Ask if the user wants to print the bill
    cout << "\nWould you like to print the bill?: ";
    cout << "\n1.Yes \n";
    cout << "2.No\n";
    int printBill;
    cin >> printBill;

    if (printBill == 1)

    {

        cout << "\n=======================================================================\n";

        cout << "|                           Bill Generated                             |\n";

        cout << "\n=======================================================================\n";

        cout << "| Customer Name: |" << customerName <<                                "\n";

        cout << "| Car Purchased: |" << selectedCar->name <<                           "\n";

        cout << "| Brand:         |" << selectedCar->brand <<                          "\n";

        cout << "| Dealer:        |" << selectedCar->dealer <<                         "\n";

        cout << "| Cost:          |" << selectedCar->cost <<                           "\n";

        cout << "| CC:            |" << selectedCar->cc <<                             "\n";

        cout << "| Model Year:    |" << selectedCar->modelYear <<                      "\n";

        cout << "| Mileage:       |" << selectedCar->mileage <<                        "\n";

        cout << "| Payment Method:|" << paymentMethod <<                               "\n";

        cout << "------------------------------------------------------------------------\n";


    }

    // Save purchase details to the file

    ofstream outFile(filePathPurchase, ios::app);
    // Open in append mode
    if (outFile.is_open())

    {
        outFile << "Purchase Details:\n";

        outFile << "Customer Name: " << customerName << "\n";

        outFile << "Car Purchased: " << selectedCar->name << "\n";

        outFile << "Brand: " << selectedCar->brand << "\n";

        outFile << "Dealer: " << selectedCar->dealer << "\n";

        outFile << "Cost: " << selectedCar->cost << "\n";

        outFile << "CC: " << selectedCar->cc << "\n";

        outFile << "Model Year: " << selectedCar->modelYear << "\n";

        outFile << "Mileage: " << selectedCar->mileage << "\n";

        outFile << "Payment Method: " << paymentMethod << "\n";

        outFile << "-------------------------------------------------------\n";

        outFile.close();
         // Close the file after writing

    }

    else
    {
        cout << "Error saving purchase details.\n";
    }



    // Mark the car as purchased
    selectedCar->booked = true;

    char showLocation;
    cout << "\n\n========================================================================\n";
    cout << "Would you like to view the Google Maps location of the dealer? (y/n): ";
    cout << "\n========================================================================\n";
    cin >> showLocation;

    if (showLocation == 'y' || showLocation == 'Y') {

    showDealerLocation(selectedCar->dealer);

     }



}

void bookCar(std::vector<Car>& cars, const string& type)

{
    const string filePathPurchase = "C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\Purchase_and_booking.txt";  // File path

    cout << "\nEnter the car name you want to book: ";
    string carName;
    cin.ignore();
     // Clear the input buffer
    getline(cin, carName);
     // Get the car name entered by the user

    // Searching for the car in the list

    vector<Car*> matchingCars;
     // Changed to hold pointers to Car (non-const)
    for (auto& car : cars)
    {

        if (car.name == carName && car.type == type && !car.booked)
        {

            matchingCars.push_back(&car);

        }

    }

    if (matchingCars.empty())

    {
        cout << "Car not found or already booked.\n";
        return;

    }

    Car* selectedCar = nullptr;

    // If multiple dealers have the same car, ask the user to select a dealer
    if (matchingCars.size() > 1)

    {
        cout << "\nMultiple dealers have this car. Please choose the dealer from which you want to book:\n";
        for (size_t i = 0; i < matchingCars.size(); ++i)

        {
            cout << i + 1 << ". Dealer: " << matchingCars[i]->dealer
                 << ", Price: " << matchingCars[i]->cost << "\n";

        }

        cout << "Enter the dealer number (1-" << matchingCars.size() << "): ";
        int dealerChoice;
        cin >> dealerChoice;

        if (dealerChoice < 1 || dealerChoice > matchingCars.size())

        {
            cout << "Invalid choice.\n";
            return;
        }


        selectedCar = matchingCars[dealerChoice - 1];
         // Select the chosen car
        cout << "\nYou selected " << selectedCar->name << " from dealer " << selectedCar->dealer << ".\n";

    }
    else

    {

        selectedCar = matchingCars[0];
        // If only one dealer has the car, use that one
        cout << "\nYou selected " << selectedCar->name << " from dealer " << selectedCar->dealer << ".\n";

    }

    // Take customer's name
    cout << "\nEnter your name: ";
    string customerName;
    cin.ignore();
    // Clear input buffer before taking the name
    getline(cin, customerName);
    cout << "Booking Successful !"<<endl;

    // Save booking details to the file
    ofstream outFile(filePathPurchase, ios::app);
     // Open in append mode
    if (outFile.is_open())
    {

        outFile << "Booking Details:\n";

        outFile << "Customer Name: " << customerName << "\n";

        outFile << "Car Booked: " << selectedCar->name << "\n";

        outFile << "Brand: " << selectedCar->brand << "\n";

        outFile << "Dealer: " << selectedCar->dealer << "\n";

        outFile << "Cost: " << selectedCar->cost << "\n";

        outFile << "CC: " << selectedCar->cc << "\n";

        outFile << "Model Year: " << selectedCar->modelYear << "\n";

        outFile << "Mileage: " << selectedCar->mileage << "\n";

        outFile << "-------------------------------------------------------\n";

        outFile.close();
         // Close the file after writing
    }
    else
    {

        cout << "Error saving booking details.\n";

    }

    // Mark the car as booked
    selectedCar->booked = true;

}




void cancelBooking(vector<Car>& cars, const string& type)

{

    cout << "\nEnter the car name you want to cancel booking for: ";
    string carName;
    cin.ignore();
    // Clear the input buffer
    getline(cin, carName);
     // Get the car name entered by the user

    for (auto& car : cars)
    {

        if (car.name == carName && car.type == type)
        {

            if (!car.booked)
            {

                cout << "\nThis car has not been booked yet.\n";
                return;

            }

            car.booked = false;
            cout << "\nYou have successfully canceled the booking for car: " << car.name << ".\n";
            return;

        }

    }

    cout << "\nCar not found.\n";

}





bool adminLogin()
{

    string username, password;
    cout << "\nEnter username: ";
    cin >> username;

    cout << "Enter password: ";
    char ch;
    while ((ch = _getch()) != '\r')
    {

         // '\r' is Enter key
        if (ch == '\b')
        {
             // Handle backspace
            if (!password.empty())
             {

                cout << "\b \b";
                password.pop_back();

            }

        }
         else
        {

            password.push_back(ch);
            cout << "*";

        }

    }

    cout << endl;

    auto it = find_if(users.begin(), users.end(), [&](const User& u)
                      {

        return u.username == username && u.password == password && u.role == "Admin";

    });

    if (it != users.end())
        {

        cout << "Login successful! Welcome " << it->username << " (Admin)\n";
        adminDashboard();  // Call Admin Dashboard
        return true;

    }


    cout << "Invalid credentials or role mismatch.\n";
    return false;

}






bool dealerLogin()
{

    string username, password;
    cout << "\nEnter username: ";
    cin >> username;


    cout << "Enter password: ";
    char ch;
    while ((ch = _getch()) != '\r')
    {  // '\r' is Enter key

        if (ch == '\b')
            {  // Handle backspace

            if (!password.empty())
                {

                cout << "\b \b";
                password.pop_back();

            }

        }
        else
            {

            password.push_back(ch);
            cout << "*";

        }

    }
    cout << endl;

    auto it = find_if(users.begin(), users.end(), [&](const User& u)
                      {

        return u.username == username && u.password == password && u.role == "Dealer";

    });

    if (it != users.end())
        {

        cout << "Login successful! Welcome " << it->username << " (Dealer)\n";
        dealerDashboard(it->username);  // Call Dealer Dashboard
        return true;

    }

    cout << "Invalid credentials or role mismatch.\n";
    return false;
}





bool userLogin() {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;

    cout << "Enter password: ";
    char ch;
    while ((ch = _getch()) != '\r')
    {  // '\r' is Enter key
        if (ch == '\b')
            {
                  // Handle backspace
            if (!password.empty())
             {

                cout << "\b \b";
                password.pop_back();

            }

        }
        else
        {

            password.push_back(ch);
            cout << "*";

        }

    }

    cout << endl;

    auto it = find_if(users.begin(), users.end(), [&](const User& u)
                    {
        return u.username == username && u.password == password && u.role == "User";
    });

    if (it != users.end())
        {

        cout << "Login successful! Welcome " << it->username << " (User)\n";

    string filePathCar = R"(C:\Users\HP\OneDrive\Desktop\Books_to_Read\New_path\New_cars.txt)";
    string filePathPurchase = "C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\Purchase_and_booking.txt";

    vector<Car> cars = loadCars(filePathCar);

    string filePathBike = R"(C:\Users\HP\OneDrive\Desktop\Books_to_Read\Bike.txt)";

    vector<Bike> bikes = loadBikes(filePathBike);
    string type;

    int ch;
    cout << "\n======================================================================\n";
    cout << "Main Menu:\n";
    cout << "======================================================================\n";
    cout << "1.Cars Menu"<<endl;
    cout << "2.Bike Menu"<<endl;
    cout << "3.Rent Menu\n";
    cout << "4.Exit\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "Enter your choice:"<<endl;
    cin >> ch;
    if(ch==1)
    {

     if (cars.empty())
     {
        cout << "No cars available in the file.\n";
        return 0;
     }

     while (true)
     {
        cout << "\n======================================================================\n";
        cout << "Main Menu For Car:\n";
        cout << "======================================================================\n";
        cout << "1. Petrol Cars\n";
        cout << "2. Electric Cars\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 3)
        {
            cout << "Exiting program.\n";
            break;  // Exit the main loop
        }

        // Petrol or Electric car options
        while (true)
        {
            string carType = (choice == 1) ? "Petrol" : "Electric";
            cout << "\n======================================================================\n";
            cout << "\n" << carType
            << " Car Options:\n";
            cout << "\n======================================================================\n";
            cout << "1. Search by Brand\n";
            cout << "2. Search by Car Name or Dealer\n";
            cout << "3. Display All Cars\n";
            cout << "4. Purchase\n";
            cout << "5. Book Car\n";
            cout << "6. Cancel Booking\n";
            cout << "7. Exit to Main Menu\n";
            cout << "----------------------------------------------------------------------\n";
            cout << "Enter your choice: ";

            int subChoice;
            cin >> subChoice;

            if (subChoice == 7)
            {
                break;  // Return to the main menu if 'Exit to Main Menu' is selected
            }

            switch (subChoice)
            {

                case 1:
                    cout << "Search Cars by Brand\n";
                    searchByBrand(cars, carType);
                    break;

                case 2:
                    cout << "Search Cars by Car Name or Dealer\n";
                    searchByCarOrDealer(cars, carType);
                    break;

                case 3:
                    displayCarsByType(cars, carType);
                    break;

                case 4:
                    purchaseCar(cars, carType);
                    break;

                case 5:
                    bookCar(cars, carType);  // Call the bookCar function
                    break;

                case 6:
                    cancelBooking(cars, carType);  // Call the cancelBooking function
                    break;

                default:
                    cout << "Invalid option. Please try again.\n";

            }

        }

     }

    }

    else if(ch==2)
    {
        if (bikes.empty())
      {
        cout << "No bikes available in the file.\n";
        return 0;
      }

     while (true)
      {
        cout << "\n======================================================================\n";
        cout << "Main Menu For Bike:\n";
        cout << "======================================================================\n";
        cout << "1. Petrol Bikes\n";
        cout << "2. Electric Bikes\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 3)
            {
            cout << "Exiting program.\n";
            break;  // Exit the main loop
        }

        // Petrol or Electric bike options

        while (true)
            {
            string bikeType = (choice == 1) ? "Petrol" : "Electric";
            cout << "\n======================================================================\n";
            cout << "\n" << bikeType
            << " Bike Options:\n";
            cout << "\n======================================================================\n";
            cout << "1. Search by Brand\n";
            cout << "2. Search by Bike Name or Dealer\n";
            cout << "3. Display All Bikes\n";
            cout << "4. Book a Bike\n";
            cout << "5. Cancel Booking\n";
            cout << "6. Purchase a Bike\n";
            cout << "7. Exit to Main Menu\n";
            cout << "Enter your choice: ";

            int subChoice;
            cin >> subChoice;

            if (subChoice == 7)
                {
                break;  // Return to the main menu if 'Exit to Main Menu' is selected
            }

            switch (subChoice)
            {
                case 1:
                    cout << "Search Bikes by Brand\n";
                    searchByBrandBike(bikes, bikeType);
                    break;

                case 2:
                    cout << "Search Bikes by Bike Name or Dealer\n";
                    searchByBikeOrDealer(bikes, bikeType);
                    break;

                case 3:
                    displayBikesByType(bikes, bikeType);
                    break;

                case 4:
                    bookBike(bikes);
                    break;

                case 5:
                    cancelBooking(bikes);
                    break;

                case 6:
                    purchaseBike(bikes);
                    break;

                default:
                    cout << "Invalid option. Please try again.\n";

            }

        }

    }

    }
    else if(ch==3)
    {
        int choice;
    while(true){
    cout<<"\n=====================================================\n";
    cout<<"SECOND SPIN RENTALS\n";
    cout<<"======================================================\n";
    cout<<"1.Rent a Bike\n";
    cout<<"2.Rent a Car\n";
    cout<<"3.Exit\n";

    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            RentalManager2 rentalManager;

    int choice;

    std::string userName, userEmail, dealerName, dealerLocation, bikeModel, bikeType, startDate;

    int bikeId, rentalHours;

    while (choice!=13)

        {

        clearScreen();

        displayMenu();

        std::cin >> choice;


        switch (choice)

        {
            case 1:

                std::cin.ignore();

                std::cout << "Enter your name: ";

                std::getline(std::cin, userName);

                std::cout << "Enter your email: ";

                std::getline(std::cin, userEmail);

                if

                (!rentalManager.userExists(userName))

                {

                    rentalManager.addUser({userName, userEmail});
                    std::cout << "User registered successfully.\n";
                }

           else

                  {
                    std::cout << "User already exists.\n";
                }

                pause();

                break;

            case 2:

                rentalManager.listUsers();

                pause();

                break;

            case 3:

                std::cin.ignore();

                std::cout << "Enter dealer name: ";

                std::getline(std::cin, dealerName);

                std::cout << "Enter dealer location: ";

                std::getline(std::cin, dealerLocation);

                rentalManager.addDealer({dealerName, dealerLocation});

                std::cout << "Dealer added successfully.\n";

                pause();

                break;

            case 4:

                rentalManager.listDealers();

                pause();

                break;

            case 5:

                std::cin.ignore();

                std::cout << "Enter bike ID: ";


                std::cin >> bikeId;

                std::cin.ignore();

                std::cout << "Enter bike model: ";

                std::getline(std::cin, bikeModel);

                std::cout << "Enter bike type: ";

                std::getline(std::cin, bikeType);

                double hourlyRate;

                std::cout << "Enter hourly rate: ";

                std::cin >> hourlyRate;

                rentalManager.addBike({bikeId, bikeModel, bikeType, hourlyRate});

                std::cout << "Bike added successfully.\n";

                pause();

                break;

            case 6:

                rentalManager.listBikes();

                pause();

                break;

            case 7:

                std::cin.ignore();

                std::cout << "Enter your name: ";

                std::getline(std::cin, userName);

                std::cout << "Enter bike ID: ";

                std::cin >> bikeId;

                std::cin.ignore();

                std::cout << "Enter rental start date (YYYY-MM-DD): ";

                std::getline(std::cin, startDate);

                std::cout << "Enter rental duration in hours: ";

                std::cin >> rentalHours;

                if

                (rentalManager.rentBike(userName, bikeId, startDate, rentalHours))

                    {

                    std::cout << "Bike rented successfully.\n";
                }

                else

                    {

                    std::cout << "Bike rental failed.\n";
                }

                pause();

                break;

            case 8:

                std::cin.ignore();

                std::cout << "Enter your name: ";


                std::getline(std::cin, userName);






                if

                    (rentalManager.returnBike(userName))

                    {
                    std::cout << "Bike returned successfully.\n";
                }

                else

                    {

                    std::cout << "Bike return failed.\n";
                }

                pause();

                break;

            case 9:

                std::cin.ignore();

                std::cout << "Enter your name: ";

                std::getline(std::cin, userName);

                rentalManager.viewContract(userName);

                pause();

                break;


            case 10:

                std::cin.ignore();

                std::cout << "Enter your name: ";

                std::getline(std::cin, userName);

                if
                    (User2* user = rentalManager.searchUserByName(userName))

                    {
                    user->printDetails();
                }
                else
                    {
                    std::cout << "User not found.\n";
                }

                pause();





                break;

            case 11:

                if
                    (Bike2* bike = rentalManager.findCheapestBike())

                    {
                    std::cout << "Cheapest Bike: \n";

                    bike->printDetails();
                }

                else

                    {
                    std::cout << "No bikes available.\n";
                }

                pause();

                break;

            case 12:

                rentalManager.displayRentalSummary();

                pause();

                break;

            case 13:

                std::cout << "Exiting system.\n";

                exit;


        }
    }
        }
        break;

    case 2:
        {
              int choice;
    while (choice!=6) {
        cout <<"\n==============================================================================\n";
        cout << "Car Rental System\n";
        cout <<"==============================================================================\n";
        cout << "1. Display all cars\n";
        cout << "2. Filter cars\n";
        cout << "3. Rent a Car\n";
        cout << "4. Leave Feedback\n";
        cout << "5. Return a Car\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Display all cars
                displayCars(carss);
                break;
            case 2:
                // Filter cars
                filterCars(carss);
                break;
            //case 3:
                // Purchase a Car
                //purchaseCar(cars);
               // break;
            case 3:
                // Rent a Car
                rentCar(carss);
                break;





            case 4:
                // Leave Feedback
                leaveFeedback(carss);
                break;
            case 5:
                // Return a Car
                returnCar(carss);
                break;
            case 6:
                // Exit
                cout << "Exiting...\n";
                exit;

        }
    }
        }
        break;

    case 3:
        cout << "\nExiting\n";
        return 0;
    }





    }

    }
     else
        {

        cout << "Exiting program.\n";

     }

        return true;
    }

    cout << "Invalid credentials or role mismatch.\n";
    return false;
}


// Main function
int main()

{
    displayWelcomeMessage();
    loadData();

    string filePathCar = R"(C:\Users\HP\OneDrive\Desktop\Books_to_Read\New_path\New_cars.txt)";
    string filePathPurchase = "C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\Purchase_and_booking.txt";



    vector<Car> cars = loadCars(filePathCar);

    string filePathBike = R"(C:\Users\HP\OneDrive\Desktop\Books_to_Read\Bike.txt)";

    vector<Bike> bikes = loadBikes(filePathBike);
    string type;

    while (true)
    {
        cout <<"\n==============================================================================\n";
        cout << "                                  \n Main Menu                      \n";
        cout <<"==============================================================================\n";
        cout << "1. User Login\n";
       // cout << "2. Dealer Login\n";
        cout << "2. Register as User\n";
        cout << "3. Admin Login\n";
        //cout << "4. Register as Dealer\n";
        cout << "4. View All Users (Admin Only)\n";
        cout << "5. Exit\n";
        cout <<"------------------------------------------------------------------------------\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                userLogin();
                break;

            //case 2:
               // dealerLogin();
               // break;

            case 2:
                registerUser("User");

                break;

            case 3:
                adminLogin();
                break;

            //case 4:
               // registerUser("Dealer");
               // break;

            case 4:
                viewAllUsers();
                break;

            case 5:
                saveData();

                cout << "Exiting program. Goodbye!\n";
                return 0;


            default:
                cout << "Invalid choice. Please try again.\n";
        }


    }


    return 0;

}

