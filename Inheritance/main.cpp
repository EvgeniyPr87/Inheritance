#include<iostream>
#include<string>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;

#define delimitr "\n--------------------------\n"
//#define DEBUG


#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETRS  last_name, first_name, age
//#define HUMAN_FIELDS_OUTPUT  last_name << " " << first_name << " " << age << endl

class Human
{
	static const int TYPE_WIDTH = 10;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 3;
	static int count;
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
	int get_count()const
	{
		return count;
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
		count++;
#ifdef DEBUG
		cout << "HConstructor:\t" << this << endl;
#endif // DEBUG

	}
	virtual~Human()
	{
		count--;
#ifdef DEBUG
		cout << "HDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//		Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		os << std::left;
		os.width(TYPE_WIDTH);
		os << std::string(typeid(*this).name() + 6)+ ":";
		os.width(LAST_NAME_WIDTH);
		os << last_name;
		os.width(FIRST_NAME_WIDTH);
		os << first_name;
		os.width(AGE_WIDTH);
		os << age;
		return os;
	}
	
};
int Human::count = 0; //статическую переменную можно инициализировать только за пределами класса

std::ostream& operator <<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
}

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendence
#define STUDENT_GIVE_PARAMETRS  speciality,group,rating, attendence
//#define STUDENT_FIELDS_OUTPUT speciality << " " << group << " " << attendance << endl

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 5;
	static const int ATTENDANSE_WIDTH = 5;
	
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
#ifdef DEBUG
		cout << "SConstructor:\t" << this << endl;
#endif // DEBUG


	}
	~Student()
	{
#ifdef DEBUG
		cout << "SDesructor:\t" << this << endl;
#endif // DEBUG

	}

	//			Methods:
	std::ostream& info(std::ostream& os)const override
	{
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(GROUP_WIDTH);
		os << group;
		os.width(RATING_WIDTH);
		os << rating;
		os.width(ATTENDANSE_WIDTH);
		os << attendance;
		return os;
	}
	
};

 std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	 return obj.info(os);
 }
 
#define TEACHER_TAKE_PARAMETRS const std::string& speciality, int expiriants
#define TEACHER_GIVE_PARAMETRS speciality, expiriants
//#define TEACHER_FIELDS_OUTPUT speciality << " " << expiriants << endl

class Teacher : public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int EXPERIENCE_WIDTH = 3;
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
#ifdef DEBUG
		cout << "TConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Teacher()
	{
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif // DEBUG

	}
	// Methods:
	std::ostream& info(std::ostream& os)const override
	{
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(EXPERIENCE_WIDTH);
		os << expiriants;
		return os;
	}
	
};

#define GRADUATE_TAKE_PARAMETRS const std::string& subject 
#define GRADUATE_GIVE_PARAMETRS subject 
//#define GRADUATE_FIELDS_OUTPUT  subject << endl

class Graduate:public Student
{
	std::string subject;
public:
	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, GRADUATE_TAKE_PARAMETRS)
		:Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
	{
		this->subject = subject;
#ifdef DEBUG
		cout << "GConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Graduate()
	{
#ifdef DEBUG
		cout << "GDistructor:\t" << this << endl;
#endif // DEBUG

	}
	//	Metods:
	std::ostream& info(std::ostream& os)const override
	{
		Student::info(os) << " ";
		return os << subject;
	}
	
};

//#define INTERITANCE
#define POLIMORPHISM


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

	cout << human << endl;
	cout << student << endl;
	cout << teacher << endl;
	cout << graduate << endl;

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
		//group[i]->info();
		cout << *group[i] << endl;
		cout << delimitr << endl;
	}
	

	char filename[] = "group.txt";
	std::ofstream fout;
	fout.open("Group.txt", std::fstream::trunc);

	if (fout.is_open())
	{
		for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
		{
			fout << *group[i]<<endl;
		}
	
	}
	else
	{
		std::cerr << "Error: file not open" << endl;
	}
	fout.close();
	char cmd[FILENAME_MAX] = "notepad ";
	//system("notepad Group.txt");
	//strcat(cmd, filename);
	system((std::string("notepad") + filename).c_str());
	cout << "Количество людей" << group[0]->get_count() << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLIMORPHISM
}