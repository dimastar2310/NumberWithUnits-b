#include <iostream>
#include <fstream>
#include "NumberWithUnits.hpp"
using namespace std;


namespace ariel{
string clean_string(const string& t) {
         string res;
    int len = t.size();
    for(ulong i =0;i<len;i++){
        if(t[i]!=' '){
            res+=t[i];
        }
    }
    //cout<<"oures res is = "<<res<<endl;
    return res;
    
    
    }
    bool check_valid(const string& s) {
        auto got = precios.find(s);//const iterator
        if(got==precios.end()){
            return false;
        }
        else
        {
            return true;
        }
        
    }
    NumberWithUnits::NumberWithUnits(double units,const std::string& abc ){//there is no find for value
    string copy(abc);
    string res =clean_string(copy);
    
    //auto res_from_map = precios.find(res);
    bool c_v = check_valid(res);
    
    if(c_v){ //if found
    
    _str = res;
    number = units;
     
    }
    else //if not found
    {
        throw "2d hashmap doen't contain does units!";
    }
    }
  //NumberWithUnits::NumberWithUnits(double value,const std::string& units){
    //     if(precios.count(units) == 0){ //checking if value exist in hashmap
    //         throw invalid_argument {"This unit does not match in the units_file"};
    //     }
    //     number = value;
    //     _str = units;
    // }


    void read_units1(const string& str){ //ani ose et ze kaha ki ani roze sheihie stati le class ve le globali ein gisha mi class aher
// string s1(str);
// cout<<s1<<endl;
        //s cout<<str<<endl;
        //iam goint to send to this function each line
        string first;
        string second;
        string doub;
        double doub1;
        ulong pos = 0;
        int len = str.size();
        bool help = true;
        //cout<<"iam at read_units"<<endl;
        for (ulong i = 0; i < len && help; i++) {
            /* code */
            // cout<<"iam at for"<<endl;
            if(str[i]=='='){
                pos++;
                help = false;
                break;
                // cout<<first<<endl;

            }
            else if(str[i]!=' ' && !isdigit(str[i])) //dont care if digit its 1 always
            {
                first+=str[i];
                //cout<<first<<endl;

                pos++;
            }

        }

        //cout<<"out of first for curr first = "<<first<<endl;
        for (ulong i =pos+1 ; i < len; i++) {
            //  cout<<"iam at second for"<<endl;
            if(str[i]!=' ' && str[i]!='=' && !isdigit(str[i])){
                second+=str[i];
                //cout<<second<<endl;
            }
            else if(isdigit(str[i])){
                doub+=str[i];
            }
        }
        doub1 = stod(doub); //function to torn string to double
        //cout<<"our double is "<< doub1<<endl;

        //cout<<" first= "<<first<<" second = " <<second<< " doub= "<<doub<<endl;
        //1 km = 1000m

        ariel::precios[first][second]=doub1;//<key,value> le meshane po
        ariel::precios[second][first] = 1/doub1; //for some numbers after point
        //cout<<"precios[first][second] = "<<ariel::precios[first][second]<<endl;
        //cout<< "precios[second][first] = "<<ariel::precios[second][first]<<endl;
//   cout<<"iam at print_map function"<<endl;
//     for (auto const &pair: precios) {
//         std::cout << "{" << pair.first << ": " << pair.second << "}\n";


    }
    void NumberWithUnits::read_units(ifstream& ifs){
        string line;
        if (ifs.is_open()) { //space itf default
            getline(ifs,line);
            read_units1(line);
            cout<<line<<endl;
            while(ifs){
                getline(ifs,line); //reading line by line and getting down its using reference
                
                cout<<line<<endl;

            }
            ifs.close();

        }
        else {
            // show message:
            std::cout << "Error opening file";
        }

    }
   

    NumberWithUnits& NumberWithUnits::operator--(){
        this->number -=1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int){
        NumberWithUnits copy = *this;
        this->number -=1;
        return copy;
    }

    NumberWithUnits& NumberWithUnits::operator++(){
        this->number +=1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int){
        NumberWithUnits copy = *this;
        this->number +=1;
        return copy;
    }
    //so that -3 = 5 wont be allowed

     NumberWithUnits operator*(const NumberWithUnits& n, double num){
        return NumberWithUnits{n.number*num,n._str};
    }




     NumberWithUnits operator*(double num,const NumberWithUnits& n){
        return NumberWithUnits{n.number*num,n._str};
    }


    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator + (const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator + (){
        return *this;
    }
    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator - (const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator - (){
        return NumberWithUnits {this->number*(-1) , this->_str};
    }

    // const NumberWithUnits operator-(const NumberWithUnits& a,const NumberWithUnits b);
    // const NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits b);


    bool operator==(const NumberWithUnits& a, const NumberWithUnits& b){
        
        return true;
    }
    bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator>(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator<(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }



    ostream& operator<< (ostream& os, const NumberWithUnits& num){
        return os << num.number << "[" << num._str << "]" << endl;
    }

    istream& operator >> (istream& is, NumberWithUnits num){
        string out;
        return is >> num.number >> out >> num._str;
    }

}