#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Ստուգում ենք field-ը
bool isField(string field){
    if(field == "population") return true;
    if(field == "city") return true;
    if(field == "lat") return true;
    if(field == "lng") return true;
    if(field == "country") return true;

    return false;
}

// Ստուգում ենք op-ը
bool isOp(string op){
    if(op == "==") return true;
    if(op == "<=") return true;
    if(op == ">=") return true;
    if(op == "<") return true;
    if(op == ">") return true;

    return false;
}

// Ստուգում ենք value-ն
bool isValue(string value){
    if(value.empty()) return false;
    if(value[0] >= '0' && value[0] <= '9'){
        for(char a : value){
            if((a < '0' || a > '9') && a != '.') return false;
        }
    }
    else if(value[0] >= 'a' && value[0] <= 'z'){
        for(char a : value){
            if(a < 'a' || a > 'z') return false;
        }
    }
    else return false;
    return true;
}

//Population
bool comparePopulation(string op, int pop, int val){
    if(op == ">") return pop > val;
    if(op == ">=") return pop >= val;
    if(op == "<") return pop < val;
    if(op == "<=") return pop <= val;
    if(op == "==") return pop == val;
    return false;
}

//Country
bool citiesOfCountry(string op, string cnt, string val){
    if(op == "==") return cnt == val;
    return false;
}

//Lat
bool compareLat(string op, double lat, double val){
    if(op == ">") return lat > val;
    if(op == ">=") return lat >= val;
    if(op == "<") return lat < val;
    if(op == "<=") return lat <= val;
    if(op == "==") return lat == val;
    return false;
}

//Lng
bool compareLng(string op, double lng, double val){
    if(op == ">") return lng > val;
    if(op == ">=") return lng >= val;
    if(op == "<") return lng < val;
    if(op == "<=") return lng <= val;
    if(op == "==") return lng == val;
    return false;
}

int main() {

    // Ներմուծում ենք հարցումը
    string query;
    cout<<"Please, enter your query."<<endl;
    getline(cin, query);
    string field="", op="", value="";
    int j=0;

    // Մաքրում ենք query-ն հեռացնելով բացատները և տառերը դարձնելով փոքրատառ
    string clean = "";
    for(char c : query){
        if(c != ' ') {
            if(c >= 'A' && c <= 'Z') c = c + 32;
            clean += c;
        }
        
    }
    query = clean;

    // Գտնում ենք field-ը
    for(int i = j; i < query.length(); i++){
    if(query[i] >= 'a' && query[i] <= 'z'){
        field += query[i];
    }
    else {
        j = i;
        break;
    }
}

    // Գտնում ենք op-ը
    for(int i = j; i<query.length(); i++){
        if(query[i] == '=' || query[i] == '>' || query[i] == '<'){
            op+= query[i];
        }
        else {
            j=i;
            break; 
        }
    }

    // Գտնում ենք value-ն
    for(int i = j; i<query.length(); i++){
        if((query[i] >= 'a' && query[i] <= 'z') || (query[i] >= '0' && query[i] <= '9') || query[i] == '.') value+= query[i];
        else {
            j=i;
            break; 
        }
    }    
    
    // Տպում ենք էկրանին, երբ սխալ մուտք են արել 
    if(field == "" || op == "" || value == ""){
        cout << "Invalid query";
        return 0;
    }

    if(!isField(field) || !isOp(op) || !isValue(value)){
        cout << "Invalid query";
        return 0;
    }


    // կարդում ենք ֆայլը
    ifstream file("worldcities.csv");
    string line;
    getline(file, line);

    int citiesPop = -1;
    bool found = false;
    double v = 0;

    if(field == "population") v = stoi(value);
    if(field == "lat" || field == "lng") v = stod(value);
    
    if(field == "city"){
    while (getline(file, line)) {
        stringstream ss(line);
        string id, city, lat, lng, country, iso2, iso3, population;

        getline(ss, id, ',');
        getline(ss, city, ',');
        getline(ss, lat, ',');
        getline(ss, lng, ',');
        getline(ss, country, ',');
        getline(ss, iso2, ',');
        getline(ss, iso3, ',');
        getline(ss, population, ',');

        if(city == value){
            citiesPop = stoi(population);
            break;
        }
    }

    if(citiesPop == -1){
        cout << "City not found";
        return 0;
    }

    file.clear();
    file.seekg(0);
    getline(file, line);
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string id, city, lat, lng, country, iso2, iso3, population;

        getline(ss, id, ',');
        getline(ss, city, ',');
        getline(ss, lat, ',');
        getline(ss, lng, ',');
        getline(ss, country, ',');
        getline(ss, iso2, ',');
        getline(ss, iso3, ',');
        getline(ss, population, ',');

        int p = stoi(population);
        double lt = stod(lat);
        double lg = stod(lng);
        
        //city
        if(field == "city"){
          if(comparePopulation(op, p, citiesPop)) cout << city << ", ";
        }


        if(field == "population"){
            if(comparePopulation(op, p, v)) cout<<city<<",  ";
        }
        //country
        if(field == "country"){
            if(citiesOfCountry(op, country, value)) cout << city << ", ";
        }
        if(field == "lat"){
            if(compareLat(op, lt, v)) cout<<city<<",  ";
        }
        if(field == "lng"){ 
            if(compareLng(op, lg, v)) cout<<city<<",  ";
        }
    }

    return 0;
}