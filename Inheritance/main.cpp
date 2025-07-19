#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define delimitr "\n--------------------------\n"


#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETRS  last_name, first_name, age
class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}


	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	// Constructors:
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//		Methods:
	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << endl;

	}
	friend std::ostream& operator<<(std::ostream os, const Human& obj)
	{
		return obj.print(os);
	}
	virtual std::ostream& print(std::ostream& os) const
	{
		return os << "Human";
	}
	
};
// operator overload:
//std::ostream&  operator<<(std::ostream& os, const Human obj)
//{
//	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
//}



#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendence
#define STUDENT_GIVE_PARAMETRS  speciality,group,rating, attendence
class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//Constructors:
	Student
	(
		HUMAN_TAKE_PARAMETRS,
		STUDENT_TAKE_PARAMETRS
	):Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendence);
		cout << "SConstructor:\t" << this << endl;

	}
	~Student()
	{
		cout << "SDesructor:\t" << this << endl;
	}

	//			Methods:
	void info()const override
	{
		Human::info();
		cout << speciality << " " << group << " " << attendance << endl;
	}
	virtual std::ostream& print(std::ostream& os) const
	{
		return os << "Student";
	}
};
// operator overload Student:
//std::ostream&  operator<<(std::ostream& os, const Student& obj)
//{
//	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " " << obj.get_speciality() <<
//		obj.get_group() << " " << obj.get_attendance() << endl;
//}
#define TEACHER_TAKE_PARAMETRS const std::string& speciality, int expiriants
#define TEACHER_GIVE_PARAMETRS speciality, expiriants
class Teacher : public Human
{
	std::string speciality;
	int expiriants;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_expiriants()const
	{
		return expiriants;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_expiriants(int expiriants)
	{
		this->expiriants = expiriants;
	}

	Teacher
	(
		HUMAN_TAKE_PARAMETRS,
		TEACHER_TAKE_PARAMETRS
	) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_expiriants(expiriants);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	// Methods:
	void info()const override
	{
	Human::info();
		cout << speciality << " " << expiriants << endl;
	}
	virtual std::ostream& print(std::ostream& os) const
	{
		return os << "Teacher";
	}
};
#define GRADUATE_TAKE_PARAMETRS const std::string& subject 
#define GRADUATE_GIVE_PARAMETRS subject 
class Graduate:public Student
{
	std::string subject;
public:
	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, GRADUATE_TAKE_PARAMETRS)
		:Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
	{
		this->subject = subject;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDistructor:\t" << this << endl;
	}

	void info()const
	{
		Student::info();
		cout << subject << endl;
	}

};
#define INTERITANCE
//#define POLIMORPHISM
void main()
{
	setlocale(LC_ALL, "");
#ifdef INTERITANCE
	Human human("Montana", "Antonio", 25);
	//human.info();

	Student student("Pincman", "Jessy", 22, "Chemistry", "WW_220", 95, 99);
	//student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	//teacher.info();

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "WW_220", 40, 60, "How to catch Heisenberg");
	//graduate.info();

	/*cout << human << endl;
	cout << student << endl;
	*/

#endif // INTERITANCE

#ifdef POLIMORPHISM
	Human* group[] =
	{
		new Human("Montana", "Antonio", 25),
		new Student("Pincman", "Jessy", 22, "Chemistry", "WW_220", 95, 99),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Student("Pinc", "Jemmi", 26, "Chemistry", "WW_220", 90, 89),
		new Teacher("Whim", "Demmi", 40, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "WW_220", 40, 60, "How to catch Heisenberg")
	};
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
		cout << delimitr << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLIMORPHISM


}