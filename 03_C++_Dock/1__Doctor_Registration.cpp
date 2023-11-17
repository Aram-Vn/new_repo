#ifndef Doctor_Reg_CPP
#define Doctor_Reg_CPP

#include <iostream>
#include "HealthCare.hpp"

Doctor_Reg::Doctor_Reg(){
	m_Doc_name = "0";
	m_specialization = "0";
	m_experience_years = 0;
	m_Doc_contact_inf = "0";
}

Doctor_Reg::~Doctor_Reg(){}

Doctor_Reg::Doctor_Reg(const Doctor_Reg& obj){
	m_Doc_name = obj.m_Doc_name;
	m_specialization = obj.m_specialization;
	m_experience_years = obj.m_experience_years;
	m_Doc_contact_inf = obj.m_Doc_contact_inf;
}

Doctor_Reg::Doctor_Reg(std::string new_name, std::string new_specialization, int new_year, std::string new_Doc_contact_inf) : 
	m_Doc_name{new_name},
	m_specialization{new_specialization},
	m_experience_years{new_year},
	m_Doc_contact_inf{new_Doc_contact_inf}
{}



void Doctor_Reg::set_Doc_name(std::string new_name){
	m_Doc_name = new_name;
}

void Doctor_Reg::set_specialization(std::string new_specialization){
	m_specialization = new_specialization;
} 

void Doctor_Reg::set_experience_years(int new_year){
	m_experience_years = new_year;
}

void Doctor_Reg::set_Doc_contact_inf(std::string new_contact_inf){
	m_Doc_contact_inf = new_contact_inf;
}

std::string Doctor_Reg::get_Doc_name(){
	return m_Doc_name;
}

std::string Doctor_Reg::get_specialization(){
	return m_specialization;
}

int Doctor_Reg::get_experience_years(){
	return m_experience_years;
}

std::string Doctor_Reg::get_Doc_contact_inf(){
	return m_Doc_contact_inf;
}

#endif
