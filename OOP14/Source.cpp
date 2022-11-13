#include<iostream>
#include<stack>
using namespace std;

class Engine {
private:
	string engineNumber;
	string company;
	double volume;
public:
	void SetEngineNumber(const string engineNumber) {
		this->engineNumber = engineNumber;
	}
	void SetEngineCompany(const string company) {
		this->company = company;
	}
	void SetEnginevolume(const double volume) {
		this->volume = volume;
	}
	string GetEngineNumber()const {
		return  engineNumber;
	}
	string GetCompany()const {
		return  company;
	}
	double GetVolume()const {
		return volume;
	}
	Engine() {}
	Engine(string engineNumber, string company, double volume) {
		SetEngineNumber(engineNumber);
		SetEngineCompany(company);
		SetEnginevolume(volume);
	}
	void Show() {
		cout << " Engine company : " << company<<endl;
		cout << " Engine number : " << engineNumber<<endl;
		cout << " Volume : " << volume << endl;
	}
};

class Vehicle {
private:
	static int staticId;
	int id;
	string vendor;
	string model;
	Engine engine;
public:
	void SetId(int id) {
		this->id = id;
	}
	void SetVendor(string vendor) {
		this->vendor = vendor;
	}
	void SetModel(string model) {
		this->model = model;
	}
	void SetEngine(Engine engine) {
		this->engine = engine;
	}
	int Getid()const {
		return  id;
	}
	string GetVendor()const {
		return  vendor;
	}
	string GetModel()const {
		return  model;
	}
	Engine GetEngine()const {
		return engine;
	}
	

	Vehicle(string vendor, string model, Engine engine) {
		id = staticId++;
		SetId(id);
		SetModel(model);
		SetVendor(vendor);
		SetEngine(engine);
	}
	virtual void Show() {
		cout << "ID : " << id << endl;
		cout << "Venodr : " << vendor << endl;
		cout << "Model : " << model << endl;
		engine.Show();
	}
};
int Vehicle :: staticId = 1;
class Car : public Vehicle {
private:
	bool hasSpoiler;
public:
	void SetHasSpoiler(bool HasSopiel) {
		this->hasSpoiler = hasSpoiler;
	}
	bool GetHasSpoiler()const {
		return hasSpoiler;
	}
	Car(string vendor, string model, Engine engine, bool hasSpoiler) :Vehicle(vendor, model, engine) {
		this->hasSpoiler = hasSpoiler;
	}
	void Show() {
		cout << "----------CAR---------" << endl;
		Vehicle::Show();
		cout << "Spiler: " << (hasSpoiler ? "Yes" : "No") << endl;
	}
};

class Ship : public Vehicle {
private:
	bool hasSail;

public:
	
	void SetHasSail(bool hasSail) {
		this->hasSail = hasSail;
	}
	bool GetHasSpoiler()const {
		return hasSail;
	}
	Ship(string vendor, string model, Engine engine, bool hasSpoiler) :Vehicle(vendor, model, engine) {
		SetHasSail(hasSail);
	}
	void Show() {
		cout << "----------SHIP---------" << endl;
		Vehicle::Show();
		cout << "Sail: " << (hasSail ? "Yes" : "No") << endl;

	}
};

class Airplane : public Vehicle {
private:
	int engineCount;
	int passengerCapacity;
public:
	void SetEngineCount(int engineCount) {
		this->engineCount = engineCount;
	}
	int GetEngineCount()const {
		return engineCount;
	}
	void SetPassengerCapacity(int passengerCapacity) {
		this->passengerCapacity = passengerCapacity;
	}
	int SetPassengerCapacity()const {
		return passengerCapacity;
	}
	
	Airplane(string vendor, string model, Engine engine, bool hasSpoiler, int engineCount,int passengerCapacity) :Vehicle(vendor, model, engine) {
		SetEngineCount(engineCount);
		SetPassengerCapacity(passengerCapacity);
	}
	void Show() {
		cout << "----------AIRPLANE---------" << endl;
		Vehicle::Show();
		cout << "Engine count  : " << engineCount << endl;
		cout << "Passenger capacity  : " << passengerCapacity << endl;
	}
};

class Garrage {
public:
	stack<Vehicle*>vehicles;
	void AddVehicle(Vehicle* vehicle) {
		vehicles.push(vehicle);
	}
	void SHowAllVehicles() {
		while (!vehicles.empty())
		{
			vehicles.top()->Show();
			vehicles.pop();
		}
	}
};

void main() {
	Garrage* garrage = new Garrage();
	garrage->AddVehicle(new Car("Wolksvagen", "Touareg", Engine("3.0 V6 TSI", "Wolksavegn", 3.6), false));
	garrage->AddVehicle(new Ship("yamaha", "SX220", Engine("TWIN TR-1 HIGH OUTPUT", "YAMAHA MARINE ENGINES", 1.6), false));
	garrage->AddVehicle(new Airplane("Azal", "A21", Engine("Azal123", "Az", 3700), false, 2, 200));
	garrage->SHowAllVehicles();
}
