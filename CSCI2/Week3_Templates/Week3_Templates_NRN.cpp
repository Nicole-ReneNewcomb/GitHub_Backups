/* Nicole-Rene Newcomb's code for the Templates Assignment
   for Week 3 of CSCI-2, September 19, 2022. */

class Load
{
};

class Car : public Load
{
};

class TreeLog : public Load
{
};

class RefrigeratedStorage : public Load
{
};

template <class T> // template
class Truck 
{
    public:
        void load(T* item) 
        {
        this->freight = item;
        }

    // returns the freight and clears the pointer
    T* unload() {

       T* tmp = freight;

        freight = 0; // clear freight of truck
        return tmp;
    }

    private:

        T* freight;

};