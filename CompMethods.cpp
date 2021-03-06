#include "CompHeader.h"

void workComputers::InputFromFile(){
	std::string file;
	std::cout << "Введите имя файла для чтения\n";
	std::cin >> file;
	std::ifstream fin;
	fin.open(file);
	if (fin.fail()){
		std::cout << file << " не удалось создать файл\n";
		return;
	}
	RECORD ab;	
	char end = '1';
	while(end != '\0'){
		if (fin.fail()) 
			break;
		
		fin >> ab.CompCost >> ab.CompInStock >>
			ab.CompInfo.ProcName >> ab.CompInfo.ProcType  >>  
			ab.CompInfo.ClockSpeed >> ab.CompInfo.Graphics >> ab.CompInfo.GraphicVolume >>
			ab.CompInfo.RAM >> ab.CompInfo.Storage >> end;
		CapabilitiesComp.push_back(ab);
		
	}
}

void workComputers::OutputInFile(){
	std::string file;
	std::cout << "Введите имя файла для сохранения\n";
	std::cin >> file;
	std::ofstream fout;
	fout.open(file);
	if (fout.fail()){
		std::cout << file << " не удалось открыть файл\n";
		return;
	}
	fout << std::setfill('-') << std::setw(129) << "\n" <<
	     "|Номер| Цена | Кол. |                 Процессор                    |              Видеокарта           | ОЗУ | Размер жесткого |\n" <<
             "|     |      |      |----------------------------------------------|-----------------------------------|     |                 |\n" << 
	     "|     |(Руб.)|(штук)|    Название    |        Тип        | Частота |        Название        | Объём Гб |  Гб |      (Гб)       |\n" <<
	             std::setw(129) << "\n"; 
	for (unsigned i = 0; i < CapabilitiesComp.size(); i++){
		fout << std::setfill(' ') <<
		   "|" << std::setw(5) << i + 1 << "|" << std::setw(6) <<CapabilitiesComp[i].CompCost << "|" 
		   << std::setw(6) << CapabilitiesComp[i].CompInStock << 
		     "|" << std::setw(16) << CapabilitiesComp[i].CompInfo.ProcName << "|" << std::setw(19) <<
		     CapabilitiesComp[i].CompInfo.ProcType << "|" << std::setw(9) << CapabilitiesComp[i].CompInfo.ClockSpeed << "|" 
		     << std::setw(24) << CapabilitiesComp[i].CompInfo.Graphics << "|" << std::setw(10) << CapabilitiesComp[i].CompInfo.GraphicVolume << "|" << std::setw(5) << 
		     CapabilitiesComp[i].CompInfo.RAM << "|" << std::setw(17) << CapabilitiesComp[i].CompInfo.Storage << "|\n";
		fout << std::setfill('-') << std::setw(129) << "\n"; 
	}

}

void workComputers::Add_comp(){
	RECORD add;
	std::cout << "Введите марку процессора: ";
	std::cin >> add.CompInfo.ProcName;
	std::cout << "Введите тип процессора(хар-ки): ";
	std::cin >> add.CompInfo.ProcType; 
	std::cout << "Введите частоту процессора: ";
	std::cin >> add.CompInfo.ClockSpeed; 
	std::cout << "Введите название графической карты: ";
	std::cin >> add.CompInfo.Graphics;
	std::cout << "Введите объем видеопамяти: ";
	std::cin >> add.CompInfo.GraphicVolume;
	std::cout << "Введите объем ОЗУ: ";
	std::cin >> add.CompInfo.RAM; 
	std::cout << "Введите объем жесткого диска: "; 
	std::cin >> add.CompInfo.Storage; 
	std::cout << "Введите цену: ";
	std::cin >> add.CompCost;
	std::cout << "Введите количество компьютеров на складе: ";
	std::cin >> add.CompInStock;
	CapabilitiesComp.push_back(add);
}

void workComputers::Delete_comp(){
	unsigned n; char ch;
	workComputers::showInfo();
	std::cout << "Введите номер строки для удаления: ";
	std::cin >> n;
	if (n < 1 || n > CapabilitiesComp.size()){
		std::cout << " нет такой строки\n";
		return;
	}
	n--;
	std::cout << " удалить строку(press y):";
	std::cin >> ch;
	if (ch == 'y' || ch == 'Y'){
		CapabilitiesComp.erase(CapabilitiesComp.begin() + n);
	}
	return;
}

void workComputers::showInfo(){
	std::cout << std::setfill('-') << std::setw(129) << "\n" <<
	     "|Номер| Цена | Кол. |                 Процессор                    |              Видеокарта           | ОЗУ | Размер жесткого |\n" <<
             "|     |      |      |----------------------------------------------|-----------------------------------|     |                 |\n" << 
	     "|     |(Руб.)|(штук)|    Название    |        Тип        | Частота |        Название        | Объём Гб |  Гб |      (Гб)       |\n" <<
	             std::setw(129) << "\n"; 
	for (unsigned i = 0; i < CapabilitiesComp.size(); i++){
		std::cout << std::setfill(' ') <<
		   "|" << std::setw(5) << i + 1 << "|" << std::setw(6) <<CapabilitiesComp[i].CompCost << "|" 
		   << std::setw(6) << CapabilitiesComp[i].CompInStock << 
		     "|" << std::setw(16) << CapabilitiesComp[i].CompInfo.ProcName << "|" << std::setw(19) <<
		     CapabilitiesComp[i].CompInfo.ProcType << "|" << std::setw(9) << CapabilitiesComp[i].CompInfo.ClockSpeed << "|" 
		     << std::setw(24) << CapabilitiesComp[i].CompInfo.Graphics << "|" << std::setw(10) << CapabilitiesComp[i].CompInfo.GraphicVolume << "|" << std::setw(5) << 
		     CapabilitiesComp[i].CompInfo.RAM << "|" << std::setw(17) << CapabilitiesComp[i].CompInfo.Storage << "|\n";
		std::cout << std::setfill('-') << std::setw(129) << "\n"; 
	}
}

void workComputers::swapElementsInVector(unsigned index){
	RECORD temp = CapabilitiesComp[index];
	CapabilitiesComp[index] = CapabilitiesComp[index - 1];
	CapabilitiesComp[index - 1] = temp;
}

void workComputers::SortProcTypeAndClock(){
	std::cout << "Сортировка по типу процессора и частоте: \n";
	unsigned n = CapabilitiesComp.size();
	bool flag;
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i].CompInfo.ProcType.compare(CapabilitiesComp[i - 1].CompInfo.ProcType) < 0)
			{
				workComputers::swapElementsInVector(i);
				flag = true;
			}
			else if (CapabilitiesComp[i].CompInfo.ProcType.compare(CapabilitiesComp[i - 1].CompInfo.ProcType) == 0 &&
				 CapabilitiesComp[i].CompInfo.ClockSpeed < CapabilitiesComp[i - 1].CompInfo.ClockSpeed)	
			{
				workComputers::swapElementsInVector(i);
				flag = true;
			}
		}
		n--;
	} while (flag);
	workComputers::showInfo();
}

void workComputers::SortProcName(){
	std::cout << "Сортировка по названию процессора: \n";
	unsigned n = CapabilitiesComp.size();
	bool flag;
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i].CompInfo.ProcName.compare(CapabilitiesComp[i - 1].CompInfo.ProcName) < 0)
			{
				workComputers::swapElementsInVector(i);
				flag = true;
			}
			else if (CapabilitiesComp[i].CompInfo.ProcName.compare(CapabilitiesComp[i - 1].CompInfo.ProcName) == 0 &&
					CapabilitiesComp[i].CompInfo.ProcType.compare(CapabilitiesComp[i - 1].CompInfo.ProcType) < 0)
			{
				workComputers::swapElementsInVector(i);
				flag = true;
			}
		}
		n--;
	} while (flag);
	workComputers::showInfo();
}

void workComputers::SortPrice(){
	std::cout << "Сортировка по цене: \n";
	bool flag;
	unsigned n = CapabilitiesComp.size();
	do{
		flag = false;
		for (unsigned i = 1; i < n; i++)
		{
			if (CapabilitiesComp[i - 1].CompCost > CapabilitiesComp[i].CompCost){
				workComputers::swapElementsInVector(i);
				flag = true;
			}
		}
		n--;
	} while(flag);
	workComputers::showInfo();
}


