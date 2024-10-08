#ifndef DRINKS_H_INCLUDED
#define DRINKS_H_INCLUDED

#include "config.h"

using namespace std;

class Drink
{
private:
    int drinking_time;
    string dishes;

    string name = "drink name";
protected:
    ClassName classname = DRINK;

public:
    Drink();

    void set_drinking_time(int time);

    int get_drinking_time();

    void set_dishes(string dishes);

    string get_dishes();

    string get_name();

    void set_name(string name);

    void save(std::ofstream &);

    void load(std::ifstream &);

    template <typename T>
    void save_primitive_type(std::ofstream& fout, T& obj) {
        fout.write(reinterpret_cast<char *>(&obj), sizeof(T));
    }

    template <typename T>
    T load_primitive_type(std::ifstream& fin) {
        T result;
        fin.read(reinterpret_cast<char *>(&result), sizeof(T));
        return result;
    }

    std::string load_sized_string(std::ifstream&);

    void save_sized_string(std::ofstream&, std::string&);

    virtual void print(std::ostream& ostream) const;

    friend std::ostream& operator<<(std::ostream&, const Drink&);

    ClassName get_classname() const;
};

#endif
