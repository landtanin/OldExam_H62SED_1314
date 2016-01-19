#include <MATH.H>
#include <IOSTREAM.H>
#include <FSTREAM.H>
#include <STDLIB.H>

using namespace std;

class train{

  public:

    train(float _maximum_speed = 0); // constructor  **speed should be float quantity

    virtual ~train(); // destructor

    train(istream& in);

    train(const train& t); // declaration of copy constructor

    const train& operator=(const train &t); // equal operator


    void set_max_speed(const float _max_speed); // set1

    virtual float get_maximum_speed(); // get1


    friend istream& operator>>(istream& in, train& t); // stream input file

    friend ostream& operator<<(ostream& out, const train& t); // stream output file



  private:

    float maximum_speed;

}; // class train

class freight_train:public train{

    public:

    freight_train(float _maximum_speed = 0, int _max_cargo = 0, int _actual_cargo = 0) // constructor  **constructor of mother class should be included

    virtual ~freight_train(); // destructor

    freight_train(istream& in); // ??? still be a mystery

    freight_train(const freight_train& m); // declaration of copy constructor

    freight_train& operator=(const freight_train& m); // equal operator


    void set_max_cargo(const int _mc); // set1

    int get_max_cargo(); // get1

    void set_actual_cargo(const int _ac); // set2 // this may not necseesary

    int get_actual_cargo(); // get2int

    virtual float get_maximum_speed();

    int try_to_load_cargo_containers(const int cargo_add)(); // cannot be const function bc it want to change the actual_cargo


    friend istream& operator>>(istream& in, freight_train& ft); // stream input file

    friend ostream& operator<<(ostream& out, const freight_train& ft); // stream output file


    //virtual bool is_passed();

    private:

        int max_cargo;

        int actual_cargo

}; // class freight_train


//---------------------------------train----------------------------------------

train::train(float _maximum_speed):maximum_speed(_maximum_speed){
} // definition of constructor

train::train(){} // definition of destructor

train::train(istream& in);{

    in>>*this;
}

train::train(const train& t){ // copy constructor

    maximum_speed = t.maximum_speed;

}

const train& train::operator=(const train& t){ // operator equal

    if(this==&t) return(*this);

    maximum_speed = t.maximum_speed;

    return(*this);

}

void train::set_max_speed(const float _max_speed){ // set1

    if(_max_speed>=0) maximum_speed = _max_speed;

}

float train::get_maximum_speed() const { // get1

    return maximum_speed;

}


//-------------------------freight_train----------------------------------------


freight_train::freight_train(float _maximum_speed, int _max_cargo, int _actual_cargo):train(_maximum_speed),max_cargo(_max_cargo),actual_cargo(_actual_cargo){

} // definition of constructor

freight_train::~freight_train(){} // definition of destructor

freight_train::freight_train(istream& in)train(in){

    in>>*this;
}

freight_train::freight_train(const freight_train& ft):train(ft){ // copy constructor

    max_cargo = ft.max_cargo;

    actual_cargo = ft.actual_cargo;

}

const freight_train& freight_train::operator=(const freight_train& ft){ // operator equal

    if(this==&m) return(*this);



    max_cargo = ft.max_cargo;

    actual_cargo = ft.actual_cargo;

    return(*this);

}

void freight_train::set_max_cargo(const int _mc){ // set1

    if(_mc>=0) max_cargo = _mc;

}

int freight_train::get_max_cargo() const { // get1

    return max_cargo;

}

void freight_train::set_actual_cargo(const int _ac){ // set2

    if(_ac>=0&&_ac<=max_cargo){

        actual_cargo = mark;

    }

}

int freight_train::get_actual_cargo() const { // get2

        return actual_cargo;

}

float train::get_maximum_speed() const { // let's say every 1 cargo container deduct speed by 1 percent

    return (maximum_speed-((actual_cargo*maximum_speed)/100);

}


int freight_train::try_to_load_cargo_containers(const int cargo_add)(){

    int cargo_add_failed = 0;

    if(!(actual_cargo+cargo_add)<=max_cargo){

        cargo_add_failed = (actual_cargo+cargo_add) - max_cargo;

    }

    return cargo_add_failed;
}

//------------------------------istream-----------------------------------------


istream& operator>>(istream& in, train &t){

      in>>t.maximum_speed;

      return(in);

}

ostream& operator<<(ostream& out,train &t){

      out<<t.maximum_speed;

      return(out);

}


istream& operator>>(istream& in,freight_train &ft){

      in>>ft.max_cargo>>ft.actual_cargo;

      return(in);

}

ostream& operator<<(ostream& out,freight_train &ft){

      out<<ft.max_cargo<<" "<<ft.actual_cargo<<endl;

      return(out);

}







int main()
{
  // task 4.1
  freight_train** train_array; // create an array of freight_train dynamically
  int no_trains = 0;

  ifstream file_in1("trains_spec.txt"); // each line contain the data of max_cargo and actual_cargo = 0

  file_in1>>no_trains;

  train_array = new*[no_trains]; // allocate size of array, number of trains

  for(int i = 0;i<no_trains;i++){

      file_in1>>new train_array*[i]; // not sure

  }

  // task 4.2
  int cargo_to_load = 0, cargo_left = 0, trains_w_cargo=0, cargo_last_train = 0;

  cout << "Please enter the number of cargo to be loaded" << endl;

  cin >> cargo_to_load;

  // task 4.3
  for(int i = 0; i<no_trains&&cargo_to_load>0; i++){

      cargo_last_train = cargo_to_load;

      cargo_left = *train_array[i].try_to_load_cargo_containers(cargo_to_load);

      cargo_to_load = cargo_left;

      trains_w_cargo = i;

  }

  // task 4.4
  if(i==0){

      cout<<"\n"<<cargo_last_train<<"cargo containers have been loaded to 1 train"

  }
  else{

      cout<<"\n"<<"Cargo containers have been loaded to "<<trains_w_cargo+1<< " trains.";

      cout<<"\n"<<"Every trains are full load except the last train which have "<<cargo_last_train<<" cargo containers loaded";

  }




}
