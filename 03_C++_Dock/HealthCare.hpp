#ifndef HELTHCARE_HPP
#define HELTHCARE_HPP

#include <iostream>

class Doctor_Reg{
private:
	std::string m_Doc_name;
	std::string m_specialization;
	int m_experience_years;
	std::string m_Doc_contact_inf;
public:
	void set_Doc_name(std::string);
	void set_specialization(std::string);
	void set_experience_years(int);
	void set_Doc_contact_inf(std::string);

	std::string get_Doc_name();
	std::string get_specialization();
	int get_experience_years();
	std::string get_Doc_contact_inf();

	Doctor_Reg();
	Doctor_Reg(const std::string&, const std::string&, int, const std::string&);
	~Doctor_Reg();
	Doctor_Reg(Doctor_Reg&&);
	Doctor_Reg(const Doctor_Reg&);
};

class Patient_Reg{
private:
	std::string m_Pat_name;
	std::string m_Pat_date_birth;
	std::string m_Pat_gender;
	std::string m_Pat_contact_inf;
	std::string m_Pat_conditions;
public:
};

void Medical_History (){

}



#endif // HELTHCARE_HPP
