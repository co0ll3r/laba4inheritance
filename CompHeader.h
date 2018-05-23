#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#pragma once

const int N = 100;
class Perechen;
class workComputers;
class aggregate;

struct COMP{
	std::string ProcName; // Brand name
	std::string ProcType; // Specification
	std::string Graphics; // Graphic Card
	double GraphicVolume;
	double ClockSpeed;
	double RAM;
	double Storage;
};

struct RECORD{
	COMP CompInfo;
	double CompCost;
	int CompInStock;
};

struct BrandPerech{
	std::string ProcName;
	int Count;
};

struct TypeProcPerech{
	std::string ProcType;
	int Count;
};

struct VideocardsPerech{
 	double GraphicVolume;
	int Count;
}; 

class workComputers {
	public:
		void InputFromFile();
		virtual void OutputInFile();
		void Add_comp();
		void Delete_comp();
 		virtual	void showInfo();
		virtual void swapElementsInVector(unsigned);
		virtual	void SortProcTypeAndClock();
		void SortProcName();
		void SortPrice();

		friend void makePerechen1(workComputers, Perechen&);
		friend void makePerechen2(workComputers, Perechen&);
		friend void makePerechen3(workComputers, Perechen&);
	protected:
		std::vector<RECORD> CapabilitiesComp;
};

class SearchComp : public workComputers{
	public:
		void SearchPrice();
		void SearchHddVolume();
		void SearchBrandTypeRamETC();
		void SortRAM();
		virtual void OutputInFile();
		virtual void SortProcTypeAndClock();
		virtual void showInfo();
		virtual void swapElementsInVector(unsigned);
	private:
		std::vector<RECORD> SearchResult;
};

class Perechen : public SearchComp{
	public:
		Perechen() : pBrandlen(0), pProclen(0), pVideolen(0) {}
		~Perechen() {}
		Perechen(Perechen&);
		Perechen operator=(Perechen&);
		
		void showFirstPerech();
		void showSecondPerech();
		void showThirdPerech();
		void sortProcTypeFirstPerech();
		void sortCountSecondPerech();
		void sortVideoVolumeThirdPerech();
		void saveFirstPerech();
		void saveSecondPerech(); 
		void saveThirdPerech();

		friend void makePerechen1(workComputers, Perechen&);
		friend void makePerechen2(workComputers, Perechen&);
		friend void makePerechen3(workComputers, Perechen&);
		
	private:
		int pBrandlen, pProclen, pVideolen;
		BrandPerech perechenBrands [N];
		TypeProcPerech perechenProcTypes [N];
		VideocardsPerech perechenVideocardVolume [N];
};
